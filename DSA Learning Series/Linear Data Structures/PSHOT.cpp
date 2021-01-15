#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string pen;
		cin>>pen;
		int c1=0;
		int c2=0;
		int s=2*n;
		for(int i=0;i<2*n;i++)
		{
			if(i%2==0&&pen[i]=='1')
				c1+=1;
			if(i%2==1&&pen[i]=='1')
				c2+=1;
			//cout<<"shoot="<<i+1<<" c1="<<c1<<" c2="<<c2<<" Remain="<<(2*n-i-1)<<" ceil"<<((2*n-i-1)/2)<<endl;
			if(c1>c2+((2*n-i)/2))
			{
				s=i+1;
				break;
			}
			if(c2>c1+((2*n-i-1)/2))
			{
				s=i+1;
				break;
			}
		}
		cout<<s<<endl;
	}
}
