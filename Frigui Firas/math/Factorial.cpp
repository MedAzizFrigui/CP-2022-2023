#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstddef>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#pragma comment(linker, "/STACK:2000000")
const size_t N_MAX = 6000000u,N_INF=1000000000;
# define M_PI           3.14159265358979323846
typedef long long int ll;



int main(){	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int u,cnt=1;cin>>u;
	vector<int> po5;
	int i=5,nb=0;
	while(i<N_INF)
	{
		po5.push_back(i);
		i*=5;
		nb++;
	}
	while(u--){
		int n,ans=0;cin>>n;
		for (int i=0;i<nb;i++)
			ans+=n/po5[i];
		cout<<ans<<endl;
			
	}		
	
	
	
}
  