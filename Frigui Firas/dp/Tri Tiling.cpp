#include <algorithm>
#include <iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <algorithm> 
#include <limits>
#include <utility>
# define PI           3.14159265358979323846
using namespace std;
const size_t N=50000;
double INF=1000000000.0;
const long double EPS = numeric_limits<double>::epsilon();
int dp[N];
int f(int i){
	if (dp[i]!=-1)
		return dp[i]; 
	if (i==1)
		return 0;
	if (i&1)
		return dp[i]=f(i-3)+f(i-2);
	if (!i)
		return 1;
	return dp[i]=3*f(i-2)+2*f(i-1);
}


int main(void){
	int n;
	fill_n(dp,N,-1);
	while(cin>>n,n!=-1)
		if (n&1)
			cout<<0<<endl;
		else
			cout<<f(n)<<endl;
	return 0;
}
 