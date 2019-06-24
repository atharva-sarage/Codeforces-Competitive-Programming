#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,min1;
	min1=1000000;
	cin>>n>>k;
	int a[100005];
	int freq[100005];
	int freq2[100005];

	int final[100005];
	memset(final,0,sizeof(final));
	memset(freq,0,sizeof(freq));
	memset(freq2,0,sizeof(freq2));
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(freq[a[i]]==0)
				{
				    	final[i]=final[i-1]+1;
					freq[a[i]]=1;
				}
			else
				final[i]=final[i-1];
		}
	if(n==1 && k==1)
		{
			cout<<"1 1"<<endl;
			return 0;	
		}
		

		int start,end,ans=k,count=0,index2,i;
	for(int i=k;i<=n;i++)
	{

		int c1=final[i];
		if(c1<k)
			continue;

		index2=i;

		while(ans>0)
		{
				
			if(freq2[a[i-count]]==0)
				{
					ans--;
					freq2[a[i-count]]=1;
				}

			count++;
		}

		break;
	}
	if(index2<index2-count+1)
		cout<<"-1 -1"<<endl;
	else
	cout<<index2-count+1<<" "<<index2<<endl;


}