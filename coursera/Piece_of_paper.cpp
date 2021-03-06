#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename iter>
void print(iter iter1, const vector<int>& numbers) {

	while (iter1 != numbers.begin()) {
		--iter1;
		cout << *iter1 << " ";
	}
}

void PrintVectorPart(const vector<int>& numbers) {

	auto iter = find_if(numbers.begin(), numbers.end(), [](int i)
	{ if (i < 0)
		return true;
	return false;
	});


	if (iter == numbers.end())
		print(numbers.end(), numbers);

	else
		print(iter, numbers);

}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 }); // 8 1 6 
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 }); // 4 5 8 1 6
	cout << endl;
	return 0;
}