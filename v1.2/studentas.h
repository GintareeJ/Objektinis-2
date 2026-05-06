#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Studentas {
private:
    std::string vard;
    std::string pavard;
    std::vector<int> paz;
    double rez_ = 0.0;
    double rez2_ = 0.0;

public:
    Studentas() {} //default kons.

    Studentas(const std::string& v, const std::string& p, const std::vector<int>& pazymiai, double rezult, double rezult2) : 
    vard(v), pavard(p), paz(pazymiai), rez_(rezult), rez2_(rezult2) {} //parametrinis kons.

    ~Studentas() { 
        vard.clear();
        pavard.clear();
        paz.clear();
        rez_=0.0;
        rez2_=0.0; 
    }

    Studentas(const Studentas& other) 
        : vard(other.vard),
          pavard(other.pavard),
          paz(other.paz),
          rez_(other.rez_),
          rez2_(other.rez2_) {} //copy kons.

    Studentas(Studentas&& other) noexcept
        : vard(std::move(other.vard)),
          pavard(std::move(other.pavard)),
          paz(std::move(other.paz)),
          rez_(other.rez_),
          rez2_(other.rez2_)
    {
        other.rez_ = 0.0;
        other.rez2_ = 0.0;
    }

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vard = other.vard;
            pavard = other.pavard;
            paz = other.paz;
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        return *this;
    } //copy assigment k.

    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vard = std::move(other.vard);
            pavard = std::move(other.pavard);
            paz = std::move(other.paz);
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        other.rez_ = 0.0;
        other.rez2_ = 0.0;
        return *this;
    } //move assigment k.

    //getteriai
    const std::string& vardas() const { return vard; }
    const std::string& pavarde() const { return pavard; }
    const std::vector<int>& pazymiai() const { return paz; }
    std::vector<int>& pazymiaiRef() { return paz; }
    double rez() const { return rez_; }
    double rez2() const { return rez2_; }

    //setteriai
    void setVardas(const std::string& v) { vard = v; }
    void setPavarde(const std::string& p) { pavard = p; }
    void addPazymys(int p) { paz.push_back(p); }
    void clearPazymiai() { paz.clear(); }
    void setPazymiai(const std::vector<int>& p) { paz = p; }
    void setRez(double r) { rez_ = r; }
    void setRez2(double r) { rez2_ = r; }
//<< ir >> operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << std::left << std::setw(15) << s.vard 
       << std::left << std::setw(15) << s.pavard;

    for (auto p : s.paz) {
        os << p << " ";
    }
    
    if (s.rez_ > 0) {
        os << std::fixed << std::setprecision(2) << " | Vid: " << s.rez_;
    }
    if (s.rez2_ > 0) {
        os << std::fixed << std::setprecision(2) << " | Med: " << s.rez2_;
    }
    
    return os;
   }
 
   friend std::istream& operator>>(std::istream& is, Studentas& s) {
    std::string v, p;

    is >> v >> p;
    
    s.setVardas(v);
    s.setPavarde(p);

    int paz;
    s.clearPazymiai();
    while (is >> paz) {
        s.addPazymys(paz);
        if (is.peek() == '\n') break;
    }
    
    return is;
   }

};


#endif
