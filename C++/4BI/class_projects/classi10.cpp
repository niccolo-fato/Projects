#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool verify = false;
const int MAX_C = 100;

struct client {
  string code;
  float bill;
  string surname;
  string name;
};
class checking_account {
  client c[MAX_C];
  int count = 0;
  float sum = 0;

public:
  void input() {
    cout << "Inserisci il cognome:";
    cin >> c[count].surname;
    cout << "Inserisci il nome:";
    cin >> c[count].name;
    cout << "Inserisci il codice:";
    cin >> c[count].code;
    cout << "Inserisci il conto:";
    cin >> c[count].bill;
    sum += c[count].bill;
    count++;
  }
  void withdrawal() {
    float wd;
    string search_code;
    cout << "Inserisci il codice dal quale vuoi fare un prelievo:";
    cin >> search_code;
    cout << "Inserisci quanto vuoi prelevare:";
    cin >> wd;
    for (int i = 0; i < count; i++) {
      if (search_code == c[i].code && c[i].bill >= wd) {
        c[i].bill -= wd;
        verify = true;
        cout << "~Prelievo eseguito con successo~\n";
      }
    }
    if (!verify)
      cout << "ERROR==>Il prelievo non e' stato effettuato ricontrolla il "
              "codice oppure che il prelievo non sia maggiore del conto "
              "disponibile!\n";
    verify = false;
  }
  void payment() {
    float pm;
    string search_code;
    cout << "Inserisci il codice dal quale vuoi fare un versamento:";
    cin >> search_code;
    do {
      cout << "Inserisci quanto vuoi versare(minimo di 100$):";
      cin >> pm;
    } while (pm <= 100);
    for (int i = 0; i < count; i++) {
      if (search_code == c[i].code) {
        c[i].bill += pm;
        verify = true;
        cout << "~Versamento eseguito con successo~\n";
      }
    }
    if (!verify)
      cout << "ERROR==>Il codice inserito non esiste!\n";
    verify = false;
  }
  void print() {
    string search_code;
    cout << "Inserire il codice del conto del quale si vuole stampare i dati:";
    cin >> search_code;
    for (int i = 0; i < count; i++) {
      if (search_code == c[i].code) {
        cout << "Nome:" << c[i].name
             << "\n"
                "Cognome:"
             << c[i].surname
             << "\n"
                "Conto:"
             << c[i].bill
             << "$\n"
                "Codice:"
             << c[i].code << "\n";
        verify = true;
      }
    }
    if (!verify)
      cout << "ERROR==>Il codice inserito non esiste!\n";
    verify = false;
  }
  void transfer() {
    string first_code, second_code;
    float t;
    cout << "Inserire il codice di chi vuole fare un bonifico:";
    cin >> first_code;
    cout << "Inserire il codice di chi riceve il bonifico:";
    cin >> second_code;
    cout << "Inserisci quanto vuoi trasferire:";
    cin >> t;
    for (int i = 0; i < count; i++) {
      if (first_code == c[i].code) {
        for (int j = 0; j < count; j++) {
          if (second_code == c[j].code) {
            c[i].bill -= t;
            c[j].bill += t;
          }
        }
      }
    }
  }
  void file() {
    ofstream f;
    float average = 0;
    average = sum / count;
    f.open("client.txt");
    for (int i = 0; i < count; i++) {
      if (c[i].bill > average) {
        f << c[i].name << " " << c[i].surname << " " << c[i].code << " "
          << c[i].bill << "\n";
      }
    }
    cout << "\t\t~Conti inseriti nel file con successo~\n";
    f.close();
  }
  void max_min() {
    float max = 0;
    float min = 0;
    for (int i = 0; i < count; i++) {
      if (c[i].bill > max)
        max = c[i].bill;
    }
    min = max;
    for (int i = 0; i < count; i++) {
      if (c[i].bill < min)
        min = c[i].bill;
    }
    cout << "Il conto minore e' " << min << " mentre quello maggiore e' " << max
         << "\n";
  }
  void sorting() {
    client tmp;
    for (int i = 0; i < count - 1; i++) {
      for (int j = i + 1; i < count; i++) {
        if (c[i].bill > c[j].bill) {
          tmp = c[i];
          c[i] = c[j];
          c[j] = tmp;
        }
      }
    }
    cout << "~\t\tOrdinamento effettuato\n";
  }
  void input_file() {
    ifstream f;
    f.open("client2.txt");
    while (!f.eof()) {
      f >> c[count].code >> c[count].bill >> c[count].name >> c[count].surname;
      count++;
    }
    cout << "~\t\tConti inseriti correttamente\n";
    f.close();
  }
};
int main() {
  int choice = 0;
  checking_account ca;
  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire un nuovo cliente,\n"
            "2-Per fare un prelievo,\n"
            "3-Per fare un versamento,\n"
            "4-Per stampare il conto in base al codice,\n"
            "5-Per spostare i denari da un conto all'altro,\n"
            "6-Per spostare i conti superiori alla media generale in un file,\n"
            "7-Per stampare i dati dei conti piu' piccolo e piu' grande,\n"
            "8-Per ordinare i conti in modo decrescente,\n"
            "9-Per inserire i conti da un file,\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 1:
      ca.input();
      cout << "============================================\n";
      break;
    case 2:
      ca.withdrawal();
      cout << "============================================\n";
      break;
    case 3:
      ca.payment();
      cout << "============================================\n";
      break;
    case 4:
      ca.print();
      cout << "============================================\n";
      break;
    case 5:
      ca.transfer();
      cout << "============================================\n";
      break;
    case 6:
      ca.file();
      break;
    case 7:
      ca.max_min();
      cout << "============================================\n";
      break;
    case 8:
      ca.sorting();
      cout << "============================================\n";
      break;
    case 9:
      ca.input_file();
      cout << "============================================\n";
      break;
    default:
      cout << "ERROR==>Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}