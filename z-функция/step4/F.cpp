// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z(string str1) {
	vector<int> z(str1.length());
	vector<int> mass(str1.length());
	int n = str1.length();
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && str1[z[i]] == str1[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void printZ(vector<int> z) {
	for (int i = 0; i < z.size(); i++) {
		std::cout << z[i] << " ";
	}
	std::cout << "\n";
}
pair<int,int> findMax(vector<int> z, string skip) {
	int max = 0;
	int max_index = -1;
	pair<int, int> max_pair;
	max_pair.first = max;
	max_pair.second = max_index;
	for (int i = skip.length() + 1; i < z.size(); i++) {
		if (z[i] >= z.size() - i  && z[i]>max) {
			max = z[i];
			max_index = i-skip.length();
			max_pair.first = max;
			max_pair.second = max_index;
		}
	}
	return max_pair;
}

//for
//codeforces

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	int count;
	std::cin >> count;
	for (int i = 0; i < count; i++) {
		string str1, str2;
		std::cin >> str1 >> str2;
		vector<int> z1=z(str1+"#"+str2);
		bool b = true;
		for (int i = str1.length() + 1; i < z1.size(); i++) {
			if (z1[i] == str1.length()) {
				std::cout << str2;
				b = false;
				break;
			}
		}
		pair<int, int> first_pair = findMax(z1, str1);
		//std::cout << str1 + "#" + str2 <<"\n";
		//printZ(z1);
		z1 = z(str2 + "#" + str1);
		for (int i = str2.length() + 1; i < z1.size() && b; i++) {
			if (z1[i] == str2.length()) {
				std::cout << str1;
				b = false;
				break;
			}
		}
		
		pair<int, int> second_pair = findMax(z1, str2);
		//std::cout << str2 + "#" + str1 <<"\n";
		//printZ(z1);

		if (b) {
			if (first_pair.first > second_pair.first) {
				std::cout << str2.substr(0, first_pair.second - 1) + str1;
			}
			else if (first_pair.first < second_pair.first) {
				std::cout << str1.substr(0, second_pair.second - 1) + str2;
			}
			else if (first_pair.first == second_pair.first && first_pair.first != 0) {
				std::cout << str1.substr(0, second_pair.second - 1) + str2;
			}
			//eq=0
			else {
				std::cout << str2 + str1;
			}
		}
		std::cout << "\n";
	}
}
