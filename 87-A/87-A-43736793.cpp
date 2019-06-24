#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);

}
ll calc(ll a,ll b,ll d)
{
	int n= (b-a)/d +1;
	return ((b+a)*(n))/2;
}
int main()
{
	ll a,b,ans1,ans2,ans3;
	cin>>a>>b;
	if(a>b)
	{
		ans1=a*b/gcd(a,b);
		ll c1=a%b;
		ans2=calc(c1,b,gcd(a,b));		
		if(ans2>ans1-ans2)
			cout<<"Dasha"<<endl;
		else if(ans2<ans1-ans2)
			cout<<"Masha"<<endl;
		else
			cout<<"Equal"<<endl;
	}
	else
	{
		swap(a,b);
		ans1=a*b/gcd(a,b);
		ll c1=a%b;
		ans2=calc(c1,b,gcd(a,b));		
		if(ans2<ans1-ans2)
			cout<<"Dasha"<<endl;
		else if(ans2>ans1-ans2)
			cout<<"Masha"<<endl;
		else
			cout<<"Equal"<<endl;
	}
}