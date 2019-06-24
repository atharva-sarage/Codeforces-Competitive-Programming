#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[100005];
	cin>>str;
	int m =strlen(str);
	int count=0,hash=0,open=0,index;
	for(int i=0;i<m;i++)
	{
		if(str[i]=='#')
			{
				hash++;
				index=i;
			}
		if(str[i]=='(')
			open++;
	}
	if(2*open-m+1<1)
	{
		printf("-1\n");
			return 0;
	}
	for(int i=0;i<m;i++)
	{
		if(str[i]=='(')
			count++;
		else if(str[i]==')')
			count--;
		else if(str[i]=='#' && i!=index)
			count--;
		else
			count=count-(2*open-m+1);

		if(count<0)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(count!=0)
		{
			printf("-1\n");
			return 0;
		}
	
	
	for(int i=0;i<hash-1;i++)
	{
		printf("1\n");
	}
	printf("%d\n",2*open-m+1 );
}