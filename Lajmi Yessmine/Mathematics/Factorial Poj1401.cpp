#include<iostream>

int main(void){
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		int k = 25;
		int i=2;
		int s5 = n/5;
		while(n/k){
			s5+=n/k;
			++i;
			k*=5;
		}
		std::cout<<s5<<'\n';
	}
	return 0;
}
