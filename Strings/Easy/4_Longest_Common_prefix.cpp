#include <iostream>
#include <string>
using namespace std;

string op_way(vector<string> &v)
{
    sort(v.begin(), v.end());
    string ans = "";
    for(int i = 0; i < min(v[0].size(), v[v.size() - 1].size()); i++)
    {
        if(v[0][i] == v[v.size() - 1][i]) ans += v[0][i];
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0 ;i < n; i++) cin>>v[i];
    string ans = op_way(v);
    cout<<ans<<endl;
}