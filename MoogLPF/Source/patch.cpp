#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"
#include "AudioFile.h"
#include "patch.h"


void Patch::init() {

    memcpy(A_prelu, A, sizeof(A));

    audioInFile1.load("/Users/timothy/Documents/Circuitry/Media/sample-44k.wav");
    digiNodes[5] = x[3]-x[4];
    digiNodes[6] = 10 / (1 + pow(M_PI_2 / 15 * 10 * digiNodes[5], 2)) + 1e-12;
    A[8][3] += digiNodes[6] + 1e-12;
    A[8][4] += -digiNodes[6] + 1e-12;
    b[9] = (0.000002 * (x[5] - x[1]))-x[9];
    b[10] = (0.000002 * (x[3] - x[0]))-x[10];
    A[2][2] += digiNodes[7] + 1e-12;
    A[2][5] += -digiNodes[7] + 1e-12;
    A[5][2] += -digiNodes[7] + 1e-12;
    A[5][5] += digiNodes[7] + 1e-12;
    A[5][5] += digiNodes[8] + 1e-12;
    A[5][3] += -digiNodes[8] + 1e-12;
    A[3][5] += -digiNodes[8] + 1e-12;
    A[3][3] += digiNodes[8] + 1e-12;
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    digiNodes[7] = std::clamp(1. / (digiNodes[2]), -0.99, 0.99);
      digiNodes[8] = std::clamp(1. / (digiNodes[3]), -0.99, 0.99);
      digiNodes[9] = sin(2*3.1415 * ((2. / 44100)*ticks));
      digiNodes[10] = digiNodes[1] + 1.;
      digiNodes[11] = digiNodes[4] * 800.;
      
      digiNodes[1] = digiNodes[9];
      digiNodes[4] = digiNodes[10];
      digiNodes[2] = digiNodes[11];
      digiNodes[3] = digiNodes[11];
      
      
    b[7] += audioInFile1.samples[0][ticks] * 0.2;
    digiNodes[5] = x[3]-x[4];
    digiNodes[6] = 10 / (1 + pow(M_PI_2 / 15 * 10 * digiNodes[5], 2)) + 1e-12;
    b[8] += digiNodes[5] * digiNodes[6] - 15 * M_2_PI * atan(digiNodes[5] * 10 * M_PI_2 / 15);
    b[9] += x[9];
    b[10] += x[10];
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[8][3] += digiNodes[6];
      A[8][4] += -digiNodes[6];
      A[2][2] += digiNodes[7];
      A[2][5] += -digiNodes[7];
      A[5][2] += -digiNodes[7];
      A[5][5] += digiNodes[7];
      A[5][5] += digiNodes[8];
      A[5][3] += -digiNodes[8];
      A[3][5] += -digiNodes[8];
      A[3][3] += digiNodes[8];
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[6] + 0;

  return (controls[2]*(output*controls[1])) + (1-controls[2]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
