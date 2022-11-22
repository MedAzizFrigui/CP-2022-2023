#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
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
	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int u;cin>>u;
	while(u--){
		
		int n,x1,x2;cin>>n;
		int cnt=0;
		string ch1,ch2;
		map<string,int> m;
		disjointSets d=disjointSets(2*n);
		for (int i=0;i<n;i++){
			cin>>ch1>>ch2;
			if(m.find(ch1)!=m.end()){
				x1=m[ch1];
			}
			else{
				x1=cnt;
				m[ch1]=x1;
				cnt++;
			}
			if(m.find(ch2)!=m.end()){
				x2=m[ch2];
			}
			else{
				x2=cnt;
				m[ch2]=x2;
				cnt++;
			}
			d.merge(x1,x2);
			cout<<d.sizeOfSet(x1)<<endl;
		}
		
		
	}
	
}    
