#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus
{
protected:
    std::string vard;
    std::string pavard;

public:
//default konstruktorius
    Zmogus() = default;
//kontruktorius
    Zmogus(const std::string& v, const std::string& p) : vard(v), pavard(p) {}
//default destruktorius
    virtual ~Zmogus() = default;
//padaro klase abstrakcia
    virtual void abstract() const = 0;
//getteriai
    const std::string& vardas() const { return vard; }
    const std::string& pavarde() const { return pavard; }
//setteriai
    void setVardas(const std::string& v) { vard = v; }
    void setPavarde(const std::string& p) { pavard = p; }

};

#endif