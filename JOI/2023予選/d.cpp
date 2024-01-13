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

    int N;
    cin >>N;
    string A[N];

    for(int i=0;i<N;i++) cin >>A[i];

    int dp1[N][N], dp2[N][N], ans[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp1[i][j] = 1;
            dp2[i][j] = ans[i][j] = 1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int nx,ny;
            // 屋根を作る(左下にある)
            nx=i+1,ny=j-1;
            if(inLine(nx,ny,N,N) && A[nx][ny]==A[i][j]){
                if(inLine(nx,ny+dp1[i][j]*2,N,N) && A[nx][ny+dp1[i][j]*2]==A[i][j]){
                    dp1[nx][ny] = dp1[i][j]+1;
                }else if(inLine(nx,ny+2,N,N) && A[nx][ny+2]==A[i][j]){
                    dp1[nx][ny] = 2;
                }
            }
        }
    }

    for(int i=N-1;i>=0;i--){
        for(int j=0;j<N;j++){
            ans[i][j] = min(dp1[i][j],dp2[i][j]) + 0;
            int nx,ny;
            // 下側を作る(左上にある)
            nx=i-1,ny=j-1;
            if(inLine(nx,ny,N,N) && A[nx][ny]==A[i][j]){
                if(inLine(nx,ny+dp2[i][j]*2,N,N) && A[nx][ny+dp2[i][j]*2]==A[i][j]){
                    dp2[nx][ny] = dp2[i][j]+1;
                }else if(inLine(nx,ny+2,N,N) && A[nx][ny+2]==A[i][j]){
                    dp2[nx][ny] = 2;
                }
            }
        }
    }

    int ANS = 1;
    for(int i=0;i<N;i++){
        
        for(int right = N; right > 0; right--){
            int left = right-1;
            while(left-1 >= 0 && ans[i][left-1] > right-left){
                chmax(ANS, right-left+1);
                left--;
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     int x,y,max_;
    //     int nx,ny;
    //     x = i, y = 0, max_ = 1;
    //     while(1){
    //         nx = x+1, ny = y+1;
    //         if(!inLine(nx,ny,N,N)) break;
    //         if(A[nx][ny]==A[i][j]){
    //             _dp2[nx][ny] = _dp2[x][y] + 1;
    //         }
    //     }
    //     x = 0, y = i, max_ = 0;
    // }

    cout <<ANS<<"\n";
    int out = 0;
    while(ANS>1){
        out += 2*ANS + (ANS-2) * 2;
        ANS--;
    }
    cout <<out+1<<"\n";
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout <<" "<<dp1[i][j];
    //     }cout <<"\n";
    // }
    // cout <<"\n";
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout <<" "<<dp2[i][j];
    //     }cout <<"\n";
    // }
    // cout <<"\n";
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout <<" "<<ans[i][j];
    //     }cout <<"\n";
    // }
    return (0);
}