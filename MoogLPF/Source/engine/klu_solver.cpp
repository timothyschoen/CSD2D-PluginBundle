#include "klu_solver.h"
#include <stdio.h>
#include <string.h>



// KLU is the solver I setteled for, since it was the fastest solver I tested by far
// KLU comes with SuiteSparse, and it is optimized for solving circuit equations
// It allows updating your factorization, which saves a massive amount of time as well
//
// It requires the matrix to be inputted in CSR (Compressed Sparse Representation)
// This means that we create an array of nonzero values, an array of column indexes
// and finally and array of the first nonzero position for each row




void KLU::init(int netsize,double* Ain)
{

        // Reduce the number of nets by one since we index from 1 (0 is a fake index for ground)
        rNets = netsize - 1;
        nNets = netsize;

        // Count the number of non-zero values
        for (int i = 0; i < rNets; i++)
                for (int j = 0; j < rNets; j++)
                        if (Ain[((j+1)*(rNets+1))+(i+1)] != 0)
                                nonzero++;

        // Allocate memory for CSR format
        Aai = new int[nNets];
        Aaj =  new int[nonzero];
        Aa =  new double[nonzero];


        // Pointers to the non-zero positions for updating the A matrix later on
        nzpointers = new double*[nonzero];
        // Amount of nonzeros for later use
        nonzero = 0;

        // Create our CSR format
        for (int i = 0; i < rNets; i++) {
                for (int j = 0; j < rNets; j++) {
                        if (Ain[((j+1)*(rNets+1))+(i+1)] != 0) {
                                Aa[nonzero] = Ain[((j+1)*(rNets+1))+(i+1)];
                                nzpointers[nonzero] = &Ain[((j+1)*(rNets+1))+(i+1)];
                                Aaj[nonzero] = j;

                                nonzero++;
                        }
                }
                Aai[i+1] = nonzero;
        }

        // Initialize KLU
        klu_defaults (&Common);

        // Symbolic analysis
        Symbolic = klu_analyze (rNets, Aai, Aaj, &Common);

        // Full numeric factorization: Only needed once!
        Numeric = klu_factor (Aai, Aaj, Aa, Symbolic, &Common);

}

void KLU::solve(double* Ain, double* b, double* x)
{
        // Update our nonzero values



        for (size_t i = 0; i < nonzero; i++) {
                Aa[i] = *(nzpointers[i]);
                printf("%G\n", b[i+1]);

        }



        // KLU writes the solution to the b array we pass it
        memcpy(x+1, b+1, (rNets)*sizeof(double));



        // Update our factorization
        klu_refactor (Aai, Aaj, Aa, Symbolic, Numeric, &Common);

        // Solve the system!
        klu_solve (Symbolic, Numeric, rNets, 1, x+1, &Common);

        for (size_t i = 0; i < rNets; i++) {
                //printf("%G\n", x[i]);
        }

}

void KLU::destroy()
{

        // Free solver
        klu_free_symbolic(&Symbolic, &Common);
        klu_free_numeric(&Numeric, &Common);


}
