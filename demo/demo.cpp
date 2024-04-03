#ifndef DEMO_H_
#define DEMO_H_

#include <string>

class Stock{
  private:
    std::string company;
    long shates;
    double share_val;
    double total_val;
    void set_yoy(){total_val = shares * share_val;}
  public:
    void acquire(const std::string & co, long n, double pr);
    void 
}
