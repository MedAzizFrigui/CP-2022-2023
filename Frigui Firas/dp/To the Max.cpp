#include <algorithm>
#include <iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <utility>
# define PI           3.14159265358979323846
#define nl '\n'  
typedef long long ll;
using namespace std;
int ninf =-1*1e9;

int dp[100][100][100];
int pref[100][100];
int a[100][100];
int n;
int best(int i,int j,int s){
	if(dp[i][j][s]!=ninf)
		return dp[i][j][s];
	if(s==n)
		return 0;
	int inter;
	if(i!=0)
		inter=pref[s][j]-pref[s][i-1];
	else
		inter=pref[s][j];
	return dp[i][j][s]=inter+max(0, best(i,j,s+1));
}

int main(void){
	ios::sync_with_stdio(false);  cin.tie(0);
	cin>>n;
	int i=0,j=0;
	while(i<n){
		cin>>a[i][j];
		if(j!=0)
			pref[i][j]=pref[i][j-1]+a[i][j];
		else
			pref[i][j]=a[i][j];
		++j;
		if(j==n){
			++i;
			j=0;
		}
	}
	int ans=ninf;
	for(int s=0;s<n;++s)
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j)
				dp[i][j][s]=ninf;
	for(int s=0;s<n;++s)
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j)
				ans=max(ans,best(i,j,s));
	cout<<ans;
	return 0;
}