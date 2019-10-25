#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;
volatile int c = 0;
class HasPtr{
    public:
        HasPtr(const string &s = string()):ps(new string(s)),i(0){}
        HasPtr(const HasPtr &p):
            ps(new string(*p.ps)),i(p.i){}
        friend void swap(HasPtr& a,HasPtr& b){
            swap(a.ps,b.ps);
            swap(a.i,b.i);
            cout << "swap:" << ++c << endl;
        }
        bool operator<(const HasPtr& p){
            return *ps < *p.ps;
        }
        friend ostream& operator<<(ostream& out,const HasPtr& p){
            out << *p.ps << endl;
            return out;
        }
        HasPtr& operator=(const HasPtr& p){
            ps = new string(*p.ps);
            i = p.i;
        }
        ~HasPtr(){
            delete ps;
        }
    private:
        std::string *ps;
        int i;
};
int main(){
    vector<HasPtr> vec;
    for(int i = 0;i < 50;++i){
        int len = random() % 20;
        string s;
        for(int j = 0;j < len;++j){
            int ch = random() % 26;
            s += (char)(ch+'a');
        }
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    for(int i = 0;i < 50;++i){
        cout << vec[i];
    }
    cout << endl;
    return 0;
}
