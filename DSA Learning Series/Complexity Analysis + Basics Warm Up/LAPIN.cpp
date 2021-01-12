#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    
	    int a[26]={0};
	    int b[26]={0};
	    
	    string str;
	    cin>>str;
	    int len=str.length();
	    //cout<<len;
	    
	    for(int i=0;i<(len)/2;i++)
	        a[str[i]-97]+=1;
	    for(int i=(len+1)/2;i<len;i++)
	        b[str[i]-97]+=1;
	    
	    int count=0;
	    for(int i=0;i<26;i++)
	    {
	        if(a[i]==b[i]) count++;
	
	    }

	    if(count==26)
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	}
	return 0;
}
