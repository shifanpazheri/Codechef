#include<bits/stdc++.h>
using namespace std;

const int N=200;
vector<pair<int,int>>prime_factors[N+1];

int check(int x)//It should be exactly of the form num=p1*p2;
{
    if(x==1) return 0;
    if(prime_factors[x].size()!=2)
        return 0;
    for(auto v:prime_factors[x])
    {
        if(v.second>1)
            return 0;
    }
    return 1;
}

int main()
{
    int n=200;
    int max_prime[n+1]={0};
    
    //vector<pair<int,int>>prime_factors[n+1];
    
    for(int i=2;i<=n;i++)
    {
        if(max_prime[i]!=0) continue;
        max_prime[i]=i;
        for(int j=2*i;j<=n;j+=i)
            max_prime[j]=i;
    }
    
    /*for(int i=2;i<=n;i++)
    {
        cout<<" i ="<<i<<" max prime="<<max_prime[i]<<endl;
    }*/
    
    for(int i=2;i<=n;i++)
    {
        int x=i;
        map<int,int> m;
        while(x!=1)
        {
            m[max_prime[x]]++;
            x=x/max_prime[x];
        }
        for(auto v:m)
        {
            prime_factors[i].push_back(v);
        }
        
    }
    /*for(int i=2;i<=n;i++)
    {
        cout<<" i ="<<i<<endl;
        for(auto v:prime_factors[i])
        {
            cout<<v.first<<" "<<v.second<<endl;
        }
    }*/
    
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        int flag=0;
        
        //cout<<num<<endl;
        for(int i=1;i<num;i++)
        {
            //cout<<" x="<<i<<" y="<<num-i<<endl;
            if(check(i)&&check(num-i))
            {
                flag=1;
                break;
            }
        }
        
        if(flag==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}