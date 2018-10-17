//
// Created by matei on 13.10.2018.
//

#ifndef T0_T0TESTER_H
#define T0_T0TESTER_H

#include <random>
#include <climits>
#include <time.h>
using  namespace std;

typedef double (*func)(unsigned int,double*);
struct raport{
    double min;
    double max;
    double med;
    double sd;

    double time_min;
    double time_med;
    double time_max;
};

class Tester {
private:
    static double T0Test(func tested_func,pair<double,double> Lims,unsigned int nrDim, unsigned int nrGen);
    static double T0TestSHCB(func tested_func,pair<double,double> LimsX1,pair<double,double> LimsX2,unsigned int nrGen);
public:
    static raport T0TestRepeater(func tested_func,pair<double,double> Lims,unsigned int nrDim, unsigned int nrGen,unsigned int nrRep);
    static raport T0TestRepeaterSHCB(func tested_func,pair<double,double> LimsX1,pair<double,double> LimsX2, unsigned int nrGen,unsigned int nrRep);

};


#endif //T0_T0TESTER_H
