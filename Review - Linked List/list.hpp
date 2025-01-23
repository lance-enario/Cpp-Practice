class List {
    public:
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void insert(int num, int pos) = 0;
    virtual int getHead() = 0;
    virtual int getTail() = 0;
    virtual void removeHead() = 0;
    virtual void removeTail() = 0;
    virtual void getSize() = 0;
    virtual void print() = 0;
};