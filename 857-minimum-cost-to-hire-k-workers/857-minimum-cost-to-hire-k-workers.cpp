class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<vector<double>>workers;
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