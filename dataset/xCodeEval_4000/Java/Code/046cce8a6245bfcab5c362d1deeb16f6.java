
import java.io.*;
import java.util.*;


public class ExtraFunctions {

    static ArrayList<Integer>[] edges;
    static boolean visited[];
    static Stack<Integer> nodes = new Stack<>();
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();

    
    static ArrayList<String> ar = new ArrayList<>();
    static ArrayList<Integer> b = new ArrayList<>();

    static int n = 50, m = 50;
    static int save[] = new int[100000];
    static int dp1[][] = new int[n][m];
    static int DP[] = new int[10000];
    static int dp[][] = new int[1000][1000];
    static int a[][] = new int[n][m];
    static int an1 = 0, an2 = 0;
    static final double cmp = 0.00001;
    static int ans = 0;
    static int grid[][] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, 1, -1}};
    static String w = "";
    static int cnt = 0;
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        while (t-- > 0) {
            int n = input.nextInt();
            int k = input.nextInt();
            int a[] = new int[n];
            boolean ca = false;
            for (int i = 0; i < n; i++) {
                a[i] = input.nextInt();
                if (a[i] == 1) {
                    ca = true;
                }
            }
            if (ca) {
                System.out.println("YES");
            } else {
                System.out.println("No");
            }
        }
    }

    static double sqrt(double v) {
        double max = 3037000499l;
        double min = 0;
        double ans = 0;
        while (max - min > cmp) {
            double mid = min + (max - min) / 2.0;
            if (mid * mid > v) {
                max = mid;
            } else {
                ans = mid;
                min = mid;
            }
        }
        return ans;
    }

    static long cbrt(long v) {
        long max = 2097152;
        long min = 0;
        long ans = 0;
        while (max >= min) {
            long mid = (max + min) / 2;
            if (mid * mid * mid > v) {
                max = mid - 1;
            } else {
                ans = mid;
                min = mid + 1;
            }
        }
        return ans;
    }

    static long sqrt(long v) {
        long max = 3037000499l;
        long min = 0;
        long ans = 0;
        while (max >= min) {
            long mid = (max + min) / 2;
            if (mid * mid > v) {
                max = mid - 1;
            } else {
                ans = mid;
                min = mid + 1;
            }
        }
        return ans;
    }

    public static int sol(int ind, int a[], int sum) {
        if (ind == a.length) {
            if (sum == 0) {
                return 0;
            } else {
                return (int) 1e6;
            }
        }
        return Math.min(1 + sol(ind + 1, a, sum - a[ind]), sol(ind + 1, a, sum));
    }

    public static int solve(long a[], long va) {
        int max = a.length - 1;
        int min = 0;
        int ans = -1;
        while (max >= min) {
            int mid = (max + min) / 2;
            if (a[mid] > va) {
                max = mid - 1;
            } else {
                min = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
    

    


    public static int[] swap(int data[], int left, int right) {

        

        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        

        return data;
    }

    

    

    

    public static int[] reverse(int data[], int left, int right) {

        

        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        

        return data;
    }

    

    

    public static boolean findNextPermutation(int data[]) {

        

        

        

        if (data.length <= 1) {
            return false;
        }

        int last = data.length - 2;

        

        

        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        

        

        if (last < 0) {
            return false;
        }

        int nextGreater = data.length - 1;

        

        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        

        data = swap(data, nextGreater, last);

        

        data = reverse(data, last + 1, data.length - 1);

        

        return true;
    }

    public static void allPremutations(LinkedList<Integer> l, boolean visited[], int a[]) {
        if (l.size() == a.length) {
            allprem.add(l);
        }
        for (int i = 0; i < a.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> nl = new LinkedList<>();
                for (Integer x : l) {
                    nl.add(x);
                }
                nl.add(a[i]);
                allPremutations(nl, visited, a);
                visited[i] = false;
            }
        }
    }

    public static int f(int n) {
        cnt++;
        if (n == 0 || n == 1) {
            return 1;
        }
        if (3 * f(n / 2) % 2 == 0) {
            return 2 * f(n / 2);
        } else {
            return 10 * f(n / 2);
        }
    }

    public static int logK(long v, long k) {
        int ans = 0;
        while (v > 0) {
            ans++;
            v /= k;
        }
        return ans;
    }

    public static long power(long a, long n) {
        if (n == 1) {
            return a;
        }
        long pow = power(a, n / 2);
        pow *= pow;
        if (n % 2 != 0) {
            pow *= a;
        }
        return pow;
    }

    public static void guess(long l, long r) {
        Scanner input = new Scanner(System.in);
        long ans = 1;
        while (r >= l) {
            long mid = (r + l) / 2;
            System.out.println("The number less than " + mid + "?\n");
            System.out.flush();
            String w;
            w = input.next();
            if (w.equalsIgnoreCase("YES")) {
                r = mid - 1;
            } else {
                l = mid + 1;
                ans = mid;
            }
        }
        System.out.println("! " + ans + "\n");
        System.out.flush();
    }

    public static long primeFactors(int n) {
        long sum = 0;
        while (n % 2 == 0) {
            System.out.println(2);
            n /= 2;
            ans++;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                System.out.println(i);
                n /= i;
                ans++;
            }
            ans++;
            if (n < i) {
                break;
            }
        }
        if (n > 2) {
            System.out.println(n);
        }
        return sum;
    }

    public static boolean isPalindrome(int n) {
        int t = n;
        int ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == n;
    }

    public static int LCS(String w, String s, String ans, int i, int j) {
        if (j == s.length() || i == w.length()) {
            return 0;
        }
        if (dp[i][j] == -1) {
            if (w.charAt(i) == s.charAt(j)) {
                dp[i][j] = 1 + LCS(w, s, ans + w.charAt(i), i + 1, j + 1);
            } else {
                dp[i][j] = Math.max(LCS(w, s, ans, i + 1, j), LCS(w, s, ans, i, j + 1));
            }
        }
        return dp[i][j];
    }

    public static int binarySearch(int a[], int value) {
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == value) {
                return m;
            } else if (a[m] > value) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    public static int findMinimumWithDivideAndConquer(int a[], int l, int r) {
        if (r - l + 1 == 1) {
            return a[l];
        }
        int min1 = findMinimumWithDivideAndConquer(a, l, (l + r) / 2);
        int min2 = findMinimumWithDivideAndConquer(a, (l + r) / 2 + 1, r);
        ans++;
        return Math.min(min1, min2);
    }

    public static int rodCutting(int index, int a[]) {

        if (index < 0) {
            ans++;
            return 0;
        }
        if (DP[index] == -1) {
            int p1 = 0;
            int p2 = index - 1;
            DP[index] = a[index];
            while (p1 <= p2) {
                ans++;
                DP[index] = Math.max(DP[index], rodCutting(p1, a) + rodCutting(p2, a));
                p1++;
                p2--;
            }
        }
        return DP[index];
    }

    public static int solve(int index, int a[], int size) {
        ans++;
        if (index == a.length) {
            return 0;
        }
        if (dp[size][index] != -1) {
            return dp[size][index];
        }
        int ans = 0;
        if (size >= index + 1) {
            ans = Math.max(a[index] + solve(index + 1, a, size - (index + 1)), solve(index + 1, a, size));
        } else {
            ans = solve(index + 1, a, size);
        }
        dp[size][index] = ans;
        return dp[size][index];
    }

    public static int solve(int a[], int prev, int index) {
        if (index == a.length) {
            return 0;
        }
        if (dp[index][prev] == -1) {
            int choice1 = solve(a, prev, index + 1);
            int choice2 = 0;
            if (a[index] > a[prev]) {
                choice2 = 1 + solve(a, index, index + 1);
            }
            dp[index][prev] = Math.max(choice1, choice2);
        }
        return dp[index][prev];
    }

    public static void genrate(int ind, int a[], ArrayList<Integer> sub) {
        if (ind == a.length) {
            powerSet.add(sub);
            return;
        }
        ArrayList<Integer> have = new ArrayList<>();
        ArrayList<Integer> less = new ArrayList<>();
        for (int i = 0; i < sub.size(); i++) {
            have.add(sub.get(i));
            less.add(sub.get(i));
        }
        have.add(a[ind]);
        genrate(ind + 1, a, have);
        genrate(ind + 1, a, less);
    }

    public static int bs(int v, ArrayList<Integer> s) {
        int max = s.size() - 1;
        int min = 0;
        int ans = -1;
        while (max >= min) {
            int mid = (max + min) / 2;
            if (s.get(mid) >= v) {
                max = mid - 1;
            } else {
                ans = mid;
                min = mid + 1;
            }
        }
        return ans;
    }

    public static int DP1(int i, int j) {
        an1++;
        if (i == n || j == m) {
            return 0;
        } else if (dp1[i][j] == -1) {
            dp1[i][j] = a[i][j] + Math.max(DP1(i + 1, j), DP1(i, j + 1));
        }
        return dp1[i][j];
    }

    public static int DP(int i, int j) {
        an2++;
        if (i == n || j == m) {
            return 0;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else {
            return a[i][j] + Math.max(DP(i + 1, j), DP(i, j + 1));
        }
    }

    public static long ceil(long a, long b) {
        return (a + b - 1) / b;
    }

    public static long round(long a, long b) {
        if (a < 0) {
            return (a - b / 2) / b;
        }
        return (a + b / 2) / b;
    }

    public static boolean isSorted(ArrayList<Integer> a) {
        for (int i = 0; i < a.size() - 1; i++) {
            if (a.get(i) > a.get(i + 1)) {
                return false;
            }
        }
        return true;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void f(String w, String s, int index, boolean vi[]) {
        if (s.length() == w.length()) {
            ar.add(s);
            return;
        }
        boolean nvi[] = new boolean[vi.length];
        System.arraycopy(vi, 0, nvi, 0, vi.length);
        if (index != -1) {
            nvi[index] = true;
        }
        for (int i = 0; i < w.length(); i++) {
            if (nvi[i]) {
                continue;
            }
            f(w, s + w.charAt(i), i, nvi);
        }

    }

    public static void quickSort(int a[], int l, int r) {
        if (l == r || l > r) {
            return;
        }
        int pivot = a[l];
        int be = l;
        int e = r;
        while (l < r) {
            if (a[l] == pivot) {
                if (a[r] < a[l]) {
                    int s = a[l];
                    a[l] = a[r];
                    a[r] = s;
                    l++;
                } else {
                    r--;
                }
            } else {
                if (a[r] < a[l]) {
                    int s = a[l];
                    a[l] = a[r];
                    a[r] = s;
                    r--;
                } else {
                    l++;
                }
            }
        }
        quickSort(a, be, l);
        quickSort(a, l + 1, e);
    }

    public static void mergeSort(int a[]) {
        if (a.length == 1) {
            return;
        }
        int child1[] = Arrays.copyOfRange(a, 0, a.length / 2);
        int child2[] = Arrays.copyOfRange(a, a.length / 2, a.length);
        mergeSort(child1);
        mergeSort(child2);
        merge(child1, child2, a);
    }

    private static void merge(int child1[], int child2[], int a[]) {
        int p1 = 0;
        int p2 = 0;
        while (p1 < child1.length || p2 < child2.length) {
            if (p1 == child1.length) {
                a[p1 + p2] = child2[p2++];
            } else if (p2 == child2.length) {
                a[p1 + p2] = child1[p1++];
            } else {
                if (child1[p1] < child2[p2]) {
                    a[p1 + p2] = child1[p1++];
                } else {
                    a[p1 + p2] = child2[p2++];
                }
            }
        }
    }

    public static int dpFib(int n) {
        int fib[] = new int[n + 1];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n];
    }

    public static ArrayList<Integer> printPrimeFactoriztion(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                if (isPrime(i)) {
                    a.add(i);
                    n /= i;
                    i = 0;
                } else if (isPrime(n / i)) {
                    a.add(n / i);
                    n = i;
                    i = 0;
                }
            }
        }
        return a;
    }

    public static int bsFindFirst(int a[], int key) {
        int max = a.length - 1;
        int min = 0;
        while (max > min) {
            int mid = (max + min) / 2;
            if (a[mid] == key) {
                max = mid;
            } else if (a[mid] < key) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return min;
    }

    public static int binarySearch(int a[], int max, int min, int key) {
        int mid = (min + max) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (min > max) {
            return -1;
        } else if (a[mid] > key) {
            return binarySearch(a, mid - 1, min, key);
        } else {
            return binarySearch(a, max, mid + 1, key);
        }
    }

    public static void getPowerSet(Queue<Integer> a) {
        int n = a.poll();
        if (!a.isEmpty()) {
            getPowerSet(a);
        }
        int s = powerSet.size();
        for (int i = 0; i < s; i++) {
            ArrayList<Integer> ne = new ArrayList<>();
            ne.add(n);
            for (int j = 0; j < powerSet.get(i).size(); j++) {
                ne.add(powerSet.get(i).get(j));
            }

            powerSet.add(ne);
        }
        ArrayList<Integer> p = new ArrayList<>();
        p.add(n);
        powerSet.add(p);
    }

    public static long GCD(long x, long y) {
        long Temp;
        while (y != 0) {
            Temp = y;
            y = x % y;
            x = Temp;
        }
        return x;
    }

    public static boolean checkLucky(String w) {
        for (int i = 0; i < w.length(); i++) {
            if (w.charAt(i) != '7' && w.charAt(i) != '4') {
                return false;
            }
        }
        return true;
    }

    public static boolean checkLucky(int w) {
        while (w > 0) {
            int r = w % 10;
            w /= 10;
            if (r != 4 && r != 7) {
                return false;
            }
        }
        return true;
    }

    public static void insertionSort(int a[]) {
        int l = 1;
        while (l < a.length) {
            for (int i = l - 1; i > -1; i--) {
                if (a[i + 1] > a[i]) {
                    break;
                }
                int x = a[i + 1];
                a[i + 1] = a[i];
                a[i] = x;
            }
            l++;
        }
    }

    public static String convertToHexdecimal(long n) {
        String ans = "";
        while (n > 0) {
            long r = n % 16;
            n /= 16;
            if (r < 10) {
                ans = r + ans;
            } else {
                ans = (char) (65 + (r - 10)) + ans;
            }
        }
        return ans;
    }

    public static long convertToDecimal(String w) {
        int counter = 0;
        long ans = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = 0;
            if (w.charAt(i) > 64) {
                x = (w.charAt(i) - 65) + 10;
            } else {
                x = w.charAt(i) - '0';
            }
            ans += x * Math.pow(16, counter);
            counter++;
        }
        return ans;
    }

    public static void bubbleSort(int a[]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length - i - 1; j++) {
                if (a[j] < a[j + 1]) {
                    int x = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = x;
                }
            }
        }
    }

    static class pair {

        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }

    }

    public static long pow(long n, int l) {
        if (l == 0) {
            return 1;
        }
        long t = n;
        for (int i = 1; i < l; i++) {
            n = (n * t);
        }
        return n;
    }

    public static long factorial(long n) {
        long t = n - 1;
        while (t > 1) {
            n *= t;
            t--;
        }
        return n;
    }

    private static boolean isPrime(long num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        if (num == 3) {
            return true;
        }
        for (int i = 3; i <= Math.sqrt(num) + 1; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void prefixSum(long a[]) {
        for (int i = 1; i < a.length; i++) {
            a[i] = a[i] + a[i - 1];
        }
    }

    public static void prefixSumrecursive(long a[], int index) {
        if (index - 1 > 0) {
            prefixSumrecursive(a, index - 1);
        }
        a[index] += a[index - 1];
    }

    public static int bainryToDecimal(String w) {
        int r = 0;
        int l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            int x = (w.charAt(i) - '0') * (int) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String decimalToBinary(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    

    public static int upperBound(int a[], int key, int begin, int end) {
        int A = begin;
        int B = end;
        if (key >= a[a.length - 1]) {
            return a.length - 1;
        }
        while (A < B) {
            int I = (int) Math.round((A + B) / 2.0);
            if (a[I] <= key) {
                A = I;

            } else {
                B = I - 1;
            }
        }
        return A;
    }
    


    public static int lowerBound(int a[], int key, int begin, int end) {
        int A = begin;
        int B = end;
        while (A < B) {
            int I = (A + B) / 2;
            if (a[I] >= key) {
                B = I;
            } else {
                A = I + 1;
            }
        }
        return A;
    }

    public static int lowerBound(ArrayList<Integer> a, int key) {
        int A = 0;
        int B = a.size() - 1;
        while (A < B) {
            int I = (A + B) / 2;
            if (a.get(I) >= key) {
                B = I;
            } else {
                A = I + 1;
            }
        }
        return A;
    }

    public static int upper(ArrayList<Integer> a, int key) {
        int low = 0;
        int high = a.size() - 1;
        if (key <= a.get(high)) {
            while (low < high) {
                int mid = low + (high - low + 1) / 2;
                if (a.get(mid) <= key) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
        } else {
            low = -1;
        }
        return low;

    }

    public static int lowerBound(ArrayList<Integer> a, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            

            if (value <= a.get(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static int lowerBound(int[] array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            

            if (value <= array[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static int upper(int arr[], int key) {
        int low = 0;
        int high = arr.length - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (arr[mid] <= key) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    static int UpperBound(int a[], int x) {

        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return l + 1;
    }

    public static int lowerBound(int a[], int key) {
        int A = 0;
        int B = a.length - 1;
        int value;
        if (key >= a[B]) {
            while (true) {
                int I = (A + B) / 2;
                if (a[I] == key) {
                    value = I;
                    A += 1;
                    if (A == a.length) {
                        break;
                    }
                } else if (a[I] > key) {
                    B = I - 1;
                    if (B == -1) {
                        value = A;
                        break;
                    }
                    if (A > B) {
                        value = B;
                        break;
                    }
                } else {
                    A = I + 1;
                    if (A == a.length) {
                        value = B;
                        break;
                    }
                    if (A > B) {
                        value = B;
                        break;
                    }
                }
            }
        } else {
            value = -1;
        }
        return value;
    }

}
