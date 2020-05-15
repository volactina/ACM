#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-12 ;
const double PI = acos( -1.0 ) ;
inline double sqr( double x ){ return x * x ; }
inline int sgn( double x ){
    if ( fabs(x) < eps ) return 0 ;
    return x > 0? 1 : -1 ;
}

struct Point{
    double x , y ;
    Point(){}
    Point( double _x , double _y ): x(_x) , y(_y) {}
    void input() { scanf( "%lf%lf" ,&x ,&y ); }
    double norm() { return sqrt( sqr(x) + sqr(y) ); }

    friend Point operator + ( const Point &a , const Point &b ) { return Point( a.x + b.x , a.y + b.y ) ; }
    friend Point operator - ( const Point &a , const Point &b ) { return Point( a.x - b.x , a.y - b.y ) ; }
    friend Point operator * ( const Point &a , const double &b ) { return Point( a.x * b , a.y * b ) ; }
    friend Point operator * ( const double &a , const Point &b ) { return Point( b.x * a , b.y * a ) ; }
    friend Point operator / ( const Point &a , const double &b ) { return Point( a.x / b , a.y / b ) ; }
    friend bool operator == ( const Point &a , const Point &b ) { return sgn( a.x - b.x ) == 0 && sgn( a.y - b.y ) == 0 ; }

    bool operator < ( const Point &a )const{
        return ( sgn( x - a.x ) < 0 ) || ( sgn( x - a.x ) == 0 && sgn( y - a.y ) < 0 ) ;
    }
};

double dot( Point a , Point b ) { return a.x * b.x + a.y * b.y ; }
double det( Point a , Point b ) { return a.x * b.y - a.y * b.x ; }
double dist( Point a , Point b ) { return ( a - b ).norm() ; }

int n ;
double k ;
Point A,B ;
Point p[505] ;
Point o ;
double r ;

int CircleInterLine( Point a, Point b, Point o, double r, Point *p )
{
    Point p1 = a - o ;
    Point d = b - a ;
    double A = dot( d, d ) ;
    double B = 2 * dot( d, p1 ) ;
    double C = dot( p1, p1 ) - sqr(r) ;

    double delta = sqr(B) - 4*A*C ;
    if ( sgn(delta) < 0 ) return 0 ;//相离
    if ( sgn(delta) == 0 ) { //相切
        double t = -B / (2*A) ; // 0 <= t <= 1说明交点在线段上
        if ( sgn( t - 1 ) <= 0 && sgn( t ) >= 0 ) {
            p[0] = a + t * d ;
            return 1 ;
        }
    }
    if ( sgn(delta) > 0 ) { //相交
        double t1 = ( -B - sqrt(delta) ) / (2*A) ;
        double t2 = ( -B + sqrt(delta) ) / (2*A) ; //0 <= t1, t2 <= 1说明交点在线段上
        int k = 0 ;
        if ( sgn( t1 - 1 ) <= 0 && sgn( t1 ) >= 0 )
            p[k++] = a + t1 * d ;
        if ( sgn( t2 - 1 ) <= 0 && sgn( t2 ) >= 0 )
            p[k++] = a + t2 * d ;
        return k ;
    }
    return 0;
}
double Triangle_area( Point a, Point b )
{
    return fabs( det( a , b ) ) / 2.0  ;
}
double Sector_area( Point a, Point b )
{
    double ang = atan2( a.y , a.x ) - atan2( b.y, b.x  ) ;
    while ( ang <= 0 ) ang += 2 * PI ;
    while ( ang > 2 * PI ) ang -= 2 * PI ;
    ang = min( ang, 2*PI - ang ) ;
    return sqr(r) * ang/2 ;
}
double calc( Point a , Point b , double r )
{
    Point pi[2] ;
    if ( sgn( a.norm() - r ) < 0 ) {
        if ( sgn( b.norm() - r ) < 0 ) {
            return Triangle_area( a, b ) ;
        }
        else {
            CircleInterLine( a, b, Point(0,0), r, pi) ;
            return Sector_area( b, pi[0] ) + Triangle_area( a, pi[0] ) ;
        }
    }
    else {
        int cnt = CircleInterLine( a, b, Point(0,0), r, pi ) ;
        if ( sgn( b.norm() - r ) < 0 ) {
            return Sector_area( a, pi[0] ) + Triangle_area( b, pi[0] ) ;
        }
        else {
            if ( cnt == 2 )
                return Sector_area( a, pi[0] ) + Sector_area( b, pi[1] ) + Triangle_area( pi[0], pi[1] ) ;
            else
                return Sector_area( a, b ) ;
        }
    }
}
double area_CircleAndPolygon( Point *p , int n , Point o , double r )
{
    double res = 0 ;
    p[n] = p[0] ;
    for ( int i = 0 ; i < n ; i++ ) {
        int tmp = sgn( det( p[i] - o , p[i+1] - o ) ) ;
        if ( tmp )
            res += tmp * calc( p[i] - o , p[i+1] - o , r ) ;
    }
    return fabs( res ) ;
}

double area_polygon(int n,Point* p){
       double s1=0,s2=0;
       int i;
       for (i=0;i<n;i++)
              s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
       return fabs(s1-s2)/2;
}


int main()
{
    cin>>n;
    for (int i=0;i<n;i++) p[i].input();
    int m;
    cin>>m;
    while(m--){
        o.input();
        //cout<<area_CircleAndPolygon(p,n,o,0.7324)<<endl;
        double pp,qq;
        scanf("%lf%lf",&pp,&qq);
        double targets=area_polygon(n,p)*(1-pp/qq);
        //cout<<targets<<endl;
        double rmin=0,rmax=3000,small=1e-12;
        r=(rmin+rmax)/2.0;
        while(sgn(rmin-rmax)<=0){
            double nows=area_CircleAndPolygon(p,n,o,r);
            if(sgn(nows-targets)<0){
                rmin=r+small;
                r=(rmin+rmax)/2.0;
            }else if(sgn(nows-targets)>0){
                rmax=r-small;
                r=(rmin+rmax)/2.0;
            }else{
                break;
            }
        }
        printf("%.12lf\n",r);
    }
    return 0;
}
