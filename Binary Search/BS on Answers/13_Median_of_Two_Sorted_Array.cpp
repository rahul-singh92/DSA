#include <iostream>
#include <vector>
using namespace std;

// double bru_ca(vector<int> v1, vector<int> v2, int n, int m)
// {
//     vector<int> ans(n + m, 0);
//     int i = 0, j = 0, k = 0;
//     while(i < n && j < m)
//     {
//         if(v1[i] <= v2[j])
//         {
//             ans[k++] = v1[i];
//             i++;
//         }
//         else
//         {
//             ans[k++] = v2[j];
//             j++;
//         }
//     }
//     while(i < n)
//     {
//         ans[k++] = v1[i];
//         i++;
//     }
//     while(j < m)
//     {
//         ans[k++] = v2[j];
//         j++;
//     }
//     int ans_n = ans.size();
//     if(ans_n % 2 == 1) return ans[ans_n/2];
//     else return (ans[ans_n/2 - 1] + ans[ans_n/2]) / 2.0;
// }



// double bet_ca(vector<int> v1, vector<int> v2, int n, int m)
// {
//     int ans_n = n + m;
    
//     int ind2 = ans_n / 2;
//     int ind1 = ind2 - 1;

//     int count = 0, i = 0, j = 0;
//     int ind1el = -1, ind2el = -1;

//     while(i < n && j < m)
//     {
//         if(v1[i] < v2[j])
//         {
//             if(count == ind1) ind1el = v1[i];
//             if(count == ind2) ind2el = v1[i];
//             i++;
//         }
//         else
//         {
//             if(count == ind1) ind1el = v2[j];
//             if(count == ind2) ind2el = v2[j];
//             j++;
//         }
//         count++;
//     }
//     while(i < n)
//     {
//         if(count == ind1) ind1el = v1[i];
//         if(count == ind2) ind2el = v1[i];
//         i++;
//     }
//     while(j < m)
//     {
//         if(count == ind1) ind1el = v2[j];
//         if(count == ind2) ind2el = v2[j];
//         j++;
//     }

//     if(ans_n % 2 == 1) return (double)ind2el;
//     else return (ind1el + ind2el) / 2.0;
// }


double op_ca(vector<int> v1, vector<int> v2, int n, int m)
{
    if(n > m) return op_ca(v2, v1, m, n);
    int low = 0, high = n;
    
    while(low <= high)
    {
        //Calculate the cut position of both arrays
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : v1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : v2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : v1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : v2[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n + m) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if(l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1(n), v2(m);
    for(int i = 0; i < n; i++)
    {
        cin>>v1[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin>>v2[i];
    }
    double ans = op_ca(v1, v2, n, m);
    cout<<ans<<endl;
}