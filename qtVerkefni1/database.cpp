#include "database.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

Database::Database(string filename)
{

}

void Database::add(FamousPersons pers)
{
    vec.push_back(pers);
}

void Database::vectorToFile(vector <FamousPersons> &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        readTofile(vec[i]);
    }
}

void Database::readTofile(FamousPersons &temp)
{
    ofstream out_stream;

    out_stream.open("csLeagends.txt", ios::out | ios::app);
    if (out_stream.fail())
    {
        cout << "Output file opening failed" << endl;
        exit(1);
    }
    out_stream << "First name: " << temp.getFirstName() << endl;
    out_stream << "Last name: " << temp.getLastName() << endl;
    out_stream << "Gender (male/female): " << temp.getGender() << endl;
    out_stream << "Year of birth: " << temp.getYearOfBirth() << endl;
    out_stream << "Year of death: " << temp.getYearOfDeath() << endl;
    out_stream << endl;
    out_stream.close();
}
