import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

	public class MainSolution extends MainSolutionT {
	
	    

	
	    public void init(int tests_count){}
	
	    public class TestCase extends TestCaseT
	    {
	        int N;
	        long[] prefS;
	
	
	        public Object solve()
	        {
	            N = readInt();
	            long s = readLong();
	
	            long[] a = readLongArray(N);
	            prefS = new long[N+1];
	            int i;
	
	            prefS[0] = a[0];
	            for (i=1; i<N; i++)
	            {
	                prefS[i] = prefS[i-1] + a[i];
	            }
	
	            MinMax M = new MinMax(N, prefS, 20, MinMax.MIN_ONLY);
	
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
	
	                r = M.rightMaxIntervalNotLessX(l, -S);
	
	                if (r-l+1 > max)
	                {
	                    ml = l+1;
	                    mr = r+1;
	                    max = r-l+1;
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

	public class MainSolutionT extends MainSolutionBase
	{
	    public class TestCaseT extends TestCaseBase
	    {
	
	    }
	}

	public class MinMax{
	
	    int N;
	    int K;
	    long[][] dmins;
	    long[][] dmaxs;
	
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
	        if (max) dmaxs = new long[N][K];
	
	        int i;
	        for (i=0; i<N; i++)
	        {
	            if (min) dmins[i][0] = A[i];
	            if (max) dmaxs[i][0] = A[i];
	        }
	
	        int d = 1;
	        for (k = 1; k<K; k++)
	        {
	            for (i=0; i<N; i++)
	            {
	                if (min) dmins[i][k] = Math.min(dmins[i][k-1], dmins[i+d <N ? i+d : N-1 ][k-1]);
	                if (max) dmaxs[i][k] = Math.max(dmaxs[i][k-1], dmaxs[i+d <N ? i+d : N-1 ][k-1]);
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
	            return dmaxs[l][0];
	        }
	
	        int k=1;
	        int d=2;
	
	        while (l+2*d <= r)
	        {
	            k++;
	            d*=2;
	        }
	
	        return Math.max(dmaxs[l][k], dmaxs[r-d+1][k]);
	    }
	
	    public int rightMaxIntervalNotLessX(int L, long X)
	    {
	        return this.rightMaxIntervalNotLessX(L, N-1, X);
	    }
	
	    public int rightMaxIntervalNotLessX(int L, int R, long X)
	    {
	        if (get_min(L, L) < X)
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
	            t = get_min(l, c);
	            if (t<X)
	            {
	                r = c-1;
	            }
	            else
	            {
	                l = c;
	            }
	        }
	
	        return r;
	    }
	
	    public int righttMaxIntervalNotGreaterX(int L, long X)
	    {
	        return this.righttMaxIntervalNotGreaterX(L, N-1, X);
	    }
	
	    public int righttMaxIntervalNotGreaterX(int L, int R, long X)
	    {
	        if (get_max(L, L) > X)
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
	            t = get_max(l, c);
	            if (t>X)
	            {
	                r = c-1;
	            }
	            else
	            {
	                l = c;
	            }
	        }
	
	        return r;
	    }
	
	    public int leftMaxIntervalNotLessX(int R, long X)
	    {
	        return this.leftMaxIntervalNotLessX(0, R, X);
	    }
	
	    public int leftMaxIntervalNotLessX(int L, int R, long X)
	    {
	        if (get_min(R, R) < X)
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
	            t = get_min(c, r);
	            if (t<X)
	            {
	                l = c+1;
	            }
	            else
	            {
	                r = c;
	            }
	        }
	
	        return r;
	    }
	
	    public int leftMaxIntervalNotGreaterX(int R, long X)
	    {
	        return this.leftMaxIntervalNotGreaterX(0, R, X);
	    }
	
	    public int leftMaxIntervalNotGreaterX(int L, int R, long X)
	    {
	        if (get_max(R, R) > X)
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
	            t = get_max(c, r);
	            if (t>X)
	            {
	                l = c+1;
	            }
	            else
	            {
	                r = c;
	            }
	        }
	
	        return r;
	    }
	
	}

	public class MainSolutionBase
	{
	    public boolean is_local = false;
	
	    public MainSolutionBase()
	    {
	
	    }
	
	    public class TestCaseBase
	    {
	        public Object solve() {
	            return null;
	        }
	
	        public int caseNumber;
	
	        public TestCaseBase() {
	
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
	
	    public int[] readIntArray(int n) {
	        int[] x = new int[n];
	        readIntArray(x, n);
	        return x;
	    }
	
	    public void readIntArray(int[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[i] = readInt();
	        }
	    }
	
	    public long[] readLongArray(int n) {
	        long[] x = new long[n];
	        readLongArray(x, n);
	        return x;
	    }
	
	    public void readLongArray(long[] x, int n) {
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
	
	    public void readLongArrayBuf(long[] x, int n) {
	
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
	
	    public void readIntArrayBuf(int[] x, int n) {
	
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