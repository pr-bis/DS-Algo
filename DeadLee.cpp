/*
  Vivek Rathi
  CSE 3rd Year
  MNNIT
  THUMB RULE - THINK FOR DP FIRST AND THEN GREEDY!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define sz(x)	(ll)x.size()
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
#define flush fflush(stdout);
#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above-----------------------------------------------
vector<pair<ll,ll> > v[100001];
ll visited[100001];
ll visited2[200001];
vector<ll> ts;
int main()
{
	boost
	ll n,m;
	cin>>n>>m;
	ll w[n+1]={0};
	ll deg[n+1]={0};
	for(ll i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		deg[x]++,deg[y]++;
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
	}
	ll flag=0;
	queue<ll> q;
	for(ll i=1;i<=n;i++)
	{
		if(deg[i]<=w[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		ll ver = q.front();
		q.pop();
		if(visited[ver]!=0)
			continue;
		visited[ver]=1;
		for(ll i=0;i<v[ver].size();i++)
		{
			if(visited2[v[ver][i].se]==0)
			{
				deg[v[ver][i].fi]--;
				visited2[v[ver][i].se]=1;
				ts.pb(v[ver][i].se);
				if(visited[v[ver][i].fi]==0&&deg[v[ver][i].fi]<=w[v[ver][i].fi])
					q.push(v[ver][i].fi);
			}
		}
	}
	//ll flag=0;
	for(ll i=1;i<=n;i++)
		if(visited[i]==0)
			flag=1;
	if(flag==1)
		cout<<"DEAD"<<endl;
	else
	{
		cout<<"ALIVE"<<endl;
		reverse(ts.begin(),ts.end());
		for(ll i=0;i<ts.size();i++)
			cout<<ts[i]+1<<" ";
	}
	return 0;
}