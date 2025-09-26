#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <int> UnionOptimal(int *a1,int *a2,int n,int m)
{
    int i = 0,j = 0;
    vector <int> Union;
    while(i < n && j < m)
    {
        if(a1[i] < a2[j])
        {
            if(Union.size() == 0 || Union.back() != a1[i])
            {
                Union.push_back(a1[i]);
            }
            i++;
        }
        else
        {
            if(Union.size() == 0 || Union.back() != a2[j])
            {
                Union.push_back(a2[j]);
            }
            j++;
        }
    }
    while(i < n)
    {
        if(Union.back() != a1[i])
        {
            Union.push_back(a1[i]);
        }
        i++;
    }
    while(j < m)
    {
        if(Union.back() != a2[j])
        {
            Union.push_back(a2[j]);
        }
        j++;
    }
    return Union;
}

vector <int> UnionBrute(int *a1,int *a2,int n,int m)
{
    set<int> st;
    vector<int> Union;

    for(int i = 0;i<n;i++) st.insert(a1[i]);

    for(int i = 0;i<m;i++) st.insert(a2[i]);

    for(auto &it:st) Union.push_back(it);
    
    return Union;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int *a1 = new int[n];
    int *a2 = new int[m];
    for(int i = 0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(int i = 0;i<m;i++)
    {
        cin>>a2[i];
    }

    // vector<int> Union = UnionBrute(a1, a2, n, m);
    vector <int> Union = UnionOptimal(a1,a2,n,m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}