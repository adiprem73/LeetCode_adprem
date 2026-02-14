class Solution
{
private:
    string decToBin(int n){
        string s="";
        while(n>0){
            int remainder = n%2;
            n=n/2;
            s= to_string(remainder)+s;
        }
        return s;
    }
public:
    string convertDateToBinary(string date)
    {
        string yr = date.substr(0,4);
        string mt = date.substr(5,2);
        string dt = date.substr(8,2);
        string binYr = decToBin(stoi(yr));
        string binMt = decToBin(stoi(mt));
        string binDt = decToBin(stoi(dt));
        return (binYr+'-'+binMt+'-'+binDt);
    }
};