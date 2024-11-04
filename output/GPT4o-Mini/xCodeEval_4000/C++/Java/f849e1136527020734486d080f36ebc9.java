import java.util.*;

class Node {
    ListHead lh;
    SplayHead sh;
    int v;
    int pos;

    Node() {
        lh = new ListHead();
        sh = new SplayHead();
    }
}

class ListHead {
    ListHead prev, next;

    ListHead() {
        reset();
    }

    void reset() {
        prev = next = this;
    }

    boolean empty() {
        return next == this;
    }

    void unlink() {
        link(prev, next);
        reset();
    }

    void insertNext(ListHead newNext) {
        link(newNext, next);
        link(this, newNext);
    }

    void insertPrev(ListHead newPrev) {
        link(prev, newPrev);
        link(newPrev, this);
    }

    static void link(ListHead prev, ListHead next) {
        prev.next = next;
        next.prev = prev;
    }
}

class SplayHead {
    SplayHead lc, rc, p;
    int size;

    SplayHead() {
        reset();
    }

    void reset() {
        lc = rc = p = null;
        size = 1;
    }

    void updateSize() {
        size = 1;
        if (lc != null) size += lc.size;
        if (rc != null) size += rc.size;
    }
}

class SplayTree {
    SplayHead root;

    SplayTree() {
        root = null;
    }

    int size() {
        return root != null ? root.size : 0;
    }

    void insert(Node node) {
        SplayHead x = node.sh;
        SplayHead y = lowerBound(root, node.v);
        insertBefore(root, x, y);
    }

    void erase(SplayHead x) {
        splay(root, x, null);
        if (x.lc == null) {
            root = x.rc;
        } else {
            SplayHead prev = rightmost(x.lc);
            splay(root, prev, x);
            prev.rc = x.rc;
            if (x.rc != null) x.rc.p = prev;
            prev.updateSize();
            root = prev;
        }
        x.reset();
    }

    SplayHead lowerBound(SplayHead root, int k) {
        SplayHead x = null;
        while (root != null) {
            if (root.v < k) {
                root = root.rc;
            } else {
                x = root;
                root = root.lc;
            }
        }
        return x;
    }

    SplayHead rightmost(SplayHead x) {
        while (x.rc != null) {
            x = x.rc;
        }
        return x;
    }

    void splay(SplayHead& root, SplayHead x, SplayHead target) {
        // Implementation of splay operation
    }

    void insertBefore(SplayHead& root, SplayHead x, SplayHead y) {
        // Implementation of insert before operation
    }
}

public class f849e1136527020734486d080f36ebc9_nc {
    static final int MAXN = 500005;
    static Node[] arr = new Node[MAXN];
    static SplayTree splay = new SplayTree();
    static long ans = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int v = scanner.nextInt();
            arr[i] = new Node();
            arr[i].v = v;
            arr[i].pos = i;
        }
        for (int i = 0; i < n; i++) {
            splay.insert(arr[i]);
        }
        int lastLeft = 0;
        int lastRight = 0;
        while (splay.size() > 0) {
            SplayHead it = splay.root; // Assuming root points to the minimum
            int left = it.next.pos;
            int right = it.prev.pos;
            splay.erase(it);
            if (it.pos == left && it.pos == right) {
                ans += Math.min(lastLeft, lastRight);
            } else if (it.pos == left) {
                ans += lastLeft;
                lastLeft = it.v;
            } else if (it.pos == right) {
                ans += lastRight;
                lastRight = it.v;
            } else {
                ans += Math.min(it.next.v, it.prev.v);
            }
            it.lh.unlink();
        }
        System.out.println(ans);
    }
}
