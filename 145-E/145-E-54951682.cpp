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
# define mx 1000005
struct data
{
	int f,s,a1,a2;
};
int lo[4*mx+1],hi[4*mx+1];
string a;
bool lazy_node[4*mx];
data tree[4*mx+1];
void print(int i,data a)
{
	cout<<i<<": "<<a.f<<" "<<a.s<<" "<<a.a1<<" "<<a.a2<<"\n";
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
void merge(int i0,int i1,int i2)
{
	//tree[i0]=min(tree[i1]+lazy_node[i1],tree[i2]+lazy_node[i2]);
	data temp1=tree[i1];
	data temp2=tree[i2];
	if(lazy_node[i1])
	{
		swap(temp1.f,temp1.s);
		swap(temp1.a1,temp1.a2);
	}
	if(lazy_node[i2])
	{
		swap(temp2.f,temp2.s);
		swap(temp2.a1,temp2.a2);
	}
	//print(i1,temp1);
	//print(i2,temp2);
	tree[i0].f=temp1.f+temp2.f;
	tree[i0].s=temp1.s+temp2.s;
	tree[i0].a1=max(temp1.f+max(temp2.s,temp2.a1),temp1.a1+temp2.s);
	tree[i0].a2=max(temp1.s+max(temp2.f,temp2.a2),temp1.a2+temp2.f);
	//print(i0,tree[i0]);
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		if(a[l]-'0'==4)
			tree[i]={1,0,1,0};
		else
			tree[i]={0,1,0,1};
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(int i)
{
	lazy_node[2*i]^=lazy_node[i];
	lazy_node[2*i+1]^=lazy_node[i];
	lazy_node[i]=false;
}
void increment(int i,int a,int b)
{
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
			lazy_node[i]^=true;
			return ;
		}
	prop(i);
	increment(2*i,a,b);
	increment(2*i+1,a,b);
	merge(i,2*i,2*i+1);
}
int main()
{
	IOS;
	int n,q;
	cin>>n>>q;
	string str="$";
	cin>>a;
	a=str+a;
	init(1,1,n);
	build(1);
	while(q--)
	{
		string str;
		cin>>str;
		if(str=="count")
		{
			if(lazy_node[1])
				cout<<max({tree[1].f,tree[1].s,tree[1].a2})<<"\n";
			else
				cout<<max({tree[1].f,tree[1].a1,tree[1].s})<<"\n";
		}
		else
		{
			int l,r;
			cin>>l>>r;
			increment(1,l,r);			
		}
	}
	
}