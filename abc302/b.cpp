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

    int h,w;
    cin >>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++) cin >>s[i];

    string t="snuke";

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]==t[0]){
                int index=1;
                for(int ii=0;ii<8;ii++){
                    int y=i+dy[ii], x=j+dx[ii];
                    while(inLine(y,x,h,w)&&s[y][x]==t[index]){
                        index++;
                        if(index==5){
                            for(int k=0;k<5;k++){
                                cout <<i+1<<' '<<j+1<<'\n';
                                i+=dy[ii];
                                j+=dx[ii];
                            }
                            return(0);
                        }
                        y += dy[ii];
                        x += dx[ii];
                    }
                    index = 1;
                }
            }
        }
    }
    cout <<"not find";
    return (0);
}