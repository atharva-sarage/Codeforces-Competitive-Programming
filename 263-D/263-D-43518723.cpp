#include<bits/stdc++.h>
# define mx 100005
using namespace std;
vector <int> adj[mx];
int mark[mx];
int visited[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}

	stack<int> s;
	queue<int> q;
	s.push(1);
	q.push(1);
	visited[1]=true;
	int flag=1;
	while(flag==1)
	{
		int v=s.top();
		flag=0;
		for(int j=0;j<adj[v].size();j++)
		{
			if(!visited[adj[v][j]])
			{
				visited[adj[v][j]]=1;
				s.push(adj[v][j]);
				q.push(adj[v][j]);
				flag=1;
				break;
			}
		}
		if(flag==0)
			break;
	}
	mark[s.top()]=1;
	for(int i=0;i<adj[s.top()].size();i++)
		mark[adj[s.top()][i]]=1;

	while(mark[q.front()]==0)
		q.pop();
	cout<<q.size()<<endl;
	while(!q.empty())
		{
			cout<<q.front()<<" ";
			q.pop();
		}
	printf("\n");
	
}