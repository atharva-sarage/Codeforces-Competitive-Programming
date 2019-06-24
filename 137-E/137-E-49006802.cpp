#include<bits/stdc++.h>
using namespace std;
# define mx 600500
# define inf 1e9
# define offset 200001
// -2*10^5 to 4*10^5
int tree[4*mx+1],lo[4*mx+1],hi[4*mx+1],a[mx];
bool mark[mx];
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
int merge(int i1,int i2)
{
	return min(i1,i2);
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i]=inf;
		return;
	}
	build(2*i);
	build(2*i+1);
	tree[i]=merge(tree[2*i],tree[2*i+1]);
}
void update(int i,int pos,int val )
{
	int l=lo[i];
	int r=hi[i];
	if(lo[i]==hi[i] && lo[i]==pos)
	{
		tree[i]=val;
		return;
	}
	int m=(l+r)/2;
	if(pos<=m)
		update(2*i,pos,val);
	else
		update(2*i+1,pos,val);

	tree[i]=merge(tree[2*i],tree[2*i+1]);
}
int query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
		return inf;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return tree[i];
	}
	return merge(query(2*i,l,r),query(2*i+1,l,r));

}
bool comp(char a)
{
	string s="aeiouAEIOU";
	for(auto k:s)
		if(k==a)
			return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ans=-inf,prev=0,count1;
	init(1,1,600001);
	build(1);
	string str;
	cin>>str;
	update(1,offset,0);
	mark[offset]=true;
	for(int i=0;i<str.length();i++)
	{
		if(comp(str[i]))
			prev-=1;
		else
			prev+=2;
		if(!mark[prev+offset])
			{update(1,prev+offset,i+1);mark[prev+offset]=true;}
		int temp=query(1,1,offset+prev)+1;
		temp=(i+1)-temp+1;
		if(ans<temp)
			{ans=temp;count1=1;}
		else if(ans==temp)
			count1++;
	}
	if(ans<=0)
		cout<<"No solution"<<"\n";
	else
		cout<<ans<<" "<<count1<<"\n";

}