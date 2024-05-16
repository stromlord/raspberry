template <typename Object>
class Vector{
public:
    // 构造函数
    // 函数声明开头，explicit关键字，用来声明某个构造函数、转换函数或转换运算符不允许被隐式转换使用。
    explicit Vector(int initSize=0)
        : theSize(initSize), theCapacity(initSize + SPACE_CAPACITY)
        {objects = new Object[theCapacity];}
    
    // 复制构造函数
    Vector(const Vector & rhs) : objects(nullptr)
        {operator=(rhs);}   // 调用赋值运算符
    
    // 析构函数
    ~Vector() {delete [] objects;}

    // 赋值运算符，实现深度复制
    const Vector & operator=(const Vector & rhs){
        if (this != &rhs){      // 如果地址不相同
            delete [] objects;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;

            objects = new Object[capacity()];
            for (int k=0; k<size(); k++)
                objects[k] = rhs.objects[k];
        }
        return *this;
    }

    void resize(int newSize){
        if(newSize > theCapacity)
            reserve(newSize*2+1);
        theSize = newSize;
    }

    void reserve(int newCapacity){
        if (!newCapacity < theSize)
            return;
        
        Object *oldArray = objects;

        objects = new Object[newCapacity];
        for (int k=0; k<theSize; k++)
            objects[k] = oldArray[k];
        theCapacity = newCapacity;

        delete [] oldArray;
    }

    int size() const {return theSize;}
    int capacity() const {return theCapacity;}


    enum {SPACE_CAPACITY = 16};
private:
    int theSize;
    int theCapacity;
    Object * objects;
};