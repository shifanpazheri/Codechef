#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5; //constant for global variable declarations

int32_t main() {
    //Fast IO
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //for each index i, find the first index j where (j>i) and arr[j]<arr[i]
    //arr[i] denotes the seniority level of the chef (arbitrary value)
    //Each Chef will give his work to the first Chef in front of him who is junior to him (arr[j]<arr[i])
    //Chaos = (j-i+1)
    //Product of chaos across all Chefs
    //if no such j exists, ignore that i
    //Maintain a variables answer (=1 initially)
    //For each i, multiply answer by (j-i+1)
    //N (the number of chefs) <= 1e5
    //a[i] (the seniority level) <= 1e5



    //For each i, we need to find the first index j such that chef at j is junior to chef at i, and j>i
    //4 9 2 7 3 1
    //2 2 1 3 1 (doesn't exist)
  	int n,k;
	cin>>n>>k;
	
	pair<int,int> temp;
	stack<pair<int ,int>> s;
	
	int f=1;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp.first;
		temp.second=i;
		while(!s.empty()&&s.top().first>temp.first)
		{
		//	cout<<" temp.first is:"<<temp.first<<" temp.second is:"<<temp.second<<" s.top().first is:"<<s.top().first<<" s.top().second is:"<<s.top().second+1<<" value is: "<<temp.second-s.top().second<<endl;
			f*=(temp.second-s.top().second+1);
			f=f%(1000000007);
			s.pop();
		}
		s.push(temp);
	}
	
	cout<<f<<endl;
	
}
