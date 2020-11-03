#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z(string s) {
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
	}
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
	string str, pattern;
	int k;
	std::cin >> str >> pattern >> k;
	vector<int> currentZ1=z(pattern + "#" + str);
	string str2 = str;
	//print
	//std::cout << pattern + "#" + str<<"\n";
	//prinArray(currentZ1);
	//
	reverse(pattern.begin(), pattern.end());
	reverse(str.begin(), str.end());
	vector<int> currentZ2 = z(pattern + "#" + str);
	//print
	//std::cout << pattern + "#" + str<<"\n";
	//prinArray(currentZ2);
	//
	vector<int> answer(str.length());
	int q = 0;
	for (int i = pattern.length() + 1; i <= currentZ1.size()- pattern.length(); i++) {
			int a = currentZ1[i];
			int b = currentZ2[pattern.length()+1+str.length() - i + 1];
			if (a + b >= ((int)pattern.length()) - k)  {
				answer[q++] = i - pattern.length();
			}
	}
		std::cout << q << "\n";
		for (int i = 0; i < q; i++) {
			std::cout << answer[i] << " ";
		}

}




//I had mistake before
//uint -int =uint 
//pattern.length()) - k

//str=abc
//pattern=a
//k=1000
