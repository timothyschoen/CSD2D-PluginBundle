#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"
#include "AudioFile.h"
#include "patch.h"


void Patch::init() {

    memcpy(A_prelu, A, sizeof(A));

    digiNodes[4] = x[2]-x[3];
    digiNodes[5] = 10 / (1 + pow(M_PI_2 / 15 * 10 * digiNodes[4], 2)) + 1e-12;
    A[7][2] += digiNodes[5] + 1e-12;
    A[7][3] += -digiNodes[5] + 1e-12;
    b[8] = (0.000002 * (x[4] - x[1]))-x[8];
    b[9] = (0.000002 * (x[2] - x[0]))-x[9];
    A[5][5] += digiNodes[6] + 1e-12;
    A[5][4] += -digiNodes[6] + 1e-12;
    A[4][5] += -digiNodes[6] + 1e-12;
    A[4][4] += digiNodes[6] + 1e-12;
    A[4][4] += digiNodes[7] + 1e-12;
    A[4][2] += -digiNodes[7] + 1e-12;
    A[2][4] += -digiNodes[7] + 1e-12;
    A[2][2] += digiNodes[7] + 1e-12;
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    digiNodes[6] = std::clamp(1. / (digiNodes[1]), -0.99, 0.99);
      digiNodes[7] = std::clamp(1. / (digiNodes[2]), -0.99, 0.99);
      digiNodes[8] = digiNodes[3] * 800.;
      
      digiNodes[1] = digiNodes[8];
      digiNodes[2] = digiNodes[8];
      digiNodes[3] = controls[1];
      
      
    digiNodes[4] = x[2]-x[3];
    digiNodes[5] = 10 / (1 + pow(M_PI_2 / 15 * 10 * digiNodes[4], 2)) + 1e-12;
    b[7] += digiNodes[4] * digiNodes[5] - 15 * M_2_PI * atan(digiNodes[4] * 10 * M_PI_2 / 15);
    b[8] += x[8];
    b[9] += x[9];
    b[10] += input * 0.5;
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[7][2] += digiNodes[5];
      A[7][3] += -digiNodes[5];
      A[5][5] += digiNodes[6];
      A[5][4] += -digiNodes[6];
      A[4][5] += -digiNodes[6];
      A[4][4] += digiNodes[6];
      A[4][4] += digiNodes[7];
      A[4][2] += -digiNodes[7];
      A[2][4] += -digiNodes[7];
      A[2][2] += digiNodes[7];
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[6] + 0;

  return (controls[3]*(output*controls[2])) + (1-controls[3]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
