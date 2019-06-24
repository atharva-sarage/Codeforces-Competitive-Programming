#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	ll x=n%m;
	ll y=m-n%m;
	
	cout<<min(y*a,x*b)<<endl;

}