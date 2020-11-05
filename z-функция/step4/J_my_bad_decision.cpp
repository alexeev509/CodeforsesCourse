#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z(string s) {
	vector<int> z(s.length());
	
		vector<int> mass(s.length());
		int n = s.length();
		int skip = 1;
		s += s;
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}

		for (int i = 1; i < n; i++) {
			if (s[i] < s[0]) {
				skip++;
			}
			else if (z[i] != 0) {
				int r = z[i];
				while (r < z.size()) {
					if (s[r] > s[i + r]) {
						skip++;
						break;
					}
					if (s[r] < s[i + r]) {
						break;
					}
					if (z[z[i]] != 0) {
						r += z[z[i]];
					}
					else {
						r++;
					}

				}
			}
		}
		std::cout << skip << "\n";
	return z;
}

void prinArray(vector<int> z) {
	for (int i = 0; i < z.size(); i++) {
		std::cout << z[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	string str;
	std::cin >> str;
	vector<int> currentZ=z(str);
	//prinArray(currentZ);
}
