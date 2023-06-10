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

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
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
    vector<int> a(A+1);
    for(int i=0;i<A;i++) cin >>a[i];
    a[A] = MOD;
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
    
    RMQ<int> sg(B+1);
    sg.update(0,B+2,0);

    // for(int i=0;i<N;i++){
    //     cout <<" "<<iti[i].fi<<" "<<iti[i].se<<"\n";
    // }
    int b_x = iti[0].se;
    int max_cnt=0;
    for(int i=0;i<N;i++){
        pii tmp=iti[i];
        if(b_x != tmp.se){// 行が変わったら，見ている位置を右に戻す
            y_index = 0;
            b_x = tmp.se;
        }
        if(a[x_index]<tmp.fi){// 横線で分断
            // chmin() cnt[]のそれぞれで最小値をとる
            // cout <<"kousinn "<<i<<"\n";
            chmin(ans_min, sg.query(0,B+1));
            sg.update(0,B+1,0);// 区間更新
            // 最大値をここにしてもいい
            x_index++;
            if(x_index<A && a[x_index]<tmp.fi){
                // 何もない
                chmin(ans_min, 0);
            }
        }
        while(y_index<B && b[y_index]<tmp.se){// 縦線で分断
            // cout <<b[y_index]<<" "<<i<<"\n";
            y_index++;
        }
        cnt[y_index]++;
        sg.update(y_index, y_index+1, sg[y_index]+1);
        chmax(max_cnt, sg[y_index]);
        chmax(ans_max, max_cnt);
        // 一転更新
        // cout <<y_index<<"\n";
        
        // for(int j=0;j<=B;j++){
        //     cout <<" "<<sg[j];
        // }cout <<"\n";
        // cout <<"cnt";
        // for(auto i:cnt){
        //     cout <<" "<<i;
        // }cout <<"\n";
    }
    cout <<ans_min<<" "<<ans_max<<"\n";
    return (0);
}