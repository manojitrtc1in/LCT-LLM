import java.util.Scanner;

public class 98f17ebeb532f8f9ab01cecf73d0d924_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[][] board = new char[8][8];
        for (int i = 0; i < 8; i++) {
            board[i] = scanner.next().toCharArray();
        }
        int total = 0;
        for (int i = 0; i < 8; i++) {
            int count = 0;
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'B') {
                    count++;
                }
            }
            if (count == 8) {
                for (int j = 0; j < 8; j++) {
                    board[i][j] = 'A';
                }
                total++;
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[j][i] == 'B') {
                    total++;
                    break;
                }
            }
        }
        System.out.println(total);
    }
}
