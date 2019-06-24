#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll digit(ll n)
{
	ll ans=0;
	while(n>=1)
	{
		ans++;
		n/=10;
	}
	return ans;
}
int main()
{
	ll t[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};
	ll s[]={0,4,49,499,4999,49999,499999,4999999,49999999,499999999,4999999999};
	ll r1[]={0,0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	ll r,l;
	cin>>l>>r;
	ll c1=digit(l);
	ll c2=digit(r);
	if(c1!=c2)
	{
		c1=max(c1,c2);
		l=r1[c1];
	}
	
		int dig=c1;
		if(l>s[dig])
			cout<<l*(t[dig]-l)<<endl;
		else if(r<s[dig])
			cout<<r*(t[dig]-r)<<endl;
		else
			cout<<s[dig]*(t[dig]-s[dig])<<endl;
	
}