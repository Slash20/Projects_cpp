#include <iostream>

class Rectangle {
    float m_a;
    float m_b;
    float m_perimetr;
public:
   

    Rectangle(float a, float b) {
        m_a = a;
        m_b = b;
    }

    void setA(float a) {
        m_a = a;

    }

    void setB(float b) {
        m_b = b;
    }

    float AreaRectangle() {
        return m_a * m_b;
    }

    float PerimeterRectangle() {
        return 2 * (m_a + m_b);
    }

    float DiagonalLengthRectangle() {
        return sqrt(m_a * m_a + m_b * m_b);
    }


};


int main() {

    setlocale(LC_ALL, "Russian");

    Rectangle r1(21.f, 23.f);

    std::cout << r1.AreaRectangle() << std::endl;
    std::cout << r1.PerimeterRectangle() << std::endl;
    std::cout << r1.DiagonalLengthRectangle() << std::endl;

    return 0;
}
