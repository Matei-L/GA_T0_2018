//
// Created by matei on 13.10.2018.
//

#ifndef T0_FUNCTIONREPOSITORY_H
#define T0_FUNCTIONREPOSITORY_H

#include <map>

using namespace std;

#define PI 3.14159265359

class FunctionRepository {
public:
    // public functions
    static double DeJong1(unsigned int n,double x[]);
    static double Schwefel7(unsigned int n,double x[]);
    static double Rastrigin6(unsigned int n,double x[]);
    static double SixHumpCamel(unsigned int n,double x[2]);

    static pair<double,double> getDeJong1Lims();
    static pair<double,double> getSchwefel7Lims();
    static pair<double,double> getRastrigin6Lims();
    static pair<double,double> getSixHumpCamelX1Lims();
    static pair<double,double> getSixHumpCamelX2Lims();

};

#endif //T0_FUNCTIONREPOSITORY_H
