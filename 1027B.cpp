#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int  main()
{
	ll  n;
	cin>>n;
	ll  q;
	cin>>q;
	while(q--)
	{
		ll  x,y;
		cin>>x>>y;
		ll  above=0;
		if((x+y)%2==0)
		{
		if(n%2==0)
		{	
			above=(x-1)*(n/2);
			above+=(y+1)/2;
			cout<<above<<endl;
		}	
		else
		{
			above+=(x/2)*((n+1)/2)+((x-1)/2)*(n/2);
			above+=(y+1)/2;
			cout<<above<<endl;
		}
		}
		else
		{
			above=(n*n+1)/2;
			if(n%2==0)
			{
				above+=(x-1)*n/2;
				above+=(y+1)/2;
				cout<<above<<endl;
			}
			else
			{
				above+=(x/2)*((n)/2)+((x-1)/2)*(n+1)/2;
				//cout<<(x/2)*((n)/2)+((x-1)/2)*(n+1)/2<<endl;
				above+=(y+1)/2;
				cout<<above<<endl;
			}
		}
		
	}

}