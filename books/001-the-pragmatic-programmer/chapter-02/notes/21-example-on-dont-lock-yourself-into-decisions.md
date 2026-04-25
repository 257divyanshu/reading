**Reversibility = don’t lock yourself into decisions**.

---

# 🔥 Scenario in the paragraph

1. You choose:

```text
Database A (relational DB)
```

2. Later you discover:

```text
Database B (object DB) is faster
```

---

# ❌ Typical (bad) situation

👉 Your code is written like this:

```js
// everywhere in your code
db.query("SELECT * FROM users WHERE id = 1");
```

👉 Problem:

* Code is tightly tied to **Database A**
* SQL is scattered everywhere

---

## 🚨 Result

If you switch DB:

* you must change **hundreds of places**
* high effort, high risk

➡️ You’re “out of luck”

---

# 🔥 Why this happens

> “calls to third-party products are entangled throughout the code”

👉 Means:

* database calls are mixed into business logic
* no separation

---

# ✅ Better approach (Reversibility)

> “abstracted the idea of a database”

👉 Treat DB as:

```text
Persistence Service
```

---

## 🔥 What does that mean?

Instead of writing SQL everywhere:

👉 Create an abstraction layer

---

## ✅ Example

### Step 1: Define interface

```js
class UserRepository {
  getUserById(id) {}
}
```

---

### Step 2: Implementation for DB A

```js
class SqlUserRepository extends UserRepository {
  getUserById(id) {
    return db.query(`SELECT * FROM users WHERE id = ${id}`);
  }
}
```

---

### Step 3: Implementation for DB B

```js
class ObjectDbUserRepository extends UserRepository {
  getUserById(id) {
    return objectDb.find(User, id);
  }
}
```

---

### Step 4: Use abstraction

```js
function getUserProfile(repo, id) {
  return repo.getUserById(id);
}
```

---

# 🔥 Now what happens?

👉 Switching DB becomes:

```js
const repo = new ObjectDbUserRepository();
```

👉 No other code changes

---

# 🔥 Key line explained

> “provides persistence as a service”

👉 Means:

* your code doesn’t care:

  * SQL vs NoSQL
  * MySQL vs MongoDB
  * local vs remote

👉 It only cares:

```text
“store and retrieve data”
```

---

# 🔥 “change horses in midstream”

👉 Means:

> Change decisions **after development has started**

Without breaking everything

---

# 🧠 Core Insight

```text
Bad design  → tied to specific tool → irreversible
Good design → abstracted → reversible
```

---

# 🔥 Real-world analogy

👉 Think like this:

* Bad: you plug directly into wall wiring
* Good: you use a standard socket

👉 Now you can change devices easily

---

# 🧾 One-line note

**Design systems so implementation details (like database choice) can be changed later without affecting core logic.**