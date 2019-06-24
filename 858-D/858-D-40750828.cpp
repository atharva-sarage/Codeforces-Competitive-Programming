#include<bits/stdc++.h>
using namespace std;
string str[70005];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	unordered_map <string,  int> m;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>str[i];
			for(int len=1;len<=9;len++)
			{
				for(int j=0;j<=9-len;j++)
					{
							
						if(m.count(str[i].substr(j,len))==0)
							m.insert(make_pair(str[i].substr(j,len),i));

						else if(m[(str[i].substr(j,len))]!=i && m.count(str[i].substr(j,len))!=0 )
						{
							m[str[i].substr(j,len)]=-1;
						}
											
				}
				
			}
		}

	for(int i=0;i<n;i++)
	{
		
		int flag=0;
		for(int len=1;len<=9;len++)
		{
			for(int j=0;j<=9-len;j++)
			{
			
				if(m[str[i].substr(j,len)]!=-1)
					{
						cout<<str[i].substr(j,len)<<"\n";
 
						flag =1;
						break;
					}
			}
			if(flag==1)
				break;
		}
	}


}