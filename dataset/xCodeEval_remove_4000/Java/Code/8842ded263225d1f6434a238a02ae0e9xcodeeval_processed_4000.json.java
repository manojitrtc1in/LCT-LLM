


import java.io.*;
import java.lang.Math;
import java.util.*;

public class Main  {

    public BufferedReader in;
    public PrintStream out;

    public boolean log_enabled = false;
    
    public boolean multiply_tests = false;

    public static boolean id5 = false;
    
    public void gen_test() {
     
        
        
    }
    
    
    private class TestCase {

        int N;
        int r_count = 0;
        
        public int[] X;

        public void gen_X()
        {
            X = new int[N];
            
            int i;
            for (i=0; i<N; i++)
            {
                X[i] = i;
            }
            
            int c, a1, a2;
            
            for (i=0; i<N; i++)
            {
                a1 = i;
                a2 = rand(N);
                
                c = X[a1];
                X[a1] = X[a2];
                X[a2] = c;
            }
        }
        
        public String bit(int x)
        {
            char[] b = new char[11];
            for (int i=10; i>=0; i--)
            {
                b[i] = x % 2 > 0 ? '1' : '0';
                x /= 2;
            }
            return new String(b);
        }
        
        public int request(int a, int b)
        {
            r_count ++;
            out.printf("? %d %d\n", a+1, b+1);
            int x = readInt();
            return x;
           

        }
        
        public Object solve() {
            







            N = readInt();
            
            int MX = 2;
            while (MX<N)
            {
                MX *= 2;
            }
            MX = MX-1;
            
            
            

            
           

            
            int q[] = new int[N];
            int qn = 0;
            
            int[] isq = new int[N];
            Arrays.fill(isq, 0);
            int qi = 0;
            
            int a, b, x, mask;
            while (true) 
            {
                a = rand(N);
                b = rand(N);
                
                if (a != b)
                {
                    x = request(a, b);
                    if (x < MX)
                    {
                        qi = 1;
                        isq[a] = 1;
                        isq[b] = 1;
                        q[0] = a;
                        q[1] = b;
                        qn = 2;
                        mask = x;
                        break;
                    }
                }
            }
            
            

            

            
            int ex_count = 0;
            
            boolean[] excluded = new boolean[N];
            Arrays.fill(excluded, false);
            
            int i, j;
            while (ex_count < N-2)
            {
                for (i=0; i<N; i++)
                {
                    if (excluded[i] )
                    {
                        continue;
                    }

                    do{
                        a = q[rand(qn)];
                    } while (a == i);
                    
                    x = request(a, i);

                    


                    if ((x | mask ) > mask)
                    {
                        

                        excluded[i] = true;
                        ex_count ++;
                        
                        continue;
                    }

                    if (x == mask)
                    {
                        if (isq[i] == qi)
                        {
                            continue;
                        }
                        
                        

                        q[qn++] = i;
                        isq[i] = qi;
                    }

                    if (x < mask)
                    {
                        qi ++;
                        isq[a] = qi;
                        isq[i] = qi;
                        q[0] = a;
                        q[1] = i;
                        qn = 2;
                        mask = x;

                        

                    }
                }
            }
            
            a = -1;
            b = -1;
            
            for (i=0; i<N; i++)
            {
                if (!excluded[i])
                {
                    if (a==-1)
                    {
                        a = i;
                    }
                    else if (b == -1)
                    {
                        b = i;
                        break;
                    }
                }
            }
            
            int c, d, z, y;
            
            if (N<16)
            {
                do {
                    c= rand(N);

                    if ((c==a)||(c==b))
                    {
                        continue;
                    }

                    x = request(a, c);
                    y = request(b, c);
                    
                    if ((x & mask) == 0)
                    {
                        z = a;
                        break;
                    }
                    
                    if ((y & mask) == 0)
                    {
                        z = b;
                        break;
                    }
                    
                } while (true);
            }
            else
            {
                do {
                    c= rand(N);
                    d= rand(N);

                    if ((c==d)||(c==a)||(c==b)||(d==a)||(d==b))
                    {
                        continue;
                    }

                    x = request(c, d);
                } while ((x & mask) != 0);

                x = request(a, c);
                if ((x & mask) == 0)
                {
                    z = a;
                }
                else
                {
                    z = b;
                }
            }
            
            
          

          
          int[] R = new int[N];
          for (i=0; i<N; i++)
          {
              if (i==z)
              {
                  R[i] = 0;
              }
              else
              {
                  R[i] =  request(i,z);
              }
          }
          
          out.print("! ");
            printArray(R, N);
          System.out.flush();
            
            


















            
            return null;
            
            

            
            

            

        }
        
        public int caseNumber;
        
        public Random rand;
        
        TestCase(int number) {
            caseNumber = number;
            rand = new Random();
        }
        
        public int rand(int n)
        {
            return rand.nextInt(n);
        }
        
        public void run(){
            Object r = this.solve();
            
            if ((r != null))
            {
                

                out.println(r);
            }
        }
        
        public String impossible(){
            return "IMPOSSIBLE";
        }
        
        public String strf(String format, Object... args)
        {
            return String.format(format, args);
        }
        


















    }

    public void run() {
        

        {
            int t = multiply_tests ?  readInt() : 1;
            for (int i = 0; i < t; i++) {
                TestCase T = new TestCase(i + 1);
                T.run();
            }
        }
    }
    
    public static String id4 = "E:/java/codeforces/new/CodeForcesApp/src/solutions/r649d2/E/";
    
    public Main(BufferedReader _in, PrintStream _out){
        in = _in;
        out = _out;
    }
    

    public static void main(String args[]) {
        Locale.setDefault(Locale.US);
        Main S;
        try {
            S = new Main(
                        new BufferedReader(new InputStreamReader(System.in)),
                        System.out
                );
        } catch (Exception e) {
            return;
        }
        
        S.run();
        
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
    
    public int[] id2(int n) {
        int[] x = new int[n];
        id2(x, n);
        return x;
    }

    public void id0(int[] x, int n) {
        for (int i = 0; i < n; i++) {
            x[i] = readInt();
        }
    }
    
    public long[] id1(int n) {
        long[] x = new long[n];
        id1(x, n);
        return x;
    }
    
    public long[] id3(int n) {
        long[] x = new long[n];
        id3(x, n);
        return x;
    }

    public void id1(long[] x, int n) {
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
    
    public void id3(long[] x, int n) {
        
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
    
    public void id2(int[] x, int n) {
        
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
