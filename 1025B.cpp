#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
struct point a[150005];
set <int> s;
set <int> :: reverse_iterator itr;
bool compare(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,flag=0,ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x1,y1;
		cin>>x1>>y1;
		a[i].x=x1;
		a[i].y=y1;
	}
//	sort(a,a+n,compare);
	int a1=a[0].x;
	int a2=a[0].y;


	for(int i=1;i*i<=a1;i++)
	{
		if(a1%i==0)
		{
			if(a1/i==i)
			s.insert(i);
			else
			{
				s.insert(i);
				s.insert(a1/i);
			}
		}
	}
	for(int i=1;i*i<=a2;i++)
	{
		if(a2%i==0)
		{
			if(a2/i==i)
			s.insert(i);
			else
			{
				s.insert(i);
				s.insert(a2/i);
			}
		}
	}
	for(itr=s.rbegin();itr!=s.rend();++itr)
	{
		int v=*itr;
	//	cout<<v<<endl;
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i].x %v==0 || a[i].y %v==0)
				continue;
			else
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
			{
			ans=v;
			break;
			}
	}
	if(ans==1)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}

