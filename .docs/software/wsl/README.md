---
description: Welcome to the Windows Subsystem for Linux tutorial!
---

# 🐧 WSL

Here, you will learn how to install and configure WSL in your PC.

{% embed url="https://learn.microsoft.com/en-us/windows/wsl/install" %}
WSL installation documentation
{% endembed %}

## About

The **Windows Subsystem for Linux** (WSL) is a tool for running GNU/Linux environments on Windows. It works like a VM[^1] but more integrated. That means the system under WSL is NOT isolated from Windows: you can access all files from WSL, and from WSL you can access all files from Windows.

Inside WSL, you have all your Linux software, including command-line tools, applications, servers, etc. If you never used a Linux based OS before (like [Ubuntu](https://ubuntu.com/download/desktop)), you will need to learn that first.

In the beginning, the only thing you have to interact with your Linux environment is the terminal, nothing of graphical interfaces and things like that.

## Why use WSL?

Most people have one PC and use Windows as their primary OS, and most developers prefer using Linux for development, but generally also want to use Windows in the same machine (either because they need to use software only compatible with Windows, or gaming, etc.), so they dual-boot[^2] or virtualize.

Dual-boot is a great solution, but if you want to change OS, you need to restart the whole computer to do so. Also, you can't use the two OS at the same time. What an inconvenience.

Using Virtual Machines solves the "have to restart to change" and "two OS at the same time" problems, but the nature of Virtual Machines in itself is an inconvenience, mainly because they are so resource-heavy to run (you are running **two entire** OS's in one CPU[^3])

WSL it's kind of a Virtual Machine, but very lightweight compared to traditional VMs so you don't need to worry about getting out of resources, it only runs the main kernel[^4] of Linux, and on top of that the distro[^5] you want to use.

## Let's start!

| 💭 What you will need?                              | 💡 What you will learn?                    |
| --------------------------------------------------- | ------------------------------------------ |
| Basic understanding of Linux environments.          | Install, configure and use WSL in Windows. |
| Basic understanding of Linux commands (like `apt`). | Integrate WSL with Visual Studio Code.     |
| Basic usage of "shells" (like `bash`).              | Install Linux software on WSL.             |
| Know to use terminal-only applications.             |                                            |

[^1]: Virtual Machine

    [\[ Wikipedia \]](https://en.wikipedia.org/wiki/Virtual\_machine)

[^2]: Have two or more OS in the same computer.

    [\[ Article \]](https://www.howtogeek.com/187789/dual-booting-explained-how-you-can-have-multiple-operating-systems-on-your-computer/)

[^3]: Central Processing Unit

    [\[ Wikipedia \]](https://en.wikipedia.org/wiki/Central\_processing\_unit)

[^4]: The "core" program of any Operating System.

    [\[ Wikipedia \]](https://en.wikipedia.org/wiki/Kernel\_\(operating\_system\))

[^5]: Linux distribution.

    An Operating System including the Linux kernel (e.g., Ubuntu)

    [\[ Wikipedia \]](https://en.wikipedia.org/wiki/Linux\_distribution)
