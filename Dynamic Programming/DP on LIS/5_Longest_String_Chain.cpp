#include <iostream>
using namespace std;
bool comp(string &a, string &b)
{
    if(a.size() != b.size() + 1) return false;
    int i = 0, j = 0;
    while(i < a.size())
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if(i == a.size() && j == b.size()) return true;

    return false;
}


int sol(vector<string>& arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), [](string& a, string& b){ return a.size() < b.size(); }); // if you want to find subset
    vector<int> dp(n, 1);

    int maxi = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(comp(arr[i], arr[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i] > maxi) maxi = dp[i];
    }
    return maxi;
}

int main()
{
    vector<string> arr = {"dog", "dogs", "dots", "dot", "d", "do"};

    int ans = sol(arr);
    cout<<ans<<endl;
}