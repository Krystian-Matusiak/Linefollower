


#include "Receiver.h"





int Receiver::Odbierz(int GnOdbioru){
  ssize_t  IZ;

   while ( IZ = read(GnOdbioru,DANA, ROZM*sizeof(char) ) > 0 ){

       for(int i=0 ; i<3 ; i++){
        info1[0][i]=DANA[i];
        info1[1][i]=DANA[i+3];
        info1[2][i]=DANA[i+6];
        info1[3][i]=DANA[i+9];
        info1[4][i]=DANA[i+12];
        info1[5][i]=DANA[i+15];
      }

       // Przyjmowanie danych PWM1 i PWM2
      for( int i=0 ; i<3 ; i++ ){
          info1[6][i]=DANA[i+18];
          info1[8][i]=DANA[i+22];
      }

      // Przyjmowanie danych DIR1 i DIR2
      info1[7][0]=DANA[21];
      info1[9][0]=DANA[25];

      // Przyjmowanie danej BATT
      for(int i=0 ; i<4 ; i++)
        info1[10][i]=DANA[i+26];

      DSilniki->setPWM1(info1[6]);
      DSilniki->setPWM2(info1[8]);
      DSens->setSensors(info1);
      DSens->setBatt(info1[10]);
  }

  return 0;
}


int Receiver::UruchomServer(int Port){
  int  GnNasluchu;
  int  GnPolaczenia;

  struct sockaddr_in    cli_addr, serv_addr;
  socklen_t  ClAddrLen;


  if ((GnNasluchu = socket(AF_INET,SOCK_STREAM,0)) < 0) return -1;

  bzero((char *)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(Port);
  if (bind(GnNasluchu,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    return -2;
  }

  ClAddrLen = sizeof(cli_addr);

   if (listen(GnNasluchu,5) < 0)  return -3;

   while (1) {
    GnPolaczenia = accept(GnNasluchu,(struct sockaddr *)&cli_addr,&ClAddrLen);
    if (GnPolaczenia < 0) return -4;
    if (this->Odbierz(GnPolaczenia)) break;

    close(GnPolaczenia);
   }
  close(GnNasluchu);
}


void * Receiver::PetlaNasluchu(void *){
  UruchomServer(PORT_KOMUNIKACJI);
  return NULL;
}











