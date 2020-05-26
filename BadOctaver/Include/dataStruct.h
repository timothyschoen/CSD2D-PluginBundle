#include "AudioFile.h"
#include "junctions.h"

struct DataStruct {

    int nets = 10;
int ticks = 0;
AudioFile<double> audioInFile1;
JunctionPN pn1;
JunctionPN pn2;
JunctionPN pn3;
JunctionPN pn4;

double A[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0.2,-0.1,-0.1,0,0,0.1,0,0,0.1},
                    {0,-0.1,0.2,0,0,-1,-0.1,0,0.1,0},
                    {0,-0.1,0,0.2,0,1,0,0.1,0,-0.1},
                    {0,1,0,0,-1,0,0,0,0,0},
                    {0,0,1,-1,0,0,0,0,0,0},
                    {0,0.1,-0.1,0,0,0,0,0,0,0},
                    {0,0,0,0.1,0,0,0,0,0,0},
                    {0,0,0.1,0,0,0,0,0,0,0},
                    {0,0.1,0,-0.1,0,0,0,0,0,0},
                    };

double A_prelu[10][10];

double b[10] = {0,0,0,0,0,0,0,0,0,0};

double b_prelu[10] = {0,0,0,0,0,0,0,0,0,0};

double x[10] = {0,0,0,0,0,0,0,0,0,0};

double digiNodes[1] = {0};

};
