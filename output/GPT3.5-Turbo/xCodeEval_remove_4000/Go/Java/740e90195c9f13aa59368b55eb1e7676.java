import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class 740e90195c9f13aa59368b55eb1e7676xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String path = nextWord(scanner);
        int x = 0, y = 0;
        Map<Long, Boolean> visited = new HashMap<>();
        visited.put(0L, true);
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
            if (visited.containsKey((long) (x * 1000 + y))) {
                printf("BUG\n");
                return;
            }
            int count = 0;
            if (visited.containsKey((long) ((x - 1) * 1000 + y))) {
                count++;
            }
            if (visited.containsKey((long) ((x + 1) * 1000 + y))) {
                count++;
            }
            if (visited.containsKey((long) (x * 1000 + y - 1))) {
                count++;
            }
            if (visited.containsKey((long) (x * 1000 + y + 1))) {
                count++;
            }
            if (count > 1) {
                printf("BUG\n");
                return;
            }
            visited.put((long) (x * 1000 + y), true);
        }
        printf("OK\n");
    }

    private static String nextLine(Scanner scanner) {
        if (!scanner.hasNextLine()) {
            throw new RuntimeException("nextLine: EOF reached");
        }
        return scanner.nextLine();
    }

    private static String nextWord(Scanner scanner) {
        while (!scanner.hasNext()) {
            String line = nextLine(scanner);
            if (line.isEmpty()) {
                return "";
            }
            scanner = new Scanner(line);
        }
        return scanner.next();
    }

    private static int nextInt(Scanner scanner) {
        try {
            return Integer.parseInt(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    private static long id3(Scanner scanner) {
        try {
            return Long.parseLong(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    private static double id6(Scanner scanner) {
        try {
            return Double.parseDouble(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    private static void printf(String format, Object... args) {
        System.out.printf(format, args);
    }
}
