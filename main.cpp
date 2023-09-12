//
// Created by Mario O Salinas on 9/11/23.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int repeatCode = 1;
    string inputFileName, outputFileName, testRunName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << endl << "Enter the name of the output file: ";
    cin >> outputFileName;

    do {

        cout << "Enter the name of the test run: ";
        cin >> testRunName;

        // open simulation.txt
        ifstream fin;
        fin.open(inputFileName);
        if (!fin.good())
            cout << "I/O error. Can't find the input file! \n";

        while (fin.good()) {
            // read the line
            int line;

            // getline(fin, line);
        }

        cout << "Press 1 to run a different test. Press 0 to exit the program: ";
        cin >> repeatCode;
    } while (repeatCode != 0);




        return 0;
}
