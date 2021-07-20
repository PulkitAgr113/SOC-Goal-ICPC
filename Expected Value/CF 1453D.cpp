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
    ll t,k;
    cin>>t;
    while(t--) {
        cin>>k;
        if(k&1) {
            cout<<"-1\n";
            continue;
        }
        k>>=1;
        ll flag=0,sum=0;
        vi v;
        while(k>0) {
            if(k&1) {
                if(flag==0) v.pb(1);
                else {
                    v.pb(1);
                    v.pb(flag);
                    sum+=flag;
                }
                sum+=1;
            }
            k>>=1;
            flag++;
        }
        cout<<sum<<"\n";
        for(auto u:v) {
            cout<<"1 ";
            f(i,1,u) cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}
