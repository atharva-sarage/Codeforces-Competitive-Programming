#include<bits/stdc++.h>
using namespace std;
 

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
  vector <pair<int,int> > vec;
int long long final=0;
void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited)
{
    visited[u] = true;
   
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

void DFS(vector<int> adj[], int V,int c[])
{
    vector<bool> visited(V, false); 
    int flag[V+5];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<V;i++)
    {
        if(visited[vec[i].second]==false)
        {
            final+=vec[i].first;
            DFSUtil(vec[i].second,adj,visited);
        }
    }

}
 
// Driver code
int main()
{
    int V,e;
    cin>>V>>e;
    int c[V+5];
  
    for(int i=0;i<V;i++)
        {
            cin>>c[i];
            vec.push_back(make_pair(c[i],i));
        }
        sort(vec.begin(),vec.end());
    vector<int> adj[V+5];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }   
    DFS(adj, V,c);
    printf("%lld\n",final );
    return 0;
}