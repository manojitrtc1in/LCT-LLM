import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

class Random {
    private final ThreadLocalRandom random;

    public Random() {
        random = ThreadLocalRandom.current();
    }

    public int getInt(int upTo) {
        return random.nextInt(0, upTo);
    }
}

class Node {
    int priority;
    int value;
    int id;
    int originalId;
    int upd = 0;
    Node l, r;
}

public class faab2f76e7ae8c8192a46962dabe3096_nc {
    private static Node root;
    private static final int MAX_NODES = 2000000;
    private static final Node[] memo = new Node[MAX_NODES];
    private static int countNodes = 0;
    private static final Random rnd = new Random();
    private static List<Integer> p;

    private static void push(Node it) {
        if (it != null && it.upd != 0) {
            it.value += it.upd;
            if (it.l != null) it.l.upd += it.upd;
            if (it.r != null) it.r.upd += it.upd;
            it.upd = 0;
        }
    }

    private static void merge(Node[] t, Node l, Node r) {
        push(l);
        push(r);
        if (l == null || r == null) {
            t[0] = (l != null) ? l : r;
        } else if (l.priority > r.priority) {
            merge(new Node[]{l.r}, l.r, r);
            t[0] = l;
        } else {
            merge(new Node[]{r.l}, l, r.l);
            t[0] = r;
        }
    }

    private static void split(Node t, int key, Node[] l, Node[] r) {
        if (t == null) {
            l[0] = r[0] = null;
            return;
        }
        push(t);
        if (key < t.value) {
            split(t.l, key, l, new Node[]{t});
            r[0] = t;
        } else {
            split(t.r, key, new Node[]{t}, r);
            l[0] = t;
        }
    }

    private static Node newNode(int value, int id) {
        Node p = memo[countNodes++];
        p.priority = rnd.getInt(1000000000);
        p.value = value;
        p.originalId = id;
        p.id = -1;
        return p;
    }

    private static void solve(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        root = null;

        for (int i = 0; i < n; i++) {
            Node t = newNode(i, i);
            merge(new Node[]{root}, root, t);
        }

        Set<Integer> leftIds = new HashSet<>();
        for (int i = 0; i < n; i++) {
            leftIds.add(i);
        }

        for (int i = 0; i < m; i++) {
            int id = in.nextInt() - 1;
            int pos = in.nextInt() - 1;

            Node[] t1 = new Node[1];
            Node[] t2 = new Node[1];
            Node[] t3 = new Node[1];
            split(root, pos - 1, t1, t2);
            split(t2[0], pos, t2, t3);

            if (t2[0].id != -1) {
                if (t2[0].id != id) {
                    out.println("-1");
                    return;
                }
            } else {
                if (!leftIds.contains(id)) {
                    out.println("-1");
                    return;
                }
                leftIds.remove(id);
                t2[0].id = id;
            }
            t2[0].value = 0;
            t2[0].upd = 0;
            if (t1[0] != null) {
                t1[0].upd++;
            }
            merge(new Node[]{root}, t2[0], t1[0]);
            merge(new Node[]{root}, root, t3[0]);
        }

        p = new ArrayList<>(Collections.nCopies(n, -1));

        for (int i = 0; i < n; i++) {
            Node[] t1 = new Node[1];
            split(root, i, t1, new Node[]{root});
            if (t1[0].id != -1) {
                p.set(t1[0].originalId, t1[0].id);
            }
        }

        for (int i = 0; i < n; i++) {
            if (p.get(i) == -1) {
                p.set(i, leftIds.iterator().next());
                leftIds.remove(leftIds.iterator().next());
            }
        }

        for (int i = 0; i < n; i++) {
            out.print((p.get(i) + 1) + " ");
        }
        out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.flush();
    }
}
