#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
char a[502][502];
ll mark[502][502];
ll value[502][502];
ll m,n,q;
ll coun;

bool valid(ll xx,ll yy)
{
    if(xx>=1&&xx<=m&&yy>=1&&yy<=n &&a[xx][yy]!='#')
    {
        return true;
    }

    return false;
}

void dfs(ll p,ll q)
{
    mark[p][q]=1;
    for(ll i=0;i<=3;i++)
    {
        ll xx=p+dx[i];
        ll yy=q+dy[i];

        if(valid(xx,yy)&&mark[xx][yy]==0)
        {
            if(a[xx][yy]=='C')
                coun++;
            dfs(xx,yy);
        }
    }
}

int main()
{
    ll t;
    cin>>t;

    for(ll tc=1;tc<=t;tc++)
    {

        cin>>m>>n>>q;

        for(ll i=1;i<=m;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }

        memset(mark,0,sizeof(mark));
        memset(value,-1,sizeof(value));

        cout<<"Case "<<tc<<":"<<endl;
        while(q--)
        {

            coun=0;
            ll x,y;
            cin>>x>>y;

            if(value[x][y]!=-1)
            {
                cout<<value[x][y]<<endl;
            }
            else{
                  memset(mark,0,sizeof(mark));
                  dfs(x,y);
                  cout<<coun<<endl;

                  for(ll i=1;i<=m;i++)
                  {
                      for(ll j=1;j<=n;j++)
                      {
                        if(mark[i][j]==1)
                            value[i][j]=coun;
                      }
                  }
            }

        }
    }

}

/*
input:
1

4 5 2
..#..
.C#C.
##..#
..C#C

1 1
4 1

output:
Case 1:
1
2
*/
