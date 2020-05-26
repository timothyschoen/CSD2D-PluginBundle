#include <cmath>
#include <iosfwd>
#include "../include/junctions.h"


// linearize junction at the specified voltage
//
// ideally we could handle series resistance here as well
// to avoid putting it on a separate node, but not sure how
// to make that work as it looks like we'd need Lambert-W then

void JunctionPN::linearizeJunctionPN(double v)
{
        double e = is * exp(v * rnvt);
        double i = e - is + gMin * v;
        double g = e * rnvt + gMin;

        geq = g;
        ieq = v*g - i;
        veq = v;
}


void JunctionPN::initJunctionPN(double i, double n)
{
        is = i;
        nvt = n * vThermal;
        rnvt = 1 / nvt;
        vcrit = nvt * log(nvt / (is * sqrt(2.)));
}



// returns true if junction is good enough
bool JunctionPN::newtonJunctionPN(double v)
{
        double dv = v - veq;
        if(fabs(dv) < vTolerance) return true;

        // check critical voltage and adjust voltage if over
        if(v > vcrit)
        {
                // this formula comes from Qucs documentation
                v = veq + nvt*log((fmax)(is, 1+dv*rnvt));
        }

        linearizeJunctionPN(v);

        return false;
}
