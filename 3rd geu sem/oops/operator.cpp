/*#include<iostream>
using namespace std;
class Complex {
private:int real, imag;
public:
friend istream& operator>> (istream &c,Complex& x);
friend ostream& operator<< (ostream&v,Complex &h);
};
istream& operator >>(istream& c , Complex& x)
{
    c>>x.real;
    c>>x.imag;
    return c;
}

ostream& operator<< (ostream& v,Complex& h)
{
    v<<h.real<<"+"<<h.imag<<"i";
    return v;

}
int main()
{
   Complex s;
   cin>>s;
   cout<<s<<endl;
   return 0;



}*/

#include <iostream>
using namespace std;
class A
{
private:
    int y;

public:
    A(int x)
    {
        y = x;
    }
    A operator++()
    {

        ++y;
        return *this;
    }
     
    A operator--()
    {
        A b=*this;
        y--;
        return b;
    }
    void show()
    {
        cout << y<<endl;
    }
};

int main()
{
    A a(8);
    ++a;
    
    a.show();
    a--;
    a.show();
    return 0;
}
