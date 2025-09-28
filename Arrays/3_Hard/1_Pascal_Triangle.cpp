#include <iostream>
#include <vector>
using namespace std;


// variant 1 where row and column will be given and we need to find the value
// so for that the shortcut is (n-1)C(r-1) , now the problem is that it is hard to compute first n-1 then r-1 then n-r-2 ) O(n-1) + O(r-1) + O(n-r-2);
// so for that we will use a loop till r times and decrease above and left is cut O(r);
void ncr(int n,int r)
{
    int res = 1;
    for(int i = 0; i < r;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    cout<<endl;
    cout<<res<<endl;
}

//variant 2 where you need to find the whole row of the pascal triangle
//First option is to use the above formula and calculate for each element in row O(n*r)
//Second option is by observing that it always start from 1 then it gets multiplied by the (row-col)/col  O(n)
//For ex if n = 6 then first ele will be 1, then next is 5 which can be written as (6-1)/1 
void var2(int n)
{
    int res = 1;
    cout<<res<<" ";
    for(int i = 1; i < n; i++)
    {
        res *= (n - i);
        res /= i;
        cout<<res<<" ";
    }
    cout<<endl;
}

//Variant 3 where wee will print the whole pascal table till n
//First option is to use 2 loop for row and col and then use ncr formula O(n*n*r)
//Second option is to use variant 2 strategy to calculate each rows
vector<int> genRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int i = 1; i < row; i++)
    {
        ans *= (row - i);
        ans /= i;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> var3(int n)
{
    vector<vector<int>> ans;
    for(int i = 1; i<=n;i++)
    {
        ans.push_back(genRow(i));
    }
    return ans;
}
int main()
{
    //variant 1.
    // int n,r;
    // cin>>n>>r;
    // ncr(n,r);

    //variant 2
    // int n;
    // cin>>n;
    // var2(n);

    //variant 3
    int n;
    cin>>n;
    vector<vector<int>> v = var3(n);
    for(auto it: v)
    {
        for(auto it1: it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}