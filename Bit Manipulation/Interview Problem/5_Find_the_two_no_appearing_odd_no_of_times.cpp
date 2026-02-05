#include <iostream>
using namespace std;

vector<int> singleNum(vector<int>& num)
{
    int n = num.size();

    long XOR = 0;
    for(int i = 0; i < n; i++)
    {
        XOR ^= num[i];
    }

    int rightmost = (XOR & (XOR - 1)) ^ XOR;

    int XOR1 = 0, XOR2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(num[i] & rightmost)
        {
            XOR1 ^= num[i];
        }
        else
        {
            XOR2 ^= num[i];
        }
    }

    if(XOR1 < XOR2) return {XOR1, XOR2};
    return {XOR2, XOR1};
}

int main()
{
    vector<int> num = {1, 2, 1, 3, 5, 2};

    vector<int> ans = singleNum(num);

    cout<<ans[0]<<' '<<ans[1];
}