import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Codeforces {
    public static void main(String[] args) throws IOException {
        id20();
    }
    public static void id20() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[][] grid = new String[n][n];
            int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            int count = 0;
            int id21 = 0, ogy1 = 0, id6 = 0, ogy2 = 0;
            for (int j = 0; j < n; j++) {
                String[] vals = bi.readLine().split("");
                for (int k = 0; k < vals.length; k++) {
                    grid[j][k] = vals[k];
                    if(vals[k].equals("*")){
                        if(count == 0){
                            id21 = k;
                            ogy1 = j;
                            y1 = j;
                            x2 = k;
                            count++;
                        }else if(count == 1){
                            id6 = k;
                            ogy2 = j;
                            y2 = j;
                            x1 = k;
                        }
                    }
                }
            }
            if(y1 == y2){
                y1 = x1;
                y2 = y1;

                if(((id21 == x1 && ogy1 == y1) || (id21 == x2 && ogy1 == y2) ||
                        (id6 == x1 && ogy2 == y1) || (id6 == x2 && ogy2 == y2))){
                    int a = 0;
                    while((y1 == ogy1) || (y2 == ogy2) || (y1 == ogy2) || (y2 == ogy1)){
                        a++;
                        y1 = n-a;
                        y2 = n-a;
                    }
                }

            }
            if(x1 == x2){
                x2 = y1;
                int ty2 = y2;
                y2 = x2;

                x1 = x2;
                y1 = ty2;

                if(((id21 == x1 && ogy1 == y1) || (id21 == x2 && ogy1 == y2) ||
                        (id6 == x1 && ogy2 == y1) || (id6 == x2 && ogy2 == y2))){
                    int a = 0;
                    while((x1 == id21) || (x2 == id6) || (x1 == id6) || (x2 == id21)){
                        a++;
                        x1 = n-a;
                        x2 = n-a;
                    }

                }
            }
            grid[y1][x1] = "*";
            grid[y2][x2] = "*";
            for (String[] strings : grid) {
                for (int k = 0; k < grid[0].length; k++) {
                    System.out.print(strings[k]);
                }
                System.out.println();
            }
        }
    }
    public static void id2() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] arrs = bi.readLine().split(" ");
            ArrayList<Integer> arr = new ArrayList<>();
            ArrayList<Integer> arrb = new ArrayList<>();
            for (int j = 0; j < n; j++) {
               arr.add(Integer.parseInt(arrs[j]));
               arrb.add(Integer.parseInt(arrs[j]));
            }
            Collections.sort(arr);
            if(arr.get(0) == arr.get(1)) {
                System.out.println(arrb.indexOf(arr.get(arr.size()-1))+1);
            }else{
                System.out.println(arrb.indexOf(arr.get(0))+1);
            }
        }
    }
    public static void id31() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            long evenP, oddP, evenQ, oddQ;
            evenP = oddP = evenQ = oddQ = 0;
            int n = Integer.parseInt(bi.readLine());
            String[] id12 = bi.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                int p = Integer.parseInt(id12[j]);
                if(p % 2 == 0) evenP++;
                else oddP++;
            }
            int m = Integer.parseInt(bi.readLine());
            String[] id28 = bi.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                int q = Integer.parseInt(id28[j]);
                if(q % 2 == 0) evenQ++;
                else oddQ++;
            }
            System.out.println(evenP * evenQ + oddP * oddQ);
        }
    }
    public static void id15(){
        Scanner scanner = new Scanner(System.in);
        String[] sn = scanner.nextLine().split(" ");
        int s = Integer.parseInt(sn[0]);
        int n = Integer.parseInt(sn[1]);
        ArrayList<Integer> strengths = new ArrayList<>();
        ArrayList<Integer> bonuses = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] dragon = scanner.nextLine().split(" ");
            int str = Integer.parseInt(dragon[0]);
            int bonus = Integer.parseInt(dragon[1]);
            strengths.add(str);
            bonuses.add(bonus);
        }
        for (int j = 0; j < n; j++) {
            int minStr = Integer.MAX_VALUE, minIndex = 0;
            for (int i = 0; i < strengths.size(); i++) {
                if(strengths.get(i) < minStr) {
                    minStr = strengths.get(i);
                    minIndex = i;
                }
            }
            if(minStr >= s) {
                System.out.println("NO");
                return;
            }
            s += bonuses.get(minIndex);
            strengths.remove(minIndex);
            bonuses.remove(minIndex);
        }
        System.out.println("YES");
    }
    public static void id4(){
        Scanner scanner = new Scanner(System.in);
        String[] ages = scanner.nextLine().split(" ");
        int a = Integer.parseInt(ages[0]);
        int b = Integer.parseInt(ages[1]);
        int years = 0;
        while(b >= a){
            a *= 3;
            b *= 2;
            years++;
        }
        System.out.println(years);
    }
    public static void id14(){
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        String readthrough = "";
        int distinct = 0;
        for (int i = 0; i < name.length(); i++) {
            if(!readthrough.contains(name.substring(i, i+1))) {
                distinct++;
                readthrough += name.substring(i, i+1);
            }
        }
        System.out.println(distinct % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
    }
    public static void id7(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] stones = scanner.nextLine().split("");
        boolean mixed = true;
        boolean same = true;
        for (int i = 1; i < stones.length; i++) {
            if(stones[i-1].equals(stones[i])) mixed = false;
            else same = false;
        }
        if(same) {
            System.out.println(N-1);
            return;
        }
        if(mixed){
            System.out.println(0);
            return;
        }
        int remove = 0;
        ArrayList<String> stoness = new ArrayList<>(Arrays.asList(stones));
        for (int i = 0; i < stoness.size()-1; i++) {
            if(stoness.get(i).equals(stoness.get(i+1))) {
                stoness.remove(i+1);
                remove++;
                i--;
            }
        }
        System.out.println(remove);
    }




























    public static void id8(){
        Scanner scanner = new Scanner(System.in);
        String[] values = scanner.nextLine().split(" ");
        int N = Integer.parseInt(values[0]), a = 0, b = 0, c = 0;
        for (int i = 1; i < values.length; i++) {
            int val = Integer.parseInt(values[i]);
            if(i == 1) a = val;
            if(i == 2) b = val;
            if(i == 3) c = val;
        }
        int min = Math.min(a, Math.min(b, c));
        int max = Math.max(a, Math.max(b, c));
        int mid = min;
        for (String value : values) {
            int val = Integer.parseInt(value);
            if (val > min && val < max) mid = val;
        }
        int ribbons, length = 0;
        if(N % min == 0) {
            System.out.println(N / min);
            return;
        }
        ribbons = (int) Math.floor(N / (double) min);
        System.out.println(ribbons);
        length = ribbons * min;
        if(length + mid <= N) {
            System.out.println(ribbons + 1);
        }else{
            System.out.println(ribbons);
        }
    }
    public static void id16(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] valuess = scanner.nextLine().split(" ");
        ArrayList<Integer> values = new ArrayList<>();
        double sum = 0;
        for (int i = 0; i < N; i++) {
            int value = Integer.parseInt(valuess[i]);
            sum += value;
            values.add(value);
        }
        int taken = 0;
        values.sort(Collections.reverseOrder());
        for (int i = 0; i < N; i++) {
            taken += values.get(i);
            if(taken > sum/2) {
                System.out.println(i+1);
                return;
            }
        }
    }
    public static void id10(){
        Scanner scanner = new Scanner(System.in);
        String pos = scanner.nextLine();
        for (int i = 0; i <= pos.length()-7; i++) {
            if(pos.substring(i, i+7).equals("0000000") || pos.substring(i, i+7).equals("1111111")) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
    public static void id34(){
        Scanner scanner = new Scanner(System.in);
        String p = scanner.nextLine();
        boolean containsNum = false;
        for (int i = 0; i < p.length(); i++) {
            if ("1234567890".contains(p.substring(i, i + 1))) {
                containsNum = true;
                break;
            }
        }
        System.out.println(p.length() >= 5 && !p.toLowerCase().equals(p) && !p.toUpperCase().equals(p) && containsNum ? "Correct" : "Too weak");
    }
    public static void id19(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        Hashtable<String, Integer> dict = new Hashtable<>();
        String[] names = new String[N];
        for (int i = 0; i < N; i++) {
            String name = scanner.nextLine();
            dict.putIfAbsent(name, 0);
            names[i] = name + (dict.get(name) == 0 ? "" : dict.get(name));
            dict.put(name, dict.get(name) + 1);
        }
        for (String name : names) {
            boolean okay = true;
            for (int i = 0; i < name.length(); i++) {
                if ("1234567890".contains(name.substring(i, i + 1))) {
                    okay = false;
                    break;
                }
            }
            System.out.println(okay ? "OK" : name);
        }
    }
    public static void id36(){
        Scanner scanner = new Scanner(System.in);
        int k = Integer.parseInt(scanner.nextLine());
        String[] xy = scanner.nextLine().split(" ");
        double x = Integer.parseInt(xy[0]);
        double y = Integer.parseInt(xy[1]);
        double r = Math.sqrt(x*x + y*y);
        double prevx = x;
        System.out.println(r);
        double currentAngle = Math.atan(y/x);
        double newAngle = currentAngle + k*Math.PI/180;
        System.out.println(currentAngle);
        System.out.println(newAngle);
        x = r*Math.cos(newAngle);
        y = r*Math.sin(newAngle);
        if(prevx < 0){
            x = -x;
            y = -y;
        }
        System.out.println(x + " " + y);
    }
    public static void id17(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] valuess = scanner.nextLine().split(" ");
        int[] values = new int[N];
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(valuess[i]);
            if(num >= 0) num = -num - 1;
            values[i] = num;
        }
        int negatives = 0;
        for (int value : values) {
            if(value < 0) negatives++;
        }
        if(negatives % 2 == 1){
            int min = Integer.MIN_VALUE;
            int minIndex = 0;
            for (int i = 0; i < N; i++) {
                int value = values[i];
                if(value < -1 && Math.abs(value) > min) {
                    min = Math.abs(value);
                    minIndex = i;
                }
            }
            values[minIndex] = -values[minIndex] - 1;
        }
        for (int value : values) {
            System.out.print(value + " ");
        }
    }
    public static void id1(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] nums = scanner.nextLine().split(" ");
        int even = 0, odd = 0;
        for (int i = 0; i < 3; i++) {
            if(Integer.parseInt(nums[i]) % 2 == 0) even++;
            else odd++;
        }
        boolean needEven = even > odd;
        for (int i = 0; i < nums.length; i++) {
            int n = Integer.parseInt(nums[i]);
            if((needEven && n % 2 != 0) || (!needEven && n % 2 == 0)){
                System.out.println(i+1);
                break;
            }
        }
    }
    public static void id13(){
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        boolean allcaps = true;
        boolean first = false;
        for (int i = 1; i < str.length(); i++) {
            if (str.substring(i, i + 1).toLowerCase().equals(str.substring(i, i + 1))) {
                allcaps = false;
                break;
            }
        }
        if(str.substring(0, 1).toLowerCase().equals(str.substring(0, 1))){
            if(allcaps) first = true;
            allcaps = false;
        }
        System.out.println(first ? str.substring(0, 1).toUpperCase() + str.substring(1).toLowerCase() : (allcaps ? str.toLowerCase() : str));
    }
    public static void id24(){
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());
        int c = Integer.parseInt(scanner.nextLine());
        System.out.println(Math.max(a*b*c, Math.max(a*(b+c), Math.max(a+b*c, Math.max((a+b)*c, a+b+c)))));
    }
    public static void id22(){
        Scanner scanner = new Scanner(System.in);
        int num = Integer.parseInt(scanner.nextLine());
        int[] lucky = {4, 7, 44, 47, 77, 444, 447, 474, 477, 744, 747, 777};
        boolean almost = false;
        for (int j : lucky) {
            if (j <= num && num % j == 0) {
                almost = true;
                break;
            }
        }
        System.out.println(almost ? "YES" : "NO");
    }
    public static void id23(){
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        System.out.println((word.contains("h") && word.contains("e") && word.contains("l") && word.contains("o") &&
                word.indexOf("h") < word.indexOf("e", word.indexOf("h")+1) &&
                word.indexOf("e", word.indexOf("h")+1) < word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1) &&
                word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1) < word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1) &&
                word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1) < word.indexOf("o", word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1))) ? "YES" : "NO");
    }
    public static void id30(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < N; i++) {
            String[] vector = scanner.nextLine().split(" ");
            x += Integer.parseInt(vector[0]);
            y += Integer.parseInt(vector[1]);
            z += Integer.parseInt(vector[2]);
        }
        System.out.println(x == 0 && y == 0 && z == 0 ? "YES" : "NO");
    }
    public static void id9(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] sizes = scanner.nextLine().split(" ");
        int cars = 0, ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < N; i++) {
            switch (sizes[i]) {
                case "4":
                    cars++;
                    break;
                case "3":
                    threes++;
                    break;
                case "2":
                    twos++;
                    break;
                case "1":
                    ones++;
                    break;
            }
        }
        System.out.println(cars);
    }
    public static void id25(){
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        System.out.println(word.substring(0, 1).toUpperCase() + word.substring(1));
    }
    public static void id29(){
        Scanner scanner = new Scanner(System.in);
        String[] calc = scanner.nextLine().replaceAll("\\+", "").split("");
        Arrays.sort(calc);
        StringBuilder newCalc = new StringBuilder();
        for (String s : calc) {
            newCalc.append(s).append("+");
        }
        newCalc.deleteCharAt(newCalc.length()-1);
        System.out.println(newCalc);
    }
    public static void id26(){
        Scanner scanner = new Scanner(System.in);
        StringBuilder word = new StringBuilder(scanner.nextLine().toLowerCase());
        for (int i = 0; i < word.length(); i++) {
            if("aeioyu".contains(word.substring(i, i+1))) {
                word.deleteCharAt(i);
                i--;
            }
            else {
                word.insert(i, ".");
                i++;
            }
        }
        System.out.println(word);
    }
    public static void id32(){
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine().toLowerCase();
        String b = scanner.nextLine().toLowerCase();
        double score = a.compareTo(b);
        System.out.println((int) (score/Math.abs(score)));
    }
    public static void id0(){
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            String[] line = scanner.nextLine().split(" ");
            for (int j = 0; j < line.length; j++) {
                if(line[j].equals("1")) System.out.println(Math.abs(j-2) + Math.abs(i-2));
            }
        }
    }
    public static void id11(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int x = 0;
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            if(line.contains("--")) x--;
            if(line.contains("++")) x++;
        }
        System.out.println(x);
    }
    public static void id3(){
        Scanner scanner = new Scanner(System.in);
        String[] mn = scanner.nextLine().split(" ");
        int m = Integer.parseInt(mn[0]);
        int n = Integer.parseInt(mn[1]);
        System.out.println(m*n/2);
    }
    public static void id18(){
        Scanner scanner = new Scanner(System.in);
        String[] nk = scanner.nextLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        String[] scores = scanner.nextLine().split(" ");
        int min = Integer.parseInt(scores[k-1]);
        int pass = 0;
        for (String score : scores) {
            if(Integer.parseInt(score) >= min && Integer.parseInt(score) > 0) pass++;
        }
        System.out.println(pass);
    }
    public static void id5(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int count = 0;
        for (int i = 0; i < N; i++) {
            String[] thoughts = scanner.nextLine().split(" ");
            int sure = 0;
            for (String thought : thoughts) {
                if(thought.equals("1")) sure++;
            }
            if(sure >= 2) count++;
        }
        System.out.println(count);
    }
    public static void id33(){
        Scanner scanner = new Scanner(System.in);
        String[] nma = scanner.nextLine().split(" ");
        double n = Integer.parseInt(nma[0]);
        double m = Integer.parseInt(nma[1]);
        double a = Integer.parseInt(nma[2]);
        System.out.println(Math.round(Math.ceil(n/a)*Math.ceil(m/a)));
    }
    public static void id35(){
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] abbrev = new String[N];
        for (int i = 0; i < N; i++) {
            String word = scanner.nextLine();
            if(word.length() > 10) abbrev[i] = word.substring(0, 1) + (word.length()-2) + word.substring(word.length()-1);
            else abbrev[i] = word;
        }
        for (String s : abbrev) {
            System.out.println(s);
        }
    }
    public static void id27(){
        Scanner scanner = new Scanner(System.in);
        int weight = Integer.parseInt(scanner.nextLine());
        if(weight <= 3 || weight % 2 == 1){
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}
