#include <stdio.h>
#include <math.h>

#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半径

double radian(double d);
double get_distance(double lat1, double lng1, double lat2, double lng2);

// 求弧度
double radian(double d)
{
    return d * PI / 180.0;   //角度1˚ = π / 180
}

//计算距离
double get_distance(double lat1, double lng1, double lat2, double lng2)
{
    double radLat1 = radian(lat1);
    double radLat2 = radian(lat2);
    double a = radLat1 - radLat2;
    double b = radian(lng1) - radian(lng2);
    
    double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2) )));
    
    dst = dst * EARTH_RADIUS;
    dst= round(dst * 10000) / 10000;
    return dst;
}

int main (int argc, const char * argv[])
{

    double lat1 = 22;
    double lng1 = 22;//经度,纬度1
    double lat2 = 23;
    double lng2 = 23;//经度,纬度2
    // insert code here...

    double dst = get_distance(lat1, lng1, lat2, lng2);
    printf("dst = %0.3fkm\n", dst);  //dst = 9.281km
    return 0;
}