import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.System.*;
import static java.lang.System.out;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Arrays.sort;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;
import static java.util.stream.IntStream.*;

public class Solution {
    private final static FastScanner scanner = new FastScanner();
    private final static int mod = (int) 1e9+7;
    private final static int max_value = Integer.MAX_VALUE;
    private final static int min_value = Integer.MIN_VALUE;
    private final static String endl = "\n";

    private static void solve() {
        int n = ii(), m = ii();
        if (m<n) yes();
        else no();
        while (m-->0) {
            int x = ii(), y = ii();
        }
    }


    public static void main(String[] args) {
        int t = ii();
        while (t-->0) solve();
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static void swap(int[] a, int[] b, int i) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

    private static int f(int x) {
        String a = x+"";
        return a.length();
    }

    private static void iota(int[] a, int x) {
        for (int i = 0; i<a.length; i++) a[i] = x++;
    }

    private static void reverse(int[] a) {
        int[] b = new int[a.length];
        int k = 0;
        for (int i = a.length-1; i>=0; i--) {
            b[k++] = a[i];
        }
        System.arraycopy(b, 0, a, 0, b.length);
    }

    private static long[] ral(int n) {
        long[] a = new long[n];
        for (int i = 0; i<n; i++) {
            a[i] = ii();
        }
        return a;
    }

    private static int[] rai(int n) {
        return scanner.readArray(n);
    }

    private static String[] ras(int n) {
        return range(0, n).mapToObj(i -> s()).toArray(String[]::new);
    }

    private static int lcm (int a, int b) {
        return a / gcd (a, b) * b;
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    private static int ii() {
        return scanner.nextInt();
    }

    private static long l() {
        return scanner.nextLong();
    }

    private static double d() {
        return scanner.nextDouble();
    }

    private static String s() {
        return scanner.next();
    }

    private static int toInt(String s) {
        return Integer.parseInt(s);
    }

    private static ArrayList<Integer> list() {
        return new ArrayList<>();
    }

    private static HashSet<Integer> set() {
        return new HashSet<>();
    }

    private static HashMap<Integer, Integer> map() {
        return new HashMap<>();
    }

    private static int toInt(char c) {
        return Integer.parseInt(c+"");
    }

    private static<K> void pl(K a) {
        p(a+endl);
    }

    private static<K> void p(K a) {
        out.print(a);
    }

    private static void yes() {
        pl("YES");
    }

    private static void no() {
        pl("NO");
    }

    private static int max_a(int[] a) {
        int max = a[0];
        for (int j : a) {
            if (j > max) {
                max = j;
            }
        }
        return max;
    }

    private static int min_a(int[] a) {
        int min = a[0];
        for (int j : a) {
            if (j < min) {
                min = j;
            }
        }
        return min;
    }

    private static long sum(int[] a) {
        return stream(a).asLongStream().sum();
    }

    private static void pl() {
        out.println();
    }

    private static void printArray(long[] a) {
        StringBuilder builder = new StringBuilder();
        for (long i : a)
            builder.append(i).append(' ');
        pl(builder);
    }

    private static void printArray(int[] a) {
        StringBuilder builder = new StringBuilder();
        for (int i : a)
            builder.append(i).append(' ');
        pl(builder);
    }

    private static<K> void printArray(K[] a) {
        StringBuilder builder = new StringBuilder();
        for (K i : a)
            builder.append(i).append(' ');
        pl(builder);
    }

    private static int reverseInteger(int k) {
        String a = k+"", res = "";
        for (int i = a.length()-1; i>=0; i--) {
            res+=a.charAt(i);
        }
        return toInt(res);
    }

    private static int  phi(int n) {
        int  result = n;
        for (int i=2; i*i<=n; i++)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        if (n > 1)
            result -= result / n;
        return result;
    }

    private static int pow(int a, int n) {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return pow(a, n-1) * a;
        else {
            int b = pow (a, n/2);
            return b * b;
        }
    }
    private static boolean id1(long n) {
        BigInteger a = BigInteger.valueOf(n);
        return a.isProbablePrime(10);
    }

    private static boolean isPrime(long n) {
        return iterate(2, i -> i * i <= n, i -> i + 1).noneMatch(i -> n % i == 0);
    }

    private static List<Integer> primes(int N) {
        int[] lp = new int[N+1];
        List<Integer> pr = new ArrayList<>();
        for (int i=2; i<=N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.add(i);
            }
            for (int j = 0; j<pr.size() && pr.get(j)<=lp[i] && i*pr.get(j)<=N; ++j)
                lp[i * pr.get(j)] = pr.get(j);
        }
        return pr;
    }

    private static Set<Integer> toSet(int[] a) {
        return stream(a).boxed().collect(Collectors.toSet());
    }

    private static int linearSearch(int[] a, int key) {
        return range(0, a.length).filter(i -> a[i] == key).findFirst().orElse(-1);
    }

    private static<K> int linearSearch(K[] a, K key) {
        return range(0, a.length).filter(i -> a[i].equals(key)).findFirst().orElse(-1);
    }

    static int upper_bound(int[] arr, int key) {
        int index = binarySearch(arr, key);
        int n = arr.length;
        if (index < 0) {
            int upperBound = abs(index) - 1;
            if (upperBound < n)
                return upperBound;
            else return -1;
        }
        else {
            while (index < n) {
                if (arr[index] == key)
                    index++;
                else {
                    return index;
                }
            }
            return -1;
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    private static void stableSort(int[] a) {
        List<Integer> list = stream(a).boxed().sorted().toList();
        setAll(a, list::get);
    }

    private static void psort(int[] arr, int n) {
        int min = min_a(arr);
        int max = max_a(arr);
        int range = max-min+1, i, j, index = 0;
        int[] count = new int[range];
        for(i = 0; i<n; i++)
            count[arr[i] - min]++;
        for(j = 0; j<range; j++)
            while(count[j]-->0)
                arr[index++]=j+min;
    }

    private static void csort(int[] a, int n) {
        int max = max_a(a);
        int min = min_a(a);
        int range = max - min + 1;
        int[] count = new int[range];
        int[] output = new int[n];
        for (int i = 0; i < n; i++) {
            count[a[i] - min]++;
        }
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[a[i] - min] - 1] = a[i];
            count[a[i] - min]--;
        }
        arraycopy(output, 0, a, 0, n);
    }

    private static void csort(char[] arr) {
        int n = arr.length;
        char[] output = new char[n];
        int[] count = new int[256];
        for (int i = 0; i < 256; ++i)
            count[i] = 0;
        for (char c : arr) ++count[c];
        for (int i = 1; i <= 255; ++i)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            --count[arr[i]];
        }
        arraycopy(output, 0, arr, 0, n);
    }
    static class id2 {
        int[] st;

        int minVal(int x, int y) {
            return min(x, y);
        }

        int getMid(int s, int e) {
            return s + (e - s) / 2;
        }
        int id4(int ss, int se, int qs, int qe, int index) {
            if (qs <= ss && qe >= se)
                return st[index];
            if (se < qs || ss > qe)
                return Integer.MAX_VALUE;
            int mid = getMid(ss, se);
            return minVal(id4(ss, mid, qs, qe, 2 * index + 1),
                    id4(mid + 1, se, qs, qe, 2 * index + 2));
        }

        int RMQ(int n, int qs, int qe) {
            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }

            return id4(0, n - 1, qs, qe, 0);
        }

        int id0(int[] arr, int ss, int se, int si) {
            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }
            int mid = getMid(ss, se);
            st[si] = minVal(id0(arr, ss, mid, si * 2 + 1),
                    id0(arr, mid + 1, se, si * 2 + 2));
            return st[si];
        }

        void constructST(int[] arr, int n) {
            int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
            int max_size = 2 * (int) Math.pow(2, x) - 1;
            st = new int[max_size]; 

            id0(arr, 0, n - 1, 0);
        }
    }

    



    static class SegmentTree
    {
        int[] st; 


        
        SegmentTree(int[] arr, int n)
        {
            

            

            int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));

            

            int max_size = 2 * (int) Math.pow(2, x) - 1;

            st = new int[max_size]; 


            id0(arr, 0, n - 1, 0);
        }

        

        int getMid(int s, int e) {
            return s + (e - s) / 2;
        }

        
        int id5(int ss, int se, int qs, int qe, int si)
        {
            

            

            if (qs <= ss && qe >= se)
                return st[si];

            

            if (se < qs || ss > qe)
                return 0;

            

            int mid = getMid(ss, se);
            return id5(ss, mid, qs, qe, 2 * si + 1) +
                    id5(mid + 1, se, qs, qe, 2 * si + 2);
        }

        
        void id3(int ss, int se, int i, int diff, int si)
        {
            

            

            if (i < ss || i > se)
                return;

            

            

            st[si] = st[si] + diff;
            if (se != ss) {
                int mid = getMid(ss, se);
                id3(ss, mid, i, diff, 2 * si + 1);
                id3(mid + 1, se, i, diff, 2 * si + 2);
            }
        }

        



        void updateValue(int arr[], int n, int i, int new_val)
        {
            

            if (i < 0 || i > n - 1) {
                System.out.println("Invalid Input");
                return;
            }

            

            int diff = new_val - arr[i];

            

            arr[i] = new_val;

            

            id3(0, n - 1, i, diff, 0);
        }

        



        int getSum(int n, int qs, int qe)
        {
            

            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }
            return id5(0, n - 1, qs, qe, 0);
        }

        

        

        int id0(int arr[], int ss, int se, int si)
        {
            

            

            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }

            

            

            int mid = getMid(ss, se);
            st[si] = id0(arr, ss, mid, si * 2 + 1) +
                    id0(arr, mid + 1, se, si * 2 + 2);
            return st[si];
        }
    }
}