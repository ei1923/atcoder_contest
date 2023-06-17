#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
constexpr int MAX=510000;

ll fact[MAX], fact_inv[MAX];

// 繰り返し二乗法
ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

ll comb(ll n, ll r){
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=100000;
    int k;
	cin>>n>>k;
	fact[0]=1;
        // 階乗の計算
	REP(i, n) fact[i+1]=fact[i]*(i+1)%MOD;
	fact_inv[n]=power(fact[n], MOD-2);
        // 逆元の計算
	FORR(i, 0, n) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
    // nCrの計算
    cout<<comb(n, k)<<'\n';
    return 0;
}