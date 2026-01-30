#include <iostream>
using namespace std;

//Convert To Binary
string convertToBinary(int n)
{
    string ans = "";
    while(n > 0)
    {
        if(n % 2 == 0)ans += '0';
        else ans += '1';
        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Convert to integer
int convertToInt(string s)
{
    int n = 0;
    for(int i = 0; i < s.size(); i++)
    {
        n += ((s[i] - '0') * (1 << (s.size() - i - 1)));
    }
    return n;
}

int main()
{
    int n = 7;
    string s = convertToBinary(n);
    cout<<s<<endl;
    int a = convertToInt(s);
    cout<<a<<endl;
    cout<<(13 & 7)<<endl;
    cout<<(13 | 7)<<endl;
    cout<<(13 >> 1) <<endl;
    cout<<(13 << 1) <<endl;
    cout<<(~6)<<endl;
}