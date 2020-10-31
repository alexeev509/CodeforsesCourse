#include <iostream>
#include <string>
using namespace std;
 
int z[2000001];
char s1[1000001], s2[1000001];
 
void z_function(string &s, int *z, int n) 
{
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = 0;
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (z[i] + i < n && s[z[i] + i] == s[z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}
 
string combine(string a, string b) 
{
	int na = a.size();
	int nb = b.size();
	string s = b + '$' + a;
	z_function(s, z, na + nb + 1);
	int common = 0;
	for (int i = nb + 1; i < na + nb + 1 && !common; ++i) {
		if (z[i] == nb) return a;
		if (i + z[i] == na + nb + 1) common = z[i];
	}
	return a + b.substr(common, nb - common);
}
 
string minstr(string a, string b) 
{
	return a.size() < b.size() ? a : b;
}
 
int main() 
{
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%s", s1, s2);
		printf("%s\n", minstr(combine(s1, s2), combine(s2, s1)).c_str());
	}
}
