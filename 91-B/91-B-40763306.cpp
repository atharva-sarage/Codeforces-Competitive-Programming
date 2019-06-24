#include<bits/stdc++.h>
#define mx 100005
typedef int long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll a[mx],min1[mx];
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	min1[n-1]=a[n-1];
	for(ll i=n-2;i>=0;i--)
	{
		min1[i]=min(min1[i+1],a[i]);
	}
	for(ll i=0;i<n-1;i++)
	{
		ll low=i;
		ll high=n-1;
		ll mid;
		while(high>=low)
		{
			mid=low+(high-low)/2;
			if(min1[mid]<a[i]) // we have an answer
				low=mid+1;
			else
				high=mid-1;
		}	
		if(high-i-1<-1)
			cout<<-1<<endl;
		else
		cout<<high-i-1<<endl;
	}
	cout<<-1<<endl;
}