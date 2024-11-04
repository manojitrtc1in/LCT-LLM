#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    

    int n;
    long long a[30010];
    bool u[30010];
    cin >> n;
    vector <long long> v1, v2;
    for (int i = 0; i < n; ++i)
    cin >> a[i];
    u[0] = 1;
    u[1] = 1;
    u[2] = 1;
    for (int i = 3; i < n; ++i)
    u[i] = 0;
    if (n == 2)
    {
        cout << a[0] << endl << a[1] << endl;
        return 0;
    }
    if (a[1] - a[0] == a[2] - a[1])
    {
        v1.push_back(a[0]);
        v1.push_back(a[1]);
        v1.push_back(a[2]);
        for (int i = 3; i < n; ++i)
        if (a[i] - v1[v1.size() - 1] == a[1] - a[0])
        {
            v1.push_back(a[i]);
            u[i] = 1;
        }
        else
        {
            if (v2.size() <= 1)
            {
                v2.push_back(a[i]);
                u[i] = 1;
            }
            else
            {
                if (a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                {
                    v2.push_back(a[i]);
                    u[i] = 1;
                }
                else break;
            }
        }
        if (v1.size() + v2.size() != n)
        {
            if (v2.size() <= 1)
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v2.size() == 2 && v2[1] - v1[v1.size() - 1] == v1[v1.size() - 1] - v2[0])
            {
                v2.push_back(v2[v2.size() - 1]);
                v2[1] = v1[v1.size() - 1];
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                v2.push_back(a[i]);
            }
            else if (v1[v1.size() - 1] - v2[v2.size() - 1] == v2[1] - v2[0])
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                v2.push_back(a[i]);
            }
            else if (v1.size() <= 1)
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
            else if (v1.size() == 2 && v1[1] - v2[v2.size() - 1] == v2[v2.size() - 1] - v1[0])
            {
                v1.push_back(v1[v1.size() - 1]);
                v1[1] = v2[v2.size() - 1];
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0])
                v1.push_back(a[i]);
            }
            else if (v2[v2.size() - 1] - v1[v1.size() - 1] == v1[1] - v1[0])
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
        }
        if (v1.size() + v2.size() == n)
        {
            if (v2.empty())
            {
                cout << v1[0] << endl;
                for (int i = 1; i < v1.size(); ++i)
                cout << v1[i] << " ";
                return 0;
            }
            if (v1.empty())
            {
                cout << v2[0] << endl;
                for (int i = 1; i < v2.size(); ++i)
                cout << v2[i] << " ";
                return 0;
            }
            for (int i = 0; i < v1.size(); ++i)
            cout << v1[i] << " ";
            cout << endl;
            for (int i = 0; i < v2.size(); ++i)
            cout << v2[i] << " ";
            cout << endl;
            return 0;
        }
    }
    for (int i = 3; i < n; ++i)
    u[i] = 0;
    v1.clear();
    v2.clear();
    v1.push_back(a[0]);
    v2.push_back(a[1]);
    v2.push_back(a[2]);
    for (int i = 3; i < n; ++i)
    if (a[i] - v2[v2.size() - 1] == a[2] - a[1]) v2.push_back(a[i]);
    else
    {
        if (v1.size() <= 1) v1.push_back(a[i]);
        else
        {
            if (a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            else break;
        }
    }
    if (v1.size() + v2.size() != n)
        {
            if (v2.size() <= 1)
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v2.size() == 2 && v2[1] - v1[v1.size() - 1] == v1[v1.size() - 1] - v2[0])
            {
                v2.push_back(v2[v2.size() - 1]);
                v2[1] = v1[v1.size() - 1];
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                v2.push_back(a[i]);
            }
            else if (v1[v1.size() - 1] - v2[v2.size() - 1] == v2[1] - v2[0])
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v1.size() <= 1)
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
            else if (v1.size() == 2 && v1[1] - v2[v2.size() - 1] == v2[v2.size() - 1] - v1[0])
            {
                v1.push_back(v1[v1.size() - 1]);
                v1[1] = v2[v2.size() - 1];
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0])
                v1.push_back(a[i]);
            }
            else if (v2[v2.size() - 1] - v1[v1.size() - 1] == v1[1] - v1[0])
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
        }
    if (v1.size() + v2.size() == n)
    {
        for (int i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
        cout << endl;
        for (int i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
        cout << endl;
        if (v2.empty())
        {
            cout << v1[0] << endl;
            for (int i = 1; i < v1.size(); ++i)
            cout << v1[i] << " ";
            return 0;
        }
        if (v1.empty())
        {
            cout << v2[0] << endl;
            for (int i = 1; i < v2.size(); ++i)
            cout << v2[i] << " ";
            return 0;
        }
        return 0;
    }
    for (int i = 3; i < n; ++i)
    u[i] = 0;
    v1.clear();
    v2.clear();
    v1.push_back(a[2]);
    v2.push_back(a[0]);
    v2.push_back(a[1]);
    for (int i = 3; i < n; ++i)
    if (a[i] - v2[v2.size() - 1] == a[1] - a[0]) v2.push_back(a[i]);
    else
    {
        if (v1.size() <= 1) v1.push_back(a[i]);
        else
        {
            if (a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            else break;
        }
    }
    if (v1.size() + v2.size() != n)
        {
            if (v2.size() <= 1)
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v2.size() == 2 && v2[1] - v1[v1.size() - 1] == v1[v1.size() - 1] - v2[0])
            {
                v2.push_back(v2[v2.size() - 1]);
                v2[1] = v1[v1.size() - 1];
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                v2.push_back(a[i]);
            }
            else if (v1[v1.size() - 1] - v2[v2.size() - 1] == v2[1] - v2[0])
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v1.size() <= 1)
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
            else if (v1.size() == 2 && v1[1] - v2[v2.size() - 1] == v2[v2.size() - 1] - v1[0])
            {
                v1.push_back(v1[v1.size() - 1]);
                v1[1] = v2[v2.size() - 1];
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0])
                v1.push_back(a[i]);
            }
            else if (v2[v2.size() - 1] - v1[v1.size() - 1] == v1[1] - v1[0])
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
        }
    if (v1.size() + v2.size() == n)
    {
        for (int i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
        cout << endl;
        for (int i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
        cout << endl;
        if (v2.empty())
        {
            cout << v1[0] << endl;
            for (int i = 1; i < v1.size(); ++i)
            cout << v1[i] << " ";
            return 0;
        }
        if (v1.empty())
        {
            cout << v2[0] << endl;
            for (int i = 1; i < v2.size(); ++i)
            cout << v2[i] << " ";
            return 0;
        }
        return 0;
    }
    for (int i = 3; i < n; ++i)
    u[i] = 0;
    v1.clear();
    v2.clear();
    v1.push_back(a[1]);
    v2.push_back(a[0]);
    v2.push_back(a[2]);
    for (int i = 3; i < n; ++i)
    if (a[i] - v2[v2.size() - 1] == a[2] - a[0]) v2.push_back(a[i]);
    else
    {
        if (v1.size() <= 1) v1.push_back(a[i]);
        else
        {
            if (a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            else break;
        }
    }
    if (v1.size() + v2.size() != n)
        {
            if (v2.size() <= 1)
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v2.size() == 2 && v2[1] - v1[v1.size() - 1] == v1[v1.size() - 1] - v2[0])
            {
                v2.push_back(v2[v2.size() - 1]);
                v2[1] = v1[v1.size() - 1];
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0])
                v2.push_back(a[i]);
            }
            else if (v1[v1.size() - 1] - v2[v2.size() - 1] == v2[1] - v2[0])
            {
                v2.push_back(v1[v1.size() - 1]);
                v1.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v2[v2.size() - 1] == v2[1] - v2[0]) v2.push_back(a[i]);
            }
            else if (v1.size() <= 1)
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
            else if (v1.size() == 2 && v1[1] - v2[v2.size() - 1] == v2[v2.size() - 1] - v1[0])
            {
                v1.push_back(v1[v1.size() - 1]);
                v1[1] = v2[v2.size() - 1];
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0])
                v1.push_back(a[i]);
            }
            else if (v2[v2.size() - 1] - v1[v1.size() - 1] == v1[1] - v1[0])
            {
                v1.push_back(v2[v2.size() - 1]);
                v2.pop_back();
                for (int i = 0; i < n; ++i)
                if (!u[i] && a[i] - v1[v1.size() - 1] == v1[1] - v1[0]) v1.push_back(a[i]);
            }
        }
    if (v1.size() + v2.size() == n)
    {
        for (int i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
        cout << endl;
        for (int i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
        cout << endl;
        if (v2.empty())
        {
            cout << v1[0] << endl;
            for (int i = 1; i < v1.size(); ++i)
            cout << v1[i] << " ";
            return 0;
        }
        if (v1.empty())
        {
            cout << v2[0] << endl;
            for (int i = 1; i < v2.size(); ++i)
            cout << v2[i] << " ";
            return 0;
        }
        return 0;
    }
    cout << "No solution" << endl;
    return 0;
}
