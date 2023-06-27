#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class RegularTetrahedron {
private:
    double side;
    string color;

public:
    // Конструктор за замовчуванням
    RegularTetrahedron() {
        side = 0.0;
        color = "No color";
    }

    // Конструктор з параметрами
    RegularTetrahedron(double s, const string& c) {
        side = s;
        color = c;
    }

    // Функція-член для обчислення площі тетраедра
    double calculateArea() {
        return sqrt(3) * side * side;
    }

    // Функція-член для обчислення периметру тетраедра
    double calculatePerimeter() {
        return 3 * side;
    }

    // Функція-член для обчислення об'єму тетраедра
    double calculateVolume() {
        return (sqrt(2) / 12) * side * side * side;
    }

    // Функція-член для встановлення значення сторони
    void setSide(double s) {
        if (s > 0) {
            side = s;
        }
        else {
            cout << "Invalid side value. Side must be greater than 0." << endl;
        }
    }

    // Функція-член для встановлення значення кольору
    void setColor(const string& c) {
        color = c;
    }

    // Функція-член, що повертає значення сторони
    double getSide() const {
        return side;
    }

    // Функція-член, що повертає значення кольору
    string getColor() const {
        return color;
    }

    // Функція-член для друку інформації про тетраедр
    void print() {
        cout << "Regular Tetrahedron" << endl;
        cout << "Side: " << side << endl;
        cout << "Color: " << color << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "Volume: " << calculateVolume() << endl;
    }
};

int main() {
    // Приклад тестування класу
    RegularTetrahedron tetrahedron(5.0, "Red");
    tetrahedron.print();

    tetrahedron.setSide(7.5);
    tetrahedron.setColor("Blue");
    cout << "\nUpdated values:\n";
    cout << "Side: " << tetrahedron.getSide() << endl;
    cout << "Color: " << tetrahedron.getColor() << endl;

    return 0;
}
