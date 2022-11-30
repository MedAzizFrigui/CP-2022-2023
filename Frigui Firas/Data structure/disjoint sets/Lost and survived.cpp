#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
const size_t N_MAX = 200000u;
typedef long long int ll;
 
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
 
 
int main(){	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int n,q,x1,x2;cin>>n>>q;
	disjointSets d=disjointSets(n);
	for (int i=0;i<q;i++){
		cin>>x1>>x2;
		d.merge(x1-1,x2-1);
		cout<<d.diff()<<endl;
	}
}