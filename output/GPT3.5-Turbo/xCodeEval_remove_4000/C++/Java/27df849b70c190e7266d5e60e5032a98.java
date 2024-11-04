import java.util.Scanner;

public class 27df849b70c190e7266d5e60e5032a98xcodeeval_processed_4000.json {
    static final int p_N = 1500000;
    static int[] huiwen = new int[p_N];
    static int[] flag = new int[p_N + 5];
    static int[] prime = new int[p_N + 5];
    static int pk = 0;

    public static void get_p() {
        for (int i = 2; i < p_N; i++) {
            if (flag[i] == 0)
                prime[pk++] = i;
            for (int j = 0; i * prime[j] < p_N; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }

    public static void main(String[] args) {
        get_p();
        int ans = 0, t1 = 0, t2 = 0;
        double p, q;
        Scanner sc = new Scanner(System.in);
        p = sc.nextDouble();
        q = sc.nextDouble();
        for (int i = 1; i < 1498941; i++) {
            if (i >= prime[t1]) {
                t1++;
            }
            if (i >= huiwen[t2]) {
                t2++;
            }
            if (t1 <= (t2) * (p / q)) {
                ans = i;
            }
        }
        System.out.println(ans);
    }
}
