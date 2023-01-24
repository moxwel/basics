---
description: You will see this notation in many places.
---

# Command notations

When reading command documentation, you will see notations representing various conditions. Not every command must be copy-pasted, some needs to change values depending of what do you want.

## `>>> Input`

In some interactive shells, you will have this symbol (`>>>`) at the start of your cursor, it means the software is waiting for user input. In documentation, it means something you should write.

```python
>>> print("Hello world")    # This is an input
Hello world                 # This is an output
```

It can also be like `>` or `$`.

## `<Placeholder>`

Represents a value for which you must supply a value.

For example:

```
python my_script.py <file>
```

You need to fill the place where `<file>` is with your own value.

```
python my_script.py my_file.txt
```

## `[Optional]`

Represents a value for which you can supply a value or leave empty.

For example:

```
python my_script.py [file]
```

It's not necesary to put something in `[file]`.

```
python my_script.py my_file.txt
python my_script.py
```

## `Mutually|Exclusive|Items`

A list where you must choose one value to put in the placeholder.

For example:

```
command <value1|value2>
```

You should select only one value in that placeholder.

```
command value1
command value2
```

## `--option`

Some commands let you add options (or flags) to change behavior. It can be with 1 dash (`-`) or 2 (`--`). Every command have their own way.

The `--help` or `-h` flag is very common in almost all commands. It shows information about the usage of a command. Use it everywhere you can.

```
python --help
```
