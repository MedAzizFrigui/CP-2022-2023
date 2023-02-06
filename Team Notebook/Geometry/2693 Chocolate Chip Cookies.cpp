#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


const double eps=numeric_limits<double>::epsilon();


struct Point {
    double x, y;
};

struct Line{
	double a,b,c; // ax+by+c=0
};

bool equals(double x, double y){
	if( fabs(x-y) < eps ) return true;
	return false;
}	

Point middle(Point A, Point B) {
    Point M;
    M.x = (A.x + B.x) / 2.0;
    M.y = (A.y + B.y) / 2.0;
    return M;
}

double dist(Point A, Point B){
    return  (A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y);
}

//mediatrice
Line bisector( Point A, Point B ){
	Line line ;
	if( equals(A.x,B.x) ){
		line.a=0.0;
		line.b=1.0;
		line.c=-(A.y + B.y ) / 2.0;
	}else if( equals(A.y,B.y) ){
		line.a=1.0;
		line.b=0.0;
		line.c=-(A.x+B.x) / 2.0 ;
	}else{
		Point M=middle(A,B);
		double alpha=-( B.x-A.x)/(B.y - A.y);
		line.a=alpha;
		line.b=-1.0;
		line.c=M.y-alpha*M.x;
	}
	return line;
}

Point pts[207];
int n=0,mx=1;

int countPts ( Point C ){
	int i,ret=0;
	for( i=0;i<n;++i ){
		if( dist( pts[i],C )  > 6.25 ) continue;
		++ret;
	}
	return ret;
}

int main(void) {
    double x, y;
    while(cin >> x >> y){
		pts[n].x=x;
		pts[n++].y=y;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
			double dx=pts[j].x-pts[i].x;
			double dy=pts[j].y-pts[i].y;
			
			Point M=middle(pts[i],pts[j]);
			
			double len=dx*dx+dy*dy ;//len=AB*AB
			if(len > 25.0) continue;
			int mx1,mx2;
			if(equals(len,25.0)){
				mx1=countPts(M);
			}else{
				Line mediatrice=bisector(pts[i],pts[j]);
				double OM=sqrt(6.25-len/4.0); // M=pts[i] * Pts[j]
				double norm=sqrt(mediatrice.a*mediatrice.a + mediatrice.b*mediatrice.b);
				double ex=fabs(mediatrice.b/norm);
				double ey=fabs(mediatrice.a/norm);
				Point center1;
				Point center2;
				center1.x=M.x+OM*ex;
				center1.y=M.y+OM*ey;
				center2.x=M.x-OM*ex;
				center2.y=M.y-OM*ey;
				mx1=countPts(center1);
				mx2=countPts(center2);
				mx1=mx1>mx2?mx1:mx2;
			}
			mx=mx<mx1?mx1:mx;
        }
    }
	
    cout<<mx;
    return 0;
}

