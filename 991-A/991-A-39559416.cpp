#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	if(n<a || n<b || n<c || n-a-b+c<=0 || c>min(a,b) )
		cout<<"-1"<<endl;
	else if(n-a-b+c>0)	
		cout<<n-a-b+c<<endl;

}