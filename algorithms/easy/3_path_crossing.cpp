/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
*/

#include <string>
#include <unordered_set>

using namespace std;

struct Point {
    int x = 0;
    int y = 0;

    bool operator==(const Point& other) const {
        return x == other.x &&  y == other.y;
    }
};

template <>
struct std::hash<Point>
{
  std::size_t operator()(const Point& k) const
  {
    return ((hash<int>()(k.x)
             ^ (hash<int>()(k.y) << 1)) >> 1);
  }
};


class Solution {
private:
    Point currentPoint {0, 0};

public:
    inline void move(const char& movechar) {
        switch (movechar) {
            case 'N':
                currentPoint.y += 1;
                break;
            case 'S':
                currentPoint.y -= 1;
                break;
            case 'E':
                currentPoint.x += 1;
                break;
            case 'W':
                currentPoint.x -= 1;
                break;
            default:
                return;
        }
    }

    bool isPathCrossing(string path) {
        unordered_set<Point> visitedPoints{currentPoint};

        for (const auto& movechar : path) {
            move(movechar);

            if (visitedPoints.find(currentPoint) != visitedPoints.end())
                return true;

            visitedPoints.insert(currentPoint);
        }

        return false;
    }
};