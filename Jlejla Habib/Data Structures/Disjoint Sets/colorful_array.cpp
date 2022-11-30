#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;

const size_t N_MAX = 200000u;

typedef long long int ll;
 
class disjointSets{
    int parent[N_MAX];
    int sz[N_MAX];
    int nbrSets;
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0u;i<nbrSets;i++){
            parent[i] = i;
       }
    }
 
    int find(int e){
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }
 
    bool merge(int x , int y){
        int px = find(x);
        int py = find(y);

        parent[px]=py;
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
};
int main(){
    int n,q;
    cin >> n >> q;
	disjointSets disjointSet = disjointSets(n+1);
	int rep[n];
	fill_n(rep,n,0);
	int query_l[q];
	int query_r[q];
	int query_c[q];
	for(int i=0;i<q;i++)
		cin >> query_l[i] >> query_r[i] >> query_c[i];
	for (int i=q-1;i>=0;--i){
		for(int k=disjointSet.find(query_l[i]-1);k<query_r[i];k=disjointSet.find(k)){
			rep[k]=query_c[i];
			disjointSet.merge(k++,k);
		}
	}
	for (int i=0;i<n;++i){
		cout << rep[i] << endl;
    }
    return 0;
}