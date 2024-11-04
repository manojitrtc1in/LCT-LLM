import java.util.*;

class Main {
    static class Node {
        Node prev, next;
        int v, pos;

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

        boolean empty() {
            return next == this;
        }

        void unlink() {
            link(prev, next);
            reset();
        }

        void insertNext(Node newNext) {
            link(newNext, next);
            link(this, newNext);
        }

        void insertPrev(Node newPrev) {
            link(prev, newPrev);
            link(newPrev, this);
        }

        static void link(Node prev, Node next) {
            prev.next = next;
            next.prev = prev;
        }

        void reset() {
            prev = next = this;
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

    static class SplayTree {
        static class Helper {
            static Node toMember(Node p) {
                return p;
            }

            static Node toParent(Node m) {
                return m;
            }
        }

        static class BstIterator implements Iterator<Node> {
            Node cur;

            BstIterator(Node head) {
                cur = head;
            }

            @Override
            public boolean hasNext() {
                return cur != null;
            }

            @Override
            public Node next() {
                Node node = cur;
                cur = bstPrev(cur);
                return node;
            }
        }

        static Node id7(Node x) {
            while (x != null && x.prev != null)
                x = x.prev;
            return x;
        }

        static Node id8(Node x) {
            while (x != null && x.next != null)
                x = x.next;
            return x;
        }

        static Node bstPrev(Node x) {
            if (x.prev != null)
                return id8(x.prev);
            Node p = x.prev;
            while (p != null && x == p.prev) {
                x = p;
                p = p.prev;
            }
            return p;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static Node id3(Node x) {
            if (x.next != null)
                return id7(x.next);
            Node p = x.prev;
            while (p != null && x == p.next) {
                x = p;
                p = p.prev;
            }
            return p;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }

        static void bstRotate(Node x) {
            Node y = x.prev, z = y.prev;
            Node b = (x == y.prev) ? x.next : x.prev;
            x.prev = z;
            y.prev = x;
            if (b != null)
                b.prev = y;
            if (z != null)
                (z.prev == y ? z.prev : z.next) = x;
            if (x == y.prev)
                x.next = y;
            else
                x.prev = y;
        }
    }

    static final int maxn = 500005;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] arr = new Node[n];
        for (int i = 0; i < n; i++) {
            int v = scanner.nextInt();
            arr[i] = new Node(v, i);
        }

        ListHead lst = new ListHead();
        SplayTree splay = new SplayTree();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            splay.insert(arr[i]);
            lst.insertPrev(arr[i]);
        }

        int lastLeft = 0;
        int lastRight = 0;

        while (splay.size() > 0) {
            SplayTree.BstIterator it = splay.begin();
            ListIter lit = new ListIter(it.cur.lh);
            ListIter root = new ListIter(lst);
            int left = root.next().pos;
            int right = root.prev().pos;
            splay.erase(it);

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
