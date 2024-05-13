#pragma once

#include <string>
#include <iostream>

class Ozon;
class Szendioxid;
class Oxigen;


class Idojaras{
public:
    virtual void change(Ozon *a)  =0;
    virtual void change(Szendioxid *a)  =0;
    virtual void change(Oxigen *a)  =0;
    virtual ~Idojaras() {}
    static Idojaras* create(int k);
};


class Zivatar : public Idojaras
{
public:
    static Zivatar* instance();
    void change(Ozon *a) override {0;};
    void change(Szendioxid *a) override {0;};
    void change(Oxigen *a) override;
    void static destroy() { if ( nullptr!=_instance ) delete _instance; _instance = nullptr; }
private:
    Zivatar(){}
    static Zivatar* _instance;
};


class Napos : public Idojaras
{
public:
    static Napos* instance();
    void change(Ozon *a) override {0;};
    void change(Szendioxid *a) override;
    void change(Oxigen *a) override;
    static void destroy() { if ( nullptr!=_instance ) delete _instance; _instance = nullptr; }
private:
    Napos(){}
    static Napos* _instance;
};


class Mas : public Idojaras
{
public:
    static Mas* instance();
    void change(Ozon *a) override;
    void change(Szendioxid *a) override  {0;};
    void change(Oxigen *a) override;
    void static destroy() { if ( nullptr!=_instance ) delete _instance; _instance = nullptr; }
private:
    Mas(){}
    static Mas* _instance;
};