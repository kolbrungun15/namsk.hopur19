#include <iostream>
#include <string>
#ifndef CSLEAGEND_H
#define CSLEAGEND_H

using namespace std;

class CSLeagend
{

public:
    CSLeagend();
    void setName(string newName);
    string getName();
    void setGender(string newGender);
    string getGender();
    void setYearOfBirth(int whenBorn);
    int getYearOfBirth();
    void setYearOfDeath(int whenDied);
    int getYearOfDeath();
 private:
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // CSLEAGEND_H
