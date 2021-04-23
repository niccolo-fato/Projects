#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ragazza
{
    string cog, prov;
    float eta, h;

public:
    ragazza(string cog2, string prov2, float eta2, float h2)
    {
        cog = cog2;
        prov = prov2;
        eta = eta2;
        h = h2;
    }
    void stampa_ragazza()
    {
        cout << "Cognome: " << cog << endl
             << "Provenienza: " << prov << endl
             << "Eta: " << eta << endl
             << "Altezza: " << h << endl;
    }
    string provenienza_ragazza()
    {
        return prov;
    }
    float eta_ragazza()
    {
        return eta;
    }
    string cognome()
    {
        return cog;
    }
    float altezza()
    {
        return h;
    }
};
vector<ragazza> concorso;
class ragazze
{
public:
    void stampa()
    {
        for (int i = 0; i < concorso.size(); i++)
        {
            cout << "\t\tRagazza numero " << i + 1 << ":\n";
            concorso[i].stampa_ragazza();
        }
    }
    float media_prov(string search_prov)
    {
        float media = 0;
        int cont = 0;
        for (int i = 0; i < concorso.size(); i++)
        {
            if (concorso[i].provenienza_ragazza() == search_prov)
            {
                media += concorso[i].eta_ragazza();
                cont++;
            }
        }
        return media / cont;
    }
    void cerca_stampa(string search_cog)
    {
        for (int i = 0; i < concorso.size(); i++)
        {
            if (concorso[i].cognome() == search_cog)
            {
                concorso[i].stampa_ragazza();
                break;
            }
        }
    }
    void delta(float delta, float h_delta)
    {
        cout << "\t\t Le partecipanti con altezza maggiore o minore di delta sono:\n";
        for (int i = 0; i < concorso.size(); i++)
        {
            if (concorso[i].altezza() < (h_delta - delta) || concorso[i].altezza() > (h_delta + delta))
            {
                cout << concorso[i].cognome() << " ha un altezza di " << concorso[i].altezza() << "\n";
            }
        }
    }
    void stampa_18()
    {
        for (int i = 0; i < concorso.size(); i++)
        {
            if (concorso[i].eta_ragazza() >= 18)
            {
                cout << "\t\tRagazza numero " << i + 1 << ":\n";
                concorso[i].stampa_ragazza();
            }
        }
    }
};
int main()
{
    int choice = 0;
    ragazze r;
    do
    {
        cout << "\t\t Menu scelta:\n";
        cout << "0-Uscire dal programma,\n"
             << "1-Registrare concorrente,\n"
             << "2-Stampa delle ragazze,\n"
             << "3-Stampa eta' media delle partecipanti di una localita' fornita in input,\n"
             << "4-Fornire dati di una concorrente inserendo il cognome,\n"
             << "5-Conta delle ragazze con una differenza di altezza di almeno Delta rispetto a un valore h\n"
             << "6-Stampa delle ragazze con eta'superiore ai 18 anni.\n"
             << "Scelta:";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Il programma si sta per chiudere\n";
            break;
        case 1:
        {
            string cog2, prov2;
            float eta2, h2;
            cout << "Inserisci cognome:";
            getline(cin >> std::ws, cog2);
            cout << "Inserisci provenienza:";
            cin >> prov2;
            cout << "Inserisci eta:";
            cin >> eta2;
            cout << "Inserisci altezza:";
            cin >> h2;
            ragazza n_ragazza(cog2, prov2, eta2, h2);
            concorso.push_back(n_ragazza);
            cout << "----------------------------------------------\n";
        }
        break;
        case 2:
            r.stampa();
            cout << "----------------------------------------------\n";
            break;
        case 3:
        {
            string search_prov;
            float x;
            cout << "Inserire localita':";
            cin >> search_prov;
            x = r.media_prov(search_prov);
            cout << "La media delle eta' e': " << x << "\n";
            cout << "----------------------------------------------\n";
        }
        break;
        case 4:
        {
            string search_cog;
            cout << "Inserisci cognome:";
            getline(cin >> std::ws, search_cog);
            r.cerca_stampa(search_cog);
            cout << "----------------------------------------------\n";
        }
        break;
        case 5:
        {
            float delta, h_delta;
            cout << "Inserire il delta:";
            cin >> delta;
            cout << "Inserire l'altezza:";
            cin >> h_delta;
            r.delta(delta, h_delta);
            cout << "----------------------------------------------\n";
        }
        break;
        case 6:
            r.stampa_18();
            cout << "----------------------------------------------\n";
            break;
        default:
            cout << "Opzione non disponibile\n";
            break;
        }
    } while (choice != 0);
}