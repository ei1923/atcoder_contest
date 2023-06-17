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
    vector<pii> card(n);
    for(int i=0;i<n;i++){
        string s;
        cin >>s;
        if('0'<=s[1]&&s[1]<='9'){
            card[i].fi = s[1]-'0';
            if(s[1]=='2') card[i].fi = 15;
            if(s[1]=='0') card[i].fi = 10;
        }else{
            if(s[1]=='A') card[i].fi = 14;
            if(s[1]=='J') card[i].fi = 11;
            if(s[1]=='Q') card[i].fi = 12;
            if(s[1]=='K') card[i].fi = 13;
        }
        if(s[2]=='D') card[i].se = 1;
        if(s[2]=='C') card[i].se = 2;
        if(s[2]=='H') card[i].se = 3;
        if(s[2]=='S') card[i].se = 4;   
    }

    sort(card.begin(), card.end());

    for(int i=0;i<n;i++){
        if(i!=0) cout <<" ";
        int tmp;
        if(card[i].fi==10) cout <<"10";
        else{
            cout <<"0";
            if(0<=card[i].fi&&card[i].fi<=9){
                tmp = card[i].fi;
                cout <<tmp;
            }else{
                // if(s[1]=='A') tmp = 1;
                // if(s[1]=='J') tmp = 11;
                // if(s[1]=='Q') tmp = 12;
                // if(s[1]=='K') tmp = 13;
                if(card[i].fi==15) cout <<"2";
                if(card[i].fi==14) cout <<"A";
                if(card[i].fi==11) cout <<"J";
                if(card[i].fi==12) cout <<"Q";
                if(card[i].fi==13) cout <<"K";  
            }
        }
        // cout <<tmp;
        if(card[i].se==1) cout <<"D";
        if(card[i].se==2) cout <<"C";
        if(card[i].se==3) cout <<"H";
        if(card[i].se==4) cout <<"S";  
        // cout <<card[i].fi<<" "<<card[i].se<<" ";
    }
    cout <<"\n";
    return (0);
}