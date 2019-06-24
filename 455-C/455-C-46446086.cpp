#include<bits/stdc++.h>
using namespace std;
# define mx 300005
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
vector<int> adj[mx];
vector <int> discover;
int visited[mx],dia[mx],ranks[mx],parent[mx];
int n,maxl,index1;
int find(int a)
    {
    	if(a==parent[a])
    		return a;
    	int x=find(parent[a]);
    	parent[a]=x;    	
    	return x;
    }
     
void unite(int a, int b)
    {
    	int x=find(a),y=find(b);
    	
    	if(x==y)	return ;
    	
    	if(ranks[x]>ranks[y])
    		swap(x,y);
    	parent[x]=y;
    	ranks[y]+=ranks[x];
    	return ;
    	
    }
void dfs(int u,int par,int level)
{
	visited[u]=true;	
	discover.push_back(u);
	if(maxl<level)
	{
		maxl=level;
		index1=u;
	}
	for(auto k:adj[u])
	{
		if(k==par)continue;		
		dfs(k,u,level+1);
	}
}

void DFS()
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
			continue;

		maxl=0;	index1=i;
		dfs(i,-1,0);
		for(auto k:discover)
			visited[k]=false;
		maxl=0;	
		dfs(index1,-1,0);
		dia[find(i)]=maxl;
		discover.clear();
	}
}
int main()
{
	IOS;
	int m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		ranks[i]=1;
		parent[i]=i;
		visited[i]=false;
		dia[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		unite(x,y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS();	
	while(q--)
	{
		int type,x,y;
		cin>>type;
		if(type==1)
		{
			cin>>x;
			cout<<dia[find(x)]<<endl;
		}
		else
		{
			cin>>x>>y;
			if(find(x)==find(y))
				continue;
			int temp1=dia[find(x)];
			int temp2=dia[find(y)];			
			unite(x,y);
			dia[find(x)]=max(temp1,temp2);
			dia[find(x)]=max(dia[find(x)],1+(temp1+1)/2+(temp2+1)/2);
			//cout<<find(x)<<" "<<x<<" "<<dia[find(x)]<<endl;
		}
	}


}