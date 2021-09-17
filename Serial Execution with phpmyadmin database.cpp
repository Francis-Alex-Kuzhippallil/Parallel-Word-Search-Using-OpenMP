#include<iostream>
#include <winsock.h>
#include<windows.h>
#include<mysql.h>
#include<omp.h>
using namespace std;
void psql(int i,string txt) {
 int qstate;
 MYSQL* conn;

 conn=mysql_init(0);
 conn=mysql_real_connect(conn,"localhost","root","","pdc",0,NULL,0);
 MYSQL_ROW row;
 MYSQL_RES* res;
 if(conn)
 {
 if(i==1)
 {
 std::string word = txt;
 std::string tmp = "select count(PNAME) from table1 where PNAME=\'" +word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)
 {
 res=mysql_store_result(conn);
 while(row=mysql_fetch_row(res))
 {
 cout<<"Count from table1 is "<<row[0]<<endl;
 }
 }
 }
 else if(i==2)
 {
 std::string word = txt;
 std::string tmp = "select count(PNAME) from table2 where PNAME=\'" + word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)
 {
 res=mysql_store_result(conn);
 while(row=mysql_fetch_row(res))
 {
 cout<<"Count from table2 is "<<row[0]<<endl;
 }
 }

 }
 else if(i==3)
 {
 std::string word = txt;
 std::string tmp = "select count(PNAME) from table3 where PNAME=\'" + word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)
 {
 res=mysql_store_result(conn);
 while(row=mysql_fetch_row(res))
 {
 cout<<"Count from table3 is "<<row[0]<<endl;
 }
 }
 }
 else if(i==4)
 {
 std::string word = txt;
 std::string tmp = "select count(PNAME) from table4 where PNAME=\'" + word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)
 {
 res=mysql_store_result(conn);
 while(row=mysql_fetch_row(res))
 {
 cout<<"Count from table4 is "<<row[0]<<endl;
 }
 }
 }
 else if(i==5)
 {
 std::string word = txt;
 std::string tmp = "select count(PNAME) from table5 where PNAME=\'" + word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)

 {
 res=mysql_store_result(conn);
 while(row=mysql_fetch_row(res))
 {
 cout<<"Count from table5 is "<<row[0]<<endl;
 }
 }
 }
 else{
 cout<<"end"<<endl;
 }
 }
 else
 {
 cout<<"Not connected"<<endl;
 }
}
int main()
{
 int i=0;
 string txt;
 cout<<"enter the word: ";
 cin>>txt;
 double time = omp_get_wtime();
 for(i=1;i<6;i++)
 {
 psql(i,txt);
 }
 time = (omp_get_wtime() - time)*1000;
 cout << "\nTime is " + to_string(time)+" milli seconds";
 return 0;
}
