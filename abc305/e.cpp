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

    int n,m,k;
    cin >>n>>m>>k;
    vector<vector<int>> lord(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        a--;b--;
        lord[a].push_back(b);
        lord[b].push_back(a);
    }
    max_heap<pii> pq;
    set<int> ans;
    for(int i=0;i<k;i++){
        int p,h;
        cin >>p>>h;
        p--;
        pq.push(mp(h,p));
        ans.insert(p);
    }
    
    while(!pq.empty()){// 初めからいる弱い警備員を消せない
        int p,h;
        tie(h,p) = pq.top();
        pq.pop();
        if(h==0) continue;
        for(auto ne:lord[p]){
            if(ans.find(ne)!=ans.end()) continue;
            ans.insert(ne);
            if(h>1) pq.push(mp(h-1, ne));
        }
    }

    cout <<ans.size()<<"\n";
    for(auto itr=ans.begin(); itr!=ans.end(); itr++){
        if(itr!=ans.begin()) cout <<" ";
        cout <<(*itr)+1;
    }cout <<"\n";
    return (0);
}