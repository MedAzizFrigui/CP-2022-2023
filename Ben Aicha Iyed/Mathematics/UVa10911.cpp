#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define iyed std::ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define endl '\n'
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
void solve() {
//    fill_n(vis,N,false) ;
    ll c = 0 ;
    while(true) {
        c++ ;
        ll n , mi ,x , y ,a,b ,dis;
        string s ;
        cin>>n ;
        n *= 2 ;
        if (n == 0 ) break;
        vector< pair <ll , ll>> v ;
        set <int> participant ;
        double ans = 0 ;
        for (ll i = 0 ; i<n ; i++) {
            cin>>s>>x>>y ;
            v.pb({x,y}) ;
        }
        for (ll i = 0 ; i <n-1 ; i++){
            if (participant.find(i) == participant.end()) {
                participant.insert(i) ;
                mi = INF;
                x = v[i].first;
                y = v[i].second;
                int k = n ;
                for (ll j = i + 1; j < n; j++)
                    if (participant.find(j) == participant.end()) {
                        a = v[j].first;
                        b = v[j].second;
                        dis = pow(a - x, 2) + pow(b - y, 2);
                        if (dis < mi) k = j ;
                        mi = min(mi, dis);
                    }
                     else mi = 0 ;
                ans += sqrt(mi);
                participant.insert(k) ;
            }
        }
        cout<<"Case "<<c<<": "<<fixed<<ans<<endl ;
        v.clear() ;
        participant.clear() ;
    }
}
int  main() {
    //freopen("orxor.in","r",stdin) ;
    iyed;
    int t = 1 ;
//    cin>>t ;
    while(t--)
        solve() ;
    return 0;
}
