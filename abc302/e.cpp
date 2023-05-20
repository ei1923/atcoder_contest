#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline A abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const int MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,Q;
    cin >>N>>Q;
    vector<int> cnt(N+1,0);
    vector<unordered_set<int>> s(N+1);
    int ans=N;
    for(int i=0;i<Q;i++){
        int k,u,v;
        cin >>k;
        if(k==1){
            cin >>u>>v;
            cnt[u]++;
            cnt[v]++;
            s[u].insert(v);
            s[v].insert(u);
            if(cnt[u]==1) ans--;
            if(cnt[v]==1) ans--;
        }else{
            cin >>v;
            for(auto j:s[v]){
                cnt[j]--;
                cnt[v]--;
                s[j].erase(v);
                if(cnt[j]==0) ans++;
                if(cnt[v]==0) ans++;
            }
            cnt[v] = 0;
            
            s[v].clear();
        }
        // cout <<"\n";
        // for(int j=1;j<=N;j++){
        //     for(auto i:s[j]){
        //         cout <<" "<<i;
        //     }cout <<"\n";
        // }
        cout <<ans<<"\n";
    }

    return (0);
}