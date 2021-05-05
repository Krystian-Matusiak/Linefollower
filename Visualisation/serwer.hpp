
#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QListWidget>

using namespace std;


/*! \brief Klasa odpowiadająca za otrzymywanie danych z transmisji poprzez gniazda. */


class SerwerGraficzny: public QWidget { //---------------------------------------
    Q_OBJECT
  public:
    SerwerGraficzny(char *Wiadomosc, QWidget *wRodzic = 0L);

  public slots:
    void GdySekunda(); 

  signals:  
    void ZglosNapis(const QString &);

  private:
    QTimer       _Sekundnik;
    char        *_Wiadomosc;
    QListWidget *_ListaWiadm;

}; //------------------------------------------------------------------


class OknoGlowne: public QMainWindow { //------------------------------
   Q_OBJECT
  public:
   OknoGlowne(char *Wiadomosc, QWidget *wRodzic = 0L);
  public slots:
   void GdyNapis(const QString &);
}; //------------------------------------------------------------------

