#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
#define all(x) x.begin(),x.end()
using namespace std;
using pii=pair<int,int>;
template<class T> using max_heap=priority_queue<T>;
template<class T> using min_heap=priority_queue<T,vector<T>,greater<T>>;
template<class T> using uset=unordered_set<T>;
template<class A,class B> using umap=unordered_map<A,B>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline A abs(A &a) { return (a < 0 ? -a : a); }
template <class A> bool inLine(A y,A x,A my,A mx){return (x>=0&&y>=0&&x<mx&&y<my);}

const lol inf=(1LL<<62);
const int MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    cin >>n>>k;
    map<int,int> m;
    for(int i=0;i<k;i++){
        int d,g;
        cin >>d>>g;
        m[d]+= g;
    }
    int ans=0;
    int date=0;
    int cnt=n;
    for(auto p:m){
        // cout <<" "<<p.fi<<" "<<ans<<"\n";
        while(p.se>0){
            if(p.fi < date){
                ans += p.se;
                p.se = 0;
                break;
            }
            // cout <<p.se<<" "<<cnt<<"\n";
            int tmp=min(p.se,cnt);
            p.se -= tmp;
            cnt -= tmp;
            if(cnt == 0){
                cnt = n;
                date++;
            }
        }
    }
    cout <<ans<<"\n";
    return (0);
}