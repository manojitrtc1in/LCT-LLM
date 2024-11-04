import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        int n = s.length();
        int m = t.length();

        List<Integer> front = new ArrayList<>();
        List<Integer> back = new ArrayList<>();
        int pos = 0;
        for (int i = 0; i < m; i++) {
            int index = s.indexOf(t.charAt(i), pos);
            front.add(index);
            pos = index + 1;
        }
        pos = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            int index = s.lastIndexOf(t.charAt(i), pos);
            back.add(index);
            pos = index - 1;
        }

        int ans = Math.max(back.get(0), n - 1 - front.get(m - 1));
        for (int i = 0; i < m - 1; i++) {
            ans = Math.max(ans, back.get(i + 1) - front.get(i) - 1);
        }
        System.out.println(ans);
    }
}
