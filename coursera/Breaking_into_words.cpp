#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {

	string test = s;
	vector<string> result;
	while (true) {
		auto iter = find(test.begin(), test.end(), ' ');

		if (iter == test.end())
			break;

		result.push_back(test.substr(0, distance(test.begin(), iter)));
		test.erase(0, distance(test.begin(), iter)+1);
	}

	result.push_back(test);
	return result;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl; // 4 Ñ/Cpp/Java/Python

	return 0;
}