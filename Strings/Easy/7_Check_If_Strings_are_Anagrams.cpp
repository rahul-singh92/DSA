#include <iostream>
#include <string>
using namespace std;

// bool wo_ca(string s, string t)
// {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     if(s == t) return true;
//     return false;
// }

bool op_ca(string s, string t)
{
    if(s.size() != t.size()) return false;

    int freq[26] = {0};

    for(int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;

    for(int i = 0; i < t.size(); i++) freq[t[i] - 'A']--;

    for(int i = 0; i < 26; i++) if(freq[i] != 0) return false;

    return true;
}

int main()
{
    string s, t;
    cin>>s>>t;
    bool ans = op_ca(s, t);
    cout<<((ans == true) ? "true" : "false")<<endl;
}