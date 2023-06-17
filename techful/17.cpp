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

lol euler_phi(lol n){
  lol ret=n;
  for(lol i=2;i*i<=n;i++){
    if(n%i==0){
      ret -= ret/i;
      while(n%i == 0) n/=i;
    }
  }
  if(n>1) ret-=ret/n;
  return ret;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >>n;
    // set<int> ret;
    // lol ans = n;
    // for(int i=2;i*i<=n;i++){
    //     if(n%i!=0) continue;
    //     bool is_in = false;
    //     for(auto r:ret){
    //         if(i%r==0) is_in = true;
    //     }
    //     if(!is_in){
    //         for(auto r:ret){
    //             ans += n/(r*i);
    //             ret.insert(r*i);
    //         }
    //         ans -= n/i;
    //         ans++;
    //         ret.insert(i);
    //     }
    // }
    // cout <<fixed(2)<<(double)ans/(double)n*100<<"\n";
    // cout <<ans<<"\n";

    cout <<fixed(2)<<(double)euler_phi(n)/(double)n*100<<"\n";
    return (0);
}