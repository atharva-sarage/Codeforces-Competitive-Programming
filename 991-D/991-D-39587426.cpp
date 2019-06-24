#include<bits/stdc++.h>
using namespace std;
int main()
{
	char up[105];
	char dow[105];
	scanf("%s",up);
	scanf("%s",dow);
	int n=strlen(up);
	int final=0;
	for(int i=0;i<n;i++)
	{
		
		//printf("%d\n",i );
		int count=0,ans=0,flag=0;
		int s[3];
		s[0]=s[1]=s[2]=0;
		if(i==n-1)
			break;
		if(i==n-2)
		{
			if(up[n-2]=='X' )
				ans++;
			if(dow[n-2]=='X' )
				ans++;
			if(up[n-1]=='X' )
				ans++;
			if(dow[n-1]=='X' )
				ans++;

			if(ans<=1)
				final++;
			break;

		}
		while(count<3 && i<n)
		{
			if(up[i]=='X' && dow[i]=='X')
				{
					if(count==2 && ans<=1)
						final++;
					flag=1;
						break;
				}
			if(up[i]=='X' || dow[i]=='X')
				{
					s[count]++;
					ans++;
				}
			i++;
			count++;
		}
		if(flag==1)
			continue;
		//cout<<ans <<endl;
		if(ans==0)
			{
				final=final+2;
				i--;
				continue;
			}
		if(ans<3)
			final++;
		//cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
		

		if(s[0]==0 && s[1]<=1 || s[0]==1 && s[1]==0 || s[0]==1 && s[1]==1 && s[2]!=0)
			i=i-2;
		else
			i--;

	}

	cout<<final<<endl;

}