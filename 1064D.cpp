#include<bits/stdc++.h>
using namespace std;
# define mx 2005
typedef int long long  ll;
int n,m;
char grid[mx][mx];
int visited[mx][mx];
struct state
{
	int r,c,x,y;
};
int isvalid(int r1,int c1)
{
	if(r1>=0 && r1<n && c1>=0 && c1<m)
	{
		if(grid[r1][c1]!='*')
		return 1;
		return 0;
	}
	return 0;
}
void bfs(int r,int c,int x,int y)
{
	visited[r][c]=true;	
	deque<struct state> q;
	struct state s1={r,c,x,y};
	q.push_back(s1);
	while(!q.empty())
	{
		struct state s2=q.front();
		q.pop_front();
		if(s2.x>0 && !visited[s2.r][s2.c-1] && isvalid(s2.r,s2.c-1))
		{
		struct state s3={s2.r,s2.c-1,s2.x-1,s2.y};
		visited[s2.r][s2.c-1]=true;
		q.push_back(s3);
		}
		if(s2.y>0 && !visited[s2.r][s2.c+1] && isvalid(s2.r,s2.c+1))
		{
		struct state s3={s2.r,s2.c+1,s2.x,s2.y-1};
		visited[s2.r][s2.c+1]=true;
		q.push_back(s3);
		}
		if(!visited[s2.r+1][s2.c] && isvalid(s2.r+1,s2.c))
		{
		struct state s3={s2.r+1,s2.c,s2.x,s2.y};
		visited[s2.r+1][s2.c]=true;
		q.push_front(s3);
		}
		if(!visited[s2.r-1][s2.c] && isvalid(s2.r-1,s2.c))
		{
		struct state s3={s2.r-1,s2.c,s2.x,s2.y};
		visited[s2.r-1][s2.c]=true;
		q.push_front(s3);
		}
	}	
	
}
int main()
{
	memset(visited,false,sizeof(visited));
	int r,c,x,y,c1=0;
	cin>>n>>m;
	cin>>r>>c;
	r--;c--;
	cin>>x>>y;
	for(int i=0;i<n;i++)
		cin>>grid[i];
	bfs(r,c,x,y);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visited[i][j]==true)
			{
				c1++;
			}
		}
	}
	cout<<c1<<endl;
}