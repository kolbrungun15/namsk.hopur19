#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return 0;
}

void readToFile()
{
    ifstream in_stream("infile.txt");
    string word;

    if (in_stream.fail())
    {
        cout << "Output file opening failed" << endl;
        exit(1);
    }
    while(in_stream >> word)
    {
        cout << word << " ";
    }
    in_stream.close();
}


