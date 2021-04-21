#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include "serwer.hpp"
#include <string>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define sample 7
#define ROZM 36


class DanePomiarowe{

public:
    void setSensors(char tab[11][ROZM]){
      for(int i=0 ; i<11 ; i++)
          copy(tab[i] , tab[i]+ROZM , info1[i] );
    };
    void setPWM1(char parse[4]){
        *pwm1 = strtod(parse, NULL);
    };
    void setPWM2(char parse[4]){
        *pwm2 = strtod(parse, NULL);
    };
    void setSen(char parse[11][ROZM]){
        CzujnikiOdb[0] = strtod(parse[0], NULL);
        CzujnikiOdb[1] = strtod(parse[1], NULL);
        CzujnikiOdb[2] = strtod(parse[2], NULL);
        CzujnikiOdb[3] = strtod(parse[3], NULL);
        CzujnikiOdb[4] = strtod(parse[4], NULL);
        CzujnikiOdb[5] = strtod(parse[5], NULL);
    };
    void setBatt(char parse[4]){
       batt = strtod( parse , NULL );
    };
    void newPlotY(double *val){

        double tmp[sample];
        memcpy( tmp , plotY+1 , (sample-1)*sizeof(double) );
        tmp[sample-1]=*val;
        memcpy( plotY , tmp , sample*sizeof(double) );
    };
    void newPlotZ(double *val){

        double tmp[sample];
        memcpy( tmp , plotZ+1 , (sample-1)*sizeof(double) );
        tmp[sample-1]=*val;
        memcpy( plotZ , tmp , sample*sizeof(double) );
    };
    /*
    void newPlotY(double *val){
        double tmp[sample];
        for(int i=0 ; i<sample-1 ; i++)
            tmp[i]=plotY[i+1];
        tmp[sample-1]=*val;
        copy(tmp , tmp+sample , plotY);
    };
    void newPlotZ(double *val){
        double tmp[sample];
        for(int i=0 ; i<sample-1 ; i++)
            tmp[i]=plotZ[i+1];
        tmp[sample-1]=*val;
        copy(tmp , tmp+sample , plotZ);
    };*/


    char info1[11][ROZM];

    /* Wartości wszystkich czujników odbiciowych */
    double CzujnikiOdb[6];

    /* Wielkości pwm1 i pwm2 określają stan wypełnienia sygnału PWM (pulse width modulation) w procentach [%] */
    double *pwm1=new double;
    double *pwm2=new double;

    /* Zmienne dotyczące kierunku jazdy (false - jazda w tył, true - jazda w przód) */
    bool dir_motor1=false;
    bool dir_motor2=false;

    /* Zmienna przechowująca dane o naładowaniu baterii */
    double batt;

    /* Zbiór wartości dla obu wykresów PWM */
    double plotY[sample];
    double plotZ[sample];
};


// //////////////////////////////////////////////////////////////////////////////////////////////////////////////


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DanePomiarowe * DP, QWidget *parent = nullptr);
    ~MainWindow();
    string      *S=new string;

signals:
    void ZglosNapis(const QString &);

public slots:
    void Czuj_trans(int c1, int c2, int c3, int c4, int c5, int c6);
    void Silniki(int dir1, int pwm1, int dir2, int pwm2);
    void GdyNapis(const QString &Napis);
    void GdySekunda();
    void setBackground();
    void setArrows(double pwm_left , double pwm_right);
    void setButtons();
    void setLabels();
    void setBattery(double battery_state);

private slots:
    //void makePlot();
    void makePlot();
    void makeGraph(double c1, double c2, double c3, double c4, double c5, double c6);

private:
    Ui::MainWindow *ui;

    QTimer       _Sekundnik;
    char        *_Wiadomosc;
    char        *_Wiadomosc2;
    char        *_Wiadomosc3;
    char        *_Wiadomosc4;

    double      *PWM1;
    double      PWM2;
    QListWidget *_ListaWiadm;
    DanePomiarowe *DaneSensoryczne;

};
#endif // MAINWINDOW_H

















