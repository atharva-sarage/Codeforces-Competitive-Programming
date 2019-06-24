#include<bits/stdc++.h>
# define pb push_back
# define mp make_pair
# define ff first
# define ss second
# define mod 1000000007
using namespace std;
typedef int long long ll;
int main()
{
	string str,str2;
	cin>>str;
	for(ll i=0;i<str.length();i++)
	{
		if(str[i]=='a' || str[i]=='b')
			str2+=str[i];
	}
	if(str2.length()==1 && str2[0]=='a')
	{
		cout<<1<<endl;
		return 0;
	}
	vector <pair<char,ll> > vec;
	ll n=str2.length();
	for(ll i=0;i<n-1;i++)
	{
		ll c=1;
		while(str2[i]==str2[i+1] && i<n)
		{
			c++;i++;
		}
		//cout<<str2[i]<<" "<<c<<endl;
		vec.pb(mp(str2[i],c));
	}
	if(n>1 && str2[n-1]=='a' && str2[n-2]=='b')
	{
		vec.pb(mp('a',1));
	}
	ll final=1;
	for(auto k:vec)
	{
		if(k.ff=='a')
		{
			final=(final*(1LL+k.ss))%mod;
			final%=mod;
		}
	}
	cout<<(final-1+mod)%mod<<endl;
}
