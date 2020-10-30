// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void z(string str1, string str2) {

	if (str1.length() != str2.length()) {
		std::cout << "No";
	}
	else
	{
		//reverse(p.begin(), p.end());
		string p = str2 + '$' + str1;
		vector<int> z(p.size());

		int l = 0, r = 0, n = p.size();
		//std::cout << z[0] << " ";
		for (int i = 1; i < n; i++) {
			if (r >= i)
				z[i] = min(z[i - l], r - i + 1);
			while (i + z[i] < n && p[z[i]] == p[i + z[i]])
				z[i]++;
			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
			//std::cout << z[i] << " ";
		}
		int answer = 0;
		int index = -1;
		for (int i = str1.length() + 1, q=0; i < z.size(); i++,q++) {
			if (z[i] != 0 && z[i]>=n-i) {
				answer = z[i];
				index = i;
				break;
			}
		}
		if (answer != 0) {
			for (int i = str1.length() + 1, q = str1.length() - 1; i < index; i++, q--) {
				if (p[i] != p[q]) {
					answer = 0;
					break;
				}
			}
		}
		if (answer == 0) {
			std::cout << "No";
		}
		else {
			std::cout << "Yes\n";
			std::cout << str1.length()-answer;
		}
	}

}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	string str1;
	std::cin >> str1;
	string str2;
	std::cin >> str2;
	z(str1,str2);
}
