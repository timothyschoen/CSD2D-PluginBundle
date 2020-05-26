#pragma once
struct JunctionPN
{
        // gMin for diodes etc..
        double gMin = 1e-12;

        // voltage tolerance
        double vTolerance = 5e-5;

        // thermal voltage for diodes/transistors
        double vThermal = 0.026;

        // variables
        double geq, ieq, veq;

        // parameters
        double is, nvt, rnvt, vcrit;

        void linearizeJunctionPN(double v);

        void initJunctionPN(double i, double n);

        // returns true if junction is good enough
        bool newtonJunctionPN(double v);
};
