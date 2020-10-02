#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 500004
#define F first
#define S second
#define INF 1e15
#define pii pair<int,int>
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<int> graph[MAX];
int n,m,qu;
int ans[MAX];
int temp[1000010];
class Ftree
{
	std::vector<int> BIT;
	int s;
public:
	Ftree(int sz)
	{
		BIT.resize(sz,0);
		s = sz;
	}
	void update(int x, int delta)
	{
    	  for(; x < s; x += x&-x)
        	BIT[x] += delta;
	}
	int query(int x)
	{
    	 int sum = 0;
     	for(; x > 0; x -= x&-x)
        	sum += BIT[x];
     	return sum;
	}
};
Ftree tree(1000010);
int OFF = 0;
vector<pii> q[MAX][2];
void handleleaf(int v,int h)
{
	int curr = 0;
	int i = 0, j = 0;
	while(i<q[v][0].size() and j<q[v][1].size())
	{
		if(q[v][0][i].F < q[v][1][j].F)
		{
			ans[q[v][0][i].F] = tree.query(q[v][0][i].F+OFF-h)+curr;
			i++;
			//cout << q[v][0][i].F << " " <<  v << endl;
		}
		else
		{
			curr += q[v][1][j++].S;
		}
	}
	while(i<q[v][0].size())
	{
		ans[q[v][0][i].F] = tree.query(q[v][0][i].F+OFF-h)+curr;
		i++;
		//cout << q[v][0][i].F << " " <<  v << endl;
	}
}
void dfs(int v,int p,int h)
{
	//cout << v << endl;
	if(n==1 or (v!=1 and graph[v].size()==1)) // leaves
	{
		handleleaf(v,h);
		return;
	}
	for(pii& u : q[v][0] )
	{
		//cout<<u.F<<" "<<u.S<<endl;
		ans[u.F] = temp[OFF+u.F-h];
	}
	for(pii &u : q[v][1])
	{
		//cout<<u.F<<" "<<u.S<<endl;
		temp[u.F+OFF-h] += u.S;
		tree.update(u.F+OFF-h,u.S);
	}
	for(int u : graph[v])
	{
		if(u==p) continue;
		dfs(u,v,h+1);
	}
	for(pii &u : q[v][1])
	{
		temp[u.F+OFF-h] -= u.S;
		tree.update(u.F+OFF-h,-u.S);
	}
}
int getht(int v,int h,int p)
{
	int maxi = h;
	for(int u : graph[v])
	{
		if(u==p) continue;
		maxi = max(getht(u,h+1,v),maxi);
	}
	return maxi;
}
int32_t main()
{
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	cin >> n >> qu;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	//	cerr << x << " " << y << endl;
	}
	for(int i=0;i<=qu;i++) ans[i] = -1;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		q[i][1].pb({-1,t});
	}
	for(int i = 0;i<qu;i++)
	{
		char c;
		int a,b;
		cin>>c>>a;
	//	cout << c << " " << a << endl;
		if(c=='?')
		{
			q[a][0].pb(make_pair(i,-1));
		}
		else
		{
			cin>>b;
			q[a][1].pb(make_pair(i,b));
		}
	}
	OFF = getht(1,0,-1)+5;
	//cout << OFF << endl;
	dfs(1,-1,0);
	/*for(int i=1;i<=n;i++)
	{
		cout <<">>>>" << i << endl;
		for(int j = 0; j<2;j++ )
		{
			for(pii u : q[i][j])
			{
				cout << u.F << u.S << endl;
			}
		}
	}*/
	for(int i=0;i<qu;i++)
	{
		if(ans[i]!=-1) cout <<ans[i] << endl;
	}
	return 0;
}
