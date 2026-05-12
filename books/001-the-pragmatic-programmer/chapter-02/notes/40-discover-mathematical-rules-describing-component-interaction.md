# 🔷 Main idea of this subtopic

After building a rough system model:

👉 **break it into smaller parts that can be estimated separately.**

Instead of estimating the giant thing as one blob.

---

# 🔹 Paragraph 1 — Decompose into components

Authors say:

> Once you have a model, decompose it into components.

Meaning:

Suppose your system model is:

```text
User → API Server → Database → Response
```

Don’t estimate:

```text
Whole system response time = ???
```

Instead break it into:

* request travel time
* API processing time
* DB query time
* response serialization time
* network return time

---

Why?

Because smaller pieces are easier to reason about.

---

# 🔹 “discover mathematical rules that describe how these components interact”

This means:

After breaking into parts, determine **how their contributions combine**.

---

Example:

If:

```text
API processing = 50ms
DB query = 120ms
Serialization = 20ms
```

Total:

```text
50 + 120 + 20 = 190ms
```

Simple addition.

---

But sometimes interaction is different.

Example:

If cache improves speed by 80%:

```text
DB_time × 0.2
```

That’s multiplication.

---

So authors mean:

👉 Understand the formula connecting parts.

---

# 🔹 “Some component contributes a single value”

Example:

Fixed network latency:

```text
40ms
```

Just added directly.

---

# 🔹 “Some supply multiplying factors”

Example:

Traffic load effect:

```text
processing_time × concurrent_users_factor
```

Suppose:

```text
base = 100ms
users factor = 3
```

Then:

```text
300ms
```

---

# 🔹 “Some are more complicated”

Example:

Traffic arrival simulation.

Requests don’t arrive neatly:

Bad assumption:

```text
1 request every second
```

Reality:

```text
20 requests suddenly
then none
then 50
```

That behavior may need more sophisticated modeling.

---

# 🔹 Paragraph 2 — Identify parameters

Authors say:

Each component has variables that affect it.

These are **parameters**.

---

Example: DB query time depends on:

* number of rows
* indexing
* network latency
* DB server power

These are parameters.

---

Example: API processing depends on:

* request size
* business logic complexity
* CPU speed

---

At this stage:

DON’T calculate everything yet.

Just list:

```text
DB query depends on:
- rows
- indexes
- latency
```

---

# 🔹 Real software estimation example

Estimate login request time:

Break into components:

```text
1. Network request
2. Authentication logic
3. DB lookup
4. Password hash verification
5. Token generation
6. Response send
```

Parameters:

```text
DB lookup → table size
Hash verify → algorithm cost
Network → latency
```

---

# 🔹 Big takeaway

This is basically:

```text
Big unknown
→ split into smaller known-ish parts
→ identify variables affecting each
```

---

# 🔹 One-line summary

👉 **Break a complex estimate into smaller components, understand how their effects combine, and identify the variables that influence each component.**
