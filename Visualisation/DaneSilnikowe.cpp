#include "DaneSilnikowe.h"



void DaneSilnikowe::setPWM1(char parse_pwm1[3]){
    *pwm1 = strtod(parse_pwm1, NULL);
};



void DaneSilnikowe::setPWM2(char parse_pwm2[3]){
    *pwm2 = strtod(parse_pwm2, NULL);
};





void DaneSilnikowe::newPlotY(double *new_val){

    double tmp[sample];
    memcpy( tmp , plotY+1 , (sample-1)*sizeof(double) );
    tmp[sample-1]=*new_val;
    memcpy( plotY , tmp , sample*sizeof(double) );
};




void DaneSilnikowe::newPlotZ(double *new_val){

    double tmp[sample];
    memcpy( tmp , plotZ+1 , (sample-1)*sizeof(double) );
    tmp[sample-1]=*new_val;
    memcpy( plotZ , tmp , sample*sizeof(double) );
};
