#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class IO {
public:
    static int readInt() {
        int num;
        cin >> num;
        return num;
    }

    static long long readLong() {
        long long num;
        cin >> num;
        return num;
    }

    static string readString() {
        string str;
        cin >> str;
        return str;
    }

    static vector<int> readIntArray(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static vector<long long> readLongArray(int n) {
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static vector<string> readStringArray(int n) {
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static void writeIntArray(vector<int>& arr, string sep = " ", bool endline = true) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1) {
                cout << sep;
            }
        }
        if (endline) {
            cout << endl;
        }
    }

    static void writeLongArray(vector<long long>& arr, string sep = " ", bool endline = true) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1) {
                cout << sep;
            }
        }
        if (endline) {
            cout << endl;
        }
    }

    static void writeStringArray(vector<string>& arr, string sep = " ", bool endline = true) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1) {
                cout << sep;
            }
        }
        if (endline) {
            cout << endl;
        }
    }

    static void writeInt(int num, string end = " ") {
        cout << num << end;
    }

    static void writeLong(long long num, string end = " ") {
        cout << num << end;
    }

    static void writeString(string str, string end = " ") {
        cout << str << end;
    }

    static void writeEndline() {
        cout << endl;
    }
};

class Math {
public:
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static float gcd(float a, float b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, fmod(a, b));
    }

    static double gcd(double a, double b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, fmod(a, b));
    }

    static double lcm(double a, double b) {
        return a / gcd(a, b) * b;
    }

    static float lcm(float a, float b) {
        return a / gcd(a, b) * b;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    static long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    static double log(double value, int base) {
        return log(value) / log(base);
    }

    static long long factorial(int number) {
        if (number < 0) {
            return 0;
        }
        return id8(number);
    }

private:
    static long long id8(int number) {
        if (number > 0) {
            return id8(number - 1) * number;
        }
        return 1;
    }
};

class Pair {
public:
    template <typename T, typename T1>
    static pair<T, T1> createPair(T first, T1 second) {
        return make_pair(first, second);
    }
};

class Fraction {
public:
    template <typename T>
    static pair<T, T> createFraction(T dividend, T divider) {
        T gcd = Math::gcd(dividend, divider);
        return make_pair(dividend / gcd, divider / gcd);
    }
};

class Graph {
public:
    static vector<vector<int>> base;
    static vector<bool> used;
    static int quantity;
    static vector<int> ancestor;

    static vector<vector<int>> getBase() {
        return base;
    }

    static vector<bool> getUsed() {
        return used;
    }

    static int getQuantity() {
        return quantity;
    }

    static vector<int> getAncestor() {
        return ancestor;
    }

    static void setBase(vector<vector<int>>& newBase) {
        base = newBase;
    }

    static void start(int length) {
        used = vector<bool>(length, false);
        ancestor = vector<int>(length, -1);
        quantity = 0;
    }

    static void dfs(int position) {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].size(); index++) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            }
        }
    }
};

vector<vector<int>> Graph::base;

vector<bool> Graph::used;

int Graph::quantity;

vector<int> Graph::ancestor;

class FastSort {
public:
    static vector<int> sort(vector<int>& array, int id17) {
        sort(array, id17, array.size());
        return array;
    }

private:
    static void sort(vector<int>& array, int id17, int length) {
        if (id17 < 0 || id17 > 4) {
            id17 = rand() % 4;
        }
        if (id17 == 0) {
            ShellSort(array);
        } else if (id17 == 1) {
            HeapSort(array);
        } else if (id17 == 2) {
            MergeSort(array, 0, length - 1);
        } else if (id17 == 3) {
            id13(array, length);
        } else if (id17 == 4) {
            id7(array);
        }
    }

    static void id13(vector<int>& array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size >> 1) + ((size % 2) == 0 ? 0 : 1);
        vector<vector<int>> ZeroBuffer(length + length % 2, vector<int>(2));
        vector<vector<int>> FirstBuffer;
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index << 1;
            int id20 = (index << 1) + 1;
            if (id20 < size) {
                if (array[ArrayIndex] > array[id20]) {
                    ZeroBuffer[index][0] = array[id20];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[id20];
                }
            } else {
                ZeroBuffer[index][0] = array[ArrayIndex];
            }
        }
        bool position = false;
        int pointer0, pointer, pointer1, number = 4, NewPointer, count;
        vector<vector<int>> NewBuffer;
        vector<vector<int>> OldBuffer;
        length = (size >> 2) + ((size % 4) == 0 ? 0 : 1);
        while (true) {
            pointer0 = 0;
            count = (number >> 1) - 1;
            if (!position) {
                FirstBuffer = vector<vector<int>>(length + length % 2, vector<int>(number));
                NewBuffer = FirstBuffer;
                OldBuffer = ZeroBuffer;
            } else {
                ZeroBuffer = vector<vector<int>>(length + length % 2, vector<int>(number));
                NewBuffer = ZeroBuffer;
                OldBuffer = FirstBuffer;
            }
            for (int i = 0; i < length; i++) {
                pointer = 0;
                pointer1 = 0;
                NewPointer = pointer0 + 1;
                if (length == 1) {
                    for (int g = 0; g < size; g++) {
                        if (pointer > count || OldBuffer[pointer0][pointer] == 0) {
                            array[g] = OldBuffer[NewPointer][pointer1];
                            pointer1++;
                        } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == 0) {
                            if (OldBuffer[pointer0][pointer] == 0) {
                                continue;
                            }
                            array[g] = OldBuffer[pointer0][pointer];
                            pointer++;
                        } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                            array[g] = OldBuffer[NewPointer][pointer1];
                            pointer1++;
                        } else {
                            array[g] = OldBuffer[pointer0][pointer];
                            pointer++;
                        }
                    }
                    return;
                }
                for (int g = 0; g < number; g++) {
                    if (pointer > count || OldBuffer[pointer0][pointer] == 0) {
                        if (OldBuffer[NewPointer][pointer1] == 0) {
                            continue;
                        }
                        NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == 0) {
                        if (OldBuffer[pointer0][pointer] == 0) {
                            continue;
                        }
                        NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                        NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else {
                        NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    }
                }
                pointer0 += 2;
            }
            position = !position;
            length = (length >> 1) + length % 2;
            number <<= 1;
        }
    }

    static void ShellSort(vector<int>& array) {
        int j;
        for (int gap = (array.size() >> 1); gap > 0; gap >>= 1) {
            for (int i = gap; i < array.size(); i++) {
                int temp = array[i];
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
    }

    static void HeapSort(vector<int>& array) {
        for (int i = (array.size() >> 1) - 1; i >= 0; i--)
            shiftDown(array, i, array.size());
        for (int i = array.size() - 1; i > 0; i--) {
            swap(array, 0, i);
            shiftDown(array, 0, i);
        }
    }

    static void shiftDown(vector<int>& array, int i, int n) {
        int child;
        int tmp;
        for (tmp = array[i]; leftChild(i) < n; i = child) {
            child = leftChild(i);
            if (child != n - 1 && (array[child] < array[child + 1]))
                child++;
            if (tmp < array[child])
                array[i] = array[child];
            else
                break;
        }
        array[i] = tmp;
    }

    static int leftChild(int i) {
        return (i << 1) + 1;
    }

    static void swap(vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static void MergeSort(vector<int>& array, int low, int high) {
        if (low < high) {
            int mid = (low + high) >> 1;
            MergeSort(array, low, mid);
            MergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    static void merge(vector<int>& array, int low, int mid, int high) {
        int n = high - low + 1;
        vector<int> Temp(n);
        int i = low, j = mid + 1;
        int k = 0;
        while (i <= mid || j <= high) {
            if (i > mid)
                Temp[k++] = array[j++];
            else if (j > high)
                Temp[k++] = array[i++];
            else if (array[i] < array[j])
                Temp[k++] = array[i++];
            else
                Temp[k++] = array[j++];
        }
        for (j = 0; j < n; j++)
            array[low + j] = Temp[j];
    }

    static void id7(vector<int>& elements) {
        for (int i = 1; i < elements.size(); i++) {
            int key = elements[i];
            int j = i - 1;
            while (j >= 0 && key < elements[j]) {
                elements[j + 1] = elements[j];
                j--;
            }
            elements[j + 1] = key;
        }
    }
};

class Main {
public:
    static void main() {
        int g = IO::readInt();
        int sh = IO::readInt();
        int j = IO::readInt();
        int p = IO::readInt();
        int priceFirst = IO::readInt();
        int priceSecond = IO::readInt();
        long long answer = 0;
        if (priceFirst <= priceSecond) {
            answer = min(min(sh, j), p);
            p -= answer;
            answer *= priceSecond;
            answer += (min(p, g) * priceFirst);
        } else {
            answer = min(g, p);
            p -= answer;
            answer *= priceFirst;
            answer += (min(min(sh, j), p) * priceSecond);
        }
        IO::writeLong(answer, "\n");
    }
};

int main() {
    Main::main();
    return 0;
}
