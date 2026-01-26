#include <iostream>
using namespace std;

void generate(int n, string s, vector<string>& result)
{
    if(s.length() == n)
    {
        result.push_back(s);
        return;
    }

    generate(n, s + "0", result);

    if(s.empty() || s.back() != '1')
    {
        generate(n, s + "1", result);
    }
}

int main()
{
    int n = 3;

    vector<string> result;

    generate(n, "", result);

    for(auto s: result)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}