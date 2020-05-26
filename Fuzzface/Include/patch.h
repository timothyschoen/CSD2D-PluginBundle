#pragma once

#include "klu_solver.h"

#include "dataStruct.h"

struct Patch : public DataStruct
{

int maxiter = 10;

double controls[16] = {0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3};
KLU Solver;

void init();

double inout(double input);

void destroy();

void setSlider(int index, double value);


void setIterations(int q){
maxiter = q;
};

};
