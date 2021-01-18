#include <bits/stdc++.h>
//Partially Correct
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
    int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector <int> a(n);
		queue <int> q;
		unordered_set <int> st;
		
		int ans=1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			st.insert(a[i]);
			q.push(i);
			
			if((int)st.size()==k)
			{
				st.erase(a[q.front()]);
				int temp=a[q.front()];
				while(!q.empty()&&temp==a[q.front()])
				{
					q.pop();
				}
			}
			ans=max(ans,(int)q.size());
		}
		cout<<ans<<"\n";
	}
	
}
