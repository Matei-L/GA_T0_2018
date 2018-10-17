#include <iostream>
#include "FunctionRepository.h"
#include "Tester.h"

using namespace std;

int main() {
    raport final_rap;
    unsigned int option,nrDim,nrGen,nrRep;
    while(true) {
        printf("Buna ziua!\n");
        printf("Pentru ce functie doriti sa calculati minimul?\n");
        printf("Optiuni:\n1) De Jong 1\n2) Schwefel 7\n3) Rastrigin 6\n4) Six-hump camel back\n");
        printf("0) Pentru oprirea algoritmului.\n");
        printf("Optiunea dumneavoastra: ");
        scanf("%u", &option);

        if (option > 4) {
            printf("Va rugam introduceti o optiune valabila.\n\n");
            continue;
        }
        if (option == 0){
            break;
        }

        printf("Numarul de dimensiuni:");
        scanf("%u", &nrDim);
        printf("Numarul de parametri generati intr-o rulare:");
        scanf("%u", &nrGen);
        printf("Numarul de rulari:");
        scanf("%u", &nrRep);

        switch (option) {
            case 1:
                final_rap = Tester::T0TestRepeater(FunctionRepository::DeJong1,FunctionRepository::getDeJong1Lims()
                        ,nrDim,nrGen,nrRep);
                break;
            case 2:
                final_rap = Tester::T0TestRepeater(FunctionRepository::Schwefel7,FunctionRepository::getSchwefel7Lims()
                        ,nrDim,nrGen,nrRep);
                break;
            case 3:
                final_rap = Tester::T0TestRepeater(FunctionRepository::Rastrigin6,FunctionRepository::getRastrigin6Lims()
                        ,nrDim,nrGen,nrRep);
                break;
            case 4:
                final_rap = Tester::T0TestRepeaterSHCB(FunctionRepository::SixHumpCamel,FunctionRepository::getSixHumpCamelX1Lims(),
                        FunctionRepository::getSixHumpCamelX2Lims(),nrGen,nrRep);
                break;
        }
        printf("Minumul gasit = %lf\nMaximul gasit = %lf\nMedia gasita = %lf\nDeviatia standard = %lf\n\n",
                final_rap.min,final_rap.max,final_rap.med,final_rap.sd);
        printf("Timpul minim al unei rulari: %lf s\nTimpul maxim al unei rulari: %lf s\nTimpul mediu al unei rulari: %lf s\n\n",
                final_rap.time_min,final_rap.time_max,final_rap.time_med);
    }
    printf("O zi buna.\n");
    return 0;
}