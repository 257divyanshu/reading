# 🔷 The Line

```cpp
Circle(double r) : r(r) {}
```

---

# 🔷 Break It Down

### 1. `Circle(double r)`

👉 Constructor that takes a parameter `r`

---

### 2. `: r(r)`

👉 This is the **initializer list**

Format:

```cpp
: member_variable(parameter)
```

So here:

* left `r` → class member
* right `r` → constructor parameter

👉 Meaning:

> “Initialize member `r` with the value of parameter `r`”

---

### 3. `{}`

👉 Empty constructor body

---

# 🔷 Equivalent (but less efficient)

```cpp
Circle(double r) {
    this->r = r;
}
```

---

# 🔷 Why Initializer List is Better

* Direct initialization ✅
* Required for:

  * `const` members
  * references
* More efficient (no extra assignment)

---

# 🔷 Visual Flow

```cpp
Circle c(5);
```

👉 Steps:

1. Constructor called with `r = 5`
2. `: r(r)` → member `r` becomes `5`
3. Object ready

---

# 🔷 Important Insight

Even though names are same:

```cpp
r(r)
```

👉 It means:

```
this->r = r
```

---

# 🔷 Pro Tip

You can rename to avoid confusion:

```cpp
Circle(double radius) : r(radius) {}
```

---

# 🔷 Final Summary

* `: r(r)` → initialize member variable
* Happens **before constructor body runs**
* Preferred over assignment inside `{}`