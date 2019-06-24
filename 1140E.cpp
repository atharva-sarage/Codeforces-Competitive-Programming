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
# define mod  998244353
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 200005
ll n,k;
ll dp[mx][2],a[mx];
vector <ll> vec3,vec4,vec2,vec1;
ll pow1(ll a, ll b)
{
    if (a==0)
        return 0;
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x%mod;
}
ll solve(ll len,ll t)
{
	// base case
	if(t==0 && len==0)
		return 0;
	if(t==0 && len==1)
		return k-1;
	if(t==0 && len==2)
		return ((k-1)*(k-2))%mod;
	if(t==1 && len==0)
		return 1;
	if(t==1 && len==1)
		return k-2;
	if(t==1 && len==2)
		return ((k-1)*(k-2)+1)%mod;

	ll &w=dp[len][t];
	if(w!=-1)
		return w;
	if(t==0)
	{
		if(len%2==1)
		{
			w=(solve(len/2,0)*solve(len/2,0))%mod;
			w=(w+(((k-1)*(solve(len/2,1))%mod)*solve(len/2,1))%mod)%mod;
		}
		else
		{
			w=(((((2LL*(k-1))%mod)*solve(len/2-1,0))%mod)*solve(len/2-1,1))%mod;
			w=(w+(((((k-1)*(k-2))%mod*solve(len/2-1,1))%mod)*solve(len/2-1,1))%mod)%mod; // check
			w%=mod;
		}
	}
	else
	{
		if(len%2==1)
		{
			w=(((2LL*(solve(len/2,0))%mod)*solve(len/2,1)))%mod;
			w=(w+((((k-2)*solve(len/2,1))%mod)*solve(len/2,1))%mod)%mod;
			w%=mod;
		}
		else
		{
			w=((solve(len/2-1,0))%mod*solve(len/2-1,0))%mod;
			w=(w+(((((2LL*(k-2))%mod)*solve(len/2-1,0))%mod)*solve(len/2-1,1))%mod)%mod;
			w=(w+((((((k-1)*(k-2)+1)%mod)*solve(len/2-1,1))%mod)*solve(len/2-1,1))%mod)%mod;
		}
	}
		return w%mod;
}
bool check()
{
	for(int i=1;i<vec1.size();i++)
	{
		if(vec1[i]!=-1 && vec1[i]==vec1[i-1])
			return false;
	}
	for(int i=1;i<vec2.size();i++)
	{
		if(vec2[i]!=-1 && vec2[i]==vec2[i-1])
			return false;
	}
	return true;
}
int main()
{
	memset(dp,-1,sizeof(dp));	
	IOS;
	cin>>n>>k;
	ll ans=1;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		a[i]=x;
		if(i%2==0)
		{
			if(x!=-1)
				vec3.pb(i);
			vec1.pb(x);
		}
		else if(i%2==1)
		{
			if(x!=-1)
				vec4.pb(i);
			vec2.pb(x);
		}
	}
	if(!check())
	{
		cout<<0<<endl;
		return 0;
	}
	if(vec3.empty())
	{
		
		ans=(pow1(k-1,vec1.size()-1)*k)%mod;
		goto l;
	}
	// handle starting case
	ans=(ans*pow1(k-1,vec3[0]/2-1))%mod;
	for(ll i=1;i<vec3.size();i++)
	{
		if(vec3[i]!=vec3[i-1]+1)
		{
			// some -1 here
			if(a[vec3[i]]==a[vec3[i-1]])
				ans=(ans*solve((vec3[i]-vec3[i-1])/2-1,0)%mod)%mod;
			else
				ans=(ans*solve((vec3[i]-vec3[i-1])/2-1,1)%mod)%mod;
		}
	}

	ans=(ans*pow1(k-1,vec1.size()-vec3.back()/2))%mod;
	
	l:
	if(vec4.empty())
	{
		ans=((ans*(pow1(k-1,vec2.size()-1))%mod*k)%mod)%mod;
		ans%=mod;
		goto l1;

	}
	ans=(ans*pow1(k-1,(vec4[0]-1)/2))%mod;
	ans%=mod;
	for(ll i=1;i<vec4.size();i++)
	{
		if(vec4[i]!=vec4[i-1]+2)
		{
			// some -1 here
			if(a[vec4[i]]==a[vec4[i-1]])
				ans=(ans*solve((vec4[i]-vec4[i-1])/2-1,0)%mod)%mod;
			else
				ans=(ans*solve((vec4[i]-vec4[i-1])/2-1,1)%mod)%mod;
		}
	}
	
	//handle ending case
	ans=(ans*pow1(k-1,vec2.size()-(vec4.back()+1)/2))%mod;
	l1:
	cout<<ans<<endl;


}
