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

    int n,m,h,k;
    cin >>n>>m>>h>>k;
    string s;
    cin >>s;
    map<pii,int> item;
    for(int i=0;i<m;i++){
        int x,y;
        cin >>x>>y;
        item.emplace(mp(x,y),1);
    }
    int x,y;
    x = 0;
    y = 0;
    for(auto c:s){
        if(c=='R') x++;
        if(c=='L') x--;
        if(c=='U') y++;
        if(c=='D') y--;
        h--;
        if(item.find(mp(x,y)) != item.end()){
            // cout <<" "<<x<<" "<<y<<" "<<h<<"\n";
            if(0<=h && h<k){
                h = k;
                item.erase(mp(x,y));
            }
        }
    }
    if(h>=0) cout <<"Yes\n";
    else cout <<"No\n";
    return (0);
}