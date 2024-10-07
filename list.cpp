#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    string stud;
    int group;
    vector<pair<int, string>> students;

    while (cin >> group >> stud) {
        students.push_back(make_pair(group, stud));
    }
    sort(students.begin(), students.end(), cmp);
    int cur_gr = -1;

    for (int i = 0; i < students.size(); i++) {
        if (cur_gr != students[i].first) {
            cur_gr = students[i].first;
            cout << "------" << cur_gr << "------" << endl;
        }
        cout << students[i].second << endl;
    }
    
        
        
        
        
    //for (const auto& p :students) std::cout << p.first << ": " << p.second << std::endl;
    return 0;
}
