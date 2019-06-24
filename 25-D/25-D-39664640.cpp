#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
vector <int> adj[1005];
vector <ipair> del;
int parent[1005],rank1[1005];

void addedge(int u,int v)
{
	adj[u].push_back(v);
	//adj[v] .push_back(u);
}

int find(int e)
{
	if(parent[e]==e)
		return e;
	return parent[e]=find(parent[e]);
}
bool merge(int e1,int e2)
{
	int p1=find(e1);
	int p2=find(e2);

	if(p1==p2)
		return 0;
	if(rank1[p1]==rank1[p2])
		rank1[p1]++;
	else if(rank1[p2]>rank1[p1])
		swap(p1,p2);

	parent[p2]=p1;
	return 1;
}
int main()
{
	memset(rank1,0,sizeof(rank1));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		parent[i]=i;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			if(!merge(i,adj[i][j]))
				del.push_back(make_pair(i,adj[i][j]));
		}
	}

	cout<<del.size()<<endl;

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(merge(i,j))
			{
				ipair p=del.front();
				cout<<p.first+1<<" "<<p.second+1<<" "<<i+1<<" "<<j+1<<endl;
				del.erase(del.begin());
			}
		}
	}
}