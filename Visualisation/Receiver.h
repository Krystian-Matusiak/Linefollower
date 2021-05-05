#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include "DaneSensoryczne.h"
#include "DaneSilnikowe.h"


#define ZN_KROTKI             4
#define ZN_DLUGI              8
#define MARGINES             10
#define ODSTEP_ZNAKU         16
#define PRZESUNIECIE_X        3

#define WSKSEK_D              8
#define PORT            6000
#define PORT_KOMUNIKACJI   6000


class Receiver{

public:

    int Odbierz(int GnOdbioru);

    int UruchomServer(int Port);

    void *PetlaNasluchu(void *);

    char DANA[ROZM];
    char info1[11][ROZM];

    DaneSensoryczne *DSens = new DaneSensoryczne;
    DaneSilnikowe *DSilniki = new DaneSilnikowe;

};








