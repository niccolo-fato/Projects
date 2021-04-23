#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool verify = false;
struct materia {
  string subject;
  float vote;
};

class student {

  string surname, name, address, class_student;
  int count;
  float vote_sum;
  vector<materia> votes;

public:
  student(string new_surname, string new_name, string new_address,
          string new_class) {
    surname = new_surname;
    name = new_name;
    address = new_address;
    class_student = new_class;
    count = 0;
    vote_sum = 0;
  }
  void print_student() {
    int num_votes = votes.size();
    cout << "Nome: " << name << "\n";
    cout << "Cognome: " << surname << "\n";
    cout << "Indirizzo: " << address << "\n";
    cout << "Classe: " << class_student << "\n";
    cout << "Media di tutti i voti presi: " << vote_sum / count << "\n";
    cout << "\t\tInterrogazioni:\n";
    if (num_votes != 0) {
      for (int i = 0; i < votes.size(); i++) {
        cout << "In " << votes[i].subject << " ha preso " << votes[i].vote << "\n";
      }
    } else {
      cout << "\t\t----!Non ha voti!----\n";
    }
  }
  void vote_student(materia v) {
    votes.push_back(v);
    vote_sum += v.vote;
    count++;
    cout << "\t\t----!Il voto e' stato inserito!---\n";
  }

  string return_surname() { return surname; }
  void return_address(string change_address) { address = change_address; }
};
vector<student> s;
class students {
  materia v;

public:
  void add_vote(string search_surname) {
    cout << "Inserire il voto:";
    cin >> v.vote;
    cout << "Inserire la materia dove hai preso il voto:";
    cin >> v.subject;
    for (int i = 0; i < s.size(); i++) {
      if (s[i].return_surname() == search_surname) {
        s[i].vote_student(v);
        break;
      }
    }
  }
  void new_address(string search_surname, string change_address) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i].return_surname() == search_surname) {
        s[i].return_address(change_address);
        verify = true;
        break;
      }
    }
    if (!verify)
      cout << "\t\t----Studente non trovato----\n";
    if (verify) {
      cout << "\t\t----!L'indirizzo e'stato cambiato!---\n";
    }
    verify = false;
  }
  void print() {

    cout << "\t\tLista studenti:\n";
    for (int i = 0; i < s.size(); i++) {
      cout << "Studente numero " << i + 1 << ":\n";
      s[i].print_student();
    }
  }
};
int main() {
  students st;
  string search_surname, change_address, vote_subject;
  float new_vote;
  int choice = 0;

  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire uno studente,\n"
            "2-Per aggiungere un voto e aggiornare la media voti,\n"
            "3-Per cambiare il proprio indirizzo,  \n"
            "4-Per stampare\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 0:
      cout << "Hai deciso di uscire dal programma\n";
      break;
    case 1: {
      string new_surname, new_name, new_address, new_class;
      cout << "Inserisci cognome:";
      cin >> new_surname;
      cout << "Inserisci nome:";
      cin >> new_name;
      cout << "Inserisci indirizzo:";
      getline(cin >> std::ws, new_address);
      cout << "Inserisci classe:";
      cin >> new_class;
      student new_student(new_surname, new_name, new_address, new_class);
      s.push_back(new_student);
      cout << "-------------------------------------------\n";
    } break;
    case 2:
      cout << "Inserire il cognome di chi ha preso il voto:";
      cin >> search_surname;
      st.add_vote(search_surname);
      cout << "-------------------------------------------\n";
      break;
    case 3:
      cout
          << "Inserire il cognome dello studente che vuole cambiare indirizzo:";
      cin >> search_surname;
      cout << "Inserire il nuovo indirizzo:";
      getline(cin >> std::ws, change_address);
      st.new_address(search_surname, change_address);
      cout << "-------------------------------------------\n";
      break;
    case 4:
      st.print();
      cout << "-------------------------------------------\n";
      break;
    default:
      cout << "Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}