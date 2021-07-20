#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for (int i=x;i<n;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll ;
typedef vector<int> vi ;
typedef priority_queue<int> pqi ;
typedef priority_queue<pair<int,int>> pqp ;
typedef queue<int> qi ;
typedef vector<vector<int>> vvi ;
typedef vector<vector<ll>> vvll ;
typedef vector<vector<pair<int,int>>> vvp ;
typedef vector<bool> vb ;
typedef vector<double> vd ;
typedef vector<vector<char>> vvc ;
typedef vector<char> vc ;
typedef pair<int,int> pii ;
typedef vector<pair<int,int>> vpi ;
typedef vector<pair<ll,ll>> vpll ;
typedef pair<ll,ll> pll ;
typedef vector<ll> vll ;
typedef stack<int> si ;
typedef map<int,int> mii ;
typedef set<int> seti ;
typedef double db ;

int mod1 = 998244353 ;
int mod2 = 1000000007 ;

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n;
    cin>>n;
    vll spf(1000001,1),tau(1000001,1),a(1000001,1),sum(1000001,1);
    f(i,2,1000001) spf[i]=i;
    f(i,2,1000001) {
        if(spf[i]==i) {
            for(int j=2*i;j<1000001;j+=i) spf[j]=i;
        }
    }
    f(i,2,1000001) {
        int x=i,y=spf[i],cnt=0;
        while(x>1) {
            x/=y;
            cnt++;
            if(x%y!=0) {
                tau[i]*=(cnt+1);
                cnt=0;
            }
            y=spf[x];
        }
    }
    f(i,2,1000001) {
        a[i]=(sum[i-1]+tau[i])%mod1;
        sum[i]=(sum[i-1]+a[i])%mod1;
    }
    cout<<a[n];
    return 0;
}
