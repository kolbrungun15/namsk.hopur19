#include "famouspersons.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

FamousPersons::FamousPersons() {
    name = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
}

FamousPersons::FamousPersons(string newName, string newGender, string whenBorn, string whenDied) {
    name = newName;
    gender = newGender;
    yearOfBirth = whenBorn;
    yearOfDeath = whenDied;
}

void FamousPersons::setName(string newName) {
    name = newName;
}

string FamousPersons::getName() {
    return name;
}

void FamousPersons::setGender(string newGender) {
    gender = newGender;
}

string FamousPersons::getGender() {
    return gender;
}

void FamousPersons::setYearOfBirth(string whenBorn) {
    yearOfBirth = whenBorn;
}

string FamousPersons::getYearOfBirth() {
    return yearOfBirth;
}

void FamousPersons::setYearOfDeath(string whenDied) {
    yearOfDeath = whenDied;
}

string FamousPersons::getYearOfDeath() {
    return yearOfDeath;
}

ostream& operator << (ostream& outs, const FamousPersons &n){
    cout << "Name: " << n.name << endl;
    cout << "Gender: " << n.gender << endl;
    cout << "Year of birth: " << n.yearOfBirth << endl;
    cout << "Year of death: " << n.yearOfDeath << endl;

    return outs;
}
istream& operator >>(istream& ins, FamousPersons &n)

{
    ins >> n.name;
    ins >> n.gender;
    ins >> n.yearOfBirth;
    ins >> n.yearOfDeath;

    return ins;
}
