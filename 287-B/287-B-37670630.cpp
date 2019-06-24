#include<bits/stdc++.h>
using namespace std;
int main()
{
	
		int long long n,k,high,low,x;
	cin>>n>>k;
	high=k-1;
	low=0;
	if((k*(k-1))/2 <n-1)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		
	int long long c1=k*(k-1)/2;
	while(high>=low)
	{
		x=low+(high-low)/2;

		if(c1-(x*(x+1))/2 <n-1)
			high=x-1;	
		else
			low=x+1;
			
	}
	cout<<k-low<<endl;
}