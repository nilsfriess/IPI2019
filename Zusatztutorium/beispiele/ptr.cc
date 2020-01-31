#include <iostream>

template <typename T>
class Ptr {
  struct RefCntObj {
    int count;
    T* obj;
    RefCntObj(T* t) {
      count = 1;
      obj = t;
    }
  };
  
public:  
  Ptr(T* t){
    ref = new RefCntObj(t);
  }

  ~Ptr() {
    decrement();
    if (ref->count == 0) {
      delete ref->obj;
      delete ref;
    }
  }

  T& operator*() {
    return *(ref->obj);
  }

  T* operator->() {
    return ref->obj;
  }

  void increment() {
    ref->count++;
    std::cout << "Increment : " << ref->count << '\n';
  }

  void decrement() {
    ref->count--;
  }

  Ptr(const Ptr<T> &other) {
    ref = other.ref;
    increment();
  }

private:
  RefCntObj *ref;
};

class A {
public:
  int x = 10;
};

int g(Ptr<A> p) {
  return p->x;
}

int main() {
  Ptr<A> pa1 = new A();
  Ptr<A> pa2(pa1);
  Ptr<A> pa3(pa2);
  g(pa3);
}
