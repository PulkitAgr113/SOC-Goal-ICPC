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

const int MAXA = 300000;
const int MAXN = 300000;
const int MAXQ = 300000;

int a[MAXN];
typedef tuple<int, int, int, int> Query;
Query query[MAXQ];

inline void moAlgorithm(const int n, const int a[], const int q, tuple<int, int, int, int> query[])
{
	const int blockSize = (int)sqrt((long double)n);

	const auto getLeft = [](const Query &q) {return get<0>(q); };
	const auto getRight = [](const Query &q) {return get<1>(q); };
	const auto getBlockIndex = [=](const Query &q) {return getLeft(q) / blockSize; };

	sort(query, query + q, [=](const Query &a, const Query &b) {
		return
			getBlockIndex(a) < getBlockIndex(b) ||
			getBlockIndex(a) == getBlockIndex(b) && getRight(a) > getRight(b);
	});

	static int count[MAXA + 1];
	memset(count, 0, sizeof(count));
	static int numberOfValuesWithCount[MAXN + 1];
	memset(numberOfValuesWithCount, 0, sizeof(*numberOfValuesWithCount) * (n + 1));
	int maxCount = 0;

	const auto remove = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount && numberOfValuesWithCount[count[a[index]]] == 0)
		{
			--maxCount;
		}
		--count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];

	};
	const auto add = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount)
		{
			++maxCount;
		}
		++count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];
	};

	int left = 0, right = -1;

	for (int i = 0; i < q; ++i)
	{
		for (; left < getLeft(query[i]); ++left)
		{
			remove(left);
		}
		for (; left > getLeft(query[i]); )
		{
			add(--left);
		}
		for (; right < getRight(query[i]); )
		{
			add(++right);
		}
		for (; right > getRight(query[i]); --right)
		{
			remove(right);
		}
		get<3>(query[i]) = maxCount;
	}

	sort(query, query + q, [=](const Query &a, const Query &b) {
		return get<2>(a) < get<2>(b);
	});
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,q,l,r,k,x;
    cin>>n>>q;
    int a[n],b[q];
    f(i,0,n) cin>>a[i];
    f(i,0,q) {
        cin>>l>>r;
        b[i]=r-l+1;
        get<0>(query[i])=l-1;
        get<1>(query[i])=r-1;
        get<2>(query[i])=i;
    }
    moAlgorithm(n,a,q,query);
    f(i,0,q) {
        k=b[i];
        x=get<3>(query[i]);
        if(x<=ceil((db)(k/2))) cout<<"1\n";
        else cout<<2*x-k<<"\n";
    }
    return 0;
}
