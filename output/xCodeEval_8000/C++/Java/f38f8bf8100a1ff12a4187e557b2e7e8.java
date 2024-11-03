import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> V = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            V.add(scanner.nextInt());
        }
        Collections.sort(V);
        System.out.println(V.get(n / 2));
    }
}
