import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.IntStream;

public class id12 {
    public static void main(String[] args) throws IOException {
        id29();
    }
    private static void id5() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            String[] nk = bi.readLine().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);
            String[] as = bi.readLine().split(" ");
            int[] a = new int[n];
            for (int j = 0; j < n; j++) a[j] = Integer.parseInt(as[j]);
            Arrays.sort(a);
            HashMap<Integer, Integer> freq = new HashMap<>();
            for (int j = 0; j < n; j++) {
                freq.put(a[j], freq.getOrDefault(Integer.parseInt(as[j]), 0) + 1);
            }
            int max = 0, current = 0;
            System.out.println(freq);
            for(int key : freq.keySet()) {

                if(freq.get(key) < k) {
                    if(current > max) max = current;
                    current = 0;
                } else {
                    current++;
                }
            }
            System.out.println(max);
        }
    }
    private static void id29() throws IOException {
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
    private static void id28() throws IOException {
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
    private static void id6() throws IOException {
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
    private static void id30() throws IOException {
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
    private static void id9() throws IOException {
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
    private static void id32() throws IOException {
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
    private static void id24() throws IOException {
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
    private static void id18() throws IOException {
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
    private static void id13() throws IOException {
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
    private static void id25() throws IOException {
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
    private static void id8() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(as[j]);
            }
            int[] id1 = new int[n];
            id1[0] = arr[0];
            for (int j = 1; j < n; j++) {
                id1[j] = arr[j] + id1[j - 1];
            }
            int[] id10 = new int[n];
            id10[0] = arr[n - 1];
            for (int j = n-2; j >= 0; j--) {
                id10[(n-1) - j] = arr[j] + id10[(n-1) - j - 1];
            }
            int candies = 0;
            ArrayList<Integer> id22 = new ArrayList<>();
            for (int integer : id10) id22.add(integer);
            for (int j = n-1; j >= 0; j--) {
                int id21 = Collections.binarySearch(id22, id1[j]);
                if(id21 > -1){
                    if(id21 + j + 2 <= n) {
                        candies = id21 + j + 2;
                        break;
                    }
                }
            }
            System.out.println(candies);
        }
    }
    private static void id26() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            int[] starts = new int[11];
            int[] ends = new int[11];
            String[] arr = new String[n];
            for (int j = 0; j < n; j++) {
                String s = bi.readLine();
                arr[j] = s;
                starts[s.charAt(0) - 'a']++;
                ends[s.charAt(1) - 'a']++;
            }
            int pairs = 0;
            for (int j = 0; j < 11; j++) {
                pairs += starts[j] * (starts[j] - 1) / 2;
                pairs += ends[j] * (ends[j] - 1) / 2;
            }
            Arrays.sort(arr);
            int id0 = 0;
            for (int j = 0; j < n - 1; j++) {
                if(arr[j].equals(arr[j+1])) {
                    int toAdd = 2;
                    int shift = 2;
                    while(j+shift < n && arr[j].equals(arr[j+shift])) {
                        shift++;
                        toAdd += Math.pow(2, shift-1);
                    }
                    id0 += toAdd;
                    j += shift - 1;
                }
            }
            if(id0 > 0) pairs -= id0;
            System.out.println(pairs);
        }
    }
    private static void id4() throws IOException {
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
    private static void id3() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] as = bi.readLine().split(" ");
            int[] arr = new int[n];
            int id23 = 0;
            int id17 = 0;
            boolean YES = true;
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(as[j]);
                if(j == 0) id23 = arr[j] % 2;
                if(j == 1) id17 = arr[j] % 2;
                if(j > 1){
                    if(j % 2 == 0 && arr[j] % 2 != id23) {
                        YES = false;
                        break;
                    }
                    else if(j % 2 == 1 && arr[j] % 2 != id17) {
                        YES = false;
                        break;
                    }
                }
            }
            if(YES) System.out.println("YES");
            else System.out.println("NO");
        }
    }
    private static void id16() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            int[] arr = new int[n];
            String[] as = bi.readLine().split(" ");
            for (int j = 0; j < n; j++) arr[j] = Integer.parseInt(as[j]);
            Arrays.sort(arr);
            if(n < 3) {
                System.out.println("-1");
                continue;
            }
            for (int j = 0; j < n-2; j++) {
                if(arr[j] == arr[j+2]) {
                    System.out.println(arr[j]);
                    break;
                }
                if(j == n-3) System.out.println("-1");
            }
        }
    }
    private static void id19() throws IOException {
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
    private static void id14() throws IOException {
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
            int id11 = 0, id15 = 0;
            int id7 = m-1, id27 = 0;
            boolean id2 = true;
            for (int pos : a) {
                if(peopleAdded > 0 &&
                        ((id7 - id11 - 1) < Math.max(id15, id27)
                        || id7 <= id11)) {
                    break;
                }
                if(id2) {
                    if(peopleAdded == -1) {
                        id11 = 0;
                        id15 = pos*2;
                    }else {
                        id11 += Math.max(pos, id15) + 1;
                        id15 = pos;
                    }


                } else {
                    if(peopleAdded == -1) {
                        id7 = m-1;
                        id27 = pos*2;
                    } else {
                        id7 -= Math.max(id27, pos) + 1;
                        id27 = pos;
                    }


                }
                if(id7 > m - 1 || id11 < 0) break;
                peopleAdded++;
                id2 = !id2;
            }
            System.out.println(peopleAdded == n ? "YES" : "NO");
        }
    }
    private static void id31() throws IOException {
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
            int id20 = (int) ((r - b)/(b + 1.0)) + 1;
            StringBuilder ans = new StringBuilder();
            while(ans.length() < n && r > 0 && b > 0) {
                for (int j = 0; j < id20; j++) {
                    ans.append("R");
                }
                r -= id20;
                ans.append("B");
                b--;
                id20 = (int) ((r - b)/(b + 1.0)) + 1;
            }
            for (int j = 0; j < r; j++) {
                ans.append("R");
            }
            System.out.println(ans);
        }
    }
}
