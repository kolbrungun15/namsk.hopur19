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
void display(int choice, vector <FamousPersons> &vec);
void Alphabetically(vector <FamousPersons> &vec);
void Chronologically(vector <FamousPersons> &vec);
void displayList(vector <FamousPersons> &vec);

int searchMenu();
void searchList(vector <FamousPersons> &vec);

bool addToList(vector<FamousPersons> &vec);
void readToFile(FamousPersons &temp);
void readFromFile(vector <FamousPersons> &vec);
int howManyPersons();
bool doYouWantToContinue();


//---------------------------------------------------------------------------------------------------
//------------------------------------------( Main Function )----------------------------------------
//---------------------------------------------------------------------------------------------------

int main()
{
    bool runWhileTrue = true;
    vector<FamousPersons> PersonVector;
    
    readFromFile(PersonVector);

    while(runWhileTrue){
        int firstChoice = mainMenu();
        runWhileTrue = whatToDo(firstChoice, PersonVector);
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
    cout << "(4) Quit" << endl;
    cout << "Enter your choice: " << endl;

    cin >> choice;

    return choice;
}

bool whatToDo(int choice, vector<FamousPersons> &vec)
{
    int c = 0;
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
            c = displayListMenu();
            display(c, vec);        //spyr notanda hvernig hann vill raða listanum.
            break;

        case 3:
            searchList(vec);    // Hér kemur fall sem leitar að streng í listanum. Prentar út mannsekju ef hún er fundin.
            break;

        case 4:
            exit(1);
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
    cout << "(1) View as is" << endl;
    cout << "(2) Alphabetical" << endl;
    cout << "(3) Chronologically" << endl;
    cout << "(4) By Gender" << endl;
    cout << "(5) Back to main menu" << endl;
    cout << "Enter your choice: " << endl;

    cin >> choice;

    return choice;
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

            Chronologically(vec);

            break;

        case 4:



            break;

        case 5:
            mainMenu();
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
    cout << "(3) Back to main menu" << endl;
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

        case 3:
            mainMenu();
            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }

    displayListMenu();

}

void Chronologically()
{
    int choice = 0;

    cout << "Do you want to sort the persons by their.." << endl;
    cout << "(1) Date of birth?" << endl;
    cout << "(2) Date of death?" << endl;
    cout << "(3) Back to main menu" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:

            for (unsigned int i = 0; i < vec.size(); i++)
            {

            }

            break;

        case 2:

            break;

        case 3:
            mainMenu();
            break;

        default:
            cout << "Not a valid choice!" << endl;
            break;
    }

    displayListMenu();

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
    cout << "(6) Back to main menu" << endl;
    cout << endl;

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
            mainMenu();
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

    FamousPersons temp(firstName, lastName, gender, yearOfBirth, yearOfDeath);
    readToFile(temp);

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


/*void readToFile(vector <FamousPersons> &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        newReadTofile(vec[i]);
    }
}*/

void readFromFile(vector <FamousPersons> &vec) //Þetta fall skrifar skránna inn í vector
{

    ifstream in_stream("csLeagends.txt"); //Opnar strím á skránna
    //Breytur
    string line;
    string word;


    if (in_stream.fail())//Ef klúðrast að opna skránna þá skrifast út villuskilaboð
    {
        cout << "Input file opening failed" << endl;
        exit(1);
    }
    while(in_stream >> line)
    {
        //Breytur inní while lykkjunni
        FamousPersons temp;
        int commaCounter = 0;

        for(unsigned int i = 0; i < line.length(); i++){     //Forlykkja sem rúllar í gegnum strenginn line
            if(line[i] == ',' || line[i] == '.'){   //Ef það kemur punktur eða komma fer orðið á undan inní viðeigandi breytu
                if(commaCounter == 0){  //til dæmis fer orðið á undan fyrstu kommunni inní firstName breytuna temp í klasanum o.s.frv
                     temp.setFirstName(word);   //Skrifar strengin word í first name breytuna í klasanum
                     commaCounter++;    //Hækkar kommu teljarann til að komast inn í næstu if setningu
                     word = "";     //Núllstillir strenginn word
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
            else{ //Ef stafurinn er eitthvða annað en . eða , þá skrifast sá stafur inní strenginn word
                word += line[i];
            }
        }
        cout << temp;
        vec.push_back(temp); //Eftir að búið er að setja línuna í viðeigandi breytur í temp, er því bætt við aftast í vectorinn
        vec.push_back(temp);
    }
    in_stream.close(); //Straumnum er síðan lokað í lokin
}

bool doYouWantToContinue() {  //Spurning að reyna að setja þetta framar í forritið
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
