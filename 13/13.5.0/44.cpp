#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
class String{
    public:
        String(){
            first = alloc.allocate(1);
            alloc.construct(first,'\0');
            last = cap = first + 1;
        }
        String(const char *s){
            auto pa = copy(s,s+strlen(s)+1);
            first = pa.first;
            last = pa.second;
        }
        String(const String& s){
            auto pa = copy(s.first,s.last);
            first = pa.first;
            last = cap = pa.second;
        }
        size_t size(){
            return last - first;   
        }
        void push_back(const char &ch){
            check();
            --last;
            alloc.construct(last++,ch);
            alloc.construct(last++,'\0');
        }
        String& operator+=(const char &ch){
            push_back(ch);
            return *this;
        }
        friend ostream& operator<<(ostream& out,const String& s){
            __ostream_insert(out,s.first,s.last - s.first);
            return out;
        }
        ~String(){
            free();
        }
    private:
        static allocator<char> alloc;
        char *first;
        char *last;
        char *cap;
        void check(){
            if(cap == last)
                newAlloc();
        }
        void free(){
            alloc.deallocate(first,last-first);
        }
        pair<char *,char *> copy(const char* b,const char *e){
            auto data = alloc.allocate(e - b);
            return {data,uninitialized_copy(b,e,data)};
        }
        void newAlloc(){
            size_t sz = size() << 1;
            auto data = alloc.allocate(sz);
            auto b = data;
            for(auto p = first;p != last;){
                alloc.construct(b++,move(*p++));
            }
            free();
            first = data;
            last = b;
            cap = first + sz;
        }
};
allocator<char> String::alloc;
int main(){
    clock_t c1 = clock();
    String s;
    for(int i = 0;i < 10000000;++i){//此测试下移动拷贝似乎比直接拷贝要慢
        s += i%26+'a';
    }
    clock_t c2 = clock();
    cout << (double)(c2 - c1)/CLOCKS_PER_SEC << endl;
    return 0;
}
