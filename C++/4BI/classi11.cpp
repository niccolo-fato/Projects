#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool verify = false;

class terrain {
  string code;
  float extension;
  float building_percentage;
  float price;

public:
  terrain(string new_code, float new_extension, float new_building_percentage,
          float new_price) {
    code = new_code;
    extension = new_extension;
    building_percentage = new_building_percentage;
    price = new_price;
  }
  string return_code() { return code; }
  float return_Totalprice() { return extension * price; }
  float return_percentage() { return extension / 100 * building_percentage; }
  void print() {
    cout << "Codice: " << code << "\n"
         << "Estensione: " << extension << "\n"
         << "Percentuale edificabile: " << building_percentage << "\n"
         << "Prezzo: " << price << "\n";
  }
};
int main() {
  vector<terrain> ter;
  string search_code;
  int choice = 0;
  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire un nuovo terreno,\n"
            "2-Per stampare la rendita media dei terreni,\n"
            "3-Per stampare i mq edificabili di un terreno,\n"
            "4-Per stampare tutti i terreni,\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 0:
      cout << "Hai deciso di uscire dal programma\n";
      break;
    case 1: {
      string new_code;
      float new_extension, new_building_percentage, new_price;
      cout << "Inserisci il codice del terreno:";
      cin >> new_code;
      cout << "Inserisci l'estensione del terreno:";
      cin >> new_extension;
      cout << "Inserisci la percentuale edificabile:";
      cin >> new_building_percentage;
      cout << "Inserisci il prezzo a mq:";
      cin >> new_price;
      terrain t(new_code, new_extension, new_building_percentage, new_price);
      ter.push_back(t);
    } break;
    case 2:
      cout << "\nInserire il codice del terreno:";
      cin >> search_code;
      for (int i = 0; i < ter.size(); i++) {
        if (ter[i].return_code() == search_code) {
          cout << "Il prezzo totale del terreno e': "
               << ter[i].return_Totalprice() << "\n";
          verify = true;
        }
      }
      if (!verify)
        cout << "ERROR==>Il codice inserito non esiste\n";
      verify = false;
      break;
    case 3:
      cout << "\nInserire il codice del terreno:";
      cin >> search_code;
      for (int i = 0; i < ter.size(); i++) {
        if (ter[i].return_code() == search_code) {
          cout << "La percentuale edificabile del terreno e' "
               << ter[i].return_percentage() << "\n";
          verify = true;
        }
      }
      if (!verify)
        cout << "ERROR==>Il codice inserito non esiste\n";
      verify = false;
      break;
    case 4:
      for (int i = 0; i < ter.size(); i++) {
        cout << "\t\t~Terreno numero " << i + 1 << "~\n";
        ter[i].print();
      }
    default:
      cout << "ERROR==>Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}