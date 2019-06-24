#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	int n,i,max1=-1;
	fin>>n;
	int a[100005];
	int neg[100005]={0};
	int pos[100005]={0};
	for(i=0;i<n;i++)
		fin>>a[i];
	if(a[0]<0)
		neg[0]=1;
	if(a[n-1]>0)
		pos[n-1]=1;
	for(i=1;i<n;i++)
	{
		neg[i]=neg[i-1];
		if(a[i]<0)
			neg[i]++;
	}
	for(i=n-2;i>=0;i--)
	{
		pos[i]=pos[i+1];
		if(a[i]>0)
			pos[i]++;
	}
	for(i=0;i<n-1;i++)
	{
		if(neg[i]+pos[i+1]>max1)
			max1=neg[i]+pos[i+1];
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d ",neg[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",pos[i]);
	}
	printf("\n");*/
	fout<<n-max1<<endl;

}