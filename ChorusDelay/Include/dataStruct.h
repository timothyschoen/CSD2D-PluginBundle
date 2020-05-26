#include "AudioFile.h"
#include "junctions.h"

struct DataStruct {

    int nets = 6;
int ticks = 0;
AudioFile<double> audioInFile1;
double delayBuffer1[131072] = {0};
double delayBuffer2[131072] = {0};

double A[6][6] = {{0,0,0,0,0,0},
                    {0,-0.0039326340425531914894,-0.0002127659574468085,44100,0,0},
                    {0,-0.0002127659574468085,0.00021276595744680851064,0,-1,0},
                    {0,1.88e-7,0,-1,0,0},
                    {0,0,1,0,0,0},
                    {0,1,0,0,0,-1},
                    };

double A_prelu[6][6];

double b[6] = {0,0,0,0,0,0};

double b_prelu[6] = {0,0,0,0,0,0};

double x[6] = {0,0,0,0,0,0};

double digiNodes[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

};
