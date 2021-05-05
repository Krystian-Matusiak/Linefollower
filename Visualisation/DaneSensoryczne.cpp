#include "DaneSensoryczne.h"





void DaneSensoryczne::setSensors(char parse_sensors[11][ROZM]){
    CzujnikiOdb[0] = strtod(parse_sensors[0], NULL);
    CzujnikiOdb[1] = strtod(parse_sensors[1], NULL);
    CzujnikiOdb[2] = strtod(parse_sensors[2], NULL);
    CzujnikiOdb[3] = strtod(parse_sensors[3], NULL);
    CzujnikiOdb[4] = strtod(parse_sensors[4], NULL);
    CzujnikiOdb[5] = strtod(parse_sensors[5], NULL);
};




void DaneSensoryczne::setBatt(char parse_batt[4]){
   batt = strtod( parse_batt , NULL );
};
