#include <iostream>
using namespace std;

void dfs(string& num, int target, int start, long long current_value, long long last_operand,
         string expression, vector<string>& result)
{
    //Base Case: if we have reacged the end of the string
    if(start == num.size())
    {
        //If the expression evaluates to the target, add it to the result
        if(current_value == target)
        {
            result.push_back(expression);
        }
        return;
    }

    //Loop through all substring starting from 'start' index
    for(int i = start; i < num.size(); i++)
    {
        //Skip leading zeros in number
        if(i > start && num[start] == '0') return;

        //Get the current number
        string current_num = num.substr(start, i - start + 1);
        long long current_num_val = stoll(current_num);

        //If we are at the first number, just start the expression
        if(start == 0)
        {
            dfs(num, target, i + 1, current_num_val, current_num_val, current_num, result);
        }
        else
        {
            //Add the current number with '+'
            dfs(num, target, i + 1, current_value + current_num_val, current_num_val, expression + "+" + current_num, result);

            //Add the current number with '-'
            dfs(num, target, i + 1, current_value - current_num_val, -current_num_val, expression + "-" + current_num, result);

            //Add the current number with '*'
            dfs(num, target, i + 1, current_value - last_operand + last_operand * current_num_val, last_operand * current_num_val, expression + "*" + current_num, result);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    //Start DFS with empty expressions
    dfs(num, target, 0, 0, 0, "", result);
    return result;
}

int main()
{
    string num = "123";
    int target = 6;

    vector<string> result = addOperators(num, target);

    for(auto i: result) cout<<i<<" ";
}