#include <algorithm>
#include <iostream>
#include<vector>
#include <iomanip>
#include <string>
#include <limits>
#include <utility>
#define endl '\n'  
# define PI           3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const size_t N=1000000ull,V=300ull,inf=1000000000ull;

ll dp[200000];
int main(void){
	
	//freopen("aaaahh.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);
	int n;
	string ch;
	while(cin>>ch,ch!="0"){
		n=ch.size();
		if(n==1){
			cout<<1<<endl;
			continue;}
		if(ch[n-1]!='0')
		dp[n-1]=1;
		else
			dp[n-1]=0;
		if(ch[n-2]<'2' || (ch[n-1]<'7' && ch[n-2]=='2'))
			dp[n-2]=dp[n-1]+1;
		else
			dp[n-2]=1;
		for(int i=n-3;i>=0;--i){
			if(ch[i+1]=='0')
				dp[i]=dp[i+2];
			else
			if((ch[i]<'2' || (ch[i+1]<'7' && ch[i]=='2'))&&(ch[i+2]!='0'))
				dp[i]=dp[i+1]+dp[i+2];
			else
				dp[i]=dp[i+1];
		}
		cout<<dp[0]<<endl;
	}
	
	return 0;
}