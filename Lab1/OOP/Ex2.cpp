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

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        this->center.setX(0);
        this->center.setY(0);
    }

    Circle(Point center, double radius): center(center), radius(radius) {}

    Circle(const Circle &circle)
    {
        this->center = circle.getCenter();
        this->radius = circle.getRadius();
    }
    
    void setCenter(Point point)
    {
        this->center.setX(point.getX());
        this->center.setY(point.getY());
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return this->center;
    }

    double getRadius() const
    {
        return this->radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

int main(){
    Circle A;
    A.printCircle(); //Center: {0.00, 0.00} and Radius 0.00

    return 0;
}