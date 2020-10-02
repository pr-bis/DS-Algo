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

int main()
{
	boost
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll pos=0,neg=0,flag=-1;
		ll sum=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]>=0&&flag!=0)
			{
				pos=max(pos,a[i]);
				sum+=neg;
				neg=-inf;
				flag=0;
			}
			else if(a[i]<0&&flag!=1)
			{
				if(neg==0)
					neg=-inf;
				neg=max(neg,a[i]);
				sum+=pos;
				pos=0;
				flag=1;
			}
			else if(a[i]>0&&flag==0)
			{
				pos=max(pos,a[i]);
			}
			else if(a[i]<0&&flag==1)
				neg=max(neg,a[i]);
		}
		if(flag==0&&neg!=-inf)
			sum+=neg;
		else
			sum+=pos;
		cout<<sum<<endl;
	}

	return 0;
}