import java.io.*;
import java.util.*;

public class cf {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
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
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        float nextFloat() {
            return Float.parseFloat(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        void readArr(int[] ar, int n) {
            for (int i = 0; i < n; i++) {
                ar[i] = nextInt();
            }
        }
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static boolean binary_search(long[] a, long k) {
        long low = 0;
        long high = a.length - 1;
        long mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid] == k) {
                return true;
            } else if (a[(int) mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    public static int id6(long[] a, int low, int high) {
        int mid = low + ((high - low) / 2);
        int hight = high;
        int lowt = low;
        while (lowt < hight) {
            mid = lowt + (hight - lowt) / 2;
            if (a[high] - a[mid] <= 5) {
                hight = mid;
            } else {
                lowt = mid + 1;
            }
        }
        return lowt;
    }

    public static long lowerbound(long a[], long ddp) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            

            

            

            if (a[(int) mid] <= ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        

        

        

        if (low == a.length && low != 0) {
            low--;
            return low;
        }
        if (a[(int) low] > ddp && low != 0) {
            low--;
        }
        return low;
    }

    public static long lowerbound(long a[], long ddp, long factor) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if ((a[(int) mid] + (mid * factor)) == ddp) {
                return mid;
            }
            if ((a[(int) mid] + (mid * factor)) < ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        

        

        

        if (low == a.length && low != 0) {
            low--;
            return low;
        }
        if (a[(int) low] > ddp - (low * factor) && low != 0) {
            low--;
        }
        return low;
    }

    public static long lowerbound(List<Long> a, long ddp) {
        long low = 0;
        long high = a.size();
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            

            

            

            if (a.get((int) mid) < ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        

        

        

        

        

        

        

        

        

        

        return low;
    }

    public static long id10(pair a[], double pr) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid].w <= pr) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        

        

        

        

        

        

        

        

        

        

        return low;
    }

    public static long upperbound(long a[], long ddp) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid] <= ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == a.length) {
            return a.length - 1;
        }
        return low;
    }

    public static long upperbound(ArrayList<Long> a, long ddp) {
        long low = 0;
        long high = a.size();
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a.get((int) mid) <= ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == a.size()) {
            return a.size() - 1;
        }
        

        if (low + 1 < a.size() && a.get((int) low) <= ddp) {
            low++;
        }
        return low;
    }

    

    

    


    

    

    

    


    

    

    

    

    

    

    


    public static class pairs {
        char w;
        int h;

        public pairs(char w, int h) {
            this.w = w;
            this.h = h;
        }
    }

    public static class pair {
        long w;
        long h;

        public pair(long w, long h) {
            this.w = w;
            this.h = h;
        }

        @Override
        public int hashCode() {
            return Objects.hash(w, h);
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) {
                return true;
            }
            if (!(o instanceof pair)) {
                return false;
            }
            pair c = (pair) o;
            return Long.compare(this.w, c.w) == 0 && Long.compare(this.h, h) == 0;
        }
    }

    public static class trinary {
        long a;
        long b;
        long c;

        public trinary(long a, long b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    public static pair[] sortpair(pair[] a) {
        Arrays.sort(a, new Comparator<pair>() {
            public int compare(pair p1, pair p2) {
                if (p1.w != p2.w) {
                    return (int) (p1.w - p2.w);
                }
                return (int) (p1.h - p2.h);
            }
        });
        return a;
    }

    public static trinary[] sortpair(trinary[] a) {
        Arrays.sort(a, new Comparator<trinary>() {
            public int compare(trinary p1, trinary p2) {
                if (p1.b != p2.b) {
                    return (int) (p1.b - p2.b);
                } else if (p1.c != p2.c) {
                    return (int) (p1.c - p2.c);
                }
                return (int) (p1.a - p2.a);
            }
        });
        return a;
    }

    public static void sort(long[] arr) {
        ArrayList<Long> a = new ArrayList<>();
        for (long i : arr) {
            a.add(i);
        }
        Collections.sort(a);
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a.get(i);
        }
    }

    public static void id0(pair[] arr) {
        ArrayList<pair> a = new ArrayList<>();
        for (pair i : arr) {
            a.add(i);
        }
        Collections.sort(a, new Comparator<pair>() {
            @Override
            public int compare(pair a, pair b) {

                return (int) (a.h - b.h);
            }
        });
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a.get(i);
        }
    }

    public static boolean id7(String s) {
        long i = 0;
        long j = s.length() - 1;
        boolean is = false;
        while (i < j) {
            if (s.charAt((int) i) == s.charAt((int) j)) {
                is = true;
                i++;
                j--;
            } else {
                is = false;
                return is;
            }
        }
        return is;
    }

    public static long power(long base, long pow, long mod) {
        long result = base;
        long temp = 1;
        while (pow > 1) {
            if (pow % 2 == 0) {
                result = ((result % mod) * (result % mod)) % mod;
                pow /= 2;
            } else {
                temp = temp * base;
                pow--;
            }
        }
        result = ((result % mod) * (temp % mod));
        

        return result;
    }

    public static long sqrt(long n) {
        long res = 1;
        long l = 1, r = (long) 10e9;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (mid * mid <= n) {
                res = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }

    public static boolean is[] = new boolean[1000000];
    public static int a[] = new int[1000000];

    public static Vector<Integer> id5() {
        Vector<Integer> listA = new Vector<>();
        for (int i = 2; i * i <= a.length; i++) {
            if (a[i] != 1) {
                for (long j = i * i; j < a.length; j += i) {
                    a[(int) j] = 1;
                }
            }
        }
        for (int i = 2; i < a.length; i++) {
            if (a[i] == 0) {
                is[i] = true;
                listA.add(i);
            }
        }
        return listA;
    }

    public static Vector<Integer> ans = id5();

    public static long id1(long n) {
        long ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    public static long id11(long a[]) {
        long t = a[0];
        for (int i = 1; i < a.length; i++) {
            t = gcd(t, a[i]);
        }
        return t;
    }

    public static ArrayList<Long> al = new ArrayList<>();

    public static void makeArr() {
        long t = 1;
        while (t <= 10e17) {
            al.add(t);
            t *= 2;
        }
    }

    public static boolean id8(String s) {
        if (s.length() == 1) {
            return false;
        }
        Stack<Character> sO = new Stack<>();
        int id = 0;
        while (id < s.length()) {
            if (s.charAt(id) == '(') {
                sO.add('(');
            }
            if (s.charAt(id) == ')') {
                if (!sO.isEmpty()) {
                    sO.pop();
                } else {
                    return false;
                }
            }
            id++;
        }
        if (sO.isEmpty()) {
            return true;
        }
        return false;
    }

    public static long id9(long a[], int start, int end) {
        long id3 = Long.MIN_VALUE;
        long id4 = 0;
        for (int i = start; i < end; i++) {
            id4 += a[i];
            if (id3 < id4) {
                id3 = id4;
            }
            if (id4 < 0) {
                id4 = 0;
            }
        }
        return id3;
    }

    public static Vector<Integer> prime = new Vector<>();

    public static int components = 0;

    public static void search(HashMap<Integer, Integer> hm, int max, int start, int high) {
        if (start == 0) {
            components++;
            return;
        }
        int t = max;
        boolean is = false;
        for (int i = start; i < high; i++) {
            if (hm.get(t) >= start) {
                t--;
                is = true;
            } else {
                

                is = false;
                break;
            }
        }
        

        if (is) {
            search(hm, t, hm.get(t), start);
            components++;
        } else {
            

            search(hm, max, hm.get(t), high);
        }
    }

    public static void helper(String s, Stack<Character> left, Stack<Character> right) {
        int id = 0;
        while (id < s.length()) {
            if (s.charAt(id) == '(') {
                left.add('(');
            }
            if (s.charAt(id) == ')') {
                right.add(')');
                if (left.size() > 0) {
                    left.pop();
                    right.pop();
                }
            }
            id++;
        }
    }

    public static long id2(long n, int fac, long m) {
        long max = (long) 10e9;
        long min = 0;
        long mid = max + (max - min) / 2;
        while (min < max) {
            mid = max + (max - min) / 2;
            if (n * mid > m) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }

    public static void solve(FastReader sc, PrintWriter w, StringBuilder sb) throws Exception {
        int n = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        if (n == 1) {
            sb.append("YES\n");
            return;
        }
        boolean is = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] < a[i]) {
                is = false;
                break;
            } else {
                is = true;
            }
        }
        if (is) {
            sb.append("YES\n");
        } else {
            ArrayList<trinary> al = new ArrayList<>();
            al.add(new trinary(a[0], 0L, 0L));
            int c = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] != al.get(c - 1).a) {
                    al.add(new trinary(a[i], i, i));
                    c++;
                } else {
                    long t = al.get(al.size() - 1).b;
                    long num = al.get(al.size() - 1).a;
                    al.remove(al.size() - 1);
                    al.add(new trinary(num, t, i));
                }
            }
            

            

            

            if (al.size() == 2) {
                sb.append("YES\n");
                return;
            }
            int count = 0;
            for (int i = 0; i < al.size(); i++) {
                if (al.get(i).b == 0) {
                    if (al.get(i + 1).a > al.get(i).a) {
                        count++;
                    }
                } else if (al.get(i).c == n - 1) {
                    if (al.get(i - 1).a > al.get(i).a) {
                        count++;
                    }
                } else {
                    if (al.get(i - 1).a > al.get(i).a && al.get(i).a < al.get(i + 1).a) {
                        count++;
                    }
                }
            }
            if (count == 1) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
    }

    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        PrintWriter w = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        

        long o = sc.nextLong();
        

        while (o > 0) {
            solve(sc, w, sb);
            o--;
        }
        System.out.print(sb.toString());
        w.close();
    }
}