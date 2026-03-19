Page 99
"You can parse a human readable file with only partial knowledge of its format; with most binary files, you must know all the details of the entire format in order to parse it successfully."

This sentence highlights the fundamental difference between how computers read **plain text** versus **binary data**. 

In short: **Binary files require an exact map to read, otherwise they are just gibberish.**

Here is the breakdown:

* **Plain Text (e.g., JSON, CSV, XML):** These are human-readable. If you open a text file looking for a user's email, you can easily scan the document, find the word "email," and grab it. You can completely ignore the rest of the file without knowing how it works.
* **Binary Files (e.g., custom compiled data, executable files):** Binary files are continuous, compressed streams of raw bytes (1s and 0s). There are no spaces or labels. To extract that same email address, your code *must* know the exact "map" of the file (e.g., "The first 4 bytes are the ID, the next 8 are the date, and the email starts exactly at byte 13"). 

If you don't know the exact rules for the *entire* binary format, you won't know where one piece of data ends and the next begins, making it impossible to parse correctly.