#include <bits/stdc++.h>
using namespace std;

int main()
{
    int period=60;
    int fib[period]={0};
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<period;i++)
        fib[i]=(fib[i-1]+fib[i-2])%10;
        
    /*for(int i=0;i<period;i++)
        cout<<i<<" "<<fib[i]<<endl;*/
    
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,ans=0;
        cin>>n;
        if(n==1) cout<<"0\n";
        else if(n==2) cout<<"1\n";
        else if(n==3) cout<<"1\n";
        else
        {
            ans=0;
            for(long long int i=2;i<=70;i++)
            {
                //cout<<"i is"<<i<<endl;
                long long int temp=n/pow(2,i);
                if(temp==0)
                {
                    ans=i-1;
                    break;
                }
            }
            long long int index=pow(2,ans);
            
            if(n<index)//in order to remove issues caused due to precision of log2 ans pow function.
            {
                ans--;
                index=pow(2,ans);
            }
            
            cout<<fib[(index-1)%60]<<endl;
            
        }
    }
    
}