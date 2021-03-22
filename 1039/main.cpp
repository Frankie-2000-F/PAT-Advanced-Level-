#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
string students[40000];
map<string, vector<int>> table;
int main() {
    cin >> n >> k;
    for(int i =0; i < k; i++){
        int id, num;
        cin >> id >> num;
        for(int j =0; j < num; j++){
            string name;
            cin >> name;
            if(table.find(name) != table.end()){
                vector<int> temp = table[name];
                temp.push_back(id);
                table[name] = temp;
            }else{
                vector<int> v = {id};
                table.insert(make_pair(name, v));
            }
        }
    }
    for(int i = 0; i < n; i++){
        cin >> students[i];
    }
    for(int i = 0; i < n; i++){
        cout << students[i];
        vector<int> temp = table[students[i]];
        sort(temp.begin(), temp.end());
        cout << " " << temp.size();
        for(int j = 0; j < temp.size(); j++){
            cout << " " << temp[j];
        }
        cout << endl;
    }
    return 0;
}
