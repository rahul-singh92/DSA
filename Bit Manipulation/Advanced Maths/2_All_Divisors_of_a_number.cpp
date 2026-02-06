#include <iostream>
using namespace std;

vector<int> print_all_bru(int n)
{
    vector<int> ls;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0) ls.push_back(i);
    }
    return ls;
}

vector<int> print_all_bet(int n)
{
    vector<int> ls;

    for(int i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ls.push_back(i);
            if(n / i != i) ls.push_back(n / i);
        }
    }
    return ls;
}

int main()
{
    int n = 36;

    vector<int> ans = print_all_bet(n);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}