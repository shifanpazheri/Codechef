#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    n=1e5+5;
    int prime_factor[n+1]={0};
    vector<pair<int,int>>all_prime_factors[n+1];
    for(int i=2;i<=n;i++)
    {
        if(prime_factor[i]!=0) continue;
        prime_factor[i]=i;
        for(int j=i*2;j<=n;j+=i)
            prime_factor[j]=i;
    }
        
    for(int i=2;i<=n;i++)
    {
        int x=i;
        //cout<<" i="<<i<<" prime_factor[i]="<<prime_factor[i]<<endl;
        map<int,int>m;
        while(x!=1)
        {
            m[prime_factor[x]]++;
            x=x/prime_factor[x];
        }
        //cout<<" i="<<i<<" prime_factor[i]="<<prime_factor[i]<<endl;
        
        for(auto v:m)
        {
            //cout<<v.first<<" "<<v.second<<endl;
            all_prime_factors[i].push_back(v);
        }
        //cout<<" i ="<<i<<" and distinct prime_factor="<<all_prime_factors[i].size()<<endl;
    
        /*cout<<"i is "<<i<<endl; 
        for(int j=0;j<all_prime_factors[i].size();j++)
        {
            cout<<all_prime_factors[i][j].first<<" "<<all_prime_factors[i][j].second<<endl;
        }*/
    }
    
    int a[n]={0};
    
    for(int i=2;i<n;i++)
        a[i]=all_prime_factors[i].size();
    
    int k=5;
    int ans[n][k]={0};
    
    for(int i=2;i<n;i++)
        for(int j=1;j<=5;j++)
            ans[i][j]=ans[i-1][j]+(a[i]==j);
            
    /*for(int i=2;i<n;i++)
        {for(int j=1;j<=5;j++)
            cout<<ans[i][j]<<"";
        cout<<endl;
        }*/
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        cout<<ans[b][k]-ans[a-1][k]<<endl;
    }
}