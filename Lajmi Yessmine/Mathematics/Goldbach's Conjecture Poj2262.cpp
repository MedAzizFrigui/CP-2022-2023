#include <iostream>
#include<bitset>
#include<vector>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
using namespace std;
const int N = 1000001;
vector<int> v;
bitset<N> b;
void sieve(){
	b.set();
	b[0] = b[1] = 0 ;
	for(int i=2;i*i<N;++i){
		if(b[i]){
			v.push_back(i);
			for(int j=i*i;j<N;j+=i){
				b[j] = 0;
			}
		}
	}
}
int main(void){
	sieve();
	FAST;
	int n;
	cin>>n;
	while(n){
		for(int i=0;i<v.size();++i){
			if(b[n-v[i]]){
				//8 = 3 + 5
				cout<<n<<" = "<<v[i]<<" + "<<n-v[i]<<'\n';
				break;
			}
		}
		cin>>n;
	}
	return 0;
}
			
