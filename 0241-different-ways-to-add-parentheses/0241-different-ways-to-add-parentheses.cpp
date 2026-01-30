class Solution {
public:
    
vector<int> diffWaysToCompute(string expression)
{
    vector<int> results;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i+1));

            for (auto itLeft : left)
            {
                for (auto itRight : right)
                {
                    if (expression[i] == '+')
                    {
                        results.push_back(itLeft + itRight);
                    }
                    else if (expression[i] == '-')
                    {
                        results.push_back(itLeft - itRight);
                    }else{
                        results.push_back(itLeft*itRight);
                    }
                }
            }
        }
    }
    if(results.empty())results.push_back(stoi(expression));
    return results;
}
};