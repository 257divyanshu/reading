# ❌ Bad Comments (low-level / redundant)

👉 These just **repeat what code already says**

### Example 1

```cpp
int sum = a + b; // add a and b
```

❌ Problem:

* Comment adds **zero value**
* Code is already clear

---

### Example 2

```cpp
if (user.isLoggedIn()) {
    // check if user is logged in
    showDashboard();
}
```

❌ Problem:

* Completely obvious from code

---

### Example 3

```cpp
i++; // increment i
```

❌ Problem:

* Noise, not documentation

---

# ✅ Good Comments (high-level / intent-based)

👉 These explain **WHY**, not WHAT

---

### Example 1 (Business Logic)

```cpp
// Apply 10% discount for premium users to increase retention
if (user.isPremium()) {
    price *= 0.9;
}
```

✅ Why it's good:

* Explains **reason behind logic**
* Not obvious from code

---

### Example 2 (Non-obvious decision)

```cpp
// Using binary search because dataset is sorted and large (~1M entries)
int idx = binarySearch(arr, target);
```

✅ Why it's good:

* Explains **design choice**

---

### Example 3 (Edge case / constraint)

```cpp
// API returns null instead of empty list for legacy reasons
if (response == null) {
    return {};
}
```

✅ Why it's good:

* Explains **weird behavior**
* Future dev won't “fix” it incorrectly

---

### Example 4 (Hack / workaround)

```cpp
// Temporary fix: retry due to intermittent timeout from payment gateway
retryPayment();
```

✅ Why it's good:

* Explains **non-ideal code**
* Prevents confusion later

---

### Example 5 (Complex logic explanation)

```cpp
// We maintain two pointers to track overlapping intervals efficiently (O(n))
while (i < n && j < m) {
    ...
}
```

✅ Why it's good:

* Explains **approach**, not syntax

---

# 🔥 Side-by-side contrast

### ❌ Bad

```cpp
// loop through array
for (int i = 0; i < n; i++) {
```

### ✅ Good

```cpp
// Iterate once to compute prefix sums for O(n) solution
for (int i = 0; i < n; i++) {
```

---

# 🧠 Key Rule (remember this)

👉 **Code = WHAT is happening**
👉 **Comments = WHY it’s happening**

---

# ⚠️ Why bad comments are dangerous (DRY connection)

If you write:

```cpp
// multiply by 0.9
price *= 0.9;
```

Later change:

```cpp
price *= 0.8;
```

But forget to update comment → ❌ **duplication bug**

---

# 🧾 One-line note for you:

**Good comments explain intent/why; bad comments repeat the code and become stale.**
