#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#define lli long long int
#define pr 998244353
using namespace std;
int main()
{
	lli i,n,l,d,ans=0,tmp=1;
	cin>>n;
	for(i=n;i;i--) ans=(ans+pr-(tmp=(i*tmp)%pr))%pr;
	ans = (ans+((n+1)*tmp)%pr)%pr;
	cout<<ans<<endl;
}