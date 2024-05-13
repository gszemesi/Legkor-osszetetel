#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "idojaras.h"

class Anyag
{
protected:
    std::string nev;
    double vastagsag;
    Anyag *ujreteg;

    Anyag(std::string n, double v, Anyag *a) : nev(n), vastagsag(v), ujreteg(a) {}

public:
    virtual ~Anyag() {};

    std::string GetNev() { return nev; };
    void SetNev(std::string n) { nev = n; };

    double GetVastagsag() { return vastagsag; };
    void SetVastagsag(double s) { vastagsag = vastagsag + s; };

    Anyag *GetReteg() { return ujreteg; };
    void SetReteg(Anyag *a) { ujreteg = a; };

    virtual void Reagal(int r) =0;
};

class Ozon : public Anyag
{
public:
    Ozon(std::string n, double v, Anyag *a) : Anyag(n, v, a) {}
    ~Ozon() { delete ujreteg; }
    void Reagal(int r) override {
        Idojaras::create(r)->change(this);
    }
};

class Oxigen : public Anyag
{
public:
    Oxigen(std::string n, double v, Anyag *a) : Anyag(n, v, a) {}
    ~Oxigen() { delete ujreteg; }
    void Reagal(int r) override {
        Idojaras::create(r)->change(this);
    }
};

class Szendioxid : public Anyag
{
public:
    Szendioxid(std::string n, double v, Anyag *a) : Anyag(n, v, a) {}
    ~Szendioxid() { delete ujreteg; }
    void Reagal(int r) override {
        Idojaras::create(r)->change(this);
    }
};