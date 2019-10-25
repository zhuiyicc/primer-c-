#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
typedef vector<int> vecint;
shared_ptr<vecint> newVector(){
    return make_shared<vecint>(vecint());
}
void printVector(istream& in,ostream& out,shared_ptr<vecint> p){
    istream_iterator<int> is(in);
    istream_iterator<int> eof;
    copy(is,eof,back_inserter(*p));
    auto it = p->begin();
    while(it != p->end()){
        out << *it << " ";
        ++it;
    }
    out << endl;
}
int main(){
    printVector(cin,cout,newVector());
    return 0;
}
