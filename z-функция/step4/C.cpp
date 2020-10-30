// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void z(string s) {
	vector<int> z(s.length());
	vector<int> mass(s.length());
	int n = s.length();
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
		if (z[i] > 0) {
			++mass[z[i] - 1];
		}

	}
	int counter = 1;
	for (int i = mass.size() - 1; i >= 0; i--) {
		z[i] = mass[i] + counter;
		if (mass[i] != 0) {
			counter += mass[i];
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << z[i] << " ";
	}

}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	int count;
	std::cin >> count;
	for (int i = 0; i < count; i++) {
		string str;
		std::cin >> str;
		z(str);
	}
}
