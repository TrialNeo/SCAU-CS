#include <math.h>
#include  <stdio.h>

struct Point {
    double x, y;
};

//TriangleArea 平面直角坐标系中给定3个点，利用行列式计算围成的三角形面积
static inline double TriangleArea(const struct Point A, const struct Point B, const struct Point C) {
    struct Point vector1 = {A.x - B.x, A.y - B.y};
    struct Point vector2 = {A.x - C.x, A.y - C.y};
    register double area = 0.5 * fabs(vector1.x * vector2.y - vector1.y * vector2.x);
    return area;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    struct Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    double maxArea = 0.0, tmpArea = 0.0;
    //有一个算法是凸包算法不太会，是离散几何学里面的东西，果然计算机再上去就是数学了。
    //A_n^3，写出全排列的算法，不知道有没有更好的算法。
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                tmpArea = TriangleArea(points[i], points[j], points[k]);
                if (tmpArea > maxArea) {
                    maxArea = tmpArea;
                }
            }
        }
    }
    printf("%.4f", maxArea);
}
