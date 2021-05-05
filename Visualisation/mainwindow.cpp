#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <unistd.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;


double val = 0;
int dir=1;



void MainWindow::GdySekunda(){

  /*if (!*_Wiadomosc) {
    _Sekundnik.start();
    return;
  }*/
  _Sekundnik.start();

  ui->PWM_lewo_val->setText(QString::number(*DaneSil->pwm1));
  if(DaneSil->dir_motor1)   ui->Kier_lewo_val->setText("Przod");
  else  ui->Kier_lewo_val->setText("Tył");

  ui->PWM_prawo_val->setText(QString::number(*DaneSil->pwm2));
  if(DaneSil->dir_motor2)   ui->Kier_prawo_val->setText("Przod");
  else  ui->Kier_prawo_val->setText("Tył");

  // Wypisywanie w tabeli danych czujnikowych
  ui->Czuj1_val->setText( QString::number( DaneSen->CzujnikiOdb[0] ) );
  ui->Czuj2_val->setText( QString::number( DaneSen->CzujnikiOdb[1] ) );
  ui->Czuj3_val->setText( QString::number( DaneSen->CzujnikiOdb[2] ) );
  ui->Czuj4_val->setText( QString::number( DaneSen->CzujnikiOdb[3] ) );
  ui->Czuj5_val->setText( QString::number( DaneSen->CzujnikiOdb[4] ) );
  ui->Czuj6_val->setText( QString::number( DaneSen->CzujnikiOdb[5] ) );

  // Uaktualnienie danych związanych z wykresem
  DaneSil->newPlotY(DaneSil->pwm1);
  DaneSil->newPlotZ(DaneSil->pwm2);


  makeGraph( DaneSen->CzujnikiOdb[0],
             DaneSen->CzujnikiOdb[1],
             DaneSen->CzujnikiOdb[2],
             DaneSen->CzujnikiOdb[3],
             DaneSen->CzujnikiOdb[4],
             DaneSen->CzujnikiOdb[5]
          );
  makePlot();
  setArrows( *DaneSil->pwm1 , *DaneSil->pwm2 );
  setBattery(*DaneSil->pwm1);

  //*_Wiadomosc = 0;
  _Sekundnik.start();
}


MainWindow::MainWindow( DaneSensoryczne *DSENSORYCZNE , DaneSilnikowe *DSILNIKOWE , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DaneSen = DSENSORYCZNE;
    DaneSil = DSILNIKOWE;

    connect(&_Sekundnik,SIGNAL(timeout()),this,SLOT(GdySekunda()));
    _Sekundnik.setInterval(5);
    _Sekundnik.setSingleShot(true);
    _Sekundnik.start();

    setBackground();
    setLabels();
    setButtons();
    setSensor_data_label(1,1,0,0,0,23);
    setMotor_data_label(1,51,1,53);
    setBattery(DaneSen->batt);
    setArrows(100.0, 100.0);

    makePlot();
    makeGraph( DaneSen->CzujnikiOdb[0],
               DaneSen->CzujnikiOdb[1],
               DaneSen->CzujnikiOdb[2],
               DaneSen->CzujnikiOdb[3],
               DaneSen->CzujnikiOdb[4],
               DaneSen->CzujnikiOdb[5]
            );
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBackground(){

    int w= ui->centralwidget->width();
    int h= ui->centralwidget->width();

    QImage img("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/bk2.jpg");
    QImage IMG = img.scaled(w, h, Qt::KeepAspectRatio);
    QPalette palette;

    palette.setBrush(QPalette::Background, IMG);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

}

void MainWindow::setArrows(double pwm_left ,double pwm_right){

    QPixmap LF_pix("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/lf.png");
    QPixmap green_pix("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/greenarrow.png");
    QPixmap red_pix("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/redarrow.png");

    green_pix = green_pix.scaled(  (ui->LEFT_DOWN->width() * pwm_left)/100,
                                   (ui->LEFT_DOWN->height() * pwm_left)/100,
                                   Qt::IgnoreAspectRatio,
                                   Qt::FastTransformation);
    red_pix = red_pix.scaled(  (ui->LEFT_DOWN->width() * pwm_right)/100,
                               (ui->LEFT_DOWN->height() * pwm_right)/100,
                               Qt::IgnoreAspectRatio,
                               Qt::FastTransformation);

    ui->LF->setScaledContents(true);
    ui->LF->setPixmap(LF_pix);

    ui->LEFT_UP->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->LEFT_DOWN->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->RIGHT_UP->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->RIGHT_DOWN->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->LEFT_UP->setPixmap(green_pix);
    ui->LEFT_DOWN->setPixmap(red_pix);

    ui->RIGHT_UP->setPixmap(green_pix);
    ui->RIGHT_DOWN->setPixmap(red_pix);
}

void MainWindow::setBattery(double battery_state){

    QPixmap batt_25("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/BAT_25.png");
    QPixmap batt_50("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/BAT_50.png");
    QPixmap batt_75("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/BAT_75.png");
    QPixmap batt_100("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/BAT_100.png");
    QPixmap actual_state;

    if( battery_state <=25)
        actual_state = batt_25;
    if( battery_state <70 && battery_state>25)
        actual_state = batt_50;
    if( battery_state <95 && battery_state>=70)
        actual_state = batt_75;
    if( battery_state >=95)
    //else
        actual_state = batt_100;

    actual_state = actual_state.scaled( ui->Battery->width() ,ui->Battery->height(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->Battery->setPixmap(actual_state);
    ui->Battery_state->setText( QString::number(battery_state)+"%" );
}

void MainWindow::setLabels(){
    ui->label_12->setStyleSheet("QLabel {border-style: solid; border-width: 1px;border-color: black;}");
    ui->label_13->setStyleSheet("QLabel {border-style: solid; border-width: 1px;border-color: black;}");
    ui->label_15->setStyleSheet("QLabel {border-style: solid; border-width: 1px;border-color: black;}");

    ui->Frame_Data->setStyleSheet("background-color: rgb(255, 255, 255,170);");
    ui->Frame_Motors->setStyleSheet("background-color: rgb(255, 255, 255,170);");
    ui->Frame_Plot->setStyleSheet("background-color: rgb(255, 255, 255,170);");
    ui->Frame_Battery->setStyleSheet("background-color: rgb(255, 255, 255,170);");
}

void MainWindow::setButtons(){
    QPixmap right("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/ARROW_RIGHT.png");
    QPixmap left("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/ARROW_LEFT.png");
    QPixmap up("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/ARROW_UP.png");
    QPixmap down("/home/krystianm/CODING/SEMESTR6/WDS/proj1/WDS1/ARROW_DOWN.png");

    QIcon right_i(right);
    QIcon left_i(left);
    QIcon up_i(up);
    QIcon down_i(down);

    QSize img_size( ui->UP_BUTTON->width()-10 , ui->UP_BUTTON->height()-10 );

    ui->RIGHT_BUTTON->setIcon(right_i);
    ui->RIGHT_BUTTON->setIconSize(img_size);
    ui->LEFT_BUTTON->setIcon(left_i);
    ui->LEFT_BUTTON->setIconSize(img_size);
    ui->UP_BUTTON->setIcon(up_i);
    ui->UP_BUTTON->setIconSize(img_size);
    ui->DOWN_BUTTON->setIcon(down_i);
    ui->DOWN_BUTTON->setIconSize(img_size);
}

void MainWindow::setSensor_data_label(int c1, int c2, int c3, int c4, int c5, int c6){
    //QString qstr = QString::fromStdString(*str);

    ui->Czuj1_txt->setText("Wskazanie transoptora 1: ");
    ui->Czuj2_txt->setText("Wskazanie transoptora 2: ");
    ui->Czuj3_txt->setText("Wskazanie transoptora 3: ");
    ui->Czuj4_txt->setText("Wskazanie transoptora 4: ");
    ui->Czuj5_txt->setText("Wskazanie transoptora 5: ");
    ui->Czuj6_txt->setText("Wskazanie transoptora 6: ");

    ui->Czuj1_val->setText(QString::number(c1));
    ui->Czuj2_val->setText(QString::number(c2));
    ui->Czuj3_val->setText(QString::number(c3));
    ui->Czuj4_val->setText(QString::number(c4));
    ui->Czuj5_val->setText(QString::number(c5));
    ui->Czuj6_val->setText(QString::number(c6));
}

void MainWindow::setMotor_data_label(int dir1, int pwm1, int dir2, int pwm2){
    ui->Kier_lewo_txt->setText("Kierunek jazdy lewego silnika: ");
    ui->PWM_lewo_txt->setText("Prędkość jazdy lewego silnika: ");
    ui->Kier_prawo_txt->setText("Kierunek jazdy prawego silnika: ");
    ui->PWM_prawo_txt->setText("Prędkość jazdy prawego silnika: ");

    ui->Kier_lewo_val->setText(QString::number(dir1));
    ui->PWM_lewo_val->setText(QString::number(pwm1));
    ui->Kier_prawo_val->setText(QString::number(dir2));
    ui->PWM_prawo_val->setText(QString::number(pwm2));
}


void MainWindow::makePlot(){
    QVector<double> x(sample), y(sample) , z(sample); // initialize with entries 0..100
    int beg=0;
    int end=10;
    QVector<double> xx(sample), yy(sample) , zz(sample); // initialize with entries 0..100


    for (double i=0; i<sample; ++i)
    {
      x[i] = end*i/sample ;
      y[(int)i] = DaneSil->plotY[(int)i] ;
      z[(int)i] = DaneSil->plotZ[(int)i] ;
    }



    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(x, z);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(beg, end);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine));
    ui->customPlot->yAxis->setRange(0, 100);
    ui->customPlot->replot();



    QPen COLOR1;
    COLOR1.setWidth(1);
    COLOR1.setColor(QColor(40,200,40));
    COLOR1.setWidth(2);
    QPen COLOR2;
    COLOR2.setWidth(1);
    COLOR2.setColor(QColor(220,40,40));
    COLOR2.setWidth(2);

    ui->customPlot->setBackground(Qt::GlobalColor::transparent);
    ui->customPlot->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->customPlot->graph(0)->setPen(COLOR1);
    ui->customPlot->graph(1)->setPen(COLOR2);
    ui->customPlot->replot();
}



void MainWindow::makeGraph(double c1, double c2, double c3, double c4, double c5, double c6){

    QBarSet *set0 = new QBarSet("Czujniki");
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QStringList categories;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QValueAxis *axisY = new QValueAxis();

    axisX->setGridLineColor(QColor(0, 0, 0));
    axisY->setGridLineColor(QColor(0, 0, 0));

    *set0 << c1 << c2 << c3 << c4 << c5 << c6;
    series->append(set0);//set0);

    chart->addSeries(series);
    chart->setTitle("Stany czujników odbiciowych");

    /* Opis osi X */
    categories << "Cz1" << "Cz2" << "Cz3" << "Cz4" << "Cz5" << "Cz6";
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    /* Opis osi Y */
    axisY->setRange(0,260);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundVisible(false);
    ui->SensorBar->setChart(chart);
    ui->SensorBar->setRenderHint(QPainter::Antialiasing);

}










