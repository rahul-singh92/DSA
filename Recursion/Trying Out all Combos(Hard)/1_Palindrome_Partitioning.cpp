#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void findAll(int index,vector<vector<string>>& ans, vector<string>& ds, string s)
{
    if(index == s.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i = index; i < s.size(); i++)
    {
        if(isPalindrome(s, index, i))
        {
            //Add substring to current path
            ds.push_back(s.substr(index, i - index + 1));

            findAll(i + 1, ans, ds, s);

            ds.pop_back();
        }
    }
}

vector<vector<string>> opt_way(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;

    findAll(0, ans, ds, s);

    return ans;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = opt_way(s);

    for(auto i : ans)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}