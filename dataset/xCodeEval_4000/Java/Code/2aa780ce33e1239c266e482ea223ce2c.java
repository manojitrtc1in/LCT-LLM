import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.*;
import java.util.stream.IntStream;

public class CodeforcesComp {
    public static void main(String[] args) throws IOException {
        _3E();
    }
    private static void _7D() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nx = bi.readLine().split(" ");
        int n = Integer.parseInt(nx[0]);
        String xs = nx[1];
        char[] xc = xs.toCharArray();
        Arrays.sort(xc);
        long x = Integer.parseInt(nx[1]);
        int steps = 0;
        while(xs.length() < n) {
            int digit = xc[xs.length()-1] - '0';
            if(digit < 2) break;
            System.out.println(digit + " " + x);
            x *= digit;
            xs = String.valueOf(x);
            xc = xs.toCharArray();
            Arrays.sort(xc);
            steps++;
        }
        System.out.println(xs.length() == n ? steps : -1);
    }
    private static void _7C() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            String[] bs = bi.readLine().split(" ");
            int[] b = new int[n];
            for (int j = 0; j < n; j++) {
                b[j] = Integer.parseInt(bs[j]);
            }
            ArrayList<Integer> iIndex = new ArrayList<>();
            ArrayList<Integer> jIndex = new ArrayList<>();
            boolean skip = true;
            for (int j = 1; j < n; j++) {
                if (a[j - 1] > a[j] || b[j - 1] > b[j]) {
                    skip = false;
                    break;
                }
            }
            if(skip) {
                System.out.println(0);
                continue;
            }
            for (int j = 0; j < n-1; j++) {
                int minIndex = j;
                for (int k = j+1; k < n; k++) {
                    if(a[k] < a[minIndex]) minIndex = k;
                }
                int tempA = a[j];
                a[j] = a[minIndex];
                a[minIndex] = tempA;

                int tempB = b[j];
                b[j] = b[minIndex];
                b[minIndex] = tempB;

                iIndex.add(minIndex);
                jIndex.add(j);
            }
            boolean flag = false;
            boolean notPerfect = true;
            while(notPerfect) {
                notPerfect = false;
                for (int j = 1; j < n; j++) {
                    if(b[j-1] > b[j]) {
                        if(a[j] != a[j-1]) {
                            flag = true;
                            break;
                        } else {
                            int tempB = b[j];
                            b[j] = b[j-1];
                            b[j-1] = tempB;

                            iIndex.add(j-1);
                            jIndex.add(j);
                            notPerfect = true;
                        }
                    }
                }
            }
            for (int j = 0; j < iIndex.size(); j++) {
                if(Objects.equals(iIndex.get(j), jIndex.get(j))) {
                    iIndex.remove(j);
                    jIndex.remove(j);
                    j--;
                }
            }
            if(!flag) {
                System.out.println(iIndex.size());
                for (int j = 0; j < iIndex.size(); j++) {
                    System.out.println((iIndex.get(j)+1) + " " + (jIndex.get(j)+1));
                }
            } else System.out.println(-1);
        }
    }
    private static void _7B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            int m = Integer.parseInt(bi.readLine());
            String[] bs = bi.readLine().split(" ");
            int[] b = new int[m];
            for (int j = 0; j < m; j++) {
                b[j] = Integer.parseInt(bs[j]);
            }
            long totalShift = 0;
            for (int i1 : b) {
                totalShift += i1;
            }
            int index = (int) (totalShift % (long) n);
            System.out.println(a[index]);
        }
    }
    private static void _7A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            int m = Integer.parseInt(bi.readLine());
            String[] bs = bi.readLine().split(" ");
            int[] b = new int[m];
            for (int j = 0; j < m; j++) {
                b[j] = Integer.parseInt(bs[j]);
            }
            Arrays.sort(a);
            Arrays.sort(b);
            ArrayList<Integer> aa = new ArrayList<>();
            ArrayList<Integer> bb = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                aa.add(a[j]);
            }
            for (int j = 0; j < m; j++) {
                bb.add(b[j]);
            }

            int ALICE = 0, BOB = 0;
            String winner = "";
            boolean AliceHasHigherMax = a[n-1] >= b[m-1];
            boolean BobHasHigherMax = a[n-1] <= b[m-1];
            if(AliceHasHigherMax) {
                System.out.println("Alice");
            } else System.out.println("Bob");

            if(BobHasHigherMax) {
                System.out.println("Bob");
            } else System.out.println("Alice");
        }
    }
    private static void _6F() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nk = bi.readLine().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) a[j] = Integer.parseInt(as[j]);
            HashMap<Integer, Integer> freq = new HashMap<>();
            ArrayList<Integer> good = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                freq.put(a[j], freq.getOrDefault(a[j], 0) + 1);
                if (freq.get(a[j]) == k) good.add(a[j]);
            }
            Collections.sort(good);
            int l = 0, r = 0;
            int prevSplit = 0;
            List<Integer> max = new ArrayList<>();
            for (int j = 1; j < good.size(); j++) {
                if(good.get(j) - good.get(j-1) > 1) {
                    List<Integer> current = good.subList(prevSplit, j);
                    if(current.size() > max.size()) {
                        max = current;
                    }
                    prevSplit = j;
                }
            }
            List<Integer> end = good.subList(prevSplit, good.size());
            if(end.size() > max.size()) {
                max = end;
            }
            if(max.size() >= 1){
                l = max.get(0);
                r = max.get(max.size()-1);
            }








































            System.out.println(!(l + r == 0) ? l + " " + r : "-1");
        }
    }
    private static void _6E() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nq = bi.readLine().split(" ");
            int n = Integer.parseInt(nq[0]);
            int q = Integer.parseInt(nq[1]);
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            Arrays.sort(a);
            int[] sum = new int[n];
            sum[0] = a[n-1];
            for (int j = 1; j < n; j++) {
                sum[j] = sum[j-1] + a[n-1-j];

            }
            for (int j = 0; j < q; j++) {
                int k = Integer.parseInt(bi.readLine());
                if(k > sum[n-1]) {
                    System.out.println(-1);
                    continue;
                }
                int candies = -1;
                int l = 0, r = n-1;
                while(l <= r) {
                    int mid = (l+r)/2;
                    if(sum[mid] >= k) {
                        candies = mid + 1;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                System.out.println(candies);
            }
        }
    }
    private static void _6D() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nm = bi.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            int[][] board = new int[n][m];
            for (int j = 0; j < n; j++) {
                String[] line = bi.readLine().split(" ");
                for (int k = 0; k < m; k++) {
                    board[j][k] = Integer.parseInt(line[k]);
                }
            }
            int max = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    int row = j;
                    int col = k;
                    int sum = 0;
                    while(row < n && col < m && row >= 0 && col >= 0) {
                        sum += board[row][col];
                        row++;
                        col++;
                    }
                    row = j;
                    col = k;
                    while(row < n && col < m && row >= 0 && col >= 0) {
                        sum += board[row][col];
                        row--;
                        col--;
                    }
                    row = j;
                    col = k;
                    while(row < n && col < m && row >= 0 && col >= 0) {
                        sum += board[row][col];
                        row--;
                        col++;
                    }
                    row = j;
                    col = k;
                    while(row < n && col < m && row >= 0 && col >= 0) {
                        sum += board[row][col];
                        row++;
                        col--;
                    }
                    sum -= 3*board[j][k];
                    if(sum > max) max = sum;
                }
            }
            System.out.println(max);
        }
    }
    private static void _6C() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nm = bi.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            String[] words = new String[n];
            for (int j = 0; j < n; j++) {
                words[j] = bi.readLine();
            }
            int minMin = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    String s1 = words[j];
                    String s2 = words[k];
                    int min = 0;
                    for (int l = 0; l < m; l++) {
                        min += Math.abs(s1.charAt(l) - s2.charAt(l));
                    }
                    if(min < minMin) {
                        minMin = min;
                    }
                }
            }
            System.out.println(minMin);
        }
    }
    private static void _6B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            Arrays.sort(a);
            int min = a[0];
            int need = 0;
            for (int i1 : a) {
                need += i1 - min;
            }
            System.out.println(need);
        }
    }
    private static void _6A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String s = bi.readLine();
            if(s.length() < 3) System.out.println("NO");
            else {
                int sum1 = Integer.parseInt(s.substring(0, 1)) + Integer.parseInt(s.substring(1, 2)) + Integer.parseInt(s.substring(2, 3));
                int sum2 = Integer.parseInt(s.substring(s.length()-3, s.length()-2)) + Integer.parseInt(s.substring(s.length()-2, s.length()-1)) + Integer.parseInt(s.substring(s.length()-1));
                System.out.println(sum1 == sum2 ? "YES" : "NO");
            }
        }
    }
    private static void _5B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String s = bi.readLine();
            boolean flag = false;
            boolean same = true;
            HashMap<String, ArrayList<Integer>> pairs = new HashMap<>();
            ArrayList<Character> list = new ArrayList<>();
            for (int j = 0; j < s.length(); j++) {
                String c = s.substring(j, j + 1);
                pairs.putIfAbsent(c, new ArrayList<>());
                pairs.get(c).add(j);
                if(!list.contains(s.charAt(j))) list.add(s.charAt(j));
                if(j < s.length() - 1){
                    if(s.charAt(j) == s.charAt(j+1)) flag = true;
                    else same = false;
                }
            }
            if(same) System.out.println("YES");
            else if(flag) System.out.println("NO");
            else {
                for(Map.Entry<String, ArrayList<Integer>> entry : pairs.entrySet()) {
                    if(entry.getValue().size() >= 2) {
                        ArrayList<Integer> indexes = entry.getValue();
                        for (int j = 0; j < indexes.size(); j++) {
                            int count = 0;
                            boolean[] chars = new boolean[26];
                            for (int k = j+1; k < indexes.size(); k++) {
                                boolean[] chars2 = countDistinct(s.substring(indexes.get(k-1), indexes.get(k)));
                                for (int l = 0; l < 26; l++) {
                                    if(!chars[l] && chars2[l]) {
                                        count++;
                                        chars[l] = true;
                                    }
                                }
                                if(list.size() != count){
                                    flag = true;
                                    break;
                                }
                            }
                            if(flag) break;
                        }
                    }
                    if(flag) break;
                }
                System.out.println(flag ? "NO" : "YES");
            }
        }
    }
    private static boolean[] countDistinct(String s) {
        boolean[] chars = new boolean[26];
        for (int l = 0; l < s.length(); l++) {
            char ch = s.charAt(l);
            if (ch >= 97 && ch <= 122) chars[ch - 'a'] = true;
        }
        int count = 0;
        for (boolean aChar : chars) if (aChar) count++;
        return chars;
    }
    private static void _5A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String s = bi.readLine();
            int sum = 0;
            for (int j = 0; j < s.length(); j++) {
                sum += s.charAt(j) - 'a' + 1;
            }
            if(s.length() == 1) {
                System.out.println("Bob  " + sum);
            }else if(s.length() % 2 == 0){
                System.out.println("Alice " + sum);
            }else {
                int worst = Math.min(s.charAt(0) - 'a' + 1, s.charAt(s.length() - 1) - 'a' + 1);
                int best = Math.max(s.charAt(0) - 'a' + 1, s.charAt(s.length() - 1) - 'a' + 1);
                System.out.println("Alice " + (sum - worst - best + best - worst));
            }
        }
    }
    private static void _4C() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            int equal = 0;
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            boolean previousPairs = false;
            for (int j = 0; j < n; j++) {
                if(j > 0){
                    if(a[j] == a[j-1]) {
                        int pairs = 0;
                        while(j < n && a[j] == a[j-1]){
                            j++;
                            pairs++;
                        }
                        j--;
                        if(pairs > 0 && previousPairs){
                            pairs--;
                        }
                        previousPairs = true;
                        pairs = (pairs+(pairs % 2))/2;
                        equal += pairs;
                        

                        

                        

                        

                        

                        

                        

                    }else previousPairs = false;
                }
            }
            System.out.println(equal);
            

            

            

        }
    }
    private static void _4B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String original = bi.readLine();
            int As = 0, Bs = 0;
            boolean flag = false;
            for (int j = 0; j < original.length(); j++) {
                char c = original.charAt(j);
                if(c == 'A'){
                    As++;
                } else if(c == 'B'){
                    Bs++;
                }
                if(Bs > As) {
                    flag = true;
                }
            }
            if(original.startsWith("A") && original.endsWith("B") && !flag && (As+Bs == original.length()) && (As >= Bs)){
                System.out.println("YES");
            }else {
                System.out.println("NO");
            }
        }
    }
    private static void _4A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            int moves = 0;
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
                moves += a[j] - 1;
                

                

                

                

                

                

            }
            System.out.println(moves % 2 == 1 ? "errorgorn" : "maomao90");
        }
    }
    private static void _3F() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(as[j]);
            }
            int[] sumsL = new int[n];
            sumsL[0] = arr[0];
            for (int j = 1; j < n; j++) {
                sumsL[j] = arr[j] + sumsL[j - 1];
            }
            int[] sumsR = new int[n];
            sumsR[0] = arr[n - 1];
            for (int j = n-2; j >= 0; j--) {
                sumsR[(n-1) - j] = arr[j] + sumsR[(n-1) - j - 1];
            }
            int candies = 0;
            ArrayList<Integer> sumsRlist = new ArrayList<>();
            for (int integer : sumsR) sumsRlist.add(integer);
            for (int j = n-1; j >= 0; j--) {
                int leftInRight = Collections.binarySearch(sumsRlist, sumsL[j]);
                if(leftInRight > -1){
                    if(leftInRight + j + 2 <= n) {
                        candies = leftInRight + j + 2;
                        break;
                    }
                }
            }
            System.out.println(candies);
        }
    }
    private static void _3E() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            double[] starts = new double[11];
            double[] ends = new double[11];
            HashMap<String, Double> freq = new HashMap<>();
            for (int j = 0; j < n; j++) {
                String s = bi.readLine();
                freq.put(s, freq.getOrDefault(s, 0d) + 1);
                starts[s.charAt(0) - 'a']++;
                ends[s.charAt(1) - 'a']++;
            }
            double pairs = 0;
            for (int j = 0; j < 11; j++) {
                pairs += (starts[j] * (starts[j] - 1) / 2.0);
                pairs += (ends[j] * (ends[j] - 1) / 2.0);
            }
            double repeats = 0;
            for (String s : freq.keySet()) {
                if(freq.get(s) > 1){
                    repeats += freq.get(s) * (freq.get(s) - 1d);
                }
            }
            pairs -= repeats;
            DecimalFormat format = new DecimalFormat("0.#");
            System.out.println(format.format(pairs));
        }
    }
    private static void _3D() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String str = bi.readLine();
            String[] a = str.split("W");
            boolean flag = false;
            for (String s : a) {
                if(s.length() > 0 && (!s.contains("B") || !s.contains("R"))) {
                    flag = true;
                    break;
                }
            }
            System.out.println(flag ? "NO" : "YES");
        }
    }
    private static void _3C() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] arr = new int[n];
            int evenShouldBe = 0;
            int oddShouldBe = 0;
            boolean YES = true;
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(as[j]);
                if(j == 0) evenShouldBe = arr[j] % 2;
                if(j == 1) oddShouldBe = arr[j] % 2;
                if(j > 1){
                    if(j % 2 == 0 && arr[j] % 2 != evenShouldBe) {
                        YES = false;
                        break;
                    }
                    else if(j % 2 == 1 && arr[j] % 2 != oddShouldBe) {
                        YES = false;
                        break;
                    }
                }
            }
            if(YES) System.out.println("YES");
            else System.out.println("NO");
        }
    }
    private static void _3B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            HashMap<Integer, Integer> map = new HashMap<>();
            String[] as = bi.readLine().split(" ");
            int val = -1;
            for (int j = 0; j < n; j++) {
                map.put(Integer.parseInt(as[j]), map.getOrDefault(Integer.parseInt(as[j]), 0) + 1);
                if(map.get(Integer.parseInt(as[j])) == 3) {
                    val = Integer.parseInt(as[j]);
                    break;
                }
            }
            System.out.println(val);
        }
    }
    private static void _3A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            if(n <= 1399) System.out.println("Division 4");
            else if(n <= 1599) System.out.println("Division 3");
            else if(n <= 1899) System.out.println("Division 2");
            else System.out.println("Division 1");
        }
    }
    private static void _2B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nm = bi.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            Arrays.sort(a);
            if(n > m) {
                System.out.println("NO");
                continue;
            }
            int peopleAdded = 0;
            int earliestPersonPos = 0, earliestPersonSpace = 0;
            int lastPersonPos = m-1, lastPersonSpace = 0;
            boolean earlyPersonNow = true;
            for (int pos : a) {
                if(peopleAdded > 0 &&
                        ((lastPersonPos - earliestPersonPos - 1) < Math.max(earliestPersonSpace, lastPersonSpace)
                        || lastPersonPos <= earliestPersonPos)) {
                    break;
                }
                if(earlyPersonNow) {
                    if(peopleAdded == -1) {
                        earliestPersonPos = 0;
                        earliestPersonSpace = pos*2;
                    }else {
                        earliestPersonPos += Math.max(pos, earliestPersonSpace) + 1;
                        earliestPersonSpace = pos;
                    }


                } else {
                    if(peopleAdded == -1) {
                        lastPersonPos = m-1;
                        lastPersonSpace = pos*2;
                    } else {
                        lastPersonPos -= Math.max(lastPersonSpace, pos) + 1;
                        lastPersonSpace = pos;
                    }


                }
                if(lastPersonPos > m - 1 || earliestPersonPos < 0) break;
                peopleAdded++;
                earlyPersonNow = !earlyPersonNow;
            }
            System.out.println(peopleAdded == n ? "YES" : "NO");
        }
    }
    private static void _2A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nm = bi.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            if(n == m) System.out.println((n-1)+(m-1));
            else if(Math.abs(n-m) == 1){
                System.out.println((n-1)+(m-1));
            }
            else if(n == 1 || m == 1) System.out.println(-1);
            else if(Math.abs(n-m) > 1){
                int diff = Math.abs(n - m);
                if(diff % 2 == 1) diff--;
                System.out.println((n-1)+(m-1) + diff);
            }
        }
    }
    private static void _B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nk = bi.readLine().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);
            String str = bi.readLine();
            for (int j = 1; j < k; j++) {
                StringBuilder newString = new StringBuilder();
                if(j % 2 == 1){
                    newString.append(str.substring(0, 1));
                    for (int s = 1; s < str.length(); s++) {
                        newString.append(1 - Integer.parseInt(str.substring(s, s + 1)));
                    }
                } else {
                    for (int s = 0; s < str.length() - 1; s++) {
                        newString.append(1 - Integer.parseInt(str.substring(s, s + 1)));
                    }
                    newString.append(str.substring(str.length() - 1));
                }
                str = String.valueOf(newString);
            }
            System.out.println(str);
        }
    }
    private static void _A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nrb = bi.readLine().split(" ");
            int n = Integer.parseInt(nrb[0]);
            int r = Integer.parseInt(nrb[1]);
            int b = Integer.parseInt(nrb[2]);
            int largestStreak = (int) ((r - b)/(b + 1.0)) + 1;
            StringBuilder ans = new StringBuilder();
            while(ans.length() < n && r > 0 && b > 0) {
                for (int j = 0; j < largestStreak; j++) {
                    ans.append("R");
                }
                r -= largestStreak;
                ans.append("B");
                b--;
                largestStreak = (int) ((r - b)/(b + 1.0)) + 1;
            }
            for (int j = 0; j < r; j++) {
                ans.append("R");
            }
            System.out.println(ans);
        }
    }
}
