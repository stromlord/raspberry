#include <iostream>
#include "demo.h"

demo::demo(){
  std::cout << "Default constructor called\n";
  company = "no name";
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

demo::demo(const std::string &co, long n, double pr){
  std::cout << "Constructor using " << co << " called\n";
  company = co;

  if (n<0){
    std::cout << "Number of shares can't be negative;"
              << company << " shares set to 0.\n";
    shares = 0;
  }
  else
    shares = n;
  share_val = pr;
  set_tot();
}

demo::~demo(){std::cout << "Bye, " << company << "!\n";}

void demo::buy(long num, double price){
  if (num < 0)
    std::cout << "Number of shares purchased can't be negative.\n";
  else{
    shares += num;
    share_val = price;
    set_tot();
  }
}

void demo::sell(long num, double price){
  using std::cout;
  if (num < 0)
    cout << "Number of shares purchased can't be negative.\n";
  else if (num > shares)
    cout << "You can't sell more than you have!\n";
  else{
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void demo::update(double price){
  share_val = price;
  set_tot();
}

void demo::show(){
  using std::cout;
  using std::ios_base;

  ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = cout.precision(3);

  std::cout << "Company: " << company 
            << " Shares: " << shares << "\n"
            << " Share Price: $" << share_val
            << " Total Worth: $" << total_val << "\n";
  cout.precision(2);

  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}
