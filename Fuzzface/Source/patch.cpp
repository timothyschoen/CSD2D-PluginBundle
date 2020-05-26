#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"
#include "AudioFile.h"
#include "patch.h"


void Patch::init() {

    memcpy(A_prelu, A, sizeof(A));

    pnC1.initJunctionPN(6.760936e-15, 1.24);
    pnC1.linearizeJunctionPN(0);

    pnE1.initJunctionPN(7.0707e-15, 1.24);
    pnE1.linearizeJunctionPN(0);

    pnC2.initJunctionPN(6.760936e-15, 1.24);
    pnC2.linearizeJunctionPN(0);

    pnE2.initJunctionPN(7.0707e-15, 1.24);
    pnE2.linearizeJunctionPN(0);

    audioInFile1.load("/Users/timothy/Documents/Circuitry/Media//Solo.wav");
    b[13] = (0.0000044 * (x[2] - x[3]))-x[13];
    b[15] = (2e-8 * (x[6] - x[9]))-x[15];
    A[16][16] += pnC1.geq + 1e-12;
    A[17][17] += pnE1.geq + 1e-12;
    A[20][20] += pnC2.geq + 1e-12;
    A[21][21] += pnE2.geq + 1e-12;
    b[24] = (0.00004 * (x[10] - x[4]))-x[24];
    A[4][4] += digiNodes[2] + 1e-12;
    A[4][10] += -digiNodes[2] + 1e-12;
    A[10][4] += -digiNodes[2] + 1e-12;
    A[10][10] += digiNodes[2] + 1e-12;
    A[4][4] += digiNodes[3] + 1e-12;
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    digiNodes[4] = std::clamp(digiNodes[1], 0.15, 0.85);
      digiNodes[2] = 1. / (100e3 * (digiNodes[4] + ((digiNodes[4] <= 0)*digiNodes[4]*0.1) - ((digiNodes[4] >= 1)*digiNodes[4]*0.1)));
      digiNodes[3] = 1. /(1. /digiNodes[2]) - (1. /100e3);
      
      digiNodes[1] = controls[1];
      
      
    b[12] += audioInFile1.samples[0][ticks] * 0.2;
    b[13] += x[13];
    b[14] += 9;
    b[15] += x[15];
    b[24] += x[24];
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[16][16] += pnC1.geq;
      b[16] += pnC1.ieq;
      A[17][17] += pnE1.geq;
      b[17] += pnE1.ieq;
      A[20][20] += pnC2.geq;
      b[20] += pnC2.ieq;
      A[21][21] += pnE2.geq;
      b[21] += pnE2.ieq;
      A[4][4] += digiNodes[2];
      A[4][10] += -digiNodes[2];
      A[10][4] += -digiNodes[2];
      A[10][10] += digiNodes[2];
      A[4][4] += digiNodes[3];
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      done &= pnC1.newtonJunctionPN(x[16]);
      done &= pnE1.newtonJunctionPN(x[17]);
      done &= pnC2.newtonJunctionPN(x[20]);
      done &= pnE2.newtonJunctionPN(x[21]);
      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[11] + 0;

  return (controls[3]*(output*controls[2])) + (1-controls[3]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
