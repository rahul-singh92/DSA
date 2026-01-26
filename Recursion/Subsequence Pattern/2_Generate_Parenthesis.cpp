#include <iostream>
using namespace std;

void backtrack(string s, int open, int close, int n, vector<string>& result)
{
    if(s.size() == 2 * n)
    {
        result.push_back(s);
        return;
    }

    if(open < n) backtrack(s + "(", open + 1, close, n, result);
    if(close < open) backtrack(s + ")", open, close + 1, n, result);
}

void generate(int n, vector<string>& result)
{
    backtrack("", 0, 0, n, result);
}

int main()
{
    int n = 3;
    vector<string> result;

    generate(n, result);

    for(auto i : result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}