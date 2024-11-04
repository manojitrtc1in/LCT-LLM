import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
import java.math.BigInteger;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.io.IOException;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    Scanner in;
    PrintWriter out;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
        run();
    }

    void run() {
        char[] cs = in.next().toCharArray();
        int n = cs.length;
        int n2 = n * 2;
        cs = Algo.merge(cs, cs);


        int[] is = new int[n2];
        for (int i = 0; i < n2; i++) is[i] = cs[i];
        int[] sa = buildSuffixArray(is);


        Seg seg = new Seg(cs);
        int[] lr = new int[2];
        for (int i = 0; ; i++) {
            int id = sa[i];
            if (id < n) {
                seg.query(id, id + n, lr);
                if (lr[1] == 0) {
                    for (int j = 0; j < lr[0]; j++) out.print('(');
                    for (int j = 0; j < n; j++) out.print(cs[j + id]);
                    out.println();
                    return ;
                } else if (lr[0] == 0) {
                    for (int j = 0; j < n; j++) out.print(cs[j + id]);
                    for (int j = 0; j < lr[1]; j++) out.print(')');
                    out.println();
                    return ;
                }
            }
        }
    }
























    private int[] buildSuffixArray(int[] _s) {
        int[] s = compress(_s);
        int n = s.length;
        int[] am = new int[n];
        for (int x : s) {
            ++am[x];
        }
        int[] start = new int[n];
        int numCols = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (am[i] > 0) {
                start[numCols] = total;
                total += am[i];
                ++numCols;
            }
        }
        int[] sa = new int[n];
        int[] col = new int[n];
        int[] tmp = start.clone();
        for (int i = 0; i < n; i++) {
            col[i] = s[i];
            sa[tmp[col[i]]++] = i;
        }
        int len = 1;
        while (len < n) {
            int[] nsa = new int[n];
            int[] ncol = new int[n];
            for (int i = 0; i < n; i++) {
                int j = sa[i] - len;
                if (j < 0) {
                    j += n;
                }
                nsa[start[col[j]]++] = j;
            }
            numCols = 1;
            start[0] = 0;
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    int u = nsa[i];
                    int v = nsa[i - 1];
                    if (col[u] != col[v] || col[(u + len) % n] != col[(v + len) % n]) {
                        start[numCols] = i;
                        ++numCols;
                    }
                }
                ncol[nsa[i]] = numCols - 1;
            }
            sa = nsa;
            col = ncol;
            len *= 2;
        }
        return sa;
    }

    private int[] compress(int[] s) {
        int[] sorted = s.clone();
        Arrays.sort(sorted);
        int k = 0;
        for (int i = 0; i < sorted.length; i++) {
            if (i == 0 || sorted[i] != sorted[i - 1]) {
                sorted[k++] = sorted[i];
            }
        }
        int[] res = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Arrays.binarySearch(sorted, 0, k, s[i]);
        }
        return res;
    }

    class Seg {
        int N;
        int[] left, right;

        Seg(char[] cs) {
            int n = cs.length;
            N = Integer.highestOneBit(n) << 1;
            left = new int[N * 2];
            right = new int[N * 2];
            for (int i = 0; i < N; i++) {
                if (i < n && cs[i] == '(') {
                    left[i + N] = 0;
                    right[i + N] = 1;
                } else {
                    left[i + N] = 1;
                    right[i + N] = 0;
                }
            }
            for (int i = N - 1; i > 0; i--) {
                left[i] = left[i * 2] + Math.max(0, left[i * 2 + 1] - right[i * 2]);
                right[i] = right[i * 2 + 1] + Math.max(0, right[i * 2] - left[i * 2 + 1]);
            }
        }
        void query(int s, int t, int[] lr) {
            int l = 0, r = 0;
            while (0 < s && s + (s & -s) <= t) {
                int i = (N + s) / (s & -s);
                int nl = l + Math.max(0, left[i] - r);
                int nr = right[i] + Math.max(0, r - left[i]);
                l = nl; r = nr;
                s += s & -s;
            }
            int l2 = 0, r2 = 0;
            while (s < t) {
                int i = (N + t) / (t & -t) - 1;
                int nl = left[i] + Math.max(0, l2 - right[i]);
                int nr = r2 + Math.max(0, right[i] - l2);
                l2 = nl; r2 = nr;
                t -= t & -t;
            }
            lr[0] = l + Math.max(0, l2 - r);
            lr[1] = r2 + Math.max(0, r - l2);
        }
    }


}

class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null)
                return false;
            eat(s);
        }
        return true;
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }

}

class Algo {


    public static char[] merge(char[] is, char[] js) {
        int in = is.length;
        int jn = js.length;
        char[] rs = new char[in + jn];
        System.arraycopy(is, 0, rs, 0, in);
        System.arraycopy(js, 0, rs, in, jn);
        return rs;
    }

}

