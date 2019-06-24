#include<bits/stdc++.h>
using namespace std;
# define mx 100005
typedef int long long ll;
ll pre[mx],suff[mx],minsuff[mx],minpre[mx],a[mx];
int main()
{
	ll n,final=0,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	pre[0]=-1*a[0];
	for(ll i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i]*-1;
	suff[n-1]=-1*a[n-1];
	for(ll i=n-2;i>=0;i--)
		suff[i]=suff[i+1]+a[i]*-1;
	minsuff[n-1]=suff[n-1];
	for(ll i=n-2;i>=0;i--)
		minsuff[i]=max(minsuff[i+1],max(0LL,suff[i]));
	minpre[0]=pre[0];
	for(ll i=1;i<n;i++)
		minpre[i]=max(minpre[i-1],max(0LL,pre[i]));
	for(ll i=0;i<n-1;i++)
	{
		final=max(final,minpre[i]+minsuff[i+1]);
	}
	for(ll i=n-1;i>0;i--)
	final=max(final,minsuff[i]+minpre[i-1]);

	final=max(final,max(minpre[n-1],minsuff[0]));
	sum+=2*final;
	cout<<sum<<endl;


}