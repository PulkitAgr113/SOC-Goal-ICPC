#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for (int i=x;i<n;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll ;
typedef vector<int> vi ;
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

void next_greatest(vll &a, vll &right, int n) {
    stack<pii> s;
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && s.top().F<a[i]) s.pop();
        if(s.empty()) right[i]=n-1-i;
        else right[i]=s.top().S-i-1;
        s.push(mp(a[i],i));
    }
}

void prev_greatest(vll &a, vll &left, int n) {
    stack<pii> s;
    f(i,0,n) {
        while(!s.empty() && s.top().F<=a[i]) s.pop();
        if(s.empty()) left[i]=i;
        else left[i]=i-s.top().S-1;
        s.push(mp(a[i],i));
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n;
    cin>>n;
    vll a(n),left(n),right(n);
    ll max_sum=0,min_sum=0;
    f(i,0,n) cin>>a[i];
    next_greatest(a,right,n);
    prev_greatest(a,left,n);
    f(i,0,n) {
        max_sum+=(right[i]+1)*(left[i]+1)*a[i];
        a[i]=-a[i];
    }
    next_greatest(a,right,n);
    prev_greatest(a,left,n);
    f(i,0,n) min_sum+=(right[i]+1)*(left[i]+1)*a[i];
    cout<<max_sum+min_sum;
    return 0;
}
