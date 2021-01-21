#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

long long int lcm(long long int a,long long int b)
{
    if(a<b)
    {
        long long int temp=a;
        a=b;
        b=temp;
    }
    return (a*b)/gcd(a,b);
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,a,b,k;
        long long int s1,s2,s3;
        
        cin>>n>>a>>b>>k;
        
        s1=n/a;
        s2=n/b;
        s3=n/lcm(a,b);
        
        //cout<<n<<" "<<a<<" "<<b<<" "<<k<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
        
        long long int ans=s1+s2-2*s3;
        //cout<<"check"<<ans;
        if(ans>=k) cout<<"Win\n";
        else cout<<"Lose\n";
    }
    
}
