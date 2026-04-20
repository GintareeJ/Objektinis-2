#ifndef PASIRINKIMAI_H
#define PASIRINKIMAI_H

#include "studentas.h"
#include "rusiavimas.h"
#include <chrono>
#include <iostream>
using namespace std::chrono;
using std::cout;

void Skaiciavimai(std::vector<Studentas>& studentai, int b);
void Spausdinimas(std::vector<Studentas>& studentai, int& b);
bool VardasPavarde(Studentas& s);
int kinta();
int kintrus(int& rus);
int kintr(int& r);
void RandPaz(std::vector<Studentas>& studentai, Studentas& s, int& kiek);
void PirmasP(std::vector<Studentas>& studentai, int& b);
void AntrasP(std::vector<Studentas>& studentai, int& b);
void TreciasP(std::vector<Studentas>& studentai, const std::vector<std::string>& pavardes,  const std::vector<std::string>& vardai, int& b);
void KetvirtasP(std::vector<Studentas>& studentai, const std::string& CVfd, const std::string& CVfr, double& suma2, double& suma3, double& suma4, double& suma5, double& suma6, int& spausd, bool& skaitytaIsFailo, int& b);
void GeneruotiStudentuFaila(const std::string& failoPav, int studentuKiekis, int ndKiekis);
template <typename Konteineris>void SpausdintiIFaila(const std::string& failoPav, const Konteineris& studentai, int b)
{
    std::ofstream fr(failoPav);
    if (b == 0)
    {
        fr << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
        for (const auto& s : studentai)
        {
            fr << std::left << std::setw(15) << s.pavarde()<< std::left << std::setw(15) << s.vardas()<< std::fixed << std::setprecision(2) << s.rez() << "\n";
        }
    }
    else
    {
        fr << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
        for (const auto& s : studentai)
        {
            fr << std::left << std::setw(15) << s.pavarde()<< std::left << std::setw(15) << s.vardas()<< std::fixed << std::setprecision(2) << s.rez2() << "\n";
        }
    }

    fr.close();
}
void PenktasP();

template <typename Konteineris>
void SkaiciavimaiBendras(Konteineris& studentai, int b)
{
    if (b == 0) {
        for (auto& s : studentai) {
            auto& paz = s.pazymiaiRef();
            if (paz.size() < 2) continue;

            double suma = 0.0;
            for (size_t j = 0; j + 1 < paz.size(); j++) {
                suma += paz[j];
            }

            s.setRez(suma / (paz.size() - 1) * 0.4 + paz.back() * 0.6);
        }
    } else {
        for (auto& s : studentai) {
            auto& paz = s.pazymiaiRef();
            if (paz.size() < 2) continue;

            std::sort(paz.begin(), paz.end() - 1);

            int nd = paz.size() - 1;
            double med;

            if (nd % 2 == 1) med = paz[nd / 2];
            else med = (paz[nd / 2 - 1] + paz[nd / 2]) / 2.0;

            s.setRez2(med * 0.4 + paz.back() * 0.6);
        }
    }
}

template <typename Konteineris>
void NuskaitytiIsFailoBendras(Konteineris& studentai, const std::string& failoPav)
{
    std::ifstream fd(failoPav);
    if (!fd.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo");
    }

    studentai.clear();

    std::string eilute;
    std::getline(fd, eilute);

    while (std::getline(fd, eilute)) {
        std::stringstream st(eilute);
        Studentas s;
        std::string vardas, pavarde;
        int p;

        st >> vardas >> pavarde;
        s.setVardas(vardas);
        s.setPavarde(pavarde);

        while (st >> p) {
            s.addPazymys(p);
        }

        studentai.push_back(std::move(s));
    }
}

template <typename Konteineris>
void PadalintiStudentusBendras1(const Konteineris& studentai, Konteineris& vargsiukai, Konteineris& kietiakai, int b) // pagal pirma strategija
{
    vargsiukai.clear();
    kietiakai.clear();

    for (const auto& s : studentai) {
        if (b == 0) {
            if (s.rez() < 5.0) vargsiukai.push_back(std::move(s));
            else kietiakai.push_back(s);
        } else {
            if (s.rez2() < 5.0) vargsiukai.push_back(std::move(s));
            else kietiakai.push_back(std::move(s));
        }
    }
}

template <typename Konteineris>
void PadalintiStudentusBendras2(Konteineris& studentai, Konteineris& vargsiukai, int b)
{
    vargsiukai.clear();

    for (size_t i = 0; i < studentai.size();) {
        if (b == 0) {
            if (studentai[i].rez() < 5.0)
            {
                vargsiukai.push_back(std::move(studentai[i]));
                studentai.erase(studentai.begin() + i);
            }
            else
            {
                ++i;
            }
        }
        else {
            if (studentai[i].rez2() < 5.0)
            {
                vargsiukai.push_back(std::move(studentai[i]));
                studentai.erase(studentai.begin() + i);
            }
            else
            {
                ++i;
            }
        }
    }
}

void PadalintiStudentusBendras2(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, int b);

template <typename Konteineris>
void RusiuotiBendras(Konteineris& studentai, int b, int r, int rus)
{
    if (b == 0) {
        if (rus == 0) {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidVar);
            else std::sort(studentai.begin(), studentai.end(), MazVar);
        }
        else if (rus == 1) {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidPav);
            else std::sort(studentai.begin(), studentai.end(), MazPav);
        }
        else {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidVid);
            else std::sort(studentai.begin(), studentai.end(), MazVid);
        }
    }
    else {
        if (rus == 0) {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidVar);
            else std::sort(studentai.begin(), studentai.end(), MazVar);
        }
        else if (rus == 1) {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidPav);
            else std::sort(studentai.begin(), studentai.end(), MazPav);
        }
        else {
            if (r == 0) std::sort(studentai.begin(), studentai.end(), DidMed);
            else std::sort(studentai.begin(), studentai.end(), MazMed);
        }
    }
}

void RusiuotiBendras(std::list<Studentas>& studentai, int b, int r, int rus);

template <typename Konteineris>
void PadalintiStudentusBendras3(Konteineris& studentai, Konteineris& vargsiukai, int b) //3 strategija vector greitesniam veikimui
{
    vargsiukai.clear();

    auto it = std::stable_partition(studentai.begin(), studentai.end(), [b](const auto& s) { return (b == 0) ? s.rez() >= 5.0 : s.rez2() >= 5.0; });

    vargsiukai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());
}

template <typename Konteineris>
void TestuotiKonteineri(const std::string& konteinerioPav, const std::string& failas, int studentuKiekis, int ndKiekis, int b, int r, int rus, int strategija)
{
    Konteineris studentai;
    Konteineris vargsiukai;
    Konteineris kietiakai;

    double testuKartai = 3;
    double nuskaitymas=0;
    double rusiavimas=0;
    double skirstymas=0;
    double visas=0;

    if(std::ifstream(failas)) 
    {
       cout<<"Failas "<<failas<<" jau egzistuoja, generavimas praleidziamas.\n";
    }
    else {
    GeneruotiStudentuFaila(failas, studentuKiekis, ndKiekis);
    }
    auto start =  high_resolution_clock::now();
    for(int i=0; i<testuKartai; i++)
{
    //nuskaitymas
    auto startN = high_resolution_clock::now();
    NuskaitytiIsFailoBendras(studentai, failas);
    auto endN = high_resolution_clock::now();
    nuskaitymas+=duration<double>(endN - startN).count();

    SkaiciavimaiBendras(studentai, b);

//rusiavimas
    auto startR = high_resolution_clock::now();
    RusiuotiBendras(studentai, b, r, rus);
    auto endR = high_resolution_clock::now();
    rusiavimas+=duration<double>(endR - startR).count();

//skirstymas
    auto startD = high_resolution_clock::now();
    //1 strategija
    if(strategija==1) PadalintiStudentusBendras1(studentai, vargsiukai, kietiakai, b);
    //2 strategija
    if(strategija==2) PadalintiStudentusBendras2(studentai, vargsiukai, b);
    //3 strategija
    if(strategija==3) PadalintiStudentusBendras3(studentai, vargsiukai, b);
    auto endD = high_resolution_clock::now();
    skirstymas+=duration<double>(endD - startD).count();
}
    auto end = high_resolution_clock::now();
    visas=duration<double>(end - start).count();

    cout << "Konteineris: " << konteinerioPav << "\n";
    cout << "Failas: " << failas << "\n";
    cout << "Nuskaitymas: " << nuskaitymas/testuKartai << " s\n";
    cout << "Rusiavimas: " << rusiavimas/testuKartai << " s\n";
    if(strategija==1) cout<<"1 STRATEGIJA: \n";
    if(strategija==2) cout<<"2 STRATEGIJA: \n";
    if(strategija==3) cout<<"3 STRATEGIJA: \n";
    cout << "Skirstymas: " << skirstymas/testuKartai << " s\n";
    cout << "Visas veikimo laikas: "<< visas<< " s\n"<<std::endl;
    cout << "-----------------------------------\n";
    
}
#endif
