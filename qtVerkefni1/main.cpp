#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "famouspersons.h"

using namespace std;

void readToFile();
void readFromFile();

int main() {

    int nr;
    string a, b, c, d;

    cout << "----------" << "Famous Programming Persons" << "----------" << endl;
    cout << "The program lets you document the name, gender, date of birth and date of death of a person" << endl;

    cout << "How many persons do you want to document:";

    cin >> nr;

    for (int i = 0; i <= nr; i++){

        cout << "First write the name of the person:" << endl;

        cin >> a;

        cout << "Now write the gender:" << endl;

        cin >> b;

        cout << "Then the date of birth:" << endl;

        cin >> c;

        cout << "and at last write the date of death (if he/she is deceased):" << endl;
        //Þarf að búa til lykkju í kringum ef hann er lifandi!
        cin >> d;
    }


}

void readToFile()
{
    ofstream out_stream;
    string word;

    out_stream.open("outfile.txt");
    if (out_stream.fail())
    {
        cout << "Output file opening failed" << endl;
        exit(1);
    }
    while(out_stream)
    {
        out_stream << word << " ";
    }
    out_stream.close();
}

void readFromFile()
{
    ifstream in_stream("infile.txt");
    string word;

    if (in_stream.fail())
    {
        cout << "Input file opening failed" << endl;
        exit(1);
    }
    while(in_stream >> word)
    {
        cout << word << " ";
    }
    in_stream.close();
}
