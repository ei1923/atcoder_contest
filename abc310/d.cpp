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


template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
FixPoint final : private F
{
public:
  template <typename G>
  explicit constexpr FixPoint(G&& g) noexcept
    : F{std::forward<G>(g)}
  {}
 
  template <typename... Args>
  constexpr decltype(auto)
  operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
    noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif  // !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};  // class FixPoint
 
 
#if defined(__cpp_deduction_guides)
template <typename F>
FixPoint(F&&)
  -> FixPoint<std::decay_t<F>>;
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
 
 
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,t,m;
    cin >>n>>t>>m;

    vector<int> a(m),b(m);
    for(int i=0;i<m;i++){
        cin >>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    vector<int> team(n,-1),tmp(t);

    auto result = makeFixPoint([&](auto f, int k) -> int {
        if(k==n){
            // 全グループ
            for(int i=0;i<t;i++) tmp[i] = 0;
            for(int i=0;i<n;i++){
                tmp[team[i]]++;
            }
            for(int i=0;i<t;i++){
                if(tmp[i]==0) return(0);
            }
            
            return (1);
        }
        int sum = 0;
        int max_team = 0;
        for(int i=0;i<k;i++){
            chmax(max_team, team[i]+1);
        }

        for(int i=0;i<max_team;i++){
            team[k] = i;
            bool NG = false;
            for(int j=0;j<m;j++){
                if(b[j]==k && team[a[j]]==team[k]){
                    NG = true;
                    break;
                }
            }
            if(NG) continue;
            sum += f(k+1);
        }

        if(max_team<t){// 新しい箱へ
            team[k] = max_team;
            sum += f(k+1);
        }
        team[k] = -1;
        return sum;
    })(0);

    cout <<result<<"\n";
    return (0);
}