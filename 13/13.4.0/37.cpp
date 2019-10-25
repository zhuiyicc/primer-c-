#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;
class Folder;
class Message{
    friend class Folder;
    public:
        explicit Message(const string &str=""):
            contents(str){}
        Message(const Message &p)
        :contents(p.contents),folders(p.folders){
            add_to_Folders(p);
        }
        Message& operator=(const Message &p){
            remove_from_Folders();
            contents = p.contents;
            folders = p.folders;
            add_to_Folders(p);
            return *this;
        }
        ~Message(){
            remove_from_Folders();
        }
        void save(Folder &p){
            folders.insert(&p);
            p.addMsg(this);
        }
        void remove(Folder &p){
            folders.erase(&p);
            p.remMsg(this);
        }
        void addFolder(Folder *p){
            folders.insert(p);
        }
        void remFolder(Folder *p){
            folders.erase(p);
        }
    private:
        string contents;
        set<Folder*> folders;
        void add_to_Folders(const Message& p){
            for(auto f : p.folders)
                f->addMsg(this);
        }
        void remove_from_Folders(){
            for(auto f : folders)
                f->remMsg(this);
        }
};
class Folder{
    public:
        void addMsg(Message* p){
            msg.insert(p);
        }
        void remMsg(Message* p){
            msg.erase(p);
        }
    private:
        string name;
        set<Message*> msg;
};
int main(){
    return 0;
}
