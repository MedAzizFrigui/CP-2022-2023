#include <algorithm>
#include <iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <algorithm> 
#include <limits>
#include <utility>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v.begin(),v.end())
#define rall(v) (v.rbegin(),v.rend())
#define F ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0)
#define endl '\n'  
# define PI           3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const size_t N=50000ull,V=300ull,inf=1000000000ull;
int dp[V][V];
int a[V];
int best (int i,int j,int p,int left,int right){
	if (j-i+1==p)
		return 0;
	if (i>j)
		return inf;
	if (dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j];
}
int main(void){
	
	int u;cin>>u;
	while(u--){
		ll n,f,b,m,x;cin>>n>>f>>b;
		vector<ll> v;
		for(int i=0;i<n;++i){
			cin>>x>>m;
			if (m)
				v.push_back(3*f-x);
			else
				v.push_back(f+x);
		}
		sort(v.begin(),v.end());
		ll ans=0;
		if(b>n){
			ans+=v[n-1];
			b-=n;
			ans+=(2*f)*(b/n);
			if(b%n)
				ans+=2*f-v[n-1]+v[b%n-1];		
		}
		else
			ans+=v[b-1];
		cout<<ans<<endl;
	}
	return 0;
}
 