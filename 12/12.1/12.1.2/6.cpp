#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
typedef vector<int> vecint;
vecint* newVector(){
    return new vector<int>();
}
void printVector(istream& in,ostream& out,vecint* p){
    istream_iterator<int> is(in);
    istream_iterator<int> eof;
    copy(is,eof,back_inserter(*p));
    auto it = p->begin();
    while(it != p->end()){
        out << *it << " ";
        ++it;
    }
    out << endl;
    delete p;
}
int main(){
    printVector(cin,cout,newVector());
    return 0;
}
