#include <iostream>
#include <vector>

using namespace std;

struct Segtree{

	vector<long long> tree;
	int size;

	void init(int n) {
		size = 1;
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, 0);
	}
	void build(vector<int>& a,int x, int lx, int rx) {
		if (rx - lx == 1) {
			if(lx<a.size())
			tree[x] = a[lx];
		}
		else {
			int m = (lx + rx) / 2;
			build(a, 2 * x + 1, lx, m);
			build(a, 2 * x + 2, m, rx);
			tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
		}
	}
	void build(vector<int> &a) {
		init(a.size());
		build(a, 0, 0, size);
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
		else
		{
			set(i, v, 2 * x + 2, m, rx);
		}
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	long long sum(int l, int r, int x, int lx, int rx) {
		if (l >= rx || lx>=r) {
			return 0;
		}
		if (lx >= l && r >= rx) {
			return tree[x];
		}
		int m = (lx + rx) / 2;
		long long s1 = sum(l, r, 2*x+1, lx, m);
		long long s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
	long long sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}

	void printTree() {
		cout << "\n";
		for (int i = 0; i < tree.size(); i++)
			cout << tree[i] << " ";
		cout << "\n";
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
			int l,r;
			cin >> l >> r;
			cout << st.sum(l, r) << "\n";

		}
	}

}
