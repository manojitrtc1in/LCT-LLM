import java.util.*;
import java.io.*;

public class 740e90195c9f13aa59368b55eb1e7676_nc {
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
                System.out.println("BUG");
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
                System.out.println("BUG");
                return;
            }
            visited.put((long) (x * 1000 + y), true);
        }
        System.out.println("OK");
    }

    private static String nextLine(Scanner scanner) {
        if (!scanner.hasNextLine()) {
            throw new NoSuchElementException("nextLine: EOF reached");
        }
        return scanner.nextLine();
    }

    private static String nextWord(Scanner scanner) {
        while (!scanner.hasNext()) {
            if (!scanner.hasNextLine()) {
                return "";
            }
            scanner = new Scanner(nextLine(scanner));
        }
        return scanner.next();
    }

    private static int nextInt(Scanner scanner) {
        try {
            return Integer.parseInt(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    private static long nextLong(Scanner scanner) {
        try {
            return Long.parseLong(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    private static double nextDouble(Scanner scanner) {
        try {
            return Double.parseDouble(nextWord(scanner));
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }
}
