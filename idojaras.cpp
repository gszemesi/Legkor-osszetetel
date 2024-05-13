#include "idojaras.h"
#include "legkor.h"

using namespace std;

Idojaras* Idojaras::create(int k)
{
    switch (k)
    {
        case 0: return Zivatar::instance();
        case 1: return Napos::instance();
        case 2: return Mas::instance();
    }
    return nullptr;
}

// Zivatar
Zivatar* Zivatar::_instance = nullptr;
Zivatar* Zivatar::instance()
{
    if(_instance == nullptr) {
        _instance = new Zivatar();
    }
    return _instance;
}

void Zivatar::change(Oxigen *a)
{
    if(a->GetReteg()!=nullptr) cout<<"HIBA!"<<endl;
    a->SetReteg(new Ozon("z", a->GetVastagsag() * 0.50, nullptr));
    a->SetVastagsag(-(a->GetVastagsag() * 0.50));
}

// Napos
Napos* Napos::_instance = nullptr;
Napos* Napos::instance()
{
    if(_instance == nullptr) {
        _instance = new Napos();
    }
    return _instance;
}

void Napos::change(Oxigen *a)
{
    if(a->GetReteg()!=nullptr) cout<<"HIBA!"<<endl;
    a->SetReteg(new Ozon("z", a->GetVastagsag() * 0.05, nullptr));
    a->SetVastagsag(-(a->GetVastagsag() * 0.05));
}

void Napos::change(Szendioxid *a)
{
    if(a->GetReteg()!=nullptr) cout<<"HIBA!"<<endl;
    a->SetReteg(new Oxigen("x", a->GetVastagsag() * 0.05, nullptr));
    a->SetVastagsag(-(a->GetVastagsag() * 0.05));
}

// Mas
Mas* Mas::_instance = nullptr;
Mas* Mas::instance()
{
    if(_instance == nullptr) {
        _instance = new Mas();
    }
    return _instance;
}

void Mas::change(Ozon *a)
{
    if(a->GetReteg()!=nullptr) cout<<"HIBA!"<<endl;
    a->SetReteg(new Oxigen("x", a->GetVastagsag() * 0.05, nullptr));
    a->SetVastagsag(-(a->GetVastagsag() * 0.05));
}

void Mas::change(Oxigen *a)
{
    if(a->GetReteg()!=nullptr) cout<<"HIBA!"<<endl;
    a->SetReteg(new Szendioxid("s", a->GetVastagsag() * 0.10, nullptr));
    a->SetVastagsag(-(a->GetVastagsag() * 0.10));
}
