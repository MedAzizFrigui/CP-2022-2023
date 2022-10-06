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
