#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n, arr[MAX], tree[MAX*4];

void buildTree(int node, int beg, int endd) {
    if(beg == endd) {
        tree[node] = arr[beg];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    buildTree(left, beg, mid);
    buildTree(right, mid+1, endd);

    tree[node] = min(tree[left], tree[right]);
}

void update(int node, int beg, int endd, int pos, int y) {
    if(beg == endd) {
        tree[node] =+ y;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    if(pos<=mid) update(left, beg, mid,pos,y);
    else update(right, mid+1, endd,pos,y);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int beg, int endd, int x, int y) {
    if(x > y) return INT_MAX;
    if(beg == x && endd == y) return tree[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    int l = query(left, beg, mid, x, min(y, mid));
    int r = query(right, mid+1, endd, max(x, mid+1), y);

    return min(l, r);
}

int main() {
    int test, kase=1, q, x, y;

    scanf("%d", &test);
    while(test--) {
        printf("Case %d:\n", kase++);
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        init(1, 1, n);
        while(q--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(1, 1, n, x, y));
        }
    }

    return 0;
}
