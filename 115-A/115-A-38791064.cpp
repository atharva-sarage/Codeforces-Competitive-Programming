#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}
int ans=0;

void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited,int count)
{
    visited[u] = true;
    ans=max(ans,count);
    //cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            {
               // printf("%d\n",count );
                int y=count;
                DFSUtil(adj[u][i], adj, visited,++y);
            }
}


void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<=V; u++)
        {
            vector<bool> visited(V, false);
            if (visited[u] == false)
            DFSUtil(u, adj, visited,1);
        }
}

int main()
{
    
    int V ,flag=0;
    cin>>V;
     vector<int> adj[V+1];
     for(int i=1;i<=V;i++)
     {
        int x;
        cin>>x;
        if(x!=-1)
            {
                addEdge(adj,x,i);
                flag=1;
            }
     }
     if(V==2 && flag==1)
     {
        printf("2\n");
        return 0;
     }
   

    DFS(adj, V);
    printf("%d\n",ans );
    return 0;
}