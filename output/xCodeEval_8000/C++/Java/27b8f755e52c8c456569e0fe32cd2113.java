import java.util.*;

public class 27b8f755e52c8c456569e0fe32cd2113_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cur = scanner.nextInt();
        scanner.nextLine();

        String line1 = scanner.nextLine();
        int len = line1.length();

        String line2 = scanner.nextLine();
        len = line2.length();

        String t1 = line1;
        String t2 = line2;

        int index = -1;
        for (int i = 0; i < 300; i += 2) {
            if (texts[i].equals(t1)) {
                index = i;
                break;
            }
        }

        System.out.println(index / 100 + 1);
    }
}
