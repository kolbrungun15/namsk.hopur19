#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "famouspersons.h"

using namespace std;

int mainMenu();
void readToFile();
void readFromFile();


int main()
{
    int firstChoice = mainMenu();
}

int mainMenu()
{
    int choice = 0;

    cout << "--------------------FAMOUS PROGRAMMERS--------------------" << endl;
    cout << "-----------------------Main menu--------------------------" << endl;
    cout << "(1) Add to list" << endl;
    cout << "(2) Display list" << endl;
    cout << "(3) Search list" << endl;
    //cout << "(4) Edit list" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
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
