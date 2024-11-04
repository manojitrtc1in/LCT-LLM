import java.io.*;
import java.util.*;
import java.lang.*;

public class codeforces {
   public static void main(String[] args) {
      InputStream inputStream = System.in;
      OutputStream outputStream = System.out;
      if (System.getProperty("ONLINE_JUDGE") == null) {
         long startTime = System.currentTimeMillis();
         try {
            sc = new InputReader(new FileInputStream("input.txt"));
            out = new PrintWriter(new FileOutputStream("output.txt"));
            pr = new PrintWriter(new FileOutputStream("error.txt"));
         } catch (Exception ignored) {
         }
         int t = 1;
         int tt = t;
         t = sc.nextInt();
         while (t-- > 0) {
            solve();
         }
         long endTime = System.currentTimeMillis();
         System.out.println("Time: " + (endTime - startTime) / tt + " ms");
         out.flush();
         pr.flush();

      } else {
         sc = new InputReader(inputStream);
         out = new PrintWriter(outputStream);
         pr = new PrintWriter(outputStream);
         int t = 1;
         t = sc.nextInt();
         while (t-- > 0) {
            solve();
         }
         out.flush();
      }
   }

   public static void solve() {
      long n=sc.nextLong();
      long a=sc.nextLong();
      long b=sc.nextLong();
      long p=1;
      while(p<=n){
         if((n-p)%b==0){
            out.println("Yes");
            return;
         }
         p*=a;
         if(a==1)break;
      }
      out.println("No");
   }

   

   

   

   

   

   

   


   

   

   

   


   


   public static int inf = Integer.MAX_VALUE;
   public static int minf = Integer.MIN_VALUE;
   public static int mod = 1000000007;
   public static int ml = (int) 1e9;
   public static InputReader sc;
   public static PrintWriter out;
   public static PrintWriter pr;

   


   static class Pair {
      int first, second;

      Pair(int x, int y) {
         this.first = x;
         this.second = y;
      }
   }

   


   static class InputReader {
      public BufferedReader reader;
      public StringTokenizer tokenizer;

      public InputReader(InputStream stream) {
         reader = new BufferedReader(new InputStreamReader(stream), 32768);
         tokenizer = null;
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

      public int nextInt() {
         return Integer.parseInt(next());
      }

      public long nextLong() {
         return Long.parseLong(next());
      }

      public double nextDouble() {
         return Double.parseDouble(next());
      }
   }

   

   public static void fill(int[][] dp, int x) {
      for (int i = 0; i < dp.length; ++i) {
         for (int j = 0; j < dp[0].length; ++j) {
            dp[i][j] = x;
         }
      }
   }

   public static int gcd(int a, int b) {
      if (a == 0)
         return b;
      return gcd(b % a, a);
   }

   public static int lcm(int a, int b) {
      return (a / gcd(a, b)) * b;
   }

   public static long gcd(long a, long b) {
      if (a == 0)
         return b;
      return gcd(b % a, a);
   }

   public static long lcm(long a, long b) {
      return (a / gcd(a, b)) * b;
   }

   public static int countDigits(int l) {
      if (l >= 1000000000)
         return 10;
      if (l >= 100000000)
         return 9;
      if (l >= 10000000)
         return 8;
      if (l >= 1000000)
         return 7;
      if (l >= 100000)
         return 6;
      if (l >= 10000)
         return 5;
      if (l >= 1000)
         return 4;
      if (l >= 100)
         return 3;
      if (l >= 10)
         return 2;
      return 1;
   }

   public static int countDigits(long l) {
      if (l >= 1000000000000000000L)
         return 19;
      if (l >= 100000000000000000L)
         return 18;
      if (l >= 10000000000000000L)
         return 17;
      if (l >= 1000000000000000L)
         return 16;
      if (l >= 100000000000000L)
         return 15;
      if (l >= 10000000000000L)
         return 14;
      if (l >= 1000000000000L)
         return 13;
      if (l >= 100000000000L)
         return 12;
      if (l >= 10000000000L)
         return 11;
      if (l >= 1000000000L)
         return 10;
      if (l >= 100000000L)
         return 9;
      if (l >= 10000000L)
         return 8;
      if (l >= 1000000L)
         return 7;
      if (l >= 100000L)
         return 6;
      if (l >= 10000L)
         return 5;
      if (l >= 1000L)
         return 4;
      if (l >= 100L)
         return 3;
      if (l >= 10L)
         return 2;
      return 1;
   }

   public static long nCr(int n, int k) {
      long ans = 1L;
      k = k > n - k ? n - k : k;
      int j = 1;
      for (; j <= k; j++, n--) {
         if (n % j == 0) {
            ans *= n / j;
         } else if (ans % j == 0) {
            ans = ans / j * n;
         } else {
            ans = (ans * n) / j;
         }
      }
      return ans;
   }

   public static String reverseString(String input) {
      StringBuilder str = new StringBuilder("");

      for (int i = input.length() - 1; i >= 0; i--) {
         str.append(input.charAt(i));
      }
      return str.toString();
   }

   public static int maxOf3(int x, int y, int z) {
      return Math.max(x, Math.max(y, z));
   }

   public static int minof3(int x, int y, int z) {
      return Math.min(x, Math.min(y, z));
   }

   public static long maxOf3(long x, long y, long z) {
      return Math.max(x, Math.max(y, z));
   }

   public static long minof3(long x, long y, long z) {
      return Math.min(x, Math.min(y, z));
   }

   public static void arrInput(int[] arr, int n) {
      for (int i = 0; i < n; i++)
         arr[i] = sc.nextInt();
   }

   public static void arrInput(long[] arr, int n) {
      for (int i = 0; i < n; i++)
         arr[i] = sc.nextLong();
   }

   public static void arrInput(Pair[] pair, int n) {
      for (int i = 0; i < n; i++)
         pair[i] = new Pair(sc.nextInt(), sc.nextInt());
   }

   public static int maxarrInput(int[] arr, int n) {
      int max = minf;
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextInt();
         max = Math.max(max, arr[i]);
      }
      return max;

   }

   public static long maxarrInput(long[] arr, int n) {
      long max = minf;
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextLong();
         max = Math.max(max, arr[i]);
      }
      return max;
   }

   public static int minarrInput(int[] arr, int n) {
      int min = inf;
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextInt();
         min = Math.max(min, arr[i]);
      }
      return min;
   }

   public static long minarrInput(long[] arr, int n) {
      long min = inf;
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextLong();
         min = Math.max(min, arr[i]);
      }
      return min;
   }

   public static long sumofarr(int[] arr) {
      long sum = 0;
      for (int i : arr)
         sum += i;
      return sum;
   }

   public static long sumofarr(long[] arr) {
      long sum = 0;
      for (long i : arr)
         sum += i;
      return sum;
   }

   public static int lowerBound(int[] arr, int x) {
      int l = -1, r = arr.length;
      while (l + 1 < r) {
         int m = (l + r) >>> 1;
         if (arr[m] >= x)
            r = m;
         else
            l = m;
      }
      return r;
   }

   public static int upperBound(int[] arr, int x) {
      int l = -1, r = arr.length;
      while (l + 1 < r) {
         int m = (l + r) >>> 1;
         if (arr[m] <= x)
            l = m;
         else
            r = m;
      }
      return l + 1;
   }

   public static long maxofarr(long[] arr) {
      long max = 0;
      for (long i : arr)
         max = Math.max(i, max);
      return max;
   }

   public static long minofarr(long[] arr) {
      long min = Integer.MAX_VALUE;
      for (long i : arr)
         min = Math.min(min, i);
      return min;
   }

   public static int maxofarr(int[] arr) {
      int max = 0;
      for (int i : arr)
         max = Math.max(i, max);
      return max;
   }

   public static int minofarr(int[] arr) {
      int min = Integer.MAX_VALUE;
      for (int i : arr)
         min = Math.min(min, i);
      return min;
   }

   public static void merge(int arr[], int l, int m, int r) {
      int n1 = m - l + 1;
      int n2 = r - m;
      int L[] = new int[n1];
      int R[] = new int[n2];
      for (int i = 0; i < n1; ++i)
         L[i] = arr[l + i];
      for (int j = 0; j < n2; ++j)
         R[j] = arr[m + 1 + j];
      int i = 0, j = 0;
      int k = l;
      while (i < n1 && j < n2) {
         if (L[i] >= R[j]) {
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

   public static void reversesort(int arr[], int l, int r) {
      if (l < r) {
         int m = l + (r - l) / 2;
         reversesort(arr, l, m);
         reversesort(arr, m + 1, r);
         merge(arr, l, m, r);
      }
   }

   public static void merge(long arr[], int l, int m, int r) {
      int n1 = m - l + 1;
      int n2 = r - m;
      long L[] = new long[n1];
      long R[] = new long[n2];
      for (int i = 0; i < n1; ++i)
         L[i] = arr[l + i];
      for (int j = 0; j < n2; ++j)
         R[j] = arr[m + 1 + j];
      int i = 0, j = 0;
      int k = l;
      while (i < n1 && j < n2) {
         if (L[i] >= R[j]) {
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

   public static void reversesort(long arr[], int l, int r) {
      if (l < r) {
         int m = l + (r - l) / 2;
         reversesort(arr, l, m);
         reversesort(arr, m + 1, r);
         merge(arr, l, m, r);
      }
   }

   


   public static boolean sysFlag = System.getProperty("ONLINE_JUDGE") == null;

   public static void debug(int[][] dp) {
      if (sysFlag) {
         for (int i = 0; i < dp.length; ++i) {
            pr.print(i + "--> ");
            for (int j = 0; j < dp[0].length; ++j) {
               pr.print(dp[i][j] + " ");
            }
            pr.println("");
         }
      }
   }

   public static void debug(long[][] dp) {
      if (sysFlag) {
         for (int i = 0; i < dp.length; ++i) {
            pr.print(i + "--> ");
            for (int j = 0; j < dp[0].length; ++j) {
               pr.print(dp[i][j] + " ");
            }
            pr.println("");
         }
      }
   }

   public static void debug(int x) {
      if (sysFlag)
         pr.println("Int-Ele: " + x);
   }

   public static void debug(String x) {
      if (sysFlag)
         pr.println("String: " + x);
   }

   public static void debug(char x) {
      if (sysFlag)
         pr.println("Char: " + x);
   }

   public static void debug(long x) {
      if (sysFlag)
         pr.println("Long-Ele: " + x);
   }

   public static void debug(int[] arr) {
      if (sysFlag) {
         for (int i = 0; i < arr.length; ++i) {
            pr.println(i + " -> " + arr[i]);
         }
      }
   }

   public static void debug(int[] arr, int n) {
      if (sysFlag) {
         for (int i = 0; i < n; ++i) {
            pr.println(i + " -> " + arr[i]);
         }
      }
   }

   public static void debug(long[] arr) {
      if (sysFlag) {
         for (int i = 0; i < arr.length; ++i) {
            pr.println(i + " -> " + arr[i]);
         }
      }
   }

   public static void debug(ArrayList<Integer> list) {
      if (sysFlag) {
         for (int i = 0; i < list.size(); ++i) {
            pr.println(i + " -> " + list.get(i));
         }
      }
   }

   public static void Ldebug(ArrayList<Long> list) {
      if (sysFlag) {
         for (int i = 0; i < list.size(); ++i) {
            pr.println(i + " -> " + list.get(i));
         }
      }
   }

   public static void debugmapII(HashMap<Integer, Integer> map) {
      if (sysFlag) {
         for (Map.Entry<Integer, Integer> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapLI(HashMap<Long, Integer> map) {
      if (sysFlag) {
         for (Map.Entry<Long, Integer> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapLL(HashMap<Long, Long> map) {
      if (sysFlag) {
         for (Map.Entry<Long, Long> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapIL(HashMap<Integer, Long> map) {
      if (sysFlag) {
         for (Map.Entry<Integer, Long> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapSL(HashMap<String, Long> map) {
      if (sysFlag) {
         for (Map.Entry<String, Long> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapCL(HashMap<Character, Long> map) {
      if (sysFlag) {
         for (Map.Entry<Character, Long> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapSI(HashMap<String, Integer> map) {
      if (sysFlag) {
         for (Map.Entry<String, Integer> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debugmapCI(HashMap<Character, Integer> map) {
      if (sysFlag) {
         for (Map.Entry<Character, Integer> entry : map.entrySet())
            pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
      }
   }

   public static void debug(Set<Integer> set) {
      if (sysFlag) {
         Iterator value = set.iterator();
         int i = 1;
         while (value.hasNext()) {
            pr.println((i++) + "-> " + value.next());
         }
      }
   }
}
