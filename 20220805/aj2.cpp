//Back-end complete function Template for C++

class Dinic
{
public:
  vector<int> edgeId,flow;
  map<array<int,2>,int> mp;
  int src,des,n;
  vector<int> lvl,nxt;
  vector<array<int,2>> path;
  vector<vector<array<int,2>>> v;
  void init(int n1,int Src,int Des, int m1)
  {
      edgeId = vector<int>(m1+10);
      flow  = vector<int>(m1+10);
      mp.clear();
      path.clear();
      n=n1;
      src=Src;
      des=Des;
      lvl=vector<int>(n+1);
      nxt=vector<int>(n+1);
      v=vector<vector<array<int,2>>>(n+1);
  }
  bool bfs()
  {
    queue<int> q;
    q.push(src);
    fill(lvl.begin(),lvl.end(),-1);
    lvl[src]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto i:v[node])
        {
           if(lvl[i[0]]!=-1||edgeId[i[1]]==0)
              continue;
            q.push(i[0]);
            lvl[i[0]]=lvl[node]+1;
        }
    }
    return lvl[des]!=-1;
  }
  int dfs(int node,int push)
  {
     if(push==0||node==des){
      if(node==des)
      path.push_back({des,-1});
      return push;
     }

    for(;nxt[node]<v[node].size();nxt[node]++,path.clear())
    {
       int id=v[node][nxt[node]][1];
       int y=v[node][nxt[node]][0];
       if(edgeId[id]==0||lvl[node]+1!=lvl[y])
        continue;
      int f=dfs(y,min(push,edgeId[id]));
      if(f==0)
        continue;
    
      flow[id]+=f;
      path.push_back({node,id});
      return f;
    }
    return 0;
  }
  
  int maxflow()
  {
      int mx=0;
      while(bfs())
      {
          fill(nxt.begin(),nxt.end(),0);
          for(int f;f=dfs(src,INT_MAX);){
            if (f==0)
            {
               path.clear();
               break;
            }
              reverse(path.begin(),path.end());
              for(int j=0;j<path.size()-1;j++)
              {
                edgeId[path[j][1]]-=f;
                edgeId[path[j][1]^1]+=f;

                int x=path[j][0];
                int y=path[j+1][0];
                int f1=f;
                if(x>y)
                {
                  swap(x,y);
                  f1*=-1;
                }
                auto it=mp.find({x,y});
                if(it!=mp.end())
                {
                    it->second+=f1;
                }
                else
                {
                  mp[{x,y}]=f1;
                }

              }
              mx+=f;
              path.clear();
          }
      }
      return mx;
  }
};



class Solution{
public:
    int maximumAdmissions(int n,int m,vector<vector<int>> applied,vector<int> no_of_seats){
        // code here

        Dinic d;

        int no_of_nodes=0;
        int source=1;
        int sink=n+m+2;
        int id=-1;
        d.init(n+m+2,source,sink,2*(n*m+n+m));  

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(applied[i][j]==1)
              {
                int x=i+2;
                int y=j+2+n;
                d.v[x].push_back({y,++id});
                d.edgeId[id]=1;
                d.v[y].push_back({x,++id});
              }
            }
        }
        for(int i=0;i<n;i++)
        {
          int x=source;
          int y=i+2;
          d.v[x].push_back({y,++id});
          d.edgeId[id]=1;
          d.v[y].push_back({x,++id});
        }

          
        for(int i=0;i<m;i++)
        {
          int x=i+2+n;
          int y=sink;
          d.v[x].push_back({y,++id});
          d.edgeId[id]=no_of_seats[i];
          d.v[y].push_back({x,++id});
        }
        return d.maxflow();
    }
};