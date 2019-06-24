#include<bits/stdc++.h>
using namespace std;
long long p[38];
void query(int long long x,int long long y)
{
	cout<<"?"<<" "<<x<<" "<<y<<endl;
}
int main()
{
	p[0]=1LL;
	for(int i=1;i<34;i++)
		p[i]=p[i-1]*2LL;
	string str,str2;
	cin>>str;
	while(1)
	{
		int i=0;
		char type;
		query(0,1);	
		cin>>type;
		if(type=='x')
			{
				cout<<'!'<<" "<<1<<endl;
				cin>>str2;
				if(!str2.compare("end"))
					break;
				else
					continue;
			}

		while(1)
		{
			query(p[i],p[i+1]);
			cin>>type;
			if(type=='x')
				break;
			else
				i++;
		}
		int low=p[i];
		int high=p[i+1];
		int mid;
		while(high-low>1)
		{
			mid=low+(high-low)/2;
			query(mid,low);
			cin>>type;
			if(type=='y')
				high=mid;
			else
				low=mid;
		}
		cout<<"!"<<" "<<high<<endl;
		
		cin>>str2;
		if(!str2.compare("end"))
			break;
	}
}