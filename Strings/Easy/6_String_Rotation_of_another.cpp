#include <iostream>
#include <string>
using namespace std;

bool wo_ca(string &s, string &t)
{
    if(s.size() != t.size()) return false;
    for(int i = 0; i < s.size(); i++)
    {
        string word = "";
        word = s.substr(i) + s.substr(0, i);
        if(word == t) return true;
    }
    return false;
}

bool op_ca(string &s, string &t)
{
    if(s.size() != t.size()) return false;

    string doubledS = s + s;
    return doubledS.find(t) != string::npos;
}

int main()
{
    string s, t;
    cin>>s>>t;
    bool ans = wo_ca(s, t);
    cout<<((ans == true) ? "True" : "False")<<endl;
}