#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	ll n,m,i,mini,maxi;
	cin>>n>>m;
	if(m==0)
	{
		cout<<n<<" "<<n<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)	
	{
		if((i*(i-1))/2 >=m)
			break;
	}
	maxi=n-i;
	maxi=max(0LL,maxi);
	if((n+1)/2-m <=0)
	{
		mini=0;
	}
	else
	{
		mini=n-2*m;
	}
	cout<<mini<<" "<<maxi<<endl;

}