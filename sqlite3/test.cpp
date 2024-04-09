#include <iostream>
#include <sqlite3.h>

int main(){
  using namespace std;

  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  
  /* SQLite API:sqlite3_open(const char *filename, sqlite3 **ppDb)
   打开一个指向SQLite数据库文件的连接，返回一个用于其他SQLite程序的数据库连接对象
  
   1.如果 filename 参数是 NULL 或 ':memory:'，那么 sqlite3_open() 将会在 RAM 中创建一个内存数据库，这只会在 session 的有效时间内持续。
   2.如果文件名 filename 不为 NULL，那么 sqlite3_open() 将使用这个参数值尝试打开数据库文件。如果该名称的文件不存在，sqlite3_open() 将创建一个新的命名为该名称的数据库文件并打开。
   * */
  rc = sqlite3_open("test.db", &db);

  if (rc){
    cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
  }
  else{
    cout << "Opened database successfully\n";
  }
  sqlite3_close(db);

  return 0;
}
