#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
#include <vector>
using namespace std;

vector<unsigned int> PrefixFunction(const string & s);
vector<unsigned int> KMPWeak(const string & pattern, const string & text);

vector<unsigned int> ZFunction(const string & s);
vector<unsigned int> StrongPrefixFunction(const string & s);
vector<unsigned int> KMPStrong(const string & pattern, const string & text);

#endif /* SEARCH_HPP */