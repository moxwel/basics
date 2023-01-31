---
description: You will see this notation in many places.
---

# Command notations

When reading command documentation, you will see notations representing various conditions. Not every command must be copy-pasted, some needs to change values depending on what do you want.

## `>>> Input` <a href="#input" id="input"></a>

In some interactive shells, you will have this symbol (`>>>`) at the start of your cursor, it means the software is waiting for user input. In documentation, it means something you should write.

```python
>>> print("Hello world")    # This is an input
Hello world                 # This is an output
```

It can also be like `>` or `$`.

## `<Placeholder>` <a href="#placeholder" id="placeholder"></a>

Represents a value for which **you must supply a value**.

For example:

```
python my_script.py <file>
```

You need to fill the place where `<file>` is with your own value.

{% code title="Example" %}
```
python my_script.py my_file.txt
```
{% endcode %}

## `[Optional]` <a href="#optional" id="optional"></a>

Represents a value for which **you can supply a value or leave empty**.

For example:

```
python my_script.py [file]
```

It's not necessary to put something in `[file]`.

{% code title="Example" %}
```
python my_script.py my_file.txt
python my_script.py
```
{% endcode %}

## `{Mutually|Exclusive|Values}` <a href="#mutually-exclusive-items" id="mutually-exclusive-items"></a>

Represents a placeholder for which you must select one item of that list.

For example:

```
command {value1|value2|value3}
```

You should select only one value in that placeholder.

{% code title="Example" %}
```
command value1
command value2
command value3
```
{% endcode %}

## `--option` <a href="#option" id="option"></a>

Some commands let you add options (or flags) to change behavior. It can be with 1 dash (`-`) or 2 (`--`). Every command has their own way.

The `--help` or `-h` flag is very common in almost all commands. It shows information about the usage of a command. Use it everywhere you can.

```
python --help
```
