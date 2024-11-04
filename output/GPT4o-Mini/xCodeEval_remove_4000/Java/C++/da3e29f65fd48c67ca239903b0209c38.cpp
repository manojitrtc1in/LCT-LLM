#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <utility>
#include <stdexcept>

using namespace std;

class Math {
public:
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static float gcd(float a, float b) {
        return b == 0 ? a : gcd(b, a);
    }

    static double gcd(double a, double b) {
        return b == 0 ? a : gcd(b, a);
    }

    static double lcm(double a, double b) {
        return a / gcd(a, b) * b;
    }

    static long factorial(int number) {
        if (number < 0) {
            return 0;
        }
        return id8(number);
    }

private:
    static long id8(int number) {
        return number > 0 ? id8(number - 1) * number : 1;
    }
};

class Main {
public:
    static void main() {
        int g, sh, j, p, priceFirst, priceSecond;
        cin >> g >> sh >> j >> p >> priceFirst >> priceSecond;
        long answer = 0;

        if (priceFirst <= priceSecond) {
            answer = min({sh, j, p});
            p -= answer;
            answer *= priceSecond;
            answer += (min(p, g) * priceFirst);
        } else {
            answer = min(g, p);
            p -= answer;
            answer *= priceFirst;
            answer += (min({sh, j, p}) * priceSecond);
        }
        cout << answer << endl;
    }
};

int main() {
    Main::main();
    return 0;
}
