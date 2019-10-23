#include <iostream>
#include <string>
using namespace std;
class HasPtr{
    public:
        HasPtr(const int xx = 0,const string& s = ""):x(xx){
            strp = new string(s);
        }
        HasPtr(HasPtr& a):x(a.x){
            strp = new string(*a.strp);
        }
        HasPtr& operator=(const HasPtr& a){
            x = a.x;
            if(strp != nullptr)
                delete strp;
            strp = new string(*a.strp);
            return *this;
        }
        ~HasPtr(){
            delete strp;
        }
        friend ostream& operator<<(ostream& out,const HasPtr& a){
            return out << hex << a.strp <<" "<< *a.strp << endl;
        }
    private:
        int x;
        string *strp;
};
int main(){
    int t = 1;
    string s = "123";
    HasPtr p1(t,s);
    HasPtr p2 = p1;
    HasPtr p3;
    p3 = p2;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    return 0;
}
