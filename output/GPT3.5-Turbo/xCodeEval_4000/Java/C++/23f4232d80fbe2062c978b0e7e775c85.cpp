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
            string token = input.substr(0, pos);
            array.push_back(stoi(token));
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
            string token = input.substr(0, pos);
            array.push_back(stoll(token));
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
            string token = input.substr(0, pos);
            array.push_back(token);
            input.erase(0, pos + split.length());
        }
        array.push_back(input);
        return array;
    }

    static void writeArray(const vector<int>& array, string split, bool enter) {
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

    static void writeArray(const vector<long long>& array, string split, bool enter) {
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

    static void writeArray(const vector<string>& array, string split, bool enter) {
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

    static void writeString(const string& word, string end) {
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
    static pair<T, T> add(pair<T, T> number1, pair<T, T> number2) {
        T lcm = math::lcm(number1.second, number2.second);
        T numerator = (lcm / number1.second) * number1.first + (lcm / number2.second) * number2.first;
        return createDivision(numerator, lcm);
    }

    template<typename T>
    static pair<T, T> multiply(pair<T, T> number1, pair<T, T> number2) {
        T numerator = number1.first * number2.first;
        T denominator = number1.second * number2.second;
        return createDivision(numerator, denominator);
    }
};

class Pair {
private:
    template<typename T, typename T1>
    static bool equals(T element1, T1 element2) {
        return element1 == element2;
    }

public:
    template<typename T, typename T1>
    static pair<T, T1> createPair(T element1, T1 element2) {
        return make_pair(element1, element2);
    }

    template<typename T, typename T1>
    static bool equals(pair<T, T1> pair1, pair<T, T1> pair2) {
        return equals(pair1.first, pair2.first) && equals(pair1.second, pair2.second);
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
        base = vector<vector<int>>(length);
        for (int i = 0; i < quantity; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
            base[input[0] - 1].push_back(input[1] - 1);
            base[input[1] - 1].push_back(input[0] - 1);
        }
        start(length);
    }

    void adjacencyMatrixToDefault(int length, int notValue, bool readConsole, vector<vector<int>> value) {
        base = vector<vector<int>>(length);
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

        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> queue(compare);
        queue.push(make_pair(start, 0));
        int position;
        while (!queue.empty()) {
            pair<int, int> getQueue = queue.top();
            queue.pop();
            position = getQueue.first;
            if (getQueue.second > dist[position]) {
                continue;
            }
            for (int index = 0; index < base[position].size(); index++) {
                int next = base[position][index];
                if (dist[position] + 1 < dist[next] && !used[next]) {
                    dist[next] = dist[position] + 1;
                    ancestor[next] = position;
                    queue.push(make_pair(next, dist[next]));
                }
            }
            used[position] = true;
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
        for (int i = array.size() / 2 - 1; i >= 0; i--) {
            shiftDown(array, i, array.size());
        }
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
            if (child != n - 1 && (array[child] < array[child + 1])) {
                child++;
            }
            if (tmp < array[child]) {
                array[i] = array[child];
            } else {
                break;
            }
        }
        array[i] = tmp;
    }

    static int leftChild(int i) {
        return 2 * i + 1;
    }

    static void swap(vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static void MergeSort(vector<int>& array, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            MergeSort(array, low, mid);
            MergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    static void merge(vector<int>& array, int low, int mid, int high) {
        int n = high - low + 1;
        vector<int> temp(n);
        int i = low, j = mid + 1;
        int k = 0;
        while (i <= mid || j <= high) {
            if (i > mid) {
                temp[k++] = array[j++];
            } else if (j > high) {
                temp[k++] = array[i++];
            } else if (array[i] < array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }
        for (j = 0; j < n; j++) {
            array[low + j] = temp[j];
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
        sort(array, ShellHeapMergeMyInsertionSort);
    }

    static vector<int> sortWithReturn(const vector<int>& array, int ShellHeapMergeMyInsertionSort) {
        vector<int> base = array;
        sort(base, ShellHeapMergeMyInsertionSort);
        return base;
    }

    static void sort(vector<int>& array, int ShellHeapMergeMyInsertionSort) {
        if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
            srand(time(NULL));
            ShellHeapMergeMyInsertionSort = rand() % 4;
        }
        if (ShellHeapMergeMyInsertionSort == 0) {
            ShellSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 1) {
            HeapSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 2) {
            MergeSort(array, 0, array.size() - 1);
        } else if (ShellHeapMergeMyInsertionSort == 3) {
            straightMergeSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 4) {
            insertionSort(array);
        }
    }

    static void straightMergeSort(vector<int>& array) {
        if (array.size() == 0) {
            return;
        }
        int length = (array.size() / 2) + ((array.size() % 2) == 0 ? 0 : 1);
        vector<vector<int>> zeroBuffer(length + length % 2, vector<int>(2));
        vector<vector<int>> firstBuffer;
        for (int index = 0; index < length; index++) {
            int arrayIndex = index * 2;
            int nextArrayIndex = index * 2 + 1;
            if (nextArrayIndex < array.size()) {
                if (array[arrayIndex] > array[nextArrayIndex]) {
                    zeroBuffer[index][0] = array[nextArrayIndex];
                    zeroBuffer[index][1] = array[arrayIndex];
                } else {
                    zeroBuffer[index][0] = array[arrayIndex];
                    zeroBuffer[index][1] = array[nextArrayIndex];
                }
            } else {
                zeroBuffer[index][0] = array[arrayIndex];
            }
        }
        bool position = false;
        int pointer0, pointer, pointer1, number = 4, newPointer, count;
        vector<vector<int>> newBuffer;
        vector<vector<int>> oldBuffer;
        length = (array.size() / 4) + ((array.size() % 4) == 0 ? 0 : 1);
        while (true) {
            pointer0 = 0;
            count = (number / 2) - 1;
            if (!position) {
                firstBuffer = vector<vector<int>>(length + length % 2, vector<int>(number));
                newBuffer = firstBuffer;
                oldBuffer = zeroBuffer;
            } else {
                zeroBuffer = vector<vector<int>>(length + length % 2, vector<int>(number));
                newBuffer = zeroBuffer;
                oldBuffer = firstBuffer;
            }
            for (int i = 0; i < length; i++) {
                pointer = 0;
                pointer1 = 0;
                newPointer = pointer0 + 1;
                if (length == 1) {
                    for (int g = 0; g < array.size(); g++) {
                        if (pointer > count || oldBuffer[pointer0][pointer] == INT_MAX) {
                            array[g] = oldBuffer[newPointer][pointer1];
                            pointer1++;
                        } else if (pointer1 > count || oldBuffer[newPointer][pointer1] == INT_MAX) {
                            if (oldBuffer[pointer0][pointer] == INT_MAX) {
                                continue;
                            }
                            array[g] = oldBuffer[pointer0][pointer];
                            pointer++;
                        } else if (oldBuffer[pointer0][pointer] >= oldBuffer[newPointer][pointer1]) {
                            array[g] = oldBuffer[newPointer][pointer1];
                            pointer1++;
                        } else {
                            array[g] = oldBuffer[pointer0][pointer];
                            pointer++;
                        }
                    }
                    return;
                }
                for (int g = 0; g < number; g++) {
                    if (pointer > count || oldBuffer[pointer0][pointer] == INT_MAX) {
                        if (oldBuffer[newPointer][pointer1] == INT_MAX) {
                            continue;
                        }
                        newBuffer[i][g] = oldBuffer[newPointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || oldBuffer[newPointer][pointer1] == INT_MAX) {
                        if (oldBuffer[pointer0][pointer] == INT_MAX) {
                            continue;
                        }
                        newBuffer[i][g] = oldBuffer[pointer0][pointer];
                        pointer++;
                    } else if (oldBuffer[pointer0][pointer] >= oldBuffer[newPointer][pointer1]) {
                        newBuffer[i][g] = oldBuffer[newPointer][pointer1];
                        pointer1++;
                    } else {
                        newBuffer[i][g] = oldBuffer[pointer0][pointer];
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
};

int main() {
    int i1 = IO::readInt();
    for (int i2 = 0; i2 < i1; i2++) {
        int i = IO::readInt();
        vector<int> quantity = IO::readArrayInt(" ");
        vector<int> base = IO::readArrayInt(" ");
        map<int, int> countValue;
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        int min = countValue.size();
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            if (countValue[base[i - quantity[2]]] == 0) {
                countValue.erase(base[i - quantity[2]]);
            }
            countValue[base[i]]++;
            min = min(min, (int)countValue.size());
        }
        IO::writeInt(min, "\n");
    }
    return 0;
}
