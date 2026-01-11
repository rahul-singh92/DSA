#include <iostream>
#include <string>
using namespace std;

string op_ca(string s)
{
    string result = "";
    int level = 0; 

    for(char ch: s)
    {
        if(ch == '(')
        {
            if(level > 0) result += ch;
            level++;
        }
        else if(ch == ')')
        {
            level--;
            if(level > 0) result += ch;
        }
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);

    string ans = op_ca(s);
    cout<<"The Result is : "<<ans<<endl;
}