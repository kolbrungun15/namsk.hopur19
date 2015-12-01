#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "famouspersons.h"

using namespace std;

class Database {

public:
    Database(string filename);
    string dataFile;
    vector <FamousPersons> vec;
    void add(FamousPersons pers);
    void vectorToFile(vector <FamousPersons> &vec);
    void readTofile(FamousPersons &temp);
private:

};

#endif // DATABASE_H
