#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct person{
    char name[10];//不要忘记给'\0'留位置
    int age;
    int worth;
};

bool cmp1(person p1, person p2){
    if(p1.worth != p2.worth)
        return p1.worth >= p2.worth;
    else if(p1.age != p2.age)
        return p1.age <= p2.age;
    else
        return strcmp(p1.name, p2.name) <= 0;
}

int n, k, m[1000], amin[1000], amax[1000];
vector<person> people;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        person temp{};
        cin >> temp.name >> temp.age >> temp.worth;
        people.push_back(temp);
    }
    for(int i =0; i < k; i++){
        cin >> m[i] >> amin[i] >> amax[i];
    }
    sort(people.begin(), people.end(), cmp1);
    for(int i = 1; i <= k; i++){
        cout << "Case #" << i << ":" << endl;
        int count = m[i - 1];
        for(int j = 0; j < people.size(); j++){
            if(count && people[j].age >= amin[i - 1] && people[j].age <= amax[i - 1]){
                cout << people[j].name << " " << people[j].age << " " << people[j].worth << endl;
                count--;
            }
            if(count == 0)
                break;
        }
        if(count == m[i - 1])
            cout << "None" << endl;
    }
    return 0;
}
