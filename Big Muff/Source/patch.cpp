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

    pn1.initJunctionPN(3.5e-11, 1.24);
    pn1.linearizeJunctionPN(0);

    pn2.initJunctionPN(3.5e-11, 1.24);
    pn2.linearizeJunctionPN(0);

    pnC3.initJunctionPN(6.760936e-15, 1.24);
    pnC3.linearizeJunctionPN(0);

    pnE3.initJunctionPN(7.0707e-15, 1.24);
    pnE3.linearizeJunctionPN(0);

    pn3.initJunctionPN(3.5e-11, 1.24);
    pn3.linearizeJunctionPN(0);

    pn4.initJunctionPN(3.5e-11, 1.24);
    pn4.linearizeJunctionPN(0);

    pnC4.initJunctionPN(6.760936e-15, 1.24);
    pnC4.linearizeJunctionPN(0);

    pnE4.initJunctionPN(7.0707e-15, 1.24);
    pnE4.linearizeJunctionPN(0);

    A[31][31] += pnC1.geq + 1e-12;
    A[32][32] += pnE1.geq + 1e-12;
    A[35][35] += pnC2.geq + 1e-12;
    A[36][36] += pnE2.geq + 1e-12;
    b[39] = (0.000002 * (x[10] - x[7]))-x[39];
    b[40] = (9.4e-10 * (x[7] - x[8]))-x[40];
    b[41] = (0.000002 * (x[8] - x[11]))-x[41];
    b[42] = (2e-7 * (x[12] - x[14]))-x[42];
    b[43] = (9.4e-10 * (x[4] - x[5]))-x[43];
    A[44][44] += pn1.geq + 1e-12;
    b[45] = (0.000002 * (x[4] - x[15]))-x[45];
    A[46][46] += pn2.geq + 1e-12;
    b[47] = (2e-7 * (x[5] - x[16]))-x[47];
    A[48][48] += pnC3.geq + 1e-12;
    A[49][49] += pnE3.geq + 1e-12;
    b[52] = (9.4e-10 * (x[17] - x[18]))-x[52];
    b[53] = (0.000002 * (x[17] - x[20]))-x[53];
    A[54][54] += pn3.geq + 1e-12;
    b[55] = (8e-9 * (x[18] - x[21]))-x[55];
    A[56][56] += pn4.geq + 1e-12;
    b[57] = (0.00002 * (x[22] - x[0]))-x[57];
    b[58] = (2e-7 * (x[23] - x[24]))-x[58];
    A[59][59] += pnC4.geq + 1e-12;
    A[60][60] += pnE4.geq + 1e-12;
    b[63] = (2e-7 * (x[25] - x[27]))-x[63];
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    b[29] += input * 0.5;
    b[30] += 9;
    b[39] += x[39];
    b[40] += x[40];
    b[41] += x[41];
    b[42] += x[42];
    b[43] += x[43];
    b[45] += x[45];
    b[47] += x[47];
    b[52] += x[52];
    b[53] += x[53];
    b[55] += x[55];
    b[57] += x[57];
    b[58] += x[58];
    b[63] += x[63];
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[31][31] += pnC1.geq;
      b[31] += pnC1.ieq;
      A[32][32] += pnE1.geq;
      b[32] += pnE1.ieq;
      A[35][35] += pnC2.geq;
      b[35] += pnC2.ieq;
      A[36][36] += pnE2.geq;
      b[36] += pnE2.ieq;
      A[44][44] += 0.1+pn1.geq;
      b[44] += pn1.ieq;
      A[46][46] += 0.1+pn2.geq;
      b[46] += pn2.ieq;
      A[48][48] += pnC3.geq;
      b[48] += pnC3.ieq;
      A[49][49] += pnE3.geq;
      b[49] += pnE3.ieq;
      A[54][54] += 0.1+pn3.geq;
      b[54] += pn3.ieq;
      A[56][56] += 0.1+pn4.geq;
      b[56] += pn4.ieq;
      A[59][59] += pnC4.geq;
      b[59] += pnC4.ieq;
      A[60][60] += pnE4.geq;
      b[60] += pnE4.ieq;
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      done &= pnC1.newtonJunctionPN(x[31]);
      done &= pnE1.newtonJunctionPN(x[32]);
      done &= pnC2.newtonJunctionPN(x[35]);
      done &= pnE2.newtonJunctionPN(x[36]);
      done &= pn1.newtonJunctionPN(x[44]);
      done &= pn2.newtonJunctionPN(x[46]);
      done &= pnC3.newtonJunctionPN(x[48]);
      done &= pnE3.newtonJunctionPN(x[49]);
      done &= pn3.newtonJunctionPN(x[54]);
      done &= pn4.newtonJunctionPN(x[56]);
      done &= pnC4.newtonJunctionPN(x[59]);
      done &= pnE4.newtonJunctionPN(x[60]);
      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[28] + 0;

  return (controls[2]*(output*controls[1])) + (1-controls[2]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
