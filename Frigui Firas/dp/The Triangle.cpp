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


int main(void){
	
	int n;cin>>n;
	int tri[100][100];
	int dp[100][100];
	for (int i=0;i<n;++i)
		for (int j=0;j<=i;++j){
			cin>>tri[i][j];
			if (i==n-1)
				dp[i][j]=tri[i][j];
		}
	for (int i=n-2;i>=0;--i)
		for (int j=0;j<=i;j++)
			dp[i][j]=tri[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
	cout<<dp[0][0]<<endl;
	return 0;
}
 