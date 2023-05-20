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
    cin >>n>>m;
    vector<string> s(n);
    string ans="No";
    for(int i=0;i<n;i++) cin >>s[i];

    vector<int> nex(n);
    for(int i=0;i<n;i++) nex[i] = i;

    do{
        bool cnt=true;
        for(int i=1;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(s[nex[i-1]][j]!=s[nex[i]][j]) c++;
            }
            if(c>1) cnt=false;
        }
        if(cnt) ans="Yes";
    }while(next_permutation(nex.begin(), nex.end()));
    cout <<ans<<"\n";
    return (0);
}