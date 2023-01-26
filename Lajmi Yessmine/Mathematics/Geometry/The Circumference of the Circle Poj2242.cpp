#include<iostream>
#include<cmath>
#include<iomanip>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
using namespace std;

const double pi = 3.141592653589793;
int main(void){
	FAST;
	double x1 , y1 , x2 , y2 , x3 , y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		double a1 = x2 - x1 , b1 = y2 - y1 , a2 = x3 - x1 , b2 = y3 - y1;
		double c1 = - a1*(x1+x2)/2 - b1*(y1+y2)/2 , c2 = - a2 *(x3+x1)/2 - b2*(y1+y3)/2;
		double x = 1.0/(a2*b1 - a1*b2)*(b2*c1-c2*b1) , y = 1.0/(a2*b1-a1*b2)*(a1*c2-a2*c1);
		double dist = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		cout<<fixed<<setprecision(2)<<2*pi*dist<<endl;
	}
	return 0;
}
