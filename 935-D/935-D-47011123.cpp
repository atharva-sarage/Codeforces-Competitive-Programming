#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mod 1000000007
typedef long long ll;
ll a[mx],b[mx],suff1[mx],suff2[mx];
ll n,m;
ll pow1(ll a, ll b) 
{
  if (a==0)
    return 0LL;

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
ll solve(ll i)
{
	if(i>=n+1)
		return 0LL;
	if(a[i]==0 && b[i]==0)
	{
		ll temp1=((((m-1)*m)/2LL)%mod);
		ll temp2=((pow1(m,suff1[i]-1)*pow1(m,suff2[i]-1))%mod)%mod;
		return ((temp1*temp2)%mod+(m*solve(i+1))%mod)%mod;
	}
	else if(a[i]==0 && b[i]!=0)
	{
		ll temp1=((pow1(m,suff1[i]-1)*pow1(m,suff2[i]))%mod)%mod;
		ll temp2=(m-b[i])%mod;
		return (solve(i+1)%mod+(temp2*temp1)%mod)%mod;
	}
	else if(b[i]==0 && a[i]!=0)
	{
		ll temp1=((pow1(m,suff1[i])*pow1(m,suff2[i]-1))%mod)%mod;
		return (solve(i+1)%mod+((a[i]-1)*temp1)%mod)%mod;
	}
	else
	{
		if(a[i]<b[i])return 0LL;
		else if(a[i]>b[i])return (pow1(m,suff1[i])*pow1(m,suff2[i]))%mod;
		else solve(i+1)%mod;
	}
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	if(a[n]==0)
		suff1[n]=1;
	else
		suff1[n]=0;

	if(b[n]==0)
		suff2[n]=1;
	else
		suff2[n]=0;


	for(ll i=n-1;i>=1;i--)
	{
		suff1[i]=suff1[i+1];
		suff2[i]=suff2[i+1];
		if(a[i]==0)
			suff1[i]++;
		if(b[i]==0)
			suff2[i]++;				
	}

	ll num=solve(1);
	ll den=pow1(m,suff1[1]+suff2[1]);
	cout<<(num*pow1(den,mod-2))%mod<<endl;

}