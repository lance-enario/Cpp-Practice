class List {
    public:
    
    virtual void print () = 0;
    virtual int get (int pos) = 0;
    virtual void add (int num) = 0;
    virtual void addHead (int num) = 0;
    virtual void addAt(int num,int pos) = 0;
    virtual void remove (int num) = 0;
    virtual void removeAt (int pos) = 0;
    virtual int removeHead () = 0;
    virtual void removeDuplicates(int num) = 0;
    virtual void removeTail () = 0;
    virtual void reverse() = 0;
    virtual void sort() = 0;

};