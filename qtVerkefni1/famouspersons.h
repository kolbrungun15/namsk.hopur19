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
    FamousPersons(string newFirstName, string newLastName, string newGender, string whenBorn, string whenDied);

    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    string getFirstName();
    string getLastName();
    void setGender(string newGender); //otharft?
    string getGender();
    void setYearOfBirth(string whenBorn); //otharft?
    string getYearOfBirth();
    void setYearOfDeath(string whenDied); //otharft?
    string getYearOfDeath();


   friend ostream& operator << (ostream& outs, const FamousPersons &n);
   // friend istream& operator >>(istream& ins, FamousPersons &n);

private:
    string firstName;
    string lastName;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
};

#endif // FAMOUSPERSONS_H
