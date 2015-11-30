#ifndef FAMOUSPERSONS_H
#define FAMOUSPERSONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class FamousPersons {

public:
    FamousPersons();
    FamousPersons(string newName, string newGender, string whenBorn, string whenDied);

    void setName(string newName);
    string getName();
    void setGender(string newGender);
    string getGender();
    void setYearOfBirth(string whenBorn);
    string getYearOfBirth();
    void setYearOfDeath(string whenDied);
    string getYearOfDeath();


   // friend ostream& operator << (ostream& outs, const FamousPersons &n);
   // friend istream& operator >>(istream& ins, FamousPersons &n);

private:
    string name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
};

#endif // FAMOUSPERSONS_H
