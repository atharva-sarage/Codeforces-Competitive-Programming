#include<bits/stdc++.h>
using namespace std;
int main()
{
	int freq[30]={0};
	int n;
	cin>>n;
	string str;
	cin>>str;
	for(int i=0;i<n;i++)
		{freq[str[i]-'0']++;}

	cout<<min(freq[8],n/11)<<endl;
}