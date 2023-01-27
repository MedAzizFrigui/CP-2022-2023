#include <algorithm>
#include <iostream>
#include<vector>
#include <iomanip>
#include <limits>
#include <utility>
#define endl '\n'  
# define PI           3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const size_t N=10000ull,V=300ull,inf=1000000000ull;

int a[300];
int dp[300][31];
int trouve(int i,int p,int sup){
	if (dp[i][p]!=-1)
		return dp[i][p];
	int best=inf,prev=0;
	if (i<p-1)
		return inf;
	if (p==0){
		for(int k=0;k<=i;++k)
			prev+=sup-a[k];
		best=prev;
	}
	else
	for (int j=i;j>=p-1;--j){
		for(int k=j+1;k<=i;++k)
			prev+=min(a[k]-a[j],sup-a[k]);
		best=min(best,trouve(j-1,p-1,a[j])+prev);
		prev=0;
	}
	
	return dp[i][p]=best;
}

int main(void){
	
	//freopen("aaaahh.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);
	int v,p;cin>>v>>p;
	for (int i=0;i<v;++i){
		cin>>a[i];
		for(int k=0;k<=p;++k)
			dp[i][k]=-1;
	}
	cout<<trouve(v-1,p,inf)<<endl;
		
	
	return 0;
}