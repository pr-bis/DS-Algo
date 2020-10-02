#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100003
#define pb push_back
int t,n;
std::vector<int> divi[1000004];
int p[1000004];
int h[1000004];
int arr[MAX];
int top = 0;
int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		 for(int i=1;i<=top;i++)
		 {
		 	h[i] = 0;
		 }
		 cin >> n;
		 ans = 0;
		 for(int i=0;i<n;i++)
		 {
		 	cin >> arr[i];
		 	top = max(top,arr[i]);
		 	if(arr[i]!=1 and !p[arr[i]])
		 	{
		 		p[arr[i]] = 1;
		 		for(int j = arr[i];j<=1000000;j+=arr[i])
		 		{
		 			divi[j].pb(arr[i]);
		 		}
		 	}
		 }


		 for(int i=0;i<n;i++)
		 {
		 	ans = max(ans,h[arr[i]]);
		 	h[1]++;
		 	for(int u : divi[arr[i]])
		 		h[u]++;
		 }



		cout << ans << endl;
	}
	return 0;
}
