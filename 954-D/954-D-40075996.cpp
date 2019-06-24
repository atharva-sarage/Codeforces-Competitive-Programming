#include<bits/stdc++.h>
using namespace std;
int dist[1005][1005];
int visited[1005];
vector<int> adj[1005];
void addedge(int x,int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void bfs(int start)
{
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(start);
	dist[start][start]=0;
	visited[start]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<adj[x].size();i++)
		{
			if(!visited[adj[x][i]])
			{
				q.push(adj[x][i]);
				visited[adj[x][i]]=true;
				dist[start][adj[x][i]]=dist[start][x]+1;
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n,m,ans=0,start,end;

	cin>>n>>m>>start>>end;
	start--;end--;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	long total;
	if(n%2==0)
		total=(n/2)*(n-1);
	else
		total=(n-1)/2*n;
	for(int i=0;i<n;i++)
		bfs(i);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(dist[i][j]!=1)// not connected by a direct edge
			{
				if(dist[start][i]+1+dist[j][end]<dist[start][end] || dist[start][j]+1+dist[i][end]<dist[start][end])
					ans--;
			}
		}
	}
	cout<<total-m+ans<<endl;
}