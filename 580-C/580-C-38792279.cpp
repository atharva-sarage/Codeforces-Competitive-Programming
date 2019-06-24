#include<bits/stdc++.h>
using namespace std;
 
int final=0;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],vector<bool> &visited,int cat,int k,int flag[],int parent)
{
    int y;
    if(flag[u]==1)
        y=++cat;
    else
        y=0;
 //   printf("##%d \n",y );

    if(y<=k)
        visited[u] = true;
    else
        {
            //printf("***\n");
            return;
        }

    if(adj[u].size()==1 && u!=1)
        final++;
    for (int i=0; i<adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false && adj[u][i]!=parent || parent==-1)
            DFSUtil(adj[u][i], adj, visited,y,k,flag,u);
        }
}
int main()
{
    int V,k ;
    cin>>V>>k;
    vector<bool> visited(V, false);
    vector<int> adj[V+1];
    int flag[V+1];
    for(int i=1;i<=V;i++)
        cin>>flag[i];
    for(int j=0;j<V-1;j++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,min(x,y),max(x,y));
    }
    
    DFSUtil(1,adj,visited,0,k,flag,-1);
    printf("%d\n",final );
    
}