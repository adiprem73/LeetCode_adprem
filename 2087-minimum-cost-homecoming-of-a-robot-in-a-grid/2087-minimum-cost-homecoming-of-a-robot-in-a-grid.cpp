class Solution {
public:
    
int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts){
    int x = startPos[0];
    int y = startPos[1];
    int a = homePos[0];
    int b = homePos[1];
    int totalCost=0;
    if(x<a){
        while(x<a){
            x++;
            totalCost+= rowCosts[x];
        }
    }
    else if(x>a){
        while(x>=a){
            x--;
            totalCost+=rowCosts[x];
        }
    }
    

    if(y<b){
        while(y<b){
            y++;
            totalCost+= colCosts[y];
        }
    }
    else if(y>b){
        while(y>=b){
            y--;
            totalCost+= colCosts[y];
        }
    }

    return totalCost;
}
};