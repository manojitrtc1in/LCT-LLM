
import java.util.*;
import java.io.*;

public class id6 {

    public static void pri_result(int i) {
        System.out.println(i);
        System.exit(0);
    }

    public static void SolveA() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[] a = new int[t];
        int[] b = new int[t];
        for (int i = 0; i < t; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        for (int i = 0; i < t; i++) {
            int answer;

            answer = Math.max(2 * b[i], a[i]);
            answer = Math.min(answer, Math.max(2 * a[i], b[i]));
            answer = Math.min(answer, a[i] + b[i]);
            System.out.println(answer * answer);

            

        }
        System.exit(0);
    }

    public static void SolveC() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int odd_i = 0;
            int even_i = 0;
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
                if (a[j] % 2 == 0) {
                    even_i++;
                } else {
                    odd_i++;
                }
            }
            Arrays.sort(a);

            int id7 = 0;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] + 1 == a[j + 1]) {
                    id7++;
                    j++;
                }
            }

            if (even_i % 2 <= id7) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

            

        }
        System.exit(0);
    }

    public static void SolveB() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] s = new int[n];
            for (int j = 0; j < n; j++) {
                s[j] = sc.nextInt();
            }

            Arrays.sort(s);
            int answer = s[1] - s[0];
            for (int j = 1; j < n - 1; j++) {
                answer = Math.min(answer, s[j + 1] - s[j]);
            }

            System.out.println(answer);

            

        }
        System.exit(0);
    }

    public static void SolveD() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            boolean found = false;

            int n = sc.nextInt();
            int k = sc.nextInt();
            int id1 = (int) (Math.sqrt(1.0 * n));
            for (int j = 1; j <= id1 && !found; j++) {
                if (n % j == 0) {
                    if (n / j <= k) {
                        System.out.println(j);
                        found = true;
                    }
                }
            }

            for (int j = id1; j >= 1 && !found; j--) {
                if (n % j == 0) {
                    if (j <= k) {
                        System.out.println(n / j);
                        found = true;
                    }
                }
            }




            

        }
        System.exit(0);
    }

    public static void SolveE() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            boolean[][] matrix = new boolean[n][n];
            sc.nextLine();
            for (int j = 0; j < n; j++) {
                String temp = sc.nextLine();
                for (int j2 = 0; j2 < n; j2++) {
                    if (temp.charAt(j2) == '1') {
                        matrix[j][j2] = true;
                    }
                }

            }

            boolean valid = true;
            for (int j = n - 2; j >= 0 && valid; j--) {
                for (int k = j; k >= 0 && valid; k--) {
                    if (matrix[j][k]) {
                        if (!matrix[j][k + 1] && !matrix[j + 1][k]) {
                            valid = false;
                        }
                    }
                    if (matrix[k][j]) {
                        if (!matrix[k][j + 1] && !matrix[k + 1][j]) {
                            valid = false;
                        }
                    }
                }
            }
            if (valid) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        System.exit(0);
    }

    public static void SolveF() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] s = new char[n][m];
            sc.nextLine();
            

            for (int j = 0; j < n; j++) {
                String temp = sc.nextLine();
                for (int j2 = 0; j2 < m; j2++) {
                    s[j][j2] = temp.charAt(j2);
                }
            }
            

            boolean ok = true;
            char[] answer = new char[m];
            char[] answer2 = new char[m];
            for (int j2 = 0; j2 < m; j2++) {
                answer[j2] = s[0][j2];
                answer2[j2] = s[0][j2];
            }

            boolean found = false;
            for (int j = 1; j < n && ok && !found; j++) {
                int diff_n = 0;
                for (int j2 = 0; j2 < m; j2++) {
                    if (answer[j2] != s[j][j2]) {
                        diff_n++;
                    }
                }
                if (diff_n > 2) {
                    ok = false;
                }
                if (diff_n == 2) {
                    found = true;
                    boolean first = true;
                    for (int j2 = 0; j2 < m; j2++) {
                        if (answer[j2] != s[j][j2]) {
                            if (first) {
                                answer[j2] = s[j][j2];
                                first = false;
                            } else {
                                answer2[j2] = s[j][j2];
                            }
                        }
                    }
                }
            }





































            int d_n = 0;
            int id5 = 0;
            for (int j = 1; j < n && ok; j++) {
                int diff_n = 0;
                int id3 = 0;
                for (int j2 = 0; j2 < m; j2++) {
                    if (answer[j2] != s[j][j2]) {
                        diff_n++;
                    }
                    if (answer2[j2] != s[j][j2]) {
                        id3++;
                    }
                }
                d_n = Math.max(d_n, diff_n);
                id5 = Math.max(id5, id3);
                if (d_n > 1 && id5 > 1) {
                    ok = false;
                }
            }

            if (ok) {
                if (d_n < 2) {
                    for (int j2 = 0; j2 < m; j2++) {
                        System.out.print(answer[j2]);
                    }
                } else {
                    for (int j2 = 0; j2 < m; j2++) {
                        System.out.print(answer2[j2]);
                    }
                }
                System.out.println();
            } else {
                System.out.println("-1");
            }
        }
        System.exit(0);
    }

    public static int calpc(char[] pc) {
        int k1 = 1;
        int pc1 = 0;
        for (int k = 3; k >= 0; k--) {
            pc1 += (pc[k] - '0') * k1;
            k1 *= 10;
        }
        return pc1;
    }

    public static void id11() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (n * a != m * b) {
                System.out.println("NO");
                continue;
            }
            System.out.println("YES");

            if (n % b == 0) {
                int starting_a = 0;
                for (int j = 0; j < n / b; j++) {

                    for (int j2 = 0; j2 < b; j2++) {
                        for (int j3 = 0; j3 < starting_a; j3++) {
                            System.out.print("0");
                        }
                        for (int j3 = starting_a; j3 < starting_a + a; j3++) {
                            System.out.print("1");
                        }

                        for (int j3 = starting_a + a; j3 < m; j3++) {
                            System.out.print("0");
                        }
                        System.out.println("");
                    }
                    starting_a += a;




                }
            } else {
                int starting_a = 0;
                int[][] matrix = new int[n][m];
                for (int j = 0; j < n; j++) {
                    for (int j2 = 0; j2 < a; j2++) {
                        matrix[j][(j2 + starting_a) % m] = 1;
                    }
                    starting_a++;
                }
                for (int j = 0; j < n; j++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        System.out.print(matrix[j][j2]);
                    }
                    System.out.println();
                }




            }
        }
        System.exit(0);
    }

    public static void SolveG() {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(new BufferedOutputStream(System.out));        
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (n * a != m * b) {
                pw.println("NO");
                continue;
            }
            pw.println("YES");

            int shift;
            for (shift = 1; shift < m; shift++) {
                if (shift * n % m == 0) {
                    break;
                }
            }

            int[][] matrix = new int[n][m];
            for (int j = 0, dx = 0; j < n; j++, dx += shift) {
                for (int j2 = 0; j2 < a; j2++) {
                    matrix[j][(j2 + dx) % m] = 1;
                }
            }

            for (int j = 0; j < n; j++) {
                for (int j2 = 0; j2 < m; j2++) {
                    pw.print(matrix[j][j2]);
                }
                pw.println();
            }

        }
        pw.close();
        System.exit(0);
    }

    public static char upp(char pc) {
        if (pc == '9') {
            return '0';
        } else {
            return (++pc);
        }
    }

    public static void id9() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            char[][] p = new char[n][4];
            int[] p1 = new int[n];
            HashSet<Integer> ap = new HashSet();
            HashSet<Integer> ap1 = new HashSet();
            int changes = 0;

            for (int j = 0; j < n; j++) {
                p[j] = sc.next().toCharArray();
                p1[j] = calpc(p[j]);
                ap.add(p1[j]);
                ap1.add(p1[j]);
            }

            for (int j = 0; j < n; j++) {
                if (ap1.contains(p1[j])) {
                    ap1.remove(p1[j]);
                    continue;
                }
                changes++;
                

                for (int k = 0; k < 4; k++) {
                    

                    char savec = p[j][k];
                    p[j][k] = upp(p[j][k]);
                    int pcnew = calpc(p[j]);
                    if (!ap.contains(pcnew)) {
                        ap.add(pcnew);
                        break;
                    }
                    p[j][k] = upp(p[j][k]);
                    pcnew = calpc(p[j]);
                    if (!ap.contains(pcnew)) {
                        ap.add(pcnew);
                        break;
                    }
                    p[j][k] = savec;
                    if (p[j][k] == '0') {
                        p[j][k] = '9';
                    } else {
                        p[j][k]--;
                    }
                    pcnew = calpc(p[j]);
                    if (!ap.contains(pcnew)) {
                        ap.add(pcnew);
                        break;
                    }
                    p[j][k] = savec;
                }
            }
            System.out.println(changes);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    System.out.print(p[j][k]);
                }
                System.out.println();
            }
        }
        System.exit(0);
    }

    public static void id0() {
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int n;
        for (int i = 0; i < t; i++) {
            n = sc.nextInt();
            int total = 3;
            ArrayList<Integer> f = new ArrayList();
            ArrayList<Integer> b = new ArrayList();
            f.add(0);
            f.add(1);
            b.add(n);
            if (n == 1) {
                total = 2;
                out.println(total);
                out.println("0 1");
                continue;
            }

            int mid = (int) Math.round(Math.sqrt(1.0 * n));
            int low = 1;
            int upp = n;
            for (int j = 2; j <= mid; j++) {
                if (j * j > n) {
                    break;
                }
                if (j * j == n) {
                    f.add(j);
                    break;
                }
                int id10 = n / j;
                if (id10 < upp) {
                    if (id10 > j) {
                        f.add(j);
                        b.add(id10);
                        upp = id10;
                    } else {
                        if (id10 == j) {
                            f.add(j);
                            break;
                        }
                    }
                }

            }
            out.println(f.size() + b.size());
            for (int j = 0; j < f.size(); j++) {
                out.print(f.get(j) + " ");
            }
            for (int j = b.size() - 1; j >= 0; j--) {
                out.print(b.get(j));
                if (j > 0) {
                    out.print(" ");
                }
            }
            out.println();
        }
        out.close();
        System.exit(0);
    }

    public static int find(int[] ar, int i) {
        if (ar[i] == 0) {
            return i;
        }
        return find(ar, ar[i]);
    }

    public static void union(int[] ar, int x, int y) {
        int rx = find(ar, x);
        int ry = find(ar, y);
        if (rx == ry) 

        

        

        

        

        {
            return;
        }
        if (rx < ry) {
            ar[ry] = rx;
        } else {
            ar[rx] = ry;
        }
    }

    static PrintWriter pw;

    public static void id2() {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        ArrayList<Integer>[] ac = new ArrayList[26]; 

        int[] ar = new int[n + 1];  


        for (int i = 0; i < 26; i++) {
            ac[i] = new ArrayList();
        }

        for (int i = 1; i <= n; i++) {
            char[] oneline = sc.next().toCharArray(); 

            for (int j = 0; j < oneline.length; j++) {
                int curri = oneline[j] - 'a';
                if (ac[curri].isEmpty()) {
                    if (ar[i] == 0) {
                        ac[curri].add(i);
                        

                    } else {
                        union(ar, ar[i], i);
                        ac[curri].add(ar[i]);
                    }

                } else {
                    union(ar, ac[curri].get(0), find(ar, i));
                }
            }
        }
        int total = 0;
        HashSet<Integer> rootset = new HashSet();
        for (int i = 0; i < 26; i++) {
            if (!ac[i].isEmpty()) {
                int index = ac[i].get(0);
                if (!rootset.contains(index) && ar[index] == 0) {
                    total++;
                    rootset.add(index);
                }
            }
        }
        pw.println(total);

        pw.close();

    }

    public static void dfs(int i, boolean[] used, ArrayList<Integer>[] ac) {
        used[i] = true;
        for (int j = 0; j < ac[i].size(); j++) {
            int nextn = ac[i].get(j);
            if (!used[nextn]) {
                dfs(nextn, used, ac);
            }
        }
    }

    public static void id4() {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        ArrayList<Integer>[] ac = new ArrayList[n + 26]; 

        boolean[] used = new boolean[n + 26];

        for (int i = 0; i < n + 26; i++) {
            ac[i] = new ArrayList();
        }

        for (int i = 0; i < n; i++) {
            char[] oneline = sc.next().toCharArray(); 

            for (int j = 0; j < oneline.length; j++) {
                int curri = n + oneline[j] - 'a';
                ac[curri].add(i);
                ac[i].add(curri);
            }
        }
        int total = 0;
        for (int i = n; i < n + 26; i++) {
            if (ac[i].size() != 0 && !used[i]) {
                total++;
                dfs(i, used, ac);
            }
        }
        pw.println(total);

        pw.close();

    }

    static int find_i(long value, long[] d) {
        for (int i = 0; i < d.length; i++) {
            if (d[i] <= value) {
                return i + 1;
            }
        }
        return d.length;
    }

    

    

    

    

    public static void id8() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] d = new int[n + 1][n + 1];
        int[] partialSum = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            d[1][i] = sc.nextInt();
            partialSum[i] += partialSum[i - 1] + d[1][i];
        }

        for (int i = 2; i <= n; i++) {
            for (int i2 = 1; i2 <= n - i + 1; i2++) {
                d[i][i2] = partialSum[i + i2 - 1] - partialSum[i2 - 1]
                        + Math.max(d[i - 1][i2], d[i - 1][i2 + 1]);
            }
        }
        System.out.println(d[n][1]);
    }

    public static void main(String args[]) {
        

        

        

        

        

        

        

        SolveG();
        

    }
}
