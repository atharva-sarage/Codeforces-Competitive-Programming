#include <bits/stdc++.h>
using namespace std;
vector<int> D[200000+20];
int tims[200000+20];
int fa[200000+20];
int deps[200000+20];
int dfs(int a , int FA)
{
    for(int i = 0  ; i<D[a].size() ; i++)
    {
        if(D[a][i]!=FA)
        {
              tims[D[a][i]]=tims[a]+1;
               fa[D[a][i]]=a;
            dfs(D[a][i],a);
        }
    }
     for(int i = 0 ; i<D[a].size() ; i++)
     {

              if(D[a][i]!=FA)
          deps[a]=max(deps[D[a][i]],deps[a]);
     }
      deps[a]++;
}

int main()
{       int n,x;
           scanf("%d%d",&n,&x);
              int a,b;
                memset(tims,0,sizeof(tims));
                 memset(fa,0,sizeof(fa));
                   memset(deps,0,sizeof(deps));
            for(int i = 0 ; i<n-1 ; i++)
            {
                 scanf("%d%d",&a,&b);
                  D[a].push_back(b);
                   D[b].push_back(a);
            }
               tims[1]=0;
             dfs(1,-1);
               int pw = (deps[x]+tims[x]-1)*2;
                 int ste = 0;
              while(x!=1)
              {
                  x = fa[x];
                   ste++;
                    if(ste<tims[x])
                    {
                        pw = max(pw,(deps[x]+tims[x]-1)*2);
                    }
                      // cout<<x<<"FGH";
                          //  cout<<tims[x]<<' '<<"E";
              }
               cout<<pw<<endl;
    return 0;
}