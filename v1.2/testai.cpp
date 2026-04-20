#include <iostream>
#include <sstream>
#include "studentas.h"

using std::cout;
using std::endl;

void TestDefaultKonstruktorius() {
    Studentas s;
    cout<<"Default konstruktorius iskviestas\n";
}

void TestCopyKonstruktorius() {
    Studentas a;
    a.setVardas("Jonas");
    a.addPazymys(10);

    Studentas b = a;

    cout<<"Copy konstruktorius: "<<b.vardas()<<" "<<b.pazymiai().size()<<endl;
}

void TestMoveKonstruktorius() {
    Studentas a;
    a.setVardas("Petras");
    a.addPazymys(9);

    Studentas b = std::move(a);

    cout<<"Move konstruktorius: "<<b.vardas()<<" "<<b.pazymiai().size()<<endl;
}

void TestCopyAssignment() {
    Studentas a;
    a.setVardas("Jonas");

    Studentas b;
    b = a;

    cout<<"Copy assignment: "<<b.vardas()<<endl;
}

void TestMoveAssignment() {
    Studentas a;
    a.setVardas("Mantas");

    Studentas b;
    b = std::move(a);

    cout<<"Move assignment: "<<b.vardas()<<endl;
}

void TestDestruktorius() {
    Studentas a;
    a.setVardas("Test");

    cout<<"Destruktorius iskviestas\n";
}

void TestIsvestis() {
    Studentas s;
    s.setVardas("Vardenis");
    s.setPavarde("Pavardenis");
    s.addPazymys(10);
    s.addPazymys(9);
    s.addPazymys(8);
    s.setRez(9.0);
    
    cout<<"Išvedame studentą: "<<s<< "Išvesties operatorius veikia"<<"\n";
}

void TestIvestis() {
    std::istringstream iss("Vardenis2 Pavardenis2 8 7 6 10");
    
    Studentas s;
    iss >> s; 
    
    cout<<"Nuskaitytasis studentas: "<<s<<"Ivesties operatorius veikia\n";
}

int main() {
    cout<<"TESTAI\n";

    TestDefaultKonstruktorius();
    TestCopyKonstruktorius();
    TestMoveKonstruktorius();
    TestCopyAssignment();
    TestMoveAssignment();
    TestDestruktorius();
    TestIsvestis();
    TestIvestis();
}