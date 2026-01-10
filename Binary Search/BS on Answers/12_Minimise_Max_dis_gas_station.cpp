#include <iostream>
#include <vector>
using namespace std;

// long double wo_ca(vector<int> v, int n, int k)
// {
//     vector<int> howMany(n-1,0);

//     for(int gasStation = 1; gasStation <= k; gasStation++)
//     {
//         long double maxSection = -1;
//         int maxInd = -1;

//         for(int i = 0; i < n-1; i++)
//         {
//             long double diff = v[i+1] - v[i];
//             long double sectionLength = diff / (howMany[i] + 1.0);

//             if(sectionLength > maxSection)
//             {
//                 maxSection = sectionLength;
//                 maxInd = i;
//             }
//         }
//         howMany[maxInd]++;
//     }

//     long double maxAns = -1;
//     for(int i = 0; i < n-1; i++)
//     {
//         long double diff = v[i+1] - v[i];
//         long double sectionLength = diff / (howMany[i] + 1.0);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }

long double be_ca(vector<int> v, int n, int k)
{
    long double low = 0, high = 0;

    for(int i = 0; i < n-1; i++)
    {
        high = max(high, (long double)(v[i+1] - v[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff)
    {
        long double mid = (low + high) / 2.0;

        //Number of gas stations required.
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            int numberInBetween = (v[i] - v[i-1]) / mid;

            if((v[i] - v[i-1]) == (mid * numberInBetween))
            {
                numberInBetween--;
            }
            count += numberInBetween;
        }
        if(count > k) low = mid;
        else high = mid;
    }
    return high;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    long double ans = be_ca(v, n, k);
    cout<<ans<<endl;
}