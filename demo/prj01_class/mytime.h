#ifndef MYTIME_H_
#define MYTIME_H_

class Time{
  private:
    int hours;
    int minutes;
  public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(double mult) const;
    // 友元，可实现数值*函数操作，赋予访问权限
    friend Time operator*(double m, const Time & t){return t * m;}
    // 友元：重载<<运算符，返回类型是ostream &，返回ostream对象的引用
    friend std::ostream & operator << (std::ostream & os, const Time & t);
};
#endif 
