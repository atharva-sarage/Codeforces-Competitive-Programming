// 10:30 pm
#include<bits/stdc++.h>
#define mx 100005
typedef int long long ll;
using namespace std;
ll flag=0,flag2=0,n,dou=0,single=0,ans=0,odd=0,four=0;
ll col[mx],visited[mx];
ll parent[mx];
vector <ll> vec;
vector<ll>r;
vector<ll> b;
vector <ll> adj[mx];
void  addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
ll count1=0;

void dfs(ll u,ll parent)
{
	
	visited[u]=true;

	if(parent==-1)
		col[u]=1;
	else
		col[u]=1^col[parent];

	if(col[u]==1)		
		r.push_back(u);		
	else
		b.push_back(u);
	
	for(ll i=0;i<adj[u].size();i++)
	{
		if(visited[adj[u][i]])
		{
			if(col[adj[u][i]]==col[u])
			{
				flag=1;  // oddlength cycle found;
				odd++;				
			}
			
		}
		else
			dfs(adj[u][i],u);
	}
}
void DFS()
{
	memset(visited,false,sizeof(visited));
	for(ll i=1;i<=n;i++)
	{
		if(!visited[i])
			{
				dfs(i,-1);
				
				if(r.size()+b.size()>=3)
				{
					flag2=1;
					ll t1=r.size();
					ll t2=b.size();					
					ans+=(t1*(t1-1))/2;
					ans+=(t2*(t2-1))/2;
					
				}
				else
				{
					if(r.size()+b.size()==2)
						dou++;
					else if(r.size()+b.size()==1)
						single++;
				}

				r.clear();
				b.clear();

			}
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	memset(col,2,sizeof(col));	
	
	DFS();
	
	if(flag==1)
	{
		cout<<0<<" "<<1<<endl;
	}
	else if(flag2==1)
	{
		cout<<1<<" "<<ans<<endl;
	}
	else
	{
		if(dou>0)
			cout<<2<<" "<<dou*(n-2)<<endl;
		else
			cout<<3<<" "<<((n)*(n-1)*(n-2))/6<<endl;
	}
	printf("\n");
}