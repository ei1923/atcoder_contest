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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >>s;

    vector<vector<lol>> dp(3100, vector<lol>(3100,0));
    
    if(s[0]=='(') dp[0][1] = 1;
    if(s[0]=='?') dp[0][1] = 1;

    auto f = [&](int t, int n) -> void {
        if(n==1){
            for(int i=3010;i>0;i--){
                dp[t][i-1] += dp[t-1][i];
                dp[t][i-1] %= mod;
            }
        }
        if(n==2){
            for(int i=0;i<3010;i++){
                dp[t][i+1] += dp[t-1][i];
                dp[t][i+1] %= mod;
            }
        }
    };

    for(int i=1;i<(int)s.size();i++){
        if(s[i]=='('){
            f(i,2);
        }else if(s[i]==')'){
            f(i,1);
        }else{
            f(i,1);
            f(i,2);
        }
    }
    cout <<dp[(int)s.size()-1][0]<<"\n";
    return (0);
}