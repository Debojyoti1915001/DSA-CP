class Solution {
public:
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        //try to use as much as ladders and continue storing all the diff in priority queue
        //when ladders can't be used to satisfy view the last minimum difference
        //in order to obtain the last minimum diff use a max heap and continue storeing the elements there
        priority_queue<int,vector<int>,greater<>>pq;//max heap
        int n=ht.size();
        for(int i=0;i<n-1;i++){
            int d=ht[i+1]-ht[i];
            if(d>0){
                pq.push(d);
            }
            if(pq.size()>ladders){
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0)return i;
        }
        return ht.size()-1;
    }
};