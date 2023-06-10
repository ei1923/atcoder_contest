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

    int W,H,N;
    cin >>W>>H;
    cin >>N;
    vector<int> p(N),q(N);
    for(int i=0;i<N;i++) cin >>p[i]>>q[i];
    int A,B;
    cin >>A;
    vector<int> a(A);
    for(int i=0;i<A;i++) cin >>a[i];
    cin >>B;
    vector<int> b(B);
    for(int i=0;i<B;i++) cin >>b[i];
    
    int x_index=0;
    int y_index=0;
    int ans_min=MOD;
    int ans_max=0;
    vector<int> cnt(B+1,0);// この変数を使いまわす
    vector<pii> iti(N);// イチゴが上から順
    for(int i=0;i<N;i++) iti[i] = mp(p[i],q[i]);
    sort(iti.begin(), iti.end());

    auto fx1=[&](int x1,int x2) -> int {return min(x1,x2);};
    auto fx2=[&](int x1,int x2) -> int {return max(x1,x2);};

    Segment<int> minst(B+1,fx1,(1LL<<31)-1);
    Segment<int> maxst(B+1,fx2,-(1LL<<31)+1);
    for(int i=0;i<B+1;i++){
        minst.set(i,0);
        maxst.set(i,0);
    }
    minst.build();
    maxst.build();

    for(int i=0;i<N;i++){
        cout <<" "<<iti[i].fi<<" "<<iti[i].se<<"\n";
    }
    int b_x = iti[0].se;
    for(int i=0;i<N;i++){
        pii tmp=iti[i];
        if(b_x != tmp.se){// 行が変わったら，見ている位置を右に戻す
            y_index = 0;
            b_x = tmp.se;
            cout <<"改行 "<<i<<"\n";
        }
        if(a[x_index]<=tmp.fi){// 横線で分断
            // chmin() cnt[]のそれぞれで最小値をとる
            chmin(ans_min, minst.get(0,B+1));
            // 最大値をここにしてもいい
            x_index++;
            if(x_index<A && a[x_index]<tmp.fi){
                // 何もない
                chmin(ans_min, 0);
            }
        }
        while(y_index<B && b[y_index]<tmp.se){// 縦線で分断
            cout <<b[y_index]<<" "<<i<<"\n";
            y_index++;
        }
        cnt[y_index]++;
        minst.update(y_index, minst[y_index]+1);
        maxst.update(y_index, maxst[y_index]+1);
    }
    cout <<ans_min<<" "<<ans_max<<"\n";
    return (0);
}