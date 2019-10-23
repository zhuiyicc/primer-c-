#include <iostream>
#include <string>
using namespace std;
class HasPtr{
    public:
        HasPtr():s(new string()),c(new size_t(1)){}
        HasPtr(const HasPtr& a):s(a.s),c(a.c){++c;}
        HasPtr& operator=(const HasPtr& a){
            ++*a.c;
            s = a.s;
            if(--*c){
                delete s;
                delete c;
            }
            s = a.s;
            c = a.c;
            return *this;
        }
        ~HasPtr(){
            if(--*c){
                delete s;
                delete c;
            }
        }
    private:
        string *s;
        size_t *c;
};
int main(){
    return 0;
}
