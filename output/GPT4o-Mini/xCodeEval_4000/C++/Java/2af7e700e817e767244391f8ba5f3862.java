import java.util.*;
import java.io.*;

public class 2af7e700e817e767244391f8ba5f3862_nc {
    static class Vert {
        int[] hoge = new int[5];
    }

    static boolean sign(Vert a, Vert b) {
        int hoge = 0;
        for (int q = 0; q < 5; q++) {
            hoge += a.hoge[q] * b.hoge[q];
        }
        return hoge <= 0;
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Vert> inputs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Vert a = new Vert();
            for (int q = 0; q < 5; q++) {
                a.hoge[q] = scanner.nextInt();
            }
            inputs.add(a);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            boolean ok = true;
            for (int q = 0; q < n; q++) {
                if (i == q) continue;
                for (int j = q + 1; j < n; j++) {
                    if (i == j) continue;
                    Vert A = new Vert(), B = new Vert();
                    for (int t = 0; t < 5; t++) {
                        A.hoge[t] = inputs.get(q).hoge[t] - inputs.get(i).hoge[t];
                        B.hoge[t] = inputs.get(j).hoge[t] - inputs.get(i).hoge[t];
                    }
                    if (!sign(A, B)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                ans.add(i);
            }
        }
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            System.out.print((ans.get(i) + 1) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        solve();
    }
}
