/*#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"enter string=";
    getline(cin,s);
    cout<<s;
    char ch;
    int k=0;
    cout<<endl<<"emter character u want to delete=";
    cin>>ch;
     for(int i=0;i<s.size();i++)
    {
          if(s[i]!=ch)

          {
                  s[k]=s[i];
                    k++;          }
       
    }
    s.resize(k);
    cout<<"string after deletion of k="<<endl<<s;
}*/

/*
#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"enter string=";
      getline(cin,s);     
      int arr[256]={0};
      for(int i=0;i<s.size();i++)
      {
        arr[s[i]]++;
      }

      for(int i=0;i<s.size();i++)
      {
        if(arr[s[i]]==1)
        {
            cout<<s[i]<<' ';
        }
      }
      return 0;
}*/

#include<iostream>
using namespace std;

class hostel
{
    int rno;
    string name;
    double tariff;
    int NOD;
     
    double calc(){
        float amount=NOD*tariff;
        if(amount > 10000)
        {
            return 1.05*amount;
        }
        return amount;
    }

    public:

       void checkin()
       {
        
          cout<<"rno=";
          cin>>rno;
          cout<<"Name=";
          cin>>name;
          cin.ignore();
          cout<<"tariff=";
          cin>>tariff;
          cout<<"NOD=";
          cin>>NOD;
           }

       void  checkout()
       {

        cout<<rno<<endl<<name<<endl<<tariff<<endl;
        cout<<calc();;
       }
    };

    int main()
    {
        hostel ob;
        ob.checkin();
        ob.checkout();
        return 0;
    }
