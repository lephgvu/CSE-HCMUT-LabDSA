#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
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
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    Circle(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
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