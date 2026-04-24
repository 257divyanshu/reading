## 🔹 Built-in Commands

👉 Part of the **shell itself** (bash, zsh, etc.)

**Examples:**

* `cd`
* `echo`
* `pwd`
* `export`

**Key traits:**

* Run **inside the shell**
* Can modify shell state (like current directory, environment variables)
* Faster (no new process created)

---

## 🔹 Command-line Utilities

👉 Separate **external programs**

**Examples:**

* `ls`
* `grep`
* `sort`
* `cat`

**Key traits:**

* Executed as a **new process**
* Cannot directly change shell state
* Located as binaries (e.g., `/bin/ls`)

---

## 🔥 Core Difference

```text
Built-in → part of shell, can change shell state
Utility  → external program, cannot change shell state
```
