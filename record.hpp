#ifndef record_hpp
#define record_hpp

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Record {
		public:
				string phrase;
				vector<string> responses;
				void printRecord();
};

#endif /* record_hpp */