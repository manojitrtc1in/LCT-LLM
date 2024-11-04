import java.util.*;

class IterRange<It> {
    private It first, second;

    public IterRange(It first, It second) {
        this.first = first;
        this.second = second;
    }

    public It begin() {
        return first;
    }

    public It end() {
        return second;
    }
}

class IntIter {
    private int i;

    public IntIter(int i) {
        this.i = i;
    }

    public int get() {
        return i;
    }

    public IntIter increment() {
        i++;
        return this;
    }

    public IntIter decrement() {
        i--;
        return this;
    }

    public IntIter add(int step) {
        return new IntIter(i + step);
    }

    public IntIter subtract(int step) {
        return new IntIter(i - step);
    }

    public int difference(IntIter that) {
        return i - that.i;
    }

    public boolean equals(IntIter that) {
        return i == that.i;
    }

    public boolean notEquals(IntIter that) {
        return !equals(that);
    }

    public int index(int n) {
        return i + n;
    }
}

class IntRange extends IterRange<IntIter> {
    public IntRange(IntIter first, IntIter second) {
        super(first, second);
    }
}

class Main {
    static long ans = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] arr = new Node[n];
        List<Node> lst = new LinkedList<>();
        SplayTree splay = new SplayTree();

        for (int i = 0; i < n; i++) {
            int v = scanner.nextInt();
            arr[i] = new Node(v, i);
        }

        for (Node node : arr) {
            splay.insert(node);
            lst.add(node);
        }

        int lastLeft = 0;
        int lastRight = 0;

        while (!splay.isEmpty()) {
            Node it = splay.begin();
            int left = lst.get(lst.indexOf(it) + 1).pos;
            int right = lst.get(lst.indexOf(it) - 1).pos;

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
                ans += Math.min(lst.get(lst.indexOf(it) + 1).v, lst.get(lst.indexOf(it) - 1).v);
            }
            lst.remove(it);
        }

        System.out.println(ans);
    }
}

class Node {
    int v;
    int pos;

    public Node(int v, int pos) {
        this.v = v;
        this.pos = pos;
    }
}

class SplayTree {
    private Node root;

    public void insert(Node node) {
        // Insert logic for splay tree
    }

    public void erase(Node node) {
        // Erase logic for splay tree
    }

    public Node begin() {
        // Return the first node
        return root; // Placeholder
    }

    public boolean isEmpty() {
        return root == null;
    }

    public int size() {
        // Return size of the tree
        return 0; // Placeholder
    }
}
