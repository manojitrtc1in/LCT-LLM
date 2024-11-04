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








        int[] sa = sa(cs);
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
        for(i = 0;i < k;++i){
            C.set(i, 0);
        }
        for(i = 0;i < n;++i){
            C.update(T.get(i), 1);
        }
    }

    private static void getBuckets(BaseArray C, BaseArray B, int k, boolean end) {
        int i, sum = 0;
        if(end != false){
            for(i = 0;i < k;++i){
                sum += C.get(i);
                B.set(i, sum);
            }
        }else{
            for(i = 0;i < k;++i){
                sum += C.get(i);
                B.set(i, sum - C.get(i));
            }
        }
    }

    
    private static void id1(BaseArray T, int[] SA, BaseArray C,
                                BaseArray B, int n, int k) {
        int b, i, j;
        int c0, c1;
		
        if(C == B){
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, false); 
        j = n - 1;
        b = B.get(c1 = T.get(j));
        --j;
        SA[b++] = (T.get(j) < c1) ? ~j : j;
        for(i = 0;i < n;++i){
            if(0 < (j = SA[i])){
                if((c0 = T.get(j)) != c1){
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                --j;
                SA[b++] = (T.get(j) < c1) ? ~j : j;
                SA[i] = 0;
            }else if(j < 0){
                SA[i] = ~j;
            }
        }
		
        if(C == B){
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, true); 
        for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
            if(0 < (j = SA[i])){
                if((c0 = T.get(j)) != c1){
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                --j;
                SA[--b] = (T.get(j) > c1) ? ~(j + 1) : j;
                SA[i] = 0;
            }
        }
    }

    private static int id2(BaseArray T, int[] SA, int n, int m) {
        int i, j, p, q, plen, qlen, name;
        int c0, c1;
        boolean diff;

		
        for(i = 0;(p = SA[i]) < 0;++i){
            SA[i] = ~p;
        }
        if(i < m){
            for(j = i, ++i;;++i){
                if((p = SA[i]) < 0){
                    SA[j++] = ~p;
                    SA[i] = 0;
                    if(j == m){
                        break;
                    }
                }
            }
        }

		
        i = n - 1;
        j = n - 1;
        c0 = T.get(n - 1);
        do{
            c1 = c0;
        }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
        for(;0 <= i;){
            do{
                c1 = c0;
            }while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
            if(0 <= i){
                SA[m + ((i + 1) >> 1)] = j - i;
                j = i + 1;
                do{
                    c1 = c0;
                }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            }
        }

		
        for(i = 0, name = 0, q = n, qlen = 0;i < m;++i){
            p = SA[i];
            plen = SA[m + (p >> 1)];
            diff = true;
            if((plen == qlen) && ((q + plen) < n)){
                for(j = 0;(j < plen) && (T.get(p + j) == T.get(q + j));++j){
                }
                if(j == plen){
                    diff = false;
                }
            }
            if(diff != false){
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
		
        if(C == B){
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, false); 
        j = n - 1;
        b = B.get(c1 = T.get(j));
        SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
        for(i = 0;i < n;++i){
            j = SA[i];
            SA[i] = ~j;
            if(0 < j){
                if((c0 = T.get(--j)) != c1){
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
            }
        }
		
        if(C == B){
            getCounts(T, C, n, k);
        }
        getBuckets(C, B, k, true); 
        for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
            if(0 < (j = SA[i])){
                if((c0 = T.get(--j)) != c1){
                    B.set(c1, b);
                    b = B.get(c1 = c0);
                }
                SA[--b] = ((j == 0) || (T.get(j - 1) > c1)) ? ~j : j;
            }else{
                SA[i] = ~j;
            }
        }
    }

    
    private static void SA_IS(BaseArray T, int[] SA, int fs, int n, int k) {
        BaseArray C, B, RA;
        int i, j, b, m, p, q, name, newfs;
        int c0, c1;
        int flags = 0;

        if(k <= 256){
            C = new IntArray(new int[k], 0);
            if(k <= fs){
                B = new IntArray(SA, n + fs - k);
                flags = 1;
            }else{
                B = new IntArray(new int[k], 0);
                flags = 3;
            }
        }else if(k <= fs){
            C = new IntArray(SA, n + fs - k);
            if(k <= (fs - k)){
                B = new IntArray(SA, n + fs - k * 2);
                flags = 0;
            }else if(k <= 1024){
                B = new IntArray(new int[k], 0);
                flags = 2;
            }else{
                B = C;
                flags = 8;
            }
        }else{
            C = B = new IntArray(new int[k], 0);
            flags = 4 | 8;
        }

		
        getCounts(T, C, n, k);
        getBuckets(C, B, k, true); 
        for(i = 0;i < n;++i){
            SA[i] = 0;
        }
        b = -1;
        i = n - 1;
        j = n;
        m = 0;
        c0 = T.get(n - 1);
        do{
            c1 = c0;
        }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
        for(;0 <= i;){
            do{
                c1 = c0;
            }while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
            if(0 <= i){
                if(0 <= b){
                    SA[b] = j;
                }
                b = B.update(c1, -1);
                j = i;
                ++m;
                do{
                    c1 = c0;
                }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            }
        }
        if(1 < m){
            id1(T, SA, C, B, n, k);
            name = id2(T, SA, n, m);
        }else if(m == 1){
            SA[b] = j + 1;
            name = 1;
        }else{
            name = 0;
        }

		
        if(name < m){
            if((flags & 4) != 0){
                C = null;
                B = null;
            }
            if((flags & 2) != 0){
                B = null;
            }
            newfs = (n + fs) - (m * 2);
            if((flags & (1 | 4 | 8)) == 0){
                if((k + name) <= newfs){
                    newfs -= k;
                }else{
                    flags |= 8;
                }
            }
            for(i = m + (n >> 1) - 1, j = m * 2 + newfs - 1;m <= i;--i){
                if(SA[i] != 0){
                    SA[j--] = SA[i] - 1;
                }
            }
            RA = new IntArray(SA, m + newfs);
            SA_IS(RA, SA, newfs, m, name);
            RA = null;

            i = n - 1;
            j = m * 2 - 1;
            c0 = T.get(n - 1);
            do{
                c1 = c0;
            }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
            for(;0 <= i;){
                do{
                    c1 = c0;
                }while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
                if(0 <= i){
                    SA[j--] = i + 1;
                    do{
                        c1 = c0;
                    }while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
                }
            }

            for(i = 0;i < m;++i){
                SA[i] = SA[m + SA[i]];
            }
            if((flags & 4) != 0){
                C = B = new IntArray(new int[k], 0);
            }
            if((flags & 2) != 0){
                B = new IntArray(new int[k], 0);
            }
        }

		
        if((flags & 8) != 0){
            getCounts(T, C, n, k);
        }
		
        if(1 < m){
            getBuckets(C, B, k, true); 
            i = m - 1;
            j = n;
            p = SA[m - 1];
            c1 = T.get(p);
            do{
                q = B.get(c0 = c1);
                while (q < j){
                    SA[--j] = 0;
                }
                do{
                    SA[--j] = p;
                    if(--i < 0){
                        break;
                    }
                    p = SA[i];
                }while ((c1 = T.get(p)) == c0);
            }while (0 <= i);
            while (0 < j){
                SA[--j] = 0;
            }
        }
        id0(T, SA, C, B, n, k);
        C = null;
        B = null;
    }

    
    public static void suffixsort(char[] T, int[] SA, int n) {
        if((T == null) || (SA == null) || (T.length < n) || (SA.length < n)){
            return;
        }
        if(n <= 1){
            if(n == 1){
                SA[0] = 0;
            }
            return;
        }
        SA_IS(new CharArray(T, 0), SA, 0, n, 128);
    }

    public static int[] sa(char[] T)
    {
        int n = T.length;
        int[] sa = new int[n];
        suffixsort(T, sa, n);
        return sa;
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

