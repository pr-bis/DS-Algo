/* ------------------------- AC in One Go ----------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;
#define LIMIT 1e12
#define INF 1e18
#define F first
#define S second
#define int long long
pair<string,pair<int,int>> arr[101];
int dp[101][37];
int n,t;
int dig(char& c)
{
	int d = 0;
	if(c<='9' and c>='0') d = c - '0';
	else d = c - 'A' + 10;
	return d;
}
int low(string& in)
{
	int a = 2;
	for(char c : in)
	{
		a = max(a,dig(c)+1);
	}
	return a;
}
int num(string& in, int k)
{
	int mul = 1;
	int  n = 0;
	reverse(in.begin(),in.end());
	for(char c : in)
	{
		if(mul>LIMIT)
			return INF;
		n += mul*dig(c);
		if(n>LIMIT)
			return INF;
		mul *= k;
	}
	reverse(in.begin(),in.end());
	return n;
}

int solve(int id,int b)
{
	int &ans = dp[id][b];
	if(ans!=-1) return ans;
	if(b<arr[id].S.S or (arr[id].S.F!=-1 and b!=arr[id].S.F))
		return ans = INF;
	ans = num(arr[id].F,b);
	if(ans==INF) return ans;
	int f = 0;
	for(int i=2;id!=1 and i<=36;i++)
	{
		if(ans==solve(id-1,i))
		{
			f=1;
			break;
		}
	}
	if(!f and id!=1) 
		ans = INF;
	return ans;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].S.F>>arr[i].F;
			arr[i].S.S = low(arr[i].F);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=36;j++) dp[i][j] = -1;
		}
		int ans = INF;
		for(int i=2;i<=36;i++)
		{
			ans = min(ans,solve(n,i));
		}
		cout << (ans!=INF?ans:-1) << endl;
	}

	return 0;
}
