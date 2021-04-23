/*A un concorso di bellezza partecipano N ragazze. Le informazioni per ogni ragazza, da memorizzare in una
  tabella sono:
  -cognome,
  -località di provenienza,
  -età,
  -altezza.
  Scrivi un programma che, dopo aver caricato i dati delle ragazze, permetta di:
  -calcolare e stampare l'età media delle partecipanti provenienti da una determinata 
   località fornita in input,
  -dato in input il cognome di una partecipante, stampare la località di provenienza e l'età (segnalare se 
   non esiste),
  -ordinare e stampare l'elenco in base all'età,
  -contare quante sono le ragazze con una differenza di altezza di almeno DELTA rispetto a un valore H
   fornito in input,*/
#include <iostream>
#include <string>
using namespace std;
int NUM_G = 0;
class competition
{
    string surname, locality;
    int age;
    float height;

public:
    void input()
    {
        for (int i = 0; i < NUM_G; i++)
    {
        cout << "\t\t Data girl in position " << i << "\n";
        cout << "Insert surname:";
        cin >> surname;
        cout << "Insert locality of provenence:";
        cin >> locality;
        cout << "Insert age:";
        cin >> age;
        cout << "Insert height:";
        cin >> height;
    }
    }
    float height2(){
        return(height);
    }
    string locality2()
    {
        return(locality);
    }
    int age2()
    {
        return (age);
    }
    string surname2()
    {
        return(surname);
    }
    void print()
    {
        cout << "\t\t Data on " << surname << "\n";
        cout << "Age: " << age << "\n";
        cout << "Locality: " << locality << "\n";
        cout << "Height: " << height << "\n";
    }
};
int main()
{
    string input2, search;
    bool inexistent = false;
    float average = 0, h2, delta;
    int  choice = 0, counter = 0;
    cout << "Insert the number of girls you want to insert: \n";
    cin >> NUM_G;
    competition array[NUM_G], tmp;
        array[NUM_G].input();
    do
    {
        cout << "\t\t----CHOICE MENU'----" << endl;
        cout << "Insert 1 to do the average of the girl from a certain locality ,\n"
                "Insert 2 to search for a girl by entering her surname,\n"
                "Insert 3 to print the ages of the girls in increasing order,\n"
                "Insert 4 to print participants by delta,\n"
                "Insert 0 if you want to exit.\n"
                "Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Insert the locality of the girls you want to average:";
            cin >> input2;
            for (int i = 0; i < NUM_G; i++)
            {
                if (input2 == array[i].locality2())
                {
                    counter++;
                    average += array[i].age2();
                }
            }
            average /= counter;
            cout << "The average age of the girls in " << input2 << " is " << average << "\n";
            cout << "----------------------------------------------------------------------------- \n";
            break;
        case 2:
            cout << "Insert surname of the girl you want search:";
            cin >> search;
            for (int i = 0; i < NUM_G; i++)
            {
                if (search == array[i].surname2())
                {
                    array[i].print();
                    inexistent = true;
                }
            }
            if (!inexistent)
            {
                cout << "\t\t !ATTENTION:The surname inserted is inexistent! \n";
            }
            inexistent = false;
            cout << "----------------------------------------------------------------------------- \n";
            break;
        case 3:
            for (int i = 0; i < NUM_G - 1; i++)
            {
                for (int j = i + 1; j < NUM_G; j++)
                {
                    if (array[i].age2() > array[j].age2())
                    {
                        tmp = array[i];
                        array[i] = array[j];
                        array[j] = tmp;
                    }
                }
            }
            for (int i = 0; i < NUM_G; i++)
            {
                array[i].print();
            }
            break;
        
        }
    } while (choice != 0);
    return 0;
}