#include<iostream>

template<typename T>
class Point2d {
    T x, y;
public: 
    void setX(T x) {
        this->x = x;
    }
    void setY(T y) {
        this->y = y;
    }
    T getX() const { return x; }
    T getY() const { return y; }
    Point2d() {
        x = 0;
        y = 0;
    }
    Point2d(T x, T y) {
        setX(x);
        setY(y);
    }
    Point2d operator+(const Point2d& point) {
        return Point2d(x + point.x, y + point.y);
    }
    //I didn't have to use this part, but here it is
    double distance(const Point2d& point) const {
        return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
    }
};

template<typename T>
std::ostream &operator<<(std::ostream& out, const Point2d<T>& point) {
    out << "(" << point.getX() << "," << point.getY() << ")" << std::endl;
    return out;
}

int main() {
    Point2d<int> FromKeyboard;
    int x, y;
    std::cout << "Keyboard input: ";
    std::cin >> x >> y;
    FromKeyboard.setX(x);
    FromKeyboard.setY(y);
    std::cout << " Keyboard output: " << FromKeyboard << std::endl;
    Point2d<int> InCode(3, 7);
    std::cout << "In-code output: " << InCode << std::endl;
    Point2d<int> result = FromKeyboard + InCode;
    std::cout << "Result output: " << result << std::endl;
    std::cout << "Distance output: " << FromKeyboard.distance(InCode) << std::endl;
    return 0;
}