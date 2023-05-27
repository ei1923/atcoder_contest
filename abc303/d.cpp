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

    lol ans = inf;
    lol x,y,z;
    cin >>x>>y>>z;
    string s;
    cin >>s;
    int n=s.size();

    vector<vector<lol>> dp(n+1,vector<lol>(2));
    for(int i=1;i<=n;i++){
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    dp[0][0] = 0;
    dp[0][1] = z;

    for(int i=0;i<n;i++){
        char c = s[i];
        chmin(dp[i][1], dp[i][0]+z);
        chmin(dp[i][0], dp[i][1]+z);
        if(c=='a'){
            chmin(dp[i+1][0], dp[i][0]+x);
            chmin(dp[i+1][1], dp[i][1]+y);
            chmin(dp[i+1][0], dp[i][1]+z+x);
        }
        if(c=='A'){
            chmin(dp[i+1][1], dp[i][1]+x);
            chmin(dp[i+1][0], dp[i][0]+y);
            chmin(dp[i+1][1], dp[i][0]+z+x);
        }
    }
    cout <<min(dp[n][0],dp[n][1])<<'\n';
    // for(int i=0;i<=n;i++) cout <<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    return (0);
}