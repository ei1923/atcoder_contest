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
// 再帰 auto result = makeFixPoint([&](auto f, int n) -> int {return(f(n-1)+f(n-2));}
template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
FixPoint final : private F {
public:
  template <typename G> explicit constexpr FixPoint(G&& g) noexcept : F{std::forward<G>(g)}{}
 
  template <typename... Args> constexpr decltype(auto) operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
    noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif  // !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};  // class FixPoint
#if defined(__cpp_deduction_guides)
template <typename F> FixPoint(F&&) -> FixPoint<std::decay_t<F>>;
#endif  // defined(__cpp_deduction_guides)
namespace
{
template <typename F>
#if !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)
#  if defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#  elif defined(_MSC_VER) && _MSC_VER >= 1700 && defined(_Check_return_)
_Check_return_
#  endif  // defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#endif  // !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)
inline constexpr decltype(auto)
makeFixPoint(F&& f) noexcept
{
  return FixPoint<std::decay_t<F>>{std::forward<std::decay_t<F>>(f)};
}
}  // namespace

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

    int n,q;
    cin >>n>>q;
    int M=n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++){
        cin >>x[i]>>y[i];
    }
    UnionFind uf(3000);
    min_heap<tuple<int,int,int>> hp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            hp.push(mt(abs(x[i]-x[j])+abs(y[i]-y[j]),i,j));
        }
    }

    while(q--){
        int k;
        cin >>k;
        if(k==1){
            M++;
            int a,b;
            cin >>a>>b;
            for(int i=0;i<n;i++){
                hp.push(mt(abs(x[i]-a)+abs(y[i]-b),i,n));
            }
            n++;
            x.push_back(a);
            y.push_back(b);
        }else if(k==2){
            if(M==1) cout <<"-1\n";
            else{
                int tmp=get<0>(hp.top());
                bool p=true;
                while(!hp.empty()&&tmp==get<0>(hp.top())){
                    auto [cost,a,b] = hp.top();
                    hp.pop();
                    if(p&&uf.same(a,b)){
                        tmp=get<0>(hp.top());
                    }else{
                        p=false;
                        if(!uf.same(a,b)) M--;
                        uf.unite(a,b);
                    }
                }
                cout <<tmp<<"\n";
            }
        }else{
            int u,v;
            cin >>u>>v;
            if(uf.same(u-1,v-1)) cout <<"Yes\n";
            else cout <<"No\n";
        }
    }
    return (0);
}
