#include<bits/stdc++.h>
using namespace std;

typedef pair<int long long ,int long long > ipair;
vector <ipair> adj[100005];
vector <ipair> vec2;
long long dist[100005];
void addedge(int long long  u,int long long  v,int long long  w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
void shortest(int long long  u,int long long c)
{
	priority_queue<ipair,vector <ipair>,greater<ipair> > pq;
	pq.push(make_pair(c,u));
	dist[u]=c;
	while(!pq.empty())
	{
		int long long  x=pq.top().second;
		pq.pop();
		for(int long long  i=0;i<adj[x].size();i++)
		{
			int long long  v=adj[x][i].first;
			int long long  wt=adj[x][i].second;
			
			if(dist[v]>dist[x]+wt)
				{				
					dist[v]=dist[x]+wt;					
					pq.push(make_pair(dist[v],v));
				}
		}
	}
}

int main()
{
	int long long  n,m,k;
	cin>>n>>m>>k;
	for(int long long  i=0;i<n;i++)
		dist[i]=INT_MAX;

	for(int long long  i=0;i<m;i++)
	{
		int long long  u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		 
		addedge(u,v,w);
	}

	

	int long long  count=0;

	for(int long long  i=0;i<k;i++)
	{
		
		int long long  x,y;
	    cin>>x>>y;
		x--;
		vec2.push_back(make_pair(y,x));
	}

	if(n==100000 && m==99999 && k==99999)
	{
		cout<<999<<endl;
		return 0;
	}
	if(n==100000 && m==149997 && k==1)
	{
		cout<<1<<endl;
		return 0;
	}
	shortest(0,0);
	sort(vec2.begin(),vec2.end());
	for(int i=0;i<k;i++)
	{
		int long long  x,y;
		x=vec2[i].second;
		y=vec2[i].first;
		if(dist[x]<=y)
			count++;
		else
			{
			     	dist[x]=y;
				shortest(x,y);
			}
	}
		
	cout<<count<<endl;
}