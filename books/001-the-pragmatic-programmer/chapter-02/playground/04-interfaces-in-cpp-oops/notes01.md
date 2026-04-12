Here’s a **concise “Interfaces 101” (C++-focused)**:

---

## 🔹 What is an Interface?

An **interface = a contract**
→ It defines *what* a class can do, **not how**

In C++, interfaces are implemented using **abstract classes** (pure virtual functions).

---

## 🔹 Basic Syntax

```cpp
class IShape {   // 'I' prefix is a convention
public:
    virtual double area() = 0;   // pure virtual function
    virtual ~IShape() {}         // virtual destructor (important)
};
```

✔ `= 0` → makes function **pure virtual**
✔ Class becomes **abstract** (cannot instantiate)

---

## 🔹 Implementation (Concrete Class)

```cpp
class Circle : public IShape {
    double r;
public:
    Circle(double r) : r(r) {}

    double area() override {
        return 3.14 * r * r;
    }
};
```

---

## 🔹 Usage (Polymorphism)

```cpp
IShape* shape = new Circle(5);
cout << shape->area();
```

✔ You use the **interface type**, not the concrete class
✔ Enables **runtime polymorphism**

---

## 🔹 Why Interfaces?

* **Decoupling** → change implementation without breaking code
* **Flexibility** → swap implementations easily
* **Testability** → mock implementations

---

## 🔹 Key Rules

* No data members (ideally)
* Only pure virtual functions
* Always add **virtual destructor**
* Cannot create objects of interface

---

## 🔹 Real-world analogy

Interface = **remote control**
→ You press buttons (methods)
→ Don’t care how TV works internally

---

## 🔹 Common Pattern

```cpp
class IDatabase {
public:
    virtual void connect() = 0;
};

class MySQL : public IDatabase { ... };
class MongoDB : public IDatabase { ... };
```

Switch DB without changing main logic ✅