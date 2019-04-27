

#include <fstream>
#include<cstring>
#include <string>
#include <cstdio>
#include <iomanip>
#include "customer.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// Gives Pno and Quatntiy to place Order
void productc::order()
    {
      cout << "Enter Product Number: "<<endl;
      cin  >> n;
      cout << "Enter Product Quantity: "<<endl ;
      cin  >> q;
    }

// Updates the recod after Order is placed 
void productc::modify (int q,int inod)
   {
     ifstream fil1;
     ofstream fil2;
     fil1.open("admin.txt");
     fil2.open("admin2.txt");
     if ( fil1.fail() )
     {
       cout << "Error in file opening!"	<< endl;
       exit(1);
     }
     if ( fil2.fail() )
     {
       cout << "Error in file opening!"	<< endl;
       exit(1);
     }
     while(fil1>>pno>>categ>>name>>price>>quant>>disc)
     {
       if (pno!=inod)
           fil2<<pno<<" "<<categ<<" "<<name<<" "<<price<<" "<<quant<<" "<<disc<<endl;
       else
           fil2<<pno<<" "<<categ<<" "<<name<<" "<<price<<" "<<quant-q<<" "<<disc<<endl;
     }
     fil1.close();
     fil2.close();
     remove("admin.txt");
     rename("admin2.txt","admin.txt");
   }

// Fuction Places order and preforms necessary updates 
   void productc::writeorder(int a,int b)
   {
     ifstream fil1;
     ofstream fil2;
     fil2.open("user.txt",ios::app);
     fil1.open("admin.txt");
     if ( fil1.fail() )
     {
       cout << "Error in file opening!"	<< endl;
       exit(1);
     }
     if ( fil2.fail() )
     {
       cout << "Error in file opening!"	<< endl;
       exit(1);
     }
     while(fil1>>pno>>categ>>name>>price>>quant>>disc)
     {
       if(pno==a)
       {
         if(update(q,n))
         fil2<<a<<" "<<categ<<" "<<name<<" "<<price<<" "<<b<<" "<<disc<<endl;
       }
     }
     fil1.close();
     fil2.close();
   }

// Checks if the quantity orderd is not higher then the quantity availible
   int productc::update (int a, int b)
   {

     if (q>quant)
     {
       cout<<"Quantity not availible"<<endl;
       return 0;
     }
     else
     {
       modify(a,b);
       return 1;
     }
   }

//Function to Place Order
  void productc::placeorder()
    {
      ifstream fil;
      fil.open("admin.txt");
      if ( fil.fail() )
      {
        cout << "Error in file opening!"	<< endl;
        exit(1);
      }
      cout<<"Products Available In the Super Market"<<endl;
      cout <<setw(80)<< "------------------------------------------------------------------------------------------"<<endl ;
      cout <<endl ;
      cout <<setw(6)<< "P.No" ;
      cout <<setw(13)<<"Category";
      cout <<setw(12)<<"Name";
      cout<<setw(9)<<"Price" ;
      cout <<setw(13)<< "Quantity" ;
      cout<<setw(13)<< "Discount" ; ;
      cout<<setw(14)<< "Total";
      cout<< endl;
      cout <<setw(80)<<"------------------------------------------------------------------------------------------"<<endl ;
      while(fil>>pno>>categ>>name>>price>>quant>>disc)
      {
        cout<<endl;
        cout <<setw(6)<< pno;
        cout<<setw(13);
        cout<<categ ;
        cout<<setw(12);
        cout<<name;
        cout<<setw(9)<< price ;
        cout<<setw(13)<<quant;
        cout<<setw(13)<< disc ;
        cout<<setw(14)<< ((100-disc)*price)/100.0;
        cout<<endl;
      }
      cout<<endl;
      cout <<setw(80)<<"------------------------------------------------------------------------------------------"<<endl ;
      cout<<endl<<endl<<endl ;
      fil.close();
      ofstream f1;
      f1.open("user.txt");
      if ( f1.fail() )
      {
        cout << "Error in file opening!"	<< endl;
        exit(1);
      }

      char x;
      do
      {
        order();
        writeorder(n,q);
        cout<<"Want to add more items(Y/y)?" ;
        cin>>x ;
      }while(x=='y'|| x=='Y');
      f1.close();
  }
// Displays the order placed by the user and prints an invoice online
  void productc::dispbill()
  {
    double sum=0;
    ifstream fil;
    fil.open("user.txt");
    if ( fil.fail() )
    {
      cout << "Error in file opening!"	<< endl;
      exit(1);
    }
    cout <<setw(80)<< "--------------------------------------------------------------------------------------------------------"<<endl ;
    cout <<endl ;
    cout <<setw(6)<< "P.No" ;
    cout <<setw(13)<<"Category";
    cout <<setw(12)<<"Name";
    cout<<setw(9)<<"Price" ;
    cout <<setw(13)<< "Quantity" ;
    cout<<setw(13)<< "Discount"  ;
    cout<<setw(20)<< "Discounted Price";
    cout<<setw(15)<< "Final Price" ;
    cout<< endl;
    cout <<setw(80)<< "--------------------------------------------------------------------------------------------------------"<<endl ;
    while(fil>>pno>>categ>>name>>price>>quant>>disc)
    {
      cout<<endl;
      cout <<setw(6)<< pno;
      cout<<setw(13);
      cout<<categ ;
      cout<<setw(12);
      cout<<name;
      cout<<setw(9)<< price ;
      cout<<setw(13)<<quant;
      cout<<setw(13)<< disc ;
      cout<<setw(20)<< (((100.0-disc)*price)/100.0);
      cout<<setw(15)<< quant*(((100.0-disc)*price)/100.0);
      cout<<endl;
      sum+= quant*(((100.0-disc)*price)/100.0);

    }
    cout <<endl<<"Total: "<<sum<<endl;
    cout <<setw(80)<< "--------------------------------------------------------------------------------------------------------"<<endl ;
  }

// Menu for Customer
void menuc ()
{
  char c;
  productc p;
  do
  {
    int n;
    cout<<"1.Place Order"<<endl;
    cout<<"2.Display Order"<<endl;
    cin >> n;
    switch (n)
    {
      case 1:p.placeorder();break;
      case 2:p.dispbill();break;
      default: cout<<"Entered Wrong Option";
    }
    cout<<"Continue(Y/y)?"<<endl;
    cin>>c;
  }while (c=='Y'||c=='y');
}
