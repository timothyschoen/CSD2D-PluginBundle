#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"
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

    A[17][17] += pnC1.geq + 1e-12;
    A[18][18] += pnE1.geq + 1e-12;
    A[21][21] += pnC2.geq + 1e-12;
    A[22][22] += pnE2.geq + 1e-12;
    b[25] = (0.02 * (x[13] - x[8]))-x[25];
    b[27] = (0.0000094 * (x[10] - x[0]))-x[27];
    b[29] = (2e-8 * (x[11] - x[6]))-x[29];
    b[30] = (0.44 * (x[4] - x[1]))-x[30];
    b[31] = (0.44 * (x[5] - x[14]))-x[31];
    A[14][14] += digiNodes[2] + 1e-12;
    A[14][1] += -digiNodes[2] + 1e-12;
    A[1][14] += -digiNodes[2] + 1e-12;
    A[1][1] += digiNodes[2] + 1e-12;
    A[14][14] += digiNodes[3] + 1e-12;
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    digiNodes[4] = std::clamp(digiNodes[1], 0.15, 0.85);
      digiNodes[2] = 1. / (10e3 * (digiNodes[4] + ((digiNodes[4] <= 0)*digiNodes[4]*0.1) - ((digiNodes[4] >= 1)*digiNodes[4]*0.1)));
      digiNodes[3] = 1. /(1. /digiNodes[2]) - (1. /10e3);
      
      digiNodes[1] = controls[1];
      
      
    b[16] += input * 0.5;
    b[25] += x[25];
    b[26] += 9;
    b[27] += x[27];
    b[28] += (x[11] - x[10]) + 44100 * x[28];
    b[29] += x[29];
    b[30] += x[30];
    b[31] += x[31];
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[17][17] += pnC1.geq;
      b[17] += pnC1.ieq;
      A[18][18] += pnE1.geq;
      b[18] += pnE1.ieq;
      A[21][21] += pnC2.geq;
      b[21] += pnC2.ieq;
      A[22][22] += pnE2.geq;
      b[22] += pnE2.ieq;
      A[14][14] += digiNodes[2];
      A[14][1] += -digiNodes[2];
      A[1][14] += -digiNodes[2];
      A[1][1] += digiNodes[2];
      A[14][14] += digiNodes[3];
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      done &= pnC1.newtonJunctionPN(x[17]);
      done &= pnE1.newtonJunctionPN(x[18]);
      done &= pnC2.newtonJunctionPN(x[21]);
      done &= pnE2.newtonJunctionPN(x[22]);
      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[15] + 0;

  return (controls[3]*(output*controls[2])) + (1-controls[3]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
