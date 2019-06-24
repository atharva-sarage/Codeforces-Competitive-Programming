#include<bits/stdc++.h>
typedef int long long ll;
using namespace std;
int main()
{
	ll k,d,a,b,t,ans;
	cin>>d>>k>>a>>b>>t;
	if(k>=d)
	{
		ans=d*a;
	}
	else if(k*b-k*a>t)
	{
		ll c1=d/k;
		ans=a*k*c1+(c1-1)*t+min((d-c1*k)*b,t+(d-c1*k)*a);
	}
	else
	{
		ans=k*a+(d-k)*b;
	}
	cout<<ans<<endl;
}