#include <QApplication>
#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QStatusBar>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <QListWidget>
#include <unistd.h>
#include <fstream>

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "serwer.hpp"

using namespace std;



SerwerGraficzny::SerwerGraficzny(char *Wiadomosc, QWidget *wRodzic): 
                        QWidget(wRodzic)
{
  _Wiadomosc = Wiadomosc;
  _ListaWiadm = new QListWidget(this);
  QHBoxLayout *wOrganizer = new QHBoxLayout();
  wOrganizer->addWidget(_ListaWiadm);
  setLayout(wOrganizer);
  connect(&_Sekundnik,SIGNAL(timeout()),this,SLOT(GdySekunda()));
  _Sekundnik.setInterval(300);
  _Sekundnik.setSingleShot(true);
  _Sekundnik.start();
}




void SerwerGraficzny::GdySekunda()
{
  fstream FILE;
  FILE.open("Dane_sensoryczne.txt");

  if (!*_Wiadomosc) { 
    _Sekundnik.start();
    return;
  }

  emit ZglosNapis(_Wiadomosc);
  FILE<<_Wiadomosc<<" ";
  _ListaWiadm->addItem(_Wiadomosc);
  *_Wiadomosc = 0;
  _Sekundnik.start();
}

void OknoGlowne::GdyNapis(const QString &Napis)
{
  statusBar()->showMessage(Napis);
}

OknoGlowne::OknoGlowne(char *Wiadomosc, QWidget *wRodzic): QMainWindow(wRodzic)
{
  SerwerGraficzny *wOkno = new SerwerGraficzny(Wiadomosc,this);
  setCentralWidget(wOkno);
  setStatusBar(new QStatusBar());
  connect(wOkno,SIGNAL(ZglosNapis(const QString &)),
          this,SLOT(GdyNapis(const QString &)));
}

