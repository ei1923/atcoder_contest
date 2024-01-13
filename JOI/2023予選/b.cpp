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

template <typename X>
struct Segment{
  using FX=function<X(X,X)>; //X●X -> X となる関数の型
  int n;
  FX fx;
  const X ex;
  vector<X> dat;
  Segment(int size,FX fx_,X ex_) : fx(fx_),ex(ex_){
    n=1;
    while(size>n){
      n*=2;
    }
    dat.resize(n*2,ex_);
    return;
  }
  
  void set(int i,X x){ dat[i+n-1]=x;}
  void build(){
    for(int k=n-2;k>=0;k--) dat[k]=fx(dat[2*k+1],dat[2*k+2]);
    return;
  }
  
  void update(int i,X x){
    i+=n-1;
    dat[i]=x;
    while(i>0){
      i=(i-1)/2;
      dat[i]=fx(dat[i*2+1],dat[i*2+2]);
    }      
    return;  
  }
  
  X get(int a,int b){ return (get_sub(a,b+1,0,0,n));}
  X get_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l) return ex;
    if(a<=l && r<=b) return dat[k];
    X vl=get_sub(a,b,k*2+1,l,(l+r)/2);
    X vr=get_sub(a,b,k*2+2,(l+r)/2,r);
    return fx(vl,vr);
  }
  
  X operator[](const int &k) const{
    return dat[k+n-1];
  }
  
    X find_rightest(int a, int b, X x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    X find_leftest(int a, int b, X x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    X find_rightest_sub(int a, int b, X x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    X find_leftest_sub(int a, int b, X x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m,q;
    cin >>n>>m>>q;

    auto fx=[](lol x1,lol x2) -> lol {return x1+x2;};
    Segment<lol> sumst(n,fx,0);
    map<int,vector<pii>> syu;

    for(int i=0;i<n;i++){
        int p,a;
        cin >>p>>a;
        syu[a].push_back(mp(i,p));
        sumst.set(i,p);
    }
    sumst.build();

    vector<lol> ans(q,0);
    vector<pii> pairr(q);
    vector<int> T(q),L(q),R(q);
    for(int i=0;i<q;i++){
        cin >>T[i]>>L[i]>>R[i];
        L[i]--;
        R[i]--;
        pairr[i] = mp(T[i],i);
    }

    sort(all(pairr));

    int day = -1;

    for(auto& p:pairr){
        if(p.first != day){
            if(day != -1){
                // 値引き解除
                for(auto& con:syu[day]){
                    sumst.update(con.first,con.second);
                }
            }
            // 値引き
            for(auto& con:syu[p.first]){
                sumst.update(con.first,con.second/2);
            }
        }
        day = p.first;
        // 求める
        ans[p.second] = sumst.get(L[p.second], R[p.second]);
        // cout <<" "<<p.second+1<<" "<<L[p.second]<<" "<<R[p.second]<<"\n";
    }

    for(int i=0;i<q;i++){
        cout <<ans[i]<<"\n";
    }

    return (0);
}