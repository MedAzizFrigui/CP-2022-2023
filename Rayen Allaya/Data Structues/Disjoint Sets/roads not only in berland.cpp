#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second

const size_t MAXN = 1<<24;

class dsu{
    size_t *parent = new size_t[MAXN];
    size_t *sz = new size_t[MAXN];
    size_t nbr;
public:
    dsu(size_t n):nbr(n){
        for(size_t i=0;i<nbr;i++){
            parent[i] = i;
            sz[i] = 1u;
        }
    }

    size_t find(size_t p){
        return parent[p]==p?p:parent[p]=find(parent[p]);
    }

    bool merge(size_t p,size_t s){
        size_t pv = find(p);
        size_t sv = find(s);
        if(pv==sv){
            return false;
        }
        if(sz[pv]<sz[sv]){
            swap(pv,sv);
        }
        parent[sv]=pv;
        sz[pv]+=sz[sv];
        --nbr;
        return true;
    }

    size_t nbrOfSets(){
        return nbr;
    }

    bool sameSet(size_t p,size_t v){
        return find(p)==find(v);
    }

    size_t sizeOfSet(size_t p){
        return sz[find(p)];
    }
};

int main()
{
    int n;cin>>n;
    dsu uf(n);
    vector<pair<int,int>> un_roads;
    int x,y;
    for (int i=0;i<n-1;i++){
        cin>>x>>y;
        if (!uf.merge(x-1,y-1)){
            un_roads.push_back({x,y});
        }
    }
    int k=0;
    cout<<un_roads.size()<<"\n";
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(uf.merge(i-1,j-1)){
                cout<<un_roads[k].f<<" "<<un_roads[k].s<<" "<<i<<" "<<j<<"\n";
                k++;
            }
        }
    }
    return 0;
}
