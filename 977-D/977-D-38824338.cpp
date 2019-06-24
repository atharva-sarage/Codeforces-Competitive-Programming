#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
   //  adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited,vector<ull>&a)
{
    visited[u] = true;
    cout << a[u] << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited,a);
}
 
int main()
{
    int V;
    cin>>V;
    vector <ull> a;
    vector<ull> b;
    for(int i=0;i<V;i++)
        {
            ull x;
            cin>>x;
        a.push_back(x);
        }
    
    sort(a.begin(),a.end());
    vector<int> adj[V];
    int flag[V+5];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<V;i++)
    {
        if(binary_search(a.begin(),a.end(),a[i]*2) && a[i]<=15e17)
            for(int j=0;j<V;j++)
            {
                if(a[j]==a[i]*2)
                    {
                        addEdge(adj,i,j);
                        flag[j]=1;
                    }
            }
        if(a[i]%3==0 && binary_search(a.begin(),a.end(),a[i]/3))
            for(int j=0;j<V;j++)
            {
                if(a[j]==a[i]/3)
                    {
                        addEdge(adj,i,j);
                        flag[j]=1;
                    }
            }
    }
    // just find the initial vertex
    int index;
    for(int i=0;i<V;i++)
        if(flag[i]==0)
            index=i;
       // printf("%d\n",index );
    vector<bool> visited(V, false);
    DFSUtil(index,adj,visited,a);
    return 0;
}