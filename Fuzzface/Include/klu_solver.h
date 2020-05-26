#pragma once
#include "klu.h"

struct KLU {

        klu_symbolic *Symbolic;
        klu_numeric *Numeric;
        klu_common Common;

        double* Aa;
        double** nzpointers;
        int* Aai;
        int* Aaj;

        int nonzero = 0; // ironic

        int rNets;
        int nNets;

        void init(int netsize, double* A);
        void solve(double*, double*, double*);

        void destroy();

};
