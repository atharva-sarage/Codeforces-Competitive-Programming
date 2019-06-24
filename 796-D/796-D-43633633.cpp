#include<bits/stdc++.h>
using namespace std;
# define mx 300005
# define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
# define ipair pair<int,int>
# define ff first
# define ss second
# define mp make_pair
using namespace std;
vector <ipair> adj[mx];
int visited[mx],par[mx],p[mx],mark[mx];
void addedge(int u,int v,int w)
{
	adj[u].push_back(mp(v,w));
	adj[v].push_back(mp(u,w));
}
int main()
{
	IOS;
	memset(mark,0,sizeof(mark));
	queue<ipair> q;
	set <int> s2;
	set <int> :: iterator itr;
	int n,k,d,ans=0;
	cin>>n>>k>>d;
	for(int i=0;i<k;i++)
		{
		cin>>p[i];
		s2.insert(p[i]);
		}
	for(itr=s2.begin();itr!=s2.end();++itr)
		{
		visited[*itr]=true;
		par[*itr]=-1;
		q.push(mp(*itr,d));
		}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y,i+1);
	}
	while(!q.empty())
	{
		int v=q.front().ff;
		int w=q.front().ss;
		q.pop();
		for(int i=0;i<adj[v].size();i++)
		{
			int x=adj[v][i].ff;
			int y=adj[v][i].ss;
			if(x==par[v])
				continue;
			if(visited[x])
				continue;
			mark[y]=1;
			par[x]=v;
			visited[x]=true;
			if(w>1)
			{
			q.push(mp(x,w-1));
			}
		}
	}
	//cout<<ans/2<<endl;
	for(int i=1;i<=n-1;i++)
		{if(mark[i]==0)
			ans++;}
	cout<<ans<<endl;
	for(int i=1;i<=n-1;i++)
		if(mark[i]==0)
			cout<<i<<" ";
}