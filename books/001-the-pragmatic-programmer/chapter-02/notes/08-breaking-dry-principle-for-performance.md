**A very important nuance of DRY** : when it’s okay to bend it.

---

Sometimes you **intentionally duplicate data** to make code faster.

➡️ DRY is a rule, but **performance can justify breaking it**

---

If something is costly to compute repeatedly, you **store (cache) the result**

---

## 🔥 Example

```cpp
double length() {
    return start.distanceTo(end); // expensive calculation
}
```

👉 If called 1000 times → slow

---

## ✅ Solution: Cache it

```cpp
double length;  // stored value
```

➡️ Now you’re duplicating:

* `start + end`
* AND `length`

👉 This **breaks DRY**, but improves performance

---

If you break DRY:

> Keep the duplication **contained in one place**

➡️ Don’t spread it across the system

---

From outside the class:

* No one knows duplication exists

➡️ Public interface remains clean

---

Only internal code ensures:

* cached value is correct
* data stays consistent

➡️ Responsibility is **localized**

---

## 🔹 Now the CODE

---

## 🔹 Private variables

```cpp
bool changed;
double length;
Point start;
Point end;
```

* `length` is cached value
* `changed` tells: “is cache outdated?”

---

## 🔹 Setter functions

```cpp
void setStart(Point p) { start = p; changed = true; }
void setEnd(Point p)   { end = p;   changed = true; }
```

* When start/end changes → mark cache invalid

---

## 🔹 Getter functions

```cpp
Point getStart() { return start; }
Point getEnd()   { return end; }
```

👉 Normal accessors

---

## 🔹 Core logic: `getLength()`

```cpp
double getLength() {
    if (changed) {
        length = start.distanceTo(end);
        changed = false;
    }
    return length;
}
```

---

1. If data changed:
   * recompute length

2. Otherwise:
   * reuse cached value

➡️ Efficient + consistent

---

## A broader lesson here for OOP design

---

👉 Don’t directly access variables like:

```cpp
line.start = p;   // ❌ bad
```

👉 Use methods:

```cpp
line.setStart(p); // ✅ good
```

---

Always use:

* getters
* setters

➡️ Not direct access

---

👉 Because you used setters/getters:

You can later add:

* caching
* logging
* validation

WITHOUT changing external code

---

### 🔥 Example

Without setters:

```cpp
line.start = p;  // no control
```

With setters:

```cpp
setStart(p) {
    start = p;
    changed = true; // enables caching logic
}
```

➡️ You gain control

---

## 🔥 Core Insight

👉 DRY can be broken **safely** if:

* done for performance
* kept internal
* properly managed

---

## 🧠 Final Mental Model

```text
DRY violation (bad) → scattered, inconsistent
DRY violation (good) → controlled, localized, hidden
```

---

# 🧾 One-line note:

**You may break DRY for performance (caching), but keep duplication localized and controlled within a class using accessors.**
