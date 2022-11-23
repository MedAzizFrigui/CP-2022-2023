#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <cstddef>
using namespace std;
const size_t N_MAX = 200000u;
 
class disjointSets{
    int parent[N_MAX];
    int sz[N_MAX];
    int nbrSets;
	multiset<int> s;
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0u;i<nbrSets;i++){
            parent[i] = i;
            sz[i] = 1u;
			s.insert(1);
       }
    }
 
    int find(int e){
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }
 
    bool merge(int x , int y){
        int px = find(x);
        int py = find(y);
        if(px==py){
            return false;
        }
        if(sz[px]>sz[py]){
            swap(px,py);
        }
		s.erase(s.lower_bound(sz[py]));
		sz[py]+=sz[px];
		s.erase(s.lower_bound(sz[px]));
		s.insert(sz[py]);
        parent[px]=py;
        sz[px]=0u;
        --nbrSets;
        return true;
    }
 
    int sizeOfSet(int x){
        return sz[find(x)];
    }
 
    int numberOfSets(){
        return nbrSets;
    }
 
    bool sameSet(int x,int y){
        return find(x)==find(y) ;
    }
	int diff(){
		return *(s.rbegin())-*(s.begin()) ;
	}
};
 
 
int main(void){	
	int n,q,y1,y2;
    cin >> n >> q;
	disjointSets disjoint_sets=disjointSets(n);
	for (int i=0;i<q;++i){
		cin >> y1 >> y2;
		disjoint_sets.merge(y1-1,y2-1);
		cout<<disjoint_sets.diff()<<endl;
	}
    return 0;
}
