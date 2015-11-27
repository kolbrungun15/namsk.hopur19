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


