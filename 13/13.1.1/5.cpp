#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
/*
*没看懂中文版的翻译，看了英文版再来填坑。
*
*/
class HasPtr{
    public:
        HasPtr(const string &s = string()):ps(new string(s)),i(0){}

    private:
        string *ps;
        int i;
};
int main(){
    return 0;
}
