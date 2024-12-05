#include <iostream>
// 使用inline内联函数示例（只是示意声明，编译器不一定完全按此执行内联优化）
inline int inlineFunction(int x) { return x * 2; }
// 定义一个基类
namespace MyNamespace {
    // 使用struct关键字定义结构体
    struct MyStruct {
        int structInt;
    };
    int app(int a, int b){return a*b*2;}
}

// 使用using关键字引入命名空间中的符号
using namespace MyNamespace;
class BaseClass {
public:
    virtual void virtualFunction() {
        std::cout << "BaseClass virtual function" << std::endl;
    }
};
// 定义一个派生类，继承自BaseClass
class DerivedClass : public BaseClass {
private:
    int derivedPrivateData;
public:
    DerivedClass(int data) : derivedPrivateData(data) {}

    // 重写基类的虚函数，体现多态性，使用virtual关键字
    virtual void virtualFunction() override {
        std::cout << "DerivedClass virtual function with data: " << derivedPrivateData << std::endl;
    }
};
//使用模板元
template <typename T>
T add(T a, T b);
// 定义一个简单的类，继续融入更多关键字展示
class MyClass {
private:
    int privateData;
protected:
    float protectedData;
public:
    double publicData;
    static int staticCount;
    // 重载运算符
    MyClass operator+(const MyClass& other);
    void voidFunction();
    MyClass(int p, float pr, double pu) : privateData(p), protectedData(pr), publicData(pu) {}
    // 虚函数构造
    virtual ~MyClass(){}
    // 添加一个公有函数用于获取privateData的值
    int getPrivateData() const {
        return privateData;
    }
    
    // 使用friend函数声明（这里只是声明，实际完整功能需外部定义）
    friend void friendFunction(MyClass& obj);
    // 成员函数示例用到很多关键字
    void doSomething() {
        if (privateData > 0) {
            std::cout << "Private data is positive" << std::endl;
        } else {
            std::cout << "Private data is non-positive" << std::endl;
        }
        // static_assert 确保MyClass是一个空类（没有任何非静态成员变量，也没有虚函数）
        // static_assert(std::is_empty<MyClass>::value, "empty class needed");
        // 取消注释会报错：error: static assertion failed: empty class needed
        int i = 0;
        while (i < 10) {
            // 这里简单示意下asm，实际可能需要嵌入汇编指令，不同平台差异大

            
            asm("");
            float sc=10.12;
            std::cout<<app(static_cast<int>(sc),i);
            i++;
        }

        for (int j = 0; j < 5; j++) {
            if (j == 3) {
                goto label;
            }
            std::cout << "In for loop: " << j << std::endl;
        }

label:

        // 使用switch语句
        switch (privateData) {
        case 1:
            std::cout << "Private data is 1" << std::endl;
            break;
        default:
            std::cout << "Private data is not 1" << std::endl;
            break;
        }

        const int constValue = 100;
        unsigned int unsignedValue = 50u;
        signed int signedValue = -10;

        // 演示try-catch块
        try {
            if (privateData == -1) {
                throw std::runtime_error("Negative private data");
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        // 定义一个联合体示例
        union MyUnion {
            int intValue;
            char charValue;
        };
        MyUnion myUnion;
        myUnion.intValue = 65;

        // 利用sizeof获取大小信息
        std::cout << "Size of union: " << sizeof(myUnion) << std::endl;

        // 使用typedef定义类型别名
        typedef long MyLong;
        MyLong myLongValue = 1000000L;

        // 使用static成员变量示例
        staticCount++;
        std::cout << "Static count: " << staticCount << std::endl;



        // 调用函数模板
        double result = add<double>(publicData, 5.5);
        std::cout << "Template result: " << result << std::endl;

        // 使用auto自动推导类型示例
        auto autoValue = result;
        std::cout << "Auto deduced value: " << autoValue << std::endl;

        // 使用register（现在编译器优化下作用有限，更多是历史遗留，示意下使用）
        //register int regValue = 10;

        // 使用enum枚举类型示例
        enum MyEnum {
            VALUE_ONE,
            VALUE_TWO
        };
        MyEnum myEnum = VALUE_ONE;


        int inlineResult = inlineFunction(5);
        std::cout << "Inline function result: " << inlineResult << std::endl;

        // 使用new和delete进行动态内存分配和释放示例
        int* ptr = new int(10);
        std::cout << "Allocated value: " << *ptr << std::endl;
        delete ptr;

        // 使用volatile示例（常用于防止编译器过度优化对变量访问，这里简单示意）
        volatile int volatileValue = 20;
        std::cout << "Volatile value: " << volatileValue << std::endl;

        // 使用this指针示例
        std::cout << "This pointer address: " << this << std::endl;



        // 演示虚函数多态性调用
        BaseClass* basePtr = new DerivedClass(5);
        basePtr->virtualFunction();
        delete basePtr;

        // 使用void类型示例（函数无返回值等情况）
        voidFunction();

        // 使用return返回示例
        return;
    }
};
        // 使用operator重载示例（这里简单重载+运算符示意，实际需完整实现逻辑）
MyClass MyClass::operator+(const MyClass& other) {
    return MyClass(privateData + other.privateData, protectedData + other.protectedData, publicData + other.publicData);
}

// 类外定义voidFunction
void MyClass::voidFunction() {
    std::cout << "This is a void function" << std::endl;
}
template <typename T>
T add(T a, T b) {
    return a + b;
}
// 初始化静态成员变量
int MyClass::staticCount = 0;

// 定义friend函数（只是简单示例实现）
void friendFunction(MyClass& obj) {
    std::cout << "Friend function accessing private data: " << obj.getPrivateData() << std::endl;
}

int main() {
    MyClass myObj(1, 2.0f, 3.0);
    myObj.doSomething();
    return 0;
}