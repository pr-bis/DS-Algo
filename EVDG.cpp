#include<bits/stdc++.h>
using namespace std;
#define MAX 1000003
vector<int> graph[MAX];
#define pb push_back
bool od;
int ed,t,n,m;
std::vector<vector<int>> ol[3];
int vis[MAX];
int deg[MAX];
void reset()
{
	for(int i=1;i<=n;i++)
	{
		deg[i] = vis[i] = 0;
		graph[i].clear();
	}
	for(int i=0;i<3;i++) ol[i].clear();
}
void print(vector<int> & ans,int p)
{
	cout << p << endl;
	for(int i=1;i<=n;i++)
		cout << ans[i] << " "; 
	cout << endl;
}
int c(std::vector<int>& ans,int k)
{
	int ec[k+1] = {0};
	for(int i=1;i<=n;i++)
	{
		for(int v : graph[i])
		{
			if(ans[i]==ans[v]) ec[ans[i]]++;
		}
	}
	for(int i = 1;i<=k;i++)
	{
		ec[i] >>=1;
		if(ec[i]&1) return 0;
	}
	return 1;
}
int recur(int id,std::vector<int> &ans,int k)
{
	if(id == n+1)
	{
		if(c(ans,k))
		{
			print(ans,k);
			return true;
		}
		return false;
	}
	for(int i = 1;i<=k;i++)
	{
		ans[id] = i;
		if(recur(id+1,ans,k)) return true;
	}
	return false;
}
void bypass()
{
	vector<int> ans(n+1);
	if(recur(1,ans,2)) return;
	recur(1,ans,3);
}
void handle2(vector<int>& ans)
{
	int f = 0;
	for(int u : ol[1][0])
	{
		if(deg[u]%2==1)
		{
			f = u;
			break;
		}
	}
	ans[f] = 2;
}
void handle3(std::vector<int>& ans)
{
	int a , b;
	int fl = 0;
	for(std::vector<int> v: ol[2])
	{
		
		if(fl) break;
		for(int u : v)
		{
			if(graph[u].size()!=0)
			{
				a = u;
				fl = 1;
				b = graph[a][0];
				break;
			}
		}
	}
	ans[a] = 2;
	ans[b] = 3;
}
void solve()
{
	vector<int> ans(n+1,0);
	int a = 2;
	if(ol[1].size()==0)
	{
		handle3(ans);
		a = 3;
	}
	else
		handle2(ans);
	for(int i=0;i<3;i++)
	{
		for(std::vector<int> v : ol[i])
		{
			for(int u:v)
			{
				if(ans[u]==0) ans[u] = 1; 
			}
		}
	}
	print(ans,a);	
}

void dfs(int u,std::vector<int>& s)
{
	vis[u] = 1;
	od = od or deg[u]%2==1;
	s.pb(u);
	ed+=deg[u];
	for(int v : graph[u])
	{
		if(!vis[v])
		{
			dfs(v,s);
		}
	}
}
void collect()
{
	for( int i = 1; i <= n ; i++ )
	{
		if(vis[i]) continue;
		od = false;
		ed = 0;
		vector<int> s;
		dfs(i,s);
		ed = ed/2;
		if(ed%2==0)
		{
			ol[0].pb(s);
			continue;
		}
		if( od )
		{
			ol[1].pb(s);
			continue;
		}
		ol[2].pb(s);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		reset();
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			deg[a]++;
			deg[b]++;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		if(m%2==0)
		{
			cout << 1 << endl;
			for(int i=0;i<n;i++) cout << 1 << " ";
			cout << endl;
			continue;
		}
		if(n<=10)
		{
			bypass();
			continue;
		}
		collect();
		solve();
	}
}
