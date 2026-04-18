# 🔥 Goal of the design

👉 We want:

* App code **NOT tied to Stripe (or any vendor)**
* Only one place in code knows about the vendor

---

# 🧱 Step 1: Create your own interface (abstraction)

```js
// paymentService.js
class PaymentService {
  pay(amount) {
    throw new Error("Not implemented");
  }
}
```

### 👉 What this does:

* Defines a **contract**
* Says: “Any payment system must implement `pay(amount)`”

➡️ This is YOUR layer (not Stripe’s)

---

# 🧱 Step 2: Implement Stripe version

```js
// stripeService.js
import Stripe from "stripe";

class StripeService extends PaymentService {
  constructor() {
    super();
    this.stripe = new Stripe("API_KEY");
  }

  pay(amount) {
    return this.stripe.charges.create({
      amount,
      currency: "usd",
    });
  }
}
```

### 👉 What this does:

* Connects your interface → Stripe
* Only this file knows about Stripe

➡️ Stripe is **isolated here**

---

# 🧱 Step 3: Use it in your app

```js
// app.js
const paymentService = new StripeService();

paymentService.pay(1000);
```

### 👉 Important point:

* App calls `pay()`
* App does NOT know:

  * Stripe exists
  * API details
  * how payment works internally

➡️ App depends on **your interface**, not vendor

---

# 🔄 Step 4: Switch vendor (key benefit)

Now you want Razorpay instead of Stripe.

---

## New implementation

```js
// razorpayService.js
class RazorpayService extends PaymentService {
  pay(amount) {
    return razorpay.pay(amount);
  }
}
```

---

## Only change in app:

```js
const paymentService = new RazorpayService();
```

---

# 🔥 What DIDN’T change

```js
paymentService.pay(1000);
```

👉 This stays SAME everywhere in your app

---

# 🔥 Why this is powerful

Without this design:

```js
stripe.charges.create(...)  // scattered everywhere ❌
```

With this design:

```js
paymentService.pay(...)     // single abstraction ✅
```

---

# 🧠 Mental Model

```text
App Code
   ↓
Your Interface (PaymentService)
   ↓
Vendor Implementation (Stripe / Razorpay)
```

---

# 🔥 Key takeaway

👉 You separated:

* **WHAT** your app needs → `pay(amount)`
* **HOW** it happens → Stripe / Razorpay

---

# 🧾 One-line note for you:

**Create your own abstraction layer so your app depends on your interface, not external vendors.**
