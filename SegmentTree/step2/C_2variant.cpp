#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segtree {
	vector<int>tree;
	int size;

	void init(int n) {
		size = 1;
		while (size < n) {
			size *= 2;
		}
		tree.assign(size * 2 - 1, INT_MIN);
	}

	void build(vector<int>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void build(vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x] = a[lx];
		}
		else {
			int m = (lx + rx) / 2;
			build(a, 2 * x + 1, lx, m);
			build(a, 2 * x + 2, m, rx);
			tree[x] = ::max(tree[2 * x + 1], tree[2 * x + 2]);
		}
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		tree[x] = ::max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	int findMin(int v) {
		return findMin(v, 0, 0, size);
	}

	int findMin(int v, int x, int lx, int rx) {
		if (tree[x] < v) {
			return -1;
		}
		if (rx - lx == 1) {
			return lx;
		}
		int m = (rx + lx) / 2;
		int res = findMin(v, 2 * x + 1, lx, m);
		if (res == -1) {
			res = findMin(v, 2 * x + 2, m, rx);
		}
		return res;
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
			int v;
			cin >> v;
			cout << st.findMin(v) << "\n";

		}
	}
}
