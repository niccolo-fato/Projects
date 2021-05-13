/*Realizza un sistema (usando una coda) che permetta di gestire una lista di attività da svolgere
 in ufficio. Ogni attività sarà formata da 
codice,descrizione,nome impiegato.
Prevedere:
--Inserimento nuova attività
--Cancellazione attività il cui codice è fornito in input
--Stampa tutte le attività relative ad un impiegato il cui nome è fornito in input
Consiglio: usare per il metodo di cancellazione un altro puntatore (ad esempio prec) che contiene
 la posizione dell'elemento precedente, mentre p contiene la posizione dell'elemento corrente.*/
#include <iostream>
#include <string>
using namespace std;
struct attivita {
	string codice, descrizione, nome;
	struct attivita* next;
};
class ufficio {
	attivita* testa;
	attivita* fine;
public:
	ufficio() {
		testa = NULL;
		fine = NULL;
	}
	void push() {
		attivita* p;
		p = new(attivita);
		cout << "Inserire nome:";
		cin >> p->nome;
		cout << "Inserire codice: ";
		cin >> p->codice;
		cout << "Inserire l'attivita: ";
		cin >> p->descrizione;
		p->next = NULL;
		if (testa == NULL)
			testa = fine = p;
		else {
			fine->next = p;
			fine = p;
		}
	}
	void print() {
		attivita* p;
		if (testa == NULL)
			cout << "ERROR==>Non ci sono attivita\n";
		else {
			cout << "\t\tElenco attivita:\n";
			for (p = testa; p != NULL; p = p->next)
				cout << "Codice: " << p->codice << " Attivita: " << p->descrizione << " Nome: " << p->nome << "\n";
		}
	}
	void elimina() {
		attivita* p;
		attivita* pp;
		string cod;
		if (testa == NULL)
			cout << "ERROR==>Non ci sono attivita\n";
		else {
			cout << "Inserire il codice dell' elemento da eliminare: ";
			cin >> cod;
			if (cod == testa->codice) {
				testa = testa->next;
				cout << "Eliminazione riuscita\n";
			}else {
				pp = testa;
			}
			for (p = testa; p != NULL; p = p->next) {
				if (p->codice == cod) {
					pp->next = p->next;
				}else {
					pp = p;
				}
			}
		}
	}
};
int main() {
	int choice = 0;
	ufficio u;
	do { //menu scelta
		cout << "\t\t Menu scelta:\n";
		cout << "0-Uscire dal programma,\n"
			<< "1-Inserire attivita,\n"
			<< "2-Eliminazione attivita,\n"
			<< "3-Stampa elenco attivita,\n"
			<< "Scelta:";
		cin >> choice;
		switch (choice) {
		case 1:
			u.push();
			break;
		case 2:
			u.elimina();
			break;
		case 3:
			u.print();
			break;
		}
	} while (choice != 0);
}
