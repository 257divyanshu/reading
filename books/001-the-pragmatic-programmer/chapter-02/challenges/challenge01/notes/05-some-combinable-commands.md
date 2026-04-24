### 1.

```bash
cat file.txt | grep "error"
```

* **Utilities**: `cat` (read file), `grep` (search pattern)
* **What it does**: Shows lines containing “error”

---

### 2.

```bash
cat file.txt | sort | uniq
```

* **Utilities**: `cat` (read), `sort` (order lines), `uniq` (remove duplicates)
* **What it does**: Outputs sorted unique lines

---

### 3.

```bash
cat file.txt | wc -l
```

* **Utilities**: `cat` (read), `wc` (count)
* **What it does**: Counts number of lines

---

### 4.

```bash
grep "error" file.txt | wc -l
```

* **Utilities**: `grep` (filter lines), `wc` (count)
* **What it does**: Counts how many lines contain “error”

---

### 5.

```bash
cat file.txt | cut -d',' -f1
```

* **Utilities**: `cat` (read), `cut` (extract fields)
* **What it does**: Extracts first column (CSV-style)

---

### 6.

```bash
cat file.txt | tr 'a-z' 'A-Z'
```

* **Utilities**: `cat` (read), `tr` (transform characters)
* **What it does**: Converts text to uppercase

---

### 7.

```bash
cat file.txt | grep "error" | sort
```

* **Utilities**: `cat` (read), `grep` (filter), `sort` (order)
* **What it does**: Filters “error” lines and sorts them

---

### 8.

```bash
find . -name "*.log" | xargs grep "error"
```

* **Utilities**: `find` (locate files), `xargs` (pass args), `grep` (search text)
* **What it does**: Searches “error” in all `.log` files

---

### 9.

```bash
cat file.txt | head -n 5
```

* **Utilities**: `cat` (read), `head` (first lines)
* **What it does**: Shows first 5 lines

---

### 10.

```bash
cat file.txt | tee output.txt | wc -l
```

* **Utilities**: `cat` (read), `tee` (duplicate output), `wc` (count)
* **What it does**: Saves content to file and counts lines simultaneously

---

👉 These show the philosophy: **small tools + pipes → powerful workflows**
