👉 **Your architecture decisions should be reversible, not permanent traps.**

---

# 🔥 Scenario 1

### Initially:

```text
Client–Server model
```

### Later:

```text
Business says → too expensive → make it standalone
```

---

## ❓ Question

> How hard should this change be?

👉 Book’s answer:

```text
Just a deployment issue → a few days max
```

---

## 🚨 If it’s hard…

👉 Then your system is:

* tightly coupled
* not reversible

---

# 🔹 Keyword 1: Client–Server Model

👉 System is split into:

```text
Client (frontend) → Server (backend)
```

---

## Example

```text
Browser → API Server → Database
```

### Code view

```js
// client
fetch("/api/user/1");
```

```js
// server
app.get("/api/user/:id", ...)
```

👉 Logic is distributed

---

# 🔹 Keyword 2: Standalone Model

👉 Everything runs in **one application**

---

## Example

```text
Desktop app (like MS Word)
```

---

### Code view

```js
// no server
function getUser(id) {
  return localDB.get(id);
}
```

👉 No network, no server dependency

---

# 🔥 Core Point

👉 If your system is well-designed:

```text
Client-server ↔ Standalone
```

should be:

* easy to switch
* minimal changes

---

# 🔥 How to design for this

👉 Keep business logic separate from:

* UI
* networking

---

## ❌ Bad design

```js
// tightly coupled to server
fetch("/api/user/1").then(...)
```

👉 Hard to convert to standalone

---

## ✅ Good design

```js
class UserService {
  getUser(id) {}
}
```

### Server version

```js
class RemoteUserService {
  getUser(id) {
    return fetch(`/api/user/${id}`);
  }
}
```

### Standalone version

```js
class LocalUserService {
  getUser(id) {
    return localDB.get(id);
  }
}
```

👉 Swap implementation → done

---

# 🔹 Keyword 3: Deploying standalone → client-server / n-tier

---

## What does this mean?

👉 You built:

```text
Standalone app
```

Now you want:

```text
Client → Server → DB (n-tier)
```

---

## 🔹 What is n-tier?

👉 Multiple layers:

```text
UI → Backend → DB
or
UI → API → Service → DB
```

---

## 🔥 Example

### Initially (standalone)

```js
// everything together
function processOrder() {
  validate();
  saveToDB();
}
```

---

### Later (n-tier)

```text
Client → API → Service → DB
```

```js
// client
api.processOrder()

// server
function processOrder() {
  validate();
  db.save();
}
```

---

# 🔥 Book’s key message

👉 Whether you go:

```text
Client-server → Standalone
OR
Standalone → Client-server / n-tier
```

👉 It should NOT be painful

---

# 🧠 Core Insight

```text
Architecture = deployment choice
NOT = hard-coded constraint
```

---

# 🔥 What reversibility means here

👉 Your system should allow:

* changing architecture
* changing deployment model
* without rewriting everything

---

# 🧾 One-line note

**Design systems so changes in deployment architecture (client-server, standalone, n-tier) require minimal effort and don’t affect core logic.**
