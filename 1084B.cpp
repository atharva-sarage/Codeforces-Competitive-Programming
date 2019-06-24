#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll a[1005];
int main()
{
	ll n,s,sum=0;
	cin>>n>>s;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll it=upper_bound(a,a+n,a[0])-a;
	for(ll i=it;i<n;i++)
		sum+=a[i];
	ll diff=sum-a[0]*(n-it);
	if(diff>=s)
		cout<<a[0]<<endl;
	else
	{
		s-=diff;
		cout<<max(-1LL,(a[0]-((s+n-1)/n)))<<endl;
	}

}