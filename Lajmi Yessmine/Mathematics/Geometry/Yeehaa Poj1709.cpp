#include<iostream>
#include<cmath>
#include<iomanip>

const double pi = 3.14159265358;
int main(void){
	int t;
	std::cin>>t;
	int n;
	double R;
	for(int i=1;i<=t;++i){
		std::cin>>R>>n;
		std::cout<<"Scenario #"<<i<<":\n";
		std::cout<<std::fixed<<std::setprecision(3)<<R*sin(pi/n)/(1.0+sin(pi/n))<<'\n';
		std::cout<<'\n';
	}
	return 0;
}
