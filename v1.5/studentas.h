#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Studentas : public Zmogus {
private:
    std::vector<int> paz;
    double rez_ = 0.0;
    double rez2_ = 0.0;

public:
//default konstruktorius
    Studentas() {}
//konstruktorius
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& pazymiai)
        : Zmogus(v, p), paz(pazymiai) {}
//default konstruktorius
    ~Studentas() {}
//copy k.
    Studentas(const Studentas& other)
        : Zmogus(other.vard, other.pavard),
          paz(other.paz),
          rez_(other.rez_),
          rez2_(other.rez2_) {}
//move k.
    Studentas(Studentas&& other) noexcept
        : Zmogus(std::move(other.vard), std::move(other.pavard)),
          paz(std::move(other.paz)),
          rez_(other.rez_),
          rez2_(other.rez2_) {}
//copy assigment k.
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vard = other.vard;
            pavard = other.pavard;
            paz = other.paz;
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        return *this;
    }
//move assigment k.
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vard = std::move(other.vard);
            pavard = std::move(other.pavard);
            paz = std::move(other.paz);
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        return *this;
    }
//padaro studentas isvestine klase
    void abstract() const override {}
//getteriai
    const std::vector<int>& pazymiai() const { return paz; }
    std::vector<int>& pazymiaiRef() { return paz; }
    double rez() const { return rez_; }
    double rez2() const { return rez2_; }
//setteriai
    void addPazymys(int p) { paz.push_back(p); }
    void clearPazymiai() { paz.clear(); }
    void setPazymiai(const std::vector<int>& p) { paz = p; }
    void setRez(double r) { rez_ = r; }
    void setRez2(double r) { rez2_ = r; }

};

std::istream& operator>>(std::istream& is, Studentas& s)
{
    std::string v, p;

    is >> v >> p;

    s.setVardas(v);
    s.setPavarde(p);

    int paz;
    s.clearPazymiai();

    while (is >> paz) {
        s.addPazymys(paz);

        if (is.peek() == '\n')
            break;
    }

    return is;
}

std::istream& operator>>(std::istream& is, Studentas& s)
{
    std::string v, p;

    is >> v >> p;

    s.setVardas(v);
    s.setPavarde(p);

    int paz;
    s.clearPazymiai();

    while (is >> paz) {
        s.addPazymys(paz);

        if (is.peek() == '\n')
            break;
    }

    return is;
}

#endif
