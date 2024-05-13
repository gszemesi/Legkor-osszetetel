/*
Szemesi Gábor
ql10n6
OEP Komplex bead
2022.05.
*/

#include "legkor.h"
#include "idojaras.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Legkor *p = Legkor::GetPeldany(); //pédányosítás

    std::string filename;
    std::cout << "Fajl nev: ";

    cin >> filename; //fajl név bekérésa
    //filename = "inp.txt";

    ifstream inf(filename);
    if (inf.fail()) //fájl sikeres megnyitásának vizsgálata
        exit(-1);

    int n;
    inf >> n; //első sorból kiolvassuk,hány sor van a fajlban (csak réteg szám)

    string a;
    double b;
    for (int i = 0; i < n; i++) //végig megyünk a fajlon(első sorból kiolvasott érték alapján) és feltöltjük a vektort a rétegekkel
    {
        inf >> a >> b;
        if (a == "z")
            p->FirstAdd(new Ozon(a, (double)b, nullptr)); //Ozon
        else if (a == "x")
            p->FirstAdd(new Oxigen(a, (double)b, nullptr)); //Oxigen
        else if (a == "s")
            p->FirstAdd(new Szendioxid(a, (double)b, nullptr)); //Széndioxid
    }

    string v;
    inf >> v; //beolvassuk a fájl utolsó sorát, ami az időjárási viszonyokat tartalmazza

    p->SetViszonyok(v); //eltároljuk a viszonyokat

    p->Szimulacio(); //elinditjuk a szimulációt

    delete Idojaras::create(0);
    delete Idojaras::create(1);
    delete Idojaras::create(2);

    delete p; //légkör törlése

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("t0", "0.txt")
{
    Legkor *p = Legkor::GetPeldany();
    ifstream inf("0.txt");
    if (inf.fail())
    {
        cout << "Nem sikerult megnyitni a fajlt\n";
    }
    int n;
    inf >> n;

    string a;
    double b;
    for (int i = 0; i < n; i++)
    {
        inf >> a >> b;
        if (a == "z")
            p->FirstAdd(new Ozon(a, (double)b, nullptr));
        else if (a == "x")
            p->FirstAdd(new Oxigen(a, (double)b, nullptr));
        else if (a == "s")
            p->FirstAdd(new Szendioxid(a, (double)b, nullptr));
    }

    string v;
    inf >> v;

    p->SetViszonyok(v);

    p->Szimulacio();


    CHECK(p->GetAnyag(0)->GetNev() == "s");
    CHECK(p->GetAnyag(0)->GetVastagsag() == 3);
    CHECK(p->GetAnyag(1)->GetNev() == "z");
    CHECK(p->GetAnyag(1)->GetVastagsag() == 6.125);

    delete Idojaras::create(0);
    delete Idojaras::create(1);
    delete Idojaras::create(2);
    delete p;
}
TEST_CASE("t1", "z.txt")
{
    cout<<"asd";
    Legkor *p = Legkor::GetPeldany();
    ifstream inf("z.txt");
    if (inf.fail())
    {
        cout << "Nem sikerult megnyitni a fajlt\n";
    }
    int n;
    inf >> n;

    string a;
    double b;
    for (int i = 0; i < n; i++)
    {
        inf >> a >> b;
        if (a == "z")
            p->FirstAdd(new Ozon(a, (double)b, nullptr));
        else if (a == "x")
            p->FirstAdd(new Oxigen(a, (double)b, nullptr));
        else if (a == "s")
            p->FirstAdd(new Szendioxid(a, (double)b, nullptr));
    }

    string v;
    inf >> v;

    p->SetViszonyok(v);

    p->Szimulacio();

    CHECK(p->GetAnyag(0)->GetNev() == "s");
    CHECK(p->GetAnyag(0)->GetVastagsag() == 3);
    CHECK(p->GetAnyag(1)->GetNev() == "z");
    CHECK(p->GetAnyag(1)->GetVastagsag() == 5.3);

    delete Idojaras::create(0);
    delete Idojaras::create(1);
    delete Idojaras::create(2);
    delete p;
}
TEST_CASE("t2", "n.txt")
{
    Legkor *p = Legkor::GetPeldany();
    ifstream inf("n.txt");
    if (inf.fail())
    {
        cout << "Nem sikerult megnyitni a fajlt\n";
    }
    int n;
    inf >> n;

    string a;
    double b;
    for (int i = 0; i < n; i++)
    {
        inf >> a >> b;
        if (a == "z")
            p->FirstAdd(new Ozon(a, (double)b, nullptr));
        else if (a == "x")
            p->FirstAdd(new Oxigen(a, (double)b, nullptr));
        else if (a == "s")
            p->FirstAdd(new Szendioxid(a, (double)b, nullptr));
    }

    string v;
    inf >> v;

    p->SetViszonyok(v);

    p->Szimulacio();

    CHECK(p->GetAnyag(0)->GetNev() == "z");
    CHECK(p->GetAnyag(1)->GetNev() == "s");
    CHECK(p->GetAnyag(2)->GetNev() == "z");
}
TEST_CASE("t3", "m.txt")
{
    Legkor *p = Legkor::GetPeldany();
    ifstream inf("m.txt");
    if (inf.fail())
    {
        cout << "Nem sikerult megnyitni a fajlt\n";
    }
    int n;
    inf >> n;

    string a;
    double b;
    for (int i = 0; i < n; i++)
    {
        inf >> a >> b;
        if (a == "z")
            p->FirstAdd(new Ozon(a, (double)b, nullptr));
        else if (a == "x")
            p->FirstAdd(new Oxigen(a, (double)b, nullptr));
        else if (a == "s")
            p->FirstAdd(new Szendioxid(a, (double)b, nullptr));
    }

    string v;
    inf >> v;

    p->SetViszonyok(v);

    p->Szimulacio();

    CHECK(p->GetAnyag(0)->GetNev() == "s");
    CHECK(p->GetAnyag(1)->GetNev() == "s");
    CHECK(p->GetAnyag(2)->GetNev() == "s");
}

#endif // NORMAL_MODE
