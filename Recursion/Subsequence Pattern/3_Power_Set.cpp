#include <iostream>
using namespace std;

void getSubsequence(string& s, int index, string current, vector<string>& result)
{
    if(index == s.size())
    {
        result.push_back(current);
        return;
    }

    getSubsequence(s, index + 1, current, result);

    current.push_back(s[index]);
    getSubsequence(s, index + 1, current, result);

    current.pop_back();
}

int main()
{
    string s ="abc";
    vector<string> result;

    getSubsequence(s, 0, "", result);

    for(auto i: result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}