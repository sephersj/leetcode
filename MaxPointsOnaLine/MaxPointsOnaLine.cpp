//============================================================================
// Max Points on a Line 
//
// Given n points on a 2D plane, find the maximum number of points that lie 
// on the same straight line.
//
//
// Complexity:
// O(n^2) time, O(n^2) space
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
* Definition for a point.
**/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};


class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int N = points.size();
        if (N < 3) return N;
        unordered_map<int, int> tb;
        int res = 0;
        for (int i = 0; i < N; i++) {
            tb.clear();
            int o = 0, u = 0, v = 0;
            for (int j = 0; j < N; j++) {
                int x = points[j].x - points[i].x, y = points[j].y - points[i].y;
                if (x == 0 && y == 0) o++;
                else if (x == 0) v++;
                else u = max(u, ++tb[1e6*y / x]);
            }
            res = max(res, o + max(u, v));
        }
        return res;
    }
};

int main() {

    Solution sol;
    vector<Point> p0;

    {
        p0 = { Point(0, 0), Point(-1, -1), Point(2, 2) };
        cout << sol.maxPoints(p0) << "," << 3 << endl;
    }

    {
        p0 = { Point(0, 0), Point(1, 1), Point(1, -1) };
        cout << sol.maxPoints(p0) << "," << 2 << endl;
    }

    {
        p0 = { Point(0, 0), Point(1, 1), Point(0, 0) };
        cout << sol.maxPoints(p0) << "," << 3 << endl;
    }

    {
        p0 = {
            Point(0, -12), Point(5, 2), Point(2, 5), Point(0, -5), Point(1, 5),
            Point(2, -2), Point(5, -4), Point(3, 4), Point(-2, 4), Point(-1, 4),
            Point(0, -5), Point(0, -8), Point(-2, -1), Point(0, -11), Point(0, -9) };
        cout << sol.maxPoints(p0) << "," << 6 << endl;
    }

    {
        p0 = {
            Point(0, 9), Point(138, 429), Point(115, 359), Point(115, 359), Point(-30, -102),
            Point(230, 709), Point(-150, -686), Point(-135, -613), Point(-60, -248), Point(-161, -481),
            Point(207, 639), Point(23, 79), Point(-230, -691), Point(-115, -341), Point(92, 289), Point(60, 336),
            Point(-105, -467), Point(135, 701), Point(-90, -394), Point(-184, -551), Point(150, 774)
        };
        cout << sol.maxPoints(p0) << "," << 12 << endl;

    }

    {
        p0 = {
            Point(560, 248), Point(0, 16), Point(30, 250), Point(950, 187), Point(630, 277), Point(950, 187),
            Point(-212, -268), Point(-287, -222), Point(53, 37), Point(-280, -100), Point(-1, -14), Point(-5, 4),
            Point(-35, -387), Point(-95, 11), Point(-70, -13), Point(-700, -274), Point(-95, 11), Point(-2, -33),
            Point(3, 62), Point(-4, -47), Point(106, 98), Point(-7, -65), Point(-8, -71), Point(-8, -147),
            Point(5, 5), Point(-5, -90), Point(-420, -158), Point(-420, -158), Point(-350, -129), Point(-475, -53),
            Point(-4, -47), Point(-380, -37), Point(0, -24), Point(35, 299), Point(-8, -71), Point(-2, -6),
            Point(8, 25), Point(6, 13), Point(-106, -146), Point(53, 37), Point(-7, -128), Point(-5, -1),
            Point(-318, -390), Point(-15, -191), Point(-665, -85), Point(318, 342), Point(7, 138), Point(-570, -69),
            Point(-9, -4), Point(0, -9), Point(1, -7), Point(-51, 23), Point(4, 1), Point(-7, 5), Point(-280, -100),
            Point(700, 306), Point(0, -23), Point(-7, -4), Point(-246, -184), Point(350, 161), Point(-424, -512),
            Point(35, 299), Point(0, -24), Point(-140, -42), Point(-760, -101), Point(-9, -9), Point(140, 74),
            Point(-285, -21), Point(-350, -129), Point(-6, 9), Point(-630, -245), Point(700, 306), Point(1, -17),
            Point(0, 16), Point(-70, -13), Point(1, 24), Point(-328, -260), Point(-34, 26), Point(7, -5),
            Point(-371, -451), Point(-570, -69), Point(0, 27), Point(-7, -65), Point(-9, -166), Point(-475, -53),
            Point(-68, 20), Point(210, 103), Point(700, 306), Point(7, -6), Point(-3, -52), Point(-106, -146),
            Point(560, 248), Point(10, 6), Point(6, 119), Point(0, 2), Point(-41, 6), Point(7, 19), Point(30, 250)
        };
        cout << sol.maxPoints(p0) << "," << 22 << endl;
    }

    return 0;
}