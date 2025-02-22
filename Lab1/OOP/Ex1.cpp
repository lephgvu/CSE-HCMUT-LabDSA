#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(): x(0), y(0) {};

    Point(double x, double y): x(x), y(y) {};

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX() const
    {
        return this->x;
    }

    double getY() const
    {
        return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        double res = sqrt(pow(this->x - pointA.getX(),2) + pow(this->y - pointA.getY(),2));
    }
};

int main(){
    Point A(2, 3);
    Point B(1, 1);
    cout << pow(A.distanceToPoint(B), 2); //5
    return 0;
}