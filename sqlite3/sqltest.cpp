#include <iostream>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
  using std::cout;
  for (int i = 0; i < argc; i++){
    cout << azColName[i] << " = " << (argv[i]?argv[i]:"NULL") << "\n";
  }
  return 0;
} 

int main(){
  using namespace std;

  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;
  
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

  sql = "CREATE TABLE COMPANY("
        "ID INT PRIMARY KEY   NOT NULL,"
        "NAME           TEXT  NOT NULL,"
        "AGE            INT   NOT NULL,"
        "ADDRESS        CHAR(50),"
        "SALSRY         REAL);";
  
  /* sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
   * 该例程提供了一个执行 SQL 命令的快捷方式，SQL 命令由 sql 参数提供，可以由多个 SQL 命令组成
   * 在这里，第一个参数 sqlite3 是打开的数据库对象，sqlite_callback 是一个回调，data 作为其第一个参数，errmsg 将被返回用来获取程序生成的任何错误
   * sqlite3_exec() 程序解析并执行由 sql 参数所给的每个命令，直到字符串结束或者遇到错误为止。
   * */

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK){
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
  }else{
    cout << "Table created successfully\n";
  }

  sqlite3_close(db);

  return 0;
}
