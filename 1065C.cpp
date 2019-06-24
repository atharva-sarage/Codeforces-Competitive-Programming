#include<bits/stdc++.h>
using namespace std;
# define mx 200010
int h[mx],pre[mx];
int main()
{
	int n,k,offset=0,count1=0,flag=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	sort(h+1,h+n+1);
	
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+h[i];
	for(int i=h[n];i>=h[1];i--)
	{
		int it=upper_bound(h+1,h+n+1,i)-h;
		if(pre[n]-pre[it-1]-i*(n-it+1)-offset>k)
		{
			count1++;
			it=upper_bound(h+1,h+n+1,i+1)-h;
			offset=pre[n]-pre[it-1]-(i+1)*(n-it+1);
			i++;
			flag=0;
		}
		else if(pre[n]-pre[it-1]-i*(n-it+1)-offset!=0)
		{
			flag=1;
		}
	}
	if(flag==1)
		count1++;
	cout<<count1<<endl;
}