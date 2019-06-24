#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll pow1(ll a, ll b) 
{
  if (a==0)
    return 0;

    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
        }
        y = (y*y);
        b /= 2;
    }
    return x;
}
ll count(ll n)
{
	ll sum=0;
	while(n>=1)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	ll n;
	cin>>n;
	ll c=n,c1,c3,sum=0;
	while(n>=10)
	{
		n=n/10;
		sum++;
	}
	ll c2=n*pow1(10,sum);
	c2--;
	c3=c-c2;
	cout<<count(c3)+count(c2)<<endl;
}