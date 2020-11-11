#include <iostream>
#include <vector>

using namespace std;

struct Segtree {
	vector <long long> tree;
	int size;

	void init(int n ) {
		size = 1;
		while (size < n)
			size *= 2;
		tree.assign(size * 2 - 1, 0);
	}

	void build(vector <int> &a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void build(vector <int>& a,int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
			tree[x] = a[lx];
		}
		else {
			int m = (rx + lx) / 2;
			build(a, x * 2 + 1, lx, m);
			build(a, x * 2 + 2, m,rx);
			tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
		}
	}

	void set(int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (tree[x] == 1) {
				tree[x] = 0;
			}
			else {
				tree[x] = 1;
			}
			
			return;
		}
		int m = (rx + lx) / 2;
		if (i < m) {
			set(i, x * 2 + 1, lx, m);
		}
		else {
			set(i, x * 2 + 2, m, rx);
		}
		tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
	}

	long long sum(int lx, int rx, int x, int l, int r) {
		if (lx >= r || rx <= l) {
			return 0;
		}
		if (lx >= l && rx <= r) {
			return tree[x];
		}
		int m = (rx + lx) / 2;
		long long s1 = sum(lx, m, x * 2 + 1, l, r);
		long long s2 = sum(m, rx, x * 2 + 2, l, r);
		return s1 + s2;
	}

	long long sum(int l, int r) {
		return sum(0, size, 0, l, r);
	}


	void set(int i) {
		set(i, 0, 0, size);
	}

	int findIndex(int number, int x, int lx ,int rx) {
		if (rx - lx == 1 && number==0) {
			return lx;
		}
		if (2 * x + 1 < tree.size()) {
			int m = (rx + lx) / 2;
			if (number < tree[2 * x + 1]) {
				return findIndex(number, 2 * x + 1, lx, m);
			}
			else {
				return findIndex(number - tree[2 * x + 1], 2 * x + 2, m, rx);
			}
		}
	}

	int findIndex(int number) {
		return findIndex(number, 0, 0, size);
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
			int i;
			cin >> i;
			st.set(i);
		}
		else
		{
			int number;
			cin >> number;
			cout << st.findIndex(number) << "\n";
		}
	}

}
