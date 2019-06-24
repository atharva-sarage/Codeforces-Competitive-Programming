#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	ll l,r;
	cin>>l>>r;
	cout<<"YES"<<endl;
	for(ll i=l;i<=r;i=i+2)
		cout<<i<<" "<<i+1<<endl;
}