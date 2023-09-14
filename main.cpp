//
// Created by Mario O Salinas on 9/11/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "UnsortedLinkedList.h"
#include "ItemType.h"

using namespace std;

void PrintList(ofstream& outFile, UnsortedLinkedList& list);

int main() {
    int repeatCode = 1;
    string inputFileName, outputFileName, testRunName;
    ifstream inputFile;
    ofstream outputFile;
    string command;     // operation to be executed

    int numCommands;
    bool found;
    int number;

    UnsortedLinkedList list;
    ItemType item;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    inputFile.open(inputFileName.c_str());

    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
    outputFile.open(outputFileName.c_str());

    do {

        cout << "Enter the name of the test run: ";
        cin >> testRunName;
        outputFile << testRunName << endl;

        if (!inputFile.good()) {
            cout << "I/O error. Can't find the input file! \n";
            exit(2);
        }
        inputFile >> command;

        numCommands = 0;
        while (command != "Quit")
        {
            if (command == "PutItem")
            {
                inputFile >> number;
                item.Initialize(number);
                list.PutItem(item);
                item.Print(outputFile);
                outputFile << " is in list" << endl;
            }
            else if (command == "DeleteItem")
            {
                inputFile >> number;
                item.Initialize(number);
                list.DeleteItem(item);
                item.Print(outputFile);
                outputFile << " is deleted" << endl;
            }
            else if (command == "GetItem")
            {
                inputFile >> number;
                item.Initialize(number);
                item = list.GetItem(item, found);
                item.Print(outputFile);
                if (found)
                    outputFile << " found in list." << endl;
                else outputFile <<  " not in list."  << endl;
            }
            else if (command == "GetLength")
                outputFile << "Length is " << list.GetLength() << endl;
            else if (command == "IsFull")
                if (list.IsFull())
                    outputFile << "List is full." << endl;
                else outputFile << "List is not full."  << endl;
            else if (command == "MakeEmpty")
                list.MakeEmpty();
            else if (command == "PrintList")
                PrintList(outputFile, list);
            else
                cout << command << " is not a valid command." << endl;
            numCommands++;
            cout <<  " Command number " << numCommands << " completed."
                 << endl;
            inputFile >> command;
        };

        cout << "Testing completed."  << endl;
        inputFile.close();
        outputFile.close();
        return 0;
        cout << "Press 1 to run a different test. Press 0 to exit the program: ";
        cin >> repeatCode;
    } while (repeatCode != 0);




        return 0;
}

void PrintList(ofstream& dataFile, UnsortedLinkedList& list)
// Pre:  list has been initialized.
//       dataFile is open for writing.
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.
{
    int length;
    ItemType item;

    list.ResetList();
    length = list.GetLength();
    for (int counter = 1; counter <= length; counter++)
    {
        item = list.GetNextItem();
        item.Print(dataFile);
    }
    dataFile << endl;
}
