/*Scriviamo un programma che istanzia un oggetto della classe CC e, facendo uso
dei metodi della classe, permette all'utente, dopo aver aperto un conto,
discegliere il tipo di operazione da eseguire sul conto corrente stesso.*/
#include <iostream>
#include <string>
using namespace std;
const int N = 10;
int NUM_C = 0;
class conto {
  string cliente[N];
  float saldo[N];

public:
  void prelievo(float a, string b) {
    for (int i = 0; i < NUM_C; i++) {
      if (b == cliente[i]) {
        if (saldo[i] > a) {
          saldo[i] -= a;
          cout << "Il saldo attuale è di " << saldo[i] << "€ \n";
        } else {
          cout << "Non è possibile effettuare il prelievo perchè la cifra da "
                  "lei inserita è superiore al saldo attuale che  ammonta a "
               << saldo[i] << "€ \n";
        }
      }
    }
  }
  void versamento(float a, string b) {
    for (int i = 0; i < NUM_C; i++) {
      if (b == cliente[i]) {
        saldo[i] += a;
        cout << "Il saldo attuale è di " << saldo[i] << "€ \n";
      }
    }
  }
  void crea() {
    cout << "Inserisci il numero dei clienti da inserire:";
    cin >> NUM_C;
    for (int i = 0; i < NUM_C; i++) {
      cout << "Inserire saldo:";
      cin >> saldo[i];
      cout << "Inserire il cognome del cliente:";
      cin >> cliente[i];
    }
  }
  void stampa() {
    for (int i = 0; i < NUM_C; i++) {
      cout << "\t\t Cliente numero " << i + 1 << "\n";
      cout << "Cliente: " << cliente[i] << " \n";
      cout << "Saldo: " << saldo[i] << "\n";
    }
  }
};
int main() {
  int scelta;
  float a;
  string b;
  conto conto;
  conto.crea();
  do {
    cout << "\t\t----MENU' SCELTA----" << endl;
    cout << "1-Per fare un prelievo,\n"
            "2-Per fare un versamento,\n"
            "3-Per fare una stampa dei dati del conto,\n"
            "0-Per uscire.\n"
            "Scleta:";
    cin >> scelta;
    switch (scelta) {
    case 0:
      cout << "Hai deciso di uscire dal programma! \n";
      break;
    case 1:
      cout << "Inserie nome cliente dal quale si vuole prelevare:";
      cin >> b;
      cout << "Inserire la cifra da prelevare:";
      cin >> a;
      conto.prelievo(a, b);
      break;
    case 2:
      cout << "Inserie nome cliente nel quale si vuole fare un versamento:";
      cin >> b;
      cout << "Inserire la cifra da versare:";
      cin >> a;
      conto.versamento(a, b);
      break;
    case 3:
      conto.stampa();
      break;
    default:
      cout << "!Scelta sbagliata riprova! \n";
      break;
    }

  } while (scelta != 0);
}