<h3 align="center">C++ Text Editor</h3>

---

<p align="center"> Project that reads a txt file and transform it into a doubly linked list using the laboratory implementation.Using only one list, each node in the list will store a character (List of characters that will represent the text).
<br>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Built Using](#built_using)
- [Authors](#authors)

## 🧐 About <a name = "about"></a>

This is a project that turns a text file into a doubly linked list. You can then read it in a doubly linked list format, count how many times a word appears, and swap any word you like to the one of your preference. In the end, it lets you save your changes into your previoulsy loaded file.

## 🏁 Getting Started <a name = "getting_started"></a>

If you're using linux, I suggest you to create a makefile so you can compile all the files and run main.cpp. I used this template:

```
all:
	g++ main.cpp Node.cpp LinkedList.cpp -o LinkedList && ./LinkedList
```

In your terminal, you just need to run it using the <b>make</b> command.

## 🎈 Usage <a name="usage"></a>

When you first run main, a menu will pop up at your terminal, letting you do 4 things:

1. <b>Count Word</b>: Given a chosen word, it'll show you the number of ocurrences of it in the text.
2. <b>Change Word</b>: Given a chosen word to be changed and a word that will be the new one, it'll change everty ocurrence of that word into the new one you've written.
3. <b>Print</b>: It'll print all the text in the doubly linked list format, e.g. given a sentence "I like to smile.", the same would appear in a doubly linked list format as:

```
        [I, , l, i, k, e, , t, o, , s, m, i, l, e, .]
```

4. <b>Save</b>: Everything you changed on your linked list will be transferred to your text file back to the normal format.

## ⛏️ Built Using <a name = "built_using"></a>

- [C++](https://www.cplusplus.com/)

## ✍️ Authors <a name = "authors"></a>

- Amanda Massari 🦊
- Vitor Navarro 🦕
