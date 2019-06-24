#include <bits/stdc++.h>

using namespace std;

int m,n,k,x,y,cnt,num;
int ans[100010];
int vis[1005][1005];
char s[1005][1005];
void dfs(int xx,int yy){
    if(s[xx][yy] == '*') cnt++;
    else if(!vis[xx][yy]){
        vis[xx][yy] = num;
        dfs(xx+1,yy);
        dfs(xx-1,yy);
        dfs(xx,yy+1);
        dfs(xx,yy-1);
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n ; i++) scanf("%s",&s[i][1]);
    while(k--){
        scanf("%d%d",&x,&y);
        if(!vis[x][y]){
            num++;
            cnt = 0;
            dfs(x,y);
            ans[num] = cnt;
        }
        printf("%d\n",ans[vis[x][y]]);
    }
    return 0;
}