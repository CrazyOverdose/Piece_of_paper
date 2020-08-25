#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto iter = find_if(elements.begin(), elements.end(), [border](T i)
	{ if (i > border)
		return true;
	return false;
	});

	vector<T> result;
	while (iter != elements.end()) {
		result.push_back(*iter);
		++iter;
	}

	return result;
}

int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {  // 7 8
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl; // 0
	return 0;
}