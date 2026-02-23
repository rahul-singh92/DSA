#include <iostream>
using namespace std;

bool op_way(vector<int>& bills)
{
    int five = 0;
    int ten = 0;

    for(int bill: bills)
    {
        if(bill == 5) five++;
        else if(bill == 10)
        {
            if(five > 0)
            {
                five--;
                ten++;
            }
            else return false;
        }
        else
        {
            if(five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if(five >= 3)
            {
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20, 20};

    bool ans = op_way(bills);
    cout<<ans<<endl;
}