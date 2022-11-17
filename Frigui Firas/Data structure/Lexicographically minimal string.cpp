#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
const size_t N_MAX = 60000u;
typedef long long int ll;
 
class disjointSets{
    int parent[N_MAX];
    int sz[N_MAX];
    int nbrSets;
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0;i<nbrSets;i++){
            parent[i] = i;
            sz[i] = 1;
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
        if(px<py){
            swap(px,py);
        } 
        parent[px]=py;
        sz[py]+=sz[px];
        sz[px]=0;
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
};
 
int main(){
    FAST;
    string a,b,c;cin>>a>>b>>c;
	char k;
	int n=a.length(),nc=c.length();
	disjointSets d=disjointSets(26);
	for(int i=0;i<n;++i)
		d.merge(a[i]-'a',b[i]-'a');
	for(int i=0;i<nc;++i){
		k='a'+d.find(c[i]-'a');
		cout<<k;
	}
}
