// Biblioteki ogólne

//#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>
#include <QBrush>
#include <QStatusBar>

/*
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
*/

using namespace std;

// Biblioteki z plików nagłówkowych

#include "mainwindow.h"

// ////////////////////////////////////////////////////////////////////////////

// KOD ZWIĄZANY Z SOCKET'AMI



/*
DaneSensoryczne *DSen = new DaneSensoryczne;
DaneSilnikowe *DSil = new DaneSilnikowe;


// Dane po kolei: Czuj1 Czuj2 Czuj3 Czuj4 Czuj5 Czuj6 PWM1 DIR1 PWM2 DIR2 BATT
char DANA[ROZM];
char info1[11][ROZM];

int Odbierz(int GnOdbioru){
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

      DSil->setPWM1(info1[6]);
      DSil->setPWM2(info1[8]);
      DSen->setSensors(info1);
      DSen->setBatt(info1[10]);
  }

  return 0;
}


int UruchomServer(int Port){
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
    if (Odbierz(GnPolaczenia)) break;

    close(GnPolaczenia);
   }
  close(GnNasluchu);
}

void *PetlaNasluchu(void *){
  UruchomServer(PORT_KOMUNIKACJI);
  return NULL;
}

// ////////////////////////////////////////////////////////////////////////////
*/
Receiver *receive = new Receiver;

void *Petla_odbiornika(void *){
  receive->UruchomServer(PORT_KOMUNIKACJI);
  return NULL;
}

int main(int argc, char *argv[]){


    //Receiver *receive = new Receiver;

    //pthread_t            Watek_Odbiornika;
    //pthread_create(&Watek_Odbiornika,NULL,PetlaNasluchu,0L);

    pthread_t            Watek2;
    pthread_create(&Watek2,NULL,Petla_odbiornika,0L);

    QApplication App (argc, argv);
    MainWindow *Wind = new MainWindow(receive->DSens,receive->DSilniki);

    Wind->show();
    Wind->setBackground();



    int end = App.exec();

    //pthread_cancel(Watek_Odbiornika);
    //pthread_join(Watek_Odbiornika,NULL);

    pthread_cancel(Watek2);
    pthread_join(Watek2,NULL);

    return end;
}
