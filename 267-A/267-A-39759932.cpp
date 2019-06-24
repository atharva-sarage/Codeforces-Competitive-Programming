#include<bits/stdc++.h>
using namespace std;
long ans=0;
int gcd(int a, int b)
{
    if (a == 0) 
       return b;
     
    return gcd(b%a, a);
}

int calc(int n,int m)
{
	if(max(n,m)%min(n,m)==0)
		{
			ans+=max(n,m)/min(n,m);
			return 0;
		}

	ans+=max(n,m)/min(n,m);
	calc(max(n,m)%min(n,m),min(n,m));

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

	ans=0;
	int n,m;
	cin>>n>>m;
	calc(n,m);
	cout<<ans<<endl;
	}
	
}