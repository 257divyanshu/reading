This section is about **real-world laziness shortcuts**.

---

# 🔹 1. “Copy a routine and tweak it”

## 🧠 Real-life case

You wrote:

```js
function calculateDiscount(price) {
  return price * 0.9;
}
```

Now you need a similar function:

```js
function calculatePremiumDiscount(price) {
  return price * 0.85;
}
```

👉 Instead of reusing/generalizing, you:

* copy
* tweak

---

## ❌ Problem later

* Bug found in discount logic
* You fix one function
* Forget the other

➡️ Inconsistent behavior

---

## ✅ Better

```js
function calculateDiscount(price, rate) {
  return price * rate;
}
```

---

# 🔹 2. “Using literal values instead of central definition”

## 🧠 Real-life case

You need max points = 100

Instead of:

```cpp
const int MAX_POINTS = 100;
```

You do:

```cpp
if (score > 100) ...
if (bonus > 100) ...
array[100]
```

👉 Why?

> “Changing header will rebuild project… too much effort”

---

## ❌ Problem later

Requirement changes → 100 → 200

Now you must:

* find all `100`s manually
* miss one → bug

---

## ✅ Better

```cpp
const int MAX_POINTS = 100;
```

---

# 🔹 3. “Copying library/runtime code”

## 🧠 Real-life case

You need a data structure or utility.

Instead of importing library:

```java
import java.util.HashMap;
```

👉 You:

* copy code from somewhere
* modify it

---

## ❌ Problem later

* Original library gets bug fixes
* Your copied version doesn’t
* You now maintain your own broken fork

---

## ✅ Better

* Use library
* Wrap if needed

---

# 🔥 Pattern behind all 3

👉 Motivation:

* “This is faster right now”

👉 Reality:

* Creates **multiple sources of truth**

---

# 🔹 Now: Y2K part (very important)

---

## 🔹 What was the Y2K problem?

👉 Years stored as **2 digits**

```text
98 → 1998
00 → ??? (1900 or 2000?)
```

➡️ Systems broke at year 2000

---

# 🔹 1. “Not parameterizing the size of date fields”

## ❌ What they did

Hardcoded:

```cpp
char year[2];  // only 2 digits
```

or

```cpp
int year = 99; // assumes 1900s
```

---

## 🚨 Problem

* System assumes:

  ```
  19xx
  ```
* Year 2000 → breaks logic

---

## ✅ If parameterized

```cpp
int YEAR_DIGITS = 4;
```

or better:

```cpp
int year = 1999;
```

➡️ Flexible → future-proof

---

# 🔹 2. “No centralized date library”

## ❌ What they did

Each developer wrote their own logic:

```cpp
if (year < 50) year += 2000;
else year += 1900;
```

➡️ Same logic duplicated everywhere

---

## 🚨 Problem

* Some places updated
* Some not
* System becomes inconsistent

---

## ✅ Centralized approach

```cpp
class DateService {
public:
    int normalizeYear(int y) {
        return y < 100 ? 1900 + y : y;
    }
};
```

👉 Everyone uses:

```cpp
DateService.normalizeYear(y);
```

---

## 🔥 Benefit

* Fix logic → update ONE place
* Whole system fixed

---

# 🔥 Core Insight (important)

👉 Y2K wasn’t just a “date bug”
👉 It was a **duplication + bad design problem**

---

# 🧠 Final Mental Model

```text
Impatient shortcut → duplication → scattered logic → huge future failure
```

---

# 🧾 One-line notes:

* **Impatient duplication → copying or hardcoding for short-term speed causes long-term bugs.**
* **Y2K happened because date logic wasn’t centralized or flexible (hardcoded assumptions everywhere).**
