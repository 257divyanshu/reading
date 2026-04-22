## 🔹 Technique 3: **Avoid Similar Functions**

---

# 🔥 Core Idea

👉 If you see multiple functions that look similar, it’s often a sign of:

* duplication
* poor abstraction

➡️ This **breaks orthogonality**

---

# 🔹 What the book means

> “Functions may share code at the start and end, but differ in the central algorithm”

👉 Structure same, logic slightly different

---

## ❌ Example (bad)

```js
function processCreditCard(payment) {
  validate(payment);
  // credit card logic
  chargeCard(payment);
  log(payment);
}

function processUPI(payment) {
  validate(payment);
  // UPI logic
  sendUPI(payment);
  log(payment);
}
```

👉 Problems:

* duplicated `validate()`
* duplicated `log()`
* only middle differs

➡️ duplication = not orthogonal

---

# 🔥 Why this is dangerous

👉 Later change:

```js
function validate(payment) {
  // new validation rule
}
```

👉 You must update:

* all similar functions

➡️ easy to miss → bugs

---

# 🔹 Better Approach: **Abstract the variation**

👉 Extract common structure

---

## ✅ Solution 1: Higher-order function

```js
function processPayment(payment, strategy) {
  validate(payment);
  strategy(payment);
  log(payment);
}
```

Usage:

```js
processPayment(payment, chargeCard);
processPayment(payment, sendUPI);
```

---

## ✅ Solution 2: Strategy Pattern (OOP)

```js
class PaymentStrategy {
  process(payment) {}
}

class CreditCardStrategy extends PaymentStrategy {
  process(payment) {
    chargeCard(payment);
  }
}

class UPIStrategy extends PaymentStrategy {
  process(payment) {
    sendUPI(payment);
  }
}
```

Main flow:

```js
function processPayment(payment, strategy) {
  validate(payment);
  strategy.process(payment);
  log(payment);
}
```

---

# 🔥 Why this improves orthogonality

👉 Now:

```text
Common logic → one place
Variable logic → separate
```

➡️ Clean separation

---

# 🔹 Book’s key line explained

> “Duplicate code is a symptom of structural problems”

👉 Meaning:

* duplication = not the real problem
* bad design is the real problem

---

# 🔥 Mental Model

```text
Similar functions → duplication → bad design
Abstract common parts → clean design
```

---

# 🧠 Final Insight

👉 Don’t copy-paste similar functions
👉 Instead:

* find pattern
* extract abstraction

---

# 🧾 One-line note for you:

**Similar-looking functions indicate duplication—abstract common behavior and isolate differences to maintain orthogonality.**
