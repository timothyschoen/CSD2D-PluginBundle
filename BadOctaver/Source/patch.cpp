#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "junctions.h"

#include "patch.h"


void Patch::init() {

    memcpy(A_prelu, A, sizeof(A));

    pn1.initJunctionPN(3.5e-11, 1.24);
    pn1.linearizeJunctionPN(0);

    pn2.initJunctionPN(3.5e-11, 1.24);
    pn2.linearizeJunctionPN(0);

    pn3.initJunctionPN(3.5e-11, 1.24);
    pn3.linearizeJunctionPN(0);

    pn4.initJunctionPN(3.5e-11, 1.24);
    pn4.linearizeJunctionPN(0);

    A[6][6] += pn1.geq + 1e-12;
    A[7][7] += pn2.geq + 1e-12;
    A[8][8] += pn3.geq + 1e-12;
    A[9][9] += pn4.geq + 1e-12;
    
    Solver.init(nets, &A[0][0]);
    }

double Patch::inout(double input) {

    ticks++;
    input *= controls[0];

    
      
      
    b[5] += input * 0.5;
    memcpy(b_prelu, b, sizeof(b));
    
    for(int iter = 0; iter < maxiter; iter++) {

      A[6][6] += 0.1+pn1.geq;
      b[6] += pn1.ieq;
      A[7][7] += 0.1+pn2.geq;
      b[7] += pn2.ieq;
      A[8][8] += 0.1+pn3.geq;
      b[8] += pn3.ieq;
      A[9][9] += 0.1+pn4.geq;
      b[9] += pn4.ieq;
      
      
      Solver.solve(&A[0][0], b, x);

      memcpy(b, b_prelu, sizeof(b));

      memcpy(A, A_prelu, sizeof(A));

      int done = 1;

      done &= pn1.newtonJunctionPN(x[6]);
      done &= pn2.newtonJunctionPN(x[7]);
      done &= pn3.newtonJunctionPN(x[8]);
      done &= pn4.newtonJunctionPN(x[9]);
      if(done) break;

    }

  memset(b, 0, sizeof(b));
  double output = x[4] + 0;

  return (controls[2]*(output*controls[1])) + (1-controls[2]) * input;
  
}

void Patch::destroy() {
  Solver.destroy();
  };
