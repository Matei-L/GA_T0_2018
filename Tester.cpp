//
// Created by matei on 13.10.2018.
//

#include "Tester.h"

double Tester::T0Test(func tested_func,pair<double,double> Lims, unsigned int nrDim, unsigned int nrGen) {
    // random distribution init
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> dist(Lims.first,Lims.second);

    // Test
    double min = numeric_limits<double>::max();
    for(unsigned int g = 0;g<nrGen;++g)
    {
        double x[nrDim];

        for(unsigned int i = 0;i<nrDim;++i)
        {
            x[i] = dist(mt);
        }
        double rez = tested_func(nrDim,x);
        if(rez < min){
            min = rez;
        }
    }
    return min;
}

raport Tester::T0TestRepeater(func tested_func, pair<double, double> Lims, unsigned int nrDim, unsigned int nrGen,
                              unsigned int nrRep) {
    raport info;
    clock_t tStart = clock();

    info.min = T0Test(tested_func,Lims,nrDim,nrGen);
    info.max = info.min;
    info.med = info.min;
    double x[nrRep];
    x[0] = info.min;

    info.time_min = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    info.time_med = info.time_min;
    info.time_max = info.time_min;

    for(unsigned int i=1;i<nrRep;++i){
        tStart = clock();

        double rez = T0Test(tested_func,Lims,nrDim,nrGen);
        if(rez<info.min) info.min = rez;
        if(rez>info.max) info.max = rez;
        info.med+=rez;
        x[i] = rez;

        double time = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        if(time > info.time_max)info.time_max = time;
        if(time < info.time_min)info.time_min = time;
        info.time_med+=time;
    }
    info.time_med = info.time_med/nrRep;
    info.med = info.med / nrRep;
    for(unsigned int i = 0;i<nrRep;++i){
        info.sd+= pow((x[i] - info.med),2);
    }
    info.sd = info.sd/nrRep;
    info.sd = sqrt(info.sd);
    return info;
}

double Tester::T0TestSHCB(func tested_func, pair<double, double> LimsX1, pair<double, double> LimsX2, unsigned int nrGen) {
    // random distribution init
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> dist1(LimsX1.first,LimsX1.second);
    uniform_real_distribution<> dist2(LimsX2.first,LimsX2.second);

    // Test
    double min = numeric_limits<double>::max();
    for(unsigned int g = 0;g<nrGen;++g)
    {
        double x[2];
        x[0] = dist1(mt);
        x[1] = dist2(mt);
        double rez = tested_func(2,x);
        if(rez < min){
            min = rez;
        }
    }
    return min;
}

raport Tester::T0TestRepeaterSHCB(func tested_func, pair<double, double> LimsX1, pair<double, double> LimsX2,
                                  unsigned int nrGen, unsigned int nrRep) {
    raport info;
    clock_t tStart = clock();

    info.min = T0TestSHCB(tested_func,LimsX1,LimsX2,nrGen);
    info.max = info.min;
    info.med = info.min;
    double x[nrRep];
    x[0] = info.min;

    info.time_min = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    info.time_med = info.time_min;
    info.time_max = info.time_min;

    for(unsigned int i=1;i<nrRep;++i){
        tStart = clock();

        double rez = T0TestSHCB(tested_func,LimsX1,LimsX2,nrGen);
        if(rez<info.min) info.min = rez;
        if(rez>info.max) info.max = rez;
        info.med+=rez;
        x[i] = rez;

        double time = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        if(time > info.time_max)info.time_max = time;
        if(time < info.time_min)info.time_min = time;
        info.time_med+=time;
    }
    info.time_med = info.time_med/nrRep;
    info.med = info.med / nrRep;
    for(unsigned int i = 0;i<nrRep;++i){
        info.sd+= pow((x[i] - info.med),2);
    }
    info.sd = info.sd/nrRep;
    info.sd = sqrt(info.sd);
    return info;
}
