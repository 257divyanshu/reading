# 🔥 Core Idea

👉 **Documentation should follow orthogonality too**

Meaning:

> **Content (what you say)** and **Presentation (how it looks)** should be independent

---

# 🔹 “The axes are content and presentation”

Think of documentation as having two dimensions:

```text
Content      → actual information (text, meaning)
Presentation → fonts, colors, layout, styling
```

---

# 🔥 What the book is saying

👉 These two should NOT be mixed

---

## ❌ Bad (non-orthogonal documentation)

```html
<h1 style="color:red; font-size:30px;">
  User Login API
</h1>
```

👉 Problems:

* content mixed with styling
* changing style = editing content everywhere ❌

---

## ✅ Good (orthogonal documentation)

```html
<h1 class="title">User Login API</h1>
```

```css
.title {
  color: red;
  font-size: 30px;
}
```

👉 Now:

* content = HTML
* presentation = CSS

➡️ independent

---

# 🔹 “you should be able to change the appearance dramatically…”

👉 Means:

You should be able to do:

```text
Change theme → without touching content
```

---

## Example

Same content:

```text
User Login API
```

### Version 1 (light theme)

```text
Black text on white background
```

### Version 2 (dark theme)

```text
White text on black background
```

👉 Content unchanged
👉 Only presentation changed

---

# 🔥 Real-world example: Markdown

## Your `.md` file

```md
# User Login API
Allows users to log in
```

---

## Different outputs

* GitHub view
* Website
* PDF

👉 Same content
👉 Different looks

➡️ Orthogonality

---

# 🔹 “Modern word processors provide style sheets and macros”

👉 Tools like:

* Word
* Google Docs

let you define:

```text
Heading 1 → font, size, color
```

Then you write:

```text
Apply "Heading 1"
```

👉 If you change style later:

* ALL headings update automatically

➡️ No duplication

---

# 🔥 Without this (bad approach)

```text
Manually set font/size for every heading
```

👉 If you want to change:

* you must edit everything ❌

---

# 🔹 Why this matters (deep insight)

👉 Same principle as DRY + orthogonality:

```text
Content ≠ Presentation
```

---

## If mixed:

```text
Change design → edit everywhere
```

## If separated:

```text
Change design → edit one place
```

---

# 🧠 Final Mental Model

```text
Documentation = system

Content      → logic
Presentation → UI
```

👉 Same idea as:

* MVC
* layered architecture

---

# 🧾 One-line note

**Keep documentation content separate from presentation so you can change appearance without modifying the actual information.**
