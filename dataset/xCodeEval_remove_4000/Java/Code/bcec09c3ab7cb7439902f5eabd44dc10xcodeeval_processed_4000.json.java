
import java.io.*;
import java.util.*;

public class Main {

    static class CP {

        static boolean isPrime(long n) {
            if (n <= 1)
                return false;
            if (n == 2 || n == 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        }

        static int id1(int prime[], int x) {

            return (prime[x / 64] & (1 << ((x >> 1) & 31)));
        }

        static void makeComposite(int prime[], int x) {

            prime[x / 64] |= (1 << ((x >> 1) & 31));
        }

        static ArrayList<Integer> id9(int n) {
            ArrayList<Integer> al = new ArrayList<Integer>();
            int prime[] = new int[n / 64 + 1];


            for (int i = 3; i * i <= n; i += 2) {

                if (id1(prime, i) == 0)
                    for (int j = i * i, k = i << 1;
                         j < n; j += k)
                        makeComposite(prime, j);
            }

            al.add(2);

            for (int i = 3; i <= n; i += 2)
                if (id1(prime, i) == 0)
                    al.add(i);

            return al;
        }

        static List<Integer> sieve(long size) {
            ArrayList<Integer> pr = new ArrayList<Integer>();
            boolean prime[] = new boolean[(int) size];
            for (int i = 2; i < prime.length; i++) prime[i] = true;
            for (int i = 2; i * i < prime.length; i++) {
                if (prime[i]) {
                    for (int j = i * i; j < prime.length; j += i) {
                        prime[j] = false;
                    }
                }
            }
            for (int i = 2; i < prime.length; i++) if (prime[i]) pr.add(i);
            return pr;
        }

        static long id3(long a, long b) {
            long res = 1;
            while (b != 0) {
                if ((b & 1) == 1) {
                    res *= a;
                    --b;
                }
                a *= a;
                b /= 2;
            }
            return res;
        }

        static long id0(long a, long b) {
            long res = 1;
            while (b != 0) {
                if ((b & 1) == 1) {
                    res = (res * a) % 1000000007;
                    --b;
                }
                a = (a * a) % 1000000007;
                b /= 2;
            }
            return res;
        }

        static int id7(int a, int b) {
            while (true) {
                if (b == 0)
                    return a;
                int c = a;
                a = b;
                b = c % b;
            }
        }

        static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        static long ceil_div(long a, long b) {
            return (a + b - 1) / b;
        }

        static int id12(int bits, int i) {
            return (bits >> (i - 1)) & 1;
        }

        static long id6(long a[], long x) {
            long l = -1, r = a.length;
            while (l + 1 < r) {
                long m = (l + r) >>> 1;
                if (a[(int) m] <= x)
                    l = m;
                else
                    r = m;
            }
            return l + 1;
        }

        static int id6(List<Integer> a, int x) {
            int l = -1, r = a.size();
            while (l + 1 < r) {
                int m = (l + r) >>> 1;
                if (a.get(m) <= x)
                    l = m;
                else
                    r = m;
            }
            return l + 1;
        }

        static int id13(int a[], int x) {
            int l = -1, r = a.length;
            while (l + 1 < r) {
                int m = (l + r) >>> 1;
                if (a[(int) m] >= x)
                    r = m;
                else
                    l = m;
            }
            return r;
        }

        static long bsh(long a[], long t) {
            long ans = 0;
            int i = 0, j = a.length - 1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (a[mid] == t) {
                    ans = a[mid];
                    break;
                } else if (a[mid] > t) {
                    ans = a[mid];
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
            return ans;
        }

        static long bsl(long a[], long t) {
            long ans = 0;
            int i = 0, j = a.length - 1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (a[mid] == t) {
                    ans = a[mid];
                    break;
                } else if (a[mid] > t) {
                    j = mid - 1;
                } else {
                    ans = a[mid];
                    i = mid + 1;
                }
            }
            return ans;
        }














































        static int id13(List<Integer> a, int x)  

        {
            int l = -1, r = a.size();
            while (l + 1 < r) {
                int m = (l + r) >>> 1;
                if (a.get(m) >= x)
                    r = m;
                else
                    l = m;
            }
            return r;
        }

        static boolean id15(int x, int factor, int target) {
            int s = (int) Math.round(Math.sqrt(x));
            return factor * s * s == target;
        }

        static boolean isSquare(int x) {
            int s = (int) Math.round(Math.sqrt(x));
            return x * x == s;
        }

        static void sort(int a[]) 

        {
            PriorityQueue<Integer> q = new PriorityQueue<>();
            for (int i = 0; i < a.length; i++)
                q.add(a[i]);
            for (int i = 0; i < a.length; i++)
                a[i] = q.poll();
        }

        static void shuffle(int[] in) {
            for (int i = 0; i < in.length; i++) {
                int idx = (int) (Math.random() * in.length);
                fast_swap(in, idx, i);
            }
        }

        static int[] id10(String pat) {
            int len = 0, i = 1, m = pat.length();
            int lps[] = new int[m];
            lps[0] = 0;
            while (i < m) {
                if (pat.charAt(i) == pat.charAt(len)) {
                    ++len;
                    lps[i] = len;
                    ++i;
                } else {
                    if (len != 0) {
                        len = lps[len - 1];
                    } else {
                        lps[i] = len;
                        ++i;
                    }
                }
            }
            return lps;
        }

        static void kmp(String s, String pat) {
            int n = s.length(), m = pat.length();
            int lps[] = id10(pat);
            int i = 0, j = 0;
            while (i < n) {
                if (s.charAt(i) == pat.charAt(j)) {
                    i++;
                    j++;

                } else {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
        }

        static void id8(int a[]) {
            shuffle(a);
            Arrays.sort(a);
            for (int l = 0, r = a.length - 1; l < r; ++l, --r)
                fast_swap(a, l, r);

        }

        static void id2(int a[]) {
            shuffle(a);
            Arrays.sort(a);
        }

        static int getMax(int arr[], int n) {
            int mx = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                    mx = arr[i];
            return mx;
        }

        static ArrayList<Long> primeFactors(long n) {
            ArrayList<Long> al = new ArrayList<>();
            while (n % 2 == 0) {
                al.add(2L);
                n /= 2L;
            }

            for (int i = 3; (long) i * i <= n; i += 2) {
                while ((n % i == 0)) {
                    al.add((long) i);
                    n /= i;
                }
            }

            if (n > 2) {
                al.add(n);
            }
            return al;
        }

        static int[] z_function(String s) {
            int n = s.length(), z[] = new int[n];

            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r)
                    z[i] = Math.min(z[i - l], r - i + 1);

                while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
                    ++z[i];

                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
            return z;
        }

        static void swap(int a[], int idx1, int idx2) {
            a[idx1] += a[idx2];
            a[idx2] = a[idx1] - a[idx2];
            a[idx1] -= a[idx2];
        }

        static void fast_swap(int[] a, int idx1, int idx2) {
            if (a[idx1] == a[idx2])
                return;

            a[idx1] ^= a[idx2];
            a[idx2] ^= a[idx1];
            a[idx1] ^= a[idx2];
        }

    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                

                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    

                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long[] id4(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }
    }

    static String addChar(String s, int n, String ch) {
        String result =String.join("", Collections.nCopies(n, ch))+s;
        return result;
    }

    static long sum(int[] arr) {
        long s = 0;
        for (int i = 0; i < arr.length; i++) {
            s += arr[i];
        }
        return s;
    }

    static void printArr(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
























































    private static void mul(long[][] a, long[][] b, int dim)
    {
        long res[][]=new long[dim+1][dim+1];

        for(int i=1;i<=dim;i++)
        {
            for(int j=1;j<=dim;j++)
            {
                res[i][j]=0;
                for(int k=1;k<=dim;++k)
                {
                    long num=(a[i][k]*b[k][j])%mod;
                    res[i][j]=(res[i][j]+num)%mod;
                }
            }
        }
        for(int i=1;i<=dim;i++)
        {
            for(int j=1;j<=dim;j++)
            {
                a[i][j]=res[i][j];
            }
        }
    }

    static void py() {
        System.out.println("YES");
    }

    static void pn() {
        System.out.println("NO");
    }

    static class id5 {
        int parent[], rank[];

        public id5(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        public void union(int a, int b) {
            int x = find(a);
            int y = find(b);
            if (x == y) {
                return;
            }
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else if (rank[y] < rank[x]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    static class Pair {
        int x,y;

        public Pair(int x,int y) {
            this.x=x;
            this.y=y;
        }
    }
    static int mod=1000000007;


























































    


    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner();
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            long sum=0;
            int arr[]=new int[n];
            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextInt();
                sum+=arr[i];
            }
            long req=2*sum/n;
            if((sum*(n-2))!=(sum-req)*n)
            {
                System.out.println(0);
            }
            else
            {
                System.out.println(id11(n,req,arr));
            }
        }
    }

    static long id11(int n, long sum,int arr[])
    {
        HashMap<Integer, Integer> hm = new HashMap<>();

        for (int i = 0; i < n; i++) {

            if (!hm.containsKey(arr[i]))
                hm.put(arr[i], 0);

            hm.put(arr[i], hm.get(arr[i]) + 1);
        }
        long id14 = 0;


        for (int i = 0; i < n; i++) {
            if (hm.get((int)sum - arr[i]) != null)
                id14 += hm.get((int)sum - arr[i]);


            if (sum - arr[i] == arr[i])
                id14--;
        }

        return id14 / 2;
    }

}




