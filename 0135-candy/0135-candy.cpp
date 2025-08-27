class Solution {
public:
    int candy(vector<int>& ratings) {
    int sum=1;
    int i=1;
    int n=ratings.size();
    while(i<n){
        //flat surface
        if(ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
            continue;
        }

        //upward slope
        int peak=1;
        while(i<n&& ratings[i]>ratings[i-1]){
            peak+=1;
            sum +=peak;
            i++;
        }

        //downward slope
        int down=0;
        while(i<n && ratings[i]<ratings[i-1]){
            down+=1;
            sum+=down;
            i++;
        }
        
        down++;
        if(down>peak){
            sum+=down-peak;
        }
    } 
    return sum;       
}
};