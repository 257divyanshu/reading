# 🔹 First Paragraph

> *“Every time you write code you run the risk of reducing the orthogonality…”*

## 👉 Meaning

Whenever you write new code, you might:

* accidentally **couple modules**
* duplicate logic
* mix responsibilities

➡️ Orthogonality is **fragile**

---

> *“Unless you constantly monitor… larger context…”*

👉 Don’t just think:

> “Does this code work?”

👉 Also think:

> “Does this break separation? Does it duplicate something?”

---

## 🔥 Real example

You write:

```js
function calculateTotal(order) {
  return order.price + order.tax;
}
```

Later somewhere else:

```js
function getFinalPrice(order) {
  return order.price + order.tax; // duplicated logic ❌
}
```

👉 Works fine
👉 But now:

* duplication exists
* logic is not centralized

➡️ Orthogonality reduced

---

> *“…you might unintentionally duplicate functionality…”*

👉 This is the core warning:

* duplication = hidden coupling
* leads to bugs later

---

## 🧠 Summary of para

👉 Writing code is easy
👉 Maintaining **clean separation + no duplication** is hard

---

# 🔹 First Technique: “Keep your code decoupled”

---

## 👉 What does “decoupled” mean?

👉 Modules should:

* not depend on each other’s internals
* interact only via **clear interfaces**

---

# 🔥 1. “Write shy code…”

👉 “Shy code” = code that:

* doesn’t expose too much
* doesn’t depend too much

---

## ❌ Bad (not shy)

```js
order.customer.address.street.name
```

👉 This depends on:

* customer
* address
* street

➡️ Too much knowledge → tightly coupled

---

## ✅ Good (shy)

```js
order.getCustomerStreetName();
```

👉 You only depend on `order`
➡️ Internal structure hidden

---

# 🔥 2. “Don’t rely on other modules’ implementations”

👉 Only rely on:

* what a module promises (interface)

---

## ❌ Bad

```js
if (user.role === "admin") {
  // depends on internal structure
}
```

---

## ✅ Good

```js
if (user.isAdmin()) {
  // uses interface
}
```

---

# 🔥 3. “Law of Demeter (LoD)”

👉 Rule:

> “Only talk to your immediate friends”

---

## ❌ Violates LoD

```js
order.getCustomer().getAddress().getZip();
```

👉 Too many chained dependencies

---

## ✅ Follows LoD

```js
order.getCustomerZip();
```

---

# 🔥 4. “If you need to change an object’s state, get it to do it for you”

👉 Don’t manipulate internals directly

---

## ❌ Bad

```js
user.balance = user.balance - 100;
```

---

## ✅ Good

```js
user.debit(100);
```

👉 Logic stays inside `user`

---

# 🔥 Why this helps orthogonality

👉 When modules are decoupled:

* You can change one module
* Without breaking others

---

## Example

```js
// change inside user class
debit(amount) {
  this.balance -= amount;
}
```

👉 No other code affected

---

# 🔥 Final Insight

```text
Coupled code → ripple effects
Decoupled code → local changes
```

---

# 🧾 One-line notes for you:

* **Always think about system-wide impact while writing code.**
* **Keep modules decoupled—depend on interfaces, not implementations.**
* **Follow Law of Demeter: talk only to immediate objects.**
