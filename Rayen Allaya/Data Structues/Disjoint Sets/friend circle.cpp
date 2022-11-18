#include <iostream>
#include <unordered_map>

using namespace std;

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

    size_t nbrSets(){
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
    int _;cin >> _;
    while(_--){
        int n;cin>>n;
        dsu uf(n<<1);
        unordered_map<string,int> d;
        string aux;int k=0;
        int a,b;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(d.find(aux)==d.end()){
                d[aux]=k;
                k++;
            }
            a=d[aux];
            cin>>aux;
            if(d.find(aux)==d.end()){
                d[aux]=k;
                k++;
            }
            b=d[aux];
            uf.merge(a,b);
            cout <<uf.sizeOfSet(a)<<"\n";
        }
    }
    return 0;
}
