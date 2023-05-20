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

    int n,m;
    lol d;
    lol ans=-1;
    cin >>n>>m>>d;
    vector<lol> A(n),B(m);
    for(int i=0;i<n;i++) cin >>A[i];
    for(int i=0;i<m;i++) cin >>B[i];

    sort(A.begin(), A.end(), greater<lol>());
    sort(B.begin(), B.end(), greater<lol>());

    int a=0,b=0;
    while(abs(A[a]-B[b])>d){
        if(A[a]>B[b]) a++;
        else b++;
        if(a>=n) break;
        if(b>=m) break;
    }
    if(abs(A[a]-B[b])<=d) ans = A[a]+B[b];
    if(abs(A[a]-B[b])>d){
        a=0,b=0;
        while(abs(A[a]-B[b])>d){
            if(A[a]<B[b]) b++;
            else a++;
            if(a>=n) break;
            if(b>=m) break;
        }
    }
    if(abs(A[a]-B[b])>d) cout <<"-1\n";
    else{
        chmax(ans, A[a]+B[b]);
        cout <<ans<<"\n";
    }
    // for(auto a:A)cout <<" "<<a;
    // cout <<"\n";
    // for(auto a:B)cout <<" "<<a;
    // cout <<"\n";
    return (0);
}