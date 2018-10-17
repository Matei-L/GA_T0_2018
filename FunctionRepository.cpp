//
// Created by matei on 13.10.2018.
//

#include "FunctionRepository.h"
#include <cmath>

double FunctionRepository::DeJong1(unsigned int n, double *x) {
    double sum = 0;
    for(unsigned int i = 0;i<n;++i){
        sum+=x[i]*x[i];
    }
    return sum;
}

double FunctionRepository::Schwefel7(unsigned int n, double *x) {
    double sum = 0;
    for(unsigned int i = 0;i<n;++i){
        sum-=x[i]*sin(sqrt(abs(x[i])));
    }
    return sum;
}

double FunctionRepository::Rastrigin6(unsigned int n, double *x) {
    double sum = 10*n;
    for(unsigned int i = 0;i<n;++i){
        sum+= x[i]*x[i] - 10*cos(2*PI*x[i]);
    }
    return sum;
}

double FunctionRepository::SixHumpCamel(unsigned int n,double *x) {
     return (4 - 2.1*pow(x[0], 2) + pow(x[0], 4) / 3)*pow(x[0], 2) + x[0]*x[1] + (-4 + 4 * pow(x[1], 2))*pow(x[1], 2);
}

pair<double, double> FunctionRepository::getDeJong1Lims() {
    return pair<double ,double>(-5.12,5.12);
}

pair<double, double> FunctionRepository::getSchwefel7Lims() {
    return pair<double ,double>(-500,500);
}

pair<double, double> FunctionRepository::getRastrigin6Lims() {
    return pair<double ,double>(-5.12,5.12);
}

pair<double, double> FunctionRepository::getSixHumpCamelX1Lims() {
    return pair<double ,double>(-3,3);
}
pair<double, double> FunctionRepository::getSixHumpCamelX2Lims() {
    return pair<double ,double>(-2,2);
}

