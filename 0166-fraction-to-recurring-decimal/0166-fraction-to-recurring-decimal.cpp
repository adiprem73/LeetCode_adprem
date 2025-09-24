class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
{

    string result;

    if((numerator<0 ^ denominator<0) && numerator!=0) result.push_back('-');

    long long num=llabs((long long)numerator);
    long long den= llabs((long long)denominator);
    
    long long part1= num/den;
    // cout << part1 << endl;
    result+=to_string(llabs(part1));
    

    unordered_map<int, int> seen;
    string decimals;
    long long remainder = ((long long)num) % ((long long)den);
    if(remainder==0){
        return result;
    }
    result.push_back('.');

    int pos = 0;
    while (remainder != 0 && seen.find(remainder) == seen.end())
    { // loop continue till the number becomes 0 or it is already stoed in the seen map
        seen[remainder] = pos++;
        remainder *= 10;
        int digit = (int)(remainder / (long long)den);
        decimals.push_back(char('0' + digit));
        remainder = remainder % (long long)den;
    }

    if (remainder == 0)
    {
        result+=decimals;
    }

    else
    {
        int start = seen[remainder];
        result+=decimals.substr(0,start) + '(' + decimals.substr(start) + ')';
    }

    return result;
    // now the rest o fthe number that is after the decimal is to be calculated --> r/denominator
    
    // a division will give terminating if the denominator contains such a number whose factors are only 2 and 5. if any other factor comes then its repeating

}
};