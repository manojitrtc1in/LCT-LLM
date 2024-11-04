import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import javafx.util.Pair;

public class CF {

    public static id22 in;
    public static PrintWriter out;

    public static void main(String[] args) {
        in = new id22(System.in);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        id7();
        out.close();
    }

    static class id22 {
        InputStream is;

        public id22(final InputStream is) {
            this.is = is;
        }

        private byte[] inbuf = new byte[8192];
        public int lenbuf = 0, ptrbuf = 0;

        public int readByte() {
            if (lenbuf == -1) {
                throw new InputMismatchException();
            }
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) {
                    return -1;
                }
            }
            return inbuf[ptrbuf++];
        }

        private boolean id6(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && id6(b)) {
                ;
            }
            return b;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char nextChar() {
            return (char)skip();
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(id6(b))) { 

                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public char[] id20(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(id6(b))) {
                buf[p++] = (char)b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        public int[] id9(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id35(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }

        public char[][] id0(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = id20(m);
            }
            return map;
        }

        public int[][] id1(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = id9(m);
            }
            return map;
        }

        public int nextInt() {
            int num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) {
                ;
            }
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long nextLong() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) {
                ;
            }
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }
    }

    static void id32() {
        int n = in.nextInt();
        long ans = 0;
        int[] cnts = new int[21];
        while (n-- > 0) {
            int num = in.nextInt();
            while (num > 0) {
                cnts[Integer.numberOfTrailingZeros(num & -num)]++;
                num &= num - 1;
            }
        }
        boolean find = true;
        while (find) {
            find = false;
            long cur = 0;
            for (int i = 20; i >= 0; i--) {
                cur <<= 1;
                if (cnts[i]-- > 0) {
                    cur++;
                    find = true;
                }
            }
            ans += cur * cur;
        }
        out.println(ans);
    }

    static void id26() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int[] nums = in.id9(n);
            long[] id23 = new long[n + 1];
            long[] f = new long[n + 1];
            long[] ff = new long[n + 1];
            for (int i = n - 1; i >= 0; i--) {
                id23[i] = nums[i] + id23[i + 1];
                f[i] = Math.max(f[i + 1], nums[i]);
            }
            int k = 2;
            for (int len = n - 1; len >= k; len -= k - 1) {
                ff[len - k + 1] = 0;
                for (int i = len - k; i >= 0; i--) {
                    long sum = id23[i] - id23[i + k];
                    ff[i] = ff[i + 1];
                    if (ff[i + 1] < sum && sum < f[i + k]) {
                        ff[i] = sum;
                    }
                }
                if (ff[0] == 0) {
                    break;
                }
                long[] tmp = f;
                f = ff;
                ff = tmp;
                k++;
            }
            out.println(k - 1);
        }
    }

    static void id21() {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        long[] sums = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            sums[i] = in.nextInt() + sums[i - 1];
        }
        long[][] f = new long[n + 1][k + 1];
        for (int j = 1; j <= k; j++) {
            for (int i = j * m; i <= n; i++) {
                f[i][j] = Math.max(f[i - 1][j], sums[i] - sums[i - m] + f[i - m][j - 1]);
            }
        }
        out.println(f[n][k]);
    }

    static void id3() {
        int ans = 0;
        int n = in.nextInt();
        int[] nums = in.id9(n);
        Stack<Integer> stack = new Stack<>();
        for (int num : nums) {
            while (!stack.empty() && stack.peek() < num) {
                ans = Math.max(ans, stack.pop() ^ num);
            }
            if (!stack.empty()) {
                ans = Math.max(ans, stack.peek() ^ num);
            }
            stack.push(num);
        }
        out.println(ans);
    }

    static void id31() {
        int ans = 0;
        int n = in.nextInt();
        int[] arr = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            arr[i] = in.nextInt();
            arr[i] = Math.min(arr[i], arr[i - 1] + 1);
        }
        for (int i = n; i >= 1; i--) {
            arr[i] = Math.min(arr[i], arr[i + 1] + 1);
            ans = Math.max(ans, arr[i]);
        }
        out.println(ans);
    }

    static void id11() {
        int n = in.nextInt();
        int[] nums = in.id9(n);
        int y = 1;
        for (int i = 1; i < n; i++) {
            int diff = Math.abs(nums[i] - nums[i - 1]);
            if (diff == 0) {
                out.println("NO");
                return;
            }
            if (diff > 1) {
                if (y == 1) {
                    y = diff;
                } else if (y != diff) {
                    out.println("NO");
                    return;
                }
            }
        }
        if (y > 1) {
            for (int i = 1; i < n; i++) {
                if (nums[i - 1] + 1 == nums[i] && nums[i - 1] % y == 0
                        || nums[i] + 1 == nums[i - 1] && nums[i] % y == 0) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
        out.println((int)1e9 + " " + y);
    }

    static void id12() {
        int n = in.nextInt();
        int c = in.nextInt();
        int[] a = in.id9(n - 1);
        int[] b = in.id9(n - 1);
        out.print(0);
        int time1 = 0;
        int time2 = c;
        for (int i = 0; i < n - 1; i++) {
            int time11 = Math.min(time1, time2) + a[i];
            int time22 = Math.min(time1 + c, time2) + b[i];
            time1 = time11;
            time2 = time22;
            out.print(" ");
            out.print(Math.min(time1, time2));
        }
    }

    static void id17() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n];
        int[] ids = new int[n + 1];
        int[] pres = new int[n + 1];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            ids[p[i]] = i + 1;
        }
        for (int i = 0; i < m; i++) {
            int x = in.nextInt(), y = in.nextInt();
            int idx = ids[x], idy = ids[y];
            if (idx < idy) {
                pres[y] = Math.max(pres[y], idx);
            } else {
                pres[x] = Math.max(pres[x], idy);
            }
        }
        long ans = 0;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = Math.max(pre, pres[p[i]]);
            ans += i + 1 - pre;
        }
        out.println(ans);
    }

    static void id13() {
        int n = in.nextInt(), m = in.nextInt();
        int[] a = new int[n], b = new int[m];
        int a1 = 0, b1 = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            a1 ^= a[i];
        }
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
            b1 ^= b[i];
        }
        if (a1 != b1) {
            out.println("NO");
            out.flush();
        } else {
            out.println("YES");
            int[][] ans = new int[n][m];
            ans[0][0] = a[0] ^ b1 ^ b[0];
            for (int i = 1; i < m; i++) {
                ans[0][i] = b[i];
            }
            for (int i = 1; i < n; i++) {
                ans[i][0] = a[i];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.print(ans[i][j]);
                    out.print(" ");
                }
                out.println();
            }
        }
    }

    static void id30() {
        int n = in.nextInt(), m = in.nextInt();
        int[] a = in.id9(n);
        int[][] b = new int[m][3];
        for (int i = 0; i < m; i++) {
            b[i][0] = in.nextInt() - 1;
            b[i][1] = in.nextInt() - 1;
            b[i][2] = i + 1;
        }
        Arrays.sort(b, Comparator.comparingInt(o -> o[0]));
        PriorityQueue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));
        int ans = Integer.MIN_VALUE;
        List<int[]> list = new ArrayList<>();
        

        TreeNode root = new TreeNode(a);
        for (int i = 0, j = 0; i < n; i++) {
            while (!queue.isEmpty() && queue.peek()[1] < i) {
                int[] p = queue.poll();
                

                root.update(1, 0, n - 1, p[0], p[1], 1);
            }
            while (j < m && b[j][0] <= i) {
                queue.offer(b[j]);
                

                root.update(1, 0, n - 1, b[j][0], b[j][1], -1);
                j++;
            }








            if (root.maxTree[1] - root.minTree[1] > ans) {
                ans = root.maxTree[1] - root.minTree[1];
                list = new ArrayList<>(queue);
            }
        }

        out.println(ans);
        out.println(list.size());
        for (int[] x : list) {
            out.print(x[2]);
            out.print(" ");
        }
        out.flush();
    }

    private static Node buildNode(int[] a, int left, int right) {
        Node node = new Node(left, right, a[left]);
        if (left == right) {
            return node;
        }
        node.leftNode = buildNode(a, left, left + (right - left) / 2);
        node.rightNode = buildNode(a, left + (right - left) / 2 + 1, right);
        node.max = Math.max(node.leftNode.max, node.rightNode.max);
        node.min = Math.min(node.leftNode.min, node.rightNode.min);
        return node;
    }

    static class Node {
        int left;
        int right;
        int max;
        int min;
        int mark;
        Node leftNode;
        Node rightNode;

        public Node(int l, int r, int v) {
            left = l;
            right = r;
            max = v;
            min = v;
        }

        public void pushDown() {
            if (mark != 0) {
                leftNode.max += mark;
                leftNode.min += mark;
                rightNode.max += mark;
                rightNode.min += mark;
                leftNode.mark += mark;
                rightNode.mark += mark;
                mark = 0;
            }
        }

        public void update(int lo, int hi, int v) {
            if (lo > right || hi < left) {
                return;
            }
            if (lo <= left && hi >= right) {
                max += v;
                min += v;
                mark += v;
                return;
            }
            pushDown();
            leftNode.update(lo, hi, v);
            rightNode.update(lo, hi, v);
            max = Math.max(leftNode.max, rightNode.max);
            min = Math.min(leftNode.min, rightNode.min);
        }
    }

    static class TreeNode {
        int[] maxTree;
        int[] minTree;
        int[] mark;

        public TreeNode(int[] a) {
            int n = a.length << 2;
            maxTree = new int[n];
            minTree = new int[n];
            mark = new int[n];
            buildTree(a, 1, 0, a.length - 1);
        }

        public void buildTree(int[] a, int idx, int lo, int hi) {
            if (lo == hi) {
                maxTree[idx] = a[lo];
                minTree[idx] = a[lo];
                return;
            }
            buildTree(a, idx << 1, lo, lo + (hi - lo >> 1));
            buildTree(a, (idx << 1) + 1, lo + (hi - lo >> 1) + 1, hi);
            maxTree[idx] = Math.max(maxTree[idx << 1], maxTree[(idx << 1) + 1]);
            minTree[idx] = Math.min(minTree[idx << 1], minTree[(idx << 1) + 1]);
        }

        public void pushDown(int idx) {
            if (mark[idx] != 0) {
                maxTree[idx << 1] += mark[idx];
                minTree[idx << 1] += mark[idx];
                mark[idx << 1] += mark[idx];
                maxTree[(idx << 1) + 1] += mark[idx];
                minTree[(idx << 1) + 1] += mark[idx];
                mark[(idx << 1) + 1] += mark[idx];
                mark[idx] = 0;
            }
        }

        public void update(int idx, int left, int right, int lo, int hi, int v) {
            if (lo > right || hi < left) {
                return;
            }
            if (lo <= left && hi >= right) {
                maxTree[idx] += v;
                minTree[idx] += v;
                mark[idx] += v;
                return;
            }
            pushDown(idx);
            update(idx << 1, left, left + (right - left >> 1), lo, hi, v);
            update((idx << 1) + 1, left + (right - left >> 1) + 1, right, lo, hi, v);
            maxTree[idx] = Math.max(maxTree[idx << 1], maxTree[(idx << 1) + 1]);
            minTree[idx] = Math.min(minTree[idx << 1], minTree[(idx << 1) + 1]);
        }
    }

    static class id14 {
        int[] tree;
        int[] mark;

        public id14(int n) {
            tree = new int[n];
            mark = new int[n];
        }

        public void pushDown(int idx) {
            if (mark[idx] != 0) {
                tree[idx << 1] |= mark[idx];
                mark[idx << 1] |= mark[idx];
                tree[(idx << 1) + 1] |= mark[idx];
                mark[(idx << 1) + 1] |= mark[idx];
                mark[idx] = 0;
            }
        }

        public void update(int idx, int left, int right, int lo, int hi, int v) {
            if (lo > right || hi < left || (tree[idx] & v) == v) {
                return;
            }
            if (lo <= left && hi >= right) {
                tree[idx] |= v;
                mark[idx] |= v;
                return;
            }
            pushDown(idx);
            update(idx << 1, left, left + (right - left >> 1), lo, hi, v);
            update((idx << 1) + 1, left + (right - left >> 1) + 1, right, lo, hi, v);
            tree[idx] = tree[idx << 1] & tree[(idx << 1) + 1];
        }

        public int query(int idx, int left, int right, int lo, int hi) {
            if (lo > right || hi < left) {
                return Integer.MAX_VALUE;
            }
            if (lo <= left && hi >= right) {
                return tree[idx];
            }
            pushDown(idx);
            return query(idx << 1, left, left + (right - left >> 1), lo, hi) &
                    query((idx << 1) + 1, left + (right - left >> 1) + 1, right, lo, hi);
        }
    }

    static void id19() {
        int n = in.nextInt(), m = in.nextInt();
        int[][] b = new int[m][3];
        id14 root = new id14(n << 2);
        for (int i = 0; i < m; i++) {
            b[i][0] = in.nextInt() - 1;
            b[i][1] = in.nextInt() - 1;
            b[i][2] = in.nextInt();
            root.update(1, 0, n - 1, b[i][0], b[i][1], b[i][2]);
        }
        for (int i = 0; i < m; i++) {
            if (root.query(1, 0, n - 1, b[i][0], b[i][1]) != b[i][2]) {
                out.println("NO");
                out.flush();
                return;
            }
        }
        out.println("YES");
        for (int i = 0; i < n; i++) {
            out.print(root.query(1, 0, n - 1, i, i));
            out.print(" ");
        }
        out.flush();
    }

    static void id27() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt(), s = -in.nextInt();
            int left = 1, right = 0;
            long sum = 0;
            int[] a = new int[n];
            for (int i = 0, j = 0; i < n; i++) {
                a[i] = in.nextInt();
                sum += a[i];
                while (j <= i && sum < s) {
                    sum -= a[j++];
                }
                if (i - j > right - left) {
                    left = j + 1;
                    right = i + 1;
                }
            }
            if (right >= left) {
                out.println(left + " " + right);
            } else {
                out.println(-1);
            }
            out.flush();
        }
    }

    static void id33() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            if ((n & 1) == 1) {
                if (k < m / 2) {
                    out.println("NO");
                    continue;
                }
                k -= m / 2;
            }
            if ((m & 1) == 1) {
                if (k > m / 2 * n) {
                    out.println("NO");
                    continue;
                }
            }
            if ((k & 1) == 1) {
                out.println("NO");
            } else {
                out.println("YES");
            }
        }
        out.flush();
    }

    static void id16() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            char[][] ans = new char[n][m];
            if ((n & 1) == 1) {
                if (k < m / 2) {
                    out.println("NO");
                    continue;
                }
                k -= m / 2;
                for (int i = 1; i < m; i += 2) {
                    char c = (char)('f' ^ (i / 2 & 1));
                    ans[n - 1][i] = c;
                    ans[n - 1][i - 1] = c;
                }
            }
            if ((m & 1) == 1) {
                if (k > m / 2 * n) {
                    out.println("NO");
                    continue;
                }
                for (int i = 1; i < n; i += 2) {
                    char c = (char)('f' ^ (i / 2 & 1));
                    ans[i][m - 1] = c;
                    ans[i - 1][m - 1] = c;
                }
            }
            if ((k & 1) == 1) {
                out.println("NO");
                continue;
            }
            out.println("YES");
            for (int i = 1; i < n; i += 2) {
                for (int j = 1; j < m; j += 2) {
                    if (k > 0) {
                        k -= 2;
                        char c = (char)('b' ^ (j / 2 & 1));
                        ans[i][j] = c;
                        ans[i][j - 1] = c;
                        ans[i - 1][j] = (char)(c ^ 1);
                        ans[i - 1][j - 1] = (char)(c ^ 1);
                    } else {
                        char c = (char)('d' ^ (i / 2 & 1));
                        ans[i][j] = c;
                        ans[i - 1][j] = c;
                        ans[i][j - 1] = (char)(c ^ 1);
                        ans[i - 1][j - 1] = (char)(c ^ 1);
                    }
                }
            }
            for (char[] an : ans) {
                out.println(new String(an));
            }
        }
        out.flush();
    }

    static void id4() {
        int n = in.nextInt();
        int[] a = in.id9(n);
        int[][] f = new int[n + 1][4];
        

        

        

        

        

        

        

        

        

        

        for (int i = 1; i <= n; i++) {
            f[i][0] = a[i - 1] == 1 ? f[i - 1][0] + 1 : f[i - 1][0];
            f[i][1] = a[i - 1] == 1 ? f[i - 1][1] : Math.max(f[i - 1][0], f[i - 1][1]) + 1;
            f[i][2] = a[i - 1] == 1 ? Math.max(f[i - 1][1], f[i - 1][2]) + 1 : f[i - 1][2];
            f[i][3] = a[i - 1] == 1 ? f[i - 1][3] : Math.max(f[i - 1][2], f[i - 1][3]) + 1;
        }
        int ans = Math.max(Math.max(f[n][0], f[n][1]), Math.max(f[n][2], f[n][3]));
        out.println(ans);
        out.flush();
    }

    static void id34() {
        int t = in.nextInt();
        while (t-- > 0) {
            long l = in.nextLong(), r = in.nextLong();
            int i = 1;
            while ((l | i) < r) {
                l |= i;
                i <<= 1;
            }
            out.println(l);
        }
        out.flush();
    }

    static void id2() {
        int n = in.nextInt(), a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
        String s = in.next();
        PriorityQueue<Pair<Integer, Integer>> queue =
                new PriorityQueue<>((o1, o2) -> o2.getValue() - o2.getKey() - o1.getValue() + o1.getKey());
        int cnt = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                continue;
            }
            int j = i - 1 + b;
            for (; i < n && s.charAt(i) == '0'; i++) {
            }
            for (; j < i; j += b) {
                cnt++;
                list.add(j + 1);
            }
        }
        out.println(cnt - a + 1);
        for (int i = a - 1; i < list.size(); i++) {
            out.print(list.get(i));
            out.print(" ");
        }
        out.flush();
    }

    static void id15() {
        int n = in.nextInt(), m = in.nextInt(), b = in.nextInt(), mod = in.nextInt();
        int[] a = in.id9(n);
        int[][] f = new int[m + 1][b + 1];
        

        f[0][0] = 1;
        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= m; j++) {
                for (int k = a[i - 1]; k <= b; k++) {
                    f[j][k] = (f[j][k] + f[j - 1][k - a[i - 1]]) % mod;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= b; i++) {
            ans = (ans + f[m][i]) % mod;
        }
        out.println(ans);
    }

    static void id18() {
        int n = in.nextInt(), k = in.nextInt();
        

        

        int[][] f = new int[k + 1][k * 25 + 1];
        for (int[] ints : f) {
            Arrays.fill(ints, -1);
        }
        f[0][0] = 0;
        while (n-- > 0) {
            long a = in.nextLong();
            int cnt2 = Long.numberOfTrailingZeros(a);
            int cnt5 = 0;
            while (a % 5 == 0 && a > 0) {
                a /= 5;
                cnt5++;
            }
            for (int i = k; i > 0; i--) {
                for (int j = k * 25; j >= cnt5; j--) {
                    if (f[i - 1][j - cnt5] >= 0) {
                        f[i][j] = Math.max(f[i][j], f[i - 1][j - cnt5] + cnt2);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < f[k].length; i++) {
            ans = Math.max(ans, Math.min(i, f[k][i]));
        }
        out.println(ans);
        out.flush();
    }

    static void id5() {
        int n = in.nextInt(), k = in.nextInt();
        int ave = (n - 1) / k, more = (n - 1) % k;
        out.println(2 * ave + Math.min(2, more));
        for (int i = 1, id = k + 2; i <= k; i++) {
            int lim = ave;
            if (i <= more) {
                lim++;
            }
            out.println(k + 1 + " " + i);
            int cur = i;
            for (int j = 1; j < lim; j++) {
                out.println(cur + " " + id);
                cur = id++;
            }
        }
    }

    static void id8() {
        int n = in.nextInt(), m = in.nextInt();
        int[] a = in.id9(n);
        Pair<Pair<Integer, Integer>, Integer>[] b = new Pair[m];
        for (int i = 0; i < m; i++) {
            b[i] = new Pair<>(new Pair<>(in.nextInt(), i), in.nextInt());
        }
        int[] ans = new int[m];
        Arrays.fill(ans, -1);
        Arrays.sort(b, Comparator.comparingInt(Pair::getValue));
        Node552 root = new Node552(1, n);
        Map<Integer, Integer> preMap = new HashMap<>();
        for (int i = 0, j = 0; i < n; i++) {
            if (preMap.containsKey(a[i])) {
                root.update(preMap.get(a[i]), preMap.get(a[i]), i - preMap.get(a[i]) + 1);
            }
            preMap.put(a[i], i + 1);
            while (j < m && b[j].getValue() == i + 1) {
                ans[b[j].getKey().getValue()] = root.query(b[j].getKey().getKey(), b[j].getValue());
                j++;
            }
        }
        for (int x : ans) {
            if (x == Integer.MAX_VALUE) {
                x = -1;
            }
            out.println(x);
        }
        out.flush();
    }

    static class Node552 {
        int left;
        int right;
        int val;
        Node552 leftNode;
        Node552 rightNode;

        public Node552(int l, int r) {
            left = l;
            right = r;
            val = Integer.MAX_VALUE;
        }

        public Node552 id28() {
            if (leftNode == null) {
                leftNode = new Node552(left, left + (right - left) / 2);
            }
            return leftNode;
        }

        public Node552 id24() {
            if (rightNode == null) {
                rightNode = new Node552(left + (right - left) / 2 + 1, right);
            }
            return rightNode;
        }

        public void update(int lo, int hi, int v) {
            if (left > hi || right < lo) {
                return;
            }
            if (left >= lo && right <= hi) {
                val = Math.min(val, v);
                return;
            }
            id28().update(lo, hi, v);
            id24().update(lo, hi, v);
            val = Math.min(leftNode.val, rightNode.val);
        }

        public int query(int lo, int hi) {
            if (left > hi || right < lo) {
                return Integer.MAX_VALUE;
            }
            if (left >= lo && right <= hi) {
                return val;
            }
            return Math.min(id28().query(lo, hi), id24().query(lo, hi));
        }
    }

    static void id29() {
        int n = in.nextInt(), m = in.nextInt();
        int[] a = in.id9(n), b = in.id9(n);
        Node292 root = new Node292(0, (int)(1e5 + 1));
        while (m-- > 0) {
            if (in.nextInt() == 1) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1, k = in.nextInt();
                root.update(y, y + k - 1, x - y);
            } else {
                int x = in.nextInt() - 1;
                int diff = root.query(x, x);
                if (diff == Integer.MAX_VALUE) {
                    out.println(b[x]);
                } else {
                    out.println(a[x + diff]);
                }
            }
        }
    }

    static class Node292 {
        int left;
        int right;
        int val;
        boolean mark;
        Node292 leftNode;
        Node292 rightNode;

        public Node292(int l, int r) {
            left = l;
            right = r;
            val = Integer.MAX_VALUE;
        }

        public Node292 id28() {
            if (leftNode == null) {
                leftNode = new Node292(left, left + (right - left) / 2);
            }
            return leftNode;
        }

        public Node292 id24() {
            if (rightNode == null) {
                rightNode = new Node292(left + (right - left) / 2 + 1, right);
            }
            return rightNode;
        }

        public void update(int lo, int hi, int v) {
            if (left > hi || right < lo) {
                return;
            }
            if (left >= lo && right <= hi) {
                val = v;
                mark = true;
                return;
            }
            pushDown();
            id28().update(lo, hi, v);
            id24().update(lo, hi, v);
        }

        public int query(int lo, int hi) {
            if (left > hi || right < lo) {
                return Integer.MAX_VALUE;
            }
            if (left >= lo && right <= hi || val != Integer.MAX_VALUE) {
                return val;
            }
            pushDown();
            int ans = id28().query(lo, hi);
            if (ans != Integer.MAX_VALUE) {
                return ans;
            }
            return id24().query(lo, hi);
        }

        public void pushDown() {
            if (mark) {
                id28().val = val;
                id24().val = val;
                leftNode.mark = true;
                rightNode.mark = true;
                val = Integer.MAX_VALUE;
                mark = false;
            }
        }
    }

    static void id25() {
        class Interval {
            boolean isOdd;
            int left;
            int right;

            public Interval(boolean is, int l, int r) {
                isOdd = is;
                left = l;
                right = r;
            }
        }
        int ans = 0;
        int n = in.nextInt();
        int[] p = in.id9(n);
        int odd = 0, even = 0;
        int head = 0, tail = n - 1;
        for (; head < n && p[head] == 0; head++) {
        }
        for (; tail >= 0 && p[tail] == 0; tail--) {
        }
        if (head > tail) {
            if (n > 1) {
                out.println(1);
            } else {
                out.println(0);
            }
            return;

        }
        int pre = head;
        PriorityQueue<Interval> queue = new PriorityQueue<>(Comparator.comparingInt(o -> (o.right - o.left)));
        for (int i = head; i <= tail; i++) {
            if (p[i] == 0) {
                continue;
            }
            if ((p[i] & 1) == 1) {
                odd++;
                if (i - pre > 1 && (p[pre] & 1) == 1) {
                    queue.offer(new Interval(true, pre, i));
                }
            } else {
                even++;
                if (i - pre > 1 && (p[pre] & 1) == 0) {
                    queue.offer(new Interval(false, pre, i));
                }
            }
            pre = i;
        }
        odd = (n + 1) / 2 - odd;
        even = n / 2 - even;
        while (!queue.isEmpty()) {
            Interval it = queue.poll();
            if (it.isOdd && odd < it.right - it.left - 1 || !it.isOdd && even < it.right - it.left - 1) {
                continue;
            }
            for (int i = it.left + 1; i < it.right; i++) {
                if (it.isOdd) {
                    p[i] = 1;
                    odd--;
                } else {
                    p[i] = 2;
                    even--;
                }
            }
        }
        if ((p[head] & 1) == 1 && odd >= head || (p[head] & 1) == 0 && even >= head) {
            for (int i = 0; i < head; i++) {
                if ((p[head] & 1) == 1) {
                    p[i] = 1;
                    odd--;
                } else {
                    p[i] = 2;
                    even--;
                }
            }
        }
        if ((p[tail] & 1) == 1 && odd >= n - tail - 1 || (p[tail] & 1) == 0 && even >= n - tail - 1) {
            for (int i = tail + 1; i < n; i++) {
                if ((p[tail] & 1) == 1) {
                    p[i] = 1;
                    odd--;
                } else {
                    p[i] = 2;
                    even--;
                }
            }
        }
        for (int i = head - 1; i >= 0; i--) {
            if (p[i] != 0) {
                continue;
            }
            if ((p[i + 1] & 1) == 1 && odd > 0 || even == 0) {
                p[i] = 1;
                odd--;
            } else {
                p[i] = 2;
                even--;
            }
        }
        for (int i = head + 1; i < n; i++) {
            if (p[i] != 0) {
                continue;
            }
            if ((p[i - 1] & 1) == 1 && odd > 0 || even == 0) {
                p[i] = 1;
                odd--;
            } else {
                p[i] = 2;
                even--;
            }
        }
        for (int i = 1; i < n; i++) {
            if ((p[i - 1] & 1) != (p[i] & 1)) {
                ans++;
            }
        }
        out.println(ans);
    }

    static void id10() {
        int n = in.nextInt();
        int[][] f = new int[n / 2 + 1][2];
        for (int j = 1; j < f.length; j++) {
            f[j][0] = 10000;
            f[j][1] = 10000;
        }
        for (int i = 0; i < n; i++) {
            int num = in.nextInt();
            for (int j = n / 2; j >= 0; j--) {
                if (num == 0 || num % 2 == 1) {
                    f[j][1] = Math.min(f[j][0] + 1, f[j][1]);
                } else {
                    f[j][1] = 10000;
                }
                if (num % 2 == 0 && j > 0) {
                    f[j][0] = Math.min(f[j - 1][0], f[j - 1][1] + 1);
                } else {
                    f[j][0] = 10000;
                }
            }
        }
        out.println(Math.min(f[n / 2][0], f[n / 2][1]));
    }

    static void id7() {
        int n = in.nextInt();
        long m = (long)(3e5);
        int[][] grid = new int[n][2];
        int[][] ans = new int[n][2];
        Map<Long, Integer> map = new HashMap<>();
        Set<Long> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            grid[i][0] = in.nextInt();
            grid[i][1] = in.nextInt();
            map.put(grid[i][0] * m + grid[i][1], i);
            set.add(grid[i][0] * m + grid[i][1]);
        }
        Queue<Long[]> queue = new LinkedList<>();
        int[][] dirs = new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            int r = grid[i][0];
            int c = grid[i][1];
            for (int[] dir : dirs) {
                long idx = (r + dir[0]) * m + c + dir[1];
                if (!set.contains(idx)) {
                    queue.offer(new Long[] {idx, idx});
                    break;
                }
            }
        }
        while (!queue.isEmpty()) {
            Long[] cur = queue.poll();
            int r = (int)(cur[0] / m);
            int c = (int)(cur[0] % m);
            for (int[] dir : dirs) {
                long idx = (r + dir[0]) * m + c + dir[1];
                if (set.contains(idx)) {
                    ans[map.get(idx)][0] = (int)(cur[1] / m);
                    ans[map.get(idx)][1] = (int)(cur[1] % m);
                    set.remove(idx);
                    queue.offer(new Long[] {idx, cur[1]});
                }
            }
        }

        for (int[] a : ans) {
            out.println(a[0] + " " + a[1]);
        }
    }
}
