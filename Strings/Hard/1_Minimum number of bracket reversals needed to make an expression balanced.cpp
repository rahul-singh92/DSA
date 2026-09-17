#include <iostream>
using namespace std;

int bet_way(string& exp)
{
    int o_b = 0;
    int c_b = 0;
    for(char ch: exp)
    {
        if(ch == '(')
            o_b++;
        else
        {
            if(o_b > 0)
                o_b--;
            else
                c_b++;
        }
    }

    if((o_b + c_b) % 2 != 0) return -1;
    return (o_b + 1) / 2 + (c_b + 1) / 2;
}

int main()
{
    string exp = ")(())(((";
    int ans = bet_way(exp);
    cout<<ans<<endl;
}