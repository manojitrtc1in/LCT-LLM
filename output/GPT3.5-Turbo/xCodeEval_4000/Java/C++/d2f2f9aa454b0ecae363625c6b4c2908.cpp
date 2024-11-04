#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class IO {
public:
    static int readInt() {
        int number;
        cin >> number;
        return number;
    }

    static long long readLong() {
        long long number;
        cin >> number;
        return number;
    }

    static string readString() {
        string word;
        cin >> word;
        return word;
    }

    static vector<int> readArrayInt(string split) {
        vector<int> array;
        string input;
        cin >> input;
        size_t pos = 0;
        while ((pos = input.find(split)) != string::npos) {
            array.push_back(stoi(input.substr(0, pos)));
            input.erase(0, pos + split.length());
        }
        array.push_back(stoi(input));
        return array;
    }

    static vector<long long> readArrayLong(string split) {
        vector<long long> array;
        string input;
        cin >> input;
        size_t pos = 0;
        while ((pos = input.find(split)) != string::npos) {
            array.push_back(stoll(input.substr(0, pos)));
            input.erase(0, pos + split.length());
        }
        array.push_back(stoll(input));
        return array;
    }

    static vector<string> readArrayString(string split) {
        vector<string> array;
        string input;
        cin >> input;
        size_t pos = 0;
        while ((pos = input.find(split)) != string::npos) {
            array.push_back(input.substr(0, pos));
            input.erase(0, pos + split.length());
        }
        array.push_back(input);
        return array;
    }

    static void writeArray(vector<int>& array, string split, bool enter) {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i];
            if (i != array.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(vector<long long>& array, string split, bool enter) {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i];
            if (i != array.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(vector<string>& array, string split, bool enter) {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i];
            if (i != array.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeInt(int number, string end) {
        cout << number << end;
    }

    static void writeLong(long long number, string end) {
        cout << number << end;
    }

    static void writeString(string word, string end) {
        cout << word << end;
    }

    static void writeEnter() {
        cout << endl;
    }
};

class math {
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
};

class Division {
private:
    template<typename T>
    static T gcd(T a, T b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

public:
    template<typename T>
    static pair<T, T> createDivision(T dividend, T divider) {
        T gcd = math::gcd(dividend, divider);
        return make_pair(dividend / gcd, divider / gcd);
    }

    template<typename T>
    static pair<T, T> reduce(pair<T, T> number) {
        T gcd = math::gcd(number.first, number.second);
        return make_pair(number.first / gcd, number.second / gcd);
    }

    template<typename T>
    static void addWithoutReturn(pair<T, T>& number1, pair<T, T> number2) {
        number1.first = number1.first * number2.second + number2.first * number1.second;
        number1.second = number1.second * number2.second;
        number1 = reduce(number1);
    }

    template<typename T>
    static pair<T, T> addWithReturn(pair<T, T> number1, pair<T, T> number2) {
        pair<T, T> result;
        result.first = number1.first * number2.second + number2.first * number1.second;
        result.second = number1.second * number2.second;
        return reduce(result);
    }

    template<typename T>
    static void multiplyWithoutReturn(pair<T, T>& number1, pair<T, T> number2) {
        number1.first = number1.first * number2.first;
        number1.second = number1.second * number2.second;
        number1 = reduce(number1);
    }

    template<typename T>
    static pair<T, T> multiplyWithReturn(pair<T, T> number1, pair<T, T> number2) {
        pair<T, T> result;
        result.first = number1.first * number2.first;
        result.second = number1.second * number2.second;
        return reduce(result);
    }
};

class Pair {
private:
    template<typename T, typename T1>
    static pair<T, T1> make_pair(T element, T1 element1) {
        return make_pair(element, element1);
    }

public:
    template<typename T, typename T1>
    static pair<T, T1> createPair(T element, T1 element1) {
        return make_pair(element, element1);
    }

    template<typename T, typename T1>
    static T getFirstElement(pair<T, T1> p) {
        return p.first;
    }

    template<typename T, typename T1>
    static T1 getSecondElement(pair<T, T1> p) {
        return p.second;
    }

    template<typename T, typename T1>
    static void setFirst(pair<T, T1>& p, T element) {
        p.first = element;
    }

    template<typename T, typename T1>
    static void setSecond(pair<T, T1>& p, T1 element) {
        p.second = element;
    }
};

class Graph {
private:
    vector<vector<int>> base;
    vector<bool> used;
    int quantity;
    vector<int> ancestor;

public:
    vector<vector<int>> getBase() {
        return base;
    }

    vector<bool> getUsed() {
        return used;
    }

    int getQuantity() {
        return quantity;
    }

    vector<int> getAncestor() {
        return ancestor;
    }

    void start(int length) {
        used = vector<bool>(length, false);
        ancestor = vector<int>(length, -1);
        quantity = 0;
    }

    void ribMatrixToDefault(int length, int quantity, bool readConsole, vector<vector<int>> value) {
        base = vector<vector<int>>(length, vector<int>());
        for (int i = 0; i < quantity; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
            base[input[0] - 1].push_back(input[1] - 1);
            base[input[1] - 1].push_back(input[0] - 1);
        }
        start(length);
    }

    void adjacencyMatrixToDefault(int length, int notValue, bool readConsole, vector<vector<int>> value) {
        base = vector<vector<int>>(length, vector<int>());
        for (int i = 0; i < length; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
            for (int index = 0; index < length; index++) {
                if (i != index && input[index] != notValue) {
                    base[i].push_back(index);
                }
            }
        }
        start(length);
    }

    void dfs(int position) {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].size(); index++) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            } else {
                if (next != ancestor[position]) {
                    throw "Exception";
                }
            }
        }
    }

    int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        vector<int> dist(size, INT_MAX);
        for (int i = 0; i < size; i++) {
            if (i != start) {
                dist[i] = INT_MAX;
            }
            ancestor[i] = start;
        }

        vector<pair<int, int>> queue;
        queue.push_back(make_pair(start, 0));
        int position;
        while (!queue.empty()) {
            int minIndex = min_element(queue.begin(), queue.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }) - queue.begin();
            position = queue[minIndex].first;
            if (queue[minIndex].second > dist[position]) {
                queue.erase(queue.begin() + minIndex);
                continue;
            }
            for (int index = 0; index < base[position].size(); index++) {
                if (dist[position] + 1 < dist[base[position][index]] && !used[base[position][index]]) {
                    dist[base[position][index]] = dist[position] + 1;
                    ancestor[base[position][index]] = position;
                    queue.push_back(make_pair(base[position][index], dist[base[position][index]]));
                }
            }
            used[position] = true;
            queue.erase(queue.begin() + minIndex);
        }
        return dist[stop] == INT_MAX ? -1 : dist[stop];
    }

    static bool floydWarshall(vector<vector<int>>& base, int length, int notValue) {
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (base[i][k] == notValue || base[k][j] == notValue) {
                        continue;
                    }
                    int total = base[i][k] + base[k][j];
                    if (base[i][j] != notValue) {
                        base[i][j] = min(base[i][j], total);
                    } else {
                        base[i][j] = total;
                    }
                }
            }
        }
        for (int index = 0; index < length; index++) {
            if (base[index][index] != 0) {
                return false;
            }
        }
        return true;
    }
};

class FastSort {
private:
    static void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    static void shiftDown(vector<int>& array, int i, int n) {
        int child;
        int temp;
        for (temp = array[i]; 2 * i + 1 < n; i = child) {
            child = 2 * i + 1;
            if (child != n - 1 && array[child] < array[child + 1]) {
                child++;
            }
            if (temp < array[child]) {
                array[i] = array[child];
            } else {
                break;
            }
        }
        array[i] = temp;
    }

    static void merge(vector<int>& array, int low, int mid, int high) {
        int n = high - low + 1;
        vector<int> Temp(n);
        int i = low, j = mid + 1;
        int k = 0;
        while (i <= mid || j <= high) {
            if (i > mid) {
                Temp[k++] = array[j++];
            } else if (j > high) {
                Temp[k++] = array[i++];
            } else if (array[i] < array[j]) {
                Temp[k++] = array[i++];
            } else {
                Temp[k++] = array[j++];
            }
        }
        for (j = 0; j < n; j++) {
            array[low + j] = Temp[j];
        }
    }

    static void insertionSort(vector<int>& elements) {
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

public:
    static void sortWithoutReturn(vector<int>& array, int ShellHeapMergeMyInsertionSort) {
        sort(array, ShellHeapMergeMyInsertionSort, array.size());
    }

    static vector<int> sortWithReturn(vector<int>& array, int ShellHeapMergeMyInsertionSort) {
        vector<int> base = array;
        sort(base, ShellHeapMergeMyInsertionSort, base.size());
        return base;
    }

private:
    static void sort(vector<int>& array, int ShellHeapMergeMyInsertionSort, int length) {
        if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
            ShellHeapMergeMyInsertionSort = rand() % 4;
        }
        if (ShellHeapMergeMyInsertionSort == 0) {
            ShellSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 1) {
            HeapSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 2) {
            MergeSort(array, 0, length - 1);
        } else if (ShellHeapMergeMyInsertionSort == 3) {
            straightMergeSort(array, length);
        } else if (ShellHeapMergeMyInsertionSort == 4) {
            insertionSort(array);
        }
    }

    static void ShellSort(vector<int>& array) {
        int j;
        for (int gap = array.size() / 2; gap > 0; gap /= 2) {
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
        for (int i = array.size() / 2 - 1; i >= 0; i--)
            shiftDown(array, i, array.size());
        for (int i = array.size() - 1; i > 0; i--) {
            swap(array[0], array[i]);
            shiftDown(array, 0, i);
        }
    }

    static void straightMergeSort(vector<int>& array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
        vector<vector<int>> ZeroBuffer(length + length % 2, vector<int>(2));
        vector<vector<int>> FirstBuffer;
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index * 2;
            int NextArrayIndex = index * 2 + 1;
            if (NextArrayIndex < size) {
                if (array[ArrayIndex] > array[NextArrayIndex]) {
                    ZeroBuffer[index][0] = array[NextArrayIndex];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[NextArrayIndex];
                }
            } else {
                ZeroBuffer[index][0] = array[ArrayIndex];
            }
        }
        bool position = false;
        int pointer0, pointer, pointer1, number = 4, NewPointer, count;
        vector<vector<int>> NewBuffer;
        vector<vector<int>> OldBuffer;
        length = (size / 4) + ((size % 4) == 0 ? 0 : 1);
        while (true) {
            pointer0 = 0;
            count = (number / 2) - 1;
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
                        if (pointer > count || OldBuffer[pointer0][pointer] == INT_MAX) {
                            array[g] = OldBuffer[NewPointer][pointer1];
                            pointer1++;
                        } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == INT_MAX) {
                            if (OldBuffer[pointer0][pointer] == INT_MAX) {
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
                    if (pointer > count || OldBuffer[pointer0][pointer] == INT_MAX) {
                        if (OldBuffer[NewPointer][pointer1] == INT_MAX) {
                            continue;
                        }
                        NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == INT_MAX) {
                        if (OldBuffer[pointer0][pointer] == INT_MAX) {
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
            length = length / 2 + length % 2;
            number *= 2;
        }
    }

    static void MergeSort(vector<int>& array, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            MergeSort(array, low, mid);
            MergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }
};

int main() {
    int i1 = IO::readInt();
    for (int i2 = 0; i2 < i1; i2++) {
        int min = INT_MAX;
        int quantity[3];
        vector<int> base;
        quantity[0] = IO::readInt();
        quantity[1] = IO::readInt();
        quantity[2] = IO::readInt();
        for (int i = 0; i < quantity[2]; i++) {
            int value = IO::readInt();
            base.push_back(value);
        }
        map<int, int> countValue;
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        min = countValue.size();
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            if (countValue[base[i - quantity[2]]] == 0) {
                countValue.erase(base[i - quantity[2]]);
            }
            countValue[base[i]]++;
            min = min(countValue.size(), min);
        }
        IO::writeInt(min, "\n");
    }
    return 0;
}
