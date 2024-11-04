import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int ans = 3;
        if (a % m == 1) {
            ans -= 1;
        }
        if (b % m == 0 || b == n) {
            ans -= 1;
        }
        if (m == 1) {
            System.out.println(1);
            System.exit(0);
        } else if ((a - 1) / m == (b - 1) / m) {
            System.out.println(1);
            System.exit(0);
        } else if ((a % m - b % m) % m == 1) {
            System.out.println(Math.min(2, ans, (b - 1) / m - (a - 1) / m + 1));
            System.exit(0);
        }
        System.out.println(Math.min(ans, (b - 1) / m - (a - 1) / m + 1));
    }
}
