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

    int H,W;
    cin >>H>>W;
    string t="snuke";
    queue<tuple<int,int,int>> q;
    vector<string> s(H);
    set<pii> visit;
    for(int i=0;i<H;i++) cin >>s[i];
    
    q.push(mt(0,0,0));
    visit.insert(mp(0,0));

    while(!q.empty()){
        int dis,h,w;
        tie(dis,h,w) = q.front();
        q.pop();
        if(h==H-1 && w==W-1){
            cout <<"Yes\n";
            return(0);
        }
        for(int i=0;i<4;i++){
            int nx,ny;
            ny = h+dy[i];
            nx = w+dx[i];
            // if(inLine(ny,nx,h,w)) cout <<s[ny][nx]<<" ";
            // cout << t[(dis+1)%5]<<" "<<dis+1<<" "<<ny<<" "<<nx<<"\n";
            if(visit.find(mp(ny,nx))==visit.end() && inLine(ny,nx,H,W) && s[ny][nx] == t[(dis+1)%5]){
                q.push(mt(dis+1, ny, nx));
                visit.insert(mp(ny,nx));
                
            }
        }

    }
    cout <<"No\n";
    return (0);
}