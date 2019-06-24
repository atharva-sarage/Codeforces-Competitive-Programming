#include<bits/stdc++.h>
using namespace std;
# define mx 200005
# define ff first
# define ss second
# define mp make_pair
# define pb push_back
# define inf 300005
struct edge
{
	int i1,i2,i3;
};
struct edge2
{
	int v,wt,id;
};
vector <pair<int,pair<int,int> > > adj[mx];
int dp1[mx],dp[mx],dp2[mx],parent[mx],visited[mx],mark[mx],mark2[mx];
struct edge e[mx];
struct edge2 parentf[mx];
void addedge(int u,int v,int wt,int id)
{
	adj[u].pb(mp(v,mp(wt,id)));
	adj[v].pb(mp(u,mp(wt,id)));
}
void print(int id)
{
	cout<<e[id].i1<<" "<<e[id].i2<<" "<<(1^(e[id].i3))<<endl;
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==1)ans++;
		addedge(x,y,z,i);
		e[i]={x,y,z};
	}
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	queue<int>q;
	queue<int>q2;
	q.push(1);
	dp1[1]=0;
	visited[1]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto k:adj[x])
		{
			if(visited[k.ff] || k.ff==parent[x])continue;
			parent[k.ff]=x;
			dp1[k.ff]=dp1[x]+1;
			visited[k.ff]=true;
			q.push(k.ff);
		}
	}
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	int mini=dp1[n];
	q2.push(n);
	dp2[n]=0;
	visited[n]=true;
	while(!q2.empty())
	{
		int x=q2.front();
		q2.pop();
		for(auto k:adj[x])
		{
			if(visited[k.ff] || k.ff==parent[x])continue;
			parent[k.ff]=x;
			dp2[k.ff]=dp2[x]+1;
			visited[k.ff]=true;
			q2.push(k.ff);
		}
	}
	memset(mark,false,sizeof(mark));
	for(int i=1;i<=n;i++)
	{
		if(dp1[i]+dp2[i]==mini)
		{
			mark[i]=true;			
		}
	}
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	for(int i=0;i<mx;i++)
		dp[i]=inf;
	deque<int>q1;
	q1.push_front(1);
	dp[1]=0;
	visited[1]=true;
	parentf[1].v=-1;
	while(!q1.empty())
	{
		int x=q1.front();
		q1.pop_front();
		for(auto k:adj[x])
		{
			//cout<<x<<endl;
			//cout<<k.ff<<" "<<mark[k.ff]<<" "<<visited[k.ff]<<endl;
			if(!mark[k.ff]|| k.ff==parent[x])continue;

			if(dp[x]+(1^k.ss.ff)<dp[k.ff])
				dp[k.ff]=dp[x]+(1^k.ss.ff);
			else
				continue;
				
			if(k.ss.ff==1)
				q1.push_front(k.ff);				
			else
				q1.push_back(k.ff);				
			
			visited[k.ff]=true;
			parentf[k.ff]={x,k.ss.ff,k.ss.ss};
		}
	}
	//cout<<dp1[n]<<" "<<dp[n]<<endl;
	
	cout<<ans+(dp[n]*2)-dp1[n]<<endl;	
	for(int i=0;i<m;i++)
		mark2[i]=true;
	int x=n;
	while(parentf[x].v!=-1)
	{
		//cout<<x<<endl;
		mark2[parentf[x].id]=false;
		if(parentf[x].wt==0)
			print(parentf[x].id);
		x=parentf[x].v;
	}
	for(int i=0;i<m;i++)
	{
		if(mark2[i]==true && e[i].i3==1)
			print(i);
	}
}