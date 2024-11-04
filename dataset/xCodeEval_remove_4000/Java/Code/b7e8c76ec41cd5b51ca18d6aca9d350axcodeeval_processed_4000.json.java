import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

	public class MainSolution extends id9 {
	
	    

	
	    public void init(int tests_count){}
	
	    public long fff(long a, long b)
	    {
	        long g = Numth.gcd(a, b);
	        return (a/g) * (b/g);
	    }
	
	    public class TestCase extends id10
	    {
	        int M = 50001;
	        long MM = M * (long)M;
	        int[] ftmp = new int [M];
	        int[][] dvs = new int[M][];
	        int K, S = 150;
	
	        int[] L, R;
	
	        int[][] dm;
	        int[] a, b;
	
	        int[] primes;
	        int prime_count;
	
	        long[][] ans;
	
	        boolean[] is_prime;
	
	        public void id8()
	        {
	            is_prime = new boolean[M];
	            Arrays.fill(is_prime, true);
	            primes = new int[5500];
	            prime_count = 0;
	
	            int i, j;
	            for (i=2; i*i<M; i++)
	            {
	                if (is_prime[i])
	                {
	                    for (j=i; j*i<M; j++)
	                    {
	                        is_prime[i*j] = false;
	                    }
	                }
	            }
	
	            for (i=2; i<M; i++)
	            {
	                if (is_prime[i])
	                {
	                    primes[prime_count++] = i;
	                }
	            }
	        }
	
	        private class Tree {
	            int li, ri;
	            Tree left, right;
	            boolean is_same;
	            int same_val;
	            long[] dans;
	            boolean is_actual;
	            long cmin;
	
	            public Tree(int l, int r)
	            {
	                li = l;
	                ri = r;
	                is_same = false;
	                is_actual = false;
	                left = null;
	                right = null;
	
	                dans = new long[M];
	                if (li == ri)
	                {
	                    for (int i=1; i<M; i++)
	                    {
	                        dans[i] = ans[l][i];
	                    }
	                }
	                else
	                {
	                    int c = (l + r) / 2;
	                    left = new Tree(l, c);
	                    right = new Tree(c+1, r);
	                    for (int i=1; i<M; i++)
	                    {
	                        dans[i] = Math.min(left.dans[i], right.dans[i]);
	                    }
	                }
	            }
	
	            public void update(int l, int r, int x)
	            {
	                if ((l == li) && (r == ri))
	                {
	                    is_same = true;
	                    same_val = x;
	                    id4();
	                }
	                else
	                {
	                    if (is_same)
	                    {
	                        left.update(left.li, left.ri, same_val);
	                        right.update(right.li, right.ri, same_val);
	                        is_same = false;
	                    }
	
	                    if (l <= left.ri)
	                    {
	                        left.update(l, Math.min(r, left.ri), x);
	                    }
	
	                    if (r >= right.li)
	                    {
	                        right.update(Math.max(l, right.li), r, x);
	                    }
	                }
	                is_actual = false;
	            }
	
	            public void break_same(int i)
	            {
	                is_actual = false;
	
	                if ((li == i) && (ri == i))
	                {
	                    if (is_same)
	                    {
	                        for (int j=L[i]; j<=R[i]; j++)
	                        {
	                            a[j] = same_val;
	                        }
	                    }
	                }
	                else
	                {
	                    if (is_same)
	                    {
	                        left.update(left.li, left.ri, same_val);
	                        right.update(right.li, right.ri, same_val);
	                    }
	
	                    if (i <= left.ri)
	                    {
	                        left.break_same(i);
	                    }
	                    else
	                    {
	                        right.break_same(i);
	                    }
	                }
	
	                is_same = false;
	            }
	
	            public long get_min(int l, int r)
	            {
	                if ((l == li) && (r == ri))
	                {
	                    if (!is_actual)
	                    {
	                        if (is_same)
	                        {
	                            cmin = dans[same_val];
	                        }
	                        else if (li == ri)
	                        {
	                            cmin = MM;
	                            for (int j=L[li]; j<=R[li]; j++)
	                            {
	                                long f = fff(a[j], b[j]);
	                                if (f < cmin)
	                                {
	                                    cmin = f;
	                                }
	                            }
	                        }
	                        else
	                        {
	                            cmin = Math.min( left.get_min(left.li, left.ri), right.get_min(right.li, right.ri));
	                        }
	                    }
	                    is_actual = true;
	                    return cmin;
	                }
	                else
	                {
	                    long m1 = MM;
	                    long m2 = MM;
	
	                    if (is_same)
	                    {
	                        left.update(left.li, left.ri, same_val);
	                        right.update(right.li, right.ri, same_val);
	                    }
	
	                    if (l <= left.ri)
	                    {
	                        m1 = left.get_min(l, Math.min(r, left.ri));
	                    }
	
	                    if (r >= right.li)
	                    {
	                        m2 = right.get_min(Math.max(l, right.li), r);
	                    }
	
	                    return Math.min(m1, m2);
	                }
	            }
	
	            public void id4()
	            {
	                is_actual = false;
	                if (li < ri)
	                {
	                    left.id4();
	                    right.id4();
	                }
	            }
	        }
	
	        public int[] factors(int x)
	        {
	            int l = 0;
	            int r = 0;
	            int i;
	
	            for (i=1; i*i <= x; i++)
	            {
	                if (x % i == 0)
	                {
	                    ftmp[l++] = i;
	
	                    if (x != i*i)
	                    {
	                        ftmp[M - (r++) -1] = x/i;
	                    }
	                }
	            }
	
	            int c = l+r;
	            int[] a = new int[c];
	
	            for (i=0; i<l; i++)
	            {
	                a[i] = ftmp[i];
	            }
	
	            for (i=0; i<r; i++)
	            {
	                a[l++] = ftmp[M-r+i];
	            }
	
	            return a;
	        }
	
	        public Object solve()
	        {
	            int i,j;
	            for (i=1; i<M; i++)
	            {
	                dvs[i] = factors(i);
	            }
	
	            int n = readInt();
	            int q = readInt();
	
	            K = (n+S-1) / S;
	            L = new int[K];
	            R = new int[K];
	
	            for (i=0; i<K; i++)
	            {
	                L[i] = S*i;
	                R[i] = S*i+S < n ? S*i+S-1 : n-1;
	            }
	
	            dm = new int[K][M];
	            for (i=0; i<K; i++)
	            {
	                Arrays.fill(dm[i], M+1);
	            }
	
	            a = id0(n);
	            b = id0(n);
	
	            for (i=0; i<n; i++)
	            {
	                for (j=0; j<dvs[b[i]].length; j++)
	                {
	                    if (b[i] < dm[i/S][dvs[b[i]][j]])
	                    {
	                        dm[i/S][dvs[b[i]][j]] = b[i];
	                    }
	                }
	            }
	
	            id8();
	            int cc = 0;
	
	            ans = new long[K][M];
	            for (int x=1; x<M; x++)
	            {
	                for (j=0; j<K; j++)
	                {
	                    if (dm[j][x] < M)
	                    {
	                        ans[j][x] = dm[j][x] / x;
	                    }
	                    else
	                    {
	                        ans[j][x] = MM;
	                    }
	                }
	                int p, f, xx = x;
	
	                for (int u=0; u<dvs[x].length; u++)
	                {
	                    p = dvs[x][u];
	                    if ((p>1) && (is_prime[p]))
	                    {
	                        f = x / p;
	
	                        for (j=0; j<K; j++)
	                        {
	                            cc ++;
	                            if (p * ans[j][f] < ans[j][x])
	                            {
	                                ans[j][x] = p * ans[j][f];
	                            }
	                        }
	                    }
	                }
	            }
	
	            Tree T = new Tree(0, K-1);
	
	            int t, l, r, _l, _r, li, ri, x;
	            long  m, f;
	
	            boolean[] is_same = new boolean[K];
	            int[] same_val = new int[K];
	            Arrays.fill(is_same, false);
	
	            for (int z=0; z<q; z++)
	            {
	                t = readInt();
	                l = readInt()-1;
	                r = readInt()-1;
	
	                if (t == 1)
	                {
	                    x = readInt();
	
	                    li = -1;
	                    ri = -1;
	                    for (i=0; i<K; i++)
	                    {
	                        if ((l <= L[i]) && (R[i] <= r))
	                        {
	                            if (li == -1)
	                            {
	                                li = i;
	                            }
	                            ri = i;
	
	                            is_same[i] = true;
	                            same_val[i] = x;
	                        }
	                        else if (((L[i] <= l) && (l <= R[i])) || ((L[i] <= r) && (r <= R[i])))
	                        {
	                            T.break_same(i);
	                            is_same[i] = false;
	
	                            if ((L[i] <= l) && (r <= R[i]))
	                            {
	                                _l = l;
	                                _r = r;
	                            }
	                            else if ((L[i] <= l) && (l <= R[i]))
	                            {
	                                _l = l;
	                                _r = R[i];
	                            }
	                            else
	                            {
	                                _l = L[i];
	                                _r = r;
	                            }
	
	                            for (j=_l; j<=_r; j++)
	                            {
	                                a[j] = x;
	                            }
	                        }
	                    }
	
	                    if (li > -1)
	                    {
	                        T.update(li, ri, x);
	                    }
	                }
	                else
	                {
	                    m = MM;
	                    li = -1;
	                    ri = -1;
	
	                    for (i=0; i<K; i++)
	                    {
	                        if ((l <= L[i]) && (R[i] <= r))
	                        {
	                            if (li == -1)
	                            {
	                                li = i;
	                            }
	                            ri = i;
	                        }
	                        else if (((L[i] <= l) && (l <= R[i])) || ((L[i] <= r) && (r <= R[i])))
	                        {
	                            if ((L[i] <= l) && (r <= R[i]))
	                            {
	                                _l = l;
	                                _r = r;
	                            }
	                            else if ((L[i] <= l) && (l <= R[i]))
	                            {
	                                _l = l;
	                                _r = R[i];
	                            }
	                            else
	                            {
	                                _l = L[i];
	                                _r = r;
	                            }
	
	                            for (j=_l; j<=_r; j++)
	                            {
	                                f = fff(is_same[i] ? same_val[i] : a[j], b[j]);
	                                if (f < m)
	                                {
	                                    m = f;
	                                }
	                            }
	                        }
	                    }
	
	                    if (li > -1)
	                    {
	                        m = Math.min(m, T.get_min(li, ri));
	                    }
	
	                    out.println(m);
	                }
	            }
	
	            return null;
	        }
	
	    }
	
	    public void run()
	    {
	        int t = multiply_test ? readInt() : 1;
	
	        this.init(t);
	
	        for (int i = 0; i < t; i++) {
	            TestCase T = new TestCase();
	            T.run(i + 1);
	        }
	    }
	
	    public void loc_params()
	    {
	        this.log_enabled = false;
	        this.multiply_test = true;
	    }
	
	    public void params(){
	        this.multiply_test = false;
	    }
	}

	public class id9 extends id1
	{
	    public class id10 extends id6
	    {
	
	    }
	}

	public  static  class Numth{
	
	    public static long gcd(long a, long b)
	    {
	        if (b == 0)
	        {
	            return a;
	        }
	
	        return gcd(b, a % b);
	    }
	
	    public static int gcd(int a, int b)
	    {
	        if (b == 0)
	        {
	            return a;
	        }
	
	        return gcd(b, a % b);
	    }
	
	}

	public class id1
	{
	    public boolean is_local = false;
	
	    public id1()
	    {
	
	    }
	
	    public class id6
	    {
	        public Object solve() {
	            return null;
	        }
	
	        public int caseNumber;
	
	        public id6() {
	
	        }
	
	        public void run(int cn){
	
	            this.caseNumber = cn;
	
	            Object r = this.solve();
	
	            if ((r != null))
	            {
	                out.println(r);
	            }
	        }
	
	    }
	
	    public String impossible(){
	        return "IMPOSSIBLE";
	    }
	
	    public String strf(String format, Object... args)
	    {
	        return String.format(format, args);
	    }
	
	    public BufferedReader in;
	    public PrintStream out;
	
	    public boolean log_enabled = false;
	
	    public boolean multiply_test = true;
	
	    public void params()
	    {
	
	    }
	
	    public void loc_params()
	    {
	
	    }
	
	
	    private StringTokenizer tokenizer = null;
	
	    public int readInt() {
	        return Integer.parseInt(readToken());
	    }
	
	    public long readLong() {
	        return Long.parseLong(readToken());
	    }
	
	    public double readDouble() {
	        return Double.parseDouble(readToken());
	    }
	
	    public String readLn() {
	        try {
	            String s;
	            while ((s = in.readLine()).length() == 0);
	            return s;
	        } catch (Exception e) {
	            return "";
	        }
	    }
	
	    public String readToken() {
	        try {
	            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	                tokenizer = new StringTokenizer(in.readLine());
	            }
	            return tokenizer.nextToken();
	        } catch (Exception e) {
	            return "";
	        }
	    }
	
	    public int[] id0(int n) {
	        int[] x = new int[n];
	        id0(x, n);
	        return x;
	    }
	
	    public void id0(int[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[i] = readInt();
	        }
	    }
	
	    public long[] id2(int n) {
	        long[] x = new long[n];
	        id2(x, n);
	        return x;
	    }
	
	    public void id2(long[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[i] = readLong();
	        }
	    }
	
	    public void id7(long[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[n-i-1] = readLong();
	        }
	    }
	
	    public void logWrite(String format, Object... args) {
	        if (!log_enabled) {
	            return;
	        }
	
	        out.printf(format, args);
	    }
	
	    public void id5(long[] x, int n) {
	
	        char[]buf = new char[1000000];
	        long r = -1;
	        int k= 0, l = 0;
	        long d;
	
	        while (true)
	        {
	            try{
	                l = in.read(buf, 0, 1000000);
	            }
	            catch(Exception E){};
	
	            for (int i=0; i<l; i++)
	            {
	                if (('0'<=buf[i])&&(buf[i]<='9'))
	                {
	                    if (r == -1)
	                    {
	                        r = 0;
	                    }
	                    d = buf[i] - '0';
	                    r = 10 * r + d;
	                }
	                else
	                {
	                    if (r != -1)
	                    {
	                        x[k++] = r;
	                    }
	
	                    r = -1;
	                }
	            }
	
	            if (l<1000000)
	                return;
	        }
	    }
	
	    public void id3(int[] x, int n) {
	
	        char[]buf = new char[1000000];
	        int r = -1;
	        int k= 0, l = 0;
	        int d;
	
	        while (true)
	        {
	            try{
	                l = in.read(buf, 0, 1000000);
	            }
	            catch(Exception E){};
	
	            for (int i=0; i<l; i++)
	            {
	                if (('0'<=buf[i])&&(buf[i]<='9'))
	                {
	                    if (r == -1)
	                    {
	                        r = 0;
	                    }
	                    d = buf[i] - '0';
	                    r = 10 * r + d;
	                }
	                else
	                {
	                    if (r != -1)
	                    {
	                        x[k++] = r;
	                    }
	
	                    r = -1;
	                }
	            }
	
	            if (l<1000000)
	                return;
	        }
	    }
	
	    public void printArray(long[] a, int n)
	    {
	        printArray(a, n, ' ');
	    }
	
	    public void printArray(int[] a, int n)
	    {
	        printArray(a, n, ' ');
	    }
	
	    public void printArray(long[] a, int n, char dl)
	    {
	        long x;
	        int i, l = 0;
	        for (i=0; i<n; i++)
	        {
	            x = a[i];
	
	            if (x<0)
	            {
	                x = -x;
	                l++;
	            }
	
	            if (x==0)
	            {
	                l++;
	            }
	            else
	            {
	                while (x>0)
	                {
	                    x /= 10;
	                    l++;
	                }
	            }
	        }
	
	        l += n-1;
	
	        char[] s = new char[l];
	
	        l--;
	        boolean z;
	        for (i=n-1; i>=0;  i--)
	        {
	            x = a[i];
	            z = false;
	            if (x<0)
	            {
	                x = -x;
	                z = true;
	            }
	
	            do{
	                s[l--] = (char)('0' + (x % 10));
	                x /= 10;
	            } while (x>0);
	
	            if (z)
	            {
	                s[l--] = '-';
	            }
	
	            if (i>0)
	            {
	                s[l--] = dl;
	            }
	        }
	
	        out.println(new String(s));
	    }
	
	    public void printArray(double[] a, int n, char dl)
	    {
	        long x;
	        double y;
	
	        int i, l = 0;
	        for (i=0; i<n; i++)
	        {
	            x = (long)a[i];
	
	            if (x<0)
	            {
	                x = -x;
	                l++;
	            }
	
	            if (x==0)
	            {
	                l++;
	            }
	            else
	            {
	                while (x>0)
	                {
	                    x /= 10;
	                    l++;
	                }
	            }
	        }
	
	        l += n-1 + 10*n;
	
	        char[] s = new char[l];
	
	        l--;
	        boolean z;
	        int j;
	        for (i=n-1; i>=0;  i--)
	        {
	            x = (long)a[i];
	            y = (long)(1000000000*(a[i]-x));
	
	            z = false;
	            if (x<0)
	            {
	                x = -x;
	                z = true;
	            }
	
	            for (j=0; j<9; j++)
	            {
	                s[l--] = (char)('0' + (y % 10));
	                y /= 10;
	            }
	
	            s[l--] = '.';
	
	            do{
	                s[l--] = (char)('0' + (x % 10));
	                x /= 10;
	            } while (x>0);
	
	            if (z)
	            {
	                s[l--] = '-';
	            }
	
	            if (i>0)
	            {
	                s[l--] = dl;
	            }
	        }
	
	        out.println(new String(s));
	    }
	
	    public void printArray(int[] a, int n, char dl)
	    {
	        int x;
	        int i, l = 0;
	        for (i=0; i<n; i++)
	        {
	            x = a[i];
	
	            if (x<0)
	            {
	                x = -x;
	                l++;
	            }
	
	            if (x==0)
	            {
	                l++;
	            }
	            else
	            {
	                while (x>0)
	                {
	                    x /= 10;
	                    l++;
	                }
	            }
	        }
	
	        l += n-1;
	
	        char[] s = new char[l];
	
	        l--;
	        boolean z;
	        for (i=n-1; i>=0;  i--)
	        {
	            x = a[i];
	            z = false;
	            if (x<0)
	            {
	                x = -x;
	                z = true;
	            }
	
	            do{
	                s[l--] = (char)('0' + (x % 10));
	                x /= 10;
	            } while (x>0);
	
	            if (z)
	            {
	                s[l--] = '-';
	            }
	
	            if (i>0)
	            {
	                s[l--] = dl;
	            }
	        }
	
	        out.println(new String(s));
	    }
	
	    public void printMatrix(int[][] a, int n, int m)
	    {
	        int x;
	        int i,j, l = 0;
	        for (i=0; i<n; i++)
	        {
	            for (j=0; j<m; j++)
	            {
	                x = a[i][j];
	
	                if (x<0)
	                {
	                    x = -x;
	                    l++;
	                }
	
	                if (x==0)
	                {
	                    l++;
	                }
	                else
	                {
	                    while (x>0)
	                    {
	                        x /= 10;
	                        l++;
	                    }
	                }
	            }
	
	            l += m-1;
	        }
	
	        l += n-1;
	
	
	        char[] s = new char[l];
	
	        l--;
	        boolean z;
	        for (i=n-1; i>=0;  i--)
	        {
	            for (j=m-1; j>=0;  j--)
	            {
	                x = a[i][j];
	                z = false;
	                if (x<0)
	                {
	                    x = -x;
	                    z = true;
	                }
	
	                do{
	                    s[l--] = (char)('0' + (x % 10));
	                    x /= 10;
	                } while (x>0);
	
	                if (z)
	                {
	                    s[l--] = '-';
	                }
	
	                if (j>0)
	                {
	                    s[l--] = ' ';
	                }
	            }
	
	            if (i>0)
	            {
	                 s[l--] = '\n';
	            }
	        }
	
	        out.println(new String(s));
	    }
	
	    public void printMatrix(long[][] a, int n, int m)
	    {
	        long x;
	        int i,j, l = 0;
	        for (i=0; i<n; i++)
	        {
	            for (j=0; j<m; j++)
	            {
	                x = a[i][j];
	
	                if (x<0)
	                {
	                    x = -x;
	                    l++;
	                }
	
	                if (x==0)
	                {
	                    l++;
	                }
	                else
	                {
	                    while (x>0)
	                    {
	                        x /= 10;
	                        l++;
	                    }
	                }
	            }
	
	            l += m-1;
	        }
	
	        l += n-1;
	
	
	        char[] s = new char[l];
	
	        l--;
	        boolean z;
	        for (i=n-1; i>=0;  i--)
	        {
	            for (j=m-1; j>=0;  j--)
	            {
	                x = a[i][j];
	                z = false;
	                if (x<0)
	                {
	                    x = -x;
	                    z = true;
	                }
	
	                do{
	                    s[l--] = (char)('0' + (x % 10));
	                    x /= 10;
	                } while (x>0);
	
	                if (z)
	                {
	                    s[l--] = '-';
	                }
	
	                if (j>0)
	                {
	                    s[l--] = ' ';
	                }
	            }
	
	            if (i>0)
	            {
	                 s[l--] = '\n';
	            }
	        }
	
	        out.println(new String(s));
	    }
	}


    public void run()
    {
        MainSolution S;
        try {
            S = new MainSolution();            
            S.in = new BufferedReader(new InputStreamReader(System.in));
            

            S.out = new PrintStream(new BufferedOutputStream( System.out ));
        } catch (Exception e) {
            return;
        }        
        S.params();
        S.run();
        S.out.flush();
    }

    public static void main(String args[]) {
        Locale.setDefault(Locale.US);
        
        Main M = new Main();
        M.run();
    }

}