import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Node {
        int data;
        int count;
        Node left, right;

        public Node(int data) {
            this.data = data;
            this.count = 0;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTrie {
        Node root;

        public BinaryTrie() {
            this.root = new Node(0);
        }

        public void insert(int num) {
            Node temp = root;
            for (int i = 31; i >= 0; i--) {
                int val = num & (1 << i);
                if (val != 0) {
                    if (temp.right == null) {
                        temp.right = new Node(0);
                    }
                    temp = temp.right;
                    temp.count++;
                } else {
                    if (temp.left == null) {
                        temp.left = new Node(0);
                    }
                    temp = temp.left;
                    temp.count++;
                }
            }
            temp.data = num;
        }

        public int query(int xor) {
            Node temp = root;
            for (int i = 31; i >= 0; i--) {
                int val = xor & (1 << i);
                if (val == 0) {
                    if (temp.left != null && temp.left.count > 0) {
                        temp = temp.left;
                    } else if (temp.right != null) {
                        temp = temp.right;
                    }
                } else {
                    if (temp.right != null && temp.right.count > 0) {
                        temp = temp.right;
                    } else if (temp.left != null) {
                        temp = temp.left;
                    }
                }
                temp.count--;
            }
            return xor ^ temp.data;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        Pair[] t = new Pair[m];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            t[i] = new Pair(a, b);
        }
        Arrays.sort(t, new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                return p1.first - p2.first;
            }
        });

        int st = 1;
        int end = 2 * Arrays.stream(l).sum();
        int ans = end;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (check(mid, l, t)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        System.out.println(ans);
    }

    public static boolean check(int x, int[] l, Pair[] t) {
        int now = x;
        int c = Arrays.stream(l).sum();
        int cur = 0;
        int last = 0;
        Map<Integer, Integer> ld = new HashMap<>();
        for (int i = 0; i < t.length; i++) {
            if (t[i].first <= x) {
                ld.put(t[i].second, i);
            }
        }
        for (int i = 0; i < t.length; i++) {
            if (ld.get(t[i].second) != i) {
                continue;
            }
            if (t[i].first > x) {
                break;
            }
            cur += t[i].first - last;
            int rt = Math.min(cur, l[t[i].second - 1]);
            cur -= rt;
            now -= rt;
            c -= rt;
            last = t[i].first;
        }
        if (now >= 2 * c) {
            return true;
        }
        return false;
    }
}
