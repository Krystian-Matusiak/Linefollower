#ifndef DANESILNIKOWE_H
#define DANESILNIKOWE_H

#endif // DANESILNIKOWE_H


#include <string>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>

#define ROZM 30
#define sample 40


/*! \brief Klasa przechowująca dane dotyczące silników. */

class DaneSilnikowe{

    public:

        /*! Funkcja odpowiadająca za pobranie danej, dotyczącej wartości wypełnienia PWM dla silnika 1 (lewego).
            \param parse_pwm1 - tablica zmiennych typu charakter; jest to dana przetrzymujące informacje o wypełnieniu sygnału PWM dla lewego silnika.
         */
        void setPWM1(char parse_pwm1[3]);

        /*! Funkcja odpowiadająca za pobranie danej, dotyczącej wartości wypełnienia PWM dla silnika 2 (prawego).
            \param parse_pwm2 - tablica zmiennych typu charakter; jest to dana przetrzymujące informacje o wypełnieniu sygnału PWM dla prawego silnika.
         */
        void setPWM2(char parse_pwm2[3]);

        /*! Funkcja przetrzymująca i aktualizująca tablicę danych z wypełnieniem sygnału PWM silnika lewego. Następnie tablica wykorzystywana jest do wygenerowania wykresu, poprzez
         *  dopisywanie nowej wartości na koniec tablicy i usuwanie pierwszej wartości.
            \param new_val - wartość, która będzie wpisywana na koniec tablicy.
         */
        void newPlotY(double *new_val);

        /*! Funkcja przetrzymująca i aktualizująca tablicę danych z wypełnieniem sygnału PWM silnika prawego. Następnie tablica wykorzystywana jest do wygenerowania wykresu, poprzez
         *  dopisywanie nowej wartości na koniec tablicy i usuwanie pierwszej wartości.
            \param new_val - wartość, która będzie wpisywana na koniec tablicy.
         */
        void newPlotZ(double *new_val);


        char info1[11][ROZM];

        /* Wielkości pwm1 i pwm2 określają stan wypełnienia sygnału PWM (pulse width modulation) w procentach [%] */
        double *pwm1=new double;
        double *pwm2=new double;

        /* Zmienne dotyczące kierunku jazdy (false - jazda w tył, true - jazda w przód) */
        bool dir_motor1=false;
        bool dir_motor2=false;

        /* Zbiór wartości dla obu wykresów PWM */
        double plotY[sample];
        double plotZ[sample];
};
