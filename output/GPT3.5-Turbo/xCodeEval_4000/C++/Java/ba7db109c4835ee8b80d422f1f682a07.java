import java.util.Scanner;

public class ba7db109c4835ee8b80d422f1f682a07_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int result = cal(m) - cal(n - 1);
        System.out.println(result);
    }

    public static int cal(int n) {
