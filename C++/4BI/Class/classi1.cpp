#include <iostream>
#include <string>
using namespace std;
class giorno
{
    int ng;
    int tmin;
    int tmax;

public:
    void inserisci(int dt)
    {
        ng = dt;
        cout << "Inserisci la temepratura minima del giorno " << ng << endl;
        cin >> tmin;
        cout << "Inserisci la temepratura massima del giorno " << ng << endl;
        cin >> tmax;
    }
    int differenza()
    {
        return (tmax - tmin);
    }
    void stampa(int dt)
    {
        if (tmin > dt)
            cout << ng << "\n";
    }
    float mediag()
    {
        return ((tmax + tmin) / 2);
    }
    int gettmin()
    {
        return (tmin);
    }
    int getng()
    {
        return (ng);
    }
};
const int NG = 5;
int main()
{
    int i, cont = 0;
    giorno dic[NG];
    int min;
    int p;
    float m;
    for (int i = 0; i < NG; i++)
    {
        dic[i].inserisci(i + 1);
    }
    do
    {
        cout << "\t\t"
             << "----MENU SCELTA----" << endl;
        cout << "Inserire 1 per stampare l'escursione termica giornaliera,"
             << "\n"
                "Inserire 2 per stampare il giorno piu' freddo,"
             << "\n"
                "Inserire 3 per stampare i giorni dove i gradi rimangono sopra lo 0,"
             << "\n"
                "Inserire 4 stampa della media delle temperature medie giornaliere,"
             << "\n"
                "Inserire 0 se si vuole uscire."
             << "\n"
                "Scelta:";
        cin >> cont;
        switch (cont)
        {
        case 1:
            for (int i = 0; i < NG; i++)
            {
                cout << "L'escursione termica del giorno " << dic[i].getng() << "e' " << dic[i].differenza() << endl;
            }
            break;
        case 2:
            min = dic[0].getng();
            p = 0;
            for (int i = 0; i < NG; i++)
            {
                if (dic[i].gettmin() < min)
                {
                    min = dic[i].gettmin();
                    p = i;
                }
            }
            cout << "Il giorno piu' freddo e' stato il " << dic[p].getng() << " con gradi " << min << endl;
            break;
        case 3:
            cout << "Giorni in cui la temperatura e' rimasta sopra lo zero:" << endl;
            for (int i = 0; i < NG; i++)
            {
                dic[i].stampa(0);
            }
            break;
        case 4:
            m = 0;
            for (int i = 0; i < NG; i++)
            {
                m += dic[i].mediag();
            }
            m /= NG;
            cout << "La media delle temperature di questo mese è " << m << endl;
            break;
        default:
            break;
        }
    } while (cont != 0);
    return 0;
}