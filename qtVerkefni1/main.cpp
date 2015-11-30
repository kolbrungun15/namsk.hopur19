#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <list>
#include "famouspersons.h"

using namespace std;

int mainMenu();
void addToList(); //Hérna er breyting
int displayListMenu();
void newReadTofile(FamousPersons &temp);
void searchList();
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
    cout << "------------------------Main menu-------------------------" << endl;
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
            break;
        case 2:
            displayListMenu();  //spyr notanda hvernig hann vill raða listanum.
             /* * kallar á fall sem prentar út listann í þeirri röð sem
             * notandi valdi. */
            break;
        case 3:
            searchList();
            readFromFile();
            /* Hér kemur fall sem leitar að streng í listanum.
             * Prentar út mannsekju ef hún er fundin.*/
            break;
        default:
            cout << "Not a valid choice!";
            break;

    }
}

void addToList()
{

    string firstName = " ", lastName = " ", gender = " ", yearOfBirth = " ", yearOfDeath = " ";

    cout << "Now add a person to the list:" << endl;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter year of birth: ";
    cin >> yearOfBirth;
    cout << "Enter year of death: ";
    cin >> yearOfDeath;

    FamousPersons temp(firstName, lastName, gender, yearOfBirth, yearOfDeath);
    newReadTofile(temp);
    list <FamousPersons> lis; //ath listinn aetti kannski ad vera annarstadar...
    lis.push_back(temp);
}

void newReadTofile(FamousPersons &temp)
{
    ofstream out_stream;

    out_stream.open("csLeagends.txt");
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
    out_stream.close();
}

int displayListMenu()
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

void searchList()
{
    //tharf ad utfaera
}

/*void readToFile()
{
    ofstream out_stream;
    string word;

    out_stream.open("csLeagends.txt");
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
*/
void readFromFile()
{
    ifstream in_stream("csLeagends.txt");
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

