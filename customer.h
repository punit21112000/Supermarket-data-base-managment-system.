#pragma once
#include <string>


using namespace std;

class productc
{
  int pno,quant;
  int n,q;
  string name;
  string categ ;
  double price,qty,disc ;
  public :
    string retcateg ()
    {
      return categ;
    }
    int retquant()
    {
      return quant ;
    }

    int retpno()
    {
      return pno ;
    }
    int retdisc()
    {
      return disc ;
    }

    string retname()
    {
      return name ;
    }

    double retprice()
    {
      return price ;
    }

    void order();

  int update (int a, int b);

  void modify (int q,int inod);


   void writeorder(int a,int b);




  void placeorder();

  void dispbill();
};

void menuc();
