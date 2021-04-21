// Biblioteki ogólne

//#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>
#include <QBrush>
#include <QStatusBar>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QSpinBox>
#include <QFormLayout>
#include <QComboBox>
#include <QtCore/QFile>
#include <QDesktopWidget>
#include <QApplication>
#include <QtXml>
#include <string>

using namespace std;

// Biblioteki z plików nagłówkowych

#include "mainwindow.h"

// ///////////////////////////////////////////////////////////////////////////

#define ZN_KROTKI             4
#define ZN_DLUGI              8
#define MARGINES             10
#define ODSTEP_ZNAKU         16
#define PRZESUNIECIE_X        3

#define WSKSEK_D              8
#define PORT_KOMUNIKACJI   6000

#define WINDOW_X 600
#define WINDOW_Y 400

#define BUTTON_X 90
#define BUTTON_Y 30

#define PORT            6000

// ////////////////////////////////////////////////////////////////////////////

// KOD ZWIĄZANY Z SOCKET'AMI





DanePomiarowe *DP = new DanePomiarowe;
char info1[11][ROZM];

// Dane po kolei: Czuj1 Czuj2 Czuj3 Czuj4 Czuj5 Czuj6 PWM1 DIR1 PWM2 DIR2 BATT
char DANA[ROZM];

int Odbierz(int GnOdbioru){
  ssize_t  IZ;

   while ( IZ = read(GnOdbioru,DANA, ROZM*sizeof(char) ) > 0 ){

       for(int i=0 ; i<4 ; i++){
        info1[0][i]=DANA[i];
        info1[1][i]=DANA[i+4];
        info1[2][i]=DANA[i+8];
        info1[3][i]=DANA[i+12];
        info1[4][i]=DANA[i+16];
        info1[5][i]=DANA[i+20];
      }
      for( int i=0 ; i<3 ; i++ ){
          info1[6][i]=DANA[i+24];
          info1[8][i]=DANA[i+28];
      }
      info1[7][0]=DANA[27];
      info1[9][0]=DANA[31];
      for(int i=0 ; i<4 ; i++)
        info1[10][i]=DANA[i+32];

      DP->setPWM1(info1[6]);
      DP->setPWM2(info1[8]);
      DP->setSen(info1);
      DP->setBatt(info1[10]);
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


int main(int argc, char *argv[]){

    for(int i=0 ; i<8 ; i++)
        info1[i][0] = 0;



    pthread_t            Watek_Odbiornika;
    pthread_create(&Watek_Odbiornika,NULL,PetlaNasluchu,0L);

    QApplication a(argc, argv);
    MainWindow *W = new MainWindow(DP);
    W->show();

    W->Czuj_trans(1,1,0,0,0,23);
    W->Silniki(1,51,1,53);
    W->setLabels();
    W->setBackground();
    W->setButtons();

    W->setArrows(100.0, 100.0);



    int rez = a.exec();

    pthread_cancel(Watek_Odbiornika);
    pthread_join(Watek_Odbiornika,NULL);
    return rez;
}
