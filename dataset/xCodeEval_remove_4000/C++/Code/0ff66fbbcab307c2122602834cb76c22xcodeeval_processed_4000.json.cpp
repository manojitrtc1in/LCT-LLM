


using namespace std;

int main()
{
    long long t;
    cin >> t;
    long long n;
    long long b;
    long long sum;
    long long sum0 = 0;
    long long sum1;
    long long sum2;
    for (long long i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        sum1 = 0;
        sum0 = 0;
        sum2 = 0;
        vector<long long>v(n );
        vector<long long>v0;
        vector<long long>v1;
        vector<long long>v2;
        for (long long j = 0;j < n; j++) {
            cin >> b;
            v[j] = b;
            if (b % 3 == 0) {
                v0.push_back(b);
                sum0++;
            }
            if (b % 3 == 1) {
                v1.push_back(b);
                sum1++;
            }
            if (b % 3 ==2 ) {
                v2.push_back(b);
                sum2++;
            }
        }
        int z = 0;
        long long min = sum0 + sum1 + sum2;
        min = min / 3;
        while (100000!=z) {
            z++;
            if (sum0 > min) {
                if (sum1 > min) {
                    sum1--;
                    sum2++;
                    sum++;
                }
                else if(sum1==min) {
                    sum0--;
                    sum2++;
                    sum += 2;
                }
                else {
                    sum0--;
                    sum1++;
                    sum++;
                }
            }
            else if(sum1>min){
                if (sum2 > min) {
                    sum1--;
                    sum0++;
                    sum+=2;
                }
                else if (sum2 == min) {
                    sum0++;
                    sum1--;
                    sum += 2;
                }
                else {
                    sum2++;
                    sum1--;
                    sum++;
                }
            }
            else if (sum2 > min) {
                if (sum0 > min) {
                    sum1++;
                    sum2--;
                    sum+=2;
                }
                else if (sum1 == min) {
                    sum0++;
                    sum2--;
                    sum += 1;
                }
                else {
                    sum2--;
                    sum1++;
                    sum+=2;
                }
            }
            
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }

    
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }

        
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }

        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }
        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }

        if (sum0 > min) {
            if (sum1 > min) {
                sum1--;
                sum2++;
                sum++;
            }
            else if (sum1 == min) {
                sum0--;
                sum2++;
                sum += 2;
            }
            else {
                sum0--;
                sum1++;
                sum++;
            }
        }
        else if (sum1 > min) {
            if (sum2 > min) {
                sum1--;
                sum0++;
                sum += 2;
            }
            else if (sum2 == min) {
                sum0++;
                sum1--;
                sum += 2;
            }
            else {
                sum2++;
                sum1--;
                sum++;
            }
        }
        else if (sum2 > min) {
            if (sum0 > min) {
                sum1++;
                sum2--;
                sum += 2;
            }
            else if (sum1 == min) {
                sum0++;
                sum2--;
                sum += 1;
            }
            else {
                sum2--;
                sum1++;
                sum += 2;
            }
        }

        
        cout << sum<<endl;

    }
}

