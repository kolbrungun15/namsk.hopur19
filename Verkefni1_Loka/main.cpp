#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "famouspersons.h"

using namespace std;

//---------------------------------------------------------------------------------------------------
//-----------------------------------------( Function List )-----------------------------------------
//---------------------------------------------------------------------------------------------------


void mainMenu(vector<FamousPersons> &PersonVector);
void whatToDo(int choice, vector<FamousPersons> &vec);

void displayListMenu(vector <FamousPersons> &vec);
void display(int choice, vector <FamousPersons> &vec);
void Alphabetically(vector <FamousPersons> &vec);
void Chronologically(vector <FamousPersons> &vec);
void Gender(vector <FamousPersons> &vec);
void displayList(vector <FamousPersons> &vec);

int searchMenu();
void searchList(vector <FamousPersons> &vec);

bool addToList(vector<FamousPersons> &vec);
void readToFile(FamousPersons &temp);
void readFromFile(vector <FamousPersons> &vec);
int howManyPersons();


//---------------------------------------------------------------------------------------------------
//------------------------------------------( Main Function )----------------------------------------
//---------------------------------------------------------------------------------------------------


int main()
{
    vector<FamousPersons> PersonVector;

    readFromFile(PersonVector);

    mainMenu(PersonVector);

}


//---------------------------------------------------------------------------------------------------
//------------------------------------------( Menu Functions )---------------------------------------
//---------------------------------------------------------------------------------------------------


void mainMenu(vector<FamousPersons> &vec)
{

    int choice = 0;

    cout << endl << endl;
    cout << "--------------------FAMOUS PROGRAMMERS--------------------" << endl;
    cout << "------------------------Main menu-------------------------" << endl;
    cout << "(1) Add to list" << endl;
    cout << "(2) Display list" << endl;
    cout << "(3) Search list" << endl;
    cout << "(4) Quit" << endl;
    cout << "Enter your choice: " << endl << endl;

    cin >> choice;

    whatToDo(choice, vec);
}

void whatToDo(int choice, vector<FamousPersons> &vec)
{
    int nr = 0;

    bool result = true;
    switch(choice)
    {

        case 1:

            while(result)
            {
                result = addToList(vec);
            }
            break;

        case 2:
            displayListMenu(vec);

            break;

        case 3:
            searchList(vec);

            break;

        case 4:

            exit(1);

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }
    mainMenu(vec);

}

//---------------------------------------------------------------------------------------------------
//------------------------------------------( Display Functions )------------------------------------
//---------------------------------------------------------------------------------------------------


void displayListMenu(vector <FamousPersons> &vec)
{
    int choice = 0;

    cout << endl;
    cout << "---------- Display Menu -----------" << endl;
    cout << "How would you like to organize the list?" << endl;
    cout << "(1) View as is" << endl;
    cout << "(2) Alphabetical" << endl;
    cout << "(3) By Gender" << endl;
    cout << "(4) Back to main menu" << endl;
    cout << "Enter your choice: " << endl << endl;

    cin >> choice;

    display(choice, vec);
}

void display(int choice, vector <FamousPersons> &vec){

    switch(choice)
    {
        case 1:

            displayList(vec);
            break;

        case 2:

            Alphabetically(vec);

            break;

        case 3:

            Gender(vec);

            break;

        case 4:
            mainMenu(vec);
            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }


}

void Alphabetically(vector <FamousPersons> &vec)
{
    int choice = 0;

    cout << endl;
    cout << "Do you want to sort the names by their.." << endl;
    cout << "(1) first name?" << endl;
    cout << "(2) last name?" << endl << endl;
    cin >> choice;

    FamousPersons temp;

    switch(choice)
    {
        case 1:

            for(unsigned int i = 0 ; i < vec.size(); i++)
            {
                for(unsigned int j = 0; j < (vec.size() - 1); j++)
                {
                    if (vec[j].getFirstName() > vec[j+1].getFirstName())
                    {
                        temp = vec[j];
                        vec[j] = vec[j+1];
                        vec[j+1] = temp;
                    }
                }
            }

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << endl;
            }

            break;
        case 2:

            for(unsigned int i = 0 ; i < vec.size(); i++)
            {
                for(unsigned int j = 0; j < (vec.size() - 1); j++)
                {
                    if (vec[j].getLastName() > vec[j+1].getLastName())
                    {
                        temp = vec[j];
                        vec[j] = vec[j+1];
                        vec[j+1] = temp;
                    }
                }
            }

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << endl;
            }

            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }
}

void Gender(vector <FamousPersons> &vec)
{
    int choice = 0;

    cout << endl;
    cout << "Do you want to choose" << endl;
    cout << "(1) Male" << endl;
    cout << "(2) Female" << endl << endl;
    cin >> choice;

    string s1 = "Male";
    string s2 = "Female";

    switch(choice)
    {
        case 1:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                if (s1 == vec[i].getGender())
                {
                    cout << vec[i] << endl;
                }
            }

            break;

        case 2:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                if (s2 == vec[i].getGender())
                {
                    cout << vec[i] << endl;
                }
            }

            break;
        default:
            cout << "Not a valid choise!" << endl;
            break;
    }

}

void displayList(vector <FamousPersons> &vec)
{
    for (unsigned int i = 0; i<vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

}

//---------------------------------------------------------------------------------------------------
//------------------------------------------( Search Functions )-------------------------------------
//---------------------------------------------------------------------------------------------------


int searchMenu(){

    int choice = 0;

    cout << endl;
    cout << "----------- Search Menu -----------" << endl;
    cout << "(1) Do you want to search by First name?" << endl;
    cout << "(2) ... Last name?" << endl;
    cout << "(3) ... gender?" << endl;
    cout << "(4) ... year of birth?" << endl;
    cout << "(5) ... year of death?" << endl;
    cout << "(6) Back to main menu" << endl << endl;

    cin >> choice;

    return choice;
}

void searchList(vector <FamousPersons> &vec)
{
    string searchWord = " ";

    int choice = searchMenu();

    cout << "Please type the word you want to search!" << endl;
    cin >> searchWord;

    switch(choice)
    {
        case 1:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getFirstName();

                if (var == searchWord)
                {
                    cout << "---------- Search Results ----------" << endl << endl;
                    cout << vec[i] << endl;
                }
            }

            break;

        case 2:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getLastName();
                if (searchWord == var)
                {
                    cout << "---------- Search Results ----------" << endl << endl;
                    cout << vec[i] << endl;
                }
            }

            break;

        case 3:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getGender();
                if (searchWord == var)
                {
                    cout << "---------- Search Results ----------" << endl << endl;
                    cout << vec[i] << endl;
                }
            }

            break;

        case 4:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getYearOfBirth();
                if (searchWord == var)
                {
                    cout << "---------- Search Results ----------" << endl << endl;
                    cout << vec[i] << endl;
                }
            }

            break;

        case 5:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getYearOfDeath();
                if (searchWord == var)
                {
                    cout << "---------- Search Results ----------" << endl << endl;
                    cout << vec[i] << endl;
                }
            }

            break;

        case 6:
            mainMenu(vec);
            break;

        default:
            cout << "Not a valid choice!";
            break;
    }

    searchMenu();
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------( Other Functions )--------------------------------------
//---------------------------------------------------------------------------------------------------


bool addToList(vector<FamousPersons> &vec)
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
    cout << endl << endl;

    FamousPersons temp(firstName, lastName, gender, yearOfBirth, yearOfDeath);
    vec.push_back(temp);
    readToFile(temp);

    char continueYN = 'k';
    cout << "Do you want to input another person(y/n)? ";
    cin >> continueYN;
    cout << endl;
    if(continueYN == 'y'){
        return true;
    }
    else{
        return false;
    }
}

void readToFile(FamousPersons &temp)
{
    ofstream out_stream;

    out_stream.open("csLeagends.txt", ios::out | ios::app);
    if (out_stream.fail())
    {
        cout << "Output file opening failed" << endl;
        exit(1);
    }
    out_stream << temp.getFirstName() << ","
               << temp.getLastName() << ","
               << temp.getGender() << ","
               << temp.getYearOfBirth() << ","
               << temp.getYearOfDeath() << "." << endl;
    out_stream.close();
}

void readFromFile(vector <FamousPersons> &vec)
{

    ifstream in_stream("csLeagends.txt");
    string line;
    string word;


    if (in_stream.fail())
    {
        cout << "Input file opening failed" << endl;
        exit(1);
    }
    while(in_stream >> line)
    {
        FamousPersons temp;
        int commaCounter = 0;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ',' || line[i] == '.'){
                if(commaCounter == 0){
                     temp.setFirstName(word);
                     commaCounter++;
                     word = "";
                }
                else if(commaCounter == 1){
                    temp.setLastName(word);
                    commaCounter++;
                    word = "";
                }
                else if(commaCounter == 2){
                    temp.setGender(word);
                    commaCounter++;
                    word = "";
                }
                else if(commaCounter == 3){
                    temp.setYearOfBirth(word);
                    commaCounter++;
                    word = "";
                }
                else if(commaCounter == 4){
                    temp.setYearOfDeath(word);
                    commaCounter++;
                    word = "";
                }
            }
            else{
                word += line[i];
            }
        }
        vec.push_back(temp);
    }
    in_stream.close();
}

