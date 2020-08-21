#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll sz1,sz2;
bool bs(string s1,string s2,ll mid)
{
    string s3;
    for(ll i=0;i<sz1;i++)
    {
         for(ll j=0;j<mid;j++)
         {
            s3+=s1[i];
         }
    }

    ll j=0;
    for(ll i=0;i<sz2;i++)
    {
        if(s2[i]==s3[j])
        {
            j++;
        }
    }

    ll sz3=s3.length();
    if(j==sz3)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    ll tc;
    cin>>tc;

    while(tc--)
    {
        string s1,s2;
        cin>>s1>>s2;

        sz1=s1.length();
        sz2=s2.length();

        ll dif=sz2/sz1;

        ll lo=0;
        ll hi=dif;
        ll mid,index;

        while(lo<=hi)
        {
            mid=lo+(hi-lo)/2;

            if(bs(s1,s2,mid))
            {
                index=mid;
                lo=mid+1;
            }

            else
            {
                hi=mid-1;
            }
        }

        cout<<index<<endl;
    }
}

/*
Input:
3
abc
aabbcc
abc
bbccc
abcdef
abc

Output:
2
0
0
*/
