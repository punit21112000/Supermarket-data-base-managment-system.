#include <fstream>
#include<cstring>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include "administrator.h"
using namespace std;





// Create and Add Product information in text file
  void producta::crt ()
    {
      ofstream fil;
      fil.open ("admin.txt", ios::app);
      if ( fil.fail() ) {
      cout << "Error in file opening!"	<< endl;
      exit(1);
    }
      char c;
      do
      {
        cout << "Please enter Product Number: " << endl;
        cin >> pno;
        cout << "Please enter Product Category: " << endl;
        cin.ignore (256, '\n');
        getline (cin, categ);
        cout << "Enter Product Name: " << endl;
        getline (cin, name);
        cout << "Please enter Product Price: " << endl;
        cin >> price;
        cout << "Please enter Quantity of Product: " << endl;
        cin >> quant;
        cout << "Please enter the Discount(%) on the Product: " << endl;
        cin >> disc;
        fil << pno << " " << categ << " " << name << " " << price << " " <<
        quant << " " << disc << endl;
        cout << "To add more items press Y or y: ";
        cin >> c;
      }
      while (c == 'y' || c == 'Y');
      fil.close ();
    }

//Shows the Products entered by the Admin  
    void producta::shw ()
    {
      ifstream fil;
      fil.open ("admin.txt");
      if ( fil.fail() ) {
      cout << "Error in file opening!"	<< endl;
      exit(1);
    }
      cout << setw (80) <<"------------------------------------------------------------------------------------------"<< endl;
      cout << endl;
      cout << setw (6) << "P.No";
      cout << setw (13) << "Category";
      cout << setw (12) << "Name";
      cout << setw (9) << "Price";
      cout << setw (13) << "Quantity";
      cout << setw (13) << "Discount";;
      cout << setw (20) << "Discounted Price";
      cout << endl;
      cout << setw (80) <<"------------------------------------------------------------------------------------------"<< endl;
      while (fil >> pno >> categ >> name >> price >> quant >> disc)
      {
        cout << endl;
        cout << setw (6) << pno;
        cout << setw (13);
        cout << categ;
        cout << setw (12);
        cout << name;
        cout << setw (9) << price;
        cout << setw (13) << quant;
        cout << setw (13) << disc;
        cout << setw (20) << ((100.0 - disc) / 100.0) * price;
        cout << endl;
      }
      cout << endl;
      cout << setw (80) <<"------------------------------------------------------------------------------------------"<< endl;
      fil.close ();
    }


// Displays information of a particular Product 
  void producta::disp ()
    {
      cout << "The Product Number of the Product is: " << pno << endl;
      cout << "The category of the Product is: " << categ << endl;
      cout << "The Name of the Product is: " << name << endl;
      cout << "The price of the Product is: " << price << endl;
      cout << "The quantity of the Product is: " << quant << endl;
      cout << "The Discount(%) on the Product is: " << disc << "%" << endl;
    }


//Searches desired product
  void producta::search ()
    {
      ifstream fil;
      int n, choice = 0, c = 0;
      string x;
      fil.open ("admin.txt");
      if ( fil.fail() ) {
      cout << "Error in file opening!"	<< endl;
      exit(1);
    }
      cout << "enter 1. to search by product number" << endl;
      cout << "enter 2. to search by product name" << endl;
      cout << "enter 3. to search by product category" << endl;
      cin >> choice;
      if (choice == 1)
      {
        cout << "Enter Product number you want to search ";
        cin >> n;
        while (fil >> pno >> categ >> name >> price >> quant >> disc)
        {
          if (pno == n)
          {
            cout << endl;
            disp ();
            c++;
          }
        }
      }
      else if (choice == 2)
      {
        cout << "Enter Product name you want to search ";
        cin.ignore (256, '\n');
        getline (cin, x);
        while (fil >> pno >> categ >> name >> price >> quant >> disc)
        {
          if (x == name)\
          {
            cout << endl;
            disp ();
            c++;
          }
        }
      }

    else if (choice == 3)
    {
      cout << "Enter Product category you want to search ";
      cin.ignore (256, '\n');
      getline (cin, x);
      while (fil >> pno >> categ >> name >> price >> quant >> disc)
      {
        if (x == categ)
        {
          cout << endl;
          disp ();
          c++;
        }
      }
    }
  if (c == 0)
{
  cout << endl << "SORRY" << endl << "Product Number not found" <<endl;
}
fil.close ();
}

// Deletes information of a record
void producta::del ()
{
  ifstream fil1;
  ofstream fil2;
  fil1.open ("admin.txt");
  fil2.open ("admin2.txt");
  if ( fil1.fail() ) {
  cout << "Error in file opening!"	<< endl;
  exit(1);
}
 if ( fil2.fail() ) {
  cout << "Error in file opening!"	<< endl;
  exit(1);
}
  int inod;
  cout << "Enter product number to be deleted" << endl;
  cin >> inod;
  int d = 0;
  while (fil1 >> pno >> categ >> name >> price >> quant >> disc)
  {
    if (pno != inod)
    {
      fil2 << pno << " " << categ << " " << name << " " << price << " "<< quant << " " << " " << disc << endl;
    }
    else
    {
      d++;
    }
  }
  if (!d)
  cout << endl << "Item not found" << endl;
  else
  cout << endl << "Item has been deleted" << endl;
  fil1.close ();
  fil2.close ();
  remove ("admin.txt");
  rename ("admin2.txt", "admin.txt");
}

// Edits Details of a record
void producta::modify()
{
  ifstream fil1;
  ofstream fil2;
  fil1.open("admin.txt");
  fil2.open("admin2.txt");
  if ( fil1.fail() ) {
  cout << "Error in file opening!"	<< endl;
  exit(1);
}
if ( fil2.fail() ) {
cout << "Error in file opening!"	<< endl;
exit(1);
}
  int a;
  char c;
  string p;
  double d;
  do
  {
    cout<<"Enter P.No of product data to be modified: "<<endl;
    cin>>a;
    int no;
    cout<<"What do you want to modify"<<endl;
    cout<<"1.Pno"<<endl;
    cout<<"2.Category"<<endl;
    cout<<"3.Name"<<endl;
    cout<<"4.Price"<<endl;
    cout<<"5.Quantity"<<endl;
    cout<<"6.Discount"<<endl;
    cout<<"7.Entire record"<<endl;
    cin>>no;
    while(fil1>>pno>>categ>>name>>price>>quant>>disc)
    {
      if (pno!=a)
          fil2<<pno<<" "<<categ<<" "<<name<<" "<<price<<" "<<quant<<" "<<disc<<endl;
      else
      {
        switch (no)
        {
          case 1:
              int b;
              cout<<"Enter new P.No"<<endl;
              cin>>b;
              fil2<<b<<" "<<categ<<" "<<name<<" "<<price<<" "<<quant<<" "<<disc<<endl;
              break;
          case 2:
              cout<<"Enter new Category"<<endl;
              cin.ignore(256,'\n');
              getline (cin,p);
              fil2<<pno<<" "<<p<<" "<<name<<" "<<price<<" "<<quant<<" "<<disc<<endl;
              break;
          case 3:
              cout<<"Enter new Name"<<endl;
              cin.ignore(256,'\n');
              getline (cin,p);
              fil2<<pno<<" "<<categ<<" "<<p<<" "<<price<<" "<<quant<<" "<<disc<<endl;
              break;
          case 4:
                cout<<"Enter new Price"<<endl;
                cin>>d;
                fil2<<pno<<" "<<categ<<" "<<name<<" "<<d<<" "<<quant<<" "<<disc<<endl;
                break;
          case 5:
              int f;
              cout<<"Enter new Quantity"<<endl;
              cin>>f;
              fil2<<pno<<" "<<categ<<" "<<name<<" "<<price<<" "<<f<<" "<<disc<<endl;
              break;
          case 6:
              int g;
              cout<<"Enter new Discount"<<endl;
              cin>>g;
              fil2<<pno<<" "<<categ<<" "<<name<<" "<<price<<" "<<quant<<" "<<g<<endl;
              break;
          case 7:
              cout << "Please enter Product Number: " << endl;
              cin >> pno;
              cout << "Please enter Product Category: " << endl;
              cin.ignore (256, '\n');
              getline (cin, categ);
              cout << "Enter Product Name: " << endl;
              getline (cin, name);
              cout << "Please enter Product Price: " << endl;
              cin >> price;
              cout << "Please enter Quantity of Product: " << endl;
              cin >> quant;
              cout << "Please enter the Discount(%) on the Product: " << endl;
              cin >> disc;
              fil2<< pno << " " << categ << " " << name << " " << price << " " <<quant << " " << disc << endl;
              break;
          default:
              cout<<"wrong option selected"<<endl;
        }
      }
    }
    cout << "Modify more Items(y/Y)";
    cin>>c;
  }while (c=='Y'||c=='y');
  fil1.close();
  fil2.close();
  remove("admin.txt");
  rename("admin2.txt","admin.txt");
  }
//Sorts the records according to product number
void sort ()
{
  ifstream fin;
  fstream f;
  fin.open("admin.txt");
  f.open("admincopy.txt",ios::out);
  product *q=new product;
  if ( fin.fail() )
  {
    cout << "Error in file opening!"	<< endl;
    exit(1);
  }
  if ( f.fail() )
  {
    cout << "Error in file opening!"	<< endl;
    exit(1);
  }
  while(fin.read((char*)&q,sizeof(q)))
  {
    f.write((char*)&q,sizeof(q));
  }
  fin.close();
  f.close();
  f.open("admincopy.txt",ios::in);
  ofstream fout("admin1.txt",ios::out);
  if ( fout.fail() )
  {
    cout << "Error in file opening!"	<< endl;
    exit(1);
  }
  int pno1, quant1;
  string name1,categ1;
  double price1, qty1, disc1;
  while(f>>pno1)
  {
    f.close();
    f.open("admincopy.txt",ios::in);
    int small = 9000;
    for(int i=0;f >> pno1 >> categ1 >> name1 >> price1 >> quant1 >> disc1;i++)
    {
      if( pno1<=small)
      {
        small=pno1;
      }
    }
    f.close();
    ofstream fil2;
    fil2.open ("admincopy2.txt");
    f.open("admincopy.txt",ios::in);
    if ( f.fail() )
    {
      cout << "Error in file opening!"	<< endl;
      exit(1);
    }
    if ( fil2.fail() )
    {
     cout << "Error in file opening!"	<< endl;
     exit(1);
    }
    while (f >> pno1 >> categ1 >> name1 >> price1 >> quant1 >> disc1)
    {
      if (pno1 != small)
       {
         fil2 << pno1 << " " << categ1 << " " << name1 << " " << price1 << " "<< quant1 << " "<< disc1 << endl;
       }
      if (small == pno1)
      {
        fout << pno1 << " " << categ1 << " " << name1 << " " << price1 << " " << quant1 << " " << disc1 << endl;
      }
    }
    f.close();
    fil2.close ();
    remove ("admincopy.txt");
    rename ("admincopy2.txt", "admincopy.txt");
    f.open("admincopy.txt",ios::in);
  }
  remove ("admincopy.txt");
  remove("admin1.txt");
  rename ("admin1.txt", "admin.txt");
  f.close();
  fout.close();
  delete q;
}

// Menu for admin 
 void menua()
 {
   char x;
    producta p;
    do
    {
    int n;
    cout<<"1.Add"<<endl;
    cout<<"2.Show"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Modify"<<endl;
    cout<<"6.Sort"<<endl;
    cout<<"7.Exit"<<endl;
    cin>>n;
    switch (n)
    {
      case 1: p.crt();break;
      case 2: p.shw();break;
      case 3: p.search();break;
      case 4: p.del();break;
      case 5: p.modify();break;
      case 6: sort();break;
      case 7: cout<<"EXITING.....";exit(1); break;
      default: cout<<"Wrong Option Chosen"<<endl;
    }
    cout<<"Continue(Y/y)?"<<endl;
    cin>>x;
  }while (x=='Y'||x=='y');

}
