#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define iyed std::ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define endl '\n'
//vector <ll > graph[N] ;
//int color[N] ;
//ll dis[N] ;
//bool vis[N] ;
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define yes cout << "YES" << endl
#define mp make_pair
#define pb push_back
#define no cout << "NO" << endl
const int N=8e5 +10 ;
const double INF = 1e8 ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){
    int n , x;
    cin>>n ;
    x = sqrt(n) ;
    bool b = true ;
    for (int i = 2; i<= x ; i++) {
        if (n%i == 0) {
            b = false;
            break;
        }
    }
    if (b) yes ;
    else no ;
}

int  main() {
    //freopen("orxor.in","r",stdin) ;
    iyed;
    ll nbt=1  ;
    cin >>nbt ;
    while(nbt--) {
        solve() ;
    }
    return 0;
}
/*
 *********************GRAPH****************************
 * TREE[m/2 + i -1] = (query(i,i) >= k)
ll DFS(ll root , bool b ) {

    //cout<<root<<" " ;
    ll ans = a[root] ;
    vis[root] = b ;
    for (auto child : graph[root]) {
        if (vis[child] != b ) ans = min(DFS(child ,b ) , ans) ;
    }
    return ans ;
}
ll findCatalan(int n ) {
    if (n<2 ) return 1 ;
    return 2*n*(2*n-1) * findCatalan(n-1) / (n+2) ;
}
void solve() {
    cin>>n ;
    cout<<findCatalan(n)<<endl ;
}
 -----------------------SEG a-----------------------

-------------------------------------------------------
ll n,k ;
ll  a[N],lazy[N] ;
bool upd [N] ;
ll f(int a , int b) {return a+b ;  }
ll g(int l , int r , int v){ return (r-l+1)*v ; }


cout<<"left = "<<l<<" node = "<<a[l].l<<","<<a[l].r<<endl ;
cout<<"right = "<<r<<" node = "<<a[r].l<<","<<a[r].r<<endl ;
cout<<"id = "<<id<<" ns = "<<ns<<" ne = "<<ne<<" node = "<<a[id].l<<","<<a[id].r<<endl ;

void update_node(int id , int ns , int ne , int t){
    upd[id] = 1 ;
    lazy[id] = f(lazy[id] , t) ;
    a[id] = f(g(ns,ne,t ) , a[id] ) ;
}
void unlazy(int id , int ns, int ne){
    if (!upd) return ;
    if(ns != ne) {
        upd[id] = 0 ;
        int l = 2*id+1,  r = l+1 , mid = (ne+ns)/2 ;
        update_node(l,ns,mid,lazy[id]) ;
        update_node(r,mid+1,ne,lazy[id]) ;
        lazy[id] = 0 ;
    }
}
ll query(int ql, int qr ,int id = 0 , int ns = 0 , int ne = k-1){
    unlazy(id,ns,ne) ;
    if (qr<ns || ql > ne) return 0 ;
    if (ql<=ns && ne<=qr) return a[id] ;
    int l = 2*id + 1 , r = l+1 , mid = (ns+ne)/2 ;
    return f(query(ql,qr,l,ns,mid), query(ql,qr,r,mid+1,ne)) ;
}

void update(int qs, int qe, int t ,int id = 0 ,int ns = 0 , int ne = k-1){
    unlazy(id,ns,ne) ;
    if (qe<ns || qs > ne) return ;
    if (qs<=ns && ne<=qe) {
        update_node(id,ns,ne,t) ;
        return ;
    }
    int l = 2*id + 1 , r = l+1 , mid = (ns+ne)/2 ;
    update(qs,qe,t,l,ns,mid) ;
    update(qs,qe,t,r,mid+1,ne) ;
    a[id]= f(a[l] , a[r]) ;
}
void solve() {
    int t, l , r,v , q ;
    bool Q ;
    cin>>n>>q ;
    k = 1 ;
    while(n>k) k *= 2 ;
    memset(a,0,sizeof(a)) ;
    memset(lazy,0,sizeof(lazy)) ;
    memset(upd,false,sizeof(upd)) ;
    while(q--) {
        cin>>Q>>l>>r ;
        l--;r-- ;
        if (!Q){
            cin>>v ;
            update(l , r,v);
        }
        else {  cout << query(l, r) << endl; }
    }
}
int  main() {
    iyed;
    ll nbt = 1 ;
    cin >>nbt ;
    while (nbt--) {
        solve() ;
    }
    return 0;
}

*/
