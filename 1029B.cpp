#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	ll n,final1=1;
	cin>>n;
	ll a[200005];
	ll final[200005];
	ll ans[200005];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	if(n==1)
		cout<<1<<endl;
	else
	{
	for(ll i=0;i<n-1;i++)
	{
		ll it=upper_bound(a,a+n,2*a[i])-a;
		ans[i]=it-1;
	}
	
	
	final[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		if(i==ans[i])
		{
			final[i]=1;
			continue;
		}
		final[i]=final[ans[i]]+ans[i]-i;
		final1=max(final1,final[i]);
	}
	cout<<final1<<endl;
}
}