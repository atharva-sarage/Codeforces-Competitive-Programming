#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
# define mx 200005
vector <int> adj[mx];
vector <int> final;
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
    IOS;
	int n,m,count1;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	
	set <int> left;
	set <int> :: iterator itr;
    int visited[n+1];
	for(int i=1;i<=n;i++)
		{left.insert(i);visited[i]=0;}
	for(int i=1;i<=n;i++)
	{
		if(left.find(i)==left.end())
			continue;
	
		queue<int> q;
		q.push(i);
		left.erase(left.find(i));
		count1=1;
		while(!q.empty())
		{
		
		int x=q.front();
		q.pop();
		for(int i=0;i<adj[x].size();i++)
		{
			visited[adj[x][i]]=1;
		}
		vector <int> temp;
		for(itr=left.begin();itr!=left.end();++itr)
		{
		   	if(visited[*itr]==0)
				{q.push(*itr);count1++;temp.push_back(*itr);}
			else
			    visited[*itr]=0;
		}
		for(auto k:temp)
		    left.erase(k);	
		temp.clear();
		}
		final.push_back(count1);	
	}
	
	cout<<final.size()<<endl;
	sort(final.begin(),final.end());
	for(auto i:final)
		cout<<i<<" ";
}