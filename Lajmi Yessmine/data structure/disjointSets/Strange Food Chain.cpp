#include <algorithm>
#include <iostream>
#include<stack>
using namespace std;
const size_t N=50000;
class disjointSets{
	size_t * parent=new size_t[N];
	size_t * sz = new size_t[N];
	int * distance = new int[N];
	size_t nbrOfSets;
	public:
	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent[i] = i;
			sz[i] = 1u;
			distance[i] = 0;
		}
	}
	size_t find(size_t x){
	    size_t y , z;
	    stack<int> s ;
		while(x!=parent[x]){
            s.push(x);
		    x = parent[x];
       }
       while(!s.empty()){
        y = s.top();
        s.pop();
        distance[y]+=distance[parent[y]];
		distance[y]%=3;
        parent[y]=x;
       }
       return x;
	}
	bool merge(size_t x , size_t y , int dist){
		size_t px = find(x), py = find(y) , d= (distance[y]-distance[x]+dist+3)%3;
		if(px==py){
			return false;
		}
		if(sz[px]>sz[py]){
			swap(px,py);
			d=(2*d)%3;
		}
        distance[px] = d;
		parent[px] = py;
		sz[py]+=sz[px];
		sz[px]= 0u;
		--nbrOfSets;
		return true;
	}
	bool sameSet(size_t x, size_t y){
		return find(x)==find(y);
	}

	int getDistance(size_t x){
		return distance[x];
	}
};

int main(void){
	int t;
	cin>>t;
	while(t--){
		size_t n , q , mistakes=0u;
		cin>>n>>q;
		disjointSets d(n);
		while(q--){
			size_t ty, x, y ;
			cin>>ty>>x>>y;
			if(x>n || y>n ){
				++mistakes;
				continue;
			}
			--x;
			--y;
			if(ty==1){
				if(!d.merge(x,y,0)){
					if(d.getDistance(x)%3!=d.getDistance(y)%3)
						++mistakes;
				}
				continue;
			}
			if(!d.merge(x,y,1)){
				if(((d.getDistance(x)-d.getDistance(y)+3)%3!=1) && ((d.getDistance(x)-d.getDistance(y))%3!=-2)){
					++mistakes;
				}
				continue;
			}
		}
		cout<<mistakes<<endl;
	}
	return 0;
}
