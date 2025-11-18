/*#include<iostream>
using namespace std;

template<class T>T great( T a,T b)
{
    if(a>b)return a;
    else return b;

}

int main()
{   int a,b;
    cin>>a>>b;
    cout<<great(a,b);
    return 0;

}
*/

/*
#include<iostream>
using namespace std;

template<class A>
void div(A a, A b)
{
    cout<<(a/b)<<endl;

}

int main()
{   //div<int>(10,5);
    int x,y;
    cin>>x>>y;
    div(x,y);
    return 0;
}*/



//SAME typee
/*
#include <iostream>
using namespace std;

template <typename A>
void swapp(A &a, A &b)
{
    A tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << a << endl
         << b;
}

int main()
{
    int x, y;
    cin >> x >> y;

    swapp(x, y);
    return 0;
}
*/

//different type




#include <iostream>
using namespace std;

template <typename A, typename B>
void swapp(A &a, B &b)
{
    auto tmp=static_cast<long double>(a);
    a =static_cast<A>( b);
    b = static_cast<B>(tmp);
    cout << a << endl
         << b;
}

int main()
{
    int x;
    float y;
    cin >> x >> y;

    swapp(x, y);
    return 0;
}
