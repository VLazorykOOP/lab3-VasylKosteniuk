#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
    double values[3];
    int state;
    static int count;

public:
    // Конструктор без параметрів (ініціалізація полів в нуль)
    Vector() {
        values[0] = 0.0;
        values[1] = 0.0;
        values[2] = 0.0;
        state = 0;
        count++;
    }

    // Конструктор з одним параметром типу double (ініціалізація масиву значенням параметру)
    Vector(double val) {
        values[0] = val;
        values[1] = val;
        values[2] = val;
        state = 0;
        count++;
    }

    // Конструктор з одним параметром вказівник на тип (ініціалізація масиву значеннями масиву,
    // який передається параметром за вказівником)
    Vector(const double* arr) {
        if (arr != nullptr) {
            for (int i = 0; i < 3; i++) {
                values[i] = arr[i];
            }
            state = 0;
        }
        else {
            state = -1; // Помилка - передано nullptr
        }
        count++;
    }

    // Деструктор із виведенням інформації про стан вектора
    ~Vector() {
        cout << "Vector destroyed. State: " << state << endl;
        count--;
    }

    // Функція, що присвоює масиву деяке значення (параметр за замовчуванням)
    void assignValues(double val = 0.0) {
        for (int i = 0; i < 3; i++) {
            values[i] = val;
        }
    }

    // Функція, яка повертає деякий елемент з масиву
    double getElement(int index) {
        if (index >= 0 && index < 3) {
            return values[index];
        }
        else {
            state = -2; // Помилка - неправильний індекс елементу
            return 0.0;
        }
    }

    // Функція друку
    void print() {
        cout << "Vector values: ";
        for (int i = 0; i < 3; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }

    // Функція додавання
    Vector add(const Vector& other) {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.values[i] = values[i] + other.values[i];
        }
        return result;
    }

    // Функція віднімання
    Vector subtract(const Vector& other) {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.values[i] = values[i] - other.values[i];
        }
        return result;
    }

    // Функція векторного добутку
    Vector crossProduct(const Vector& other) {
        Vector result;
        result.values[0] = values[1] * other.values[2] - values[2] * other.values[1];
        result.values[1] = values[2] * other.values[0] - values[0] * other.values[2];
        result.values[2] = values[0] * other.values[1] - values[1] * other.values[0];
        return result;
    }

    // Функція ділення на ціле типу short
    void divideByShort(short num) {
        if (num != 0) {
            for (int i = 0; i < 3; i++) {
                values[i] /= num;
            }
        }
        else {
            state = -3; // Помилка - ділення на 0
        }
    }

    // Функція порівняння (більше)
    bool operator>(const Vector& other) {
        double magnitude1 = sqrt(values[0] * values[0] + values[1] * values[1] + values[2] * values[2]);
        double magnitude2 = sqrt(other.values[0] * other.values[0] + other.values[1] * other.values[1] + other.values[2] * other.values[2]);
        return magnitude1 > magnitude2;
    }

    // Функція порівняння (менше)
    bool operator<(const Vector& other) {
        double magnitude1 = sqrt(values[0] * values[0] + values[1] * values[1] + values[2] * values[2]);
        double magnitude2 = sqrt(other.values[0] * other.values[0] + other.values[1] * other.values[1] + other.values[2] * other.values[2]);
        return magnitude1 < magnitude2;
    }

    // Функція порівняння (рівно)
    bool operator==(const Vector& other) {
        return values[0] == other.values[0] && values[1] == other.values[1] && values[2] == other.values[2];
    }

    // Функція підрахунку числа об'єктів даного типу
    static int getCount() {
        return count;
    }
};

int Vector::count = 0;

int main() {
    // Приклад тестування класу
    Vector v1; // Вектор за замовчуванням
    v1.print();

    Vector v2(2.5); // Вектор з одним параметром типу double
    v2.print();

    double arr[3] = { 1.0, 2.0, 3.0 };
    Vector v3(arr); // Вектор з одним параметром вказівник на тип
    v3.print();

    cout << "Element at index 1 of v3: " << v3.getElement(1) << endl;

    Vector v4;
    v4.assignValues(5.0); // Присвоєння масиву значенням 5.0
    v4.print();

    Vector v5 = v2.add(v3); // Додавання
    v5.print();

    Vector v6 = v3.subtract(v2); // Віднімання
    v6.print();

    Vector v7 = v2.crossProduct(v3); // Векторний добуток
    v7.print();

    v7.divideByShort(2); // Ділення на ціле
    v7.print();

    if (v5 > v6) { // Порівняння (більше)
        cout << "v5 is greater than v6" << endl;
    }

    if (v6 < v7) { // Порівняння (менше)
        cout << "v6 is less than v7" << endl;
    }

    if (v2 == v3) { // Порівняння (рівно)
        cout << "v2 is equal to v3" << endl;
    }

    cout << "Number of Vector objects: " << Vector::getCount() << endl;

    return 0;
}
