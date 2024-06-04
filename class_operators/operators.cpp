#include <cmath>
#include <iostream>

class Vector2D
{
private:
    float x, y;

public:
    // constructors
    Vector2D() : x(0), y(0) {}
    Vector2D(float _x, float _y) : x(_x), y(_y) {}

    // equality operator
    bool operator==(const Vector2D& other) const // (1)
    {
        // if we comapre with itself, its always true
        if (this == &other) return true;
        return x == other.x and y == other.y;
    }

    Vector2D operator*(double s) const // (2)
    {
        return Vector2D(x * s, y * s);
    }
    Vector2D operator+(const Vector2D& other) const // (3)
    {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-() const { return Vector2D(-x, -y); } // (4)
    Vector2D operator-(const Vector2D& other) const         // (5)
    {
        /* This would not work as `- other` would call operator-(..) recursively. We can however
         * first cal the negation operator and then add it to the this as in the netx file
         *
        return *this - other;
         *
         */
        return *this + (-other);
        /* This will raise a question of performance. Wouldn't it be more efficient to implement
         * same way like operator-(...) ? Check that with godbolt by yourself.
         */
    }

    Vector2D operator+=(const Vector2D& other) // (6)
    {
        x = +other.x;
        y = +other.y;
        return *this;
    }

    auto radius() const { return sqrt(x * x + y * y); }
};

int main()
{
    Vector2D v1(1, 2);
    auto v2 = v1;
    Vector2D v3(2, 4);

    std::cout << "Scaling test: " << (v3 == v1 * 2) << '\n';                    // uses (1) and (2)
    std::cout << "Addition test: " << (v1 + v3 == Vector2D(3, 6)) << '\n';      // uses (3) and (1)
    std::cout << "Reverse test: " << (-v1 == Vector2D(-1, -2)) << '\n';         // uses (4) and (1)
    std::cout << "Subtraction test: " << (v1 - v3 == Vector2D(-1, -2)) << '\n'; // uses (5) and (1)

    Vector2D v4;
    v4 += Vector2D(3, 3);
    std::cout << "Self Addition test: " << (v4 == Vector2D(3, 3)) << '\n';

    return v2.radius();
}
