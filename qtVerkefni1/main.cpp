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


int mainMenu();
bool whatToDo(int choice, vector<FamousPersons> &vec);
int displayListMenu();
void display(vector <FamousPersons> &vec);
void Alphabetically();
void Chronologically();

int searchMenu();
void searchList(vector <FamousPersons> &vec);

bool addToList(vector<FamousPersons> &vec);
void newReadTofile(FamousPersons &temp);
void readToFile(vector <FamousPersons> &vec);
void readFromFile(vector <FamousPersons> &vec);
bool whatToDo(int choice, vector<FamousPersons> &vec);
int howManyPersons();
bool doYouWantToContinue(); //Spyr hvort notandi vilji halda áfram
void readFromFile();
bool doYouWantToContinue();


//---------------------------------------------------------------------------------------------------
//------------------------------------------( Main Function )----------------------------------------
//---------------------------------------------------------------------------------------------------

int main()
{
    bool runWhileTrue = true;
    vector<FamousPersons> vec;

    readFromFile(vec);

    while(runWhileTrue){
        int firstChoice = mainMenu();
        runWhileTrue = whatToDo(firstChoice, vec);
    }
}


//---------------------------------------------------------------------------------------------------
//------------------------------------------( Menu Functions )---------------------------------------
//---------------------------------------------------------------------------------------------------


int mainMenu()
{

    int choice = 0;

    cout << "--------------------FAMOUS PROGRAMMERS--------------------" << endl;
    cout << "------------------------Main menu-------------------------" << endl;
    cout << "(1) Add to list" << endl;
    cout << "(2) Display list" << endl;
    cout << "(3) Search list" << endl;
    cout << "(4) Save list" << endl;
    cout << "(5) Quit" << endl;
    cout << "Enter your choice: " << endl;

    cin >> choice;

    return choice;
}

bool whatToDo(int choice, vector<FamousPersons> &vec)
{
    bool result = true;
    bool continueProgram;
    switch(choice)
    {

        case 1:

            while(result)
            {
                result = addToList(vec); //Bætir við frægri manneskju við listann
            }
            break;

        case 2:
            displayListMenu();  //spyr notanda hvernig hann vill raða listanum.
            /* * kallar á fall sem prentar út listann í þeirri röð sem
             * notandi valdi. */
            break;

        case 3:
            searchList(vec);
            /* Hér kemur fall sem leitar að streng í listanum.
             * Prentar út mannsekju ef hún er fundin.*/
            break;

        case 4:

            break;

        case 5:

            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }
    continueProgram = doYouWantToContinue();
    return continueProgram;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------( Display Functions )------------------------------------
//---------------------------------------------------------------------------------------------------


int displayListMenu()
{
    int choice = 0;

    cout << endl;
    cout << "---------- Display Menu -----------" << endl;
    cout << "How would you like to organize the list?" << endl;
    cout << "(1) Alphabetical" << endl;
    cout << "(2) Chronologically" << endl;
    cout << "(3) By Gender" << endl;
    cout << "(4) Do you want to continue organizing or go back to main menu?" << endl;
    cout << "Enter your choice: " << endl;

    cin >> choice;

    return choice;
}

void display(vector <FamousPersons> &vec){

    int choice = displayListMenu();

    switch(choice)
    {

        case 1:
            //Vantar að klára!
            Alphabetically();

            break;

        case 2:
            //Vantar að klára!
            Chronologically();

            break;

        case 3:
            //Vantar að klára!


            break;

        case 4:
            //Vantar að klára!
            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }

}

void Alphabetically()
{
    int choice = 0;

    cout << "Do you want to sort the names by their.." << endl;
    cout << "(1) first name?" << endl;
    cout << "(2) last name?" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            //Vantar að klára!
            break;
        case 2:
            //Vantar að klára!
            break;
        default:
            cout << "Not a valid choice!" << endl;
            break;
    }

}

void Chronologically()
{
    int choice = 0;

    cout << "Do you want to sort the persons by their.." << endl;
    cout << "(1) Date of birth?" << endl;
    cout << "(2) Date of death?" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            //Vantar að klára!
            break;

        case 2:
            //Vantar að klára!
            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }

}

//---------------------------------------------------------------------------------------------------
//------------------------------------------( Search Functions )-------------------------------------
//---------------------------------------------------------------------------------------------------

                            //Vantar að klára ALLAN ÞENNAN HLUTA! hálfklárað semsagt!
int searchMenu(){

    int choice = 0;

    cout << endl;
    cout << "----------- Search Menu -----------" << endl;
    cout << "(1) Do you want to search by First name?" << endl;
    cout << "(2) ... Last name?" << endl;
    cout << "(3) ... gender?" << endl;
    cout << "(4) ... year of birth?" << endl;
    cout << "(5) ... year of death?" << endl;
    cout << "(6) Do you want to go back to main menu or continue searching?" << endl;
    cout << endl;

    cin >> choice;

    return choice;
}

void searchList(vector <FamousPersons> &vec)
{

    //vec =

    string searchWord = " ";

    int choice = searchMenu();

    cout << "Please type the word you want to search!" << endl;
    cin >> searchWord;

    switch(choice)
    {

        case 1:

            cout << "for hingad" << endl;

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string Var = vec[i].getFirstName();

                unsigned int pos = 0;

                int j = 0;
                cout << j << endl;
                j++;

                pos = searchWord.find(Var);

                if (pos > 0)
                {
                    cout << vec[i] << endl;
                }
                else if (pos == 0)
                {
                    cout << "Search was not successful!" << endl;
                }
            }

            break;

        case 2:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getLastName();
                if (searchWord == var)
                {
                    cout << vec[i] << endl;
                }
                else
                {
                    cout << "Search was not successful!" << endl;
                }
            }

            break;

        case 3:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getGender();
                if (searchWord == var)
                {
                    cout << vec[i] << endl;
                }
                else
                {
                    cout << "Search was not successful!" << endl;
                }
            }

            break;
        case 4:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getYearOfBirth();
                if (searchWord == var)
                {
                    cout << vec[i] << endl;
                }
                else
                {
                    cout << "Search was not successful!" << endl;
                }
            }

            break;
        case 5:

            for (unsigned int i = 0; i < vec.size(); i++)
            {
                string var = vec[i].getYearOfDeath();
                if (searchWord == var)
                {
                    cout << vec[i] << endl;
                }
                else
                {
                    cout << "Search was not successful!" << endl;
                }
            }

            break;

        default:
            cout << "Not a valid choice!";
            break;
    }

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

    FamousPersons temp(firstName, lastName, gender, yearOfBirth, yearOfDeath);
    vec.push_back(temp);
    readToFile(vec);

    char continueYN = 'k';
    cout << "Do you want to input another person(y/n)? ";
    cin >> continueYN;
    if(continueYN == 'y'){
        return true;
    }
    else{
        return false;
    }
}

void newReadTofile(FamousPersons &temp)
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


void readToFile(vector <FamousPersons> &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        newReadTofile(vec[i]);
    }
}

void readFromFile(vector <FamousPersons> &vec)//þetta skjal skrifar ut a skja, thad tharf bara ad laga til, t.d. 'word'
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
            if(line[i] == ','){
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
        cout << temp;
        vec.push_back(temp);
    }
    in_stream.close();
}

bool doYouWantToContinue(){
    char continueProgram = 'y';
    cout << "Do you want to continue(y/n)? ";
    cin >> continueProgram;
    if(continueProgram == 'y'){
        return true;
    }
    else{
        return false;
    }
}
