#include<bits/stdc++.h>
using namespace std;

bool visited[1000005];
int p[100005];
int count1[1000005]={0};

int main()
{
	int n,a,flag=0;
	cin>>n>>a;
	set <int> x;
	
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++)
		cin>>p[i];
	if(p[0]==a)
	{
		cout<<-1<<endl;
		return 0;
	}
	int flag2=0;
	for(int i=0;i<n;i++)
	{	
		int y;
		y=p[i];
		count1[y]++;

		if(!visited[y] && y!=a && flag2==0)
			{
				x.insert(y);
				visited[y]=true;
			}
		else if(y==a )
		{
			flag2=1;
			set <int> temp;
			set <int> :: iterator itr;
			for(itr=x.begin();itr!=x.end();itr++)
			{
				if(count1[*itr]>=count1[a])
					temp.insert(*itr);
			}
			x=temp;
		}
		if(x.empty())
		{
			flag=1;
			break;
		}

	}
	if(flag==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		cout<<*x.begin()<<endl;
	}

}