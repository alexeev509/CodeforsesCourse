#include <iostream>
#include <vector>



using namespace std;


struct segtree {
	vector <long long> tree;
	int size;

	void init(int n) {
		size = 1;
		while (size < n)
			size *= 2;
		tree.assign(size * 2 - 1, 0);
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
			int m = (rx + lx) / 2;
			build(a, 2 * x + 1, lx, m);
			build(a, 2 * x + 2, m, rx);
			tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
		}
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int m = (rx + lx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}



	long long find(int v) {
		return find(v, 0, 0, size);
	}

	long long find(int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}
		int m = (rx + lx) / 2;

			if (v < tree[2 * x + 2]) {
				return find(v, 2 * x + 2, m, rx);
			}
			else {
				return find(v - tree[2 * x + 2], 2 * x + 1, lx, m);
			}
		
	}


};

void main() {
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	int n, m;
	cin >> n;
	segtree st;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> q(n, 1);
	st.build(q);
	for (int i = q.size()-1; i >=0; i--) {
		long long lx = st.find(a[i]);
		q[i] = lx + 1;
		st.set(lx,0);
	}

	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << " ";
	}
}
