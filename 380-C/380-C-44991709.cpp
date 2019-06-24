#include<bits/stdc++.h>
using namespace std;
# define mx 1000005
struct node
{
	int c,o,w;
};
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int lo[4*mx+1],hi[4*mx+1],n;
struct node tree[4*mx+1],a[mx];
string str;
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
struct node merge(struct node i1,struct node i2)
{
	struct node i0;
	i0.w=i1.w+i2.w+min(i1.o,i2.c);
	i0.o=i1.o+i2.o-min(i1.o,i2.c);
	i0.c=i1.c+i2.c-min(i1.o,i2.c);
	return i0;
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
	tree[i]=merge(tree[2*i],tree[2*i+1]);
}
struct node query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
			struct node dummy={0,0,0};
		return dummy;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return tree[i];
	}
	return merge(query(2*i,l,r),query(2*i+1,l,r));

}
int main()
{
	IOS;
	cin>>str;
	n=str.length();
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='(')
			{a[i].o=1;
			a[i].c=0;
			a[i].w=0;}
		else
			{a[i].o=0;
			a[i].c=1;
			a[i].w=0;}
	}
	init(1,1,n);
	build(1);
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(1,l,r).w*2<<endl;
	}
}