# 🔷 What is an Abstract Class?

👉 An **abstract class = incomplete class**

* It defines *what should exist*
* But **does NOT fully implement it**

👉 You **cannot create objects** of it

---

# 🔷 Why Do We Need It?

Think:

> “All shapes have area… but HOW to compute it depends on the shape”

So:

* Circle → πr²
* Rectangle → l × b

👉 Base class **can’t define one universal formula**

---

# 🔷 Syntax (Core Idea)

```cpp
class Shape {
public:
    virtual double area() = 0;  // pure virtual
};
```

👉 `= 0` means:

* “No implementation here”
* “Derived classes MUST implement this”

---

# 🔷 Pure Virtual Function (Important)

```cpp
virtual void func() = 0;
```

👉 This does 2 things:

1. Makes function **mandatory to override**
2. Makes class **abstract**

---

# 🔷 Why Object Creation Fails

```cpp
Shape s;  // ❌ ERROR
```

👉 Because:

* `Shape` doesn’t know how to compute `area()`
* It’s incomplete

---

# 🔷 Derived Class Completes It

```cpp
class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}

    double area() override {
        return 3.14 * r * r;
    }
};
```

👉 Now it’s complete → object can be created

---

# 🔷 How It’s Used (IMPORTANT)

```cpp
Shape* s = new Circle(5);
cout << s->area();
```

👉 Flow:

* Pointer type = `Shape*`
* Actual object = `Circle`
* `area()` → resolved at runtime

---

# 🔷 Key Properties

✔ Cannot instantiate abstract class
✔ Must override all pure virtual functions
✔ Used as **base class only**
✔ Enables polymorphism

---

# 🔷 Mental Model (Very Important)

👉 Abstract class = **template of behavior**

It says:

> “Any child class MUST provide these functions”

---

# 🔷 Real-World Analogy

Abstract class = **job role description**

Example:

* Role: “Employee”
* Must have:

  * `work()`
  * `getSalary()`

But:

* Manager works differently than Developer

👉 So base class defines rules, not implementation

---

# 🔷 Abstract Class vs Normal Class

| Feature             | Normal Class | Abstract Class   |
| ------------------- | ------------ | ---------------- |
| Can create object   | ✅            | ❌                |
| Has full methods    | ✅            | ❌ (some missing) |
| Has `= 0` functions | ❌            | ✅                |

---

# 🔷 IMPORTANT Insight (Interview-level)

👉 Abstract class = **partial abstraction**

* Can have:

  * implemented functions ✅
  * pure virtual functions ✅

---

# 🔷 Bridge to Interfaces (VERY IMPORTANT)

👉 If you remove all implementations:

```cpp
class IShape {
public:
    virtual double area() = 0;
};
```

👉 This becomes:
**“Interface-like class” in C++**

---

# 🔷 Final Summary

* Abstract class = class with **at least one pure virtual function**
* Cannot instantiate
* Forces derived classes to implement behavior
* Enables runtime polymorphism
* Foundation of interfaces