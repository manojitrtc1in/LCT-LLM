import java.util.*;

class Int {
    private int[] arr;
    private int sign;
    public static int size;
    public static int max = 1000000000;

    public Int(String a) {
        arr = new int[size + 1];
        Arrays.fill(arr, 0);
        sign = 0;
        if (a.charAt(0) == '-') {
            sign = 1;
            a = a.substring(1);
        }
        arr[0] = 0;
        while (a.length() > 9) {
            arr[0]++;
            arr[arr[0]] = num(a.substring(a.length() - 9));
            a = a.substring(0, a.length() - 9);
        }
        arr[0]++;
        arr[arr[0]] = num(a);
    }

    public Int(Int a) {
        arr = new int[size + 1];
        Arrays.fill(arr, 0);
        arr[0] = a.getArr()[0];
        System.arraycopy(a.getArr(), 1, arr, 1, arr[0]);
        sign = a.getSign();
    }

    public Int assign(Int a) {
        if (this != a) {
            arr = new int[size + 1];
            Arrays.fill(arr, 0);
            arr[0] = a.getArr()[0];
            System.arraycopy(a.getArr(), 1, arr, 1, arr[0]);
            sign = a.getSign();
        }
        return this;
    }

    public Int assign(String a) {
        return assign(new Int(a));
    }

    public boolean greaterThan(Int a) {
        int[] brr = a.getArr();
        if (sign != a.getSign())
            return sign < a.getSign();
        if (sign == 0) {
            if (arr[0] != brr[0])
                return arr[0] > brr[0];
            for (int i = arr[0]; i >= 1; i--)
                if (arr[i] != brr[i])
                    return arr[i] > brr[i];
            return false;
        }
        if (arr[0] != brr[0])
            return arr[0] < brr[0];
        for (int i = arr[0]; i >= 1; i--)
            if (arr[i] != brr[i])
                return arr[i] < brr[i];
        return false;
    }

    public boolean lessThan(Int a) {
        return a.greaterThan(this);
    }

    public boolean equals(Int a) {
        return !(a.greaterThan(this) || a.lessThan(this));
    }

    public boolean notEquals(Int a) {
        return !equals(a);
    }

    public boolean lessThanOrEqual(Int a) {
        return !greaterThan(a);
    }

    public boolean greaterThanOrEqual(Int a) {
        return !lessThan(a);
    }

    public Int negate() {
        Int c = new Int(this);
        c.setSign((sign + 1) % 2);
        return c;
    }

    public Int add(Int a) {
        int[] brr = a.getArr();
        int carry = 0, i;

        if (lessThan(new Int("0"))) {
            if (a.lessThan(new Int("0"))) {
                if (arr[0] >= brr[0]) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] + brr[i] + carry;
                        carry = arr[i] / max;
                        arr[i] %= max;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        carry = arr[i] / max;
                        arr[i] %= max;
                        i++;
                    }
                    if (i == arr[0] + 2)
                        arr[0]++;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    assign(d.add(c));
                }
            } else {
                if (equals(new Int(-a)))
                    assign(new Int("0"));
                else if (negate().greaterThan(a)) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] - brr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += max;
                        } else
                            carry = 0;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += max;
                        } else
                            carry = 0;
                        i++;
                    }
                    while (arr[arr[0]] == 0 && arr[0] > 1)
                        arr[0]--;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    assign(d.add(c));
                }
            }
        } else {
            if (a.lessThan(new Int("0"))) {
                if (equals(new Int(-a)))
                    assign(new Int("0"));
                else if (greaterThan(-a)) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] - brr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += max;
                        } else
                            carry = 0;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += max;
                        } else
                            carry = 0;
                        i++;
                    }
                    while (arr[arr[0]] == 0 && arr[0] > 1)
                        arr[0]--;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    assign(d.add(c));
                }
            } else {
                Int c = negate(), d = new Int(-a);
                assign(d.add(c));
            }
        }
        return this;
    }

    public Int add(Int a) {
        return new Int(this).add(a);
    }

    public Int subtract(Int a) {
        return new Int(this).add(negate());
    }

    public Int multiply(Int a) {
        int i;
        if (a.equals(new Int("0")))
            assign(new Int("0"));
        else if (a.equals(str(max))) {
            if (!equals(new Int("0"))) {
                for (i = arr[0]; i >= 1; i--)
                    arr[i + 1] = arr[i];
                arr[1] = 0;
                arr[0]++;
            }
        } else if (abs(a).lessThan(str(max))) {
            long tmp;
            int carry = 0;
            int[] brr = a.getArr();
            for (i = 1; i <= arr[0]; i++) {
                tmp = (long) arr[i] * (long) brr[1] + (long) carry;
                arr[i] = (int) (tmp % max);
                carry = (int) (tmp / max);
            }
            if (carry != 0) {
                arr[i] = carry;
                arr[0]++;
            }
        } else {
            Int tmp, res = new Int("0");
            int[] brr = a.getArr();
            for (i = brr[0]; i >= 1; i--) {
                tmp = multiply(str(brr[i]));
                res = res.multiply(str(max)).add(tmp);
            }
            assign(res);
        }
        sign = (sign + a.getSign()) % 2;
        return this;
    }

    public Int multiply(Int a) {
        Int c = new Int(this);
        return c.multiply(a);
    }

    public String toString() {
        StringBuilder res = new StringBuilder();
        if (sign == 1)
            res.append('-');
        res.append(str(arr[arr[0]]));
        for (int i = arr[0] - 1; i >= 1; i--) {
            int k = max;
            for (int j = 0; j < 9; j++)
                res.append((arr[i] % k) / (k /= 10));
        }
        return res.toString();
    }

    public int[] getArr() {
        return arr;
    }

    public int getSign() {
        return sign;
    }

    public void setSign(int k) {
        sign = k;
    }

    public static Int abs(Int a) {
        return a.lessThan(new Int("0")) ? a.negate() : a;
    }

    public static int num(String a) {
        int res = 0;
        for (int i = 0; i < a.length(); i++)
            res = res * 10 + (a.charAt(i) - '0');
        return res;
    }

    public static String str(int a) {
        StringBuilder res = new StringBuilder();
        int h = (a < 0 ? 1 : 0);
        a = Math.abs(a);
        while (a != 0) {
            res.insert(0, (char) (a % 10 + '0'));
            a /= 10;
        }
        if (res.length() == 0)
            res.append("0");
        if (h == 1)
            res.insert(0, '-');
        return res.toString();
    }

    public static void setSize(int k) {
        size = k;
    }
}

public class d466288ea1696c8492238b770d50afca_nc {
    static int qanak;

    public static Int solve(String s, int h) {
        boolean[] u = new boolean[26];
        Int answer = new Int("1");
        int k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?')
                k++;
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                u[s.charAt(i) - 'A'] = true;
        }
        for (int i = 0; i < k; i++)
            qanak++;

        k = 0;
        for (boolean b : u)
            if (b)
                k++;
        if (k > 10)
            return new Int("0");
        for (int i = 0; i < k; i++)
            answer = answer.multiply(new Int(Int.str(10 - i - h)));
        return answer;
    }

    public static void main(String[] args) {
        qanak = 0;
        Int.setSize(12);
        Int answer = new Int("0");
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        if (s.length() == 1) {
            if (s.charAt(0) == '?' || (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z'))
                answer = new Int("9");
            else
                answer = new Int("1");
            System.out.println(answer);
            return;
        }
        if (s.charAt(0) == '?') {
            String st = s.substring(1);
            answer = answer.multiply(solve(st));
        } else if (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z') {
            for (int k = 1; k < 10; k++) {
                String st = s;
                qanak = 0;
                for (int i = 0; i < st.length(); i++)
                    if (st.charAt(i) == s.charAt(0))
                        st = st.substring(0, i) + (char) ('0' + k) + st.substring(i + 1);
                answer = answer.add(solve(st, 1));
            }
        } else {
            answer = solve(s);
        }
        System.out.print(answer);
        for (int i = 0; i < qanak; i++)
            System.out.print(0);
        System.out.println();
    }
}
