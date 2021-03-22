#include <iostream>
using namespace std;
int t;
long long a, b, c, sum;
int main() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);//题目的范围是[-2^63, 2^63] ,long long的范围是[-2^63, 2^63)
                                                    // 测试用例中会出现2^63,但用scanf不会判断溢出，所以在此题该方法可行
        sum = a + b;
        if (a < 0 && b < 0 && sum >= 0)
            cout << "Case #" << i << ": " << "false";
        else if (a > 0 && b > 0 && sum < 0)
            cout << "Case #" << i << ": " << "true";
        else if(sum > c)
            cout << "Case #" << i << ": " << "true";
        else
            cout << "Case #" << i << ": " << "false";
        cout << endl;
    }

    return 0;
}
