#include <iostream>
#include <algorithm>
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
            sz[i] = 1u;
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
        parent[px]=py;
        sz[py]+=sz[px];
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
};
 
 
int main(){
	
	int t;
    cin >> t;
    for(int j=0;j<t;++t){
        int n, x1, x2;
        cin >> n;
		int cnt=0;
		string s1,s2;
		map<string,int> m;
		disjointSets disjoint_sets=disjointSets(2*n);
		for (int i=0;i<n;i++){
			cin>>s1>>s2;
			if(m.find(s1)!=m.end()){
				x1=m[s1];
			}
			else{
				x1=cnt;
				m[s1]=x1;
				cnt++;
			}
			if(m.find(s2)!=m.end()){
				x2=m[s2];
			}
			else{
				x2=cnt;
				m[s2]=x2;
				cnt++;
			}
			disjoint_sets.merge(x1,x2);
			cout<<disjoint_sets.sizeOfSet(x1)<<endl;
		}    
  }		
	
}   
