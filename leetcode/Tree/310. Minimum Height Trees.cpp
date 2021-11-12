// https://leetcode.com/problems/minimum-height-trees/

"Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
And to find the longest path, we can first find the farthest leaf from any node, and then find
the farthest leaf from the node found above. Then these two nodes we found are the end points
of the longest path. And last, we find the centers of the longest path."

Steps:

1.Create adjcent list(neighbors)

2.Count in-degree of all vertices.

3.Pick any vertex 'v' which has in-degree of 0.

4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.

5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;//updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)//adding all the leave nodes
                queue.push(i);
        }
        while(!queue.empty())
        {
            res.clear();// clear vector before we start traversing level by level.
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    if(degrees[neighbor]==1)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};