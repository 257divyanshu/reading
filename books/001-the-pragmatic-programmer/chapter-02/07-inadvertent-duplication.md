## We define a `Truck` like:

```cpp
class Truck {
    string type;
    string licenseNumber;
    string driver;   // ❌ key point
};
```

➡️ We assume: *truck has a driver*

---

## We define another class:

```cpp
class DeliveryRoute {
    string route;
    Truck truck;
    string driver;   // ❌ duplicated
};
```

➡️ Now `driver` exists in **two places**

---

## Real-world change happens:

* Driver changes

---

## Both Truck and DeliveryRoute contain a driver.

Now you have:

```text
Truck.driver
DeliveryRoute.driver
```

➡️ Same information duplicated

---

## Which one do we change?

🔥 Core problem

If driver changes:

* Update Truck?
* Update DeliveryRoute?
* Both?

➡️ Risk of inconsistency

---

## Clearly this duplication is bad.

Because:

* Easy to forget one place
* Leads to bugs

---

## Key idea: **Fix the design**

Ask:

> What is the *true relationship* in reality?

---

## Think carefully:

Is driver permanently tied to truck?
❌ No — drivers can change

Is driver part of route?
❌ No — routes don’t own drivers either

---

## Create a better model

✅ Correct Design

```cpp
class Driver {
    string name;
};

class Truck {
    string type;
    string licenseNumber;
};

class Route {
    string path;
};

class DeliveryAssignment {
    Driver driver;
    Truck truck;
    Route route;
};
```

👉 Now:

* No duplication
* Driver exists **only once**

---

This new class (`DeliveryAssignment`) represents:

* “who drives what on which route”

➡️ Correct real-world mapping

---

Don’t store same information in multiple places

➡️ Always:

* rethink design
* model reality correctly

---

## Core Insight

👉 Duplication often means:

> ❌ You modeled the problem wrong

---

## Final Mental Model

```text
Bad design → duplicated data → bugs
Good design → single source of truth → clean system
```

---

## One-line note:

**Inadvertent duplication arises from poor modeling—fix the design to ensure each piece of data has a single, correct place.**
