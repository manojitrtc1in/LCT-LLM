import java.util.*;

class Main {
    static class Vert {
        int[] hoge;

        Vert() {
            hoge = new int[5];
        }
    }

    static boolean sign(Vert a, Vert b) {
        int hoge = 0;
        for (int q = 0; q < 5; q++) {
            hoge += a.hoge[q] * b.hoge[q];
        }
        return hoge <= 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Vert[] inputs = new Vert[n];
        for (int i = 0; i < n; i++) {
            inputs[i] = new Vert();
            for (int q = 0; q < 5; q++) {
                inputs[i].hoge[q] = sc.nextInt();
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int ok = 1;
            for (int q = 0; q < n; q++) {
                if (i == q)
                    continue;
                for (int j = q + 1; j < n; j++) {
                    if (i == j)
                        continue;
                    Vert A = new Vert();
                    Vert B = new Vert();
                    for (int t = 0; t < 5; t++) {
                        A.hoge[t] = inputs[q].hoge[t] - inputs[i].hoge[t];
                        B.hoge[t] = inputs[j].hoge[t] - inputs[i].hoge[t];
                    }
                    if (!sign(A, B)) {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
            if (ok == 1) {
                ans.add(i);
            }
        }
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            System.out.print((ans.get(i) + 1) + " ");
        }
        System.out.println();
    }
}
