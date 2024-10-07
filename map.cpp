#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    int counter = 0;
    map<string, int> hold;

    

    while (cin >> s) {
        counter += 1;
        ++hold[s];

    }
    for (const auto& p :hold) std::cout << p.first << ": " << p.second << std::endl;
    return 0;
}
