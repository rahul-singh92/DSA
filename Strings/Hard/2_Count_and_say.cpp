#include <iostream>
using namespace std;

string sol(int n)
{
    string result = "1";
    for(int i = 1; i < n; i++)
    {
        string current = "";
        int count = 1;

        for(int j = 1; j < result.size(); j++)
        {
            if(result[j] == result[j-1])
                count++;
            else
            {
                current += to_string(count) + result[j-1];
                count = 1;
            }
        }

        current += to_string(count) + result.back();
        result = current;
    }
    return result;
}

int main()
{
    int n = 4;
    string ans = sol(n);
    cout<<ans<<endl;
}