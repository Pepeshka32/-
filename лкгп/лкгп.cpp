#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
    double radius;
    int M_PI = 3.14;

public:
    Circle() : radius(0) {}
    Circle(double r) : radius(r) {}

    bool operator==(const Circle& other) const
    {
        return radius == other.radius;
    }

    bool operator>(const Circle& other) const
    {
        return this->getCircumference() > other.getCircumference();
    }

    bool operator<(const Circle& other) const
    {
        return this->getCircumference() < other.getCircumference();
    }

    Circle operator*(double scale) const
    {
        return Circle(radius * scale);
    }

    Circle& operator*=(double scale)
    {
        radius *= scale;
        return *this;
    }

    double getCircumference() const
    {
        return 2 * M_PI * radius;
    }

    void display() const
    {
        cout << "Radius: " << radius << ", Circumference: " << getCircumference() << endl;
    }
};

int main()
{
    Circle c1(5.0);
    Circle c2(10.0);

    c1.display();
    c2.display();

    if (c1 == c2)
        cout << "Circles have equal radii." << endl;
    else if (c1 > c2)
        cout << "c1 has a larger circumference than c2." << endl;
    else
        cout << "c2 has a larger circumference than c1." << endl;

    Circle c3 = c1 * 2.0;
    c3.display();

    c1 *= 1.5;
    c1.display();

    return 0;
}
