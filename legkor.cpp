#include "legkor.h"
#include "idojaras.h"

Legkor *Legkor::GetPeldany()
{
    static Legkor *p = new Legkor();
    return p;
}

void Legkor::FirstAdd(Anyag *a)
{
    anyagok.insert(anyagok.begin(), a);
}

void Legkor::Add(Anyag *a)
{
    anyagok.push_back(a);
}

void Legkor::SetViszonyok(std::string v)
{
    viszonyok = v;
}

void Legkor::Szimulacio() //időjárás szimulációja
{
    //fájl tartalma
    for (int i = anyagok.size() - 1; 0 <= i; i--)
    {
        std::cout << anyagok[i]->GetNev() << " " << anyagok[i]->GetVastagsag() << std::endl;
    }
    std::cout << "Idojarasi viszonyok: " << viszonyok << std::endl
              << std::endl;

    //szimuláció indítása
    int iterate = 0;
    while (Vege())
    {
        //időjárási viszony(zivatar,napos,más)
        Reagalas((char)viszonyok[iterate]);
        RetegRendezes();

        //légrétegek kiíratása körönként
        std::cout << "Idojaras: " << viszonyok[iterate] << std::endl;
        for (int i = anyagok.size() - 1; i >= 0; i--)
        {
            std::cout << anyagok[i]->GetNev() << " " << anyagok[i]->GetVastagsag() << std::endl;
        }

        //következő időjárási viszony beállítása
        std::cout << std::endl;
        if (iterate < (int)viszonyok.size() - 1)
            iterate++;
        else
            iterate = 0;
    }
}

void Legkor::Reagalas(char ido) //mi reagál az adott időjárási viszonyban, az mivé alakul át és mekkor százalékban
{
    int n;
    if (ido == 'z')
        n = 0;
    else if (ido == 'n')
        n = 1;
    else if (ido == 'm')
        n = 2;

    for (int i = 0; i < (int)anyagok.size(); i++)
    {
        anyagok[i]->Reagal(n);
    }
}

void Legkor::RetegRendezes() //Létre jött-e új réteg vagy vékonyá vált-e?
{
    for (int i = 0; i < (int)anyagok.size(); i++)
    {
        //Létre jött új réteg?
        if (anyagok[i]->GetReteg() != nullptr)
        {
            bool l = false;
            for (int j = i + 1; j < (int)anyagok.size(); j++) //keresük felette lévő, úgyan olyan anyagú réteget
            {
                if (anyagok[j]->GetNev() == anyagok[i]->GetReteg()->GetNev() && !l)
                {
                    anyagok[j]->SetVastagsag(anyagok[i]->GetReteg()->GetVastagsag());
                    l = true;
                }
            }
            if (!l) //ha nem találtunk, akkor újat hozunk létre a légkör legtetején
            {
                if (anyagok[i]->GetReteg()->GetNev() == "z")
                    Add(new Ozon(anyagok[i]->GetReteg()->GetNev(), anyagok[i]->GetReteg()->GetVastagsag(), nullptr));
                else if (anyagok[i]->GetReteg()->GetNev() == "x")
                    Add(new Oxigen(anyagok[i]->GetReteg()->GetNev(), anyagok[i]->GetReteg()->GetVastagsag(), nullptr));
                else if (anyagok[i]->GetReteg()->GetNev() == "s")
                    Add(new Szendioxid(anyagok[i]->GetReteg()->GetNev(), anyagok[i]->GetReteg()->GetVastagsag(), nullptr));
            }
            Anyag *a = anyagok[i]->GetReteg();
            delete a;
            anyagok[i]->SetReteg(nullptr);
        }

        //A réteg vékonnyá vált? (0.5 km-nél vékonyabb)
        if (anyagok[i]->GetVastagsag() < 0.5)
        {
            bool l = false;
            for (int j = i + 1; j < (int)anyagok.size(); j++) //kersük felette lévő, úgyan olyan anyagú réteget
            {
                if (anyagok[j]->GetNev() == anyagok[i]->GetNev() && !l) //ha találnuk, akkor hozzá adjuk a vékony réteget
                {
                    anyagok[j]->SetVastagsag(anyagok[i]->GetVastagsag());
                    l = true;
                }
            }
            Anyag *a = anyagok[i];
            anyagok.erase(anyagok.begin() + i); //ha találtunk, ha nem kitöröljük a réteget
            i--;                                //rétegtörlés miatt a kövekező elem lejjebb került(a mostnai réteg helyére) ezért nem lépünk tovább
            delete a;
        }
    }
}

bool Legkor::Vege() //Végig nézi a rétegeket, hogy mind a 3 anyag megtalálható-e. Ha nem false-al tér vissza.
{
    bool z = false;
    bool x = false;
    bool s = false;
    for (int i = 0; i < (int)anyagok.size(); i++)
    {
        if (anyagok[i]->GetNev() == "z")
            z = true;
        else if (anyagok[i]->GetNev() == "x")
            x = true;
        else if (anyagok[i]->GetNev() == "s")
            s = true;
    }
    return (z && x && s);
}

Legkor::~Legkor() //destruktor
{
    for (Anyag *a : anyagok)
    {
        delete a;
    }
}

