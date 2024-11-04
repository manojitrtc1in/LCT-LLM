import java.util.*;

class Main {
    static class Node {
        Node prev, next;
        int v;
        int pos;

        Node(int v, int pos) {
            this.v = v;
            this.pos = pos;
        }
    }

    static class ListHead {
        Node prev, next;

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
            prev.next = next;
            next.prev = prev;
            reset();
        }

        void insertNext(Node newNode) {
            newNode.next = next;
            newNode.prev = this;
            next.prev = newNode;
            next = newNode;
        }

        void insertPrev(Node newPrev) {
            newPrev.prev = prev;
            newPrev.next = this;
            prev.next = newPrev;
            prev = newPrev;
        }

        static void link(ListHead prev, ListHead next) {
            prev.next = next;
            next.prev = prev;
        }
    }

    static class ListIter implements Iterator<Node> {
        Node cur;

        ListIter(Node head) {
            cur = head;
        }

        @Override
        public boolean hasNext() {
            return cur != null;
        }

        @Override
        public Node next() {
            Node node = cur;
            cur = cur.next;
            return node;
        }
    }

    static class SplayHead {
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

    static void rotate(SplayHead x) {
        SplayHead y = x.p, z = y.p;
        bstRotate(x);
        y.updateSize();
    }

    static void splay(SplayHead root, SplayHead x, SplayHead target) {
        while (x.p != target) {
            if (x.p.p != target) {
                if ((x.p.lc == x) == (x.p.p.lc == x.p))
                    rotate(x.p);
                else
                    rotate(x);
            }
            rotate(x);
        }
        x.updateSize();
        if (target == null)
            root = x;
    }

    static void insertBefore(SplayHead root, SplayHead x, SplayHead y) {
        if (y == null) {
            x.lc = root;
            if (root != null) root.p = x;
            root = x;
            x.updateSize();
        } else {
            splay(root, y, null);
            if (y.lc == null)
                y.lc = x;
            else {
                SplayHead prev = bstRightmost(y.lc);
                splay(root, prev, y);
                prev.rc = x;
                x.p = prev;
                prev.updateSize();
                y.updateSize();
            }
        }
    }

    static void erase(SplayHead root, SplayHead x) {
        splay(root, x, null);
        if (x.lc == null) {
            if (x.rc != null) x.rc.p = null;
            root = x.rc;
        } else {
            SplayHead prev = bstRightmost(x.lc);
            splay(root, prev, x);
            prev.rc = x.rc;
            if (x.rc != null) x.rc.p = prev;
            prev.updateSize();
            prev.p = null;
            root = prev;
        }
        x.reset();
    }

    static int getRank(SplayHead root, SplayHead x) {
        if (x == null) return root != null ? root.size : 0;
        splay(root, x, null);
        return x.lc != null ? x.lc.size : 0;
    }

    static SplayHead findNthInner(SplayHead root, int k) {
        SplayHead p = root;
        while (true) {
            int lsize = p.lc != null ? p.lc.size : 0;
            if (k < lsize)
                p = p.lc;
            else if (k == lsize)
                return p;
            else
                k -= lsize + 1;
        }
    }

    static SplayHead findNth(SplayHead root, int k) {
        SplayHead p = findNthInner(root, k);
        splay(root, p, null);
        return p;
    }

    static class SizedSplay {
        static class Helper {
            static SplayHead toMember(Node p) {
                return p.sh;
            }

            static Node toParent(SplayHead m) {
                return m != null ? m.parent : null;
            }
        }

        static class KeyAccessor {
            int operator(Node p) {
                return p.v;
            }
        }

        static class Comp {
            boolean operator(int a, int b) {
                return a < b;
            }
        }

        static class Node {
            ListHead lh;
            SplayHead sh;
            int v;
            int pos;

            Node(int v, int pos) {
                this.v = v;
                this.pos = pos;
            }
        }

        SizedSplay() {
        }

        SizedSplay(SizedSplay that) {
            throw new UnsupportedOperationException();
        }

        int size(SplayHead root) {
            return root != null ? root.size : 0;
        }

        ListIter begin(SplayHead root) {
            return new ListIter(bstLeftmost(root));
        }

        ListIter end() {
            return new ListIter(null);
        }

        ListIter findNth(SplayHead root, int k) {
            return new ListIter(findNth(root, k));
        }

        int getRank(SplayHead root, SplayHead it) {
            return getRank(root, it);
        }

        ListIter erase(SplayHead root, SplayHead it) {
            ListIter next = new ListIter(it.lh.next);
            erase(root, it);
            return next;
        }

        ListIter find(SplayHead root, int k) {
            SplayHead x = bstLowerBound(root, k, new KeyAccessor(), new Comp());
            if (x != null) splay(root, x, null);
            if (x != null && x.v == k)
                return new ListIter(x.lh);
            return new ListIter(null);
        }

        ListIter lowerBound(SplayHead root, int k) {
            SplayHead x = bstLowerBound(root, k, new KeyAccessor(), new Comp());
            if (x != null) splay(root, x, null);
            return new ListIter(x.lh);
        }

        ListIter upperBound(SplayHead root, int k) {
            SplayHead x = bstUpperBound(root, k, new KeyAccessor(), new Comp());
            if (x != null) splay(root, x, null);
            return new ListIter(x.lh);
        }

        ListIter insert(SplayHead root, Node node) {
            SplayHead x = Helper.toMember(node);
            SplayHead y = bstLowerBound(root, node.v, new KeyAccessor(), new Comp());
            insertBefore(root, x, y);
            return new ListIter(x.lh);
        }
    }

    static ListHead lst = new ListHead();
    static SizedSplay splay = new SizedSplay();
    static Node[] arr;
    static long ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new Node[n];
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            arr[i] = new Node(v, i);
        }
        for (int i = 0; i < n; i++) {
            splay.insert(arr[i]);
            lst.insertPrev(arr[i].lh);
        }
        int lastLeft = 0;
        int lastRight = 0;
        while (splay.size() > 0) {
            SizedSplay.ListIter it = splay.begin();
            ListIter lit = new ListIter(it.cur.lh);
            ListIter root = new ListIter(lst);
            int left = root.next().pos;
            int right = root.prev().pos;
            splay.erase(it.cur);
            if (it.cur.pos == left && it.cur.pos == right) {
                ans += Math.min(lastLeft, lastRight);
            } else if (it.cur.pos == left) {
                ans += lastLeft;
                lastLeft = it.cur.v;
            } else if (it.cur.pos == right) {
                ans += lastRight;
                lastRight = it.cur.v;
            } else {
                ans += Math.min(lit.next().v, lit.prev().v);
            }
            it.cur.lh.unlink();
        }
        System.out.println(ans);
    }
}
