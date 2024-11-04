import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

	public class MainSolution extends MainSolutionT {
	
	    

	
	    public void init(int tests_count){}
	
	    public class TestCase extends TestCaseT
	    {
	        int n, m;
	        int[][] Mx;
	        int[][] My;
	
	        int[][] P;
	        int[][] C;
	        int[][] T;
	
	        int[][] stack;
	        int stackSize;
	
	        public void walk(int X, int Y, int c)
	        {
	            int x = X;
	            int y = Y;
	
	            int x1, y1;
	            int k = 0;
	
	            stackSize = 0;
	
	            while (true)
	            {
	                C[x][y] = c;
	                T[x][y] = k++;
	
	                x1 = x + Mx[x][y];
	                y1 = y + My[x][y];
	
	                if ((x1<0)||(y1<0)||(x1>=n)||(y1>=m))
	                {
	                    walk_back_1(x,y,X,Y,1);
	                    return;
	                }
	
	                if (C[x1][y1]==c)
	                {
	                    int cycle_size = T[x][y] - T[x1][y1]+1;
	
	                    walk_back_2(x,y,x1,y1,cycle_size);
	                    walk_back_1(x1,y1,X,Y, cycle_size);
	                    return;
	                }
	
	                if (C[x1][y1]!=-1)
	                {
	                    walk_back_1(x,y,X,Y,P[x1][y1]+1);
	                    return;
	                }
	
	
	                stack[stackSize][0] = x;
	                stack[stackSize][1] = y;
	                stackSize ++;
	
	                x = x1;
	                y = y1;
	
	
	            }
	        }
	
	        public void walk_back_1(int x,int y, int X, int Y, int k)
	        {
	            int x1, y1;
	            while (true)
	            {
	                P[x][y] = k++;
	
	                if (stackSize==0)
	                {
	                    return;
	                }
	
	                stackSize--;
	                x1 = stack[stackSize][0];
	                y1 = stack[stackSize][1];
	
	                x = x1;
	                y = y1;
	            }
	        }
	
	        public void walk_back_2(int x,int y, int X, int Y, int k)
	        {
	            int x1, y1;
	            while (true)
	            {
	                if ((x==X)&&(y==Y))
	                {
	                    return;
	                }
	
	                P[x][y] = k;
	
	                stackSize--;
	                x1 = stack[stackSize][0];
	                y1 = stack[stackSize][1];
	
	                x = x1;
	                y = y1;
	            }
	        }
	
	        public Object solve()
	        {
	            n = readInt();
	            m = readInt();
	
	
	            Mx = new int[n][m];
	            My = new int[n][m];
	
	            int i,j;
	            for (i=0; i<n; i++)
	                Arrays.fill(Mx[i], 0);
	            for (i=0; i<n; i++)
	                Arrays.fill(My[i], 0);
	
	            String s;
	
	            for (i=0; i<n; i++)
	            {
	                s = readLn();
	                for (j=0; j<m; j++)
	                {
	                    switch (s.charAt(j))
	                    {
	                        case 'L':
	                            My[i][j]--;
	                            break;
	                        case 'R':
	                            My[i][j]++;
	                            break;
	                        case 'U':
	                            Mx[i][j]--;
	                            break;
	                        case 'D':
	                            Mx[i][j]++;
	                            break;
	                    }
	                }
	            }
	
	            P = new int[n][m];
	            for (i=0; i<n; i++)
	                Arrays.fill(P[i], -1);
	
	            C = new int[n][m];
	            for (i=0; i<n; i++)
	                Arrays.fill(C[i], -1);
	
	            T = new int[n][m];
	            for (i=0; i<n; i++)
	                Arrays.fill(T[i], -1);
	
	            stack = new int[n*m][2];
	
	            int c= 1;
	            for (i=0; i<n; i++)
	            {
	                for (j=0; j<m; j++)
	                {
	                    if (C[i][j]==-1)
	                    {
	                        walk(i, j, c++);
	                    }
	                }
	            }
	
	            int maxx = 0;
	            int maxy = 0;
	
	
	
	            for (i=0; i<n; i++)
	            {
	                for (j=0; j<m; j++)
	                {
	                    if (P[i][j] > P[maxx][maxy])
	                    {
	                        maxx = i;
	                        maxy = j;
	                    }
	                }
	            }
	
	            return strf("%d %d %d", maxx+1, maxy+1, P[maxx][maxy]);
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
	
	    public void readLongArrayRev(long[] x, int n) {
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