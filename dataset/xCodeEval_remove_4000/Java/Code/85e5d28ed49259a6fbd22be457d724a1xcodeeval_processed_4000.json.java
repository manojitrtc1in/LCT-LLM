import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

	public class MainSolution extends id4 {
	
	    

	
	    public void init(int tests_count){}
	
	    public class TestCase extends id6
	    {
	
	        public Object solve()
	        {
	            int n = readInt(), m = readInt();
	            String s;
	
	            int[] I2 = new int[100];
	            int[] p2 = new int[100];
	            Arrays.fill(I2, 0);
	
	            int[] I3 = new int[1000];
	            int[] p3 = new int[1000];
	            Arrays.fill(I3, 0);
	
	            int i, j, d;
	            for (i=0; i<n; i++)
	            {
	                s = readLn();
	
	                if (m==1) continue;
	
	                d = s.charAt(0)-'0';
	                for (j=1; j<m; j++)
	                {
	                    d = 10 * (d % 10);
	                    d += s.charAt(j)-'0';
	
	                    if (I2[d] == 0)
	                    {
	                        I2[d] = i+1;
	                        p2[d] = j;
	                    }
	                }
	
	                if (m==2) continue;
	
	                d = 10*(s.charAt(0)-'0') + s.charAt(1)-'0';
	                for (j=2; j<m; j++)
	                {
	                    d = 10 * (d % 100);
	                    d += s.charAt(j)-'0';
	
	                    if (I3[d] == 0)
	                    {
	                        I3[d] = i+1;
	                        p3[d] = j-1;
	                    }
	                }
	            }
	
	
	            s = readLn();
	
	            if (m==1)
	            {
	                return -1;
	            }
	
	            int[] T = new int[m+1];
	            int[] idx = new int[m+1];
	            int[] K = new int[m];
	            T[m-1] = 0;
	            T[m] = 0;
	
	
	            d = 10*(s.charAt(m-2)-'0') + s.charAt(m-1) - '0';
	
	            if (I2[d]>0)
	            {
	                T[m-2] = 2;
	                idx[m-2] = d;
	                K[m-2] = 1;
	            }
	            else
	            {
	                T[m-2] = 0;
	            }
	
	            if (m==2)
	            {
	                if (T[0]==0)
	                {
	                    return -1;
	                }
	
	                out.println(1);
	                out.printf("%d %d %d\n", p2[idx[0]], p2[idx[0]]+1, I2[idx[0]]);
	
	                return null;
	            }
	
	            d = 100*(s.charAt(m-3)-'0') + 10*(s.charAt(m-2)-'0') + s.charAt(m-1) - '0';
	            if (I3[d]>0)
	            {
	                T[m-3] = 3;
	                idx[m-3] = d;
	                K[m-3] = 1;
	            }
	            else
	            {
	                T[m-3] = 0;
	            }
	
	            for (i=m-4; i>=0; i--)
	            {
	                T[i] = 0;
	
	                d = 10*(s.charAt(i)-'0') + s.charAt(i+1) - '0';
	                if ((I2[d]>0) && (T[i+2]>0))
	                {
	                    T[i] = 2;
	                    idx[i] = d;
	                    K[i] = 1 + K[i+2];
	                }
	
	                d = 100*(s.charAt(i)-'0') + 10*(s.charAt(i+1) - '0') + (s.charAt(i+2) - '0');
	                if ((I3[d]>0) && (T[i+3]>0))
	                {
	                    T[i] = 3;
	                    idx[i] = d;
	                    K[i] = 1 + K[i+3];
	                }
	            }
	
	            if (T[0] == 0)
	            {
	                return -1;
	            }
	
	
	            out.println(K[0]);
	
	            int[] ans = new int[K[0] *3];
	            i = 0;
	            int b = 0;
	            while (i<m)
	            {
	                if (T[i]==2)
	                {
	                    ans[b++] = (p2[idx[i]]);
	                    ans[b++] = (p2[idx[i]]+1 );
	                    ans[b++] = (I2[idx[i]]);
	
	
	                    i+= 2;
	                }
	                else
	                {
	                    ans[b++] = (p3[idx[i]]);
	                    ans[b++] = (p3[idx[i]]+2);
	                    ans[b++] = (I3[idx[i]]);
	
	                    i+= 3;
	                }
	            }
	
	            id2(ans, 3*K[0]);
	            return null;
	        }
	
	    }
	
	    public void id2(int[] a, int n)
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
	                s[l--] = i % 3 == 0 ? '\n' : ' ';
	            }
	        }
	
	        out.println(new String(s));
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

	public class id4 extends id0
	{
	    public class id6 extends id8
	    {
	
	    }
	}

	public class id0
	{
	    public boolean is_local = false;
	
	    public id0()
	    {
	
	    }
	
	    public class id8
	    {
	        public Object solve() {
	            return null;
	        }
	
	        public int caseNumber;
	
	        public id8() {
	
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
	
	    public int[] id1(int n) {
	        int[] x = new int[n];
	        id1(x, n);
	        return x;
	    }
	
	    public void id1(int[] x, int n) {
	        for (int i = 0; i < n; i++) {
	            x[i] = readInt();
	        }
	    }
	
	    public long[] id3(int n) {
	        long[] x = new long[n];
	        id3(x, n);
	        return x;
	    }
	
	    public void id3(long[] x, int n) {
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
	
	    public void id7(long[] x, int n) {
	
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
	
	    public void id5(int[] x, int n) {
	
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
            S.out = System.out;            
        } catch (Exception e) {
            return;
        }        
        S.params();
        S.run();
    }

    public static void main(String args[]) {
        Locale.setDefault(Locale.US);
        
        Main M = new Main();
        M.run();
    }

}