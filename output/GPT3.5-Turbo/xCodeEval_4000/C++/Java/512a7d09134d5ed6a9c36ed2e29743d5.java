import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        int n = s.length();
        int m = t.length();

        int[] front = new int[m];
        int[] back = new int[m];
        int pos = 0;
        for (int i = 0; i < m; i++) {
            front[i] = s.indexOf(t.charAt(i), pos);
            pos = front[i] + 1;
        }
        pos = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            back[i] = s.lastIndexOf(t.charAt(i), pos);
            pos = back[i] - 1;
        }

        int ans = Math.max(back[0], n - 1 - front[m - 1]);
        for (int i = 0; i < m - 1; i++) {
            ans = Math.max(ans, back[i + 1] - front[i] - 1);
        }
        System.out.println(ans);
    }
}
