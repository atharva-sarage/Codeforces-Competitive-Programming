#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	ll  n,k;
	cin>>n>>k;
	ll  ans=k-1;
	if(k-n-1 > 0)
		ans=ans-2*(k-n-1);
	if(k-2*n-1 >0)
		ans+=k-2*n-1;

	if(k%2==0 && n>=k/2)
		ans--;
	ans/=2;
	cout<<ans<<endl;
}