import java.io.*;
import java.util.*;

public class 740e90195c9f13aa59368b55eb1e7676xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String path = nextWord(scanner);
        int x = 0, y = 0;
        Set<Long> visited = new HashSet<>();
        visited.add(0L);
        
        for (char c : path.toCharArray()) {
            switch (c) {
                case 'U':
                    y--;
                    break;
                case 'D':
                    y++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
            if (visited.contains((long) (x * 1000 + y))) {
                System.out.println("BUG");
                return;
            }
            int count = 0;
            if (visited.contains((long) ((x - 1) * 1000 + y))) count++;
            if (visited.contains((long) ((x + 1) * 1000 + y))) count++;
            if (visited.contains((long) (x * 1000 + (y - 1)))) count++;
            if (visited.contains((long) (x * 1000 + (y + 1)))) count++;
            if (count > 1) {
                System.out.println("BUG");
                return;
            }
            visited.add((long) (x * 1000 + y));
        }
        System.out.println("OK");
    }

    private static String nextWord(Scanner scanner) {
        while (scanner.hasNext()) {
            return scanner.next();
        }
        return "";
    }
}
