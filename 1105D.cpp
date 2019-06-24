#include<bits/stdc++.h>
using namespace std;
# define pb push_back
# define mx 1010
# define ff first
# define mp make_pair
# define ss second
deque<pair<pair<int,int>,pair<int,int> > > q;
int visited[mx][mx];
int castle[mx][mx];
int s[15];
char grid[mx][mx];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m;
int ans[20];
vector <pair<int,int>> vec[15];
set <pair<int,int> > s1;
bool isvalid(pair<int,int> p1,int id)
{
	if(p1.ff>=0 && p1.ff<n && p1.ss>=0 && p1.ss<m)
	{
		if(grid[p1.ff][p1.ss]!='#' && (castle[p1.ff][p1.ss]==-1||castle[p1.ff][p1.ss]==id) )
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(castle,-1,sizeof(castle));
	memset(visited,-1,sizeof(visited));
	int p,total=0,ans1=0;
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]!='.' && grid[i][j]!='#')
				{vec[grid[i][j]-'0'].pb({i,j});}
			if(grid[i][j]!='#')
				total++;
		}
	}
	// input taken
	for(int i=1;i<=p;i++)
	{
		for(auto k:vec[i])
			{castle[k.ff][k.ss]=i;ans1++;}
	}
	while(1)
	{
	    int prev=ans1;
		for(int i=1;i<=p;i++)
		{
			for(auto k:vec[i])
				q.push_back({{i,s[i]},k});
			vec[i].clear();
			while(!q.empty())
			{
				pair<int,int> p1=q.front().ff;
				pair<int,int> p2=q.front().ss;
				//cout<<p1.ff<<endl;
				q.pop_front();
				if(visited[p2.ff][p2.ss]!=-1 && p1.ff!=castle[p2.ff][p2.ss])
					continue;
				if(visited[p2.ff][p2.ss]!=-1 && p1.ff==castle[p2.ff][p2.ss] && p1.ss<=visited[p2.ff][p2.ss])
					continue;
				visited[p2.ff][p2.ss]=p1.ss;			
				for(int i=0;i<4;i++)
				{
					pair<int,int> p3={p2.ff+dx[i],p2.ss+dy[i]};
					if(!isvalid(p3,p1.ff))
						continue;
					if(castle[p3.ff][p3.ss]==-1)
						ans1++;
					castle[p3.ff][p3.ss]=p1.ff;
					if(p1.ss==1)
						vec[p1.ff].push_back(p3);
					else
						q.push_back({{p1.ff,p1.ss-1},p3});
				}	
			}				
		}
		//cout<<ans1<<" "<<total<<endl;
		if(ans1==prev)
			break;
	}		

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]!='#')
			{
				ans[castle[i][j]]++;
			}
		}	
	}
	for(int i=1;i<=p;i++)
		cout<<ans[i]<<" ";
	printf("\n");
}