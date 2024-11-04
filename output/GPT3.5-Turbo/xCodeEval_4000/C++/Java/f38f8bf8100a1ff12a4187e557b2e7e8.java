import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] V = new int[n];
        for (int i = 0; i < n; i++) {
            V[i] = sc.nextInt();
        }
        Arrays.sort(V);
        System.out.println(V[n / 2]);
    }
}
