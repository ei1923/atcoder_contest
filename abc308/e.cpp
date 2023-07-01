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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >>a[i];
    string s;
    cin >>s;
    vector<vector<lol>> M(3,vector<lol>(n,0)), X(3,vector<lol>(n,0));
    
    if(s[0]=='M') M[a[0]][0] = 1;
    for(int i=1;i<n;i++){
        if(s[i]=='M') M[a[i]][i] = 1;
        for(int j=0;j<3;j++){
            M[j][i] += M[j][i-1];
        }
    }

    if(s[n-1]=='X') X[a[n-1]][n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(s[i]=='X') X[a[i]][i] = 1;
        for(int j=0;j<3;j++){
            X[j][i] += X[j][i+1];
        }
    }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<n;j++){
    //         cout <<" "<<M[i][j];
    //     }
    //     cout <<"\n";
    // }
    // cout <<"\n";
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<n;j++){
    //         cout <<" "<<X[i][j];
    //     }
    //     cout <<"\n";
    // }
    
    lol ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]!='E') continue;
        if(a[i] == 0){
            // 00 20 02 22
            ans += (M[0][i]*X[0][i]) + (M[2][i]*X[0][i]) + (M[0][i]*X[2][i]) + (M[2][i]*X[2][i]);
            // 01 10 11
            ans += 2*((M[0][i]*X[1][i]) + (M[1][i]*X[0][i]) + (M[1][i]*X[1][i]));
            // 12 21
            ans += 3*((M[1][i]*X[2][i]) + (M[2][i]*X[1][i]));
        }
        if(a[i] == 1){
            // 01 10 00
            ans += 2*((M[0][i]*X[1][i]) + (M[1][i]*X[0][i]) + (M[0][i]*X[0][i]));
            // 02 20
            ans += 3*((M[0][i]*X[2][i]) + (M[2][i]*X[0][i]));
        }
        if(a[i] == 2){
            // 00 20 02
            ans += (M[0][i]*X[0][i]) + (M[2][i]*X[0][i]) + (M[0][i]*X[2][i]);
            // 10 01
            ans += 3*((M[1][i]*X[0][i]) + (M[0][i]*X[1][i]));
        }
        // cout <<i<<" "<<ans<<"\n";
    }
    cout <<ans<<"\n";
    return (0);
}