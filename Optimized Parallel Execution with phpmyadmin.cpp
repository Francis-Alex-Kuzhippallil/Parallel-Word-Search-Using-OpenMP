#include<iostream>
#include <winsock.h>
#include<windows.h>
#include<mysql.h>
#include<omp.h>
using namespace std;
void psql(int i,string txt)
{
 int qstate;
 MYSQL* conn;
 conn=mysql_init(0);
 conn=mysql_real_connect(conn,"localhost","root","","pdc",0,NULL,0);
 MYSQL_ROW row;
 MYSQL_RES* res;
 if(conn)
 {
 std::string word = txt;
 std::string iter = to_string(i);

 std::string tmp = "select count(PNAME) from table"+iter+" where PNAME=\'" +word+"\'";
 qstate=mysql_query(conn,tmp.c_str());
 if(!qstate)
 {
 res=mysql_store_result(conn);
 //cout<<"Email id"<<" "<<"name"<<" "<<"combo"<<endl;
 while(row=mysql_fetch_row(res))
 {
 //cout<<row[0]<<" " <<row[1]<<" "<<row[2]<<endl;
 cout<<"\nCount from Table "<<i<< " is "<<row[0]<<endl;
 }
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
 cout<<" ";
 double time = omp_get_wtime();
 #pragma omp parallel
 #pragma omp for
 for(i=1;i<6;i++)
 {
 psql(i,txt);
 }
 time = (omp_get_wtime() - time)*1000;
 cout << "\nTime is " + to_string(time)+" milli seconds";
 return 0;
}
