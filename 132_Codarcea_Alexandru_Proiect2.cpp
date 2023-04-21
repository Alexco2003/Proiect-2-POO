#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <typeinfo>

using namespace std;


void clearScreen()
{
    system("CLS");
}

void displayMeniuPrincipal()
{
    cout << "\n1-Utilizator/Client";
    cout << "\n2-Admin";
    cout << "\n3-Stop";
    cout << endl;

}

void displayMeniuUtilizator()
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl << endl;
    cout << "1-Introduceti-va datele" << endl;
    cout << "2-Inapoi" << endl;
}

void displayMeniuUtilizator2()
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl << endl;
    cout << "1-Inapoi la Meniu Utilizator" << endl;
    cout << "2-Inapoi" << endl;
}





void displayMeniuAdmin()
{
    clearScreen();
    cout << "---Meniu Admin---" << endl << endl;
    cout << "Introduceti Parola: ";
}

void displaySubMeniuAdmin()
{
    clearScreen();
    cout << "---Meniu Admin---" << endl << endl;
    cout << "1-Adauga Membru" << endl;
    cout << "2-Adauga Antrenor" << endl;
    cout << "3-Adauga Clasa" << endl;
    cout << "4-Vezi Lista de Membrii" << endl;
    cout << "5-Vezi Lista de Antrenori" << endl;
    cout << "6-Vezi Lista de Clase" << endl;
    cout << "7-Sterge Membru" << endl;
    cout << "8-Sterge Antrenor" << endl;
    cout << "9-Sterge Clasa" << endl;
    cout << "10-Schimba Bonus Antrenor" << endl;
    cout << "11-Vezi cheltuielile salii" << endl;
    cout << "12-Modifica o Clasa (Setari Avansate)" << endl;
    cout << "13-Inapoi" << endl;

}

void displaySubMeniuAdmin2()
{
    clearScreen();
    cout << "---Meniu Admin (Setari Avansate <-> Clase)---" << endl << endl;
    cout << "1-Schimba Pret Clasa" << endl;
    cout << "2-Schimba Data Clasa" << endl;
    cout << "3-Schimba Numar Locuri Clasa" << endl;
    cout << "4-Schimba Status Clasa" << endl;
    cout << "5-Schimba Antrenor Clasa" << endl;
    cout << "6-Vezi lista de participanti a unei Clase" << endl;
    cout << "7-Adauga un Membru in lista de participanti a unei Clase" << endl;
    cout << "8-Sterge un Membru din lista de participanti a unei Clase" << endl;
    cout << "9-Inapoi"<<endl;

}

void pauza(int secunde)
{
    this_thread::sleep_for(chrono::seconds(secunde));
}

struct data
{
    int zi;
    int luna;
    int an;

};

class IOinterface
{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

class Persoana: public IOinterface
{
protected:
    string nume;
public:
    Persoana();
    Persoana(string nume);
    Persoana(const Persoana&);
    Persoana& operator=(const Persoana&);

    friend istream& operator>>(istream&, Persoana&);
    friend ostream& operator<<(ostream&, const Persoana&);

    istream& citire(istream& in)
    {
        cout<<"Nume: ";
        cin.ignore(10000, '\n');
        getline(in, this->nume);
        return in;
    }
    ostream& afisare(ostream& out) const
    {
        out<<"Nume: "<<this->nume<<endl;
        return out;
    }

    string getNume() const
    {
        return this->nume;
    };
    void settNume(string nume)
    {
        this->nume=nume;
    };

    virtual float cheltuieli() const = 0;

    virtual ~Persoana() {};

};

class Membru: virtual public Persoana
{
protected:
    float buget;
public:
    Membru();
    Membru(string nume, float buget);
    Membru(const Membru&);
    Membru& operator=(const Membru&);
    bool operator==(const Membru&);

    istream& citire(istream& in)
    {
        this->Persoana::citire(in);
        cout << "Buget: ";
        in >> this->buget;
        cout<<endl;

        return in;
    }

    ostream& afisare(ostream& out) const
    {
        this->Persoana::afisare(out);
        cout << "Buget: " << this->buget << endl;
        return out;
    }

    float getBuget() const
    {
        return this->buget;
    };
    void settBuget(float buget)
    {
        this->buget=buget;
    };

    float cheltuieli() const
    {
        return 50;
    }

    virtual ~Membru() {};


};

class Antrenor: virtual public Persoana
{
protected:
    float bonus;
    string specializare;
public:
    Antrenor();
    Antrenor(string nume, float bonus, string specializare);
    Antrenor(const Antrenor&);
    Antrenor& operator=(const Antrenor&);

    istream& citire(istream& in)
    {
        this->Persoana::citire(in);
        cout << "Bonus: ";
        in >> this->bonus;
        cout<<"Specializare: ";
        cin.ignore(10000, '\n');
        getline(in, this->specializare);

        return in;
    }

    ostream& afisare(ostream& out) const
    {
        this->Persoana::afisare(out);
        cout << "Bonus: " << this->bonus << endl;
        cout<< "Specializare: "<<this->specializare<<endl;
        return out;

    }


    float getBonus() const
    {
        return this->bonus;
    };
    string getSpecializare() const
    {
        return this->specializare;
    };

    void settBonus(float bonus)
    {
        this->bonus=bonus;
    };
    void settSpecializare(string specializare)
    {
        this->specializare=specializare;
    };

    float cheltuieli() const
    {
        return this->bonus*2;
    }
    virtual ~Antrenor() {};


};

///Persoana

Persoana::Persoana()
{
    this->nume="Anonim";
}

Persoana::Persoana(string nume)
{
    this->nume=nume;
}

Persoana::Persoana(const Persoana& obj)
{
    this->nume=obj.nume;
}

Persoana& Persoana::operator=(const Persoana& obj)
{
    if (this!=&obj)
    {
        this->nume=obj.nume;
    }
    return *this;

}

istream& operator >>(istream& in, Persoana& obj)
{
    return obj.citire(in);
}

ostream& operator <<(ostream& out, const Persoana& obj)
{
    return obj.afisare(out);
}

///Membru

Membru::Membru(): Persoana()
{
    this->buget = 0;
}

Membru::Membru(string nume, float buget):Persoana(nume)
{
    this->buget=buget;
}

Membru::Membru(const Membru& obj):Persoana(obj)
{
    this->buget=obj.buget;
}

Membru& Membru::operator=(const Membru& obj)
{
    if (this!=&obj)
    {
        Persoana::operator=(obj);

        this->buget=obj.buget;
    }

    return *this;
}

bool Membru::operator==(const Membru& obj)
{
    return this->nume == obj.nume;
}

///Antrenor

Antrenor::Antrenor(): Persoana()
{
    this->bonus = 0;
    this->specializare="Nimic";
}

Antrenor::Antrenor(string nume, float bonus, string specializare):Persoana(nume)
{
    this->bonus=bonus;
    this->specializare=specializare;
}

Antrenor::Antrenor(const Antrenor& obj):Persoana(obj)
{
    this->bonus=obj.bonus;
    this->specializare=obj.specializare;
}

Antrenor& Antrenor::operator=(const Antrenor& obj)
{
    if (this!=&obj)
    {
        Persoana::operator=(obj);
        this->specializare=obj.specializare;
        this->bonus=obj.bonus;
    }

    return *this;
}


class Clasa: public Membru, public Antrenor
{
    float pret;
    data dataClasa;
    int nrLocuri;
    bool valabilitate;
    Antrenor* antrenor;
    vector <Membru> listaMembrii;

public:
    Clasa();
    Clasa(string nume, float buget, float bonus, float pret, data dataClasa, bool valabilitate,Antrenor* antrenor, vector<Membru> listaMembrii, int nrLocuri, string specializare);
    Clasa(const Clasa&);
    Clasa& operator=(const Clasa&);

    istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout<<"Pret: ";
        in>> this->pret;
        cout<<"Numar locuri: ";
        in >> this->nrLocuri;
        cout<<"Data (ziua): ";
        in>>this->dataClasa.zi;
        cout<<"Data (luna): ";
        in>>this->dataClasa.luna;
        cout<<"Data (an): ";
        in>>this->dataClasa.an;
        cout<<endl;
        return in;
    }
    ostream& afisare(ostream& out) const
    {
        Persoana::afisare(out);
        out<<"Pret: " << this->pret<< endl;
        out<<"Data: " <<this->dataClasa.zi<<"/"<<this->dataClasa.luna<<"/"<<this->dataClasa.an<< endl;
        if(this->antrenor != NULL)

        {
            out << "Antrenor: " << this->antrenor->getNume() << endl;
            out <<"Specializare antrenor: "<<this->specializare <<endl;
        }
        else out << "Antrenor: Indisponibil"<<endl;
        if (this->nrLocuri>0 && this->valabilitate==true)
            out<<"Locuri disponibile: "<<this->nrLocuri<<endl;

        out<<"Valabilitate: " << (this->valabilitate ? "Da" : "Nu")<<endl;


        return out;
    }

    vector<Membru> getListaMembrii()
    {
        return this->listaMembrii;
    };
    bool getValabilitate()
    {
        return this->valabilitate;
    };
    Antrenor* getAntrenor()
    {
        return this->antrenor;
    };
    float getPret()
    {
        return this->pret;
    };
    int getNrLocuri()
    {
        return this->nrLocuri;
    };
    data getDataClasa()
    {
        return this->dataClasa;
    };

    void settListaMembrii(vector<Membru> listaMembrii)
    {
        this->listaMembrii=listaMembrii;
    };
    void settValabilitate(bool valabilitate)
    {
        this->valabilitate=valabilitate;
    };
    void settAntrenor(Antrenor* antrenor)
    {
        this->antrenor=antrenor;
    };
    void settPret(float pret)
    {
        this->pret=pret;
    };
    void settNrLocuri(int nrLocuri)
    {
        this->nrLocuri=nrLocuri;
    };
    void settDataClasa(int zi, int luna, int an)
    {
        this->dataClasa.zi=zi;
        this->dataClasa.luna=luna;
        this->dataClasa.an=an;
    };

    float cheltuieli() const
    {
        return this->listaMembrii.size()*this->pret;
    }

    virtual ~Clasa()
    {
        this->antrenor=NULL;
    };
};

///Clasa

Clasa::Clasa()
{
    this->pret=0;
    this->dataClasa.zi=0;
    this->dataClasa.luna=0;
    this->dataClasa.an=0;
    this->nrLocuri=0;
    this->valabilitate=true;
    this->antrenor=NULL;
    this->listaMembrii = vector<Membru>();
}

Clasa::Clasa(string nume, float buget, float bonus, float pret, data dataClasa, bool valabilitate,Antrenor* antrenor, vector<Membru> listaMembrii, int nrLocuri,string specializare):Persoana(nume), Membru(nume, buget), Antrenor(nume,bonus,specializare)
{
    this->pret=pret;
    this->dataClasa.zi=dataClasa.zi;
    this->dataClasa.luna=dataClasa.luna;
    this->dataClasa.an=dataClasa.an;
    this->nrLocuri=nrLocuri;
    this->valabilitate=valabilitate;
    this->antrenor=antrenor;
    this->listaMembrii=listaMembrii;
}

Clasa::Clasa(const Clasa& obj): Persoana(obj),Membru(obj),Antrenor(obj)
{
    this->pret=obj.pret;
    this->dataClasa.zi=obj.dataClasa.zi;
    this->dataClasa.luna=obj.dataClasa.luna;
    this->dataClasa.an=obj.dataClasa.an;
    this->nrLocuri=obj.nrLocuri;
    this->valabilitate=obj.valabilitate;
    this->antrenor=obj.antrenor;
    this->listaMembrii=obj.listaMembrii;
}

Clasa& Clasa::operator=(const Clasa& obj)
{
    if(this!=&obj)
    {
        Membru::operator=(obj);
        Antrenor::operator=(obj);
        this->pret=obj.pret;
        this->dataClasa.zi=obj.dataClasa.zi;
        this->dataClasa.luna=obj.dataClasa.luna;
        this->dataClasa.an=obj.dataClasa.an;
        this->nrLocuri=obj.nrLocuri;
        this->valabilitate=obj.valabilitate;
        this->antrenor=obj.antrenor;
        this->listaMembrii=obj.listaMembrii;

    }
    return *this;
}


void displaySubMeniuUtilizator(const Membru& client)
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl;
    cout<<"<-> Buget: " << client.getBuget()<<" lei <->" << endl <<endl;


    cout << "1-Alegeti-va o Clasa pentru a efectua o rezervare" << endl;
    cout << "2-Anulati o rezervare" << endl;

    cout << "3-Creeati-va propria Clasa personalizata (cost: 500 lei)" << endl;
    cout << "4-Schimbati-va bugetul (Adaugati fonduri)" << endl;
    cout << "5-Inapoi" << endl;
}


int main()

{

    vector <Membru> listaMembrii;
    vector <Antrenor> listaAntrenori;
    vector <Clasa> listaClase;

    Membru M1("Alexandra Popescu", 250.5);
    Membru M2("George Ionescu", 350.2);
    Membru M3("Maria Radulescu", 200);
    Membru M4("Ion Andrei", 150.8);
    Membru M5("Ana Stanescu", 300.3);
    Membru M6("Andrei Popa", 100);
    Membru M7("Razvan Marinescu", 450);
    Membru M8("Gabriela Tudor", 220.6);
    Membru M9("Florin Pop", 180.2);
    Membru M10("Alina Bucur", 400);
    listaMembrii.push_back(M1);
    listaMembrii.push_back(M2);
    listaMembrii.push_back(M3);
    listaMembrii.push_back(M4);
    listaMembrii.push_back(M5);
    listaMembrii.push_back(M6);
    listaMembrii.push_back(M7);
    listaMembrii.push_back(M8);
    listaMembrii.push_back(M9);
    listaMembrii.push_back(M10);



    Antrenor A1("Mitrache Darius", 100,"Yoga, Body Pump, Zumba");
    Antrenor A2("Ionescu Andrei", 30.5,"Cycling Virtual, Cycling");
    Antrenor A3("Popescu Maria", 76.3,"Skill-X");
    Antrenor A4("Stanescu Ionut", 50.2,"Step Dance");
    Antrenor A5("Bucur Alina", 30,"Yoga, Pilates, Healthy Spine");
    Antrenor A6("Georgescu George", 14,"Functional, Glutes");
    Antrenor A7("Marinescu Alexandru", 20.3,"Khai BO, TRX");
    listaAntrenori.push_back(A1);
    listaAntrenori.push_back(A2);
    listaAntrenori.push_back(A3);
    listaAntrenori.push_back(A4);
    listaAntrenori.push_back(A5);
    listaAntrenori.push_back(A6);
    listaAntrenori.push_back(A7);




    vector <Membru> lista1;
    lista1.push_back(M4);
    lista1.push_back(M5);
    lista1.push_back(M6);
    lista1.push_back(M7);
    vector <Membru> lista2;
    lista2.push_back(M8);
    lista2.push_back(M9);
    lista2.push_back(M10);
    vector <Membru> lista3;
    lista3.push_back(M1);
    lista3.push_back(M2);
    lista3.push_back(M3);
    lista3.push_back(M4);
    lista3.push_back(M5);
    lista3.push_back(M9);
    lista3.push_back(M10);
    vector <Membru> lista4;

    data D1= {25,4,2023};
    data D2= {23,6,2023};
    data D3= {17,5,2023};
    data D4= {30,4,2023};

    Clasa C1("Body Pump",0,0,278,D1,true,&listaAntrenori[0],lista3,12,A1.getSpecializare());
    Clasa C2("Yoga",0,0,237.5,D2,true,&listaAntrenori[4],lista2,7,A5.getSpecializare());
    Clasa C3("TRX",0,0,99.9,D3,true,&listaAntrenori[6],lista1,9,A7.getSpecializare());
    Clasa C4("Cycling",0,0,156.3,D4,false,&listaAntrenori[1],lista4,15,A2.getSpecializare());

    int nr;
    nr=C1.getNrLocuri()-C1.getListaMembrii().size();
    C1.settNrLocuri(nr);
    nr=C2.getNrLocuri()-C2.getListaMembrii().size();
    C2.settNrLocuri(nr);
    nr=C3.getNrLocuri()-C3.getListaMembrii().size();
    C3.settNrLocuri(nr);
    nr=C4.getNrLocuri()-C4.getListaMembrii().size();
    C4.settNrLocuri(nr);
    listaClase.push_back(C1);
    listaClase.push_back(C2);
    listaClase.push_back(C3);
    listaClase.push_back(C4);


    int p=0;
    Membru client1;
    vector <int> frecventa(4,0);



    cout << "Bine ati venit la World Class (Sectiunea destinata Claselor)! Alegeti-va functia:" << endl;

    while (true)
    {
        int comanda;
        displayMeniuPrincipal();
        cin >> comanda;

        switch (comanda)
        {
        case 1:
        {
            if(p==0)
                displayMeniuUtilizator();
            else
                displayMeniuUtilizator2();

            int comanda2;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                if(p==0)
                {
                    clearScreen();
                    cin>>client1;
                    if(client1.getBuget()<0)
                        client1.settBuget(0);
                    listaMembrii.push_back(client1);
                    clearScreen();
                    p++;


                }
                else
                    clearScreen();
                while (true)
                {
                    displaySubMeniuUtilizator(client1);

                    int comanda4;
                    cin >> comanda4;
                    switch (comanda4)
                    {


                    case 1:
                    {
                        if (listaClase.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        clearScreen();
                        for(int i=0; i<listaClase.size(); i++)
                            cout<<i<<". "<<listaClase[i]<<endl;
                        cout<<"Alegeti nr-ul Clasei unde doriti sa rezervati un loc: ";
                        int nr;
                        cin>>nr;

                        if(listaClase[nr].getPret()<client1.getBuget() && listaClase[nr].getNrLocuri()>0 && listaClase[nr].getValabilitate()==true && frecventa[nr]==0)
                        {
                            frecventa[nr]=1;
                            float buget=client1.getBuget();
                            buget=buget-listaClase[nr].getPret();
                            client1.settBuget(buget);
                            vector <Membru> lista=listaClase[nr].getListaMembrii();
                            lista.push_back(client1);
                            listaClase[nr].settListaMembrii(lista);
                            int nrLocuri=listaClase[nr].getNrLocuri();
                            nrLocuri--;
                            listaClase[nr].settNrLocuri(nrLocuri);
                            float bonus=listaClase[nr].getAntrenor()->getBonus();
                            bonus=bonus+10;
                            listaClase[nr].getAntrenor()->settBonus(bonus);
                            for(int i=0; i<listaMembrii.size(); i++)
                                if(listaMembrii[i]==client1)
                                {
                                    float suma=client1.getBuget();
                                    listaMembrii[i].settBuget(suma);
                                }
                            clearScreen();
                            cout<<"Rezervare facuta cu succes!";
                            pauza(2);
                            break;

                        }
                        else
                        {
                            clearScreen();
                            if(frecventa[nr]==1)
                            {
                                cout<<"Ati efectuat deja o rezervare pentru clasa aceasta. Sunteti pe lista de participanti."<<endl<<endl;
                                cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                cin.ignore();
                                while(cin.get() != '\n');
                                clearScreen();
                                break;
                            }

                            cout<<"A intervenit o eroare. Verificati daca exista fonduri suficiente, daca mai exista locuri disponibile pentru Clasa dorita sau daca Clasa nu este disponibila momentan."<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;

                        }



                        clearScreen();
                        break;
                    }


                    case 2:
                    {
                        int cnt5=0,cnt6=0;

                        clearScreen();
                        for (int i=0; i<frecventa.size(); i++)
                            if (frecventa[i]==1 || frecventa[i]==2)
                            {
                                cout<<i<<". "<<listaClase[i]<<endl;
                                cnt5++;
                            }
                        if (cnt5==0)
                        {
                            clearScreen();
                            break;
                        }

                        cout<<"Introduceti nr-ul Clasei pentru anularea rezervarii curente (Banii va vor fi inapoiati integral, conform regulamentului va vom retine suma de 5 lei din suma originala. Pentru a anula procesul de anulare al rezervarii si pentru a pastra rezervarea curenta apsati tasta '-1': ";

                        int nr;
                        cin>>nr;

                        for (int i=0; i<frecventa.size(); i++)
                            if (frecventa[i]==1 || frecventa[i]==2)
                            {
                                if(i==nr)
                                    cnt6++;
                            }

                        if(nr==-1 || cnt6==0)
                        {
                            clearScreen();
                            break;

                        }
                        else
                        {
                            if(frecventa[nr]==1)
                            {
                                float bani=listaClase[nr].getPret();
                                bani=bani+client1.getBuget()-5;
                                client1.settBuget(bani);
                            }

                            if(frecventa[nr]==2)
                            {
                                float bani=500;
                                bani=bani+client1.getBuget()-5;
                                client1.settBuget(bani);
                            }

                            frecventa[nr]=0;

                            vector <Membru> lista=listaClase[nr].getListaMembrii();
                            for(int j=0; j<lista.size(); j++)
                                if(lista[j]==client1)
                                {
                                    lista.erase(lista.begin()+j);
                                    j=lista.size()+1;
                                }
                            listaClase[nr].settListaMembrii(lista);
                            int nrLocuri=listaClase[nr].getNrLocuri();
                            nrLocuri++;
                            listaClase[nr].settNrLocuri(nrLocuri);
                            for(int i=0; i<listaMembrii.size(); i++)
                                if(listaMembrii[i]==client1)
                                {
                                    float suma=client1.getBuget();
                                    listaMembrii[i].settBuget(suma);
                                }
                            clearScreen();
                            cout<<"Ati anulat rezervarea cu succes."<<endl<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;
                        }


                        clearScreen();
                        break;
                    }

                    case 3:
                    {
                        clearScreen();
                        if(client1.getBuget()<500)
                        {
                            cout<<"A intervenit o eroare! Fonduri insuficiente.";
                            pauza(2);
                            break;
                        }
                        else
                        {
                            float buget=client1.getBuget();
                            buget=buget-500;
                            client1.settBuget(buget);
                            for(int i=0; i<listaMembrii.size(); i++)
                                if(listaMembrii[i]==client1)
                                {
                                    float suma=client1.getBuget();
                                    listaMembrii[i].settBuget(suma);
                                }
                            cout<<"Introduceti datele Clasei dumneavoastra personalizata: " << endl<<endl;
                            Clasa A;
                            cin>>A;
                            for(int i=0; i<listaAntrenori.size(); i++)
                                cout<<i<<". "<<listaAntrenori[i]<<endl;
                            cout<<"Alegeti nr-ul antrenorului dorit: ";
                            int nr;
                            cin>>nr;
                            A.settAntrenor(&listaAntrenori[nr]);
                            A.settSpecializare(listaAntrenori[nr].getSpecializare());
                            float bonus=A.getAntrenor()->getBonus();
                            bonus=bonus+10;
                            A.getAntrenor()->settBonus(bonus);
                            vector <Membru> lista;
                            lista.push_back(client1);
                            A.settListaMembrii(lista);
                            int nrLocuri=A.getNrLocuri();
                            nrLocuri=nrLocuri-1;
                            A.settNrLocuri(nrLocuri);
                            listaClase.push_back(A);
                            frecventa.push_back(2);
                            clearScreen();
                            cout<<"Clasa dumneavoastra a fost realizata cu succes! Puteti privi mai jos detaliile Clasei."<<endl<<endl;
                            cout<<A<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;






                        }



                        clearScreen();
                        break;
                    }
                    case 4:
                    {

                        clearScreen();
                        cout<<"Introduceti '+' daca doriti sa adaugati fonduri in contul dumneavoastra sau '-' daca doriti sa retrageti fonduri din contul dumneavoastra: ";
                        char x;
                        cin>>x;
                        int cnt=0;
                        if(x=='+')
                        {
                            cout<<"Introduceti suma pe care doriti sa o adaugati la bugetul curent: ";
                            float suma,buget;
                            cin>>suma;
                            buget=client1.getBuget();
                            buget=suma+buget;
                            client1.settBuget(buget);
                            for(int i=0; i<listaMembrii.size(); i++)
                                if(listaMembrii[i]==client1)
                                {
                                    float suma1=client1.getBuget();
                                    listaMembrii[i].settBuget(suma1);
                                }


                        }
                        if(x=='-')
                        {
                            cout<<"Introduceti suma pe care doriti sa o retrageti din bugetul curent: ";
                            float suma,buget;

                            cin>>suma;
                            if (suma<client1.getBuget())
                            {
                                buget=client1.getBuget();
                                buget=buget-suma;
                                client1.settBuget(buget);
                                for(int i=0; i<listaMembrii.size(); i++)
                                    if(listaMembrii[i]==client1)
                                    {
                                        float suma1=client1.getBuget();
                                        listaMembrii[i].settBuget(suma1);
                                    }

                            }
                            else
                                cnt++;



                        }

                        cout<<endl;

                        for(int i=0; i<=3; i++)
                        {
                            clearScreen();
                            cout << "\rSe proceseaza.";
                            this_thread::sleep_for(chrono::milliseconds(500));
                            cout << "\rSe proceseaza..";
                            this_thread::sleep_for(chrono::milliseconds(500));
                            cout << "\rSe proceseaza...";
                            this_thread::sleep_for(chrono::milliseconds(500));
                        }
                        clearScreen();
                        if(cnt==0)
                            cout<<"Schimbarea bugetului a fost efectuata cu succes! Veti fi redirectionat automat inapoi la meniu!";
                        else
                            cout<<"A intervenit o eroare. Fonduri insuficiente pentru retragere. Veti fi redirectionat automat inapoi la meniu!";

                        pauza(5);
                        break;

                    }
                    case 5:
                    {
                        clearScreen();

                        break;
                    }


                    default:
                    {
                        clearScreen();
                        cout << "Comanda invalida. Folositi o comanda valida." << endl;
                        break;
                    }

                    }


                    if (comanda4==5)
                    {

                        break;
                    }




                }
            }
            case 2:
            {
                clearScreen();

                break;
            }

            default:
            {
                clearScreen();
                cout << "Comanda invalida. Folositi o comanda valida." << endl;
                break;
            }
            }
            break;
        }


        case 2:
        {
            displayMeniuAdmin();
            string parola;
            char c;
            while ((c = getch()) != '\r')   // se citesc caractere pana se apasa enter
            {
                if (c == '\b' && !parola.empty())   // ca sa mearga backspace
                {
                    parola.pop_back();
                    cout << "\b \b"; // sa stearga si '*' din consola cand apesi backspace
                }
                else if (c != '\b')     // sa ignore backspace, sa nu il ia ca si caracter
                {
                    parola += c;
                    cout << "*";
                }
            }
            cout << endl;
            if (parola == "1234")
            {
                while (true)
                {
                    displaySubMeniuAdmin();
                    int comanda3;
                    cin >> comanda3;
                    switch (comanda3)
                    {


                    case 1:
                    {
                        clearScreen();
                        Membru A;
                        cin >> A;
                        listaMembrii.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 2:
                    {
                        clearScreen();
                        Antrenor A;
                        cin >> A;
                        listaAntrenori.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 3:
                    {
                        clearScreen();
                        Clasa A;
                        cin >> A;
                        clearScreen();
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<i<<". "<<listaAntrenori[i]<<endl;
                        cout<<"Selectati nr-ul Antrenorului dorit: ";
                        int nr;
                        cin>>nr;
                        A.settAntrenor(&listaAntrenori[nr]);
                        A.settSpecializare(listaAntrenori[nr].getSpecializare());
                        listaClase.push_back(A);
                        frecventa.push_back(0);
                        clearScreen();
                        break;
                    }

                    case 4:
                    {
                        clearScreen();
                        if(listaMembrii.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaMembrii.size(); i++)
                            cout<<i<<". "<<listaMembrii[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }
                    case 5:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<i<<". "<<listaAntrenori[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }
                    case 6:
                    {
                        clearScreen();
                        if(listaClase.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaClase.size(); i++)
                            cout<<i<<"."<<listaClase[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }

                    case 7:
                    {
                        clearScreen();
                        if(listaMembrii.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaMembrii.size(); i++)
                            cout<<i<<". "<<listaMembrii[i]<<endl;
                        cout<<"Introduceti nr-ul membrului pe care doriti sa-l eliminati: ";
                        int nr;
                        cin>>nr;

                        if(listaMembrii[nr]==client1)
                        {
                            clearScreen();
                            break;
                        }

                        if(listaClase.size()!=0)
                        {



                            for(int i=0; i<listaClase.size(); i++)
                                for (int j=0; j<listaClase[i].getListaMembrii().size(); j++)
                                    if(listaClase[i].getListaMembrii()[j]==listaMembrii[nr])
                                    {
                                        vector <Membru> lista=listaClase[i].getListaMembrii();
                                        lista.erase(lista.begin()+j);
                                        listaClase[i].settListaMembrii(lista);
                                        int nr;
                                        nr=listaClase[i].getNrLocuri()+1;
                                        listaClase[i].settNrLocuri(nr);
                                    }
                        }

                        listaMembrii.erase(listaMembrii.begin()+nr);
                        clearScreen();
                        break;
                    }
                    case 8:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<i<<". "<<listaAntrenori[i]<<endl;
                        cout<<"Introduceti nr-ul antrenorului pe care doriti sa-l eliminati: ";
                        int nr;
                        cin>>nr;
                        if(listaClase.size()!=0)
                        {



                            for(int i=0; i<listaClase.size(); i++)
                                if(listaClase[i].getAntrenor()==&listaAntrenori[nr])
                                {
                                    listaClase[i].settAntrenor(NULL);
                                    listaClase[i].settValabilitate(false);
                                }
                        }

                        listaAntrenori.erase(listaAntrenori.begin()+nr);

                        clearScreen();
                        break;
                    }
                    case 9:
                    {

                        clearScreen();
                        if(listaClase.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaClase.size(); i++)
                            cout<<i<<". "<<listaClase[i]<<endl;
                        cout<<"Introduceti nr-ul clasei pe care doriti sa o eliminati: ";
                        int nr;
                        cin>>nr;

                        for(int i=0; i<listaClase[nr].getListaMembrii().size(); i++)
                            for(int j=0; j<listaMembrii.size(); j++)
                                if(listaClase[nr].getListaMembrii()[i]==listaMembrii[j])
                                {
                                    if(listaMembrii[j]==client1)
                                    {
                                        if(frecventa[nr]==1)
                                        {
                                            float bani=listaClase[nr].getPret();
                                            bani=bani+client1.getBuget();
                                            client1.settBuget(bani);
                                            listaMembrii[j].settBuget(bani);
                                            frecventa[nr]=0;
                                        }

                                        if(frecventa[nr]==2)
                                        {
                                            float bani=500;
                                            bani=bani+client1.getBuget();
                                            client1.settBuget(bani);
                                            frecventa[nr]=0;
                                        }
                                    }
                                    else
                                    {
                                        float bani=listaClase[nr].getPret();
                                        bani=bani+listaMembrii[j].getBuget();
                                        listaMembrii[j].settBuget(bani);

                                    }
                                }


                        listaClase.erase(listaClase.begin()+nr);
                        frecventa.erase(frecventa.begin()+nr);

                        clearScreen();
                        break;

                    }



                    case 10:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<i<<". "<<listaAntrenori[i]<<endl;
                        cout<<"Introduceti nr-ul antrenorului caruia doriti sa ii schimbati bonusul: ";
                        int nr;
                        cin>>nr;
                        cout<<endl;
                        cout<<"Introduceti '+' daca doriti sa mariti bonusul antrenorului respectiv sau '-' daca doriti sa miscorati bonusul antrenorului respectiv: ";
                        char x;
                        cin>>x;
                        cout<<endl;
                        cout<<"Introduceti suma cu care doriti sa modificati bonusul: ";
                        float suma;
                        cin>>suma;
                        cout<<endl;
                        if(x=='+')
                        {
                            float bonus=listaAntrenori[nr].getBonus();
                            bonus=bonus+suma;
                            listaAntrenori[nr].settBonus(bonus);
                        }
                        if(x=='-')
                        {
                            float bonus=listaAntrenori[nr].getBonus();
                            bonus=bonus-suma;
                            listaAntrenori[nr].settBonus(bonus);
                        }


                        clearScreen();
                        break;
                    }

                    case 11:
                    {
                        clearScreen();
                        vector<Persoana*> listaTotala;

                        for (int i=0; i<listaMembrii.size(); i++)
                            listaTotala.push_back(&listaMembrii[i]);
                        for (int i=0; i<listaAntrenori.size(); i++)
                            listaTotala.push_back(&listaAntrenori[i]);
                        for (int i=0; i<listaClase.size(); i++)
                            listaTotala.push_back(&listaClase[i]);
                        float S1=0,S2=0,S3=0;
                        for (int i=0; i<listaTotala.size(); i++)
                        {
                            if(typeid(*listaTotala[i])==typeid(Membru))
                                S1=S1+listaTotala[i]->cheltuieli();
                            if(typeid(*listaTotala[i])==typeid(Antrenor))
                                S2=S2+listaTotala[i]->cheltuieli();
                            if(typeid(*listaTotala[i])==typeid(Clasa))
                                S3=S3+listaTotala[i]->cheltuieli();

                        }

                        cout<<"---Situatia financiara actuala World Class---"<<endl<<endl;
                        cout<<"Costurile legate de nevoile membrilor: " << S1 <<" lei."<< endl;
                        cout<<"Costurile legate de antrenori: " << S2 << " lei."<< endl;;
                        cout<<"Suma acumulata din rezervari: " << S3 << " lei."<< endl;
                        cout<<"Profitul actual: " <<S3-S1-S2<<" lei."<< endl<<endl;

                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;


                        clearScreen();
                        break;
                    }

                    case 12:
                    {
                        while (true)
                        {
                            displaySubMeniuAdmin2();
                            int comanda4;
                            cin>>comanda4;
                            switch (comanda4)
                            {
                            case 1:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii schimbati pretul: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                cout<<"Introduceti noul pret: ";
                                float suma;
                                cin>>suma;
                                cout<<endl;
                                listaClase[nr].settPret(suma);


                                clearScreen();
                                break;

                            }



                            case 2:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii schimbati data: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;

                                cout<<"Introduceti ziua: ";
                                int zi;
                                cin>>zi;

                                cout<<"Introduceti luna: ";
                                int luna;
                                cin>>luna;

                                cout<<"Introduceti anul: ";
                                int an;
                                cin>>an;

                                listaClase[nr].settDataClasa(zi,luna,an);


                                clearScreen();
                                break;




                            }

                            case 3:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii schimbati numarul total de locuri: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                cout<<"Introduceti noul numar total de locuri: ";
                                int nr1;
                                cin>>nr1;
                                int nr2;
                                nr2=nr1-listaClase[nr].getListaMembrii().size();


                                listaClase[nr].settNrLocuri(nr2);


                                clearScreen();
                                break;




                            }

                            case 4:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii schimbati statusul: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                cout<<"Introduceti noul status (1 (=Clasa Valabila) sau 0 (=Clasa indisponibila momentan)): ";
                                int nr1;
                                cin>>nr1;


                                listaClase[nr].settValabilitate(nr1);


                                clearScreen();
                                break;




                            }

                            case 5:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii schimbati antrenorul: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                for(int i=0; i<listaAntrenori.size(); i++)
                                    cout<<i<<". "<<listaAntrenori[i]<<endl;
                                cout<<"Introduceti nr-ul noului antrenor: ";
                                int nr1;
                                cin>>nr1;
                                cout<<endl;


                                listaClase[nr].settAntrenor(&listaAntrenori[nr1]);
                                listaClase[nr].settSpecializare(listaAntrenori[nr1].getSpecializare());


                                clearScreen();
                                break;




                            }

                            case 6:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii vedeti lista de participanti: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                for(int i=0; i<listaClase[nr].getListaMembrii().size(); i++)
                                    cout<<i<<". "<<listaClase[nr].getListaMembrii()[i]<<endl;






                                cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                cin.ignore();
                                while(cin.get() != '\n');
                                clearScreen();
                                break;



                            }

                            case 7:
                            {

                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii adaugati un membru in lista de participanti: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;
                                cout<<"Introduceti 1 daca doriti sa creeati un membru nou sau 0 daca doriti sa adaugati un membru existent: ";
                                int dorinta;
                                cin>>dorinta;
                                cout<<endl;

                                if(dorinta==1)
                                {
                                    Membru client;
                                    cout<<"Introduceti datele clientului: "<<endl;
                                    cin>>client;
                                    if(client.getBuget()>=listaClase[nr].getPret() && listaClase[nr].getValabilitate()==true && listaClase[nr].getNrLocuri()>0)
                                    {
                                        float suma=client.getBuget()-listaClase[nr].getPret();
                                        client.settBuget(suma);
                                        listaMembrii.push_back(client);
                                        vector <Membru> lista;
                                        lista=listaClase[nr].getListaMembrii();
                                        lista.push_back(client);
                                        listaClase[nr].settListaMembrii(lista);
                                        int nr5=listaClase[nr].getNrLocuri()-1;
                                        listaClase[nr].settNrLocuri(nr5);
                                        float bonus=listaClase[nr].getAntrenor()->getBonus();
                                        bonus=bonus+10;
                                        listaClase[nr].getAntrenor()->settBonus(bonus);


                                    }
                                    else

                                    {
                                        cout<<"A intervenit o eroare. Verificati daca exista fonduri suficiente, daca mai exista locuri disponibile pentru Clasa dorita sau daca Clasa nu este disponibila momentan."<<endl;
                                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                        cin.ignore();
                                        while(cin.get() != '\n');
                                        clearScreen();
                                        break;
                                    }


                                }

                                if(dorinta==0)

                                {
                                    int cnt=0,cnt2=0;

                                    for(int i=0; i<listaMembrii.size(); i++)
                                        cout<<i<<". "<<listaMembrii[i]<<endl;

                                    cout<<"Introduceti nr-ul membrului dorit: ";
                                    int nr27;
                                    cin>>nr27;
                                    cout<<endl;
                                    for(int i=0; i<listaClase[nr].getListaMembrii().size(); i++)
                                    {
                                        if(listaMembrii[nr27]==listaClase[nr].getListaMembrii()[i])
                                        {
                                            cnt++;
                                        }
                                        if(listaMembrii[nr27]==client1)
                                        {
                                            cnt2=1;
                                        }
                                    }



                                    if(listaMembrii[nr27].getBuget()>=listaClase[nr].getPret() && listaClase[nr].getValabilitate()==true && listaClase[nr].getNrLocuri()>0 && cnt==0)
                                    {
                                        if(cnt2==1)
                                        {
                                            float suma=client1.getBuget()-listaClase[nr].getPret();
                                            client1.settBuget(suma);
                                            listaMembrii[nr27].settBuget(suma);
                                            frecventa[nr]=1;

                                            float bonus=listaClase[nr].getAntrenor()->getBonus();
                                            bonus=bonus+10;
                                            listaClase[nr].getAntrenor()->settBonus(bonus);

                                            vector <Membru> lista;
                                            lista=listaClase[nr].getListaMembrii();
                                            lista.push_back(listaMembrii[nr27]);
                                            listaClase[nr].settListaMembrii(lista);
                                            int nr5=listaClase[nr].getNrLocuri()-1;
                                            listaClase[nr].settNrLocuri(nr5);
                                        }
                                        else
                                        {
                                            float suma=listaMembrii[nr27].getBuget()-listaClase[nr].getPret();
                                            listaMembrii[nr27].settBuget(suma);
                                            float bonus=listaClase[nr].getAntrenor()->getBonus();
                                            bonus=bonus+10;
                                            listaClase[nr].getAntrenor()->settBonus(bonus);

                                            vector <Membru> lista;
                                            lista=listaClase[nr].getListaMembrii();
                                            lista.push_back(listaMembrii[nr27]);
                                            listaClase[nr].settListaMembrii(lista);
                                            int nr5=listaClase[nr].getNrLocuri()-1;
                                            listaClase[nr].settNrLocuri(nr5);
                                        }
                                    }

                                    else
                                    {
                                        if(cnt==0)
                                            cout<<"A intervenit o eroare. Verificati daca exista fonduri suficiente, daca mai exista locuri disponibile pentru Clasa dorita sau daca Clasa nu este disponibila momentan."<<endl;
                                        if(cnt!=0)
                                            cout<<"A intervenit o eroare. Membrul este deja pe lista participantilor."<<endl<<endl;

                                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                        cin.ignore();
                                        while(cin.get() != '\n');
                                        clearScreen();
                                        break;

                                    }

                                    clearScreen();
                                    break;




                                }





                                clearScreen();
                                break;




                            }


                            case 8:
                            {
                                clearScreen();
                                if(listaClase.size()==0)
                                {
                                    clearScreen();
                                    break;
                                }
                                for(int i=0; i<listaClase.size(); i++)
                                    cout<<i<<". "<<listaClase[i]<<endl;
                                cout<<"Introduceti nr-ul clasei careia doriti sa ii stergeti un membru din lista de participanti: ";
                                int nr;
                                cin>>nr;
                                cout<<endl;

                                for(int i=0; i<listaClase[nr].getListaMembrii().size(); i++)
                                    cout<<i<<". "<<listaClase[nr].getListaMembrii()[i]<<endl;

                                if (listaClase[nr].getListaMembrii().size()==0)
                                {
                                    cout<<"Nu exista membrii pe lista de participanti a acestei Clase."<<endl<<endl;
                                    cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                                    cin.ignore();
                                    while(cin.get() != '\n');
                                    clearScreen();
                                    break;
                                }
                                else
                                {
                                    cout<<"Introduceti nr-ul membrului pe care doriti sa il stergeti: ";
                                    int nr2;
                                    cin>>nr2;
                                    cout<<endl;

                                    vector <Membru> lista;

                                    lista=listaClase[nr].getListaMembrii();

                                    for(int i=0; i<listaMembrii.size(); i++)
                                        if(listaMembrii[i]==listaClase[nr].getListaMembrii()[nr2])
                                        {
                                            if(listaMembrii[i]==client1)
                                            {
                                                if(frecventa[nr]==1)
                                                {
                                                    float suma=client1.getBuget()+listaClase[nr].getPret();
                                                    client1.settBuget(suma);
                                                    listaMembrii[i].settBuget(suma);
                                                    frecventa[nr]=0;
                                                }
                                                if(frecventa[nr]==2)
                                                {
                                                    float suma=client1.getBuget()+500;
                                                    client1.settBuget(suma);
                                                    listaMembrii[i].settBuget(suma);
                                                    frecventa[nr]=0;
                                                }

                                            }
                                            else
                                            {
                                                float suma=listaMembrii[i].getBuget()+listaClase[nr].getPret();
                                                listaMembrii[i].settBuget(suma);
                                            }

                                        }

                                    lista.erase(lista.begin()+nr2);

                                    listaClase[nr].settListaMembrii(lista);

                                    int nr3=listaClase[nr].getNrLocuri()+1;

                                    listaClase[nr].settNrLocuri(nr3);





                                    clearScreen();
                                    break;
                                }

                                clearScreen();
                                break;


                            }



                            case 9:
                            {
                                clearScreen();
                                break;
                            }

                            default:
                            {
                                clearScreen();
                                cout << "Comanda invalida. Folositi o comanda valida." << endl;
                                break;
                            }
                            }

                            if (comanda4==9)
                                break;
                        }



                    }

                    case 13:
                    {
                        clearScreen();
                        break;
                    }


                    default:
                    {
                        clearScreen();
                        cout << "Comanda invalida. Folositi o comanda valida." << endl;
                        break;
                    }

                    }


                    if (comanda3==13)
                        break;
                }


            }
            else
            {
                cout<<endl;
                cout << "Acces restrictionat. Parola incorecta." << endl;
                pauza(3);
                clearScreen();
            }
            break;
        }
        case 3:
        {

            break;
        }
        default:
        {
            clearScreen();
            cout << "Comanda invalida. Folositi o comanda valida." << endl;
            break;
        }
        }
        if(comanda==3)
        {
            clearScreen();
            break;

        }
    }
    cout<<"La revedere! -Echipa World Class" << endl;





    return 0;
}





