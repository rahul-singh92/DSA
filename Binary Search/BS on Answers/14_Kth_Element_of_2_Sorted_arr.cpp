#include <iostream>
#include <vector>
using namespace std;

// int wo_ca(vector<int> v1, vector<int> v2, int n, int m, int k)
// {
//     vector<int> ans(n + m, 0);
//     int i = 0, j = 0, p = 0;
//     while(i < n && j < m)
//     {
//         if(v1[i] < v2[j]) ans[p++] = v1[i++];
//         else ans[p++] = v2[j++];
//     }
//     while(i < n) ans[p++] = v1[i++];
//     while(j < m) ans[p++] = v2[j++];
//     return ans[k-1];
// }



// int be_ca(vector<int> v1, vector<int> v2, int n, int m, int k)
// {
//     int i = 0, j = 0, count = 0;
//     while(i < n && j < m)
//     {
//         if(v1[i] < v2[j])
//         {
//             if(count + 1 == k) return v1[i];
//             i++;
//             count++;
//         }
//         else
//         {
//             if(count + 1 == k) return v2[j];
//             j++;
//             count++;
//         }
//     }
//     while(i < n)
//     {
//         if(count + 1 == k) return v1[i];
//         i++;
//         count++;
//     }
//     while(j < m)
//     {
//         if(count + 1 == k) return v2[j];
//         j++;
//         count++;
//     }
//     return -1;
// }


int op_ca(vector<int> v1, vector<int> v2, int n, int m, int k)
{
    if(n > m) return op_ca(v2, v1, m, n, k);

    int low = max(0, k - m), high = min(k, n);
    int left = k;
    while(low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? v1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? v2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n) ? v1[mid1] : INT_MAX;
        int r2 = (mid2 < m) ? v2[mid2] : INT_MAX;

        if(l1 <= r2 && l2<= r1) return max(l1,l2);
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> v1(n), v2(m);
    for(int i = 0; i < n; i++) cin>>v1[i];
    for(int i = 0; i < m; i++) cin>>v2[i];

    int ans = op_ca(v1, v2, n, m, k);
    cout<<ans<<endl;
}