### ✅ Correct Answer

**The small, combinable command-line utilities are more orthogonal.**

---

### 🔥 Why?

* Each utility does **one specific task** (single responsibility)
* They are **independent of each other**
* They interact through a **simple, standard interface (text streams)**
* They can be **combined freely (via pipes)** without knowing each other’s internals

---

### ❌ In contrast: large GUI tools

* Combine **many responsibilities** in one application
* Tightly integrated features → **less independent**
* Harder to reuse parts independently
* Less flexible in composition

---

### 🧠 Core Insight

```text
Small tools → independent + composable → high orthogonality
Large tools → bundled + interdependent → low orthogonality
```

---