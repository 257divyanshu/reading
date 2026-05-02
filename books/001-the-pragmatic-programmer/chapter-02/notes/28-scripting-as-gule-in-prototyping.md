## 🔹 Core idea (in one line)

👉 **Use scripting languages as “glue” to quickly connect existing pieces instead of building everything from scratch.**

---

## 🔹 Break it down

### 👉 “Scripting languages work well as the ‘glue’…”

* You already have small components (libraries, tools, APIs)
* Instead of rewriting them, you **connect them together**

👉 Think:

> Python / JS = glue
> C libraries / APIs = building blocks

---

### 👉 “combine low-level pieces into new combinations”

* Low-level = fast, complex code (like C/C++ libraries)
* You don’t rewrite them
* You just **orchestrate them**

---

## 🔹 Example

### Without glue (bad for prototype):

You write everything in C++:

* parsing
* logic
* UI
* networking

👉 slow, heavy

---

### With glue (good for prototype):

```python id="1l3p2k"
import numpy as np  # low-level optimized C lib
import requests     # HTTP lib

data = requests.get("https://api.example.com").json()
result = np.mean(data["values"])

print(result)
```

👉 Python is just **connecting existing pieces**

---

## 🔹 “Visual Basic can glue COM controls”

* Old Windows example
* You could drag-and-drop components and connect them quickly

👉 Same idea:

* reuse components
* connect them fast

---

## 🔹 “Perl and Python bind C libraries…”

* Many powerful libraries are written in C
* Python/Perl can **call them directly**

Example:

```python id="z0c0lq"
import cv2  # OpenCV (written in C/C++)
img = cv2.imread("image.png")
```

👉 You didn’t write image processing
👉 You just used it

---

## 🔹 “SWIG… automatically”

* Tool that helps connect C/C++ code to languages like Python
* So you don’t manually write bindings

👉 Again: faster integration

---

## 🔹 “rapidly assemble existing components…”

This is the KEY POINT.

👉 Instead of:

* designing everything
* implementing everything

You:

* take existing parts
* connect them quickly
* test idea

---

## 🔹 Real-world prototype example

Say you're building:
👉 “Image upload + processing + storage”

Instead of building everything:

```text
Python (glue)
 ├── Flask (web server)
 ├── OpenCV (image processing - C++)
 ├── AWS SDK (storage)
```

👉 You assemble this in hours
👉 Not weeks

---

## 🔹 Why this matters for prototyping

Because prototypes need:

* speed
* flexibility
* experimentation

NOT:

* perfection
* deep low-level control

---

## 🔹 One-line takeaway

👉 **Use high-level scripting languages to quickly glue together powerful existing components and explore ideas fast.**