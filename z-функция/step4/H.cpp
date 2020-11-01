// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> zFunction(string s) {
	vector<int> z(s.length()+1);
	vector<int> mass(s.length());
	int n = s.length();
	int max = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}

		if (z[i] > max) {
			max = z[i];
		}
	}
	z[s.length()] = max;
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
	long long summ_of_lengths = 0;
	string t = "";
	for (int i = str.size()-1; i >=0; i--) {
		t = str[i]+t;
		//std::cout << t;
		vector<int> z = zFunction(t);
		for (int j = z[z.size() - 1]; j < z.size() - 1; j++) {
			summ_of_lengths += j+1;
		}
		//prinArray(z);
	}
	std::cout << summ_of_lengths;
}
//aabaab
//b a
// ab ba aa
// aab baa aba
//aaba abaa baab
//aabaa abaab
//aabaab
//45+

//ababab
// a b -2
// ab ba - 4
// aba bab - 6
// abab baba - 8
// ababa babab - 10
// ababab-6 
//36 +
