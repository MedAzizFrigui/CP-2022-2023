#include <iostream>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define ull unsigned long long

const size_t MAXN = 1<<30;

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

int main(void)
{
    ull _;cin>>_;
    while(_--){
       ull n,m;cin>>n>>m;
        bool milk[n];
        pair<ull,pair<ull,ull>> graphe[m];
        dsu uf(n+1);
        for(ull i=0;i<n;i++){
            cin>>milk[i];
            if(milk[i]){
                uf.merge(0,i+1);
            }
        }
        for(ull i=0;i<m;i++){
            cin >> graphe[i].s.f>>graphe[i].s.s>>graphe[i].f;
        }
        sort(graphe,graphe+m);
        ull S=0;
        for(ull i=0;i<m;i++){
            if (uf.nbrOfSets()==1){
                break;
            }
            if(uf.merge(graphe[i].s.f,graphe[i].s.s)){
                S+=graphe[i].f;
            }
        }
        if(uf.nbrOfSets()==1){
            cout<<S<<"\n";
        }else{
            cout<<"impossible\n";
        }
    }
    return 0;
}
