import java.util.*;

class Main {
    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        int an = a.length();
        int cn = c.length();

        int[] t = new int[cn];
