import java.util.*;
import java.io.*;

public class Main {

    public static class Solution {

        public String YoungPhysicist() {
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();

            int[] arr = new int[] { 0, 0, 0 };
            for (int i = 0; i < n; i++) {
                

                int a = input.nextInt();
                int b = input.nextInt();
                int c = input.nextInt();
                arr[0] += a;
                arr[1] += b;
                arr[2] += c;
            }
            input.close();
            return (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) ? "YES" : "NO";
        }

        public int BeautifulMatrix() {
            int[][] matrix = new int[5][5];
            Scanner input = new Scanner(System.in);
            int row = -1, col = -1;

            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    matrix[i][j] = input.nextInt();
                    if (matrix[i][j] == 1) {
                        input.close();
                        return Math.abs(i - 2) + Math.abs(j - 2);
                    }
                }
            }
            input.close();
            return row + col;
        }

        public String QueueAtTheSchool() {
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();
            int t = input.nextInt();
            input.nextLine();
            String queue = input.nextLine();
            char[] arr = queue.toCharArray();

            for (int k = 0; k < t; k++) {
                for (int i = 1; i < n; i++) {
                    if (arr[i] == 'B' && arr[i - 1] == 'G') {
                        arr[i] = 'G';
                        arr[i - 1] = 'B';
                    }
                }
            }

            input.close();
            return new String(arr);
        }

        public String Borze() {
            Scanner input = new Scanner(System.in);
            String str = input.nextLine();
            String sol = "";
            int n = str.length();

            for (int i = 0; i < n; i++) {
                String a = str.charAt(i) + "";
                String b = "";
                if (i < n - 1)
                    b = "" + str.charAt(i + 1);

                if (a.equals(".")) {
                    sol = sol + "0";
                } else if (a.equals("-")) {
                    i++;
                    if (b.equals(".")) {
                        sol = sol + "1";
                    } else if (b.equals("-")) {
                        sol = sol + "2";
                    }
                }
            }

            input.close();
            return sol;
        }

        public int BeautifulYear() {
            Scanner input = new Scanner(System.in);
            int year = input.nextInt();
            year++;
            while (!isUnique(year)) {
                year++;
            }

            input.close();
            return year;
        }

        public boolean isUnique(int num) {
            boolean unique = true;
            Set<Character> set = new HashSet<>();
            String str = num + "";
            for (int i = 0; i < str.length(); i++) {
                if (set.contains(str.charAt(i)))
                    return false;
                set.add(str.charAt(i));
            }
            return unique;
        }

        public String[][] lightsOut() {
            int sq = 3;
            int[][] input = new int[sq][sq];
            String[][] sol = new String[sq][sq];

            Scanner scanner = new Scanner(System.in);

            for (int i = 0; i < sq; i++) {
                for (int j = 0; j < sq; j++) {
                    sol[i][j] = "1";
                }
            }

            for (int i = 0; i < sq; i++) {
                for (int j = 0; j < sq; j++) {
                    input[i][j] = scanner.nextInt();

                    if (input[i][j] % 2 != 0) {
                        toggleAdj(sol, i, j);
                    }
                }
            }
            System.out.println("\n\n\n");
            for (int i = 0; i < sol.length; i++) {
                String a = sol[i][0];
                String b = sol[i][1];
                String c = sol[i][2];
                System.out.println(a + b + c);
            }
            scanner.close();
            return sol;
        }

        public void toggleAdj(String[][] sol, int row, int col) {
            if (row + 1 < sol.length) {
                if (sol[row + 1][col].equals("1")) {
                    sol[row + 1][col] = "0";
                } else {
                    sol[row + 1][col] = "1";
                }
            }

            if (row - 1 >= 0) {
                if (sol[row - 1][col].equals("1")) {
                    sol[row - 1][col] = "0";
                } else {
                    sol[row - 1][col] = "1";
                }
            }

            if (col + 1 < sol[0].length) {
                if (sol[row][col + 1].equals("1")) {
                    sol[row][col + 1] = "0";
                } else {
                    sol[row][col + 1] = "1";
                }
            }

            if (col - 1 >= 0) {
                if (sol[row][col - 1].equals("1")) {
                    sol[row][col - 1] = "0";
                } else {
                    sol[row][col - 1] = "1";
                }
            }
        }

        public String word() {
            Scanner scanner = new Scanner(System.in);
            String w = scanner.nextLine();
            int n = w.length();

            int a = (int) 'a';
            int z = (int) 'z';

            int count = 0;
            for (int i = 0; i < n; i++) {
                int curr = (int) w.charAt(i);
                if (curr >= a && curr <= z)
                    count++;
            }

            if (count >= n - count) {
                w = w.toLowerCase();
            } else {
                w = w.toUpperCase();
            }

            

            scanner.close();
            return w;
        }

        public String wordCapitalization() {
            Scanner scanner = new Scanner(System.in);
            String word = scanner.nextLine();
            char[] c = word.toCharArray();
            c[0] = ((word.charAt(0) + "").toUpperCase()).charAt(0);
            String sol = new String(c);
            scanner.close();
            return sol;
        }

        public String nearlyLuckyNumber() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            String s = n + "";
            int cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '4' || c == '7')
                    cnt++;
                if (cnt > 7)
                    return "NO";
            }
            scanner.close();
            return (cnt == 7 || cnt == 4) ? "YES" : "NO";
        }

        public int stonesOnTheTable() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            scanner.nextLine();
            String s = scanner.nextLine();
            int sol = removeStones(s);
            scanner.close();
            return sol;
        }

        public int removeStones(String s) {
            if (isValidStoneArrangement(s))
                return 0;

            int n = s.length();
            int min = n;
            for (int i = 0; i < n; i++) {
                int k = removeStones(removeChar(s, i));
                if (k < min)
                    min = k;
            }

            return min + 1;
        }

        public boolean isValidStoneArrangement(String s) {
            for (int i = 0; i < s.length() - 1; i++) {
                if (s.charAt(i) == s.charAt(i + 1))
                    return false;
            }

            return true;
        }

        public String removeChar(String s, int idx) {
            String nw = "";
            int n = s.length();

            for (int i = 0; i < n; i++) {
                if (i == idx)
                    continue;
                nw = nw + s.charAt(i);
            }
            return nw;
        }

        public String panoramixPrediction() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (!isPrime(m))
                return "NO";

            for (int i = n + 1; i < m; i++) {
                if (isPrime(i))
                    return "NO";
            }

            scanner.close();
            return "YES";
        }

        public boolean isPrime(int n) {

            for (int i = 2; i < n; i++) {
                float f = (float) n / (float) i;
                int r = (int) f;
                if (f == r)
                    return false;
            }

            return true;
        }

        public String ultraFastMathematician() {
            String sol = "";
            Scanner scanner = new Scanner(System.in);
            String n1 = scanner.nextLine();
            String n2 = scanner.nextLine();
            int n = n1.length();

            for (int i = 0; i < n; i++) {
                if (n1.charAt(i) == n2.charAt(i)) {
                    sol = sol + "0";
                } else {
                    sol = sol + "1";
                }
            }

            scanner.close();
            return sol;
        }

        public List<Integer> perfectPermutation() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();

            List<Integer> sol = pPerm(n, new ArrayList<Integer>());

            scanner.close();
            return sol;
        }

        public List<Integer> pPerm(int n, List<Integer> lst) {
            List<Integer> sol = new ArrayList<>();
            if (lst.size() == n) {
                for (int i = 0; i < lst.size(); i++) {
                    if (lst.get(i) == i + 1) {
                        sol.add(-1);
                        return sol;
                    }
                }

                return lst;
            }

            List<Integer> res;
            for (int i = 0; i < n; i++) {
                if (lst.contains(i + 1))
                    continue;

                lst.add(i + 1);

                res = pPerm(n, lst);
                if (res.get(0) != -1) {
                    return res;
                }

                lst.remove(lst.size() - 1);
            }

            sol.add(-1);
            return sol;
        }

        public int arrivalOfTheGeneral() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();

            List<Integer> line = new ArrayList<>();

            int a = scanner.nextInt();
            int b = scanner.nextInt();
            line.add(a);
            line.add(b);

            int min;
            int minidx;
            int max;
            int maxidx;

            if (a < b) {
                min = a;
                minidx = 0;
                max = b;
                maxidx = 1;
            } else {
                min = b;
                minidx = 1;
                max = a;
                maxidx = 0;
            }

            for (int i = 2; i < n; i++) {
                int num = scanner.nextInt();
                line.add(num);

                if (num > max) {
                    max = num;
                    maxidx = i;
                } else if (num <= min) {
                    min = num;
                    minidx = i;
                }
            }

            int leftSwap = n - 1 - minidx;
            int rightSwap = maxidx;

            scanner.close();
            int sol = leftSwap + rightSwap;

            return (minidx < maxidx) ? sol - 1 : sol;
        }

        public float drinks() {
            Scanner scanner = new Scanner(System.in);

            int n = scanner.nextInt();
            int num = 0;
            int denom = 0;

            for (int i = 0; i < n; i++) {
                num += scanner.nextInt();
                denom += 100;
            }

            scanner.close();
            return (float) num / (float) denom * 100;
        }

        public int insomniaCure() {
            Scanner scanner = new Scanner(System.in);
            int k = scanner.nextInt();
            int l = scanner.nextInt();
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            int d = scanner.nextInt();
            List<Integer> lst = new ArrayList<>();

            lst.add(k);
            lst.add(l);
            lst.add(m);
            if (n != 0)
                lst.add(n);

            int sol = 0;
            for (int i = 0; i < d; i++) {
                int dragonNum = i + 1;
                for (int j = 0; j < lst.size(); j++) {
                    if (dragonNum % lst.get(j) == 0) {
                        sol++;
                        break;
                    }
                }
            }

            scanner.close();
            return sol;
        }

        public int cupboards() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int sol = 0;
            int l = 0;
            int r = 0;

            for (int i = 0; i < n; i++) {
                int nl = scanner.nextInt();
                if (nl == 1)
                    l++;
                int rl = scanner.nextInt();
                if (rl == 1)
                    r++;
            }

            int lClosed = n - l;
            int rClosed = n - r;

            int lres = (lClosed < l) ? lClosed : l;
            int rres = (rClosed < r) ? rClosed : r;
            sol = lres + rres;
            scanner.close();
            return sol;
        }

        public int iLoveUsername() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int l = scanner.nextInt();
            int h = -1;

            int amazing = 0;
            for (int i = 1; i < n; i++) {
                int c = scanner.nextInt();

                if (i == 1) {
                    if (c < l) {
                        h = l;
                        l = c;
                    } else {
                        h = c;
                    }

                    if (h != l)
                        amazing++;
                    continue;
                }

                if (c < l) {
                    l = c;
                    amazing++;
                } else if (c > h) {
                    h = c;
                    amazing++;
                }
            }

            scanner.close();
            return amazing;
        }

        public List<Integer> cellCompete(int[] states, int days) {
            


            int[] ns = new int[states.length];

            for (int j = 0; j < days; j++) {
                for (int i = 0; i < states.length; i++) {
                    int[] ref = (j % 2 == 0) ? states : ns;
                    int[] change = (j % 2 == 0) ? ns : states;

                    int ln;
                    if (i == 0) {
                        ln = 0;
                    } else {
                        ln = ref[i - 1];
                    }

                    int rn;
                    if (i == ref.length - 1) {
                        rn = 0;
                    } else {
                        rn = ref[i + 1];
                    }

                    if (rn == ln) {
                        change[i] = 0;
                    } else {
                        change[i] = 1;
                    }
                }
            }

            int[] target = (days % 2 == 0) ? ns : states;
            List<Integer> sol = new ArrayList<>();

            for (int i = 0; i < target.length; i++) {
                sol.add(target[i]);
            }

            return sol;

        }

        public ArrayList<String> popularNToys(int numToys, int topToys, List<String> toys, int numQuotes,
                List<String> quotes) {
            


            

            Map<String, Integer> map = new HashMap<>();
            for (int i = 0; i < numToys; i++) {
                map.put(toys.get(i), 0);
            }

            for (int i = 0; i < numQuotes; i++) {
                String quote = quotes.get(i).toLowerCase();
                String[] words = quote.split(" ");
                Set<String> mentioned = new HashSet<String>();

                for (int j = 0; j < words.length; j++) {
                    if (mentioned.contains(words[j]))
                        continue;

                    if (map.containsKey(words[j])) {
                        int c = map.get(words[j]);
                        map.put(words[j], ++c);
                        mentioned.add(words[j]);
                    }
                }
            }

            

            List<Map.Entry<String, Integer>> lst = new ArrayList<>();
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                lst.add(entry);
            }

            Collections.sort(lst, new Comparator<Map.Entry<String, Integer>>() {
                public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2) {
                    Integer val1 = e1.getValue();
                    Integer val2 = e2.getValue();
                    

                    if (val1 != val2) {
                        

                        return val2.compareTo(val1);
                    }
                    String id1 = e1.getKey();
                    String id2 = e2.getKey();
                    

                    return id1.compareTo(id2);
                }
            });

            ArrayList<String> sol = new ArrayList<>();

            for (int i = 0; i < topToys; i++) {
                

                if (lst.get(i).getValue() > 0)
                    sol.add(lst.get(i).getKey());
            }
            return sol;
        }

        public List<String> reorderLines(int logFileSize, List<String> logLines) {
            

            for (int i = 0; i < logFileSize; i++) {
                if (isInt(logLines.get(i)))
                    continue;

                int j = i;

                while (j > 0 && !isLess(logLines.get(j), logLines.get(j - 1))) {
                    

                    String temp = logLines.get(j);
                    logLines.set(j, logLines.get(j - 1));
                    logLines.set(j - 1, temp);
                    j--;
                }
            }

            return logLines;
        }

        public boolean isInt(String a) {
            String[] lst = a.split(" ");
            try {
                int c = Integer.parseInt(lst[1]);
            } catch (Exception ex) {
                return false;
            }
            return true;
        }

        

        public boolean isLess(String a, String b) {
            a = a.toLowerCase();
            b = b.toLowerCase();

            String[] wordsA = a.split(" ");
            String[] wordsB = b.split(" ");

            for (int i = 1; i < Math.min(wordsA.length, wordsB.length); i++) {
                if (!wordsA[i].equals(wordsB[i])) {
                    return (wordsA[i].compareTo(wordsB[i]) < 0);
                }
            }

            if (wordsA.length < wordsB.length) {
                return true;
            }
            if (wordsA.length == wordsB.length) {
                return (wordsA[0].compareTo(wordsB[0]) < 0);
            }

            return false;
        }

        public int Tram() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int max = 0;
            int numPassengers = 0;

            for (int i = 0; i < n; i++) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();

                numPassengers -= a;
                numPassengers += b;

                if (numPassengers > max) {
                    max = numPassengers;
                }

            }

            scanner.close();
            return max;
        }

        public String helpfulMaths() {
            Scanner scanner = new Scanner(System.in);
            String s = scanner.nextLine();
            String[] a = s.split("\\+");

            Arrays.sort(a);
            String sol = "";

            for (int i = 0; i < a.length; i++) {
                if (i < a.length - 1) {
                    sol = sol + a[i] + "+";
                } else {
                    sol = sol + a[i];
                }
            }

            scanner.close();
            return sol;
        }

        public int isYourHorseShoeOnTheOtherHoof() {
            Scanner scanner = new Scanner(System.in);
            Set<Integer> set = new HashSet<Integer>();

            for (int i = 0; i < 4; i++) {
                set.add(scanner.nextInt());
            }

            scanner.close();
            return 4 - set.size();
        }

        public List<String> wayTooLongWords() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            List<String> sol = new ArrayList<>();
            scanner.nextLine();

            for (int i = 0; i < n; i++) {
                String s = scanner.nextLine();
                int sl = s.length();
                if (sl <= 10) {
                    sol.add(s);
                    System.out.println(s);
                    continue;
                }
                String num = sl - 2 + "";

                String k = s.charAt(0) + num + s.charAt(sl - 1) + "";
                System.out.println(k);
                sol.add(k);
            }

            scanner.close();
            return sol;
        }

        public String boyOrGirl() {
            Scanner scanner = new Scanner(System.in);
            String input = scanner.nextLine();
            char[] ic = input.toCharArray();
            Set<Character> set = new HashSet<>();
            int n = ic.length;
            for (int i = 0; i < n; i++) {
                set.add(ic[i]);
            }

            scanner.close();
            return (set.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!";
        }

        public String amusingJoke() {
            Scanner scanner = new Scanner(System.in);
            String a = scanner.nextLine();
            String b = scanner.nextLine();
            String c = scanner.nextLine();
            scanner.close();

            String hosts = a + b;
            char[] harr = hosts.toCharArray();
            char[] bullyLet = c.toCharArray();
            Arrays.sort(bullyLet);
            Arrays.sort(harr);

            int n = harr.length;
            if (n != bullyLet.length)
                return "NO";

            for (int i = 0; i < n; i++) {
                if (harr[i] != bullyLet[i])
                    return "NO";
            }

            return "YES";
        }

        public int softDrinking() {
            Scanner scanner = new Scanner(System.in);
            int numFriends = scanner.nextInt();
            int numBottles = scanner.nextInt();
            int literPerBottle = scanner.nextInt();
            int numLimes = scanner.nextInt();
            int limeSlices = scanner.nextInt();
            int foundSalt = scanner.nextInt();
            int neededLitersPerDrink = scanner.nextInt();
            int neededGramsOfSaltPerDrink = scanner.nextInt();
            scanner.close();
            int totalLiters = numBottles * literPerBottle;
            int totalLimes = numLimes * limeSlices;

            int var1 = totalLimes;
            int var2 = foundSalt / (neededGramsOfSaltPerDrink);
            int var3 = totalLiters / (neededLitersPerDrink);

            int minToasts = Math.min(var1, var2);
            minToasts = Math.min(minToasts, var3);
            return minToasts / numFriends;
        }

        public String hq9() {
            Scanner scanner = new Scanner(System.in);
            String p = scanner.nextLine();
            scanner.close();
            char[] input = p.toCharArray();
            int n = input.length;

            for (int i = 0; i < n; i++) {
                char c = input[i];
                if (c == 'H' || c == 'Q' || c == '9') {
                    return "YES";
                }
            }

            return "NO";
        }

        public int petyaAndStrings() {
            Scanner scanner = new Scanner(System.in);
            String a = scanner.nextLine();
            String b = scanner.nextLine();
            scanner.close();

            a = a.toLowerCase();
            b = b.toLowerCase();

            int sol = a.compareTo(b);
            if (sol == 0) {
                return 0;
            }
            if (sol < 1) {
                return -1;
            } else {
                return 1;
            }
        }

        public int team() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                int c = scanner.nextInt();
                if (a + b + c >= 2)
                    cnt++;
            }
            scanner.close();
            return cnt;
        }

        public int bitpp() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            scanner.nextLine();
            int x = 0;
            for (int i = 0; i < n; i++) {
                String statement = scanner.nextLine();
                if (statement.charAt(0) == '-' || statement.charAt(statement.length() - 1) == '-') {
                    x--;
                } else {
                    x++;
                }
            }
            scanner.close();
            return x;
        }

        public void effectiveApproach() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int[] narr = new int[n];
            Map<Integer,Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                narr[i] = scanner.nextInt();
                map.put(narr[i], i);
            }

            int m = scanner.nextInt();
            int[] marr = new int[m];
            for (int i = 0; i < m; i++) {
                marr[i] = scanner.nextInt();
            }
            scanner.close();

            long a = 0, b = 0;

            for (int i = 0; i < m; i++) {
                int key = marr[i];

                if(map.containsKey(key)){
                    int idx = map.get(key);

                    int cntA = idx+1;
                    a += cntA;
                    int cntB =  n - 1 + 1 - idx;
                    b += cntB;
                }

                
            }
            System.out.println(a + " " + b);
        }

    }

    public static void main(String[] args) {
        
        Solution sol = new Solution();
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        
        

        

        

        

        

        

        

        

        

        

        

        sol.effectiveApproach();
        

    }
}
