

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segtree {

	struct node {
		int min, cnt;
	};

	node combine(node a, node b) {
		if (a.min < b.min)
			return a;
		if (a.min > b.min)
			return b;
		return { a.min,a.cnt + b.cnt };
	}


	vector<node>tree;
	int size;

	void init(int n) {
		size = 1;
		while (size < n) {
			size *= 2;
		}
		tree.assign(size * 2 - 1, { 0,0 });
	}

	void build(vector<int> &a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void build(vector<int>& a,int x,int lx,int rx) {
		if (rx - lx == 1) {
			if(lx<a.size())
				tree[x] = { a[lx],1 };
		}
		else {
			int m = (lx + rx) / 2;
			build(a, 2 * x + 1, lx, m);
			build(a, 2 * x + 2, m, rx);
			tree[x]= combine(tree[2 * x + 1],tree[2 * x + 2]);
		}
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = { v,1 };
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		tree[x] = combine(tree[2 * x + 1],tree[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	node min(int l, int r, int x, int lx, int rx) {
		if (l >= rx || lx >= r) {
			return { INT_MAX,0 };
		}
		if (rx <= r && lx >= l) {
			return tree[x];
		}
		int m = (rx + lx) / 2;
		node s1 = min(l, r, 2 * x + 1, lx, m);
		node s2 = min(l, r, 2 * x + 2, m, rx);
		return combine(s1,s2);
	}

	node min(int l, int r) {
		return min(l, r, 0, 0, size);
	}

};

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	Segtree st;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	st.build(a);
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			Segtree::node node = st.min(l, r);
			cout << node.min <<" "<< node.cnt << "\n";

		}
	}


}

