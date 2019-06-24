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
# define mx 200005
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
ll pre[mx],a[mx];
int main()
{
	ll n,total=0;
	cin>>n;
	LineContainer line,linerev;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i],total+=i*a[i];
	ll final=total;
	for(ll i=1;i<=n+1;i++)
	{	
		if(i!=1)
		{
			ll a1=line.query(i-1);
			final=max(final,a1+total-pre[i-1]);
		}
		line.add(a[i],-a[i]*i+pre[i]);
	}
	for(ll i=n;i>=0;i--)
	{
		if(i!=n)
		{
			ll a1=linerev.query(i+1);
			final=max(final,a1+total-pre[i]);
		}
		linerev.add(a[i],-a[i]*i+pre[i-1]);
	}
	cout<<final<<endl;
}