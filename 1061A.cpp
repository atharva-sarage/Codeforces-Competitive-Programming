#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	long long n,s;
	cin>>n>>s;
	if(s%n==0)
		cout<<s/n<<endl;
	else
		cout<<s/n+1<<endl;
}

