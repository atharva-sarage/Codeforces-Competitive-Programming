#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
# define ff first
# define ss second
# define  ll long long
ll dp[2][10];
ll len[2][10];
ll p[100010];
ll pow1(ll a, ll b)
{
    if (a==0)return 0;

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
void reset(ll c)
{
	for(ll i=0;i<10;i++)
		{dp[c][i]=len[c][i]=0;}
}

int main()
{
	string s;
	cin>>s;
	ll n;
	cin>>n;
	stack<pair<ll,string> > st;
	while(n--)
	{
		ll d;char c1,c2;
		string temp1;
		cin>>d;cin>>c1;cin>>c2;
		getline(cin,temp1);
		st.push({d,temp1});
	}
	memset(dp,0,sizeof(dp));
	memset(len,0,sizeof(len));
	for(ll i=0;i<10;i++)
		{dp[0][i]=i;len[0][i]=1;}
	ll c=1;
	while(!st.empty())
	{
		reset(c);
		ll temp=st.top().ff;
		string s=st.top().ss;
		st.pop();
		ll rem=0;
		if(s=="")
			dp[c][temp]=len[c][temp]=0;
		else
		{	
			for(ll i=s.size()-1;i>=0;i--)
			{	
				dp[c][temp]+=(dp[c^1][s[i]-'0']*pow1(10,rem))%mod;
				dp[c][temp]%=mod;
				rem+=len[c^1][s[i]-'0'];
				rem%=mod-1;
			}
			len[c][temp]=rem;
		}
		for(ll i=0;i<10;i++)
		{
			if(i!=temp)
			{
				dp[c][i]=dp[c^1][i];
				len[c][i]=len[c^1][i];
			}
		}
		c=c^1;
	}
	ll ans=0;
	ll rem=0;
	for(ll i=s.length()-1;i>=0;i--)
	{
		ans+=dp[c^1][s[i]-'0']*pow1(10,rem);
		rem+=len[c^1][s[i]-'0'];
		rem%=mod-1;
		ans%=mod;
	}
	cout<<ans<<endl;
}