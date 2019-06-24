#include<bits/stdc++.h>
# define mx 200005
using namespace std;
struct point
{
	int ver,hor;
};
struct point pre1[mx],pre2[mx];
int n;
string str;
int x,y;
void pre()
{
	
		if(str[0]=='U')
			pre1[0].ver=1;
		else if(str[0]=='D')
			pre1[0].ver=-1;
		else if(str[0]=='L')
			pre1[0].hor=-1;
		else if(str[0]=='R')
			pre1[0].hor=1;

		if(str[n-1]=='U')
			pre2[n-1].ver=1;
		else if(str[n-1]=='D')
			pre2[n-1].ver=-1;
		else if(str[n-1]=='L')
			pre2[n-1].hor=-1;
		else if(str[n-1]=='R')
			pre2[n-1].hor=1;


	for(int i=1;i<n;i++)
	{
		if(str[i]=='U')
			{pre1[i].ver=pre1[i-1].ver+1;
			pre1[i].hor=pre1[i-1].hor;}
		else if(str[i]=='D')
			{pre1[i].ver=pre1[i-1].ver-1;
				pre1[i].hor=pre1[i-1].hor;}
		else if(str[i]=='L')
			{
			pre1[i].hor=pre1[i-1].hor-1;
			pre1[i].ver=pre1[i-1].ver;
			}
		else if(str[i]=='R')
		{
			pre1[i].hor=pre1[i-1].hor+1;
			pre1[i].ver=pre1[i-1].ver;
		}

	}
	for(int i=n-2;i>=0;i--)
	{
		if(str[i]=='U')
			{
			pre2[i].ver=pre2[i+1].ver+1;
			pre2[i].hor=pre2[i+1].hor;
			}
		else if(str[i]=='D')
			{
			pre2[i].ver=pre2[i+1].ver-1;
			pre2[i].hor=pre2[i+1].hor;
			}
		else if(str[i]=='L')
			{
			pre2[i].hor=pre2[i+1].hor-1;
			pre2[i].ver=pre2[i+1].ver;
			}
		else if(str[i]=='R')
			{
			pre2[i].hor=pre2[i+1].hor+1;
			pre2[i].ver=pre2[i+1].ver;
			}
	}
}
int check(int l)
{
	for(int i=0;i<=n-l;i++)
	{
		//cout<<i<<" "<<l<<" "<<pre1[i-1].ver<<" "<<pre1[i-1].hor<<" "<<pre2[i+l].ver<<" "<<pre2[i+l].hor<<endl;
		if(i==n-l)
		{
			if(abs(y-(pre1[i-1].ver))+abs(x-((pre1[i-1].hor))) <=l && (l-(abs(y-(pre1[i-1].ver))+abs(x-((pre1[i-1].hor)))))%2==0 )
			return 1;
		}
		else if(i==0)
		{
			if(abs(y-(pre2[i+l].ver))+abs(x-(pre2[i+l].hor)) <=l && (l-(abs(y-(pre2[i+l].ver))+abs(x-(pre2[i+l].hor))))%2==0)
			return 1;
		}		
		else
		{
		if(abs(y-(pre1[i-1].ver+pre2[i+l].ver))+abs(x-((pre1[i-1].hor+pre2[i+l].hor))) <=l && (l-(abs(y-(pre1[i-1].ver+pre2[i+l].ver))+abs(x-((pre1[i-1].hor+pre2[i+l].hor)))))%2==0 )
			return 1;
		}
	}
	return 0;
}
int main()
{
	memset(pre1,0,sizeof(pre1));
	memset(pre2,0,sizeof(pre2));
	cin>>n;
	cin>>str;
    	cin>>x;
	cin>>y;
	pre();
	int low=0;
	int high=n;
	int mid;
	while(high>=low)
	{
		mid=low+(high-low)/2;
		if(check(mid))
			high=mid-1;
		else
			low=mid+1;
	}
	if(low==n+1)
		cout<<-1<<endl;
	else
		cout<<low<<endl;
}