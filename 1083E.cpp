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
# define ld long double
# define db double
# define inf 1e9
# define mx2 100005
# define mx 2000005
struct rect
{
	ll x,y,a;
};
bool cmp(const rect&a,const rect&b) {return a.x<b.x;}
struct line
{
	ll m,c;
	ll eval(ll x) { return m*x+c;}
	ld iinter(line l) { return (ld)(c-l.c)/(l.m-m);}
};
rect r[mx];
deque<line>dq;
int main()
{
	dq.push_back({0,0});
	IOS;
	ll n,final=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		r[i]={x,y,z};
	}
	sort(r+1,r+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		ll x,y,a;
		tie(x,y,a)=make_tuple(r[i].x,r[i].y,r[i].a);
		// first query for point
		while(dq.size()>=2 && dq.back().eval(y)<dq[dq.size()-2].eval(y))
			dq.pop_back();
		line temp={-x,dq.back().c+y*dq.back().m+x*y-a};
		final=max(final,temp.c);
		while(dq.size()>=2 && temp.iinter(dq[0])>temp.iinter(dq[1]))
			dq.pop_front();

		// add line
		dq.push_front(temp);
	}
	cout<<final<<endl;
	
}