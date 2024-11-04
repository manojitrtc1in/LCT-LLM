import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

	public class MainSolution extends id19 {
	
	    

	
	    public void init(int tests_count){}
	
	    public class TestCase extends id23
	    {
	        int N;
	        long[] prefS;
	
	
	        public Object solve()
	        {
	            N = readInt();
	            long s = readLong();
	
	            long[] a = id6(N);
	            prefS = new long[N+1];
	            int i;
	
	            prefS[0] = -a[0];
	            for (i=1; i<N; i++)
	            {
	                prefS[i] = prefS[i-1] - a[i];
	            }
	
	            MinMax M = new MinMax(N, prefS, 20, MinMax.MAX_ONLY);
	
	            long S = s;
	            int r;
	            int max = 0;
	            int ml=-1, mr=-1;
	
	            for (int l=0; l<N; l++)
	            {
	                if (l>0)
	                {
	                    S -= a[l-1];
	                }
	
	                r = M.id1(l, S);
	
	                if (r > max)
	                {
	                    ml = l+1;
	                    mr = l+r;
	                    max = r;
	                }
	            }
	
	            if (ml>-1)
	            {
	                return strf("%d %d", ml, mr);
	            }
	
	            return -1;
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
	    }
	
	    public void params(){
	        this.multiply_test = true;
	    }
	}

	public class id19 extends id5
	{
	    public class id23 extends id14
	    {
	
	    }
	}

	public class MinMax{
	
	    int N;
	    int K;
	    long[][] dmins;
	    long[][] id9;
	
	    public static final int MIN_ONLY = 1;
	    public static final int MAX_ONLY = 2;
	
	    public MinMax(int n, long[] A, int k)
	    {
	        this(n, A, k, 0);
	    }
	
	    public MinMax(int n, long[] A, int k, int type)
	    {
	        N = n;
	        K = k;
	
	        boolean min = type != MAX_ONLY;
	        boolean max = type != MIN_ONLY;
	
	        if (min) dmins = new long[N][K];
	        if (max) id9 = new long[N][K];
	
	        int i;
	        for (i=0; i<N; i++)
	        {
	            if (min) dmins[i][0] = A[i];
	            if (max) id9[i][0] = A[i];
	        }
	
	        int d = 1;
	        for (k = 1; k<K; k++)
	        {
	            for (i=0; i<N; i++)
	            {
	                if (min) dmins[i][k] = Math.min(dmins[i][k-1], dmins[i+d <N ? i+d : N-1 ][k-1]);
	                if (max) id9[i][k] = Math.max(id9[i][k-1], id9[i+d <N ? i+d : N-1 ][k-1]);
	            }
	            d *= 2;
	        }
	    }
	
	    public long get_min(int l, int r)
	    {
	        if (l==r)
	        {
	            return dmins[l][0];
	        }
	
	        int k=1;
	        int d=2;
	
	        while (l+2*d <= r)
	        {
	            k++;
	            d*=2;
	        }
	
	        return Math.min(dmins[l][k], dmins[r-d+1][k]);
	    }
	
	    public long get_max(int l, int r)
	    {
	        if (l==r)
	        {
	            return id9[l][0];
	        }
	
	        int k=1;
	        int d=2;
	
	        while (l+2*d <= r)
	        {
	            k++;
	            d*=2;
	        }
	
	        return Math.max(id9[l][k], id9[r-d+1][k]);
	    }
	
	    public int id12(int L, long X)
	    {
	        return this.id12(L, N-1, X);
	    }
	
	    public int id12(int L, int R, long X)
	    {
	        int r = id20(L, R, X);
	        return (r==-1) ? R : (r==L ? -1 :r-1);
	    }
	
	    public int id7(int L, long X)
	    {
	        return this.id7(L, N-1, X);
	    }
	
	    public int id7(int L, int R, long X)
	    {
	        int r = id12(L, R, X);
	        return (r==-1) ? 0 : r - L + 1;
	    }
	
	    public int id10(int L, long X)
	    {
	        return this.id10(L, N-1, X);
	    }
	
	    public int id10(int L, int R, long X)
	    {
	        int r = id21(L, R, X);
	        return (r==-1) ? R : (r==L ? -1 :r-1);
	    }
	
	    public int id1(int L, long X)
	    {
	        return this.id1(L, N-1, X);
	    }
	
	    public int id1(int L, int R, long X)
	    {
	        int r = id10(L, R, X);
	        return (r==-1) ? 0 : r - L + 1;
	    }
	
	    public int id18(int R, long X)
	    {
	        return this.id18(0, R, X);
	    }
	
	    public int id18(int L, int R, long X)
	    {
	        int r = id24(L, R, X);
	        return (r==-1) ? L : (r==R ? -1 :r+1);
	    }
	
	    public int id3(int L, long X)
	    {
	        return this.id3(L, N-1, X);
	    }
	
	    public int id3(int L, int R, long X)
	    {
	        int l = id18(L, R, X);
	        return (l==-1) ? 0 : R - l + 1;
	    }
	
	    public int id22(int R, long X)
	    {
	        return this.id22(0, R, X);
	    }
	
	    public int id22(int L, int R, long X)
	    {
	        int r = id16(L, R, X);
	        return (r==-1) ? L : (r==R ? -1 :r+1);
	    }
	
	    public int id2(int L, long X)
	    {
	        return this.id2(L, N-1, X);
	    }
	
	    public int id2(int L, int R, long X)
	    {
	        int l = id22(L, R, X);
	        return (l==-1) ? 0 : R - l + 1;
	    }
	
	    public int id21(int L, int R, long X)
	    {
	        if (get_max(L,R)<=X)
	        {
	            return -1;
	        }
	
	        int l = L;
	        int r = R;
	        int c;
	        long t;
	
	        while (l<r)
	        {
	            c = (l+r) / 2;
	            t = get_max(l, c);
	            if (t>X)
	            {
	                r = c;
	            }
	            else
	            {
	                l = c+1;
	            }
	        }
	
	        return l;
	    }
	
	    public int id20(int L, int R, long X)
	    {
	        if (get_min(L,R)>=X)
	        {
	            return -1;
	        }
	
	        int l = L;
	        int r = R;
	        int c;
	        long t;
	
	        while (l<r)
	        {
	            c = (l+r) / 2;
	            t = get_min(l, c);
	            if (t<X)
	            {
	                r = c;
	            }
	            else
	            {
	                l = c+1;
	            }
	        }
	
	        return l;
	    }
	
	    public int id16(int L, int R, long X)
	    {
	        if (get_max(L,R)<=X)
	        {
	            return -1;
	        }
	
	        int l = L;
	        int r = R;
	        int c;
	        long t;
	
	        while (l<r)
	        {
	            c = (l+r+1) / 2;
	            t = get_max(c, r);
	            if (t>X)
	            {
	                l = c;
	            }
	            else
	            {
	                r = c-1;
	            }
	        }
	
	        return r;
	    }
	
	    public int id24(int L, int R, long X)
	    {
	        if (get_min(L,R)>=X)
	        {
	            return -1;
	        }
	
	        int l = L;
	        int r = R;
	        int c;
	        long t;
	
	        while (l<r)
	        {
	            c = (l+r+1) / 2;
	            t = get_min(c, r);
	            if (t<X)
	            {
	                l = c;
	            }
	            else
	            {
	                r = c-1;
	            }
	        }
	
	        return r;
	    }
	
	    public int id11(int L, int R, long X)
	    {
	        return id21(L, R, X-1);
	    }
	
	    public int id4(int L, int R, long X)
	    {
	        return id20(L, R, X+1);
	    }
	
	    public int id15(int L, int R, long X)
	    {
	        return id16(L, R, X-1);
	    }
	
	    public int id17(int L, int R, long X)
	    {
	        return id24(L, R, X+1);
	    }
	
	    public int id21(int i, long X)
	    {
	        return id21(i, N-1, X);
	    }
	
	    public int id20(int i, long X)
	    {
	        return id20(i, N-1, X);
	    }
	
	    public int id16(int i, long X)
	    {
	        return id16(0, i,X);
	    }
	
	    public int id24(int i, long X)
	    {
	        return id24(0, i, X);
	    }
	
	    public int id11(int i, long X)
	    {
	        return id11(i, N-1, X);
	    }
	
	    public int id4(int i, long X)
	    {
	        return id4(i, N-1, X);
	    }
	
	    public int id15(int i, long X)
	    {
	        return id15(0, i, X);
	    }
	
	    public int id17(int i, long X)
	    {
	        return id17(0, i, X);
	    }
	
	}

	public class id5
	{
	    public boolean is_local = false;
	
	    public id5()
	    {
	
	    }
	
	    public class id14
	    {
	        public Object solve() {
	            return null;
	        }
	
	        public int caseNumber;
	
	        public id14() {
	
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
	
	    public long[] id6(int n) {
	        long[] x = new long[n];
	        id6(x, n);
	        return x;
	    }
	
	    public void id6(long[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[i] = readLong();
	        }
	    }
	
	    public void logWrite(String format, Object... args) {
	        if (!log_enabled) {
	            return;
	        }
	
	        out.printf(format, args);
	    }
	
	    public void id13(long[] x, int n) {
	
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
	
	    public void id8(int[] x, int n) {
	
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