#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

    int nr;
    string a, b, c, d;

    cout << "----------" << "Famous Programming Persons" << "----------" << endl;
    cout << "The program lets you document the name, gender, date of birth and date of death of a person" << endl;

    cout << "How many persons do you want to document:"

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

