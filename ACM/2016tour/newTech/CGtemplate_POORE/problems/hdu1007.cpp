/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
struct Point {
  double x, y;
  Point(double _x, double _y):x(_x),y(_y){}
  Point():x(0.0),y(0.0){}
};
typedef Point Vec;

void showPoint(Point A) {
  printf("(%.6f, %.6f)\n", A.x, A.y);
}
const Vec operator + (Vec A, Vec B) {
  return Vec(A.x+B.x, A.y+B.y);
}
const Vec operator - (Vec A, Vec B) {
  return Vec(A.x-B.x, A.y-B.y);
}
const double operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}
// A*B = |A|*|B|*sin(theta)
// theta为 A,B 向量的夹角
// 如果 A 在 B 的顺时针方向180度内，则theta取正值
// 向量叉乘
// 返回值为正时，表示 A 在 B 的右侧180度内
// 返回值的绝对值等于以A,B向量为邻边的平行四边型的面积
const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

double Lenth(Vec v) {
	return sqrt(v*v);
}

const double eps = 1e-8;

int dcmp(double x) {
  if (fabs(x) < eps ) return 0;
  return x < 0? -1:1;
}

const int oo = 1e9+7;
const int maxn = 1e5+20;
const double inf = 1e30;
int n;
Point p[maxn];
int t[maxn];


bool cmp(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmpy(int a, int b) {
  return p[a].y < p[b].y;
}

double closePair(int l, int r) {
  if (l == r) return inf;
  if (l+1 == r) return Lenth((p[l]-p[r]));
  int mid = (l+r)/2;
  double tdis = min(closePair(l, mid), closePair(mid+1, r));
  int cnt = 0;
  for (int i = l; i <= r; i++) if (fabs(p[i].x-p[mid].x) < tdis)
    t[cnt++] = i;
  sort(t, t + cnt, cmpy);
  for (int i = 0; i < cnt; i++) {
    for (int j = i+1; j < cnt && dcmp(p[t[j]].y-p[t[i]].y-tdis) < 0; j++) {
      double tmp = Lenth((p[t[i]]-p[t[j]]));
      tdis = min(tdis, tmp);
    }
  }
  return tdis;
}

int main()
{
  while(scanf("%d", &n) != EOF) {
    if (n==0) break;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p, p+n, cmp);
    double ans = closePair(0, n-1);
    printf("%.2f\n", ans/2);
  }
  return 0;
}

