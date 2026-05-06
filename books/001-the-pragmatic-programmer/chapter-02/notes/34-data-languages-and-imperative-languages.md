# 🔹 Big Picture of this subtopic

The authors are saying:

👉 Mini-languages can be of **two kinds**:

1. **Data Languages**
   → describe data/configuration

2. **Imperative Languages**
   → describe actions/behavior/procedures

---

# 🔷 PART 1 — Data Languages

---

## 🔹 “Data languages produce some form of data structure…”

👉 These languages don’t *execute logic*

👉 They mainly define:

* configuration
* structure
* metadata

---

## 🔹 Example: JSON

```json id="z5zw69"
{
  "port": 8080,
  "debug": true
}
```

👉 This is not “running” anything

👉 It just describes data

---

# 🔹 sendmail example

Authors show a terrible-looking config syntax:

```text
Mlocal, P=/usr/bin/procmail, ...
```

👉 This is a **data language**

It configures:

* email routing
* protocols
* handlers

---

## 🔹 Key point

👉 The language defines:

* WHAT exists
* HOW system should be configured

NOT:

* procedural steps

---

# 🔹 Windows `.rc` example

This:

```text
MAIN_MENU MENU
{
   POPUP "&File"
}
```

defines:

* menus
* buttons
* dialogs

👉 Again:

* not executable behavior
* just UI structure/configuration

---

## 🔹 Important line

> “compiled to generate a data structure”

Meaning:

👉 These files get transformed into internal structures used by application

---

# 🔷 PART 2 — Imperative Languages

Now authors move to something stronger.

---

## 🔹 “Imperative languages take this a step further”

👉 Now language can:

* execute instructions
* make decisions
* control flow

---

## 🔹 Example

```python
if balance < 0:
    reject()
else:
    store()
```

👉 This is procedural behavior

---

# 🔹 The screen scraping example

This is the most important part.

---

## 🔹 Problem

Suppose:

* company has old mainframe software
* no API exists
* but you must integrate it into modern GUI app

---

## 🔹 Solution: Screen scraping

Your app:

* pretends to be a human
* types keystrokes
* reads screen text

---

## 🔹 Example script

```text
locate prompt "SSN:"
type "%s" social_security_number
type enter
```

---

## 🔹 What this means

👉 Find SSN field
👉 Type SSN
👉 Press Enter

---

# 🔹 Why use mini-language here?

Because this:

```text
locate prompt "SSN:"
```

is FAR easier than low-level C code like:

```cpp
sendKeyboardEvent(...)
waitForScreen(...)
readTerminalBuffer(...)
```

---

# 🔹 Key insight

👉 Maintenance programmers can edit scripts without touching core code

---

# 🔹 Important line

> “programming in the maintenance programmer’s domain”

Meaning:

👉 Write automation in language natural for maintainers

Not:

* low-level system code

---

# 🔹 Final example

Suppose mainframe UI changes:

OLD:

```text
SSN:
```

NEW:

```text
SOCIAL SECURITY NUMBER:
```

---

Without mini-language:

* modify/recompile C program

With mini-language:

```text
locate prompt "SOCIAL SECURITY NUMBER:"
```

👉 tiny script update only

---

# 🔷 Final distinction

| Type                | Purpose                   | Example                |
| ------------------- | ------------------------- | ---------------------- |
| Data language       | Describe structure/config | JSON, XML, `.rc`       |
| Imperative language | Describe behavior/actions | scripts, workflow DSLs |

---

# 🔹 Main lesson of the subtopic

👉 Use domain-specific mini-languages to:

* simplify maintenance
* separate rules from code
* express problems at higher abstraction levels

---

# 🔹 One-line takeaway

👉 **Data languages describe system structure/configuration, while imperative languages describe executable behavior and workflows.**
