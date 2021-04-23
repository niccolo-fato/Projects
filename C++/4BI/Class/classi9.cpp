#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool verify = false;

struct departments {
  string name_department;
  float recessed;
};

class supermarket {

  string name_supermarket;
  vector<departments> shop;

public:
  supermarket(string new_supermarket) { name_supermarket = new_supermarket; }
  void print_market() {
    int num_departments = shop.size();
    float sum = 0;
    if (num_departments != 0) {
      for (int i = 0; i < shop.size(); i++) {
        cout << "Nome reparto:" << shop[i].name_department
             << "\nIncasso:" << shop[i].recessed << "$\n";
        sum += shop[i].recessed;
      }
      cout << "La somma degli incassi e' " << sum << "$\n";
    } else {
      cout << "\t\t----!Non ha reparti!----\n";
    }
  }
  float max_supermarket() {
    int num_departments = shop.size();
    float sum = 0;
    if (num_departments != 0) {
      for (int i = 0; i < shop.size(); i++) {
        sum += shop[i].recessed;
      }
    }
    return sum;
  }
  void input_department(departments d) { shop.push_back(d); }
  string return_supermarket() { return name_supermarket; }
};
vector<supermarket> market;
class supermarkets {

public:
  void new_department(string search_supermarket) {
    departments d;
    cout << "Inserire il nome del reparto:";
    cin >> d.name_department;
    cout << "Inserire l'incasso del reparto:";
    cin >> d.recessed;
    for (int i = 0; i < market.size(); i++) {
      if (market[i].return_supermarket() == search_supermarket) {
        market[i].input_department(d);
        cout << "\t\t~Reparto inserito con successo~\n";
        verify = true;
        break;
      }
    }
    if (!verify)
      cout << "ERROR==>Il supermercato inserito non esiste!\n";
    verify = false;
  }
  void print() {
    for (int i = 0; i < market.size(); i++) {
      cout << "\t\t Stampa reparti del supermercato "
           << market[i].return_supermarket() << ":\n";
      market[i].print_market();
    }
  }
  void print_max() {
    float max = 0;
    string max_supermarket;
    cout << "Calcolo degli incassi in corso...\n";
    for (int i = 0; i < market.size(); i++) {
      if (market[i].max_supermarket() > max) {
        max = market[i].max_supermarket();
        max_supermarket = market[i].return_supermarket();
      }
    }
    cout << "Il supermercato con piu' incassi e' " << max_supermarket
           << " e ha un incasso di " << max << "$\n";
  }
};
int main() {
  supermarkets sm;
  string search_supermarket;
  int choice = 0;

  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire un nuovo supermercato,\n"
            "2-Per inserire un reparto con il suo incasso,\n"
            "3-Per stampare gli incassi di ogni supermercato,\n"
            "4-Per stampare il supermercato con piu' incassi,\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 0:
      cout << "Hai deciso di uscire dal programma\n";
      break;
    case 1: {
      string new_supermarket;
      cout << "Inserisci il nome del supermercato:";
      cin >> new_supermarket;
      supermarket s(new_supermarket);
      market.push_back(s);
      cout << "============================================\n";
    } break;
    case 2:
      cout << "\nInserisci il nome del supermercato dove vuoi inserire un "
              "reparto:";
      cin >> search_supermarket;
      sm.new_department(search_supermarket);
      cout << "============================================\n";
      break;
    case 3:
      sm.print();
      cout << "============================================\n";
      break;
    case 4:
      sm.print_max();
      cout << "============================================\n";
      break;
    default:
      cout << "ERROR==>Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}/* condition */