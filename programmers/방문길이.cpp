#include <set>
#include <string>

using namespace std;
using pii = pair<int, int>;

int solution(string dirs) {
    set<pii> vis;
    int r = 5, c = 5;

    for (int i = 0; i < dirs.length(); i++) {
        char command = dirs[i];
        int prevr = r, prevc = c;

        if (command == 'U')
            r = max(0, r - 1);
        else if (command == 'D')
            r = min(10, r + 1);
        else if (command == 'L')
            c = max(0, c - 1);
        else
            c = min(10, c + 1);

        if (prevr != r || prevc != c) {
            vis.insert({r * 11 + c, prevr * 11 + prevc});
            vis.insert({prevr * 11 + prevc, r * 11 + c});
        }
    }

    return vis.size() / 2;
}