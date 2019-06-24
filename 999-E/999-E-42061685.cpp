// easy peasy lemon squeezy
#include<bits/stdc++.h>
using namespace std;
#define mx 5005
vector <int> adj[mx];
vector<pair<int,int> > edge;
map <int,int> m1;
vector <int> vec3;
int mark2[mx][mx],visited[mx];
int mark3[mx][mx];
int mark[mx],low[mx],val[mx];
vector <int> vec[mx];
stack <int> s;
int scc=0,n,t=0;
void addedge(int u,int v)
	{
		adj[u].push_back(v);
	}
void dfs(int x)
{
	val[x]=t;
	low[x]=t;
	t++;
	s.push(x);
	for(int i=0;i<adj[x].size();i++)
	{
		int u=adj[x][i];		
		
		if(val[u]==-1)
		{
			dfs(u);					
		}
								
		low[x]=min(low[x],low[u]);
	}
	if(low[x]==val[x])
	{
		while(1)
		{
			int j=s.top();
			s.pop();
			vec[scc].push_back(j);
			low[j]=n+5;
			if(x==j)
				break;
		}
		scc++;
	}
	
}
void dfs2(int u)
{
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!visited[v])
			dfs2(v);
	}
}
int main()
{
	int m,c;
	cin>>n>>m>>c;
	memset(mark2,0,sizeof(mark2));
	memset(mark,0,sizeof(mark));
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
		val[i]=-1;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		addedge(u,v);
		mark3[u][v]=1;
		edge.push_back(make_pair(u,v));
	}

	dfs2(c);
	for(int i=1;i<=n;i++)
	{
		if(val[i]==-1)
			dfs(i);
	}
	//cout<<scc<<endl;
	for(int i=0;i<scc;i++)
	{
		vec3.push_back(vec[i][0]);
		m1.insert(make_pair(vec[i][0],vec[i][0]));
		for(int j=1;j<vec[i].size();j++)
		{
			m1.insert(make_pair(vec[i][j],vec[i][0]));
		}
	}

	
	for(int i=0;i<m;i++)
	{
		if(m1[edge[i].first]==m1[edge[i].second])
			continue;

		if(mark2[m1[edge[i].first]][m1[edge[i].second]]==0)
		{
			mark[m1[edge[i].second]]=1;
			mark2[m1[edge[i].first]][m1[edge[i].second]]=1;
		}
	}
	int count=0;
	for(int i=0;i<vec3.size();i++)
	{
		if(mark[vec3[i]]==0 && vec3[i]!=c && visited[vec3[i]]==false)
			count++;
	}
	cout<<count<<endl;
}