import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        int an = a.length();
        int cn = c.length();
        int[] t = new int[cn];
        int[][] tt = new int[cn][2];
        for (int i = 0; i < cn; i++) {
            int k = 0;
