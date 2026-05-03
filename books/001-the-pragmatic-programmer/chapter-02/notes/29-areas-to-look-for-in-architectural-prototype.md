## 🔹 1) **Are responsibilities of major components well defined?**

👉 Each component should have **one clear job**.

### What to check:

* Does this module do *one thing* or multiple unrelated things?
* Is there overlap between components?

### Bad:

```text
UserService:
  - handles authentication
  - sends emails
  - writes logs
```

### Better:

```text
AuthService → authentication
EmailService → emails
Logger → logging
```

👉 Goal: **high cohesion, no confusion**

---

## 🔹 2) **Are collaborations between components well defined?**

👉 Components should interact through **clear contracts (interfaces/APIs)**

### What to check:

* Who calls whom?
* What data flows between them?
* Is it predictable?

### Bad:

```text
UI directly touches DB + business logic + cache
```

### Better:

```text
UI → API → Service → DB
```

👉 Goal: **clean interaction boundaries**

---

## 🔹 3) **Is coupling minimized?**

👉 Components should **not depend heavily on each other**

### What to check:

* If I change module A, does module B break?
* Are there hard dependencies?

### Bad:

```cpp
PaymentService directly uses MySQL queries everywhere
```

### Better:

```cpp
PaymentService → DatabaseInterface → MySQL/Postgres
```

👉 Goal: **replace/change parts independently**

---

## 🔹 4) **Can you identify potential duplication?**

👉 Look for **same logic appearing in multiple places**

### What to check:

* Same validation logic repeated?
* Same business rules copied?

### Bad:

```js
if (user.age > 18) // repeated in 5 files
```

### Better:

```js
function isAdult(user) { return user.age > 18; }
```

👉 Goal: **single source of truth (DRY)**

---

## 🔹 5) **Are interface definitions and constraints acceptable?**

👉 Interfaces = how components talk
👉 Constraints = limits (input, format, rules)

### What to check:

* Are APIs too restrictive?
* Are they too vague?

### Bad:

```json
POST /user
body: anything
```

### Better:

```json
POST /user
body: { name: string, age: number }
```

👉 Goal: **clear, stable, usable interfaces**

---

## 🔹 6) **Does every module have access to the data it needs? (and at the right time?)**

👉 This is about **data flow + timing**

### What to check:

* Does module have required data?
* Is data available when needed?
* Any delays / missing dependencies?

---

### Example problem:

```text
OrderService needs user info
→ but UserService call is slow or async
→ causes delay/failure
```

---

### Better design:

```text
- Cache user info
- Pass required data upfront
- Use async handling properly
```

---

👉 This is tricky because:

* data dependencies are often hidden
* timing issues show up late

👉 That’s why authors say:

> this gives the most surprises

---

## 🔹 Final mental model

This checklist is basically asking:

👉 “Is my system cleanly divided, loosely connected, non-duplicated, and data-flow correct?”

---

## 🔹 One-line summary

👉 **Use architectural prototypes to validate structure, interactions, dependencies, duplication, interfaces, and data flow before committing to full implementation.**