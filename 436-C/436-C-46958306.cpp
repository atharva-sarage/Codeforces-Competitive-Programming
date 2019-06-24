#include<bits/stdc++.h>
using namespace std;
# define mx 1005
# define pb push_back
# define mp make_pair
# define ff first
# define ss second
# define ipair pair<int,int>
vector<pair<int,ipair>> edge;
char grid[mx][15][15];
int wt[mx][mx],ranks[mx],parent[mx];
bool mark[mx],mark2[mx];
int n,m,k,w;
int find(int a)
    {
    	if(a==parent[a])
    		return a;
    	int x=find(parent[a]);
    	parent[a]=x;    	
    	return x;
    }
     
void merge(int a, int b)
    {
    	int x=find(a),y=find(b);    	
    	if(x==y)return ;    	
    	if(ranks[x]>ranks[y])
    		swap(x,y);    	
    	parent[x]=y;
    	ranks[y]+=ranks[x];
    	return ;    	
    }
void pre()
{
	for(int i=1;i<k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			for(int l=0;l<n;l++)
			{
				for(int p=0;p<m;p++)
				{
					if(grid[i][l][p]!=grid[j][l][p])
						wt[i][j]++;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k>>w;
	for(int i=1;i<=k;i++)
	{
		ranks[i]=1;
		parent[i]=i;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				cin>>grid[i][j][k];				
			}
		}
	}
	pre();
	for(int i=1;i<k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			edge.pb(mp(min(n*m,w*wt[i][j]),mp(i,j)));
		}
	}
	sort(edge.begin(),edge.end());
	int ans=0,flag=0;
	deque<ipair>final;
	for(auto k:edge)
	{
		if(k.ff==n*m)break;
		if(find(k.ss.ff)==find(k.ss.ss))
			continue;
		final.pb(mp(k.ss.ff,k.ss.ss));
		ans+=k.ff;
		merge(k.ss.ff,k.ss.ss);
	}
	for(int i=1;i<=k;i++)
	{
		if(mark[find(i)])continue;
		final.push_front(mp(find(i),0));
		ans+=n*m;mark[find(i)]=true;
	}
	cout<<ans<<endl;
	mark2[0]=true;
	while(!final.empty())
		{
			ipair l=final.front();
			if(mark2[l.ss]==false)
					swap(l.ff,l.ss);
			if(mark2[l.ff]==false && mark2[l.ss]==false)
			{
				final.pb(mp(l.ff,l.ss));
				final.pop_front();
				continue;
			}
			
			cout<<l.ff<<" "<<l.ss<<endl;
			mark2[l.ff]=true;
			mark2[l.ss]=true;
			final.pop_front();

		}

}