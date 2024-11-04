import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.*;

public class Codeforces {
    public static void main(String[] args) throws IOException {


        id33();
    }
    public static void id33() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String s = bi.readLine();
            int end = 1;
            while (end < n && ((s.charAt(end - 1) > s.charAt(end)) || (end > 1 && s.charAt(end - 1) == s.charAt(end)))){
                end++;
            }
            for (int j = 0; j < end; j++) {
                System.out.print(s.charAt(j));
            }
            for (int j = end; j >= 1; j--) {
                System.out.print(s.charAt(j - 1));
            }
            System.out.println();
        }
    }
    public static void id53() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] a = bi.readLine().split(" ");
            int[] freq = new int[101];
            for (String s : a) {
                int num = Integer.parseInt(s);
                if(num == 0){
                    freq[Math.abs(num)] = 1;
                }else freq[Math.abs(num)]++;
            }
            int max = 0;
            for (int f : freq) {
                if(f == 1) max++;
                else if(f >= 2) max+=2;
            }
            System.out.println(max);
        }
    }
    public static void id17() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String a = bi.readLine();
        StringBuilder ax = new StringBuilder(a);
        StringBuilder x = ax;
        if((C(ax, 1) + C(ax, 4)) > 10){
            rotate(x, 1, 3);
        }else{
            rotate(x, 4, 8);
        }
        if((C(ax, 3) + C(ax, 2)) > 8){
            rotate(x, 4, 9);
        }else{
            rotate(x, 5, 8);
        }
        if(C(ax, 3) % 2 == 1){
            rotate(x, 3, 3);
        }else{
            rotate(x, 3, 4);
        }
        if(C(ax, 5) > C(ax, 2)){
            rotate(x, 4, 1);
        }else{
            rotate(x, 2, 7);
        }
        if(C(ax, 1) % 2 == 1){
            rotate(x, 1, 3);
        }else{
            rotate(x, 3, 5);
        }
        if(C(ax, 4) % 2 == 1){
            rotate(x, 4, 7);
        }else{
            rotate(x, 1, 9);
        }
        if(C(ax, 4) > C(ax, 1)){
            rotate(x, 4, 9);
        }else{
            rotate(x, 4, 2);
        }
        if(C(ax, 1) > C(ax, 3)){
            rotate(x, 2, 1);
        }else{
            rotate(x, 3, 1);
        }
        if(C(ax, 5) > C(ax, 3)){
            rotate(x, 4, 5);
        }else{
            rotate(x, 5, 8);
        }
        if((C(ax, 1) + C(ax, 3)) > 8){
            rotate(x, 4, 5);
        }else{
            rotate(x, 2, 5);
        }
        if(C(ax, 1) > C(ax, 4)){
            rotate(x, 4, 3);
        }else{
            rotate(x, 2, 3);
        }
        if((C(ax, 3) + C(ax, 1)) > 9){
            rotate(x, 2, 9);
        }else{
            rotate(x, 2, 2);
        }
        if((C(ax, 4) + C(ax, 3)) > 10){
            rotate(x, 4, 7);
        }else{
            rotate(x, 5, 7);
        }
        if(C(ax, 3) > C(ax, 2)){
            rotate(x, 3, 2);
        }else{
            rotate(x, 4, 6);
        }
        if(C(ax, 1) > C(ax, 3)){
            rotate(x, 1, 9);
        }else{
            rotate(x, 2, 9);
        }
        if(C(ax, 3) % 2 == 1){
            rotate(x, 3, 9);
        }else{
            rotate(x, 1, 5);
        }
        if((C(ax, 3) + C(ax, 5)) > 9){
            rotate(x, 3, 4);
        }else{
            rotate(x, 3, 9);
        }
        if(C(ax, 3) > C(ax, 1)){
            rotate(x, 5, 1);
        }else{
            rotate(x, 5, 7);
        }
        if(C(ax, 1) > C(ax, 3)){
            rotate(x, 2, 9);
        }else{
            rotate(x, 4, 6);
        }
        if((C(ax, 2) + C(ax, 3)) > 10){
            rotate(x, 2, 2);
        }else{
            rotate(x, 3, 6);
        }
        System.out.println(x);
    }
    private static void rotate(StringBuilder x, int pos, int rotations){
        int num = I(x.charAt(pos - 1));
        for (int i = 0; i < rotations; i++) {
            num++;
            if(num == 10) num = 0;
        }
        x.setCharAt(pos - 1, (char)(num+'0'));
    }
    private static int C(StringBuilder x, int pos){
        return I(x.charAt(pos - 1));
    }
    private static int I(char n){


        return Character.getNumericValue(n);
    }
    public static void id32() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nl = bi.readLine().split(" ");
        int n = Integer.parseInt(nl[0]);
        int l = Integer.parseInt(nl[1]);
        String[] as = bi.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < as.length; i++) {
            a[i] = Integer.parseInt(as[i]);
        }
        Arrays.sort(a);
        double maxD = 0;
        for (int i = 0; i < a.length-1; i++) {
            int D = a[i+1] - a[i];
            if(D > maxD) maxD = D;
        }
        System.out.println(Math.max(maxD/2, Math.max(a[0], l - a[a.length-1])));
    }
    public static void id4() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] a = bi.readLine().split(" ");
        ArrayList<Integer> maxes = new ArrayList<>();
        int max = 1;
        int ai = Integer.parseInt(a[0]);
        for (int i = 1; i < a.length; i++) {
            int aii = Integer.parseInt(a[i]);
            if(aii >= ai){
                max++;
            }else{
                maxes.add(max);
                max = 1;
            }
            ai = aii;
        }
        maxes.add(max);
        Collections.sort(maxes);
        System.out.println(maxes.get(maxes.size()-1));
    }
    public static void id8() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String arg = bi.readLine();
        for (int i = 0; i < arg.length(); i++) {
            if("HQ9".contains(arg.substring(i, i+1))) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
    public static void id29() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nh = bi.readLine().split(" ");
        int n = Integer.parseInt(nh[0]);
        int h = Integer.parseInt(nh[1]);
        String[] a = bi.readLine().split(" ");
        int width = 0;
        for (int i = 0; i < n; i++) {
            int ai = Integer.parseInt(a[i]);
            if(ai > h) width += 2;
            else width++;
        }
        System.out.println(width);
    }
    public static void id15() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bi.readLine());
        String s = "";
        boolean diff = false;
        while(!diff){
            num++;
            s = String.valueOf(num);
            diff = true;
            for (int i = 0; i < s.length(); i++) {
                for (int j = i+1; j < s.length(); j++) {
                    if (s.charAt(i) == s.charAt(j)) {
                        diff = false;
                        break;
                    }
                }
            }
        }
        System.out.println(num);
    }
    public static void id42() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String s = bi.readLine();
        int A, D;
        A = D = 0;
        for (int i = 0; i < s.length(); i++) {
           if(s.charAt(i) == 'A') A++;
           else D++;
        }
        System.out.println(A > D ? "Anton" : (A == D ? "Friendship" : "Danik"));
    }
    public static void id51() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String a = bi.readLine();
        String b = bi.readLine();
        if(a.length() != b.length()) {
            System.out.println("NO");
            return;
        }
        int ib = a.length() - 1;
        for (int ia = 0; ia < a.length(); ia++) {
            if(a.charAt(ia) != b.charAt(ib)) {
                System.out.println("NO");
                return;
            }
            ib--;
        }
        System.out.println("YES");
    }
    public static void id2() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String num = bi.readLine();
        int lucky = 0;
        for (int i = 0; i < num.length(); i++) {
            if(num.charAt(i) == '4' || num.charAt(i) == '7') lucky++;
        }
        String luckyy = String.valueOf(lucky);
        boolean nearly = true;
        for (int i = 0; i < luckyy.length(); i++) {
            if (!(luckyy.charAt(i) == '4') && !(luckyy.charAt(i) == '7')) {
                nearly = false;
                break;
            }
        }
        System.out.println(nearly ? "YES" : "NO");
    }
    public static void id39() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nt = bi.readLine().split(" ");
        int n = Integer.parseInt(nt[0]);
        int t = Integer.parseInt(nt[1]);
        String a = bi.readLine();
        StringBuilder str = new StringBuilder(a);
        StringBuilder temp = new StringBuilder(a);
        for (int i = 0; i < t; i++) {
            for (int j = str.length()-1; j > 0; j--) {
                if(str.charAt(j-1) == 'B' && str.charAt(j) == 'G'){
                    temp.setCharAt(j-1, 'G');
                    temp.setCharAt(j, 'B');
                }
            }
            str = new StringBuilder(temp.toString());
        }
        System.out.println(str);
    }
    public static void id22() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        int people = 0, maxPeople = 0;
        for (int i = 0; i < n; i++) {
            String[] ab = bi.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            people -= a;
            people += b;
            if(people > maxPeople) maxPeople = people;
        }
        System.out.println(maxPeople);
    }
    public static void id38() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = bi.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        for (int i = 0; i < k; i++) {
            if(n % 10 != 0) n--;
            else n /= 10;
        }
        System.out.println(n);
    }
    public static void id18() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String str = bi.readLine();
        int up = 0, low = 0;
        for (int i = 0; i < str.length(); i++) {
            String s = str.substring(i, i+1);
            if(s.equals(s.toLowerCase())) low++;
            else up++;
        }
        System.out.println(up > low ? str.toUpperCase() : str.toLowerCase());
    }
    public static void id24() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(bi.readLine());
        int pos = 0, steps = 0;
        while (pos < x) {
            int diff = x - pos;
            int move = 0;
            for (int i = 1; i <= 5; i++) {
                if(diff >= i) move = i;
            }
            pos += move;
            steps++;
        }
        System.out.println(steps);
    }
    public static void id34() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] knw = bi.readLine().split(" ");
        int k = Integer.parseInt(knw[0]);
        int n = Integer.parseInt(knw[1]);
        int w = Integer.parseInt(knw[2]);
        int cost = k*(w*(w+1)/2);
        System.out.println(Math.max(cost - n, 0));
    }
    public static void id36() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = bi.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int clicks;
        if(n >= m) clicks = n - m;
        else{
            if((m / (double) n) % 2 == 0) clicks = (int) (m / (double) n)/2;
            else {
                int clickss = Integer.MAX_VALUE;
                for (int i = 0; i < 700000; i++) {
                    int num = n;
                    int steps = 0;
                    while(num != m){
                        if(Math.random() < 0.88 && num > 0) num -= 1;
                        else num *= 2;
                        steps++;
                        if(num > m * 2 || num < 1) break;
                    }
                    if(num == m){
                        if(steps < clickss) clickss = steps;
                    }
                }
                clicks = clickss;
            }
        }
        System.out.println(clicks);
    }
    public static void id37() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] sm = bi.readLine().split(" ");
        int m = Integer.parseInt(sm[0]);
        int s = Integer.parseInt(sm[1]);
        if(m == 0 || (m == 1 && s > 9) || s == 0){
            System.out.println("-1 -1");
            return;
        }


        double low = Double.MAX_VALUE, high = Double.MIN_VALUE;
        for (double i = Math.pow(10, m-1); i < Math.pow(10, m); i++) {
            String num = new DecimalFormat("
            int sum = 0;
            for (int j = 0; j < num.length(); j++) {
                sum += Integer.parseInt(num.substring(j, j+1));
            }
            if(sum == s){
                if(i < low) low = i;
                if(i > high) high = i;
            }
        }
        System.out.println((int) low + " " + (int) high);
    }
    public static void _706B() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bi.readLine());
        String[] pricess = bi.readLine().split(" ");
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = Integer.parseInt(pricess[i]);
        }
        Arrays.sort(prices);
        int days = Integer.parseInt(bi.readLine());
        for (int i = 0; i < days; i++) {
            int coins = Integer.parseInt(bi.readLine());
            System.out.println(indexClosestTo(prices, coins) + 1);
        }
    }
    public static int indexClosestTo(int[] nums, int target) {
        int low = 0, high = nums.length-1;
        if (nums[low] > target) return -1;
        if (nums[high] < target) return high;
        while (low < high) {
            int mid = (low + high + 1)/2;
            if (target >= nums[mid]) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    public static void _466A() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String[] vals = bi.readLine().split(" ");
        int ridesNeeded = Integer.parseInt(vals[0]);
        int mrides = Integer.parseInt(vals[1]);
        int priceof1 = Integer.parseInt(vals[2]);
        int priceofm = Integer.parseInt(vals[3]);
        int ridesBought = 0;
        int price = 0;
        if(Math.ceil(priceofm / (double) mrides) <= priceof1){
            while(ridesBought < ridesNeeded){
                ridesBought += mrides;
                price += priceofm;
            }
            if(ridesBought > ridesNeeded){
                int prev = price;
                ridesBought -= mrides;
                price -= priceofm;
                price += (ridesNeeded - ridesBought)*priceof1;
                if(price > prev) price = prev;
            }
            System.out.println(price);
        }else{
            System.out.println(priceof1*ridesNeeded);
        }
    }
    public static void _1512G() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int c = Integer.parseInt(bi.readLine());
            for (int j = 1; j <= c; j++) {
                int sum = 0;
                for (int k = 1; k <= j; k++) {
                    if(j % k == 0) {
                        sum += k;
                    }
                }
                if(c == sum){
                    System.out.println(j);
                    break;
                }
                if(j == c){
                    System.out.println(-1);
                }
            }
        }
    }
    public static void _1512C() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[] values = bi.readLine().split(" ");
            int a = Integer.parseInt(values[0]);
            int b = Integer.parseInt(values[1]);
            String[] str = bi.readLine().split("");
            int as = 0, bs = 0, qs = 0;
            for (String s : str) {
                if(s.equals("a")) as++;
                else if(s.equals("b")) bs++;
                else qs++;
            }
            if(n % 2 == 0 && as == bs && qs == n){
                System.out.println(-1);
                return;
            }

        }
    }
    public static void id12() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[][] grid = new String[n][n];
            ArrayList<Integer> X = new ArrayList<>();
            ArrayList<Integer> Y = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                String[] vals = bi.readLine().split("");
                for (int k = 0; k < vals.length; k++) {
                    grid[j][k] = vals[k];
                    if(vals[k].equals("*")){
                        X.add(k);
                        Y.add(j);
                    }
                }
            }
            if (Objects.equals(X.get(0), X.get(1))) {
                if (X.get(0) == 0) {
                    X.add(1);
                } else X.add(0);
            }
            if (Objects.equals(Y.get(0), Y.get(1))) {
                if (Y.get(0) == 0) {
                    Y.add(1);
                } else Y.add(0);
            }
            for (Integer x : X) {
                for (Integer y : Y) {
                    grid[y][x] = "*";
                }
            }
            for (String[] strings : grid) {
                for (int k = 0; k < grid[0].length; k++) {
                    System.out.print(strings[k]);
                }
                System.out.println();
            }
        }
    }
    public static void id31() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(bi.readLine());
            String[][] grid = new String[n][n];
            int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            int count = 0;
            int id35 = 0, ogy1 = 0, id10 = 0, ogy2 = 0;
            for (int j = 0; j < n; j++) {
                String[] vals = bi.readLine().split("");
                for (int k = 0; k < vals.length; k++) {
                    grid[j][k] = vals[k];
                    if(vals[k].equals("*")){
                        if(count == 0){
                            id35 = k;
                            ogy1 = j;
                            y1 = j;
                            x2 = k;
                            count++;
                        }else if(count == 1){
                            id10 = k;
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
                if(((id35 == x1 && ogy1 == y1) || (id35 == x2 && ogy1 == y2) ||
                        (id10 == x1 && ogy2 == y1) || (id10 == x2 && ogy2 == y2))){
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
                if(((id35 == x1 && ogy1 == y1) || (id35 == x2 && ogy1 == y2) ||
                        (id10 == x1 && ogy2 == y1) || (id10 == x2 && ogy2 == y2))){
                    int a = 0;
                    while((x1 == id35) || (x2 == id10) || (x1 == id10) || (x2 == id35)){
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
    public static void id3() throws IOException {
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
            if(Objects.equals(arr.get(0), arr.get(1))) {
                System.out.println(arrb.indexOf(arr.get(arr.size()-1))+1);
            }else{
                System.out.println(arrb.indexOf(arr.get(0))+1);
            }
        }
    }
    public static void id52() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        for (int i = 0; i < t; i++) {
            long evenP, oddP, evenQ, oddQ;
            evenP = oddP = evenQ = oddQ = 0;
            int n = Integer.parseInt(bi.readLine());
            String[] id20 = bi.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                int p = Integer.parseInt(id20[j]);
                if(p % 2 == 0) evenP++;
                else oddP++;
            }
            int m = Integer.parseInt(bi.readLine());
            String[] id48 = bi.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                int q = Integer.parseInt(id48[j]);
                if(q % 2 == 0) evenQ++;
                else oddQ++;
            }
            System.out.println(evenP * evenQ + oddP * oddQ);
        }
    }
    public static void id25(){
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
    public static void id7(){
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
    public static void id23(){
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
    public static void id11(){
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
    public static void id5(){
        Scanner scanner = new Scanner(System.in);
        String[] values = scanner.nextLine().split(" ");
        int n = Integer.parseInt(values[0]);
        int x = Integer.parseInt(values[1]);
        int pos = Integer.parseInt(values[2]);
        System.out.println((int) (factorial(n-1) % (10E9 + 7)));
    }
    public static long factorial(int n) {
        if (n <= 2) {
            return n;
        }
        return n * factorial(n - 1);
    }
    public static void id13() {
        Scanner scanner = new Scanner(System.in);
        String[] values = scanner.nextLine().split(" ");
        int N = Integer.parseInt(values[0]), a = 0, b = 0, c = 0;
        for (int i = 1; i < values.length; i++) {
            int val = Integer.parseInt(values[i]);
            if (i == 1) a = val;
            if (i == 2) b = val;
            if (i == 3) c = val;
        }
        int min = Math.min(a, Math.min(b, c));
        int max = Math.max(a, Math.max(b, c));
        int mid = min;
        for (String value : values) {
            int val = Integer.parseInt(value);
            if (val > min && val < max) mid = val;
        }
        int ribbons, length;
        if (N % min == 0) {
            System.out.println(N / min);
            return;
        }
        ribbons = (int) Math.floor(N / (double) min) - 1;
        length = ribbons * min;
        int diff = N - length;
        if (diff % mid == 0) {
            System.out.println(ribbons + diff / mid);
        } else if (diff % max == 0) {
            System.out.println(ribbons + diff / max);
        } else {
            boolean canMax = false;
            while (true) {
                length -= min;
                ribbons--;
                diff = N - length;
                if (diff % mid == 0) {
                    System.out.println(ribbons + diff / mid);
                    return;
                } else if (diff % max == 0) {




                } else if (diff == mid + max) {
                    System.out.println(ribbons + 2);
                    return;
                }
                if (diff % max == 0) {
                    canMax = true;
                }
            }
        }
    }
    public static void id26(){
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
    public static void id16(){
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
    public static void id56(){
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
    public static void id30(){
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
    public static void id57(){
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
    public static void id27(){
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
    public static void id21(){
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
    public static void id43(){
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());
        int c = Integer.parseInt(scanner.nextLine());
        System.out.println(Math.max(a*b*c, Math.max(a*(b+c), Math.max(a+b*c, Math.max((a+b)*c, a+b+c)))));
    }
    public static void id40(){
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
    public static void id41(){
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        System.out.println((word.contains("h") && word.contains("e") && word.contains("l") && word.contains("o") &&
                word.indexOf("h") < word.indexOf("e", word.indexOf("h")+1) &&
                word.indexOf("e", word.indexOf("h")+1) < word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1) &&
                word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1) < word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1) &&
                word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1) < word.indexOf("o", word.indexOf("l", word.indexOf("l", word.indexOf("e", word.indexOf("h")+1)+1)+1))) ? "YES" : "NO");
    }
    public static void id50(){
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
    public static void id14(){
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
    public static void id44(){
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        System.out.println(word.substring(0, 1).toUpperCase() + word.substring(1));
    }
    public static void id49(){
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
    public static void id46(){
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
    public static void id54(){
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
    public static void id19(){
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
    public static void id6(){
        Scanner scanner = new Scanner(System.in);
        String[] mn = scanner.nextLine().split(" ");
        int m = Integer.parseInt(mn[0]);
        int n = Integer.parseInt(mn[1]);
        System.out.println(m*n/2);
    }
    public static void id28(){
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
    public static void id9(){
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
    public static void id55(){
        Scanner scanner = new Scanner(System.in);
        String[] nma = scanner.nextLine().split(" ");
        double n = Integer.parseInt(nma[0]);
        double m = Integer.parseInt(nma[1]);
        double a = Integer.parseInt(nma[2]);
        System.out.println(Math.round(Math.ceil(n/a)*Math.ceil(m/a)));
    }
    public static void id45(){
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
    public static void id47(){
        Scanner scanner = new Scanner(System.in);
        int weight = Integer.parseInt(scanner.nextLine());
        if(weight <= 3 || weight % 2 == 1){
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}
