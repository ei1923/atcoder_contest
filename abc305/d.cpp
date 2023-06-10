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

    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >>a[i];
    
    vector<int> rui(n);
    for(int i=2;i<n;i+=2){
        rui[i] = (a[i]-a[i-1]);
    }
    for(int i=1;i<n;i++) rui[i] += rui[i-1];
    // for(int i=0;i<n;i++) cout <<" "<<rui[i];
    // cout <<"\n";
    int q;
    cin >>q;
    while(q--){
        int l,r;
        cin >>l>>r;
        auto lower = upper_bound(a.begin(), a.end(), l);
        auto upper = lower_bound(a.begin(), a.end(), r);
        size_t L = distance(a.begin(), lower);
        size_t R = distance(a.begin(), upper);
        int ans=rui[R]-rui[L-1];

        if(L!=0 && L%2==0){// 寝てる時間
            ans -= l-a[L-1];
            // cout <<"  "<<ans<<"  "<<l-a[L-1]<<"\n";
        }

        if(R!=0 && R%2==0){// 寝てる時間
            ans -= a[R]-r;
            // cout <<ans<<" "<<a[R]-r<<"\n";
        }
        // cout <<L<<" "<<R<<"\n";
        cout <<ans<<"\n";
    }

    return (0);
}