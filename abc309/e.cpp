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

int tansaku(int k, int tmp, vector<vector<int>>& ch, vector<int>& hoken,map<int,int>& rui, vector<int>& cost){
    int ans = 0;
    if(rui.find(cost[k]-1)!=rui.end()){
        tmp += rui[cost[k]-1];
        // cout <<rui[cost[k]-1]<<" "<<k<<" "<<tmp<<"\n";

    }
    
    if(hoken[k]!=0){
        // 保険を掛ける
        tmp++;
        rui[hoken[k]+cost[k]] --;
    }
    // cout <<" "<<k<<" "<<tmp<<"\n";
    

    for(int i=0;i<ch[k].size();i++){
        int now = ch[k][i];
        cost[now] = cost[k]+1;

        ans += tansaku(now, tmp, ch, hoken, rui, cost);
    }

    if(hoken[k]!=0){
        // 保険を外す
        tmp--;
        rui[hoken[k]+cost[k]] ++;
    }
    if(tmp==0&&hoken[k]==0) ans++;
    return(ans);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 再帰

    int n,m;
    cin >>n>>m;
    vector<vector<int>> ch(n);
    vector<int> ans(n,0);
    vector<int> hoken(n,0);
    for(int i=1;i<n;i++){
        int p;
        cin >>p;
        p--;
        ch[p].push_back(i);
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin >>x>>y;
        x--;
        chmax(hoken[x],y);
    }

    vector<int> cost(n);
    cost[0] = 0;
    map<int,int> p;
    int tmp=0;
    cout <<n-tansaku(0,tmp,ch,hoken,p,cost)<<"\n";
    
    // for(int i=0;i<n;i++){
    //     cout <<" "<<cost[i];
    // }cout <<"\n";
    return (0);
}