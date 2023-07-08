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

    int n1,n2,m;
    cin >>n1>>n2>>m;
    vector<vector<int>> lord(n1+n2);
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        a--;
        b--;
        lord[a].push_back(b);
        lord[b].push_back(a);
    }

    int cost_1,cost_2;
    cost_1 = cost_2 = 0;
    queue<int> q;
    vector<int> visit(n1+n2, -1);
    
    q.push(0);
    visit[0] = 0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i=0;i<lord[k].size();i++){
            if(visit[lord[k][i]]==-1){
                visit[lord[k][i]] = visit[k]+1;
                chmax(cost_1,visit[k]+1);
                q.push(lord[k][i]);
            }
        }
    }
    // for(int i=0;i<n1+n2;i++) cout <<" "<<visit[i];
    // cout <<"\n";
    q.push(n1+n2-1);
    visit[n1+n2-1] = 0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i=0;i<lord[k].size();i++){
            if(visit[lord[k][i]]==-1){
                visit[lord[k][i]] = visit[k]+1;
                chmax(cost_2,visit[k]+1);
                q.push(lord[k][i]);
            }
        }
    }
    // for(int i=0;i<n1+n2;i++) cout <<" "<<visit[i];
    // cout <<"\n";
    cout <<cost_1+cost_2+1<<"\n";
    return (0);
}