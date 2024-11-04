import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;

public class CF {

    public static id14 in;
    public static PrintWriter out;

    public static void main(String[] args) {
        in = new id14(System.in);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        id9();
        out.close();
    }

    static class id14 {
        InputStream is;

        public id14(final InputStream is) {
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

        private boolean id3(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && id3(b)) {
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
            while (!(id3(b))) { 

                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public char[] id12(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(id3(b))) {
                buf[p++] = (char)b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        public int[] id4(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id22(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }

        public char[][] id0(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = id12(m);
            }
            return map;
        }

        public int[][] id1(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = id4(m);
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

    static void id20() {
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

    static void id16() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int[] nums = in.id4(n);
            long[] id15 = new long[n + 1];
            long[] f = new long[n + 1];
            long[] ff = new long[n + 1];
            for (int i = n - 1; i >= 0; i--) {
                id15[i] = nums[i] + id15[i + 1];
                f[i] = Math.max(f[i + 1], nums[i]);
            }
            int k = 2;
            for (int len = n - 1; len >= k; len -= k - 1) {
                ff[len - k + 1] = 0;
                for (int i = len - k; i >= 0; i--) {
                    long sum = id15[i] - id15[i + k];
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

    static void id13() {
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

    static void id2() {
        int ans = 0;
        int n = in.nextInt();
        int[] nums = in.id4(n);
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

    static void id19() {
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

    static void id5() {
        int n = in.nextInt();
        int[] nums = in.id4(n);
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

    static void id6() {
        int n = in.nextInt();
        int c = in.nextInt();
        int[] a = in.id4(n - 1);
        int[] b = in.id4(n - 1);
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

    static void id10() {
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

    static void id7() {
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

    static void id18() {
        int n = in.nextInt(), m = in.nextInt();
        int[] a = in.id4(n);
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

    static class id8 {
        int[] tree;
        int[] mark;

        public id8(int n) {
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

    static void id11() {
        int n = in.nextInt(), m = in.nextInt();
        int[][] b = new int[m][3];
        id8 root = new id8(n << 2);
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

    static void id17() {
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

    static void id21() {
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

    static void id9() {
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

}
