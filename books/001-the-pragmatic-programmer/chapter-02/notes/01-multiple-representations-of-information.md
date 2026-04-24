# 🔥 Core Idea First

👉 Same **information (knowledge)**
➡️ represented in **different forms**
➡️ across different layers of a system

---

# ✅ Example 1: User Data Across Full Stack

## 🧠 Single Concept:

> A **User** with `id`, `name`, `email`

---

## 1️⃣ Database Representation (SQL)

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(100),
  email VARCHAR(100)
);
```

---

## 2️⃣ Backend Representation (Java)

```java
class User {
  int id;
  String name;
  String email;
}
```

---

## 3️⃣ API Representation (JSON)

```json
{
  "id": 1,
  "name": "Divyanshu",
  "email": "div@example.com"
}
```

---

## 4️⃣ Frontend Representation (TypeScript)

```ts
type User = {
  id: number;
  name: string;
  email: string;
};
```

---

## 🚨 What’s happening?

👉 SAME information:

```text
User = { id, name, email }
```

👉 But represented in:

* SQL
* Java
* JSON
* TypeScript

➡️ This is **“multiple representations of the same information”**

---

# ⚠️ The Problem (Why this matters)

Now imagine you change something:

```text
Add field: age
```

You must update:

* DB schema ✅
* Backend class ✅
* API response ✅
* Frontend type ✅

👉 If you forget ONE → bugs 💥

---

# 🔥 Example 2: Validation Logic Duplication

## 🧠 Rule:

> Password must be at least 8 characters

---

## Frontend (JS)

```js
if (password.length < 8) {
  showError("Too short");
}
```

---

## Backend (Node.js)

```js
if (password.length < 8) {
  throw new Error("Too short");
}
```

---

## 🚨 Same rule, different forms

➡️ This is again:
**same knowledge → multiple representations**

---

# 🔥 Example 3: API Contract

## 🧠 Concept:

> Product object

---

## Backend (Node.js)

```js
res.json({
  id: 1,
  name: "Phone",
  price: 1000
});
```

---

## Frontend expects:

```ts
type Product = {
  id: number;
  name: string;
  price: number;
};
```

---

👉 If backend changes:

```js
price → cost
```

Frontend breaks ❌

➡️ Because **same info represented differently**

---

# 🧠 Why Author is Saying This

👉 You **cannot avoid** multiple representations
(because different systems need different formats)

BUT:

❗ Problem = manually maintaining them
❗ Solution = **single source of truth + generation**

---

# ✅ Better Approach (DRY)

Instead of writing everywhere manually:

```json
// schema.json (single source)
{
  "User": {
    "id": "int",
    "name": "string",
    "email": "string"
  }
}
```

👉 Generate:

* DB schema
* Backend class
* Frontend types

---

# 🧾 Final One-line Understanding

**Same data must exist in different forms across systems—but managing them manually creates duplication and bugs.**
