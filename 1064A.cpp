#include<bits/stdc++.h>
using namespace std;
# define mx 100005
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<max(a[2]-a[0]-a[1] +1 ,0)<<endl;
}