class Solution {
public:
    //think of k elements all together
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<vector<double>>workers;
        //W[i]/Q[i]=W[j]/Q[j]
        
//         So to minimize the total wage, we want a small ratio.
// So we sort all workers with their expected ratio, and pick up K first worker.
// Now we have a minimum possible ratio for K worker and we their total quality.

// As we pick up next worker with bigger ratio, we increase the ratio for whole group.
// Meanwhile we remove a worker with highest quality so that we keep K workers in the group.
// We calculate the current ratio * total quality = total wage for this group.

// We redo the process and we can find the minimum total wage.
// Because workers are sorted by ratio of wage/quality.
// For every ratio, we find the minimum possible total quality of K workers.
        for(int i=0;i<q.size();++i){
            workers.push_back({(double)(w[i])/q[i],(double)q[i]});
        }
        sort(workers.begin(),workers.end());
        double res=DBL_MAX,qsum=0;
        priority_queue<int>pq;
        for(auto worker:workers){
            qsum+=worker[1];
            pq.push(worker[1]);
            if(pq.size()>k)qsum-=pq.top(),pq.pop();
            if(pq.size()==k)res=min(res,qsum*worker[0]);
        }
        return res;
    }
};