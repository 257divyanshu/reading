You understood the first paragraph, so let’s focus on the **second paragraph + its example**.

---

# 🔹 Main idea of second paragraph

Authors are saying:

After identifying important parameters:

```text
request arrival rate
processing time
network latency
DB response time
```

don’t just guess randomly.

Use **real evidence** wherever possible.

---

# 🔹 The “queuing example” — what are they talking about?

Earlier they mentioned modeling systems where requests arrive and wait to be processed.

Like:

```text
Users sending requests → server queue → server processes → response
```

This is a **queueing system**.

Example:

* API server
* print queue
* ATM queue
* ticket booking server

---

# 🔹 Suppose you're estimating a new API server

Your model might need:

```text
requests per second
average processing time
network delay
```

Now authors ask:

How will you get these values?

---

# 🔸 Example 1: Measure existing system

Suppose your current production system handles login requests.

Measure:

```text
actual request arrival rate = 120 requests/second
```

instead of guessing:

```text
maybe 500 requests/sec?
```

---

Another measurement:

Measure:

```text
average request processing = 80ms
```

instead of inventing:

```text
maybe 20ms?
```

---

# 🔸 Example 2: Measure similar system

Suppose your system doesn’t exist yet.

Then find a comparable one.

Example:

You’re building:

* food delivery backend

You inspect:

* existing ecommerce backend

Measure:

```text
checkout request latency
DB query times
```

Use that as approximation.

---

# 🔹 “estimate based on other subestimates”

This is the tricky part.

Suppose:

To estimate:

```text
Total response time
```

you need:

```text
DB query time
```

But DB doesn’t exist yet.

So now you estimate DB time.

That estimate itself depends on:

```text
number of rows
index efficiency
network speed
```

Those are estimates too.

So:

```text
Final estimate
depends on
smaller estimates
```

This is estimate-on-estimate stacking.

---

# 🔹 Why largest errors creep in here

Because uncertainty compounds.

Example:

You assume:

```text
DB = 50ms
network = 20ms
processing = 30ms
```

Total:

```text
100ms
```

But actual:

```text
DB = 150ms
```

Now total becomes:

```text
200ms
```

Huge error.

---

# 🔹 Final meaning of second paragraph

Authors are warning:

👉 Critical parameters should be measured or justified.

Because bad assumptions in lower-level estimates create huge final estimation errors.

---

# 🔹 One-line summary

**Use real measurements (or comparable systems) for important parameters, because estimates built on other shaky estimates can amplify errors badly.**
