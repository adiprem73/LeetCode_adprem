class Solution {
public:
    static 
    bool sorting (vector<int>& a, vector<int>& b){
    return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1];
}

int scheduleCourse(vector<vector<int>> &courses)
{
    sort(courses.begin(), courses.end(), sorting);
    priority_queue<int> pq;
    int time =0; // time taken to complete the course til now

    for(auto course: courses){
        if(course[0] <= course[1]){ // check if we consider curren t oucrse : if duration<=lastday
            if(course[0]+time <=  course[1]){ // current course can be completed with the lastday given
                pq.push(course[0]); // we want the duration in the priority queue
                time += course[0];
            }else{
                // check if we can swap
                if (!pq.empty() && pq.top() > course[0])
                {
                    time -= pq.top();
                    pq.pop();
                    pq.push(course[0]);
                    time+=course[0];
                }
            }
        }
    }
    return pq.size();
}
};