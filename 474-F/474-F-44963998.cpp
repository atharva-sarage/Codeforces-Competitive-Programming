#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define pb push_back
# define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int lo[4*mx],hi[4*mx],s[mx];
vector <int> tree[4*mx];
int gcd[4*mx];
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
	gcd[i0]=__gcd(gcd[i1],gcd[i2]);
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
		tree[i].pb(s[l]);
		gcd[i]=s[l];
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
		pair<vector<int>::iterator,vector<int>::iterator> ip;
		ip=equal_range(tree[i].begin(),tree[i].end(),val);
		return ip.second-ip.first;

	}
	return query(2*i,l,r,val)+query(2*i+1,l,r,val);

}
int query2(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
		return 0;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return gcd[i];
	}
	return __gcd(query2(2*i,l,r),query2(2*i+1,l,r));
}
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	init(1,1,n);
	build(1);
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		int g1=query2(1,l,r);
		cout<<r-l+1-query(1,l,r,g1)<<endl;
	}
}