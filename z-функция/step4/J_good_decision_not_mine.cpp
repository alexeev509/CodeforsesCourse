
#include <iostream>
#include <string>
using namespace std;
 
int len, r, l, z[2000000], pos{1};
string s;
 
int main()
{
    cin >> s;
    len = s.length();
    s.append(s);
    for (int i = 1; i < len; ++i)
    {
        if (i < r)
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] > r)
            l = i, r = i + z[i];
        if (i + z[i] < s.length() && s[z[i]] > s[i + z[i]])
            ++pos;
    }
    cout << pos << endl;
}

// i don't understand how to proof this fact: s[z[i]] > s[i + z[i]] ??

//- Underdtood :)
