#include <iostream>
#include<vector>
#include <map>


using namespace std;




const size_t MAXN =1<<24;
using namespace std;

class disjointSets{
  size_t *parent= new size_t[MAXN];
	size_t *sz=new size_t[MAXN];
	size_t nbrSets;

public:
    disjointSets(size_t n):nbrSets(n){
       for(size_t i=0u;i<nbrSets;++i){
            parent[i] = i;
            sz[i] = 1u;
       }
    }

    size_t find(size_t e){
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }

    bool merge(size_t x , size_t y){
        size_t px = find(x);
        size_t py = find(y);

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
        return find(x)==find(y) ;
    }
};

    #define ll long long int

//map <ll,ll> vz;

map < ll, vector <ll> > tab;
ll rs[1000000];
int main()
{
    ll l,n,m,r,c,q;
    cin >> n;
    cin >> q;
    for(int i=0;i<q;++i){
        cin >> l;
        cin >> r;
        cin >> c;
        tab[i].push_back(l);
        tab[i].push_back(r);
        tab[i].push_back(c);
    }
        disjointSets ds(n+10);
        for(int i=q-1;i>=0;--i){
            l=tab[i][0];
            r=tab[i][1];
            c=tab[i][2];
            for (int j=ds.find(l);j<=r;j++){
                j=ds.find(j);
                rs[j]=c;
                ds.merge(j,r+1);
            }
    }
    for (int i=1;i<=n;++i){
        cout << rs[i]<< endl;
    }




    return 0;
}
