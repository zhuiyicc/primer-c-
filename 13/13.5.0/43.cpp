#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;
class StrVec{
    public:
        StrVec()
        :elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(const StrVec &p){
            auto pa = copy_n(p.begin(),p.end());
            elements = pa.first;
            first_free = cap = pa.second;
        }
        StrVec(const initializer_list<string> &il){
            auto pa = copy_n(il.begin(),il.end());
            elements = pa.first;
            first_free = cap = pa.second;
        }
        StrVec& operator=(const StrVec &p){
            auto pa = copy_n(p.begin(),p.end());
            free();
            elements = pa.first;
            first_free = cap = pa.second;
            return *this;
        }
        void push_back(const string& s){
            full();
            alloc.construct(first_free++,s);
        }
        void pop_back(){
            if(!empty()){
                --first_free;
            }else{
                cout << "pop error" << endl;
            }
        }
        string *begin() const{
            return elements;
        }
        string *end() const{
            return first_free;
        }
        ~StrVec(){
            free();
        }
        void resize(size_t n){
            if(size() <= n)
                return;
            while(n != size()) --first_free;
        }
        void reserve(size_t n){
            if(capacity() >= n)
                return;
            newAlloc();
        }
        friend ostream& operator<<(ostream& out,const StrVec& a){
            for(auto p = a.begin();p != a.end();++p)
                out << *p << endl;
            return out;
        }
    private:
        static allocator<string> alloc;
        string *elements;
        string *first_free;
        string *cap;
        /* StrVec(const string *b,const string *e){
            
        } */
        size_t size(){
            return first_free - elements;
        }
        size_t capacity(){
            return cap - elements;
        }
        pair<string*,string*> copy_n(const string *first,const string *end){
            auto data = alloc.allocate(end - first);
            return {data,uninitialized_copy(first,end,data)};
        }
        void full(){//检查当前容量是否已满
            if(size() == capacity()){
                newAlloc();
            }
        }
        bool empty(){
            if(first_free == elements)
                return true;
            return false;
        }
        void free(){
            for(auto p = elements;p!=first_free;){
                alloc.destroy(p++);
            }
            alloc.deallocate(elements,cap-elements);
        }
        void newAlloc(){//新分配内存并存储旧数据
            auto sz = (cap - elements)<<1;
            auto data = alloc.allocate(sz);
            auto dest = data;
            for(auto p = elements;p!=first_free;){
                alloc.construct(dest++,move(*p++));
            }
            free();
            elements = data;
            first_free = dest;
            cap = elements + sz;
        }
};
allocator<string> StrVec::alloc;
int main(){
    StrVec strv = {"122","12222","1111"};
    for(int i = 0;i < 50;++i){
        string s;
        int len = random() % 20 + 1;
        for(int j = 0;j < len;++j){
            char ch = random() % 26 + 'a';
            s += ch;
        }
        strv.push_back(s);
    }
    cout << strv << endl;
    return 0;
}
