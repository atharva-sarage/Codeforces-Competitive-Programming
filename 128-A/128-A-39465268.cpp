#include<bits/stdc++.h>
using namespace std;
char grid[9][9][20];
int flag=0;
bool visited[9][9];

int isvalid(int a,int b)
  {
    	int n=8;
    	int m=8;
        if(a>=0&&a<=n-1&&b>=0&&b<=m-1) 
        	return 1;
        else
        	return 0;
  }
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};

void dfs(int xx,int yy,int time)
{
	//printf("%d   %d\n",xx,yy );
	if(!isvalid(xx,yy))
		return ;
	visited[xx][yy]=true;
	if(grid[xx][yy][0]=='A')
	{
		flag=1;
		return;
	}
	int flag2=0,flag3=0;
	for(int i=0;i<8;i++)
	{
		if(isvalid(xx+dx[i],yy+dy[i]) &&  grid[xx+dx[i]][yy+dy[i]][time]!='S' && grid[xx+dx[i]][yy+dy[i]][time+1]!='S' && !visited[xx+dx[i]][yy+dy[i]] )
		{
			//printf("****%d %d\n",xx+dx[i],yy+dy[i] );
			dfs(xx+dx[i],yy+dy[i],time+1);
			flag2=1;
		}		
		
	}
	if(grid[xx-1][yy][time]!='S' && time<=16 )
		{
			dfs(xx,yy,time+1);
		}
	

	if(flag2==0)
		return;
}
int main()
{
	memset(visited,false,sizeof(visited));
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cin>>grid[i][j][0];
		}
	}
	for(int x=1;x<16;x++)
	{
		for(int j=0;j<8;j++)
			{
				for(int i=0;i<8;i++)
					{
						grid[i][j][x]='.';
					}
			}
	}

	for(int x=0;x<16;x++)
	{
		for(int j=0;j<8;j++)
			{
				for(int i=0;i<7;i++)
					{
						if(grid[i][j][x]=='S')
						grid[i+1][j][x+1]='S';
					}
			}		

	}
	

	dfs(7,0,0);
	if(flag==1)
		printf("WIN\n");
	else
		printf("LOSE\n");
	

}