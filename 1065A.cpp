#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	ll s,a,b,c;
	cin>>s>>a>>b>>c;
	ll c1;
	c1=s/c;
	cout<<c1+(c1/a )*b<<endl;
}
}