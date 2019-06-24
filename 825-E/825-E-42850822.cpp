#include<bits/stdc++.h>
# define mx 100005
using namespace std;
vector <int> adj[mx];
vector <int> vec;
int a[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
}
int outdeg[mx],n;
void topo()
{
	priority_queue <int> q; 
	for(int i=0;i<n;i++)
	{
		if(outdeg[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vec.push_back(u+1);
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			outdeg[v]--;
			if(outdeg[v]==0)
				q.push(v);
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		outdeg[x]++;
		addedge(y,x);
		
	}
	topo();

	for(int i=0;i<n;i++)
	{
		a[vec[i]]=n-i;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	printf("\n");

}