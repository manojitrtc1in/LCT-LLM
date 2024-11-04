import java.util.Scanner;

public class id0 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int row = sc.nextInt();
        int col = sc.nextInt();

        char[][] arr = new char[row][];
        for (int i = 0; i < row; i++) {
            arr[i] = new char[col];

        }

        for (int i = 0; i < row; i++) {
            String x = sc.next();
            for (int j = 0; j < x.length(); j++) {
                arr[i][j] = x.charAt(j);

            }

        }
        int count = 0;
        boolean flag = true;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < col; j++) {
                int x = 0;
                if (row > 1 && col > 1) {
                    if (i == 0 && j == 0) {
                        if (arr[i][j] == '.') {
                            if (arr[i][j + 1] == '*' || arr[i + 1][j] == '*' || arr[i + 1][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j + 1] == '.' || arr[i + 1][j] == '.' || arr[i + 1][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {
                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;
                        }

                    } 

                    

                    else if (i == row - 1 && j == col - 1) {
                        if (arr[i][j] == '.') {
                            if (arr[i][j - 1] == '*' || arr[i - 1][j] == '*' || arr[i - 1][j - 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j - 1] == '.' || arr[i - 1][j] == '.' || arr[i - 1][j - 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j - 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    } 

                    else if (i == 0 && j > 0 && j < (col - 1)) {

                        if (arr[i][j] == '.') {
                            if (arr[i][j - 1] == '*' || arr[i][j + 1] == '*' || arr[i + 1][j - 1] == '*' || arr[i + 1][j] == '*' || arr[i + 1][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j - 1] == '.' || arr[i][j + 1] == '.' || arr[i + 1][j - 1] == '.' || arr[i + 1][j] == '.' || arr[i + 1][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    } 

                    else if (i > 0 && j == 0 && i < (row - 1)) {
                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j] == '*' || arr[i - 1][j + 1] == '*' || arr[i][j + 1] == '*' || arr[i + 1][j] == '*' || arr[i + 1][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j] == '.' || arr[i - 1][j + 1] == '.' || arr[i][j + 1] == '.' || arr[i + 1][j] == '.' || arr[i + 1][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    } 

                    else if (i == 0 && j == (col - 1)) {

                        if (arr[i][j] == '.') {
                            if (arr[i][j - 1] == '*' || arr[i + 1][j - 1] == '*' || arr[i + 1][j] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j - 1] == '.' || arr[i + 1][j - 1] == '.' || arr[i + 1][j] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");

                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    } 

                    else if (i == (row - 1) && j == 0) {

                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j] == '*' || arr[i - 1][j + 1] == '*' || arr[i][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j] == '.' || arr[i - 1][j + 1] == '.' || arr[i][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");

                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    } 

                    else if (i > 0 && j == (col - 1) && i < (row - 1)) {
                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j - 1] == '*' || arr[i - 1][j] == '*' || arr[i][j - 1] == '*' || arr[i + 1][j - 1] == '*' || arr[i + 1][j] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j - 1] == '.' || arr[i - 1][j] == '.' || arr[i][j - 1] == '.' || arr[i + 1][j - 1] == '.' || arr[i + 1][j] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");

                            if (arr[i - 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    } 

                    else if (i == (row - 1) && j > 0 && j < (col - 1)) {

                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j - 1] == '*' || arr[i - 1][j] == '*' || arr[i - 1][j + 1] == '*' || arr[i][j - 1] == '*' || arr[i][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j - 1] == '.' || arr[i - 1][j] == '.' || arr[i - 1][j + 1] == '.' || arr[i][j - 1] == '.' || arr[i][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");

                            if (arr[i - 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    } 

                    else {
                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j - 1] == '*' || arr[i - 1][j] == '*' || arr[i - 1][j + 1] == '*' || arr[i][j - 1] == '*' || arr[i][j + 1] == '*' || arr[i + 1][j - 1] == '*' || arr[i + 1][j] == '*' || arr[i + 1][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j - 1] == '.' || arr[i - 1][j] == '.' || arr[i - 1][j + 1] == '.' || arr[i][j - 1] == '.' || arr[i][j + 1] == '.' || arr[i + 1][j - 1] == '.' || arr[i + 1][j] == '.' || arr[i + 1][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {
                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i - 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j - 1] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (arr[i + 1][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    }
                }
                


                if (row == 1 && col > 1) {
                    if (i == 0 && j == 0) {
                        if (arr[i][j] == '.') {
                            if (arr[i][j + 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j + 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {
                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;
                        }
                    } 

                    else if (i == 0 && j == (col - 1)) {
                        if (arr[i][j] == '.') {
                            if (arr[i][j - 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j - 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    } 

                    else if (i == 0 && j > 0 && j < (col - 1)) {
                        if (arr[i][j] == '.') {
                            if (arr[i][j + 1] == '*' || arr[i][j - 1] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i][j + 1] == '.' || arr[i][j - 1] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i][j + 1] == '*') {
                                count++;
                            }
                            if (arr[i][j - 1] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    }

                    

                }
                if (row > 1 && col == 1) 

                {
                    if (i == 0 && j == 0) {
                        if (arr[i][j] == '.') {
                            if (arr[i + 1][j] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i + 1][j] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    } 

                    else if (i == (row - 1) && j == 0) {
                        if (arr[i][j] == '.') {
                            if (arr[i - 1][j] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i - 1][j] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {

                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }
                    } 

                    else if (i > 0 && i < (row - 1) && j == 0) {
                        if (arr[i][j] == '.') {
                            if (arr[i + 1][j] == '*' || arr[i - 1][j] == '*') {
                                flag = false;
                                break;
                            }

                        } else if (arr[i][j] == '*') {
                            if (arr[i + 1][j] == '.' || arr[i - 1][j] == '.') {
                                flag = false;
                                break;
                            }
                        }
                        if (arr[i][j] != '.' && arr[i][j] != '*') {
                            x = Integer.parseInt(arr[i][j] + "");
                            if (arr[i + 1][j] == '*') {
                                count++;
                            }
                            if (arr[i - 1][j] == '*') {
                                count++;
                            }
                            if (count != x) {
                                flag = false;
                                break;
                            }
                            count = 0;

                        }

                    }

                    

                    

                }
                if (row == 1 && col == 1) {
                    if (arr[i][j]=='*'|| arr[i][j]=='.')
                        flag=true;
                    else{
                    flag = false;
                    break;
                        }
                }
            }

            if (flag == false) {
                break;
            }
        }

        if (flag == true) {
            System.out.println("YES");
        } else if (flag == false) {
            System.out.println("NO");
        }

    }

}
