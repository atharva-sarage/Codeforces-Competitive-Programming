#include<bits/stdc++.h>
using namespace std;
# define inf 1e9
# define mx 500005
# define ff first
# define ss second
# define pb push_back
int lo[4*mx+1],hi[4*mx+1],a[mx],ans[mx];
pair<int,int> tree[4*mx+1];
vector <pair<int,int>> vec[mx+5];
bool comp(pair<pair<int,int>,int > p1,pair<pair<int,int>,int > p2)
{
	return p1.ff.ss<p2.ff.ss;
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
pair<int,int> merge(pair<int,int> i1,pair<int,int> i2)
{
	pair<int,int> p1;
	if(i1.ff<i2.ff)
		return i1;
	return i2;
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i].ff=inf;
		tree[i].ss=l;
		return;
	}
	build(2*i);
	build(2*i+1);
	pair<int,int> p2=merge(tree[2*i],tree[2*i+1]);
	tree[i].ff=p2.ff;
	tree[i].ss=p2.ss;
}
void update(int i,int pos,int val )
{
	int l=lo[i];
	int r=hi[i];
	if(lo[i]==hi[i] && lo[i]==pos)
	{
		tree[i].ff=val;
		return;
	}
	int m=(l+r)/2;
	if(pos<=m)
		update(2*i,pos,val);
	else
		update(2*i+1,pos,val);

	pair<int,int> p2=merge(tree[2*i],tree[2*i+1]);
	tree[i].ff=p2.ff;
	tree[i].ss=p2.ss;
}
pair<int,int> query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
		return {inf,-1};
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return tree[i];
	}
	return merge(query(2*i,l,r),query(2*i+1,l,r));

}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&t);
	pair<pair<int,int>,int> q[mx];
	for(int i=0;i<t;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		q[i]={{l,r},i};
		vec[r].pb({l,i});
	}
	init(1,1,n);
	build(1);
	sort(q,q+t,comp);
	int j=0;
	map<int,int> m;
	map<int,int> m2;
	for(int i=1;i<=n;i++)
	{
		if(!m[a[i]])
		{
			update(1,i,1);
			m[a[i]]=1;
			m2[a[i]]=i;
		}
		else
		{
			update(1,m2[a[i]],inf);
			update(1,i,m2[a[i]]+1);
			m[a[i]]=m2[a[i]]+1;
			m2[a[i]]=i;
		}
		for(auto k:vec[i])
		{
			//cout<<query(1,k.ff,i).ff<<" "<<query(1,k.ff,i).ss<<" "<<k.ff<<endl;
			if(query(1,k.ff,i).ff<=k.ff)
				ans[k.ss]=a[query(1,k.ff,i).ss];
			else
				ans[k.ss]=0;
		}
	}
	for(int i=0;i<t;i++)
		printf("%d\n",ans[i] );
}