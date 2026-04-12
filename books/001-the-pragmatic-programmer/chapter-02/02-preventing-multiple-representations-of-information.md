This is one of the **most important parts of DRY**.

---

# 🔹 Paragraph 2: *“Multiple representations of information…”*

---

### **1. “Multiple representations of information.”**

👉 Meaning:
Same data/knowledge exists in **different forms/places**.

---

### **2. “At the coding level, we often need to have the same information represented in different forms.”**

👉 Meaning:
In real systems, you *must* represent the same thing differently.

**Example:**

* Database → table schema
* Backend → class
* Frontend → JSON

➡️ Same concept, different formats

---

### **3. “Maybe we’re writing a client-server application… using different languages on the client and server…”**

👉 Meaning:
Frontend and backend use **different languages**, so duplication happens.

**Example:**

```js
// Frontend (JS)
{
  id: number,
  name: string
}
```

```java
// Backend (Java)
class Product {
  int id;
  String name;
}
```

➡️ Same structure duplicated

---

### **4. “…and need to represent some shared structure on both.”**

👉 Meaning:
Both sides need the **same data definition**.

➡️ This is unavoidable — but dangerous if manually duplicated.

---

### **5. “Perhaps we need a class whose attributes mirror the schema of a database table.”**

👉 Meaning:
Your code often copies DB structure.

**Example:**

```sql
-- DB
Product(id INT, name VARCHAR)
```

```java
// Code
class Product {
  int id;
  String name;
}
```

➡️ Duplication between DB and code

---

### **6. “Maybe you’re writing a book and want to include excerpts of programs that you also will compile and test.”**

👉 Meaning:
Even documentation can duplicate code.

**Example:**

* Code in repo
* Same code copy-pasted in docs/book

➡️ Now 2 versions exist → risk of mismatch

---

# 🔹 Paragraph 3: *“With a bit of ingenuity…”*

---

### **1. “With a bit of ingenuity you can normally remove the need for duplication.”**

👉 Meaning:
Duplication looks unavoidable — but with smart design, you can eliminate it.

---

### **2. “Often the answer is to write a simple filter or code generator.”**

👉 Meaning:
Instead of writing the same thing multiple times, **generate it automatically**.

---

### 🔥 Example: Code Generator

Instead of writing this manually:

```java
class Product {
  int id;
  String name;
}
```

```js
// frontend
{
  id: number,
  name: string
}
```

👉 Use a **single source of truth**:

```json
// schema.json
{
  "Product": {
    "id": "int",
    "name": "string"
  }
}
```

Then generate:

* Java class
* JS object type
* DB schema

➡️ No duplication — everything comes from one place

---

### **3. “Structures in multiple languages can be built from a common metadata representation…”**

👉 Meaning:
Define structure **once (metadata)** → generate everywhere.

➡️ Metadata = description of data

---

### **4. “…using a simple code generator each time the software is built.”**

👉 Meaning:
Generation should be **automatic (build step)** — not manual.

---

### **5. “Class definitions can be generated automatically from the online database schema…”**

👉 Meaning:
Instead of copying DB → code manually, generate classes from DB.

**Example tools:**

* Hibernate (Java)
* Prisma (JS)

---

### **6. “The code extracts in this book are inserted by a preprocessor each time we format the text.”**

👉 Meaning:
Even this book avoids duplication!

➡️ Code in book = pulled automatically from real source

---

### **7. “The trick is to make the process active…”**

👉 Meaning:
This must be **automated and always running**, not one-time.

---

### **8. “…this cannot be a one-time conversion…”**

👉 Meaning:
If you generate once and then edit manually → duplication comes back.

---

### **9. “…or we’re back in a position of duplicating data.”**

👉 Meaning:
If automation stops, duplication returns → DRY is broken again.

---

# 🔥 Core Insight (very important)

👉 The problem is NOT multiple representations
👉 The problem is **multiple sources of truth**

---

# 🧠 Final Mental Model

❌ Bad (duplication):

```text
DB schema → manually copied → backend → manually copied → frontend
```

✅ Good (DRY):

```text
Single source (metadata/schema)
        ↓
   auto-generate everywhere
```

---

# 🧾 One-line note for you:

**Use a single source of truth and generate all representations to avoid duplication across systems.**