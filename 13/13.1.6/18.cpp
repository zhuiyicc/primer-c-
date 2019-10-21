class Employee{
    public:
        static int sz;
        static int size(){return sz;}
        Employee():id(++sz){
        }
        Employee(const string& name):empName(name),id(++sz){
        }
        Employee(const Employee& emp):empName(emp.empName),id(++sz){}
        Employee& operator=(const Employee& emp){
            empName = emp.empName;
            id = ++sz;
            return *this;
        }
        void print(){
            cout << "id: " << id <<" name: " << empName << endl;
        }
    private:
        size_t id;
        string empName;
};
