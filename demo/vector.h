#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR{
    class Vector{
    public:
        // RECT为直角坐标模式，POL为极坐标模式
        enum Mode {RECT, POL};
    private:
        double x;       // 横坐标
        double y;       // 纵坐标
        double mag;     // 矢量
        double ang;     // 角度
        Mode mode;
        // 私有方法用于设定值
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form=RECT);
        void reset(double n1, double n2, Mode from=RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double megval() const {return mag;}
        double angval() const {return ang;}
        void polar_mode();      // 将模式切换为POL
        void rect_mode();       // 将模式切换为RECT
        // 操作函数
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // friend
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
};  // end namespace VECTOR

#endif // !VECTOR_H_
