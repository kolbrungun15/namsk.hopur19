#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "famouspersons.h"

using namespace std;

int mainMenu();
FamousPersons addToList();
int orderMenu();
void readToFile();
void readFromFile();
void whatToDo(int choice);

int main()
{
    int firstChoice = mainMenu();
    whatToDo(firstChoice);
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

void whatToDo(int choice)
{
    switch(choice) {
        case 1:
            addToList();
        case 2:
            orderMenu();  //spyr notanda hvernig hann vill raða listanum.
             /* * kallar á fall sem prentar út listann í þeirri röð sem
             * notandi valdi. */
        case 3:
            /* Hér kemur fall sem leitar að streng í listanum.
             * Prentar út mannsekju ef hún er fundin.*/
        default:
            cout << "Not a valid choice!";

    }
}

int orderMenu()
{
    int choice = 0;

    cout << "How would you like to organize the list?" << endl;
    cout << "(1) Alphabetical" << endl;
    cout << "(2) Chornological" << endl;
    //osfrv
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

FamousPersons addToList()
{

    string name = " ", gender = " ", yearOfBirth = " ", yearOfDeath = " ";

    cout << "Now add a person to the list:" << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter year of birth: ";
    cin >> yearOfBirth;
    cout << "Enter year of death: ";
    cin >> yearOfDeath;

    FamousPersons temp(name, gender, yearOfBirth, yearOfDeath);

    return temp;

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

