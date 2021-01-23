#include <bits/stdc++.h>
using namespace std;


//NEED TO FIND EFFICENT nCr function
const int maxn = 2e5 + 42, mod = 1e9 + 7;
 
int bpow(int x, int n) {
	return n ? n % 2 ? 1LL * x * bpow(x, n - 1) % mod : bpow(1LL * x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}
 
int F[maxn];
int fact(int n) {
	return n ? F[n] ? F[n] : F[n] = 1LL * n * fact(n - 1) % mod : 1;
}
int rfact(int n) {
	return inv(fact(n));
}
int nCr(int n, int r) {
	return 1LL * fact(n) * rfact(r) % mod * rfact(n - r) % mod;
}

/*long long int fact(long long int n)
{
    long long int sum=1;
    if(n==0) return 1;
    
    for(long long int i=1;i<=n;i++)
        sum*=i;
    
    return (sum%mod);
}*/

int main()
{
    long long int t;
    cin>>t;
    
    while(t--)
    {
        long long int n;
        cin>>n;
        
        string str1,str2;
        cin>>str1>>str2;
        
        long long int p=0,q=0;
        for(long long int i=0;i<n;i++)
        {
            if(str1[i]=='1') p++;
        }
        for(long long int i=0;i<n;i++)
        {
            if(str2[i]=='1') q++;
        }
        
        string temp1=str1,temp2=str2,temp3=str2;
        long long int r=n-q;
        for(long long int i=0;i<n;i++)
        {
            if(p>0)
            {
                temp1[i]='1';
                p--;
            }
            else
                temp1[i]='0';
        }
        for(long long int i=0;i<n;i++)
        {
            if(q>0)
            {
                temp2[i]='1';
                q--;
            }
            else
                temp2[i]='0';
        }
        
        for(long long int i=0;i<n;i++)
        {
            if(r>0)
            {
                temp3[i]='0';
                r--;
            }
            else
                temp3[i]='1';
        }
        
        //cout<<"temp1="<<temp1<<" temp2="<<temp2<<" temp3="<<temp3<<endl;
        
        long long int ans1=0,ans2=0;
        
        for(long long int i=0;i<n;i++)
        {
            if(temp1[i]!=temp2[i])
                ans1++;
        }
        
        for(long long int i=0;i<n;i++)
        {
            if(temp1[i]!=temp3[i])
                ans2++;
        }
        
        //cout<<" ans1="<<ans1<<" ans2="<<ans2<<endl;
        
        long long int sum=0;
        for(long long int i=ans1;i<=ans2;i+=2)//i+=2->very imp fact
        {
            long long int temp=nCr(n, i);
            sum+=temp;
            //nCrModPFermat(n, i, mod);
            sum=sum%mod;
           // cout<<"sum is"<<sum<<endl;
        }
        
        cout<<sum<<"\n";
    }
}