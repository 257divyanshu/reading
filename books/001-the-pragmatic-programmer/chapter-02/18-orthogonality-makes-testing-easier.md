# 🔹 1) “interactions between the system’s components are formalized and limited”

## 👉 Meaning

In an orthogonal system:

* modules talk via **clear, well-defined interfaces**
* not random/internal access

---

## ❌ Non-orthogonal

```js
// module A directly accesses internals of B
b.internalData.value = 10;
```

👉 Interaction is:

* informal
* uncontrolled

---

## ✅ Orthogonal

```js
b.setValue(10);
```

👉 Interaction is:

* formal (via method)
* limited (only allowed operations)

---

## 🔥 Why this helps testing

👉 You can test module B by just calling:

```js
b.setValue(10);
```

👉 No need to understand entire system

---

# 🔹 2) Unit Testing vs Integration Testing

## 🔸 Unit Testing

👉 Test **one module in isolation**

```js
function add(a, b) {
  return a + b;
}
```

Test:

```js
assert(add(2, 3) === 5);
```

✔️ Simple
✔️ Fast
✔️ Easy to debug

---

## 🔸 Integration Testing

👉 Test how modules work together

```js
orderService.placeOrder()
// uses:
// → paymentService
// → inventoryService
```

Test:

```js
placeOrder(order);
// verify payment + inventory + DB
```

---

## 🔥 Key Difference

```text
Unit test        → single module
Integration test → multiple modules interaction
```

👉 Integration tests are:

* harder
* slower
* more complex

---

## 🔥 Why orthogonality helps

👉 If modules are independent:

```text
More testing = unit level
Less testing = integration level
```

➡️ Easier overall

---

# 🔹 3) “we suggest every module have its own unit test…”

## 👉 Meaning

Each module should come with:

* its own tests
* testing its behavior

---

## Example

```js
// user.js
function isAdult(age) {
  return age >= 18;
}
```

```js
// user.test.js
assert(isAdult(20) === true);
assert(isAdult(15) === false);
```

👉 Every module = self-tested

---

# 🔹 4) “unit test built into its code”

## 👉 Meaning

Not literally inside the function, but:

👉 Tests should be:

* written alongside the module
* maintained with it
* run automatically

---

## 🔥 Example structure

```text
user/
  user.js
  user.test.js
```

---

## 🔥 Even better (conceptually “built-in”)

Some systems embed tests:

```js
function isAdult(age) {
  return age >= 18;
}

// quick self-check
if (process.env.TEST) {
  console.assert(isAdult(18) === true);
}
```

---

# 🔹 5) “performed automatically as part of build process”

👉 Means:

Whenever you:

* build
* deploy
* push code

👉 tests run automatically

---

## Example (CI/CD)

```bash
npm test
```

or in pipeline:

```text
Build → Run tests → Deploy
```

---

## 🔥 Why this matters

👉 Prevents:

* broken code from shipping
* regressions

---

# 🧠 Final Understanding

Orthogonality → modules are independent

⬇️

Independent modules → easy unit testing

⬇️

More unit testing, less integration chaos

---

# 🧾 One-line note

**Orthogonal systems enable isolated unit testing by enforcing clear, limited interactions between modules, reducing reliance on complex integration testing.**