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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k,num=0;
    cin >>n>>k;
    vector<int> a(n);
    map<int,set<int>> pos;
    int ans = n;
    for(int i=0;i<n;i++){
        cin >>a[i];
        // pos[a[i]] = i;
        if(pos[a[i]].empty()) num++;
        pos[a[i]].insert(i);
    }

    // 尺取り
    int r = 0, l = 0;
    int del = 0;
    while(r<n){
        if(num-del > k){
            while(l<n){
                // 追加した場所の数字があるか
                if(r+1<=a[l] && a[l]<=l+1){
                    // a[l]の数字がすべて範囲に入っているか
                    if(pos[a[l]].lower_bound(r)==pos[a[l]].begin() && pos[a[l]].upper_bound(l) == pos[a[l]].end()){
                        del++;
                        // cout <<r<<" "<<l<<"\n";
                    }
                }

                // 削除の最大値が増える
                // if(r<=pos[l-r] && pos[l-r]<=l) del++;
                if(!pos[l+1].empty()){
                    if(pos[l+1].lower_bound(r)==pos[l+1].begin() && pos[l+1].upper_bound(l) == pos[l+1].end()){
                        if(l+1 != a[l]) del++;
                        // cout <<r<<" "<<l<<"\n";
                        // cout <<pos[l].size()<<"\n";
                    }
                }
                
                l++;
                // cout <<" "<<r<<" "<<l<<" "<<del<<"\n";
                // 種類数
                if(num-del <= k){
                    chmin(ans, l-r);
                    break;
                }
            }
        }
        // 左端の処理
        if(r+1<=a[r] && a[r]<=l){
            if(pos[a[r]].lower_bound(r)==pos[a[r]].begin() && pos[a[r]].upper_bound(l-1) == pos[a[r]].end()){
                del--;
                // cout <<r<<" "<<l<<" "<<a[r]<<"\n";
            }
        }
        if(!pos[r+1].empty()){
            if(pos[r+1].lower_bound(r)==pos[r+1].begin() && pos[r+1].upper_bound(l-1) == pos[r+1].end()){
                if(r+1 != a[r]) del--;
                // cout <<" "<<r<<" "<<l<<"\n";
            }
        }
        r++;
        // cout <<" "<<r<<" "<<l<<" "<<del<<"\n";
        if(num-del <= k){
            // cout <<" "<<r<<" "<<l<<" "<<del<<"\n";
            chmin(ans, l-r);
        }
    }

    if(num <= k) ans = 1;

    cout <<ans<<"\n";
    return (0);
}