#include<bits/stdc++.h>
using namespace std;
# define mx 100005
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
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,c=0;
		cin>>n;		
		while(n>=1)
		{
			if(n%2==1)
				c++;
			n/=2;
		}
		cout<<pow1(2,c)<<endl;
	}
}