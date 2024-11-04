import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.io.BufferedReader;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    Scanner in;
    PrintWriter out;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
        run();
    }

    void run() {
        int n = in.nextInt();
        int k = in.nextInt();
        char[] cs = in.next().toCharArray();
        Hash2 h = new Hash2(n);
        long[] hs = h.build(cs);
        id3 sa = new id3(cs);
        sa.buildHs();
        sa.id4();
        int[] res = new int[n + 1];
        for (int len = 1; len * k <= n; len++) {
            if (fit(n, k, len, hs, h)) {
                int l = len * k == n ? 0 : sa.id2(0, len * k);
                l = Math.min(l, len);
                res[len * k - 1]++;
                res[len * k + l]--;
            }
        }
        for (int i = 0, crt = 0; i < n; i++) {
            crt += res[i];
            if (crt > 0) {
                out.print('1');
            } else {
                out.print('0');
            }
        }
        out.println();
    }

    private boolean fit(int n, int k, int len, long[] hs, Hash2 h) {
        if (k == 1) return true;
        for (int i = 1; ; i *= 2) {
            if (h.get(hs, 0, len * i) != h.get(hs, len * i, len * i * 2)) return false;
            if (i * 4 > k) return h.get(hs, 0, len * i * 2) == h.get(hs, len * k - len * i * 2, len * k);
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}

class Hash2 {
    public final long BL;
    public final long BR;
    public final long ML;
    public final long MR;
    public final long[] psl;
    public final long[] psr;

    public Hash2(int n) {
        Random r = new Random(System.nanoTime());
        BL = (long) (1e9 + r.nextInt((int) 1e9));
        BR = (long) (1e9 + r.nextInt((int) 1e9));
        ML = (long) (1e9 + r.nextInt((int) 1e9));
        MR = (long) (1e9 + r.nextInt((int) 1e9));
        psl = new long[n + 1];
        psr = new long[n + 1];
        for (int i = 0; i <= n; i++) psl[i] = (i == 0 ? 1 : psl[i - 1] * BL) % ML;
        for (int i = 0; i <= n; i++) psr[i] = (i == 0 ? 1 : psr[i - 1] * BR) % MR;
    }

    public long[] build(char[] cs) {
        int n = cs.length;
        long[] hs = new long[n + 1];
        long l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l = (l * BL + cs[i]) % ML;
            r = (r * BR + cs[i]) % MR;
            if (l < 0) l += ML;
            if (r < 0) r += MR;
            hs[i + 1] = (l << 32) | r;
        }
        return hs;
    }

    public long get(long[] hs, int b, int e) {
        long el = hs[e] >>> 32;
        long er = hs[e] & 0xffffffffL;
        long bl = hs[b] >>> 32;
        long br = hs[b] & 0xffffffffL;
        long l = el - bl * psl[e - b] % ML;
        long r = er - br * psr[e - b] % MR;
        if (l < 0) l += ML;
        if (r < 0) r += MR;
        return (l << 32) | r;
    }
}

class id3 {
    private static interface BaseArray {
        public int get(int i);

        public void set(int i, int val);

        public int update(int i, int val);
    }

    private static class CharArray implements BaseArray {
        private char[] m_A = null;
        private int m_pos = 0;

        CharArray(char[] A, int pos) {
            m_A = A;
            m_pos = pos;
        }

        public int get(int i) {
            return m_A[m_pos + i] & 0xffff;
        }

        public void set(int i, int val) {
            m_A[m_pos + i] = (char) (val & 0xffff);
        }

        public int update(int i, int val) {
            return m_A[m_pos + i] += val & 0xffff;
        }
    }

    private static class IntArray implements BaseArray {
        private int[] m_A = null;
        private int m_pos = 0;

        IntArray(int[] A, int pos) {
            m_A = A;
            m_pos = pos;
        }

        public int get(int i) {
            return m_A[m_pos + i];
        }

        public void set(int i, int val) {
            m_A[m_pos + i] = val;
        }

        public int update(int i, int val) {
            return m_A[m_pos + i] += val;
        }
    }

    
    private static void getCounts(BaseArray T, BaseArray C, int n, int k) {
        int i;
        for (i = 0; i < k; ++i) {
            C.set(i, 0);
        }
        for (i = 0; i < n; ++i) {
            C.update(T.get(i), 1);
        }
    }

    private static void getBuckets(BaseArray C, BaseArray B, int k, boolean end) {
        int i, sum = 0;
        if (end) {
            for (i = 0; i < k; ++i) {
                sum += C.get(i);
                B.set(i, sum);
            }
        } else {
            for (i = 0; i < k; ++i) {
                sum += C.get(i);
                B.set(i, sum - C.get(i));
            }
        }
    }

    
    private static void id1(BaseArray T, int[] SA, BaseArray C,
                                BaseArray B, int n, int k) {
        int b, i, j;
        int c0, c1;
        
        if (C == B) {
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, false); 
        j = n - 1;
        b = B.get(c1 = T.get(j));
        --j;
        SA[b++] = (T.get(j) < c1) ? ~j : j;
        for (i = 0; i < n; ++i) {
            if (0 < (j = SA[i])) {
                if ((c0 = T.get(j)) != c1) {
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                --j;
                SA[b++] = (T.get(j) < c1) ? ~j : j;
                SA[i] = 0;
            } else if (j < 0) {
                SA[i] = ~j;
            }
        }
		
        if (C == B) {
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, true); 
        for (i = n - 1, b = B.get(c1 = 0); 0 <= i; --i) {
            if (0 < (j = SA[i])) {
                if ((c0 = T.get(j)) != c1) {
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                --j;
                SA[--b] = (T.get(j) > c1) ? ~(j + 1) : j;
                SA[i] = 0;
            }
        }
    }

    private static int id5(BaseArray T, int[] SA, int n, int m) {
        int i, j, p, q, plen, qlen, name;
        int c0, c1;
        boolean diff;

		
        for (i = 0; (p = SA[i]) < 0; ++i) {
            SA[i] = ~p;
        }
        if (i < m) {
            for (j = i, ++i; ; ++i) {
                if ((p = SA[i]) < 0) {
                    SA[j++] = ~p;
                    SA[i] = 0;
                    if (j == m) {
                        break;
                    }
                }
            }
        }

		
        i = n - 1;
        j = n - 1;
        c0 = T.get(n - 1);
        do {
            c1 = c0;
        } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
        for (; 0 <= i; ) {
            do {
                c1 = c0;
            } while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
            if (0 <= i) {
                SA[m + ((i + 1) >> 1)] = j - i;
                j = i + 1;
                do {
                    c1 = c0;
                } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            }
        }

		
        for (i = 0, name = 0, q = n, qlen = 0; i < m; ++i) {
            p = SA[i];
            plen = SA[m + (p >> 1)];
            diff = true;
            if ((plen == qlen) && ((q + plen) < n)) {
                for (j = 0; (j < plen) && (T.get(p + j) == T.get(q + j)); ++j) ;
                if (j == plen) {
                    diff = false;
                }
            }
            if (diff) {
                ++name;
                q = p;
                qlen = plen;
            }
            SA[m + (p >> 1)] = name;
        }

        return name;
    }

    
    private static void id0(BaseArray T, int[] SA, BaseArray C,
                                 BaseArray B, int n, int k) {
        int b, i, j;
        int c0, c1;
		
        if (C == B) {
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, false); 
        j = n - 1;
        b = B.get(c1 = T.get(j));
        SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
        for (i = 0; i < n; ++i) {
            j = SA[i];
            SA[i] = ~j;
            if (0 < j) {
                if ((c0 = T.get(--j)) != c1) {
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
            }
        }
		
        if (C == B) {
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, true); 
        for (i = n - 1, b = B.get(c1 = 0); 0 <= i; --i) {
            if (0 < (j = SA[i])) {
                if ((c0 = T.get(--j)) != c1) {
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                SA[--b] = ((j == 0) || (T.get(j - 1) > c1)) ? ~j : j;
            } else {
                SA[i] = ~j;
            }
        }
    }

    
    private static void SA_IS(BaseArray T, int[] SA, int fs, int n, int k) {
        BaseArray C, B, RA;
        int i, j, b, m, p, q, name, newfs;
        int c0, c1;
        int flags;

        if (k <= 256) {
            C = new IntArray(new int[k], 0);
            if (k <= fs) {
                B = new IntArray(SA, n + fs - k);
                flags = 1;
            } else {
                B = new IntArray(new int[k], 0);
                flags = 3;
            }
        } else if (k <= fs) {
            C = new IntArray(SA, n + fs - k);
            if (k <= (fs - k)) {
                B = new IntArray(SA, n + fs - k * 2);
                flags = 0;
            } else if (k <= 1024) {
                B = new IntArray(new int[k], 0);
                flags = 2;
            } else {
                B = C;
                flags = 8;
            }
        } else {
            C = B = new IntArray(new int[k], 0);
            flags = 4 | 8;
        }

		
        getCounts(T, C, n, k);
        getBuckets(C, B, k, true); 
        for (i = 0; i < n; ++i) {
            SA[i] = 0;
        }
        b = -1;
        i = n - 1;
        j = n;
        m = 0;
        c0 = T.get(n - 1);
        do {
            c1 = c0;
        } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
        for (; 0 <= i; ) {
            do {
                c1 = c0;
            } while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
            if (0 <= i) {
                if (0 <= b) {
                    SA[b] = j;
                }
                b = B.update(c1, -1);
                j = i;
                ++m;
                do {
                    c1 = c0;
                } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            }
        }
        if (1 < m) {
            id1(T, SA, C, B, n, k);
            name = id5(T, SA, n, m);
        } else if (m == 1) {
            SA[b] = j + 1;
            name = 1;
        } else {
            name = 0;
        }

		
        if (name < m) {
            if ((flags & 4) != 0) {
                C = null;
                B = null;
            }
            if ((flags & 2) != 0) {
                B = null;
            }
            newfs = (n + fs) - (m * 2);
            if ((flags & (1 | 4 | 8)) == 0) {
                if ((k + name) <= newfs) {
                    newfs -= k;
                } else {
                    flags |= 8;
                }
            }
            for (i = m + (n >> 1) - 1, j = m * 2 + newfs - 1; m <= i; --i) {
                if (SA[i] != 0) {
                    SA[j--] = SA[i] - 1;
                }
            }
            RA = new IntArray(SA, m + newfs);
            SA_IS(RA, SA, newfs, m, name);

            i = n - 1;
            j = m * 2 - 1;
            c0 = T.get(n - 1);
            do {
                c1 = c0;
            } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            for (; 0 <= i; ) {
                do {
                    c1 = c0;
                } while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
                if (0 <= i) {
                    SA[j--] = i + 1;
                    do {
                        c1 = c0;
                    } while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
                }
            }

            for (i = 0; i < m; ++i) {
                SA[i] = SA[m + SA[i]];
            }
            if ((flags & 4) != 0) {
                C = B = new IntArray(new int[k], 0);
            }
            if ((flags & 2) != 0) {
                B = new IntArray(new int[k], 0);
            }
        }

		
        if ((flags & 8) != 0) {
            getCounts(T, C, n, k);
        }
		
        if (1 < m) {
            getBuckets(C, B, k, true); 
            i = m - 1;
            j = n;
            p = SA[m - 1];
            c1 = T.get(p);
            do {
                q = B.get(c0 = c1);
                while (q < j) {
                    SA[--j] = 0;
                }
                do {
                    SA[--j] = p;
                    if (--i < 0) {
                        break;
                    }
                    p = SA[i];
                } while ((c1 = T.get(p)) == c0);
            } while (0 <= i);
            while (0 < j) {
                SA[--j] = 0;
            }
        }
        id0(T, SA, C, B, n, k);
    }

    
    public static void suffixSort(char[] T, int[] SA, int n) {
        if ((T == null) || (SA == null) || (T.length < n) || (SA.length < n)) {
            return;
        }
        if (n <= 1) {
            if (n == 1) {
                SA[0] = 0;
            }
            return;
        }
        SA_IS(new CharArray(T, 0), SA, 0, n, 128);
    }

    public id3(char[] T) {
        cs = T;
        n = T.length;
        si = new int[n];
        suffixSort(T, si, n);
    }

    public int n;
    public int[] si;
    public int[] is; 

    public char[] cs;
    public int[] hs; 


    public void buildHs() {
        int h = 0;
        hs = new int[n];
        is = new int[n];
        for (int i = 0; i < n; i++) is[si[i]] = i;
        for (int i = 0; i < n; i++) {
            if (is[i] > 0) {
                for (int j = si[is[i] - 1]; j + h < n && i + h < n && cs[j + h] == cs[i + h]; h++) ;
                hs[is[i]] = h;
            } else {
                hs[is[i]] = 0;
            }
            if (h > 0) h--;
        }
    }
    
    public Seg seg;

    public void id4() {
        seg = new Seg(hs);
    }

    

    public int id2(int i, int j) {
        if (i == j) return n - i;
        return seg.query(Math.min(is[i] + 1, is[j] + 1), Math.max(is[i] + 1, is[j] + 1));
    }

    public static class Seg {
        public int[] is;
        public int N;

        public Seg(int[] hs) {
            N = Integer.highestOneBit(hs.length) << 1;
            is = new int[N * 2];
            for (int i = 0; i < N; i++) {
                if (i < hs.length) is[i + N] = hs[i];
            }
            for (int i = N - 1; i > 0; i--) {
                is[i] = Math.min(is[i * 2], is[i * 2 + 1]);
            }
        }

        public int query(int s, int t) {
            int res = Integer.MAX_VALUE;
            while (0 < s && s + (s & -s) <= t) {
                int i = (N + s) / (s & -s);
                res = Math.min(res, is[i]);
                s += s & -s;
            }
            while (s < t) {
                int i = (N + t) / (t & -t) - 1;
                res = Math.min(res, is[i]);
                t -= t & -t;
            }
            return res;
        }
    }


}
