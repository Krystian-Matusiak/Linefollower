#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include "Receiver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//#define sample 7
//#define ROZM 36





// //////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Klasa określa główne okienko aplikacje. W nim są wszystkie funkcje dotyczące wyświetlania. */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( DaneSensoryczne *DSENSORYCZNE , DaneSilnikowe *DSILNIKOWE , QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //void ZglosNapis(const QString &);

public slots:

    /*! Funkcja wyświetlająca dane czujnikowe w tabelii.
        \param c1 - wartość odczytana z czujnika 1.
        \param c2 - wartość odczytana z czujnika 2.
        \param c3 - wartość odczytana z czujnika 3.
        \param c4 - wartość odczytana z czujnika 4.
        \param c5 - wartość odczytana z czujnika 5.
        \param c6 - wartość odczytana z czujnika 6.
     */
    void setSensor_data_label(int c1, int c2, int c3, int c4, int c5, int c6);

    /*! Funkcja wyświetlająca dane dot. silników w tabelii.
        \param dir1 - kierunek obrotu pierwszego silnika.
        \param pwm1 - wypełnienie PWM dla pierwszego silnika.
        \param dir2 - kierunek obrotu drugiego silnika.
        \param pwm2 - wypełnienie PWM dla drugiego silnika.
     */
    void setMotor_data_label(int dir1, int pwm1, int dir2, int pwm2);

   // void GdyNapis(const QString &Napis);

    /*! Funkcja "nasłuchująca" dane oraz wykonująca się w nieskończoność, w celu ciągłej aktualizacji danych dot. czujników. */
    void GdySekunda();

    /*! Funkcja konfigurująca wygląd tła aplikacji. */
    void setBackground();

    /*! Funkcja przedstawiająca wizualnie kierunek i prędkość kół za pomocą strzałek, zmieniających swój rozmiar.
        \param pwm_left - zmienna przechowująca informacje o wypełnieniu PWM lewego silnika.
        \param pwm_right - zmienna przechowująca informacje o wypełnieniu PWM prawego silnika.
     */
    void setArrows(double pwm_left , double pwm_right);

    /*! Funkcja wyświetlająca dane dot. silników w tabelii. */
    void setButtons();

    /*! Funkcja konfigurująca wygląd tabel itp (np. ustawienie poziomu przezroczystości). */
    void setLabels();

    /*! Funkcja przedstawiająca wizualnie stan naładowania akumulatora.
        \param battery_state - przetrzymuje informacje o aktualnym stanie baterii.
     */
    void setBattery(double battery_state);

private slots:

    /*! Funkcja generująca wykres.*/
    void makePlot();

    /*! Funkcja generująca graf słupkowy, informujący o danych czujnikowych z transoptoprów.
        \param c1 - wartość odczytana z czujnika 1.
        \param c2 - wartość odczytana z czujnika 2.
        \param c3 - wartość odczytana z czujnika 3.
        \param c4 - wartość odczytana z czujnika 4.
        \param c5 - wartość odczytana z czujnika 5.
        \param c6 - wartość odczytana z czujnika 6.
     */
    void makeGraph(double c1, double c2, double c3, double c4, double c5, double c6);

private:
    Ui::MainWindow *ui;

    QTimer       _Sekundnik;

    DaneSensoryczne *DaneSen;
    DaneSilnikowe *DaneSil;

};
#endif // MAINWINDOW_H








