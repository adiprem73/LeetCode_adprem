class Solution {
public:
    
void func(string & tiles, vector<int> & visit, string curr, int & count){
    for(int i=0;i<tiles.size();i++){
        if(visit[i])continue;  //allready visited

        // to skip duplicates'
        if(i>0 && tiles[i] == tiles[i-1] && !visit[i-1]){
            continue;
        }

        visit[i]=1;
        count++; // valid sequence formed
        func(tiles, visit, curr+tiles[i], count);

        visit[i]=0;
    }
    
}

int numTilePossibilities(string tiles)
{
    sort(tiles.begin(), tiles.end());

    vector<int> visit(tiles.size(), 0);

    int count =0;

    func(tiles, visit, "", count);
    return count;
}
};