#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1(ll k)
{
	if(k%2==0)
		return k/2 * (k-1);
	else
		return (k-1)/2 * k;
}
ll f(ll n,ll k)
{
	return n-k+min(n-k,c1(k));
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		ll low=1;
		ll high=x;

		while(high>=low)
		{
			ll mid=low+(high-low)/2;
			if(f(x,mid)>f(x,mid+1))
				high=mid-1;
			else
				low=mid+1;
		}
		//cout<<low<<endl;
		cout<<f(x,low)<<endl;

	}
}