#include<bits/stdc++.h>
typedef int long long ll;
using namespace std;
ll find(ll x)
{
	ll i;
	for(i=1;i*i<=1e18;i++)
	{	
		if(((i*(i+1))/2) <x && (((i+1)*(i+2))/2) >=x)
			break;
	}
	return i+1;
}
int main()
{
	ll x,ans;
	cin>>x;
	if(x==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(x<0)
		x=x*-1LL;
	ans=find(x);	
	if((ans*(ans+1))/2 %2 == x%2)
		cout<<ans<<endl;
	else 
	{
		if(ans%2==0)
			cout<<ans+1<<endl;
		else
			cout<<ans+2<<endl;
	}
}