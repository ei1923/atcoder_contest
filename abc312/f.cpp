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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    lol ans = 0;
    cin >>n>>m;
    vector<lol> n_can,y_can,c_can;

    for(int i=0;i<n;i++){
        lol t,x; 
        cin >>t>>x;
        if(t==0) n_can.emplace_back(x);
        else if(t==1) y_can.emplace_back(x);
        else c_can.emplace_back(x);
    }
    sort(all(n_can),greater<lol>());
    sort(all(y_can),greater<lol>());
    sort(all(c_can),greater<lol>());
    
    lol sum = 0;
    int ni, yi;
    ni = yi = 0;
    int cnt = 0;
    lol key = 0;
    // 缶切りを使わない
    for(int i=0;i<min(m,(int)n_can.size());i++){
        sum += n_can[i];
        ni++;
        cnt++;
    }
    chmax(ans,sum);

    // i+1個の缶切りを使う
    for(int i=0;i<min(m,(int)c_can.size());i++){
        cnt ++;
        key += c_can[i];
        if(cnt>m){
            if(ni>0){
                sum -= n_can[ni-1];
                ni--;
                cnt--;
            }else{
                break;
            }
        }
        // 

        while(cnt<m&&yi<(int)y_can.size()){
            if(key<=0) break;
            key--;
            cnt++;
            sum += y_can[yi];
            yi++;
            chmax(ans,sum);
        }
        
        // トレード
        while(yi<(int)y_can.size() && ni>0 && key>0){
            if(n_can[ni-1]<=y_can[yi]){
                sum -= n_can[ni-1];
                sum += y_can[yi];
                ni--;
                yi++;
                key--;
                chmax(ans,sum);
            }else{
                break;
            }
        }

    }
    cout <<ans<<"\n";

    return (0);
}