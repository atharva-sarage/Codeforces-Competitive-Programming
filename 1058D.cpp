#include<bits/stdc++.h>
# define ll unsigned long long int
using namespace std;
ll gcd(ll a,ll b)
{
	 if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}
int main()
{
	ll n,n1,m,k;
	cin>>n>>m>>k;
	n1=n*m+n*m;
	if(n1%k!=0)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		ll c1=(m+m)/(gcd(m+m,k));
		if(c1<=m)
		{
			cout<<"YES"<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<((m+m)/(gcd(m+m,k)))<<endl;
		cout<<(n*gcd(2*m,k))/k<<" "<<0<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<0<<" "<<(m*gcd(2*n,k))/k<<endl;
			cout<<((n+n)/(gcd(n+n,k)))<<" "<<0<<endl;
		}
	}

}