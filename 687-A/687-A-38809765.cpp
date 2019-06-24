#include<bits/stdc++.h>
using namespace std;
vector <int> vec1;
vector <int> vec;
enum colour{white,black,gray};
int flag=0;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],int parent,int colour[])
{
   
    if(parent==-1)
        colour[u]=white;
    else
        {
            //printf("**%d %d**\n",parent,u );
            if(colour[parent]==white && (colour[u]==gray))
                colour[u]=black;
            else if(colour[parent]==white && (colour[u]==black))
                return;
            else if(colour[parent]==black && (colour[u]==gray))
                colour[u]=white;
            else if(colour[parent]==black && (colour[u]==white))
                    return;
            else
                {
                    flag=1;
                    return;
                }
        } 

    for (int i=0; i<adj[u].size(); i++)
        if (adj[u][i]!=parent || parent==-1)
            DFSUtil(adj[u][i], adj,u ,colour);
}
 

void DFS(vector<int> adj[], int V,int colour[])
{

    for(int i=0;i<V;i++)
        colour[i]=gray;
    for (int u=0; u<V; u++)
        if (colour[u] == gray)
           {
            DFSUtil(u, adj,-1,colour);            
           } 
}
 
int main()
{
    int V,e;
    cin>>V>>e;
    vector<int> adj[V+5];
    int colour[V+5];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }
   
    DFS(adj, V,colour);
    if(flag==1)
        printf("-1\n");
    else
    {
        for(int i=0;i<V;i++)
            if(colour[i]==white)
                vec1.push_back(i+1);
            else
                vec.push_back(i+1);
        int x=vec.size();
        int x1=vec1.size();
        printf("%d\n",x );
        for(int i=0;i<x;i++)
            printf("%d ",vec[i] );
        printf("\n");
        printf("%d\n",x1 );
        for(int i=0;i<x1;i++)
            printf("%d ",vec1[i] );
        printf("\n");
    }
    return 0;
}