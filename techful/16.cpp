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
struct UnionFind {
  vector < int > par;
  vector < int > siz;
  
  UnionFind(int n): par(n), siz(n, 1) {
    for(int i = 0; i < n; i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  int size(int x){ return siz[root(x)];}
  bool same(int x, int y){ return root(x) == root(y); }//Ƚ��
  bool unite(int x, int y){//Ϣ��
    if((x=root(x))==(y=root(y))) return false;
    if( siz[y] > siz[x] ) swap(x,y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >>n;
    UnionFind uf(n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >>x>>y;
        y += 1000000;
        if(m.find(x)!=m.end()){
            uf.unite(i,m[x]);
            // cout <<" "<<i<<" "<<m[x]<<"\n";
        }else{
            m[x] = i;
        }
        if(m.find(y)!=m.end()){
            uf.unite(i,m[y]);
            // cout <<" "<<i<<" "<<m[y]<<"\n";
        }else{
            m[y] = i;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(uf.root(i)==i){
            ans++;
        }
    }
    cout <<ans<<"\n";
    return (0);
}