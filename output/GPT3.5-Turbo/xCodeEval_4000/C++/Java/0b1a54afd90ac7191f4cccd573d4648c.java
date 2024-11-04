import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Long> a = new ArrayList<>();
        HashMap<Long, Integer> mp = new HashMap<>();
        for (int i = 0; i < N; i++) {
            long num = sc.nextLong();
            a.add(num);
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        ArrayList<Long> b = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            long num = sc.nextLong();
            b.add(num);
        }

        ArrayList<Long> vs = new ArrayList<>();
        for (Map.Entry<Long, Integer> entry : mp.entrySet()) {
            if (entry.getValue() > 1) {
                vs.add(entry.getKey());
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            boolean isok = false;
            for (long elem : vs) {
                if ((elem & a.get(i)) == a.get(i)) {
                    isok = true;
                    break;
                }
            }

            if (isok) {
                ans += b.get(i);
            }
        }

        System.out.println(ans);
    }
}
