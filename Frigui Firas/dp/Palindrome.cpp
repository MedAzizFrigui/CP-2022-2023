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


short int dp[5000][5000];
string ch;
short int n;
short int trouve(short int i,short int j){
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(ch[i]==ch[j])
		return dp[i][j]=trouve(i+1,j-1);
	else
		return dp[i][j]=1+min(trouve(i+1,j),trouve(i,j-1));
}

int main(void){
	ios::sync_with_stdio(false);  cin.tie(0);
	cin>>n>>ch;
	for(short int i=0;i<n;++i)
		for(short int j=0;j<n;++j)
			dp[i][j]=-1;
	cout<<trouve(0,n-1)<<endl;
	return 0;
}