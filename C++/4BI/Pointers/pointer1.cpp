/*I dati relativi ai pazienti di uno studio medico sono memorizzati in una coda
Quando un paziente arriva nello studio gli viene assegnato un numero progressivo
e viene messo in coda, quando il medico è libero viene estratto il primo
paziente della coda e viene visitato. Si realizzi un programma che preveda tre
opzioni: 1.arrivo di un paziente; 2.estrazione del paziente dalla coda;
3.stampa dei dati relativi ai pazienti in lista d'attesa*/
#include <iostream>
#include <string>
using namespace std;
struct patient
{
    string name;
    int num;
    struct patient* next; // puntatore al successivo
};
class patients
{
    patient* head; // puntatore al primo elemento della lista
    patient* end;  // puntatore all'ultimo elemento della lista
    int num;       // primo numero distribuito
public:
    patients()
    { // costruttore
        head = NULL;
        end = NULL; // inizializzazione della coda e testa a vuoto
        num = 1;
    }
    void push()
    { // estrazione del paziente in coda
        int choice = 0;
        patient* p;
        p = new (patient);
        cout << "\t\t Menu scelta paziente:\n";
        cout << "Inserisci 1 se il paziente presenta delle disabilita' o in stato "
            "di gravidanza, \n"
            << "Inserisci 2 se non rispetta le condizioni dell'opzione 1, \n"
            << "Scelta:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Inserire il nome del paziente:";
            cin >> p->name;
            p->num = 0;
            cout << "Il paziente " << p->name << " ha ricevuto un permesso speciale per saltare la fila "
                << "\n";
            if (head == NULL)   // controllo se il paziente inserito sia il primo
                head = end = p; // inserimento del primo paziente
            else
            {
                p->next = head;
                head = p;
            }
        }
        break;
        case 2:
            cout << "Inserire il nome del paziente:";
            cin >> p->name;
            p->num = num++;
            cout << "Il paziente " << p->name << " ha il numero " << p->num << "\n";
            p->next = NULL;
            if (head == NULL)   // controllo se il paziente inserito sia il primo
                head = end = p; // inserimento del primo paziente
            else
            {
                end->next = p;
                end = p;
            }
            break;
        }
    }
    void pop()
    { // estrazione del primo paziente in coda
        patient* p;
        if (head == NULL)
            cout << "ERROR==>Non ci sono pazienti in attesa\n";
        else
        {
            p = head;
            head = p->next;
            if (p->num == 0)
                cout << "Il prossimo da visitare e' " << p->name << " che ha saltato la fila per un'urgenza" << "\n";
            else
                cout << "Il prossimo da visitare e' " << p->name << " e ha il  numero "
                << p->num << "\n";
            if (head == NULL)
                end = NULL;
            delete p;
        }
    }
    void print()
    { // stampa dei pazienti in attesa
        patient* p;
        if (head == NULL) // controllo se sono stati inseriti dei pazienti
            cout << "ERROR==>Non ci sono pazienti in attesa\n";
        else
        {
            cout << "\t\tELENCO PAZIENTI IN ATTESA\n";
            for (p = head; p != NULL; p = p->next)
            {
                if (p->num == 0)
                {
                    cout << "Nome:\t\t Numero:\n";
                    cout << p->name << "\t\t "
                        << "!Dev'essere visitato con urgenza!"
                        << "\n";
                }
                else
                {
                    cout << "Nome:\t\t Numero:\n";
                    cout << p->name << "\t\t " << p->num << "\n";
                }
            }
        }
    }
};
int main()
{
    int choice = 0;
    patients office;
    do
    { // menu scelta
        cout << "\t\t Menu scelta:\n";
        cout << "0-Uscire dal programma,\n"
            << "1-Inserire paziente,\n"
            << "2-Estrai paziente,\n"
            << "3-Stampa elenco pazienti in attesa,\n"
            << "Scelta:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            office.push();
            break;
        case 2:
            office.pop();
            break;
        case 3:
            office.print();
            break;
        }
    } while (choice != 0);
}