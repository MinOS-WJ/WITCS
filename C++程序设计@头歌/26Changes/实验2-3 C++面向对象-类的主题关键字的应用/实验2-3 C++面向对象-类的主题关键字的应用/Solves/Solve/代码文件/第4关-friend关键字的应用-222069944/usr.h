#ifndef USR_H
#define USR_H

#include <iostream>
class A {
private:
    int n;
public:
    A() : n(0) {}                          // 本地初始化为 0
    int get() const { return n; }          // main 里调用了 temp.get()
    
    friend void Set(A& a, int t);          // 友元函数 Set
    friend class B;                        // 友元类 B
};

class B {
public:
    void Set(A& a, int t) { a.n = t; }     // B 是 A 的友元,可直接改 a.n
};

#endif