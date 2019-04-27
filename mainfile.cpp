#include <fstream>
#include<cstring>
//#include <string>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include "customer.h"
#include "administrator.h"
using namespace std;


int main ()
{
  cout<<"1.Admin"<<endl;
  cout<<"2.Customer"<<endl;
  cout<<"3.Exit"<<endl;
  int n;
  cin>>n;
  switch (n) {
    case 1:menua();break;
    case 2:menuc();break;
    case 3:exit(1);break;
  }
  return 0;
}
