#ifndef string_functions_hpp
#define string_functions_hpp

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string strToSplit, char delimeter);
size_t levenshtein_distance(const string &s1, const string &s2); 

// trim whitespace functions
void trimLeading(string& str);
void trimTrailing(string& str);
void trim(string& str);

#endif /* string_functions_hpp */