#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
class StrBlob{
    public:
        StrBlob():p(new vector<string>()){}
        StrBlob(const vector<string> vec):p(new vector<string>(vec)){}
        StrBlob(const StrBlob& a):p(new vector<string>(*p.get())){}
        StrBlob& operator=(const StrBlob& a){
            vector<string> *vec = new vector<string>();
            vector<string> *vecp = a.p.get();
            auto it = vecp->begin();
            while(it != vecp->end()){
                vec->push_back(*it);
                ++it;
            }
            cout << hex << &p << endl;
            p.reset(vec);//此处将会swap两个shared_ptr,而在reset中创建的局部shared_ptr会在reset返回时释放资源。
            return *this;
        }
    private:
        shared_ptr<vector<string> > p;
};
int main(){
    vector<string> vec;
    vec.push_back(string("123"));
    vec.push_back(string("1234"));
    StrBlob str1(vec);
    StrBlob str2;
    str2 = str1; 
    return 0;
}
