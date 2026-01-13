#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool arr(string &s, string &t)
{
    if(s.size() != t.size()) return false;
    int m1[256] = {0}, m2[256] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        if(m1[s[i]] != m2[t[i]]) return false;

        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    string s, t;
    cin>>s>>t;
    bool ans = arr(s, t);
    cout<<((ans == true) ? "True" : "False")<<endl;
}