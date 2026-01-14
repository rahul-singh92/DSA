#include <iostream>
#include <string>
using namespace std;

int op_ca(string s)
{
    long int num = 0;
    int i = 0;
    int sign = 1;
    while(i < s.size() && s[i] == ' ') i++;
    if(i == s.size()) return 0;
    
    if(s[i] == '-')
    {
        sign = 0;
        i++;
    } 
    else if(s[i] == '+') i++;

    for(int i = 0; i < s.size(); i++)
    {
        // Clamp to INT_MAX if overflow occurs
        if (sign * num > INT_MAX) return INT_MAX;
        // Clamp to INT_MIN if underflow occurs
        if (sign * num < INT_MIN) return INT_MIN;

        if(s[i] - '0' < 10 && s[i] - '0' >= 0) num = num * 10 + (s[i] - '0') ;
        else break;
    }
    return (int)(sign * num);
}

int main()
{
    string s;
    getline(cin, s);
    int ans = op_ca(s);
    cout<<ans<<endl;
}