#include <iostream>
#include <sstream>
#include <cassert>
#include "studentas.h"

using std::cout;
using std::endl;

void TestDefaultKonstruktorius() {
    Studentas s;

    assert(s.vardas().empty());
    assert(s.pavarde().empty());
    assert(s.pazymiai().empty());
    assert(s.rez() == 0.0);
    assert(s.rez2() == 0.0);

    cout << "Default OK\n";
}

void TestCopyKonstruktorius() {
    Studentas a;

    a.setVardas("Jonas");
    a.setPavarde("Jonaitis");
    a.addPazymys(10);
    a.addPazymys(9);
    a.setRez(9.5);
    a.setRez2(9.0);

    Studentas b = a;

    assert(b.vardas() == a.vardas());
    assert(b.pavarde() == a.pavarde());
    assert(b.pazymiai() == a.pazymiai());
    assert(b.rez() == a.rez());
    assert(b.rez2() == a.rez2());

    cout << "Copy constructor OK\n";
}

void TestMoveKonstruktorius() {
    Studentas a;

    a.setVardas("Petras");
    a.setPavarde("Petraitis");
    a.addPazymys(8);
    a.addPazymys(9);
    a.setRez(8.5);
    a.setRez2(8.0);

    Studentas b = std::move(a);

    // destination
    assert(b.vardas() == "Petras");
    assert(b.pavarde() == "Petraitis");
    assert(b.pazymiai().size() == 2);
    assert(b.rez() == 8.5);
    assert(b.rez2() == 8.0);

    // source po move
    assert(a.vardas().empty());
    assert(a.pavarde().empty());
    assert(a.pazymiai().empty());
    assert(a.rez() == 0.0);
    assert(a.rez2() == 0.0);

    cout << "Move constructor OK\n";
}

void TestCopyAssignment() {
    Studentas a;

    a.setVardas("Mantas");
    a.setPavarde("Mantaitis");
    a.addPazymys(7);
    a.setRez(7.0);
    a.setRez2(7.0);

    Studentas b;
    b = a;

    assert(b.vardas() == a.vardas());
    assert(b.pavarde() == a.pavarde());
    assert(b.pazymiai() == a.pazymiai());
    assert(b.rez() == a.rez());
    assert(b.rez2() == a.rez2());

    cout << "Copy assignment OK\n";
}

void TestMoveAssignment() {
    Studentas a;

    a.setVardas("Tomas");
    a.setPavarde("Tomaitis");
    a.addPazymys(10);
    a.addPazymys(8);
    a.setRez(9.0);
    a.setRez2(8.0);

    Studentas b;
    b = std::move(a);

    // destination
    assert(b.vardas() == "Tomas");
    assert(b.pavarde() == "Tomaitis");
    assert(b.pazymiai().size() == 2);
    assert(b.rez() == 9.0);
    assert(b.rez2() == 8.0);

    // source po move
    assert(a.vardas().empty());
    assert(a.pavarde().empty());
    assert(a.pazymiai().empty());
    assert(a.rez() == 0.0);
    assert(a.rez2() == 0.0);

    cout << "Move assignment OK\n";
}

void TestIvestis() {
    std::istringstream iss(
        "Vardenis Pavardenis 8 9 10"
    );

    Studentas s;
    iss >> s;

    assert(s.vardas() == "Vardenis");
    assert(s.pavarde() == "Pavardenis");
    assert(s.pazymiai().size() == 3);
    assert(s.pazymiai()[0] == 8);
    assert(s.pazymiai()[1] == 9);
    assert(s.pazymiai()[2] == 10);

    cout << "Input operator OK\n";
}

int main() {
    cout << "TESTAI\n\n";

    TestDefaultKonstruktorius();
    TestCopyKonstruktorius();
    TestMoveKonstruktorius();
    TestCopyAssignment();
    TestMoveAssignment();
    TestIvestis();

    cout << "\nVisi testai praejo.\n";
}
