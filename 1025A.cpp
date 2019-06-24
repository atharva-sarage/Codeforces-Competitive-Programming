#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char str[100005];
	int freq[27]={0};
	int count1=0;
	int count2=0;
	cin>>str;
	if(n==1)
		cout<<"Yes"<<endl;
	else
	{
	for(int i=0;i<n;i++)
		freq[str[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(freq[i]>=2)
			count2++;
	}
	if(count2>=1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
}