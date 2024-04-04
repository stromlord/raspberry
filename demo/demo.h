#ifndef DEMO_H_
#define DEMO_H_

#include <string>

class demo{
  private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val = shares * share_val;}
  public:
    demo();
    demo(const std::string &co, long n=0, double pr=0.0);
    ~demo();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif
