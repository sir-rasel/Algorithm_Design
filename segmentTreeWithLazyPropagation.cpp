#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAX = 100005;
struct data {
    LL sum, lazyVal;
    bool lazyFlag;
} tree[MAX*4];
int n;

void buildTree(int node, int beg, int endd) {
    if(beg == endd) {
        tree[node].sum = tree[beg].sum;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    buildTree(left, beg, mid);
    buildTree(right, mid+1, endd);

    tree[node].sum = tree[left].sum+tree[right].sum;
}

void pushDown(int node, int left, int right, int beg, int mid, int endd) {
    tree[left].sum += tree[node].lazyVal*(mid-beg+1);
    tree[right].sum += tree[node].lazyVal*(endd-mid);
    tree[left].lazyVal += tree[node].lazyVal;
    tree[right].lazyVal += tree[node].lazyVal;
    tree[left].lazyFlag = true;
    tree[right].lazyFlag = true;
    tree[node].lazyVal = 0;
    tree[node].lazyFlag = false;
}

void update(int node, int beg, int endd, int x, int y, LL val) {
    if(x > y) return;
    if(beg == x && endd == y) {
        tree[node].sum += val*(endd-beg+1);
        tree[node].lazyVal += val;
        tree[node].lazyFlag = true;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    if(tree[node].lazyFlag) pushDown(node, left, right, beg, mid, endd);

    update(left, beg, mid, x, min(y, mid), val);
    update(right, mid+1, endd, max(x, mid+1), y, val);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

LL query(int node, int beg, int endd, int x, int y) {
    if(x > y) return 0ll;
    if(beg == x && endd == y) return tree[node].sum;

    int left = node*2;
    int right = node*2+1;
    int mid = (beg+endd)/2;

    if(tree[node].lazyFlag) pushDown(node, left, right, beg, mid, endd);

    LL l = query(left, beg, mid, x, min(y, mid));
    LL r = query(right, mid+1, endd, max(x, mid+1), y);

    return l+r;
}

int main() {

    int test, kase=1, q, com, x, y;
    LL val;

    scanf("%d", &test);
    while(test--) {
        printf("Case %d:\n", kase++);
        scanf("%d %d", &n, &q);
        memset(tree, 0, sizeof(tree));
        while(q--) {
            scanf("%d", &com);
            if(com == 0) {
                scanf("%d %d %lld", &x, &y, &val);
                x++, y++;
                update(1, 1, n, x, y, val);
            }
            else {
                scanf("%d %d", &x, &y);
                x++, y++;
                printf("%lld\n", query(1, 1, n, x, y));
            }
        }
    }

    return 0;
}
