

import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class FileHandler {

    BigInteger fib(int n) {

        BigInteger a = new BigInteger("1");
        BigInteger b = new BigInteger("1");
        BigInteger s = new BigInteger("2");

        if (n == 1 || n == 2)
            return a;

        for (int i = 3; i <= n; i++) {

            s = a.add(b);
            a = b;
            b = s;
        }
        return s;
    }

    boolean isPrime(int n) {
        if (n == 0) return false;
        return BigInteger.valueOf(n).isProbablePrime(n);
    }

    int nextprime(int n) {
        return BigInteger.valueOf(n).nextProbablePrime().intValue();
    }

    void id29(int n) {
        if (n == 0)
            return;
        System.out.print(n + " ");
        id29(n - 1);
    }

    void id33(int n) {
        if (n == 0)
            return;
        id33(n - 1);
        System.out.print(n + " ");
    }

    int sumNatural(int n, int s) {







        

        if (n == 0)
            return n + s;
        s += n;
        return sumNatural(n - 1, s);
    }

    public boolean isPalindrome(String s, int start, int end) {
        while (start < end && s.charAt(start) == s.charAt(end)) {
            start++;
            end--;
        }
        return start >= end;
    }

    int id2(int n) {
        if (n == 0)
            return 0;

        return n % 10 + id2(n / 10);
    }

    int id51(int n, int a, int b, int c) {
        if (n == 0)
            return 0;
        if (n < 0)
            return -1;

        int max = Math.max((Math.max(id51(n - a, a, b, c), id51(n - b, a, b, c))), id51(n - c, a, b, c));

        if (max == -1)
            return -1;

        return ++max;
    }

    void subsets(String s, String t, int i) {
        if (i == s.length()) {
            System.out.print(t + " ");
            return;
        }
        subsets(s, t, i + 1);
        subsets(s, t + s.charAt(i), i + 1);
    }

    int id22(int n, char a, char b, char c) {

        if (n == 1) {
            System.out.println("Move disc 1 from " + a + " to " + c);
            return 1;
        }

        id22(n - 1, a, c, b);
        System.out.println("Move disc " + n + " from " + a + " to " + c);
        id22(n - 1, b, a, c);

        return (int) (Math.pow(2, n) - 1);
    }

    int countDigits(int n) {
        if (n <= 9)
            return 1;
        return 1 + countDigits(n / 10);
    }

    boolean id49(int N) {
        

        

        String s = String.valueOf(N);
        return isPalindrome(s, 0, s.length() - 1);
    }

    int id5(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;

        if (a > b)
            return id5(a % b, b);
        else
            return id5(a, b % a);
    }

    void id11(int arr[], int n) {
        

        if (n == 0) return;

        id11(arr, n - 1);
        System.out.print(arr[n - 1] + " ");
    }

    int RecursivePower(int n, int p) {
        if (p == 0)
            return 1;
        return n * RecursivePower(n, p - 1);
    }

    int id44(int n1, int n2) {
        

        if (n1 == 0 || n2 == 0)
            return 0;

        return (n1 % 10) * (n2 % 10) + id44(n1 / 10, n2 / 10);

    }

    int id0(int arr[], int n) {
        

        return Arrays.stream(arr).min().getAsInt() + Arrays.stream(arr).max().getAsInt();
    }

    int id45(int[] arr, int n) {

        int maxLength = 0;
        int pane = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1])
                pane++;
            else {
                maxLength = Math.max(maxLength, pane);
                pane = 1;
            }
        }
        return Math.max(maxLength, pane);
    }

    boolean zeroSum(int[] arr) {
        HashSet<Integer> hs = new HashSet<>();
        int ps = 0;

        for (int i = 0; i < arr.length; i++) {
            ps += arr[i];

            if (ps == 0 || hs.contains(ps))
                return true;
            hs.add(ps);
        }
        return false;
    }

    int id16(int[] arr, int target) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        int ps = 0;
        int max = 0;

        for (int i = 0; i < arr.length; i++) {
            ps += arr[i];

            if (ps == target)
                max = i + 1;

            if (!hm.containsKey(ps))
                hm.put(ps, i);

            if (hm.containsKey(ps - target))
                max = Math.max(max, i - hm.get(ps - target));
        }
        return max;
    }

    int id23(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = (arr[i] == 0) ? -1 : 1;

        return id16(arr, 0);
    }

    int id35(int[] arr) {
        HashSet<Integer> hs = new HashSet<>();
        for (int i : arr)
            hs.add(i);
        return hs.size();
    }

    void id43(int[] arr) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }
        for (int keys : hm.keySet())
            System.out.println(keys + " --> " + hm.get(keys));
    }

    int binarySearch(long[] arr, int target) {
        int h = arr.length - 1;
        int l = 0;
        int mid;

        while (l <= h) {
            mid = (h + l) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }

    int binarySearch(int[] arr, int low, int high, int target) {

        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, high, target);
    }

    long sqrt(long n) {
        long low = 1;
        long high = n / 2;
        long res = 1;

        while (low <= high) {
            long mid = (high + low) / 2;
            long sqre = mid * mid;

            if (sqre == n)
                return mid;
            else if (sqre < n) {
                low = mid + 1;
                res = mid;
            } else
                high = mid - 1;
        }
        return res;
    }

    int id12(int[] arr) {
        int count = 0;
        int majority = 0;

        for (int i = 0; i < arr.length; i++) {
            if (count == 0)
                majority = arr[i];

            if (majority == arr[i])
                count++;
            else
                count--;
        }

        int t = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == majority)
                t++;
        }

        if (t > arr.length / 2)
            return majority;

        return -1;
    }

    void sortSelection(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            int j = i + 1;
            while (j < arr.length) {
                if (arr[j] < arr[min])
                    min = j;
                j++;
            }
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
    }

    void sortInsertion(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];

            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void combineSort(int[] arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int[] left = new int[n1];
        int[] right = new int[n2];

        for (int i = 0; i < n1; i++)
            left[i] = arr[i + low];

        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k++] = left[i];
            i++;
        }

        while (j < n2) {
            arr[k++] = right[j];
            j++;
        }
    }

    void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            combineSort(arr, low, mid, high);
        }
    }

    void id30(int[] arr, int[] brr) {
        int i = 0;
        int j = 0;

        while (i < arr.length && j < brr.length) {

            if (i > 0 && arr[i] == arr[i - 1]) {
                i++;
                continue;
            }

            if (arr[i] < brr[j])
                i++;
            else if (arr[i] > brr[j])
                j++;
            else {
                if (arr[i] == brr[j]) {
                    System.out.print(arr[i] + " ");
                }

                i++;
                j++;
            }
        }
    }

    void unionElements(int[] arr, int[] brr) {
        int i = 0;
        int j = 0;

        while (i < arr.length && j < brr.length) {

            if (i > 0 && arr[i] == arr[i - 1]) {
                i++;
                continue;
            }

            if (j > 0 && brr[j] == brr[j - 1]) {
                j++;
                continue;
            }

            if (arr[i] < brr[j]) {
                System.out.print(arr[i] + " ");
                i++;
            } else if (arr[i] > brr[j]) {
                System.out.print(brr[j] + " ");
                j++;
            } else {
                System.out.print(brr[j] + " ");
                j++;
                i++;
            }
        }

        while (i < arr.length) {
            if (arr[i] != arr[i - 1])
                System.out.print(arr[i] + " ");
            i++;
        }

        while (j < brr.length) {
            if (brr[j] != brr[j - 1])
                System.out.print(brr[j] + " ");
            j++;
        }
    }

    int id15(int[] arr, int low, int high) {
        int res = 0;
        if (low < high) {

            int mid = (low + high) / 2;
            res += id15(arr, 0, mid);
            res += id15(arr, mid + 1, high);
            res += mergeInverse(arr, low, mid, high);
        }
        return res;
    }

    int mergeInverse(int[] arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int res = 0;

        int[] left = new int[n1];
        int[] right = new int[n2];

        for (int i = 0; i < n1; i++)
            left[i] = arr[i + low];

        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                res += n1 - i;
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k++] = left[i];
            i++;
        }

        while (j < n2) {
            arr[k++] = right[j];
            j++;
        }
        return res;
    }

    void id6(int[] arr) {
        int l = 0;
        int r = arr.length - 1;

        while (l < r) {
            while (arr[l] < 0 && l < r) {
                l++;
            }

            while (arr[r] > 0 && l < r) {
                r--;
            }

            if (l < r) {
                int t = arr[l];
                arr[l] = arr[r];
                arr[r] = t;
                r--;
                l++;
            }
        }
    }

    void id25(int[] arr) {
        int i = -1;
        

        int k = Integer.MAX_VALUE;
        for (int j = 0; j < arr.length; j++) {
            if (arr[j] < k && arr[j] >= 0)
                k = arr[j];
        }

        for (int j = 0; j < arr.length - 1; j++) {
            if (arr[j] < k) {
                i++;
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }

        int temp = arr[arr.length - 1];
        arr[arr.length - 1] = arr[i + 1];
        arr[i + 1] = temp;
    }

    public static int getMaximum(int N, int[] arr) {
        

        long sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        while (N > 0) {
            if (sum % N == 0)
                return N;
            N--;
        }
        return 1;
    }

    public static boolean check(long A[], long B[], int N) {
        

        HashMap<Long, Integer> hm1 = new HashMap<>();
        HashMap<Long, Integer> hm2 = new HashMap<>();

        for (long i : A)
            hm1.put(i, hm1.getOrDefault(i, 0) + 1);
        for (long i : B)
            hm1.put(i, hm2.getOrDefault(i, 0) + 1);


        return hm1.equals(hm2);
    }

    public long minValue(long a[], long b[], long n) {
        

        Arrays.sort(a);

        int i = 0;
        int t = (int) (n - 1);
        while (i < t) {
            long temp = b[i];
            b[i] = b[t];
            b[t] = temp;

            t--;
            i++;
        }

        long sum = 0;

        for (int j = 0; j < n; j++)
            sum += a[i] * b[i];

        return sum;
    }

    static ArrayList<Integer> id17(int[] arr, int n, int s) {
        



        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + arr[i];
            

        }

        int left = 0;
        int right = 1;

        if (n == 1 && arr[0] == s) {
            a.add(1);
            a.add(1);
            return a;
        }

        while (left <= right && right < n) {
            if (arr[right] == s) {
                a.add(1);
                a.add(right + 1);
                return a;
            }

            if (arr[left] == s) {
                a.add(left + 1);
                a.add(left + 1);
                return a;
            }

            if (arr[right] - arr[left] < s)
                right++;
            else if (arr[right] - arr[left] > s)
                left++;
            else {
                a.add(left + 2);
                a.add(right + 1);
                return a;
            }
        }

        a.add(-1);
        return a;
    }

    static int equilibrium(long[] arr, int n) {

































        long id21 = 0;
        long cur_sum = 0;

        for (long l : arr)
            id21 += l;

        for (int i = 0; i < n; i++) {

            if (id21 - arr[i] - cur_sum == cur_sum)
                return i;
            cur_sum += arr[i];
        }
        return -1;
    }

    static ArrayList<Integer> leaders(int arr[], int n) {
        


        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int t = arr[l];
            arr[l] = arr[h];
            arr[h] = t;
            h--;
            l++;
        }
        ArrayList<Integer> a = new ArrayList<>();
        a.add(arr[0]);

        int j = 0;
        int i = 1;
        while (i < n && j < i) {
            if (arr[i] >= arr[j]) {
                a.add(arr[i]);
                j = i;
            }
            i++;
        }
        Collections.reverse(a);
        return a;
    }

    int maxLen(int arr[], int n) {
        

        HashMap<Integer, Integer> hm = new HashMap<>();
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cur += arr[i];
            if (hm.containsKey(cur)) {
                ans = Math.max(ans, i - hm.get(cur));
            } else
                hm.put(cur, i);
        }
        int max = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                max = i + 1;
                break;
            }
        }
        return Math.max(ans, max);
    }

    public String isSubset(long a1[], long a2[], long n, long m) {

        HashMap<Long, Integer> hm1 = new HashMap<>();
        HashMap<Long, Integer> hm2 = new HashMap<>();
        for (long l : a1) {
            hm1.put(l, hm1.getOrDefault(l, 0) + 1);
        }

        for (long l : a2) {
            hm2.put(l, hm2.getOrDefault(l, 0) + 1);

        }

        for (long l : a2) {
            if (!hm1.get(l).equals(hm2.get(l)))
                return "No";
        }
        return "Yes";
    }

    String id3(String arr[], int n) {
        

        String s = "";
        int l = id18(arr, n);
        for (int i = 0; i < l; i++) {
            char c = arr[0].charAt(i);

            for (int j = 0; j < n; j++) {
                if (arr[j].charAt(i) != c)
                    return s;
                s += c;
            }
        }
        return s;
    }

    int id18(String arr[], int n) {
        int min = arr[0].length();

        for (int i = 1; i < n; i++) {
            if (arr[i].length() < min) {
                min = arr[i].length();
            }
        }

        return (min);
    }

    long id24(long A[], int n, long B[], int m) {
        

        long sa = 0, sb = 0;

        Arrays.sort(A);
        Arrays.sort(B);

        for (int i = 0; i < n; i++)
            sa += A[i];

        for (int i = 0; i < m; i++)
            sb += B[i];
        

        if (Math.abs(sa + sb) % 2 == 1)
            return -1;

        long dif = Math.max(sa, sb) - (sa + sb) / 2;

        int index = -1;
        for (int i = 0; i < n; i++) {

            long target = A[i] - dif;

            if (dif > A[i])
                target = A[i];
            index = binarySearch(B, (int) target);
        }

        

        if (index != -1)
            return 1;

        for (int i = 0; i < m; i++) {
            long target = B[i] - dif;

            if (dif > B[i])
                target = B[i];
            index = binarySearch(A, (int) target);
        }
        

        if (index != -1)
            return 1;

        return -1;
    }

    public static int id27(String s) {
        

        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += c;
        }
        return sum;
    }

    public static String TieBreak(String names[], int n) {
        

        HashMap<String, Integer> hm = new HashMap<>();

        for (String name : names) {
            hm.put(name, hm.getOrDefault(name, 0) + 1);
        }
        int max = -1;
        String pname = "";
        String cname = "";
        for (String s : hm.keySet()) {
            int t = hm.get(s);

            if (t > max) {
                pname = s;
                max = t;
            } else if (t == max && s.compareTo(pname) < 0)
                pname = s;
        }

        System.out.println(hm);
        return pname;
    }

    public static int id31(int arr[], int n) {
        

        

        

        Arrays.sort(arr);
        int sum = 0;
        int l = 0;
        int h = n - 1;
        while (l < h) {
            sum += Math.abs(arr[l] - arr[h]);
            h--;
            l++;
        }
        if (n % 2 == 1)
            sum += arr[n / 2];
        return sum;

    }

    int minSubset(int[] arr, int n) {
        Arrays.sort(arr);
        long sum = 0;
        int ans = 0;
        long s = 0;

        for (int i : arr)
            s += i;

        for (int i = arr.length - 1; i >= 0; i--) {
            sum += arr[i];
            ans++;
            if (sum > s - sum)
                break;
        }
        return ans;
    }

    void id20() {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        while (T > 0) {
            String a = scan.next();
            String b = scan.next();

            String parentName = a + b;
            boolean is = true;
            int n = scan.nextInt();
            String[] names = new String[n];

            String concatName = "";

            for (int i = 0; i < n; i++) {
                names[i] = scan.next();
                concatName += names[i];
            }

            HashMap<Character, Integer> parentHM = new HashMap<>();
            for (char c : parentName.toCharArray()) {
                parentHM.put(c, parentHM.getOrDefault(c, 0) + 1);
            }

            HashMap<Character, Integer> childHM = new HashMap<>();
            for (char c : concatName.toCharArray()) {
                childHM.put(c, childHM.getOrDefault(c, 0) + 1);
            }

            for (char c : childHM.keySet()) {
                if (parentHM.get(c) == null || parentHM.get(c) < childHM.get(c)) {
                    System.out.println("NO");
                    is = false;
                    break;
                }
            }
            if (is)
                System.out.println("YES");

            T--;
        }

    }

    static boolean search(long[] arr) {
        for (long l : arr)
            if (l == 0)
                return true;

        return false;
    }

    public int[] id1(int[] changed) {

        Arrays.sort(changed);
        ArrayList<Integer> a = new ArrayList<>();

        for (int i = 0; i < changed.length; i++) {
            if (!a.contains(i)) {
                int index = binarySearch(changed, i + 1, changed.length - 1, 2 * changed[i]);
                


                if (a.contains(index))
                    index = binarySearch(changed, index + 1, changed.length - 1, 2 * changed[i]);

                if (index != -1)
                    a.add(index);
            }
        }
        int[] arr = new int[changed.length / 2];

        if (2 * a.size() != changed.length)
            return new int[0];

        int j = 0;
        System.out.println(a.size());
        for (int i = 0; i < changed.length; i++) {
            if (!a.contains(i)) {
                arr[j] = changed[i];
                j++;
                System.out.print("J " + j);
            }
        }
        return arr;
    }

    public int removeDuplicates(int[] arr) {
        int j = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                arr[j] = arr[i];
                j++;
            }
        }
        arr[j] = arr[arr.length - 1];
        return j + 1;
    }

    public void id48() {
        List<Integer> a = Arrays.asList(2, 3, 4, 5, 6, 7, 8);
        a.stream().filter(x -> (x % 2 == 0 && x < 5)).forEach(System.out::println);
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8};
        Arrays.stream(arr).filter(x -> x % 2 == 1).forEach(System.out::println);
    }

    void problem1() {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while (t > 0) {

            int n = scan.nextInt();
            int[] arr = new int[n];
            int max = -1, min = Integer.MAX_VALUE;
            int index = -1;
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
                if (arr[i] > max) {
                    max = arr[i];
                    index = i;
                }

                if (arr[i] < min)
                    min = arr[i];
            }

            if (min == max)
                System.out.println(n);
            else
                System.out.println(index + 1);
            t--;
        }
    }

    public static void id28(List<Integer> arr) {
        

        long max = 0, min = 0, sum = 0;
        for (int i : arr)
            sum += i;
        

        max = Collections.max(arr);
        min = Collections.min(arr);
        System.out.println((sum - max) + " " + (sum - min));
    }

    public static int findMedian(List<Integer> arr) {
        

        Collections.sort(arr);
        return arr.get(arr.size() / 2);
    }

    public Stack<Integer> sortStack(Stack<Integer> stack) {
        Stack<Integer> temp = new Stack<>();
        while (!stack.isEmpty()) {
            int t = stack.peek();
            stack.pop();
            while (!temp.isEmpty() && t < temp.peek()) {
                stack.push(temp.peek());
                temp.pop();
            }
            temp.push(t);
        }

        return temp;
    }

    public void id4(Stack<Integer> stack) {
        if (stack.isEmpty())
            return;

        int n = stack.pop();
        id4(stack);
        sortedInsert(stack, n);
    }

    private void sortedInsert(Stack<Integer> stack, int n) {
        if (stack.isEmpty() || n > stack.peek()) {
            stack.push(n);
            return;
        }

        int t = stack.pop();
        sortedInsert(stack, n);
        stack.push(t);
    }

    public void reverseStack(Stack<Integer> stack) {

        if (stack.isEmpty())
            return;

        int n = stack.pop();
        reverseStack(stack);
        id36(stack, n);
    }

    private void id36(Stack<Integer> stack, int n) {
        if (stack.isEmpty()) {
            stack.push(n);
            return;
        }

        int t = stack.pop();
        id36(stack, n);
        stack.push(t);
    }

    public static int id38(List<Integer> a) {
        

        HashMap<Integer, Integer> hm = new HashMap<>();

        for (Integer i : a)
            hm.put(i, hm.getOrDefault(i, 0) + 1);

        for (int i : hm.keySet()) {
            if (hm.get(i) == 1)
                return i;
        }
        return -1;
    }

    public static int id37(List<List<Integer>> arr) {
        

        int primary = 0;
        int secondary = 0;

        for (int i = 0; i < arr.size(); i++) {
            primary += arr.get(i).get(i);
        }

        int i = 0;
        int j = arr.size() - 1;
        while (i < arr.size() && j >= 0) {
            secondary += arr.get(i).get(j);
            i++;
            j--;
        }

        return Math.abs(primary - secondary);
    }

    public static List<Integer> id14(List<Integer> arr) {
        


        int[] a = new int[100];
        List<Integer> list = new ArrayList<>();

        for (int i : arr)
            a[i]++;

        for (int i = 0; i < a.length; i++)
            list.add(a[i]);

        return list;
    }

    public static int id41(List<List<Integer>> matrix) {
        

        int sum = 0;
        int n = matrix.size() / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num1 = matrix.get(i).get(2 * n - j - 1);  

                int num2 = matrix.get(i).get(j); 

                int num3 = matrix.get(2 * n - i - 1).get(j); 

                int num4 = matrix.get(2 * n - i - 1).get(2 * n - j - 1);

                

                sum += Math.max(num1, Math.max(num2, Math.max(num3, num4)));
            }
        }
        return sum;
    }

    public int id34(String s) {
        

        int start = 0;
        int end = s.length() - 1;
        while (start < end && s.charAt(start) == s.charAt(end)) {
            start++;
            end--;
        }
        if (start >= end) return -1;

        if (isPalindrome(s, start + 1, end)) return start;
        if (isPalindrome(s, start, end - 1)) return end;

        return -1;
    }

    static String id42(String S, int K) {
        


        if (S.length() == 1 && S.charAt(0) == '-') {

            return "";
        }


        int dash = 0;
        String string = "";
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '-')
                dash++;
            else
                string += S.charAt(i);
        }


        int firstgrp = (S.length() - dash) % K;

        String s = "";
        int i;
        for (i = 0; i < firstgrp; i++) {

            s += Character.toUpperCase(string.charAt(i));

        }

        if (firstgrp != 0)
            s += '-';

        int c = 0;

        for (int j = i; j < string.length(); j++) {

            s += Character.toUpperCase(string.charAt(j));
            c++;

            if (c == K) {
                c = 0;
                if (j != string.length() - 1)
                    s += '-';
            }

        }

        StringBuilder sb = new StringBuilder(s);

        if (s.charAt(s.length() - 1) == '-')
            sb.deleteCharAt(s.length() - 1);


        return sb.toString();
    }


    public int id19(String str) {
        


        int ans = 0;

        int p = str.length() - 1;
        int i = 0;
        while (i < str.length()) {
            if (str.charAt(i) == '1')
                ans += Math.pow(2, p);
            p--;
            i++;
        }

        return ans;
    }

    public String toBinary(String N) {
        

        int ans = 0;

        String s = "";
        int n = Integer.parseInt(N);
        while (n > 0) {
            s = n % 2 + s;
            n = n / 2;
        }
        return s;
    }

    public static int id47(int Mat[][], int N, int M) {
        

        int max = -1;
        int index = -1;
        for (int i = 0; i < N; i++) {
            int[] arr = Mat[i];

            if (arr[M - 1] == 0)
                continue;

            int t = M - firstOne(arr);


            if (t > max) {
                index = i;
                max = t;
            }
        }
        return index;
    }

    public static int firstOne(int[] arr) {
        int l = 0;
        int h = arr.length - 1;

        while (l < h) {
            int mid = (l + h) / 2;

            if (arr[mid] == 0) {
                if (arr[mid + 1] == 1)
                    return mid + 1;
                else
                    l = mid + 1;
            } else {
                if (arr[mid - 1] == 0)
                    return mid;
                else
                    h = mid - 1;
            }
        }
        return l;
    }

    ArrayList<Integer> countDistinct(int[] arr, int n, int k) {
        

        ArrayList<Integer> a = new ArrayList<>();

        HashMap<Integer, Integer> hm = new HashMap<>();

        for (int i = 0; i < k; i++) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        a.add(hm.size());

        for (int j = k; j < n; j++) {
            if (hm.get(arr[j - k]) == 1)
                hm.remove(arr[j - k]);
            else
                hm.replace(arr[j - k], hm.get(arr[j - k]) - 1);

            hm.put(arr[j], hm.getOrDefault(arr[j], 0) + 1);

            a.add(hm.size());
        }

        return a;
    }

    public ArrayList<ArrayList<Integer>> uniqueRow(int arr[][], int r, int c) {
        

        HashMap<String, Integer> hm = new HashMap<>();

        ArrayList<ArrayList<Integer>> a = new ArrayList<>();

        for (int i = 0; i < r; i++) {
            String s = "";

            for (int j = 0; j < c; j++) {
                s += String.valueOf(arr[i][j]);
            }

            if (!hm.containsKey(s))
                hm.put(s, i);

        }

        ArrayList<Integer> list = new ArrayList<>();
        for (String s : hm.keySet()) {
            list.add(hm.get(s));
        }

        Collections.sort(list);

        System.out.println(list);


        for (int i : list) {
            int[] n = arr[i];
            ArrayList<Integer> cool = new ArrayList<>();
            for (int k : n)
                cool.add(k);
            a.add(cool);
        }

        return a;
    }

    static boolean id46(String x) {
        

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < x.length(); i++) {
            if (!stack.isEmpty() && (stack.peek() == ']' || stack.peek() == '}' || stack.peek() == ')'))
                return false;

            if (stack.isEmpty() || x.charAt(i) == '(' || x.charAt(i) == '{' || x.charAt(i) == '[')
                stack.push(x.charAt(i));
            else {
                char c = x.charAt(i);
                if (c == ')') {
                    if (stack.peek() == '(')
                        stack.pop();
                    else
                        return false;
                } else if (c == '}') {
                    if (stack.peek() == '{')
                        stack.pop();
                    else
                        return false;
                } else {
                    if (stack.peek() == '[')
                        stack.pop();
                    else
                        return false;
                }
            }

        }
        return stack.isEmpty();
    }

    static String sortString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        s = String.valueOf(chars);
        return s;
    }

    static boolean isSorted(String s) {
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(i - 1))
                return false;
        }
        return true;
    }

    public static String gridChallenge(List<String> grid) {
        


        ArrayList<String> a = new ArrayList<>();
        for (String s : grid) {
            a.add(sortString(s));
        }

        for (int i = 0; i < a.get(0).length(); i++) {
            String s = "";
            for (int j = 0; j < a.size(); j++) {
                s += a.get(j).charAt(i);
            }

            if (!isSorted(s))
                return "NO";
        }

        return "YES";
    }

    public static void id26(List<Integer> q) {
        


        List<Integer> people = new LinkedList<>();
        IntStream.range(1, q.size() + 1).forEach(people::add);
        int currIndex;
        long id7 = 0;

        for (int i = 0; i < q.size(); i++) {
            final int currPerson = q.get(i);
            currIndex = people.get(0);

            if ((currIndex) != currPerson) {
                long id10 = people.indexOf(currPerson);
                if (id10 > 2) {
                    System.out.println("Too chaotic");
                    return;
                }
                id7 += id10;
                people.remove(Integer.valueOf(currPerson));
            } else {
                people.remove(Integer.valueOf(currPerson));
            }
        }
        System.out.println(id7);
    }

    String reverseWords(String S) {
        

        String[] str = S.split("[.]");
        String s = "";

        if (S.charAt(S.length() - 1) == '.')
            s += '.';

        for (int i = str.length - 1; i >= 0; i--) {
            s += str[i];

            if (i == 0) continue;
            s += ".";
        }

        return s;
    }

    

    public int id9(String str) {
        
















        HashMap<Character, Integer> hm = new HashMap<>();
        hm.put('I', 1);
        hm.put('V', 5);
        hm.put('X', 10);
        hm.put('L', 50);
        hm.put('C', 100);
        hm.put('D', 500);
        hm.put('M', 1000);
        

        int sum = 0;

        for (int i = 0; i < str.length() - 1; i++) {

            if (hm.get(str.charAt(i)) >= hm.get(str.charAt(i + 1))) {
                sum += hm.get(str.charAt(i));
            } else {
                sum -= hm.get(str.charAt(i));
            }
        }

        sum += hm.get(str.charAt(str.length() - 1));

        return sum;
    }

    

    String id13(String S) {
        

        String ans = "";

        for (char c : S.toCharArray()) {
            if (!ans.contains(String.valueOf(c)))
                ans += c;
        }
        return ans;
    }


    

    static int id40(String S) {
        

        boolean[] arr = new boolean[26];

        int maxLen = -1;
        int tempLen = 0;

        for (int i = 0; i < S.length(); i++)       

        {
            if (!arr[S.charAt(i) - 'a']) {
                tempLen++;
                arr[S.charAt(i) - 'a'] = true;
            } else {
                i = i - tempLen;
                maxLen = Math.max(maxLen, tempLen);
                tempLen = 0;
                arr = new boolean[26];
            }
        }
        return Math.max(maxLen, tempLen);
    }

    

    static boolean id39(int n, int k) {
        


        return (n & (1 << k)) == 1 << k;
    }

    static long solve(int N, int K, ArrayList<Long> GeekNum) {
        


        if(K == 1)
            return GeekNum.get(0);

        long sum=0;
        for(int i=0; i<K; i++)
            sum += GeekNum.get(i);

        long ans=0;
        for(int i=K; i<N; i++)
        {
            ans = sum;
            sum = 2*sum - GeekNum.get(i-K);
        }
        return ans;
    }

    int secondLargest(int[] arr)
    {
        int second=arr[0], max = arr[0];

        for(int i=1; i<arr.length; i++)
        {
            if(arr[i] > max)
            {
                second = max;
                max = arr[i];
            }
            else if(arr[i] > second && arr[i] != max)
                second = arr[i];
        }

        if(max == second)
            return -1;

        return second;
    }

    public long[] id32(int n,int arr[])
    {

        int[] temp = Arrays.copyOf(arr,0);

        HashMap<Integer, Long> hm = new HashMap<>();
        Arrays.sort(temp);

        long[] sum = new long[n];
        for(int i=1; i<n; i++)
        {
            sum[i] = sum[i-1] + temp[i-1];
        }

        hm.put(temp[0], sum[0]);
        for(int i=1; i<n; i++)
        {
            if(temp[i] == temp[i-1])
            {
                sum[i] = sum[i-1];
            }
            hm.put(temp[i], sum[i]);
        }

        for(int k=0; k<n; k++)
            sum[k] = hm.get(arr[k]);

        return sum;
    }

    static String reverse(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    static int id8(String S, int K) {
        

        int c=0;
        HashSet<Character> hs = new HashSet<>();    

        for(int i=0; i<K; i++)
            hs.add(S.charAt(i));

        if(hs.size() == K-1)
            c++;

        int l=0;
        int r=K;

        while(r < S.length())
        {
            hs.remove(S.charAt(l));
            hs.add(S.charAt(r));
            l++;
            r++;

            if(hs.size() == K-1)
                c++;
        }

        return c;
    }


    static String maxSum(String w,char x[],int b[], int n)
    {
        


































        HashMap<Character, Integer> hm = new HashMap<>();

        for(int i=0; i<n; i++)
            hm.put(x[i], b[i]);

        int max=0,sum=0;                                    

        String s="",ans=String.valueOf(w.charAt(0));
                                                                            

        for(int i=0; i<w.length(); i++)
        {
            if(hm.containsKey(w.charAt(i)))
                sum += hm.get(w.charAt(i));
            else
                sum += w.charAt(i);

            s += w.charAt(i);

            if(max < sum){
                max = sum;
                ans = s;
            }

            if(sum<0){
                sum=0;
                s="";
            }
        }
        return ans;

    }

    

    static String id50(String S, int k) {
        

        Stack<Character> stack = new Stack<>();     


        String s = "";

        k = correctK(k, S.length());
        for(int i=0; i<S.length(); i++)
        {
            while(!stack.isEmpty() && k > 0 && stack.peek() > S.charAt(i)) {
                stack.pop();
                k--;
            }

            stack.push(S.charAt(i));
        }

        while(!stack.isEmpty() && k > 0){
            stack.pop();
            k--;
        }

        while (!stack.isEmpty())
            s = stack.pop() + s;

        if(s.isEmpty())
            return "-1";

        return s;
    }

    static int correctK(int k, int n)
    {
        if((int)(Math.ceil((Math.log(n) / Math.log(2)))) == (int)(Math.floor(((Math.log(n) / Math.log(2))))))
        {
            return k/2;
        }
        return 2*k;
    }

    void solve() {

        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0)
        {
            int n = scanner.nextInt();

            if(n==1 || n==3)
                System.out.print(-1);
            else {
                System.out.print(n + " " + (n-1) + " ");

                for(int i=1; i<n-1; i++)
                    System.out.print(i + " ");
            }
            System.out.println();
            t--;
        }
    }


    public static void main(String[] temp) {

        FileHandler f = new FileHandler();















            

        

        

            f.solve();





































































































        

    }

}

