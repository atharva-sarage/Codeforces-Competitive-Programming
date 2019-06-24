/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 500005
bool mark1[mx];
int p[mx];
vector <int> adj[mx];
int main()
{
	unordered_set <int> left;
	IOS;
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		if(y==p[n])
			mark1[x]=true;
	}
	for(int i=n-1;i>=1;i--)
	{
		if(mark1[p[i]]==true)
		{
			int c1=0;
			for(auto k:adj[p[i]])
			{
				if(mark1[k]==false && left.find(k)!=left.end())
					c1++;
			}
			if(c1!=left.size())
				{mark1[p[i]]=false;left.insert(p[i]);}
			else
				ans++;
		}
		else
		{
			left.insert(p[i]);
		}
	}
	cout<<ans<<endl;

}
