import com.sun.jdi.ArrayReference;
import com.sun.jdi.IntegerType;

import java.io.*;
import java.util.*;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.regex.Pattern;


public class Main {
    
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));


    public static void main(String[] args) throws IOException {
        id1();
    }


    static void id1() throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int max1 = 0, max2 = 0;
            for (int i = 0; i < n; i++) {
                int val = Integer.parseInt(st.nextToken());
                if (val > max1) {
                    max2 = max1;
                    max1 = val;
                } else if (val > max2)
                    max2 = val;
            }
            pw.println(max1 + max2);
        }
        pw.close();

    }

    static void id5() throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            br.readLine();
            String str = br.readLine();
            StringBuilder sb = new StringBuilder();
            for (char c : str.toCharArray()) {
                if (sb.length() == 0 || sb.charAt(sb.length() - 1) > c || (sb.charAt(sb.length() - 1) == c && sb.length() > 1)) {
                    sb.append(c);
                } else {
                    break;
                }
            }
            System.out.println(sb.toString() + sb.reverse().toString());
        }
    }

    static void id2() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<List<Integer>> nums = new ArrayList<>();
        while (st.hasMoreTokens()) {
            List<Integer> num = new ArrayList<>();
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            num.add(x);
            num.add(y);
            nums.add(num);
            st = new StringTokenizer(br.readLine());
        }
        System.out.println(nums);
    }

    static void Labyrinth() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken()) - 1;


        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) arr.add(new ArrayList<>());


        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int to = Integer.parseInt(st.nextToken()) - 1;
            int from = Integer.parseInt(st.nextToken()) - 1;
            arr.get(to).add(from);
        }

        int[] comp = new int[n];
        int[] prev = new int[n];

        Arrays.fill(comp, -1);
        Arrays.fill(prev, -1);

        comp[s] = s;
        Queue<Integer> q = new ArrayDeque<>();
        for (int to : arr.get(s)) {
            if (comp[to] == -1) {
                q.add(to);
                comp[to] = to;
                prev[to] = s;
            }
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int to : arr.get(cur)) {
                if (comp[to] == -1) {
                    q.add(to);
                    comp[to] = comp[cur];
                    prev[to] = cur;
                } else if (to != s && comp[to] != comp[cur]) {
                    ArrayList<Integer> path1 = getPath(to, prev);
                    ArrayList<Integer> path2 = getPath(cur, prev);
                    path2.add(to);
                    pw.println("Possible");
                    pw.println(path1.size());
                    for (var ele : path1) {
                        pw.print((ele + 1) + " ");
                    }
                    pw.println();
                    pw.println(path2.size());
                    for (var ele : path2) {
                        pw.print((ele + 1) + " ");
                    }
                    pw.println();
                    pw.close();
                    return;
                }
            }
        }

        pw.println("Impossible");
        pw.close();
    }


    private static ArrayList<Integer> getPath(int cur, int[] prev) {
        ArrayList<Integer> res = new ArrayList<>();
        while (cur != -1) {
            res.add(cur);
            cur = prev[cur];
        }
        Collections.reverse(res);
        return res;
    }

    static String id10(int[] tail, int cur) {
        StringBuilder ans = new StringBuilder();
        while (cur != -1) {
            ans.insert(0, tail[cur] == -1 ? cur : " " + cur);
            cur = tail[cur];
        }
        return ans.toString();
    }


    static void id7() throws IOException {
        int t = Integer.parseInt(br.readLine());
        next:
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] nums = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            HashMap<Integer, Integer> freq = new HashMap<>();

            int maxFreq = 0;
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
                int ret = freq.getOrDefault(nums[i], 0);
                if (ret == n - 1) {
                    pw.println(0);
                    continue next;
                }
                maxFreq = Math.max(maxFreq, ret + 1);
                freq.put(nums[i], ret + 1);
            }
            int ans = 0;
            while (maxFreq < n) {
                int d = Math.min(n - maxFreq, maxFreq);
                ans += 1 + d;
                maxFreq += d;
            }
            pw.println(ans);
        }
        br.close();
        pw.close();
    }


    static void id6() throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            pw.printf("%d %d %d %d\n", Integer.parseInt(br.readLine()) - 3, 1, 1, 1);
        }
        pw.close();
        br.close();
    }


    static void id3() throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] data = br.readLine().split(" ");
            int year = Integer.parseInt(data[0]);
            int year1 = year + 1;
            int year2 = Integer.parseInt(data[3]);
            int ans = 0;
            while (year1 < year2) {
                if (year1 >= 2020 && year1 <= 2029 || year1 % 1000 == 202) {
                    ans += isLeap(year1) ? 366 : 365;
                } else if (year1 >= 2000) {
                    ans++;
                    if (year1 % 10 == 2) ans += isLeap(year1) ? 29 : 28;
                    else ans++;
                }
                year1++;
            }
            int month1 = Integer.parseInt(data[1]), month2 = Integer.parseInt(data[4]);
            int day1 = Integer.parseInt(data[2]), day2 = Integer.parseInt(data[5]);
            if (year2 - year > 0) {
                if (month1 < 12) {
                    ans++;
                    if (data[0].substring(0, 3).equals("202") || year % 1000 == 202) {
                        ans += day1;
                        ans += calculate(year, month1 + 1);
                    } else if (year % 10 == 2 && month1 == 2) {
                        ans += day1;
                    } else ans++;
                } else {
                    if (data[0].substring(0, 3).equals("202") || year % 1000 == 202) {
                        ans += day1;
                    } else {
                        ans += day1 > 2 ? 0 : 1;
                    }
                }


                if (data[3].substring(0, 3).equals("202") || year2 % 1000 == 202) {
                    ans += calculate(year2, 1, month2 - 1);
                    ans += day2;
                } else {
                    if (month2 == 12) {
                        ans += day2 >= 2 ? 1 : 0;
                    }
                    if (year2 % 10 == 2) {
                        if (month2 == 2) {
                            ans += day2 >= 2 ? 1 : 0;
                        } else if (month2 > 2) {
                            ans += isLeap(year2) ? 29 : 28;
                        }
                    } else ans++;
                }
            } else {
                if (data[0].substring(0, 3).equals("202") || year % 1000 == 202) { 

                    if (month1 == month2) ans += day2 - day1 + 1;
                    else {
                        ans += calculate(year2, month1, month1) + 1 - day1;
                        ans += day2;
                        ans += calculate(year, month1 + 1, month2 - 1);
                    }
                } else if (year2 % 10 == 2) { 

                    if (month2 == 2) {
                        ans += day2;
                    } else if (month1 == 2) {
                        if (month2 > month1) {
                            ans += 1 - day1 + (isLeap(year2) ? 29 : 28);
                        } else if (month2 == month1)
                            ans += day2 - day1 + 1;
                        else if (month2 == 12)
                            if (day2 >= 2) ans++;
                    }
                } else if (month2 % 10 == 2) {
                    if (day2 >= 2) {
                        if (month2 == 2) ans++;
                        if (month2 == 12) ans++;
                    }
                }
            }
            pw.println(ans);
        }
        pw.close();
    }

    static int calculate(int year, int month, int endMonth) {
        int ans = 0;
        while (month <= endMonth) {
            switch (month) {
                case 4:
                case 6:
                case 9:
                case 11:
                    ans += 30;
                    break;
                case 2:
                    ans += isLeap(year) ? 29 : 28;
                    break;
                default:
                    ans += 31;
            }
            month++;
        }
        return ans;
    }

    static int calculate(int year, int month) {
        int ans = 0;
        while (month <= 12) {
            switch (month) {
                case 4:
                case 6:
                case 9:
                case 11:
                    ans += 30;
                    break;
                case 2:
                    ans += isLeap(year) ? 29 : 28;
                    break;
                default:
                    ans += 31;
            }
            month++;
        }
        return ans;
    }

    static boolean isLeap(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? true : false;
    }

    static void id8() throws IOException {
        int n = Integer.parseInt(br.readLine());
        Queue<String> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int choose = Integer.parseInt(st.nextToken());
            if (choose == 1) {
                queue.offer(st.nextToken());
            } else {
                String poll = queue.poll();
                queue.offer(poll);
                pw.println(poll);
            }
        }
        br.close();
        pw.close();
    }


    static void id0() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

    }

    static void id9() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        pw.println(n % m == 0 ? n / m : n / m + 1);
        br.close();
        pw.close();
    }

    static void GettingZero() throws IOException {
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int nums[] = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        for (var ele : nums) {
            int ans = 15;
            for (int i = 0; i < 15; i++) { 

                for (int j = 0; j < 15; j++) { 

                    if (((ele + j) << i) % 32768 == 0)
                        ans = Math.min(ans, i + j);
                }
            }
            pw.println(ans);
        }

        br.close();
        pw.close();
    }

    static void id4() throws IOException {
        int t = Integer.valueOf(br.readLine());




        while (t-- > 0) {
            int n = Integer.valueOf(br.readLine());






            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            long[] arr1 = new long[n], arr2 = new long[n];
            for (int i = 0; i < n; i++) {
                arr1[i] = Integer.valueOf(st1.nextToken());
                arr2[i] = Integer.valueOf(st2.nextToken());
            }
            for (int i = 0; i < n; i++) {
                if (arr1[i] <= arr2[i]) continue;
                arr1[i] ^= arr2[i];
                arr2[i] ^= arr1[i];
                arr1[i] ^= arr2[i];
            }

            long sum = 0;
            for (int i = 0; i < n - 1; i++) {
                long res1 = Math.abs(arr1[i] - arr1[i + 1]) + Math.abs(arr2[i] - arr2[i + 1]);
                sum += res1;
            }
            pw.println(sum);
        }
        br.close();
        pw.close();
    }


    static int N = 10010;
    static int[] ne = new int[N], e = new int[N], h = new int[N], w = new int[N];
    static int idx, n, m;
    static boolean[] st = new boolean[N];

    static int[] cnt = new int[N];  

    static int[] dist = new int[N]; 


    static void add(int a, int b, int c) {
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    static boolean spfa() {
        

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            q.offer(i);
        }
        while (!q.isEmpty()) {
            int t = q.poll();
            st[t] = false;
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                

                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    cnt[j] = cnt[t] + 1; 

                    

                    if (cnt[j] >= n) {
                        return true;
                    }
                    if (!st[j]) {
                        st[j] = true;
                        q.offer(j);
                    }
                }

            }
        }
        return false;
    }

    static int gcd(int x, int y) {
        return x % y == 0 ? y : gcd(y, x % y);
    }


    static String addLeading(String str, int n) {
        StringBuilder ans = new StringBuilder(str);
        while (n-- > 0)
            ans.insert(0, 0);
        return ans.toString();
    }

    boolean[] visited = new boolean[4];

    Stack<Integer> stack = new Stack<Integer>();


    static boolean isDigit(String str) {
        Pattern pattern = Pattern.compile("^[-\\+]?[\\d]*$");
        return pattern.matcher(str).matches();
    }

    
    private static void backtrack(int start, LinkedList<Integer> current, int n, int k, List<List<Integer>> ans) {
        if (current.size() == k) {
            ans.add(new LinkedList<Integer>(current));
        }
        for (int i = start; i <= n && current.size() < k; i++) {
            current.add(i);
            backtrack(i + 1, current, n, k, ans);
            current.removeLast();
        }
    }

    
    public static List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new LinkedList<>();
        if (k == 0) {
            ans.add(new LinkedList<Integer>());
            return ans;
        }
        backtrack(1, new LinkedList<Integer>(), n, k, ans);
        return ans;
    }

    public void dfs(int[] nums) {
        if (nums.length == stack.size()) {
            System.out.println(stack);
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                stack.push(nums[i]);
                dfs(nums);
                visited[i] = false;
                stack.pop();
            }
        }
    }
}
