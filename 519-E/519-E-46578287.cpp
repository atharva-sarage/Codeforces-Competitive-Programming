#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define pb push_back
# define D 20
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int par[25][mx],depth[mx],parent[mx],sub[mx],temp1,temp2;
vector <int> adj[mx];
void addedge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
int dfs(int u,int p)
{
	int temp=0;
	parent[u]=p;
	par[0][u]=p;
	if(u!=1)
	depth[u]=1+depth[p];
	for(auto v:adj[u])
	{
		if(v==p)continue;	
		temp+=dfs(v,u);
	}
	sub[u]=1+temp;	
	return sub[u];
}
int  walk(int  i,int  k)
{
    for(int  d=0;d<=D;d++)
    {
        if((k & 1<<d )>0)
            i=par[d][i];
    }
    return i;
}

int  lca(int  i,int  j)
{
    if(depth[i]>depth[j])
        i=walk(i,depth[i]-depth[j]);
    if(depth[i]<depth[j])
        j=walk(j,depth[j]-depth[i]);
    temp1=i;temp2=j;   
    if(i==j)
        return i;        
    for(int  d=D;d>=0;d--)
    {
        if(par[d][i]!=par[d][j])
        {
            i=par[d][i];
            j=par[d][j];           
            temp1=i;
            temp2=j;            
        }
    }
   
    return par[0][i];
}
int main()
{
    IOS;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	memset(par,-1,sizeof(par));
	depth[1]=0;
	dfs(1,-1);
	/*for(int i=1;i<=n;i++)
		cout<<sub[i]<<" ";
	printf("\n");*/
	for(int  d=1;d<=D;d++)
       {
            for(int i=1;i<=n;i++)
            { 
                int  mid=par[d-1][i];
                if(mid!=-1)
                par[d][i]=par[d-1][mid];
       		 }
       }

	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int l=lca(x,y);	
		if(x==y)
			{cout<<n<<endl;continue;}
		if((depth[x]+depth[y]-2*depth[l])%2==1)
			{cout<<0<<endl;continue;}
		if(depth[x]==depth[y])
			cout<<n-sub[temp1]-sub[temp2]<<endl;
		else if(depth[x]>depth[y])
			cout<<sub[walk(x,(depth[x]+depth[y]-2*depth[l])/2)]-sub[walk(x,(depth[x]+depth[y]-2*depth[l])/2-1)]<<endl;	
		else 
			cout<<sub[walk(y,(depth[y]+depth[x]-2*depth[l])/2)]-sub[walk(y,(depth[y]+depth[x]-2*depth[l])/2-1)]<<endl;	
			
	}
}