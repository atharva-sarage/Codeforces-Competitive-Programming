/*
	Author- Atharva Sarage
		IIT HYDERABAD
		*/

#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int dist[100005][101];

int visited[100005];

int a[100005];
void bfs(int k,int n)
{
	for(int i=0;i<n;i++)
		visited[i]=0;
	queue <int> q;
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
			{
				q.push(i);
				dist[i][k]=0;
				visited[i]=1;
			}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int j=0;j<adj[x].size();j++)
		{
			
			if(!visited[adj[x][j]])
			{
				visited[adj[x][j]]=1;
				dist[adj[x][j]][k]=1+dist[x][k];
				q.push(adj[x][j]);
			}
		}
	}

}

int main()
{
	memset(dist,0,sizeof(dist));
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			x--;
			y--;
			addEdge(x,y);
		}
	for(int i=1;i<=k;i++)
		bfs(i,n);
	long ans=0;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		long ans=0;
		for(int j=1;j<=k;j++)
			vec.push_back(dist[i][j]);

		sort(vec.begin(),vec.end());
		for(int j=0;j<s;j++)
			ans+=vec[j];

		cout<<ans<<" ";
		vec.clear();
	}
	printf("\n");
}