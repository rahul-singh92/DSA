#include <iostream>
using namespace std;

bool bru_way(string& s, int i, int open)
{
    if(open < 0) return false;

    // If we reach the end then check if open are zero
    if(i == s.length()) return open == 0;

    if(s[i] == '(') return bru_way(s, i + 1, open + 1);

    else if(s[i] == ')') return bru_way(s, i + 1, open - 1);
    
    else
    {
        return bru_way(s, i + 1, open) ||
               bru_way(s, i + 1, open + 1) ||
               bru_way(s, i + 1, open - 1);
    }
}

bool op_way(string s)
{
    int minOpen = 0, maxOpen = 0;

    for(auto c: s)
    {
        if(c == '(')
        {
            minOpen++;
            maxOpen++;
        }
        else if(c == ')')
        {
            minOpen--;
            maxOpen--;
        }
        else
        {
            minOpen--;
            maxOpen++;
        }

        if(maxOpen < 0) return false;

        minOpen = max(minOpen, 0);
    }

    return minOpen == 0;
}

int main()
{
    string s;
    cin>>s;

    // bool ans = bru_way(s, 0, 0);
    bool ans = op_way(s);

    cout<<ans<<endl;
}