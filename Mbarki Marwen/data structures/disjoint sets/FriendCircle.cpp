#include <iostream>
#include <algorithm>
#include <string>
#include <map>
const size_t N_MAX = 1u<<24u;
using namespace std;

class DisjointSets{
    size_t *parent=new size_t[N_MAX];
    size_t *sz=new size_t[N_MAX];
    size_t nbrSets;
public:
    DisjointSets(size_t n):nbrSets(n){
        for(size_t i=0u;i<nbrSets;++i){
            parent[i] = i;
            sz[i] = 1u;
        }
    }

    size_t find(size_t e){
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }

    bool merge(size_t x,size_t y){
        size_t px = find(x);
        size_t py = find(y);
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

    size_t sizeOfSet(size_t x){
        return sz[find(x)];
    }

    size_t numberOfSets(){
        return nbrSets;
    }

    bool sameSet(size_t x,size_t y){
        return find(x)==find(y);
    }
};
int main()
{
    int t,n;
    string a,b;
    map<string,int>M;
    cin>>t;
    while(t--){
        cin>>n;
        DisjointSets D(2*n);
        int k=1;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(M.find(a)==M.end()){
                M[a]=k;
                k++;
            }
            if(M.find(b)==M.end()){
                M[b]=k;
                k++;
            }
            D.merge(M[a],M[b]);
            cout<<D.sizeOfSet(M[a])<<endl;
        }
    }
    return 0;
}
