#include "famouspersons.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

FamousPersons::FamousPersons()
{
    firstName = "";
    lastName = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
}

FamousPersons::FamousPersons(string newFirstName, string newLastName, string newGender, string whenBorn, string whenDied)
{
    firstName = newFirstName;
    lastName = newLastName;
    gender = newGender;
    yearOfBirth = whenBorn;
    yearOfDeath = whenDied;
}

void FamousPersons::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void FamousPersons::setLastName(string newLastName)
{
    lastName = newLastName;
}

string FamousPersons::getFirstName()
{
    return firstName;
}

string FamousPersons::getLastName()
{
    return lastName;
}

void FamousPersons::setGender(string newGender)
{
    gender = newGender;
}

string FamousPersons::getGender()
{
    return gender;
}

void FamousPersons::setYearOfBirth(string whenBorn)
{
    yearOfBirth = whenBorn;
}

string FamousPersons::getYearOfBirth()
{
    return yearOfBirth;
}

void FamousPersons::setYearOfDeath(string whenDied)
{
    yearOfDeath = whenDied;
}

string FamousPersons::getYearOfDeath()
{
    return yearOfDeath;
}

ostream& operator << (ostream& outs, const FamousPersons &n)
{
    cout << "First name: " << n.firstName << endl;
    cout << "Last name: " << n.lastName << endl;
    cout << "Gender (male/female): " << n.gender << endl;
    cout << "Year of birth: " << n.yearOfBirth << endl;
    cout << "Year of death: " << n.yearOfDeath << endl;

    return outs;
}

/*
istream& operator >>(istream& ins, FamousPersons &n)
{
    ins >> n.name;
    ins >> n.gender;
    ins >> n.yearOfBirth;
    ins >> n.yearOfDeath;
    return ins;
}
*/
