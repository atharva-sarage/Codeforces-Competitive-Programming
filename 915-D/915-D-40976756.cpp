#include<bits/stdc++.h>
#define mx 505
using namespace std;
int flag=0,n;
int col[mx];
int par[mx];
vector <int> adj[mx];
vector< pair<int,int> > vec;
vector< pair<int,int> > vec2;
vector< int > :: iterator itr;
void addedge(int u,int v)
{
	adj[u].push_back(v);
}
void dfs(int u,int parent)
{
	col[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int x=adj[u][i];
		par[x]=u;
		if(col[x]==1 && flag==0)
		{
			// cycle found 
			flag=1;
			
			vec.push_back(make_pair(u,x));
			while(par[u]!=x)
			{
				vec.push_back(make_pair(par[u],u));
				u=par[u];
			}	
			vec.push_back(make_pair(x,u));
			return ;
		}
		else if(col[x]==0)
		{
			dfs(x,u);
		}
	}
	col[u]=2;
}
void DFS()
{
	for(int i=0;i<n;i++)
	{
		if(col[i]==0)
			dfs(i,-1);
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	memset(col,0,sizeof(col));
	memset(par,-1,sizeof(par));
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	DFS();
	/*for(int i=0;i<vec.size();i++)	
		cout<<vec[i].first<<"***"<<vec[i].second<<endl;*/
	flag=0;
	vec2=vec;
	for(int i=0;i<vec2.size();i++)
	{
		vec.clear();
		flag=0;
		memset(col,0,sizeof(col));
		memset(par,-1,sizeof(par));
		int x=vec2[i].first;
		int y=vec2[i].second;
		itr=find(adj[x].begin(),adj[x].end(),y);
		adj[x].erase(itr);
		DFS();
		if(flag==0)
		{
			break;
		}
		addedge(x,y);
	}

	if(flag==1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}