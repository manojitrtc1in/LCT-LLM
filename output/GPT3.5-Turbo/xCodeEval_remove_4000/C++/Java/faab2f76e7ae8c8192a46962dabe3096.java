import java.util.*;
import java.io.*;

class Main {
    static class Node {
        int priority;
        int value;
        int id;
        int originalId;
        int upd = 0;
        Node l, r;
    }

    static Random rnd = new Random();
    static Node root;
    static int countNodes = 0;
    static Node[] memo;

    static void push(Node it) {
        if (it != null && it.upd != 0) {
            it.value += it.upd;
            if (it.l != null) it.l.upd += it.upd;
            if (it.r != null) it.r.upd += it.upd;
            it.upd = 0;
        }
    }

    static void merge(Node t, Node l, Node r) {
        push(l);
        push(r);
        if (l == null || r == null) {
            t = (l != null) ? l : r;
        } else if (l.priority > r.priority) {
            merge(l.r, l.r, r);
            t = l;
        } else {
            merge(r.l, l, r.l);
            t = r;
        }
    }

    static void split(Node t, int key, Node l, Node r) {
        if (t == null) {
            l = r = null;
            return;
        }
        push(t);
        if (key < t.value) {
            split(t.l, key, l, t.l);
            r = t;
        } else {
            split(t.r, key, t.r, r);
            l = t;
        }
    }

    static Node newNode(int value, int id) {
        Node p = memo[countNodes++];
        p.priority = rnd.nextInt(1000000000);
        p.value = value;
        p.originalId = id;
        p.id = -1;
        return p;
    }

    static void solve(BufferedReader in, PrintWriter out) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        root = null;

        memo = new Node[2000000];
        for (int i = 0; i < 2000000; i++) {
            memo[i] = new Node();
        }

        for (int i = 0; i < n; i++) {
            Node t = newNode(i, i);
            merge(root, root, t);
        }
        Set<Integer> leftIds = new HashSet<>();
        for (int i = 0; i < n; i++) {
            leftIds.add(i);
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int id = Integer.parseInt(st.nextToken()) - 1;
            int pos = Integer.parseInt(st.nextToken()) - 1;

            Node t1, t2, t3;
            split(root, pos - 1, t1, t2);
            split(t2, pos, t2, t3);

            if (t2.id != -1) {
                if (t2.id != id) {
                    out.println("-1");
                    return;
                }
            } else {
                if (!leftIds.contains(id)) {
                    out.println("-1");
                    return;
                }
                leftIds.remove(id);
                t2.id = id;
            }
            t2.value = 0;
            t2.upd = 0;
            if (t1 != null) {
                t1.upd++;
            }
            merge(root, t2, t1);
            merge(root, root, t3);
        }

        int[] p = new int[n];
        Arrays.fill(p, -1);

        for (int i = 0; i < n; i++) {
            Node t1;
            split(root, i, t1, root);
            if (t1.id != -1) {
                p[t1.originalId] = t1.id;
            }
        }

        for (int i = 0; i < n; i++) {
            if (p[i] == -1) {
                p[i] = leftIds.iterator().next();
                leftIds.remove(p[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            out.print((p[i] + 1) + " ");
        }
        out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}
