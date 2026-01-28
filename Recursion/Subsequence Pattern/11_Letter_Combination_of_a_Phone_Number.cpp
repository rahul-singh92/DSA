#include <iostream>
using namespace std;

void findAll(int ind, string digits, string s, vector<string>& ans, string combos[])
{
    if(ind == digits.size())
    {
        ans.push_back(s);
        return;
    }

    //Convert each digit into integers
    int digit = digits[ind] - '0';

    //Loop through the corresponding character
    for(int i = 0; i < combos[digit].size(); i++)
    {
        //Recursively call next index
        //Add current character to string
        findAll(ind + 1, digits, s + combos[digit][i], ans, combos);
    }
}

vector<string> opt_way(string digits)
{
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string s = "";

    findAll(0, digits, s, ans, combos);

    return ans;
}

int main()
{
    string digits = "23";
    vector<string> result = opt_way(digits);

    for(auto i : result) cout<<i<<" ";
    cout<<endl;
}