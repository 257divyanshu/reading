# 🔷 Example with Multiple Members

```cpp id="e3j7n3"
class Circle {
    double r;
    int id;

public:
    Circle(double radius, int idVal) 
        : r(radius), id(idVal) {}   // multiple initializations
};
```

---

# 🔷 General Syntax

```cpp id="q1j6u9"
Constructor(params) : member1(val1), member2(val2), member3(val3) {}
```

---

# 🔷 Important Rules

### 1. Initialization order ⚠️

👉 **Order is NOT the same as list order**

It follows **declaration order** in class:

```cpp id="r7g3tl"
class A {
    int x;
    int y;
public:
    A() : y(2), x(1) {}  // still x initialized first, then y
};
```

---

### 2. Required for these cases

Must use initializer list for:

```cpp id="2f6o9m"
class A {
    const int x;
    int& ref;
public:
    A(int val, int& r) : x(val), ref(r) {}
};
```

---

### 3. Cleaner + efficient

Better than:

```cpp id="k4y8sm"
A(int a, int b) {
    x = a;
    y = b;
}
```

---

# 🔷 Quick Mental Model

👉 Initializer list = **“build object directly”**
👉 Assignment inside `{}` = **“build then modify”**

---

# 🔷 Final Summary

* Use `: a(x), b(y), c(z)`
* Separate with commas
* Order follows **member declaration**, not list
* Mandatory for `const` & references