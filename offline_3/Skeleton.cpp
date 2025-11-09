#include<iostream>
// your code
using namespace std;

class Point2D
{
    double x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code
};

Point2D::Point2D(double argx,double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x=argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

// your code

class Circle
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code
};


Circle:: Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius=r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout<<"]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

// your code

class Rectangle
{
    Point2D topRightPoint,bottomLeftPoint;
public:
    Rectangle();
    Rectangle(Point2D oneCorner,Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner,Point2D anotherCorner)
{
    topRightPoint=oneCorner;
    bottomLeftPoint=anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint=oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint=anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout<<"[Top Right Point: ";
    topRightPoint.print();
    cout<<"  Bottom left Point: ";
    bottomLeftPoint.print();
    cout<<"]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}

// your code

int main()
{
    Point2D p1(5,10),p2(15,10),p3;
    Circle c1(p1,10),c2,c3;
    Rectangle r1(p1,p2),r2;
    // your code
    return 0;
}
