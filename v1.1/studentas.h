#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas {
private:
    std::string vard;
    std::string pavard;
    std::vector<int> paz;
    double rez_ = 0.0;
    double rez2_ = 0.0;

public:
    Studentas()=default;

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
};

#endif
