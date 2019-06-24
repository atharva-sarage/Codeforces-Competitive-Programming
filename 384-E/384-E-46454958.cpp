#include<bits/stdc++.h>
# define mx 200005
using namespace std;
vector <int> adj[mx];
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int se[mx],so[mx],eo[mx],ee[mx],table1[mx],table2[mx],l[mx],a[mx];
int te=1,to=1; 

void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void update1(int i,int delta)
{
	while(i<=mx)
	{		
		table1[i]+=delta;
		i+=(i&-i);
	}
}
int sum1(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=table1[i];
		i-=(i&-i);
	}
	return ans;
}
void update2(int i,int delta)
{
	while(i<=mx)
	{		
		table2[i]+=delta;
		i+=(i&-i);
	}
}
int sum2(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=table2[i];
		i-=(i&-i);
	}
	return ans;
}

void dfs(int u,int par,int level)
{
	//cout<<u<<" "<<t<<endl;
	l[u]=level;
	if(level%2==0)
	{se[u]=te++;
	 so[u]=to;}
	else
	{so[u]=to++;
	se[u]=te;}
	for(auto v:adj[u])
	{
		if(v==par)continue;
		dfs(v,u,level+1);
	}	
	if(level%2==0)
	{ee[u]=te;
	eo[u]=to;}
	else
	{eo[u]=to;
	ee[u]=te;}
}
int main()
{
	IOS;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		ee[i]=se[i]=so[i]=eo[i]=-1;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs(1,-1,1);		
	/*for(int i=1;i<=n;i++)
		cout<<se[i]<<" "<<ee[i]<<"  "<<so[i]<<" "<<eo[i]<<" "<<l[i]<<endl;*/
	
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==1) // update subtree rooted at y by z
		{
			int z;
			cin>>z;
			if(l[y]%2==0)
			{   
				update1(se[y],z);
				update1(ee[y],-z);
				if(adj[y].size()>1)
				{
				update2(so[y],-z);
				update2(eo[y],z);
				}
			}
			else
			{
				if(adj[y].size()>1 ||  y==1)
				{
					update1(se[y],-z);
					update1(ee[y],+z);
				}
				
				update2(so[y],z);
				update2(eo[y],-z);
				
			}
		}
		else // give subtree sum rooted at y
		{
			if(l[y]%2==0)
			cout<<sum1(se[y])+a[y]<<endl;
			else
			cout<<sum2(so[y])+a[y]<<endl;
		}
	}
}