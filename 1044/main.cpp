#include <iostream>
#include <vector>
using namespace std;

struct queue{
    int start;
    int end;
};

vector<int> values;
vector<queue> queues;
int n, m;
int min1 = 10000000000;
int main() {
    cin >> n >> m;
    values.push_back(0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        values.push_back(x + values[i - 1]);
    }//前缀和思想
    for(int i = 0; i <= n; i++){
        int l = i, r = n;
        while(l <= r){//二分法
            int mid = (l + r)/2;
            int value = values[mid] - values[i] - m;
            if(value < 0)
                l = mid + 1;
            else {
                if (value < min1)
                    min1 = value;
                r = mid - 1;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        int l = i, r = n;
        queue temp;
        while(l <= r){
            int mid = (l + r)/2;
            int value = values[mid] - values[i] - m;
            if(value == min1){
                temp.start = i + 1;
                temp.end = mid;
                queues.push_back(temp);
                break;
            }else if(value > min1){
                r = mid - 1;
            }else
                l = mid + 1;
        }
    }
    for(int i = 0; i < queues.size(); i++){
            cout << queues[i].start << "-" << queues[i].end;
            if(i != queues.size() - 1)
                cout << endl;
        }
    return 0;
}
