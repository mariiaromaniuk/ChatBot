/* 
  main.cpp
  Chatbot Application in C++

  Created by Mariia Romaniuk

  Chatbots are typically used in dialog systems for various practical purposes including customer service or 
  information acquisition. Chatbot application in C++ interact with user in simple English language and can 
  simulate a conversation. It has a repository or database of facts and rules, which are searched to give the 
  best possible response.
*/

#include "record.hpp"
#include "string_functions.hpp"
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> readLinesIntoArr(ifstream &file){
		string line;
		vector<string> fileLines;

		while(getline(file, line)){
				fileLines.push_back(line);
		}
		return fileLines;
}

vector<Record> getRecords(string fileName){
		const string phraseTag = "<phrase>";
		const string respTag = "<response>";
		vector<Record> records;
		vector<string> rawFile; 
		vector<string> splitString; 
		string line;
		char delim = '>';
		ifstream file("records.txt");
		rawFile = readLinesIntoArr(file);
		Record *curRec;

		for(int i = 0;i < rawFile.size();i++){
				line = rawFile[i];
				if(line.find(phraseTag) != string::npos){ // if this line defines a phrase
						Record tempRec;
						splitString = split(line, delim);
						tempRec.phrase = splitString[1];
						trim(tempRec.phrase);
						records.push_back(tempRec);
						curRec = &records[records.size()-1];
				} 
        else if (line.find(respTag) != string::npos) {
						splitString = split(line, delim);
						trim(splitString[1]);
						curRec->responses.push_back(splitString[1]);
				}
		}
		return records;
}

string getResponse(string input, vector<Record> records){
		string response;
		vector<string> words = split(input, ' ');
		int total = levenshtein_distance(input, records[0].phrase);
		int index = 0;

		// go through each response and each word in the smalles levenshtien distance
		for (int i = 1; i < records.size(); i++){
				int tempTotal = levenshtein_distance(input, records[i].phrase);

				if (tempTotal <= total) {
						total = tempTotal;
						index = i;
				}
		}

		int randIndex = rand() % records[index].responses.size();
		response = records[index].responses[randIndex];

		return response;
}
 

int main() {

		string sInput = "";
		string sResponse = "";
		ifstream myFile("records.txt");
		vector<Record> records;
		records = getRecords("records.txt");

		while(1){
				cout << ">";
				getline(cin, sInput);
				if (sInput == "q") break;
				sResponse = getResponse(sInput, records);
				cout << sResponse << endl;
		}

		return 0;
}
