import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class id33 {
    public static void main(String[] args) throws IOException {






        id0();
    }
    private static void id0() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int tt = 0; tt < t; tt++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            long pairs = 0;
            HashMap<Integer, Integer> id21 = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int a = Integer.parseInt(as[i]);
                pairs += id21.getOrDefault(a - i, 0);
                id21.put(a - i, id21.getOrDefault(a - i, 0) + 1);
            }












            System.out.println(pairs);
        }
    }
    private static void id10() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int tt = 0; tt < t; tt++) {
            String[] nx = bi.readLine().split(" ");
            int n = Integer.parseInt(nx[0]);
            int x = Integer.parseInt(nx[1]);
            String[] as = bi.readLine().split(" ");
            int odd = 0, even = 0;
            for (int i = 0; i < n; i++) {
                int a = Integer.parseInt(as[i]);
                if (a % 2 == 0) even++;
                else odd++;
            }
            if (odd % 2 == 0) odd--;
            if(odd < 0 || even < x - odd) System.out.println("No");
            else if (x % 2 == 1) System.out.println("Yes");
            else System.out.println(even > 0 ? "Yes" : "No");
        }
    }
    private static void id44() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(as[i]);
        int pileCount = Arrays.stream(a).sum();
        int[] piles = new int[pileCount + 1];
        int index = 1;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i]; j++) {
                if(index == pileCount + 1) break;
                piles[index++] = i+1;
            }
        }
        int m = Integer.parseInt(bi.readLine());
        String[] qs = bi.readLine().split(" ");
        for (int i = 0; i < m; i++) {
            int q = Integer.parseInt(qs[i]);
            System.out.println(piles[q]);
        }
    }
    private static void id13() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        int id54 = 0;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(as[i]);
            if(a[i] == 1) id54++;
        }
        if(n == 1) {
            System.out.println(1 - id54);
            return;
        }else if (id54 == n) {
            System.out.println(n - 1);
            return;
        }
        int max = id54;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int ones = 0, zeros = 0;
                for (int k = i; k <= j; k++) {
                    if(a[k] == 1) ones++;
                    else zeros++;
                }
                if(zeros > ones) {
                    max = Math.max(max, id54 + zeros - ones);
                }
            }
        }
        System.out.println(max);
    }
    private static void id1() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        boolean allZero = true;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(as[i]);
            if(a[i] != 0) allZero = false;
        }
        if(allZero) {
            System.out.println((n-1)*(n-2)/2);
            return;
        }
        int[] sums = new int[n];
        int negPos = 0;
        sums[0] = a[0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i-1] + a[i];
            if(sums[i-1] < 0 || a[i] < 0) negPos++;
        }
        double neededSum = sums[n-1] / 3.0;


        if(neededSum % 1 != 0 || n < 3) System.out.println(0);
        else {
            ArrayList<Integer> id8 = new ArrayList<>();
            ArrayList<Integer> id50 = new ArrayList<>();
            int needed = (int) neededSum;
            for (int i = 0; i < n; i++) {
                if(sums[i] == needed){
                    id8.add(i);
                } else if(sums[i] == needed*2){
                    id50.add(i);
                }
            }




            int ways = 0;
            for (Integer first : id8) {
                for (Integer second : id50) {
                    if(first < second){
                        ways++;
                    }
                }
            }
            System.out.println(ways + negPos);
        }
    }
    public static void id41() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        HashMap<Integer, Integer> qp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] pqs = bi.readLine().split(" ");
            qp.put(Integer.parseInt(pqs[1]), Integer.parseInt(pqs[0]));
        }
        Map<Integer, Integer> treeMap = new TreeMap(qp);
        int[] prices = new int[n];
        int[] qualities = new int[n];
        int c = 0;
        for (Integer quality : treeMap.keySet()) {
            qualities[c] = quality;
            prices[c] = treeMap.get(quality);
            c++;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if(qualities[i] > qualities[j]){
                    if(prices[i] < prices[j]){
                        System.out.println("Happy Alex");
                        return;
                    }
                }
            }
        }
        System.out.println("Poor Alex");
    }
    public static void id17() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(as[i]);
        int id52 = 0, starts = 0, stops = 0;
        for (int i = 0; i < n - 1; i++) {
            if(a[i] > a[i+1]){
                if(id52 == 1) {
                    System.out.println("no");
                    return;
                }
                stops = i + 1;
                while(stops < n - 1 && a[stops] > a[stops + 1]) stops++;
                starts = i;
                i = stops;
                id52++;
            }
        }
        if(starts != 0 && a[stops] < a[starts-1]){
            System.out.println("no");
        }else if(stops != n-1 && a[stops+1] < a[starts]){
            System.out.println("no");
        }else{
            System.out.println("yes");
            System.out.println((starts+1) + " " + (stops+1));
        }
    }
    public static void id26() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String numStr = bi.readLine();
        int num = Integer.parseInt(numStr);
        double sqrt = Math.sqrt(num);
        if(sqrt == (int) sqrt) System.out.println((int) sqrt);
        else {
            int sum = 0;
            for (int i = 0; i < numStr.length(); i++) {
                sum += Integer.parseInt(numStr.substring(i, i+1));
            }
            System.out.println(sum);
            System.out.println((int) Math.sqrt(sum));
        }
    }
    public static void id24() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        while(bi.readLine() != null) System.out.println("NO");
    }
    public static void id57() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nt = bi.readLine().split(" ");
        int n = Integer.parseInt(nt[0]);
        int t = Integer.parseInt(nt[1]);
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(as[i]);
        int books = 0;
        int end = 0;
        int timeRead = 0;
        for (int i = 0; i < n; i++) {
            while(end < n && timeRead + a[end] <= t){
                timeRead += a[end];
                end++;
            }
            books = Math.max(books, end - i);
            timeRead -= a[i];
        }
        System.out.println(books);
    }
    public static void id27() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] id34 = bi.readLine().split(" ");
            int[] factors = new int[n];
            for (int j = 0; j < n; j++) factors[j] = Integer.parseInt(id34[j]);
            Arrays.sort(factors);
            long val1 = (long) factors[0] * factors[n-1];
            boolean wrongFactors = false;

            if((n % 2 != 0 && val1 != (long) factors[n/2] * factors[n/2])
                || (n % 2 == 0 && val1 != (long) factors[1] * factors[n-2])) {
                System.out.println(-1);
            } else {
                boolean invalidFactors = false;
                for (long factor : factors) {
                    if (val1 % factor != 0) {
                        invalidFactors = true;
                        break;
                    }
                }
                if(invalidFactors) System.out.println(-1);
                else{
                    for (long j = 2; j <= Math.sqrt(val1); j++) {
                        if (val1 % j == 0) {
                            boolean newFactor = true;
                            for (long factor : factors) {
                                if (j == factor) {
                                    newFactor = false;
                                    break;
                                }
                            }
                            if(newFactor) {
                                wrongFactors = true;
                                break;
                            }
                        }
                    }
                    System.out.println(wrongFactors ? -1 : val1);
                }
            }
        }
    }
    public static void id32() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] numsStr = bi.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = Integer.parseInt(numsStr[i]);
        Arrays.sort(nums);
        int gcd = 1;
        boolean allEven = false;
        do{
            allEven = true;
            for (int num : nums) {
                if (num % 2 != 0) allEven = false;
            }
            if(allEven){
                gcd *= 2;
                for (int i = 0; i < nums.length; i++) {
                    nums[i] /= 2;
                }
            }
        }while(allEven);
        System.out.println(Arrays.toString(nums));
    }
    public static void id58() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[][] grid = new String[n][n];
        for (int i = 0; i < n; i++) grid[i] = bi.readLine().split("");
        if(n < 2) System.out.println(0);
        else {
            int crosses = 0;
            for (int i = 1; i < grid.length - 1; i++) {
                for (int j = 1; j < grid[0].length - 1; j++) {
                    if(grid[i-1][j-1].equals("X") &&
                            grid[i-1][j+1].equals("X") &&
                            grid[i][j].equals("X") &&
                            grid[i+1][j-1].equals("X") &&
                            grid[i+1][j+1].equals("X")) crosses++;
                }
            }
            System.out.println(crosses);
        }
    }
    public static void id49() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(bi.readLine());
        if(n < 3) System.out.println(n);
        else if(n % 2 == 0) System.out.println((n-1)*(n-3)*(n % 3 == 0 ? n-2 : n));
        else System.out.println(n*(n-1)*(n-2));
    }
    public static void id35() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = Long.parseLong(as[i]);
        long max = Long.MIN_VALUE;
        for (long l : a) if (l > max) max = l;
        long sum = Arrays.stream(a).sum();
        if(sum % 2 == 0 && (sum-max) >= max) System.out.println("YES");
        else System.out.println("NO");
    }
    public static void id3() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] xyxy = bi.readLine().split(" ");
            System.out.println((Long.parseLong(xyxy[2])-Long.parseLong(xyxy[0]))*(Long.parseLong(xyxy[3])-Long.parseLong(xyxy[1]))+1);
        }
    }
    public static void id29() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] ns = bi.readLine().split(" ");
            String stringN = ns[0];
            long n = Long.parseLong(ns[0]);
            int s = Integer.parseInt(ns[1]);
            int currentSum = 0;
            for (int j = 0; j < stringN.length(); j++) {
                currentSum += Integer.parseInt(stringN.substring(j, j+1));
            }
            if(currentSum > s){
                int newSum = currentSum;
                long newNum = n;
                String newNums = stringN;
                int moves = 0;
                int id36 = newNums.length() - 1;
                while(newSum > s && id36 >= 0){
                    int lastDigit = Integer.parseInt(newNums.substring(id36, id36+1));
                    id36--;
                    moves++;
                    newNum += (long) (Math.pow(10, moves) - lastDigit*Math.pow(10, moves-1));
                    newNums = String.valueOf(newNum);
                    newSum = 0;
                    for (int j = 0; j < stringN.length(); j++) {
                        newSum += Integer.parseInt(newNums.substring(j, j+1));
                    }
                }
                System.out.println(newNum - n);
            }else System.out.println(0);
        }
    }
    public static void id16() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        double k = Double.parseDouble(bi.readLine());
        String[] base = {"c", "o", "d", "e", "f", "o", "r", "c", "e", "s"};
        StringBuilder str = new StringBuilder("codeforces");
        if(k == 1) {
            System.out.println(str);
            return;
        }
        double kDone = 1;
        int loops = 0;
        int index = 0;
        while(kDone < k){
            String val = base[index];
            if(index != 5 && index != 7 && index != 8){
                str.insert(str.indexOf(val), val);
            }else{
                StringBuilder before = new StringBuilder();
                for (int i = 0; i < loops+2; i++) before.append(val);
                int offset = str.indexOf(String.valueOf(before)) + before.length();
                str.insert(str.indexOf(val, offset), val);
            }
            index++;
            kDone *= (loops + 2.0)/(loops + 1.0);
            

            if(index == base.length) {
                loops++;
                index = 0;
            }
        }
        System.out.println(kDone);
        System.out.println(str);
    }
    public static void id59() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        ArrayList<String[]> game = new ArrayList<>();
        HashMap<String, Integer> scores = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] line = bi.readLine().split(" ");
            game.add(line);
            String name = line[0];
            int score = Integer.parseInt(line[1]);
            scores.put(name, scores.getOrDefault(name, 0) + score);
        }
        

        int maxScore = Integer.MIN_VALUE;
        for(String player : scores.keySet()) {
            if(scores.get(player) > maxScore){
                maxScore = scores.get(player);
            }
        }
        

        for(String player : scores.keySet()) {
            if(scores.get(player) < maxScore){
                for (int i = 0; i < game.size(); i++) {
                    if(game.get(i)[0].equals(player)) {
                        game.remove(i);
                        i--;
                    }
                }
            }
        }
        HashMap<String, Integer> id31 = new HashMap<>();
        for(String[] line : game){
            String name = line[0];
            int score = Integer.parseInt(line[1]);
            id31.put(name, id31.getOrDefault(name, 0) + score);
            if(id31.get(name) >= maxScore) {
                System.out.println(name);
                return;
            }
        }
    }
    public static void id30() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        long nLong = Long.parseLong(bi.readLine());
        int n = (int) nLong;
        String[] bs = bi.readLine().split(" ");
        long[] b = new long[n];
        for (int i = 0; i < n; i++) b[i] = Long.parseLong(bs[i]);
        Arrays.sort(b);
        if(n == 2){
            System.out.println((b[1] - b[0]) + " " + 1);
        }else if(b[n-1] == b[0]){
            System.out.println(0 + " " + nLong*(nLong-1)/2);
        } else{
            int minIndex = 1, maxIndex = n - 2;
            long mins = 1, maxes = 1;
            while(b[0] == b[minIndex]) {
                minIndex++;
                mins++;
            }
            while(b[n-1] == b[maxIndex]) {
                maxIndex--;
                maxes++;
            }
            System.out.println((b[n-1] - b[0]) + " " + mins*maxes);
        }
    }
    public static void id56() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nk = bi.readLine().split(" ");
            int n = Integer.parseInt(nk[0]), k = Integer.parseInt(nk[1]);
            if(k < n) {
                System.out.println(k);
                continue;
            }
            int num = 1;
            int id9 = n - 1;
            int skips = k/id9;
            num += skips*n;
            k = k % id9;
            System.out.println(k);
            num += (k*(k+1)/2) - k;
            System.out.println(num - (k == 0 ? 2 : 0));
            

        }
    }
    public static void id45() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = bi.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        String[] hs = bi.readLine().split(" ");
        int[] h = new int[n];
        for (int i = 0; i < n; i++) h[i] = Integer.parseInt(hs[i]);
        int prev = 0;
        for (int i = 0; i < k; i++) prev += h[i];
        int min = prev, minIndex = 0;
        for (int i = 1; i <= n - k; i++) {
            int sum = prev + h[i+k-1] - h[i - 1];
            if(sum < min){
                min = sum;
                minIndex = i;
            }
            prev = sum;
        }
        System.out.println(minIndex+1);
    }
    public static void id2() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int a = Integer.parseInt(bi.readLine());
            int exterior = 180 - a;
            System.out.println(360 % exterior == 0 ? "YES" : "NO");
        }
    }
    public static void id18() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        int M, C;
        M = C = 0;
        for (int i = 0; i < n; i++) {
            String[] mc = bi.readLine().split(" ");
            int m = Integer.parseInt(mc[0]);
            int c = Integer.parseInt(mc[1]);
            if(m > c) M++;
            else if (m < c) C++;
        }
        System.out.println(M > C ? "Mishka" : (M < C ? "Chris" : "Friendship is magic!^^"));
    }
    public static void id51() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String s = bi.readLine();
            boolean sus = false;
            for (int j = 65; j < 65+26; j++) {
                if(s.contains(String.valueOf((char) j))){
                    int first = s.indexOf(String.valueOf((char) j));
                    int last = s.lastIndexOf(String.valueOf((char) j));
                    for (int k = first+1; k < last; k++) {
                        if(s.charAt(k) != (char) j){
                           sus = true;
                           break;
                        }
                    }
                }
                if(sus){
                    break;
                }
            }
            System.out.println(sus ? "NO" : "YES");
        }
    }
    public static void id7() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] ab = bi.readLine().split(" ");
            double a = Integer.parseInt(ab[0]);
            double b = Integer.parseInt(ab[1]);
            double min = Math.min(a, b);
            double max = Math.max(a, b);
            if(max / min >= 2) System.out.println((int) (max*max));
            else System.out.println((int) (min*min*4));
        }
    }
    public static void id40() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] valss = bi.readLine().split(" ");
        int[] vals = new int[8];
        for (int i = 0; i < 8; i++) {
            vals[i] = Integer.parseInt(valss[i]);
        }
        System.out.println(Math.min((vals[1]*vals[2])/vals[6],
                Math.min(vals[3]*vals[4], vals[5]/vals[7]))/vals[0]);
    }
    public static void id46() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] Ts = bi.readLine().split(" ");
        int[] T = new int[n];
        for (int i = 0; i < n; i++) {
            T[i] = Integer.parseInt(Ts[i]);
        }
        ArrayList<Integer> ones = new ArrayList<>();
        ArrayList<Integer> twos = new ArrayList<>();
        ArrayList<Integer> threes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int t = T[i];
            if(t == 1) ones.add(i+1);
            if(t == 2) twos.add(i+1);
            if(t == 3) threes.add(i+1);
        }
        int teams = Math.min(ones.size(), Math.min(twos.size(), threes.size()));
        System.out.println(teams);
        for (int i = 0; i < teams; i++) {
            System.out.println(ones.get(i) + " " + twos.get(i) + " " + threes.get(i));
        }
    }
    public static void id60() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(as[i]);
        }
        Arrays.sort(a);
        int max = a[n-1];
        int S = 0;
        for (int i = 0; i < n-1; i++) S += (max - a[i]);
        System.out.println(S);
    }
    public static void id15() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            int even, odd, misplaced;
            even = odd = misplaced = 0;
            for (int j = 0; j < n; j++) {
               int val = Integer.parseInt(as[j]);
               a[j] = val;
               if(val % 2 == 0) even++;
               else odd++;

               if(j % 2 != val % 2) misplaced++;
            }

            if((n % 2 == 0 && even != odd) || (n % 2 == 1 && even - 1 != odd)){
                System.out.println("-1");
            }else {
                System.out.println(misplaced/2);
            }
        }
    }
    public static void id25() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = bi.readLine().split(" ");
        int n = Integer.parseInt(nk[0]), k = Integer.parseInt(nk[1]);
        String[] y = bi.readLine().split(" ");
        int available = 0;
        for (String js : y) if (5 - Integer.parseInt(js) >= k) available++;
        System.out.println(available/3);
    }
    public static void id37() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            if((n/2 % 2) == 1) System.out.println("NO");
            else {
                System.out.println("YES");
                for (int j = 1; j <= n/2; j++) {
                    System.out.print((j*2) + " ");
                }
                for (int j = 1; j < n/2; j++) {
                    System.out.print((j*2 - 1) + " ");
                }
                System.out.println((n - 1 + n/2) + " ");
            }
        }
    }
    public static void id22() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String b = bi.readLine();
        if((Integer.parseInt(b)) >= 0) System.out.println(b);
        else {
            int b1 = Integer.parseInt(b.substring(0, b.length() - 1));
            int b2 = Integer.parseInt(b.substring(0, b.length() - 2) + b.substring(b.length() - 1));
            System.out.println(Math.max(b1, b2));
        }
    }
    public static void id19() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(bi.readLine());
        String s = Integer.toBinaryString(x);
        int bacteria = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '1') bacteria++;
        }
        System.out.println(bacteria);
    }
    public static void id38() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String s = bi.readLine();
            StringBuilder out = new StringBuilder();
            out.append(s.charAt(0));
            for (int j = 1; j < s.length()-1; j += 2) out.append(s.charAt(j));
            out.append(s.charAt(s.length()-1));
            System.out.println(out);
        }
    }
    public static void id14() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] xs = bi.readLine().split(" ");
        int[] x = new int[3];
        for (int i = 0; i < 3; i++) x[i] = Integer.parseInt(xs[i]);
        Arrays.sort(x);
        System.out.println(x[2] - x[0]);
    }
    public static void id39() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        if(n % 2 == 0){
            System.out.println(4 + " " + (n - 4));
        }else{
            System.out.println(9 + " " + (n - 9));
        }
    }
    public static void id4() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            int k = 0, multiplier = 1;
            StringBuilder str = new StringBuilder();
            while (n != 0) {
                if (n % 10 != 0) {
                    str.append((n % 10) * multiplier).append(" ");
                    k++;
                }
                multiplier *= 10;
                n /= 10;
            }
            System.out.println(k);
            System.out.println(str);
        }
    }
    public static void id43() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] str = bi.readLine().split(" ");
        int[] nums = new int[4];
        for (int i = 0; i < 4; i++) {
            nums[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(nums);
        int sum = nums[3];
        System.out.println((sum - nums[0]) + " " + (sum - nums[1]) + " " + (sum - nums[2]));
    }
    public static void id42() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] kr = bi.readLine().split(" ");
        int k = Integer.parseInt(kr[0]);
        int r = Integer.parseInt(kr[1]);
        int remainder = k % 10;
        int count;
        for (count = 1; count < 10; count++) {
            if((count * remainder) % 10 == r || (count * remainder) % 10 == 0) break;
        }
        System.out.println(count);
    }
    public static void id47() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] ab = bi.readLine().split(" ");
        int a = Integer.parseInt(ab[0]);
        int b = Integer.parseInt(ab[1]);
        System.out.println(Math.min(a, b) + " " + (Math.max(a, b)-Math.min(a, b))/2);
    }
    public static void id23() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = bi.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int min = Integer.parseInt(nk[1]);
        int problems = 0;
        while(min <= 240 && problems <= n){
            min += (problems+1)*5;
            problems++;
        }
        System.out.println(problems-1);
    }
    public static void id53() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nk = bi.readLine().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);
            String[] as = bi.readLine().split(" ");
            String[] bs = bi.readLine().split(" ");
            int[] a = new int[n];
            int[] b = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(as[j]);
                b[j] = Integer.parseInt(bs[j]);
            }
            Arrays.sort(a);
            Arrays.sort(b);
            int minA, maxB;
            minA = maxB = 0;
            for (int j = 0; j < k; j++) {
                if(a[j] < b[n - j - 1]) {
                    minA += a[j];
                    maxB += b[n - j - 1];
                }
            }
            System.out.println(Math.max(Arrays.stream(a).sum() + (maxB - minA), Arrays.stream(a).sum()));
        }
    }
    public static void id12() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] ab = bi.readLine().split(" ");
            int diff = Math.abs(Integer.parseInt(ab[1]) - Integer.parseInt(ab[0]));
            System.out.println(diff / 10 + ((diff % 10 == 0) ? 0 : 1));
        }
    }
    public static void id48() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] xyn = bi.readLine().split(" ");
            int x = Integer.parseInt(xyn[0]);
            int y = Integer.parseInt(xyn[1]);
            int n = Integer.parseInt(xyn[2]);
            int remainder = n % x;
            if(remainder > y){
                System.out.println(n - (remainder - y));
            }else if(remainder < y){
                System.out.println(n - x + (y - remainder));
            }else{
                System.out.println(n);
            }
        }
    }
    public static void id28() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int len = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] a = new int[len];
            for (int j = 0; j < len; j++) {
                a[j] = Integer.parseInt(as[j]);
            }
            Arrays.sort(a);
            boolean yes = true;
            for (int j = 0; j < len - 1; j++) {
                if (a[j + 1] - a[j] >= 2) {
                    yes = false;
                    break;
                }
            }
            System.out.println(yes ? "YES" : "NO");
        }
    }
    public static void id6() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = bi.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        StringBuilder grid = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringBuilder row = new StringBuilder("");
            for (int j = 0; j < m; j++) {
                if(i % 2 == 0) row.append("
                else {
                    if((i - 1 % 4) % 4 == 0){
                        if(j == m - 1) row.append("
                        else row.append(".");
                    }else {
                        if(j == 0) row.append("
                        else row.append(".");
                    }
                }
            }
            row.append("\n");
            grid.append(row);
        }
        System.out.println(grid);
    }
    public static void _427A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] events = bi.readLine().split(" ");
        int police = 0, crimes = 0;
        for (String event : events) {
            int val = Integer.parseInt(event);
            if(val > 0) police += val;
            if(val < 0){
                if(police < Math.abs(val)) crimes += Math.abs(val) - police;
                police = Math.max(0, police - Math.abs(val));
            }
        }
        System.out.println(crimes);
    }
    public static void _451A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = bi.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int intersections = n*m;
        int lossOnNext = n+m-1;
        int next = 1;
        while (intersections > 0){
            intersections -= lossOnNext;
            lossOnNext -= 2;
            next ^= 1;
        }
        System.out.println(next == 0 ? "Akshat" : "Malvika");
    }
    public static void _1343A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int test = 0; test < t; test++) {
            long n = Long.parseLong(bi.readLine());
            int k;
            for (k = 2; k <= 30; k++) {
                if(n % (Math.pow(2, k) - 1) == 0) break;
            }
            System.out.println(n/((int)Math.pow(2, k) - 1));
        }
    }
    public static void _155A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] scores = bi.readLine().split(" ");
        int max = Integer.parseInt(scores[0]), min = Integer.parseInt(scores[0]);
        int amazing = 0;
        for (int i = 1; i < scores.length; i++) {
            int score = Integer.parseInt(scores[i]);
            if(score > max){
                max = score;
                amazing++;
            }else if(score < min){
                min = score;
                amazing++;
            }
        }
        System.out.println(amazing);
    }
    public static void _339B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = bi.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int pos = 1;
        long time = 0;
        String[] a = bi.readLine().split(" ");
        for (int i = 0; i < m; i++) {
            int h = Integer.parseInt(a[i]);
            if(h > pos) time += h - pos;
            else if(h < pos) time += n - pos + h;
            pos = h;
        }
        System.out.println(time);
    }
    public static void _785A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int candles = Integer.parseInt(bi.readLine());
            if(candles < 3) System.out.println("0");
            else System.out.println((candles-1)/2);
        }
    }
    public static void _141A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String n1 = bi.readLine().toLowerCase();
        String n2 = bi.readLine().toLowerCase();
        String m = bi.readLine().toLowerCase();
        int[] names = new int[26];
        int[] mixed = new int[26];
        for (int i = 0; i < n1.length(); i++) {
            names[((int) n1.charAt(i))-97]++;
        }
        for (int i = 0; i < n2.length(); i++) {
            names[((int) n2.charAt(i))-97]++;
        }
        for (int i = 0; i < m.length(); i++) {
            mixed[((int) m.charAt(i))-97]++;
        }
        for (int i = 0; i < names.length; i++) {
            if(names[i] != mixed[i]){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    public static void id20() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        int[] denominations = {100, 20, 10, 5, 1};
        int bills = 0;
        for (int denomination : denominations) {
            while(n >= denomination) {
                n -= denomination;
                bills++;
            }
        }
        System.out.println(bills);
    }
    public static void id55() throws IOException {
        

        int[] ascii = new int[26];
        for (int i = 0; i < ascii.length; i++) ascii[i] = i+97;
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String ss = bi.readLine().toLowerCase();
        char[] chars = ss.toCharArray();
        int[] id5 = new int[n];
        for (int i = 0; i < n; i++) id5[i] = chars[i];
        ArrayList<Integer> arr = new ArrayList<>();
        for (int a : id5) arr.add(a);
        if(ss.length() < 26) System.out.println("NO");
        else {
            for (int i : ascii) {
                if(!arr.contains(i)) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");
        }

    }
    public static void id11() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        int[] home = new int[n];
        int[] guest = new int[n];
        for (int i = 0; i < n; i++) {
            String[] hg = bi.readLine().split(" ");
            home[i] = Integer.parseInt(hg[0]);
            guest[i] = Integer.parseInt(hg[1]);
        }
        int change = 0;
        for (int h : home) {
            for (int g : guest) {
                if(g == h) change++;
            }
        }
        System.out.println(change);
    }
}