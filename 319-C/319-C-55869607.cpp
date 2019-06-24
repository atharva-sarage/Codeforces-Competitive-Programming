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
# define inf 1e9
# define mx2 100005
# define mx 100005
struct line
{
	ll m,c;
	ll eval(ll x) { return m*x+c;}
	ld iinter(line l) { return (ld)(c-l.c)/(l.m-m);}
};
deque <line> dq;
ll a[mx],b[mx];
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=1;i<=n;i++)	
		cin>>b[i];
	dq.push_back({b[1],0});
	for(int i=2;i<=n;i++)
	{
		// of all lines take the minimum
		// query for point
		while(dq.size()>=2 && dq.back().eval(a[i])>dq[dq.size()-2].eval(a[i]))
			dq.pop_back();
		line temp={b[i],dq.back().eval(a[i])};
		while(dq.size()>=2 && temp.iinter(dq[0]) < temp.iinter(dq[1]) )
			dq.pop_front();
		dq.push_front(temp);
	}
	cout<<dq[0].c<<endl;	
}