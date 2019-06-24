#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long count=0,flip,rotate;
	cin>>rotate>>flip;
	char str[300005];
	for(int i=0;i<n;i++)
		cin>>str[i];
	for(int i=0;i<n-1;i++)
		if(str[i]=='0' && str[i+1]=='1')
			count++;

	if(str[n-1]=='0')
		count++;
	if(count==0)
	{
	    	cout<<0<<endl;
		return 0;
	}
	cout<<min(count*flip,(count-1)*rotate+flip);

}