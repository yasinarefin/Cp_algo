#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

typedef long long int T;    /// basic type
typedef double Tf;      /// floating point type

Tf eps = 1e-6;

//int sgn(Tf x){
//    if(fabs(x) < eps) return 0;
//    if(x > 0) return 1;
//    else return -1;
//}

int sgn(T x){
    if(x == 0) return 0;
    if(x > 0) return 1;
    else return -1;
}


struct point{
    T x, y;
    point(T x = 0, T y = 0){
        this->x = x;
        this->y = y;
    }

    point operator+(point p){ return point(x+p.x, y+p.y); }

    point operator-(point p){ return point(x-p.x, y-p.y); }

    point operator*(T a){ return point(x*a, y*a); }

    point operator/(T a){ return point(x/a, y/a); }

    Tf len(){ return sqrt(x*x+y*y); }

    T norm(){ return x*x + y*y; }

//    bool operator==(point p){       /// for integers
//        return x == p.x && y == p.y;
//    }

    bool operator==(point p){       /// for floating point
       return sgn(x-p.x) == 0 && sgn(y-p.y) == 0;
    }

//    bool operator<(point p){        /// for integers
//        if(x == p.x) return y < p.y;
//        else return x < p.x;
//    }
//
    bool operator<(point p){        /// for floating points
        if(sgn(x-p.x) == 0) return sgn(y-p.y) == -1;
        else return sgn(x-p.x) == -1;
    }

};

T dot(point p, point q){
    return p.x * q.x + p.y * q.y;
}

T cross(point p, point q){
    return p.x * q.y - p.y * q.x;
}

/// a->b->c which direction we rotate, +ve ccw, -ve cw, 0 collinear
T orient(point a, point b, point c){
    return cross(b-a, c-a);
}

ostream& operator<<(ostream &os, point p){
    return os<<"("<<p.x<<","<<p.y<<")";
}

T triangleArea(point a, point b, point c){
    return abs(orient(a, b, c));
}


struct segment{
    point a, b;

    bool onSegment(point p){ // check if a point is on the segment.
        if(sgn(orient(a, b, p)) != 0) return false;
        return sgn(dot(p-a, p-b)) <= 0;
    }

    bool intersection(segment s){
        if(onSegment(s.a)) return true;
        if(onSegment(s.b)) return true;
        if(s.onSegment(a)) return true;
        if(s.onSegment(b)) return true;

        int s1 = sgn(orient(a, b, s.a));
        int s2 = sgn(orient(a, b, s.b));
        int s3 = sgn(orient(s.a, s.b, a));
        int s4 = sgn(orient(s.a, s.b, b));

        if(s1*s2 < 0 && s3 * s4 < 0) return true;

        return false;
    }
};

//8 -6 8 6
//0 0 7
void solve(){
     int n; cin>>n;
     double arr1[n], arr2[n];
     for(int  x=0;x<n;x++){
        cin>>arr1[x]>>arr2[x];
     }
     int maxa = 0;
     for(int x=0;x<n;x++){
        for(int y=x+1;y<n;y++){
            point  a(arr1[x], arr2[x]);
            point  b(arr1[y], arr2[y]);
            int ans = 2;
            for(int z = y+1;z<n;z++){
                point c(arr1[z], arr2[z]);
                if(orient(a, b, c) == 0) ans++;
            }
            maxa = max(maxa, ans);
        }
     }
     cout<<maxa<<endl;
}
int main(){
    double x1, y1, x2, y2, c1, c2, l;
    cin>>x1>>y1>>x2>>y2>>c1>>c2>>l;

    point a(x1, y1);
    point b(x2, y2);
    point c(c1, c2);

    point d = (a + b) / 2;


    segment seg;
    seg.a = a;
    seg.b = b;

    double ans1;
    if(dot(a-b, a-c) * dot(b-a, b-c) > 0){
        double ar = triangleArea(a, b, c);
        ans1 = ar / (a-b).len();
    }else{
        ans1 = min((c-a).len(), (c-b).len());
    }
    printf("%.2lf\n", max((double) 0,  ans1 - l));


    double ans2 = max((double)0, max((a-c).len(), (b-c).len()) - l);
    printf("%.2lf\n",  ans2);

}
