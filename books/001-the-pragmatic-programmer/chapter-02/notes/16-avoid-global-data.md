## 🔹 Technique: **Avoid Global Data**

This one is subtle but very important.

---

# 🔥 Core Idea

👉 **Global data = hidden coupling between modules**

➡️ Any module can read/write it
➡️ Changes in one place affect many places

---

# 🔹 What is global data?

```js
let currentUser = null; // global variable
```

👉 Accessible from anywhere

---

# ❌ Why it’s bad (breaks orthogonality)

## Problem 1: Hidden dependencies

```js
function greet() {
  console.log("Hello " + currentUser.name);
}
```

👉 `greet()` secretly depends on `currentUser`

➡️ Not obvious from function signature ❌

---

## Problem 2: Hard to change

```js
currentUser = { name: "A" };
greet();

currentUser = { name: "B" };
greet();
```

👉 Behavior depends on global state
➡️ unpredictable

---

## Problem 3: Multithreading issues

👉 If multiple threads modify global data:

```text
Thread 1 → updates currentUser
Thread 2 → reads currentUser
```

➡️ Race conditions ❌

---

# 🔥 Book’s key line explained

> “Even globals that you intend only to read can lead to trouble”

👉 Why?

Because later someone might:

* modify it
* depend on it

➡️ Becomes shared mutable state → chaos

---

# 🔹 Better Approach: Pass context explicitly

## ❌ Bad

```js
let config = { tax: 0.1 };

function calculate(price) {
  return price + price * config.tax;
}
```

---

## ✅ Good

```js
function calculate(price, config) {
  return price + price * config.tax;
}
```

👉 Now dependency is:

* explicit
* visible
* controlled

---

# 🔹 OOP-style solution (from paragraph)

👉 Pass context via objects

```js
class OrderService {
  constructor(config) {
    this.config = config;
  }

  calculate(price) {
    return price + price * this.config.tax;
  }
}
```

---

# 🔹 “Create structures containing context”

👉 Instead of many globals:

```js
let user;
let config;
let logger;
```

👉 Use:

```js
const context = {
  user,
  config,
  logger
};
```

👉 Pass it:

```js
function process(context) {
  context.logger.log(context.user.name);
}
```

---

# 🔹 Singleton warning

👉 Singleton = “only one instance”

```js
class Config {
  static instance = new Config();
}
```

👉 Used like global:

```js
Config.instance.getTax();
```

---

## 🚨 Problem

👉 Singleton = disguised global

➡️ Same issues:

* hidden dependency
* tight coupling

---

# 🔥 Summary of technique

```text
Global data → hidden coupling → hard to maintain
Explicit context → clear dependencies → better design
```

---

# 🧠 Final Insight

👉 Orthogonality requires:

* modules to be independent

👉 Global data does the opposite:

* connects everything invisibly

---

# 🧾 One-line note for you:

**Avoid global state—pass required data explicitly to keep dependencies clear and modules independent.**
