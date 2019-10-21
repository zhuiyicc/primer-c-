class Employee{
    public:
        static int sz;
        static int size(){return sz;}
        Employee():id(++sz){
        }
        Employee(const string& name):empName(name),id(++sz){
        }
        void print(){
            cout << "id: " << id <<" name: " << empName << endl;
        }
    private:
        size_t id;
        string empName;
};
