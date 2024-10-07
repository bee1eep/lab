#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, std::vector<int>, std::greater<int> > hold;

    hold.push(2);
    hold.push(3);
    hold.push(5);

    while (n) {
        int num = hold.top();
        while (hold.top() == num) hold.pop();
        std::cout << num << ' ';
        hold.push(num * 2);
        hold.push(num * 3);
        hold.push(num * 5);
        n -= 1;
    }

    return 0;
}
