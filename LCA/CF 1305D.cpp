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

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,x,y,z,a,b;
    cin>>n;
    vvi adj(n+1);
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    m=n;
    while(m>1) {
        x=-1;
        f(i,1,n+1) {
            if(adj[i].size()==1) {
                if(x==-1) x=i;
                else {
                    y=i;
                    break;
                }
            }
        }
        cout<<"? "<<x<<" "<<y<<"\n";
        cout.flush();
        cin>>z;
        if(z==x || z==y) {
            cout<<"! "<<z<<"\n";
            cout.flush();
            break;
        }
        a=adj[x][0];
        b=adj[y][0];
        if(m==3) z=a;
        adj[a].erase(find(adj[a].begin(),adj[a].end(),x));
        adj[b].erase(find(adj[b].begin(),adj[b].end(),y));
        adj[x].pop_back();
        adj[y].pop_back();
        m-=2;
    }
    if(m==1) {
        cout<<"! "<<z<<"\n";
        cout.flush();
    }
    return 0;
}
