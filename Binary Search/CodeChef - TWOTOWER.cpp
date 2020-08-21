 #include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v,v1;
int main()
{
    ll n,a;

    cin>>n;
    cin>>a;

    v.push_back(a);
    v1.push_back(a);
    for(ll i=1;i<n;i++)
    {
        cin>>a;
        if(a>v.back())
            v.push_back(a);
        else{
            ll p=upper_bound(v.begin(),v.end(),a)-v.begin();
            v[p]=a;
        }

        if(a<v1.back())
        {
            v1.push_back(a);
        }
        else{
            //cout<<lower_bound(v1.rbegin(),v1.rend(),a)-v1.rbegin()<<" "<<v1.size()<<endl;
            //ll p=v1.size()-(lower_bound(v1.begin(),v1.end(),a)-v1.begin());
            ll p=v1.size()-(lower_bound(v1.rbegin(),v1.rend(),a)-v1.rbegin());
            v1[p]=a;
        }

    }
    //cout<<v.size()<<endl;



    if(v.size()==v1.size())
    {
        cout<<"Both"<<endl<<n-v.size()<<endl;
    }
    else if(v.size()>v1.size())
    {
        cout<<"Ajeyaa"<<endl<<n-v.size()<<endl;
    }
    else
        cout<<"Sriram"<<endl<<n-v1.size()<<endl;
}

/*
7
10 163 89 5 73 15 49
*/
