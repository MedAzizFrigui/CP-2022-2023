#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double pi=3.141592653589793;

int main()
{
    double x1,x2,x3,y1,y2,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		double a,b,c;
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		double p=(a+b+c)/2;
		cout<<fixed<<setprecision(2)<<pi*(a*b*c)/(2*sqrt(p*(p-a)*(p-b)*(p-c)))<<endl;	
    }
}
