#include<bits/stdc++.h>
using namespace std;
# define mx 1000005
# define mp make_pair
# define pb push_back
# define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int a[mx],n,ll[mx],rr[mx],lo[4*mx],hi[4*mx];
vector <int> tree[4*mx];
map <int,int> m1,m2;
void pre()
{
	for(int i=1;i<=n;i++)
	{
		if(m1.find(a[i])==m1.end())
			{m1.insert(mp(a[i],1));
			ll[i]=1;}
		else
			ll[i]=++m1[a[i]];
	}
	for(int i=n;i>0;i--)
	{
		if(m2.find(a[i])==m2.end())
		{
			m2.insert(mp(a[i],1));
			rr[i]=1;
		}
		else
		{
			rr[i]=++m2[a[i]];
		}
	}
}
void init(int i,int a,int b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}
int merge(int i0,int i1,int i2)
{
	int s1=tree[i1].size();
	int s2=tree[i2].size();
	int i=0,j=0;
	while(i<s1 && j<s2)
	{
		if(tree[i1][i]<=tree[i2][j])
			tree[i0].pb(tree[i1][i++]);
		else if(tree[i1][i]>tree[i2][j])
			tree[i0].pb(tree[i2][j++]);
	}
	while(i<s1)
	{
		tree[i0].pb(tree[i1][i++]);
	}
	while(j<s2)
	{
		tree[i0].pb(tree[i2][j++]);	
	}
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i].pb(rr[l]);
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
int query(int i,int l,int r,int val)
{
	if(r<lo[i] || hi[i]<l)
		{
		return 0;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return upper_bound(tree[i].begin(),tree[i].end(),val)-tree[i].begin();
	}
	return query(2*i,l,r,val)+query(2*i+1,l,r,val);

}
int main()
{
	IOS;
	long long final=0LL;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	pre();
	init(1,1,n);
	build(1);	
	for(int i=1;i<n;i++)
	{
		final+=query(1,i+1,n,ll[i]-1);
	}
	cout<<final<<endl;
}