#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mp make_pair
# define ff first
# define ss second
int m[mx+10],m2[mx+10];
vector<int>vec;
vector <int> adj[450];
int a[mx];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m1;
	cin>>n>>m1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx)continue;
		m[a[i]]++;
	}
	for(int i=1;i<mx;i++)
	{
		if(i<=m[i])
			vec.push_back(i);
	}
	for(int j=0;j<vec.size();j++)
	{
		for(int i=1;i<=n;i++)
		{
			int k=vec[j];
			if(a[i]==k)
			{
				m2[k]=j;
				adj[j].push_back(i);
			}
		}
	}
	for(int i=0;i<m1;i++)
	{
		int l,r,c1=0;
		cin>>l>>r;
		for(auto k:vec)
		{
			int k1=m2[k];
			int r1=upper_bound(adj[k1].begin(),adj[k1].end(),r)-adj[k1].begin();
			int l1=lower_bound(adj[k1].begin(),adj[k1].end(),l)-adj[k1].begin();
			if(r1-l1==k)
				c1++;
		}
		cout<<c1<<endl;
	}
}