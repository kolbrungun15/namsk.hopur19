#include "famouspersons.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

FamousPersons::FamousPersons() {
    string Name = "";
    string Gender = "";
    string YearOfBirth = "";
    string YearOfDeath = "";
}

FamousPersons::FamousPersons(string a, string b, string c, string d) {
    string Name = a;
    string Gender = b;
    string YearOfBirth = c;
    string YearOfDeath = d;
} //Annaðhvort getum við get þetta svona eða /a /b /c /d

void setName(string newName) {
    Name = newName;
} //a

string getName() {
    return Name;
}

void setGender(string newGender) {
    Gender = newGender;
} //b

string getGender() {
    return Gender;
}

void setYearOfBirth(string whenBorn) {
    YearOfBirth = whenBorn
} //c

string getYearOfBirth() {
    return YearOfBirth;
}

void setYearOfDeath(string whenDied) {
    YearOfDeath = whenDied;
} //d

string getYearOfDeath() {
    return YearOfDeath;
}

ostream& operator << (ostream& outs, const FamousPersons &n){
    // Vantar
}

istream& operator >> (istream& ins, FamousPersons &n){
    // Vantar
}
