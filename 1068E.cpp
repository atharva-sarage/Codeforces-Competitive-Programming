#include<bits/stdc++.h>
using namespace std;
# define mx 100005
vector <int> adj[mx];
vector <int> vec2;
int deg[mx],mark[mx],parent[mx],dist[mx],k;
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int check(int x)
{
	queue<int> q;
	q.push(x);
	parent[x]=-1;
	dist[x]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<adj[x].size();i++)
		{
			int v=adj[x][i];
			if(v!=parent[x])
			{dist[v]=1+dist[x];parent[v]=x;
			q.push(v);}
		}
	}
	for(int i=0;i<vec2.size()-1;i++)
	{
		if(dist[vec2[i]]!=dist[vec2[i+1]] )
			return 0;
	}
	if(dist[vec2[0]]!=k)
		return 0;
	return 1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	queue<int> q;
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
		deg[x]++;
		deg[y]++;
	}
	for(int i=0;i<n;i++)
	{
		if(deg[i]==1)
			{q.push(i);mark[i]=2;vec2.push_back(i);}
	}
	int count1=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(deg[x]==0)		
		{
			if(check(x))
				{
				mark[x]=0;
				}
			break;
		}
		for(int i=0;i<adj[x].size();i++)
		{
			int v=adj[x][i];
			deg[v]--;
			if(deg[v]==1)
				{
				q.push(v);
				mark[v]=1;
				}
		}
	}
	int flag=0,flag2=0;
	for(int i=0;i<n;i++)
	{
		if(mark[i]==0)
			flag=1;	
	}
	if(flag==1)
	{
		for(int i=0;i<n;i++)
		{
			if(mark[i]==1 && adj[i].size()<=3)
			{
				flag2=1;
				break;
			}
			else if(mark[i]==0 && adj[i].size()<3)
			{
				flag2=1;
				break;	
			}
		}
	}

	if(flag2==1 || flag==0)
		cout<<"No"<<"\n";
	else
		cout<<"Yes"<<"\n";



}




