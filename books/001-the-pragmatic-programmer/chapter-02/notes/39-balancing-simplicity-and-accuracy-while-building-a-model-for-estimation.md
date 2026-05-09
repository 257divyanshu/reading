When building a model for estimation:

* a **simple model**
  → easier/faster to create
  → less accurate

* a **detailed model**
  → harder/slower to create
  → more accurate

So you must balance:

```text id="0n3w7t"
simplicity  ↔  accuracy
```

---

# 🔹 Example

Suppose estimating:

```text id="g8n0f0"
“How long will login system take?”
```

---

## 🔸 Very simple model

```text id="8cr4u0"
Frontend + Backend + DB = 5 days
```

Easy estimate.

But inaccurate.

---

## 🔸 More detailed model

```text id="m6jknw"
JWT auth
+ OAuth
+ password reset
+ email service
+ rate limiting
+ testing
+ deployment
```

Much more accurate.

But takes more effort to analyze.

---

# 🔹 So what are you “trading”?

You are sacrificing:

* simplicity
  to gain:
* accuracy

OR

sacrificing:

* accuracy
  to keep:
* simplicity

---

# 🔹 Key insight

Perfect accuracy usually isn’t worth the massive effort.

So engineers aim for:

```text id="ttmcrq"
“simple enough, but accurate enough”
```

---

# 🔹 One-line meaning

👉 **More detailed models improve estimate accuracy, but make the estimation process more complex and time-consuming.**
