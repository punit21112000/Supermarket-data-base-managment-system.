#pragma once
#include <string>


using namespace std;

class producta
{
  int pno, quant;
  string name,categ;
  double price, qty, disc;

  public:
  string retcateg ()
    {
      return categ;
    }

  int retquant ()
    {
      return quant;
    }

  int retpno ()
    {
      return pno;
    }

  int retdisc ()
    {
      return disc;
    }

  string retname ()
    {
      return name;
    }

  double retprice ()
    {
      return price;
    }
  void crt ();
  void shw ();
  void disp ();
  void search ();
  void del ();
  void modify();


};
void sort();
void menua();
