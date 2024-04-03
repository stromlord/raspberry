#include <iostream>
#include "demo.h"

void demo::acquire(const std::string & co, long n, double pr){
  company = co;
  if (n < 0){
    std::cout << "Number of shares can't be negative;" << company << " shares set to 0.\n";
    shares = 0;
  }
  else
    shares = n;
  share_val = pr;
  set_tot(); 
}

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
  std::cout << "Company: " << company 
            << " Shares: " << shares << "\n"
            << " Share Price: $" << share_val
            << " Total Worth: $" << total_val << "\n";
}
