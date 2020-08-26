#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
char a[1000][1000];
ll ck[1000][1000];
ll r,c;
ll n;
ll tc;

bool valid(int x,int y,int r,int c)
{
	if(x>=1&&x<=r&&y>=1&&y<=c&&a[x][y]!='#')
	    return true;

	return false;
}

void dfs(ll x,ll y)
{
	ck[x][y]=1;
	for(ll i=0;i<=3;i++)
	{
		ll xx=x+dx[i];
		ll yy=y+dy[i];

		if(valid(xx,yy,r,c)&&ck[xx][yy]==0)
		{
		    n++;
			dfs(xx,yy);
		}
	}
    //cout<<n<<endl;
    //n=0;
}
int main()
{
	ll m,i,j;
	//ll c,r;
	ll t;
	cin>>t;
	for(tc=1;tc<=t;tc++)
    {
        memset(ck,0,sizeof(ck));
        n=1;
        cin>>c>>r;
        ll x,y;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='@')
                {
                    x=i,y=j;
                }
                }
        }
        dfs(x,y);
        //if(ck[r][c]==1) cout<<"yes"<<endl;
        //else cout<<"no"<<endl;
        cout<<"Case "<<tc<<": "<<n<<endl;
    }
}

/*
input:
2

6 9

....#.

.....#

......

......

......

......

......

#@...#

.#..#.

11 9

.#.........

.#.#######.

.#.#.....#.

.#.#.###.#.

.#.#..@#.#.

.#.#####.#.

.#.......#.

.#########.

...........


output:
Case 1: 45
Case 2: 59
*/
