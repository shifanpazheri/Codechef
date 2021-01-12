#include <bits/stdc++.h>
using namespace std;

//BUT TIME EXCEEDED FIXED
// IMP n!=1*2*3...*n
// IN THIS CASE # of 2 >= # of 5
// SO ONLY NEED TO COMPUTE FACTORS OF 5
// NOW COMPLEXITY IS ((N/5)LOGN) (TO BASE 5)
// But again time exceeded so
//floor(n/5)+floor(n/25)+..... is the solution

/*long long int fact2(long long int  n)
{
	if(n==1) return 0;
	long long int i;
		
	for(i=1;i<n;i++)
	{
		if(n%((long long int)pow(2,i))!=0)
		{
			i--;
			break;
		}
	}
	//cout<<"no is:"<<n<<" its power of 2 is:"<<i<<"\n";
	return i;
}

long long int fact5(long long int  n)
{
	if(n==1) return 0;
	long long int j;
		
	for(j=1;j<n;j++)
	{
		if(n%((long long int)pow(5,j))!=0)
		{
			j--;
			break;
		}
	}
	//cout<<"no is:"<<n<<" its power of 5 is:"<<j<<"\n";
	return j;
}*/


int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int ans=0;
		long long int temp=0;
		for(int i=1;i<=n;i++)
		{
			temp=floor(n/pow(5,i));
			if(temp==0)
				break;
			ans+=temp;
		//	cout<<"temp="<<temp<<" ans="<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
}
