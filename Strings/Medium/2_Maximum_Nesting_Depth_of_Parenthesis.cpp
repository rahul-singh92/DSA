#include <iostream>
#include <string>
using namespace std;

int my_wa(string s)
{
    int maxi = INT_MIN;
    int num = 0;
    for(char i: s)
    {
        if(i == '(') num++;
        maxi = max(maxi, num);
        if(i == ')') num--; 
    }
    return maxi;
}

int main()
{
    string s;
    getline(cin, s);
    int ans = my_wa(s);
    cout<<ans<<endl;
}