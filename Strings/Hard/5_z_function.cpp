#include <iostream>
using namespace std;

vector<int> calculateZ(const string& s)
{
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    string s = "abacaba";
    vector<int> ans = calculateZ(s);
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}