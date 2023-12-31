//Created by Mario O Salinas on 9/11/23.
//Team 3: Abia Khan and Mario Salinas
//NetID: ac6212 and ry7931 
//CS 301-03 
//9/11/23 

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "UnsortedLinkedList.h"
#include "ItemType.h"

using namespace std;

void PrintList(ofstream& outFile, UnsortedLinkedList& list);

int main() {
    int repeatCode;
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

    if (!inputFile.good()) {
        cout << "I/O error. Can't find the input file! \n";
        exit(2);
    }
    inputFile >> command;

    numCommands = 0;
   do {
       cout << "Enter the name of the test run: ";
       cin >> command;
       outputFile << testRunName << endl;

       if (command == "PutItem") {
           inputFile >> number;
           item.Initialize(number);
           list.PutItem(item);
           item.Print(outputFile);
           outputFile << " is in list" << endl;
       } else if (command == "DeleteItem") {
           inputFile >> number;
           item.Initialize(number);
           list.DeleteItem(item);
           item.Print(outputFile);
           outputFile << " is deleted" << endl;
       } else if (command == "GetItem") {
           inputFile >> number;
           item.Initialize(number);
           item = list.GetItem(item, found);
           item.Print(outputFile);
           if (found)
               outputFile << " found in list." << endl;
           else
               outputFile << " not in list." << endl;
       } else if (command == "GetLength") {
           outputFile << "Length is " << list.GetLength() << endl;
       } else if (command == "IsFull") {
           if (list.IsFull())
               outputFile << "List is full." << endl;
           else outputFile << "List is not full." << endl;
       } else if (command == "MakeEmpty") {
           list.MakeEmpty();
       } else if (command == "PrintList") {
           PrintList(outputFile, list);
           if (list.GetLength() == 0) {
               outputFile << "List is empty" << endl;
           }
       } else
           cout << command << " is not a valid command." << endl;
       numCommands++;
       cout << " Command number " << numCommands << " completed."
            << endl;
       inputFile >> command;


       cout << "Press 1 to run a different test. Press 0 to exit the program: ";
       cin >> repeatCode;
   } while (repeatCode != 0);

    cout << "Testing completed."  << endl;
    inputFile.close();
    cout << inputFileName << " closed" << endl;
    outputFile.close();
    cout << outputFileName << " closed" << endl;

    return 0;
}

void PrintList(ofstream& dataFile, UnsortedLinkedList& list) {
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
