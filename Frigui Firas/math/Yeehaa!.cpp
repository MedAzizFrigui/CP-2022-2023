#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstddef>
#include <cmath>
#include <iomanip>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#pragma comment(linker, "/STACK:2000000")
const size_t N_MAX = 6000000u;
# define M_PI           3.14159265358979323846
typedef long long int ll;



int main(){	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int u,cnt=1;cin>>u;
	while(u--){
		cout<<"Scenario #"<<cnt<<":"<<endl;
		double r,alpha,n,ans;
		cin>>r>>n;
		alpha=(2*M_PI/n);
		double s=sin(alpha),c=2*cos(alpha/2);
		ans=r*s/(s+c);
		cout<<fixed<<setprecision(3)<<ans<<endl;
		++cnt;
		cout<<endl;
	}		
	
	
	
}
  