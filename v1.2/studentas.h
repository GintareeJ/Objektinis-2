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
    Studentas() {}

    Studentas(const std::string& v, const std::string& p, const std::vector<int>& pazymiai)
        : vard(v), pavard(p), paz(pazymiai) {}

    ~Studentas() {
        std::cout<<"Destruktorius\n";
    }

    Studentas(const Studentas& other)
        : vard(other.vard),
          pavard(other.pavard),
          paz(other.paz),
          rez_(other.rez_),
          rez2_(other.rez2_) {
          std::cout<<"COPY konstruktorius\n";
          }

    Studentas(Studentas&& other) noexcept
        : vard(std::move(other.vard)),
          pavard(std::move(other.pavard)),
          paz(std::move(other.paz)),
          rez_(other.rez_),
          rez2_(other.rez2_) {
          std::cout<<"MOVE konstruktorius\n";
          }

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vard = other.vard;
            pavard = other.pavard;
            paz = other.paz;
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        std::cout<<"COPY assignment\n";
        return *this;
    }

    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vard = std::move(other.vard);
            pavard = std::move(other.pavard);
            paz = std::move(other.paz);
            rez_ = other.rez_;
            rez2_ = other.rez2_;
        }
        std::cout<<"MOVE assignment\n";
        return *this;
    }

    const std::string& vardas() const { return vard; }
    const std::string& pavarde() const { return pavard; }
    const std::vector<int>& pazymiai() const { return paz; }
    std::vector<int>& pazymiaiRef() { return paz; }
    double rez() const { return rez_; }
    double rez2() const { return rez2_; }

    void setVardas(const std::string& v) { vard = v; }
    void setPavarde(const std::string& p) { pavard = p; }
    void addPazymys(int p) { paz.push_back(p); }
    void clearPazymiai() { paz.clear(); }
    void setPazymiai(const std::vector<int>& p) { paz = p; }
    void setRez(double r) { rez_ = r; }
    void setRez2(double r) { rez2_ = r; }

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
