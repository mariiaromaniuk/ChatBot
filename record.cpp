#include "record.hpp"

void Record::printRecord() {
		cout << "Phrase: " << phrase << endl;
		cout << "Responses: " << endl;
		for (int i = 0; i < responses.size(); i++) {
				cout << '\t' << responses.at(i) << endl;
		}
}