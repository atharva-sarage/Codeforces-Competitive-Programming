#include<bits/stdc++.h>
using namespace std;
int ceil1(int n,int i)
{
	if(n%i==0)
		return n/i;
	else
		return n/i+1;

}
int calc(int n)
{
	int ans=500005,index1;
	for(int i=1;i<=n;i++)
	{
		if(i+ceil1(n,i)<ans)
			{
				index1=i;
				ans=i+ceil1(n,i);
			}
	}
	return index1;
}
int main()
{
	int n;
	cin>>n;
	vector <int> vec;
	int b=calc(n);
	for(int i=n;i>=1;i--)
	{
		int count=0;
		while(count<b && i>0)
			{
			vec.push_back(i);
			count++;
			i--;
			}
			i++;
		reverse(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		vec.clear();
	}
	printf("\n");
}