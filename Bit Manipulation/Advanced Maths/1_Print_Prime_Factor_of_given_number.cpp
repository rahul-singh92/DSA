#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n == 2) return true;
    int count = 0;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) count++;
        if(count > 0) return false;
    }
    return true;
}

vector<int> checkPrime_Bru(int n)
{
    vector<int> ls;

    for(int i = 2; i*i < n; i++)
    {
        if(n % i == 0)
        {
            if(isPrime(i)) ls.push_back(i);
            if(n / i != i)
            {
                if(isPrime(n/i)) ls.push_back(n/i);
            }
        }
    }
    return ls;
}

//Using school method factors of that number
vector<int> checkPrime_Bet(int n)
{
    vector<int> ls;
    
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0) ls.push_back(i);
        while(n % i == 0) n = n / i;
    }
    return ls;
}

vector<int> checkPrime_Op(int n)
{
    vector<int> ls;
    for(int i = 2; i*i < n; i++)
    {
        if(n % i == 0) ls.push_back(i);
        while(n % i == 0) n = n / i;
    }
    if(n != 1) ls.push_back(n); // This is needed because the last check of prime like 13 is not done 

    return ls;
}

int main()
{
    int n = 780;
    vector<int> ans = checkPrime_Op(n);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}