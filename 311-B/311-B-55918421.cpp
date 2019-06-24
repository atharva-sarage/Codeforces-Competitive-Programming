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
# define mx2 100005
# define mx 100005
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
ll dp[mx][105],pre[mx],d[mx],pre2[mx],c[mx];
LineContainer line[105];
int main()
{
	ll n,m,p;
	cin>>n>>m>>p;
	for(ll i=2;i<=n;i++)
		{cin>>d[i];pre2[i]=pre2[i-1]+d[i];}
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		c[i]=y-pre2[x];
	}
	sort(c+1,c+m+1);
	for(ll i=1;i<=m;i++)
		pre[i]=pre[i-1]+c[i];

	line[0].add(0,0);
	for(ll j=1;j<=p;j++)
	{
		for(ll i=1;i<=m;i++)
		{
			dp[i][j]=line[j-1].query(-c[i])+pre[i]+i*(-c[i]);
			line[j].add(-i,dp[i][j]-pre[i]);
		}
	}
	cout<<-dp[m][p]<<endl;
}