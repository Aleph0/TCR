
#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = 9223372036854775807LL; // (1LL << 62) - 1 + (1LL << 62)
const double pi = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

const bool LOG = false;
void Log() { if(LOG) cerr << "\n\n"; }
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1,T2> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

// Order Statistics Tree (if this is supported by the judge software)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TIn, class TOut> // key, value types. TOut can be null_type
using order_tree = tree<TIn, TOut, less<TIn>,
	rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(int r) (0-based)
// order_of_key(TIn v)
// use key pair<Tin,int> {value, counter} for multiset/multimap

int main() {
	ios_base::sync_with_stdio(false); // faster IO
	cin.tie(NULL);                    // faster IO
	cerr << boolalpha;                // (print true/false)
	(cout << fixed).precision(10);    // set floating point precision
	// TODO: code
	return 0;
}