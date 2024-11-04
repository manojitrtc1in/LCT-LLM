import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.text.DecimalFormat;

public class gziputil {
    

    public static void main(String args[]) {
        InputReader in = new InputReader(System.in);
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        int t = in .nextInt();
        while (t-- > 0) {
            int n = in .nextInt();
            int m = in .nextInt();
            char arr[][] = new char[n][m];
            boolean flag = true;
            if (n % 2 != 0 && m % 2 != 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        {
                            if (flag)
                                arr[i][j] = 'B';
                            else
                                arr[i][j] = 'W';
                        }
                        flag = !flag;
                    }
                }
            } 
            else if ((n % 2 == 0 && m % 2 != 0) || (m == 1) || (n == 1)) {
            flag = true;
            for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        {
                        if (i == n - 1 && j == m - 1) {
                            arr[i][j] = 'B';
                        }
                          else {  if (flag)
                                arr[i][j] = 'B';
                            else
                                arr[i][j] = 'W';
                                }
                        }
                        flag = !flag;
                    }
                }            
            }
            
            else if (n % 2 != 0 && m % 2 == 0) {
            flag = true;
            for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        {
                        if (i == n - 1 && j == m - 2) {
                            arr[i][j] = 'B';
                        }
                         else {   if (flag)
                                arr[i][j] = 'W';
                            else
                                arr[i][j] = 'B';
                                }
                        }
                        flag = !flag;
                    }
                } 
                }
                
            else if (n % 2 == 0 && m % 2 == 0){
            flag = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == n - 1 && j == m - 2) {
                            arr[i][j] = 'B';
                        } else {
                            if (flag)
                                arr[i][j] = 'W';
                            else
                                arr[i][j] = 'B';
                        }
                        flag = !flag;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.print(arr[i][j]);
                }
                out.println();
            }
        }
        out.close();
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    static int floorSearch(int arr[], int low, int high, int x) {
        int ans = -1;
        while (low < high) {
            

            if (x >= arr[high])
                return high;
            int mid = (low) + (high - low) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    void findFactors(int[] id5, int[] multiplicity, int id0, long currentResult) {
        if (id0 == id5.length) {
            

            System.out.println(currentResult);
            return;
        }
        

        

        for (int i = 0; i <= multiplicity[id0]; ++i) {
            findFactors(id5, multiplicity, id0 + 1, currentResult);
            currentResult *= id5[id0];
        }
    }
    static int ceilSearch(long arr[], int low, int high, long x) {

        int mid;

        
        if (x <= arr[low])
            return low;

        
        if (x > arr[high])
            return -1;

        
        mid = (low + high) / 2; 

        
        if (arr[mid] == x)
            return mid;

        
        else if (arr[mid] < x) {
            if (mid + 1 <= high && x <= arr[mid + 1])
                return mid + 1;
            else
                return ceilSearch(arr, mid + 1, high, x);
        }

        
        else {
            if (mid - 1 >= low && x > arr[mid - 1])
                return mid;
            else
                return ceilSearch(arr, low, mid - 1, x);
        }
    }
    public static long id4(long n, long r) {
        long result = 1;
        System.out.println(factorial(29));
        result = factorial(n) / (factorial(r) * factorial(n - r));

        return result;
    }
    public static long factorial(long n) {
        long c;
        long result = 1;

        for (c = 1; c <= n; c++)
            result = result * c;

        return result;
    }
    

    

    

    

    

    

    

    

    

    public static void id2(String pat, int M, int lps[]) {
        

        int len = 0;
        int i = 1;
        lps[0] = 0; 


        

        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else 

            {
                

                

                

                if (len != 0) {
                    len = lps[len - 1];

                    

                    

                } else 

                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
    public static void id8(String pat, String txt) {
        System.out.println("sdfsdf");
        int M = pat.length();
        int N = txt.length();

        

        

        int lps[] = new int[M];
        int j = 0; 


        

        

        id2(pat, M, lps);
        int i = 0; 

        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                j++;
                i++;
            }
            if (j == M) {
                System.out.println("Found pattern " +
                    "at index " + (i - j));
                j = lps[j - 1];
            }

            

            else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                

                

                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }
    

    

    

    

    

    

    

    

    

    

    public static long gcd(long p, long q) {
        if (q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }
    static int mid = -1;
    static int find(int arr[], int k, int f, int l) {
        if (f > l)
            return mid;
        mid = (f + l) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] < k) {
            f = mid;
            return find(arr, k, f, l);
        } else {
            l = mid;
            return find(arr, k, f, l);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    


    public static int id1(int[] segmentTree, int qlow, int qhigh, int len) {
        return id1(segmentTree, 0, len - 1, qlow, qhigh, 0);
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    public static int id1(int segmentTree[], int low, int high, int qlow, int qhigh, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return 0;
        }
        int mid = (low + high) / 2;
        return id1(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1) +
            id1(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2);
    }
    static void merge(long arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        
        long L[] = new long[n1];
        long R[] = new long[n2];

        
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        
        i = 0; 

        j = 0; 

        k = l; 

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    
    static void mergeSort(long arr[], int l, int r) {
        if (l < r) {
            

            

            int m = l + (r - l) / 2;

            

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    private static int[] id3(InputReader in , int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in .nextInt();
        return a;
    }
    public static double dis(double x1, double x2, double y1) {
        return Math.sqrt(((x1 - x2) * (x1 - x2)) + (y1 * y1));
    }
    private static String[] id6(InputReader in , int n) {
        String[] a = new String[n];
        for (int i = 0; i < n; i++)
            a[i] = in .next();
        return a;
    }
    private static void show(int[] a) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
    private static void id7(char[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++)
                System.out.print(a[i][j]);
            System.out.println();
        }
    }
    static long fact(long x) {
        long i = x, mul = 1;
        while (i > 0) {
            mul = (mul % 1000000007) * (i % 1000000007) % 1000000007;
            i--;
        }
        return mul;
    }
    static class LengthComparator implements Comparator < String > {
        public int compare(String arg0, String arg1) {
            

            return (arg0 + arg1).compareTo(arg1 + arg0);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    static long func(boolean v[], int j, ArrayList < Integer > h[], long ban[]) {
        v[j] = true;
        int k;
        long sum = 0;
        sum = sum + ban[j];
        

        for (k = 0; k < h[j].size(); k++) {
            if (v[h[j].get(k)] == false) {
                v[h[j].get(k)] = true;
                sum += func(v, h[j].get(k), h, ban);
            }
        }
        return sum;
    }
    
    static int root(int arr[], int i) {
        while (arr[i] != i) {
            i = arr[i];
        }
        return i;
    }
    static boolean find(int arr[], int a, int b) {
        if (root(arr, a) == root(arr, b)) {
            return true;
        } else
            return false;
    }
    static void weighted_union(int arr[], int size[], int a, int b) {
        int root_a = root(arr, a);
        int root_b = root(arr, b);
        if (root_a != root_b) {
            if (size[root_a] < size[root_b]) {
                arr[root_a] = arr[root_b];
                size[root_b] += size[root_a];
            } else {
                arr[root_b] = arr[root_a];
                size[root_a] += size[root_b];
            }
            

        }
    }
    static class Pair implements Comparable < Pair > {
        private long first;
        private long index;
        


        public Pair(long i, long j) {
            this.first = i;
            this.index = j;
        }
        public Pair() {
            

        }
        public long getFirst() {
            return first;
        }
        

        public long getIndex() {
            return index;
        }
        public void setFirst(long k) {
            this.first = k;
        }
        public void setIndex(long k) {
            this.index = k;
        }
        

        @Override
        public int compareTo(Pair o) {
            return Long.compare(this.first, o.first);
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream inputstream) {
            reader = new BufferedReader(new InputStreamReader(inputstream));
            tokenizer = null;
        }

        public String nextLine() {
            String fullLine = null;
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    fullLine = reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                return fullLine;
            }
            return fullLine;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}