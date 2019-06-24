// easy peasy lemon squeezy
#include<bits/stdc++.h>
using namespace std;
# define mx 200005
# define ff first
# define ss second
# define pb push_back
int parent[mx],ranks[mx];
vector <pair<int,pair<int,int> > > edge;
vector <int> vec;
int find(int a)
{
	if(a==parent[a])
		return a;
	int x=find(parent[a]);parent[a]=x;return x;
} 
void merge(int a, int b)
{
	int x=find(a),y=find(b);	
	if(x==y)	return ;	
	if(ranks[x]>ranks[y])swap(x,y);
	parent[x]=y;ranks[y]+=ranks[x];return ;
	
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{parent[i]=i;ranks[i]=1;}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({w,{u,v}});
	}
	sort(edge.begin(),edge.end());
	for(int i=0;i<edge.size();i++)
	{
		if(edge[i].ff==edge[i+1].ff)
		{
			if(find(edge[i].ss.ff)!=find(edge[i].ss.ss))
				vec.pb(i);
		}
		else
		{
			if(find(edge[i].ss.ff)!=find(edge[i].ss.ss))
				vec.pb(i);
			// evaluate
			for(auto k:vec)
			{
				if(find(edge[k].ss.ff)==find(edge[k].ss.ss))
					ans++;
				else
					merge(edge[k].ss.ff,edge[k].ss.ss);
			}
			vec.clear();
		}
	}
	cout<<ans<<endl;

}