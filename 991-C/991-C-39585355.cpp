#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int check(ll n,ll k)
{
	if(k==0)
		return 0;
	ll sum=0;
	ll x=n;
	int flag=0;
	while(n>0)
	{
		//printf("%lld %lld\n",n,k );	
		if(n>=k)
		{
			sum+=k;
			n=n-k;
		}
		else
		{
			sum+=n;
			n=0;
		}		
		if(sum>=(x+1)/2)
			{
				flag=1;
				break;
			}		
		if(n>=10)
		n=n-(n)/10;		
		
	}

	
	if(flag==1)
		return 1;
	else 
		return 0;

}
int main()
{	
	ll n;
	cin>>n;
	ll low=0;
	ll high=n;
	//cout<<check(n,2)<<endl;
	while(high>=low)
	{
		ll mid=low+(high-low)/2;
		if(check(n,mid))
			high=mid-1;
		else
			low=mid+1;
	}
	cout<<low<<endl;
}