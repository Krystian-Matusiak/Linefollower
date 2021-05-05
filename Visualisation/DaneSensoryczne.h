#ifndef DANESENSORYCZNE_H
#define DANESENSORYCZNE_H

#endif // DANESENSORYCZNE_H


#include <string>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>

#define ROZM 30




/*! \brief Klasa przechowująca dane dotyczące wykonanych pomiarów (czujniki i bateria). */

class DaneSensoryczne{

    public:

        /*! Uzupełnia dane pobrane z czujników odbiciowych.
            \param parse_sensors - zestaw danych, przechowujących informacje o odczytach z czujników.
         */
        void setSensors(char parse_sensors[11][ROZM]);

        /*! Wypełnia daną, związaną z poziomem naładowania akumulatora
            \param parse_batt - tablica, przechowująca dane o aktualnym napięciu akumulatora.
         */
        void setBatt(char parse_batt[4]);


        char info1[11][ROZM];

        /* Wartości wszystkich czujników odbiciowych */
        double CzujnikiOdb[6];

        /* Zmienna przechowująca dane o naładowaniu baterii */
        double batt;
};
