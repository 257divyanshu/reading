# 🔷 Problem Without `virtual`

```cpp
class Animal {
public:
    void speak() {
        cout << "Animal\n";
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Bark\n";
    }
};
```

```cpp
Animal* a = new Dog();
a->speak();   // ❌ prints "Animal"
```

👉 Why?

* Compiler sees: `a` is `Animal*`
* So it binds call **at compile time**

👉 This is called:
**🔹 Compile-time (static) binding**

---

# 🔷 Enter `virtual`

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal\n";
    }
};
```

Now:

```cpp
Animal* a = new Dog();
a->speak();   // ✅ prints "Bark"
```

---

# 🔷 What `virtual` Actually Does

👉 It tells the compiler:

> “Don’t decide which function to call now…
> decide it **at runtime**, based on actual object”

---

# 🔷 Runtime Polymorphism (Simple Meaning)

👉 Same call:

```cpp
a->speak();
```

👉 Different behavior:

* If object = `Dog` → "Bark"
* If object = `Cat` → "Meow"

👉 This is:
**🔹 Runtime polymorphism**
(**many forms at runtime**)

---

# 🔷 Why This Happens

Because:

```cpp
Animal* a = new Dog();
```

* Pointer type = `Animal*`
* Actual object = `Dog`

👉 With `virtual`, C++ checks **actual object type at runtime**

---

# 🔷 One-Line Intuition

* Without `virtual` → *“call based on pointer type”*
* With `virtual` → *“call based on object type”*

---

# 🔷 Internal Idea (keep it light)

C++ maintains a hidden **vtable (virtual table)**
→ maps function calls to correct implementation

You don’t need details now — just know:
👉 It enables runtime decision

---

# 🔷 Why This Matters for Interfaces

Interfaces rely on this:

```cpp
IShape* s = new Circle();
s->area();   // must call Circle's version
```

👉 This only works because of **virtual functions**

---

# 🔷 Quick Analogy

Think:

* Pointer = **remote control**
* Object = **actual device**

`virtual` ensures:
👉 Button presses control the **real device**, not the remote type

---

# 🔷 Final Summary

* `virtual` → enables **runtime decision**
* Runtime polymorphism → same call, different behavior
* Required for:

  * overriding
  * interfaces
  * flexible design