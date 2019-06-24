#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define inf 1e9
int tree[4*mx+1],lo[4*mx+1],hi[4*mx+1],a[mx],delta[4*mx+1];
vector <int> ans[mx+5];
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
void merge(int i0,int i1,int i2)
{
	tree[i0]=min(tree[i1]+delta[i1],tree[i2]+delta[i2]);
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i]=a[l];
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(int i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}
void range_update(int i,int a,int b,int val) // INCREMENT ALL VALUES IN RANGE A TO B
{
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
			delta[i]+=val;
			return ;
		}
	prop(i);
	range_update(2*i,a,b,val);
	range_update(2*i+1,a,b,val);
	merge(i,2*i,2*i+1);
}
int query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
		return INT_MAX;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return tree[i]+delta[i];
	}
	prop(i);
	int minr=query(2*i,l,r);
	int minl=query(2*i+1,l,r);
	merge(i,2*i,2*i+1);
	return min(minr,minl);
}
int main()
{
	int n,m,final=-inf,index1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init(1,1,n);
	build(1);
	vector<pair<int,int>>vec;
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		vec.push_back({l,r});
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<vec.size();j++)
		{
			pair<int,int> k=vec[j];
			if(k.first>i || k.second<i)
				{range_update(1,k.first,k.second,-1);
				ans[i].push_back(j+1);}
		}
		if(a[i]-query(1,1,n)>final)
		{
			index1=i;
			final=a[i]-query(1,1,n);
		}
		for(auto k:vec)
		{
			if(k.first>i || k.second<i)
				range_update(1,k.first,k.second,1);			
		}
	}
	cout<<final<<endl;
	cout<<ans[index1].size()<<endl;
	for(auto k:ans[index1])
		cout<<k<<" ";
	cout<<endl;
}