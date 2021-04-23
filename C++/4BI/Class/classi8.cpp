#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool verify = false;

class day {
  float tmin;
  float tmax;
public:
  day(float new_tmin, float new_tmax) {
    tmin = new_tmin;
    tmax = new_tmax;
  }
  float calculation() {
    return (tmax - tmin);
  }
  void print_temperature(int j) {
    if (tmin != 0 && tmax != 0) {
      cout << "Giorno " << j+1 << ":\n";
      cout << "Temperatura massima: " << tmax
           << "\nTemperatura minima: " << tmin << "\n";
    }
  }
  float average(){
    return((tmax+tmin)/2);
  }
};
vector<day> december;
class days {
public:
  void temperature_range(float num) {
    for (int j = 0; j < december.size(); j++) {
      if (j == num) {
        cout << "L'escursione termica del giorno " << j+1 << " e' " << december[j].calculation() <<"\n";
        verify = true;
      }
    }
    if (!verify)
      cout << "ERROR==>Le temperature del giorno inserito non sono ancora state inserite!\n";
    verify = false;
  }
  void print_zero() {
    cout << "\t\t~Lista dei giorni copn le temperature maggiori di zero:~\n";
    for (int j = 0; j < december.size(); j++) {
      december[j].print_temperature(j);
    }
  }
  void print_average() {
    cout<<"\t\t~Lista medie giornaliere:~\n";
    for(int j = 0; j < december.size(); j++){
      cout<<"Giorno "<< j+1 << ":\n";
      cout<<"Media giornaliera: " << december[j].average() << "\n";
    }
  }
};
int main() {
  days d;
  int choice = 0, i = 1;
  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire la temperatura del giorno " << i
         << ",\n"
            "2-Per avere l'escursione termica di un giorno,\n"
            "3-Per stampare i giorni che hanno avuto una temperatura sopra lo "
            "zero,\n"
            "4-Per stampare le medie delle temperature giornaliere,\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 0:
      cout << "Hai deciso di uscire dal programma\n";
      break;
    case 1: {
      if (i <= 31) {
        float new_tmin, new_tmax;
        cout << "\t\tTemperatura del giorno " << i << ":\n";
        cout << "Inserisci temperatura minima della giornata:";
        cin >> new_tmin;
        cout << "Inserisci temperatura massima della giornata:";
        cin >> new_tmax;
        day temperatures(new_tmin, new_tmax);
        december.push_back(temperatures);
        i++;
      } else {
        cout << "~Hai raggiunto il massimo dei giorni disponibili di "
                "dicembre~\n";
      }
      cout << "============================================\n";
    } break;
    case 2: {
      float num;
      cout << "Inserire il numero del giorno del quale si vuole sapere "
              "l'escursione termica:";
      cin >> num;
      num--;
      d.temperature_range(num);
      cout << "============================================\n";
    } break;
    case 3:
      d.print_zero();
      cout << "============================================\n";
      break;
    case 4:
      d.print_average();
      cout << "============================================\n";
      break;
    default:
      cout << "ERROR==>Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}