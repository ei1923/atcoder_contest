#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
using pii=pair<int,int>;
template<class T> using max_heap=priority_queue<T>;
template<class T> using min_heap=priority_queue<T,vector<T>,greater<T>>;
template<class T> using uset=unordered_set<T>;
template<class A,class B> using umap=unordered_map<A,B>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline A abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
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
    vector<uset<int>> lord(n+1);
    vector<int> ans;
    vector<int> visit(n, 0);
    vector<int> only;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >>u>>v;
        u--;
        v--;
        lord[u].insert(v);
        lord[v].insert(u);
    }
    // for(int i=1;i<=n;i++){
    //     for(auto p:lord[i]) cout <<" "<<p;
    //     cout <<"\n";
    // }
    int node = 0;
    for(int i=0;i<n;i++){
        if(lord[i].size()==1 && visit[i]==0){
            only.emplace_back(i);
        }
    }
    while(true){
        if(only.size() <= node) break;
        int root = *(lord[only[node]].begin());
        
        if(visit[root] == 1){
            node++;
            continue;
        }
        node++;
        // cout <<" "<<root<<"\n";
        int cnt = 0;
        for(auto ne:lord[root]){
            cnt++;
            for(auto ne2:lord[ne]){
                if(ne2!=root){
                    lord[ne2].erase(ne);
                    if(lord[ne2].size()==1 && visit[ne2]==0){
                        only.emplace_back(ne2);
                    }
                }
            }
            visit[ne] = 1;
        }
        visit[root] = 1;
        ans.emplace_back(cnt);
        // for(auto i:visit) cout <<" "<<i;
        // cout <<"\n";
        // for(int i=0;i<n;i++){
        //     for(auto p:lord[i]) cout <<" "<<p;
        //     cout <<"\n";
        // }
        // break;
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        if(i!=0) cout <<" ";
        cout <<ans[i];
    }cout <<"\n";
    return (0);
}