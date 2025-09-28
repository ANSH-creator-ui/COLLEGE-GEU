
/*

#include<iostream>
using namespace std;
class best;
class test{
    int a;
    public:
     test(int a)
     {
        this->a=a;
     }

     friend void swapp(test & , best &);
     void show()
     {
        cout<<"a="<<a<<endl;
     }

    };

    class best{
        int b;
        public:
        best(int b)
        {
            this->b=b;

        }        friend void swapp(test & , best &);
        void show()
        {
            cout<<"b="<<b<<endl;

        }
    };

void swapp(test &x ,best &y)
{
    int tmp=x.a;
    x.a=y.b;
    y.b=tmp;


}

int main()
{
    test t1(9);
    best t2(10);
    swapp(t1,t2);
    t1.show();
    t2.show();
}

*/
// OVERLOADING

/*
#include<iostream>
using namespace std;


class Best{


    int h,m;
    public:
    Best(int k=0,int l=0)
    {
        h=k;
        m=l;
    }

     Best operator-( Best &);
    void show()
    {
        cout<<h<<"hours"<<m<<"minutes"<<endl;
    }

};


   Best Best :: operator-( Best &c2)
     {
        Best tmp;
        tmp.h=h*60+m;
        tmp.m=c2.h*60+c2.m;
         int diff=tmp.h-tmp.m;
         tmp.h=diff/60;
         tmp.m=diff%60;

return tmp;
     }

     int main()
     {
        Best c1(2,15),c2(1,15);
        cout<<"c1=";c1.show();
        cout<<"c2=";c2.show();
       Best c3=c1-c2;
       c3.show();


     }
*/

#include <iostream>
using namespace std;

class Best
{
    string s;

public:
    Best(string p)
    {
        s = p;
    }
    void show()
    {
        cout << "string=" << s << endl;
    }

    bool operator==(Best &e)
    {
        return s == e.s;
    }
};

int main()
{
    Best c1("ansh"), c2("madhvi"), c3("ansh");
    cout << "c1=";
    c1.show();
    cout << "c2=";
    c2.show();
    cout << "c3=";
    c3.show();

    if (c1 == c2)
        cout << "euqal";
    else
        cout << "enequal";
    cout << endl;

    if (c1 == c3)
        cout << "euqal";
    else
        cout << "enequal";
}