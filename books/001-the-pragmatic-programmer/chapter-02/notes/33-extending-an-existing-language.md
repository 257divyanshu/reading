This paragraph introduces a **third approach** to building a mini-language—very practical and widely used today.

---

# 🔹 Core idea (one line)

👉 **Instead of creating a new language, extend an existing language (like Python) to behave like your domain language.**

---

# 🔹 Step-by-step breakdown

## 🔸 “extend an existing one”

👉 You don’t build:

* parser
* grammar
* compiler

👉 You reuse an existing language (Python, JS, etc.)

And **inject your domain concepts into it**

---

## 🔹 What does that mean?

👉 You create classes/functions so that code looks like domain language

---

# 🔹 Understand the given example

```python
record = X25LINE1.get(format=ABC123)

if (record.balance < 0):
    X25LINE1.put(record, format=ABC123)
else:
    TELSTAR1.put(record, format=XYZ43B)
    DB.store(record)
```

---

## 🔹 What’s happening here?

This is **normal Python**, but:

👉 `X25LINE1`, `TELSTAR1`, `DB`
👉 `get()`, `put()`, `store()`

are designed to match **domain concepts**

---

## 🔹 Translate this to plain English

👉 “Get a record from X25LINE1 in ABC123 format
If balance is negative → send it back
Else → send to TELSTAR1 and store in DB”

---

## 🔹 Why this is powerful

👉 This code is:

* readable by domain experts
* close to business logic
* still executable Python

---

# 🔹 What you are actually building

👉 This is called an **Internal DSL (Embedded DSL)**

You are:

* using Python syntax
* but expressing domain logic

---

## 🔹 How you would implement it

Example:

```python
class Line:
    def get(self, format):
        # fetch data
        return Record()

    def put(self, record, format):
        # send data
        pass

class DB:
    def store(self, record):
        pass
```

---

👉 Now your domain language is built *inside Python*

---

# 🔹 Compare with previous approaches

| Approach                        | Effort | Flexibility |
| ------------------------------- | ------ | ----------- |
| New mini-language               | High   | Very high   |
| Parser-based                    | Medium | High        |
| Extend existing language (this) | Low    | High enough |

---

# 🔹 Why authors suggest this

👉 Because it gives:

* fast development
* no need for parser tools
* real executable system

---

# 🔹 Real-world examples

* SQLAlchemy (Python ORM)
* React JSX
* LINQ (C#)

👉 All are **languages inside languages**

---

# 🔹 Final insight

👉 You are not creating a new language
👉 You are **bending an existing language to speak your domain**

---

# 🔹 One-line takeaway

👉 **Embed your domain language inside a real programming language to get both expressiveness and executability with minimal effort.**
