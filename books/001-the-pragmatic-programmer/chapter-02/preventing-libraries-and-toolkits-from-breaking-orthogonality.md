The main idea (which is being repeated here in different forms):

> **Don’t let libraries/tools leak into your core design and break orthogonality.**

---

# 🔹 1. “Be careful to preserve orthogonality… choose technologies wisely”

👉 Meaning:
When you add a library/framework:

* it can **force your code to change shape**

👉 If that happens → ❌ breaks orthogonality

---

# 🔹 2. Java RMI example (important)

## 🔥 Problem setup

They had code that:

* runs locally
* OR runs remotely

---

## ❌ Using RMI (bad here)

👉 With Java RMI:

* remote calls can throw exceptions

So your code becomes:

```java
try {
    remoteService.doSomething();
} catch (RemoteException e) {
    // handle network failure
}
```

---

## 🚨 Problem

Now EVERY place calling this must:

* handle remote exceptions
* know it's remote

👉 Your business logic is now polluted with:

* networking concerns

➡️ NOT orthogonal

---

## 🔥 Why bad?

```text
Business Logic + Network Logic mixed ❌
```

---

## ✅ Using CORBA (better here)

👉 CORBA allowed:

* calling remote objects like local ones

```java
service.doSomething(); // same call
```

👉 No need to care:

* local vs remote

---

## 🔥 Insight

👉 Good abstraction hides:

* location
* implementation

---

# 🔹 3. “Ask whether toolkit imposes changes…”

👉 When using any library, ask:

> Does this force me to write code differently everywhere?

---

## Example: ORM (database)

### ❌ Bad ORM

```js
db.saveUser(user); // but only works if user has special annotations
```

👉 Now your whole code depends on ORM-specific patterns

---

### ✅ Good ORM

```js
repository.save(user);
```

👉 Internals hidden → orthogonal

---

# 🔹 4. “If persistence is transparent → orthogonal”

👉 Transparent = invisible

---

## Example

### ❌ Non-transparent

```js
user.saveToDatabase(); // DB logic inside model
```

---

### ✅ Transparent

```js
userService.save(user);
```

👉 Business logic doesn’t care HOW it’s saved

---

# 🔹 5. EJB Example (important concept)

## Problem

Normally you write:

```java
startTransaction();
// business logic
endTransaction();
```

👉 Transaction logic scattered everywhere

---

## ✅ EJB solution

Move transaction logic to metadata:

```java
@Transactional
public void transferMoney() {
    // business logic only
}
```

---

👉 Now:

* no transaction code in logic
* handled externally

➡️ Orthogonal

---

# 🔹 6. “Same code runs in different environments”

👉 Because logic is clean:

* can run in different systems
* no change needed

➡️ Flexible system

---

# 🔹 7. AOP (Aspect-Oriented Programming)

👉 This is the most interesting part

---

## 🔥 Problem: Logging everywhere

```java
function process() {
    log("start");
    // logic
    log("end");
}
```

👉 Logging code scattered everywhere ❌

---

## ✅ AOP solution

Define logging separately:

```java
aspect Trace {
  advice * process(..) {
    before {
      log("Entering method");
    }
  }
}
```

---

👉 Then “weave” it into code

➡️ Your original code:

```java
function process() {
    // clean logic
}
```

---

## 🔥 Result

* Logging added automatically
* Code unchanged
* Clean separation

---

# 🔹 8. “If you weave this aspect…”

👉 If enabled → logs appear
👉 If disabled → no logs

➡️ Behavior added/removed without touching code

---

# 🔥 Core Insight (VERY IMPORTANT)

👉 Orthogonality = **separating concerns**

---

## Examples of concerns

* business logic
* database
* logging
* transactions
* networking

---

👉 Good system:

```text
Each concern isolated
```

---

👉 Bad system:

```text
Everything mixed everywhere
```

---

# 🧠 Final Mental Model

```text
If a library forces your code to change everywhere → bad
If a library stays isolated → good
```

---

# 🧾 One-line notes:

* **Choose tools that don’t leak into your core logic.**
* **Keep concerns like logging, transactions, and networking separate from business logic.**
* **Good abstractions make code unaware of implementation details (location, storage, etc.).**
