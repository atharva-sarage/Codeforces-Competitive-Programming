#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,max1=0,max2=0;
	cin>>n;
	while(n--)
	{
		char type;
		int x,y;
		cin>>type>>x>>y;
		if(type=='+')
		{
			max1=max(max1,max(x,y));
			max2=max(max2,min(x,y));
		}
		else
		{
			if(max1<=max(x,y) && max2<=min(x,y))
				cout<<"YES"<<"\n";
			else
				cout<<"NO"<<"\n";
		}

	}
}