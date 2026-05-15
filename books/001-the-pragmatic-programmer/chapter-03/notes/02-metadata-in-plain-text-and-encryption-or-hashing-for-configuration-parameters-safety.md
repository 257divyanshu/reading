# Paragraph 2

Authors say plain text drawbacks may be unacceptable in some applications.

Examples:

* satellite telemetry data
* relational database internal storage

---

## Why satellite telemetry?

Satellite sends massive streams of sensor data.

Example:

```text
temperature
position
velocity
battery status
radiation readings
...
```

every second (or faster).

If stored as plain text:

```text
temperature=27.34
velocity=18234.89
battery=84
```

this becomes:

* larger in size
* slower to parse

Binary representation:

```text
4 bytes float
8 bytes double
1 byte integer
```

much smaller + faster.

Critical because:

* limited bandwidth
* limited storage
* performance-sensitive

---

## Why relational database internals?

Databases process huge amounts of data.

Suppose 10 million rows.

If every integer stored as text:

```text
"123456"
```

instead of raw binary integer.

Problems:

* wastes storage
* slower comparisons
* slower indexing
* slower querying

So DB internals use optimized binary formats.

---

## Main point

Sometimes plain text is simply too inefficient.

---

# Paragraph 3

Authors say:

Even then, storing **metadata** in plain text may still help.

---

## What is metadata?

Metadata = **data about data**

Example:

Raw binary image:

```text
[random bytes]
```

Metadata:

```json
{
  "format": "PNG",
  "width": 1920,
  "height": 1080
}
```

---

Another example:

Database raw storage = binary.

Metadata in plain text:

```yaml
users:
  id: integer
  email: string
  created_at: datetime
```

---

Why?

Because metadata helps humans understand the binary data.

So:

```text
actual payload → binary
description/info → plain text
```

Best of both worlds.

---

# Paragraph 4

This is about **security misconception**.

Some developers think:

```text
"If users can't read binary files, data is secure."
```

Authors say:

**Wrong.**

---

Binary ≠ secure

Because obscurity is not security.

Example:

You store password in binary:

```text
01101010100101...
```

An attacker can still decode it.

Binary only makes it less obvious.

Not protected.

---

## Password example

Wrong:

```text
password stored in binary file
```

Right:

```text
password encrypted / hashed
```

Because actual cryptography protects data.

---

## Config tampering example

Suppose config file:

```text
max_users=100
premium=true
```

User may edit it.

Binary format only makes editing harder, not impossible.

Proper solution:

Integrity verification.

Example:

```text
config values + secure hash
```

App checks:

```text
Does current config hash match stored hash?
```

If not:

```text
File was modified.
```

---

## What is checksum here?

A checksum is a fingerprint of file contents.

Example:

```text
Original config → hash ABC123
```

User edits:

```text
max_users=999999
```

New hash:

```text
XYZ789
```

Mismatch detected.

---

# Final takeaway

Authors are saying:

* performance may require binary
* metadata can still be plain text
* binary is NOT security
* use encryption/hashing for actual protection
