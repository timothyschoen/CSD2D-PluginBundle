#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"
#include "patch.h"


void Patch::init() {

    memcpy(A_prelu, A, sizeof(A));

    b[3] = (9.4e-8 * (x[1] - x[0]))-x[3];
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    digiNodes[22] = ticks & 131071;
      digiNodes[23] = digiNodes[23] * 0.998 + (digiNodes[2] + digiNodes[12]) * 0.002;
      delayBuffer1[(int)digiNodes[22]] = (digiNodes[1] + digiNodes[6]);
      digiNodes[24] = ticks & 131071;
      digiNodes[25] = digiNodes[25] * 0.998 + (digiNodes[4] + digiNodes[10]) * 0.002;
      delayBuffer2[(int)digiNodes[24]] = (digiNodes[3] + digiNodes[7]);
      digiNodes[26] = (digiNodes[13] + digiNodes[14]) * 0.3;
      digiNodes[27] = digiNodes[5] * digiNodes[20];
      digiNodes[28] = digiNodes[8] * digiNodes[21];
      digiNodes[29] = sin(2*3.1415 * ((digiNodes[18] / 44100)*ticks));
      digiNodes[30] = digiNodes[9] * digiNodes[16];
      digiNodes[31] = 80. - digiNodes[11];
      digiNodes[32] = digiNodes[15] * 400.;
      digiNodes[33] = digiNodes[17] * 10.;
      digiNodes[34] = digiNodes[19] * 0.9;
      
      digiNodes[8] = delayBuffer1[(int)(digiNodes[22] - digiNodes[23]) + (digiNodes[22] - digiNodes[23] <= 0)*131072];
      digiNodes[14] = delayBuffer1[(int)(digiNodes[22] - digiNodes[23]) + (digiNodes[22] - digiNodes[23] <= 0)*131072];
      digiNodes[1] = x[5];
      digiNodes[3] = x[5];
      digiNodes[2] = 20000;
      digiNodes[5] = delayBuffer2[(int)(digiNodes[24] - digiNodes[25]) + (digiNodes[24] - digiNodes[25] <= 0)*131072];
      digiNodes[13] = delayBuffer2[(int)(digiNodes[24] - digiNodes[25]) + (digiNodes[24] - digiNodes[25] <= 0)*131072];
      digiNodes[4] = 8000;
      digiNodes[6] = digiNodes[27];
      digiNodes[7] = digiNodes[28];
      digiNodes[9] = digiNodes[29];
      digiNodes[10] = digiNodes[30];
      digiNodes[11] = digiNodes[30];
      digiNodes[12] = digiNodes[31];
      digiNodes[15] = controls[1];
      digiNodes[16] = digiNodes[32];
      digiNodes[17] = controls[2];
      digiNodes[18] = digiNodes[33];
      digiNodes[19] = controls[3];
      digiNodes[20] = digiNodes[34];
      digiNodes[21] = digiNodes[34];
      
      
    b[3] += x[3];
    b[4] += input * 0.5;
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = digiNodes[26] + 0;

  return (controls[5]*(output*controls[4])) + (1-controls[5]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
