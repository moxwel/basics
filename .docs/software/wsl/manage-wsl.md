# Manage WSL

{% hint style="warning" %}
**This topic is:  **_<mark style="background-color:orange;">****</mark>_<mark style="background-color:orange;">** **</mark><mark style="background-color:orange;">**intermediate**</mark>&#x20;

I recommend you to first familiarize yourself with everything before.
{% endhint %}

Here's a list of the most common used commands to manage WSL. You must run these commands in **Powershell**.

## View a list of commands

```
wsl --help
```

## Install a distro

```
wsl --install <distro>
```

{% code title="Example" %}
```
wsl --install kali-linux
```
{% endcode %}

## View a list of distros installed in WSL

```
wsl --list
```

## Set the default distribution to use

```
wsl --set-default <distro>
```

{% hint style="info" %}
When you use the command `wsl` alone, it will run the selected default distro in the current directory.
{% endhint %}

## Run a specific distro

```
wsl --distribution <distro>
```

## Run a distro in specific directory

```
wsl --cd <directory>
```

{% code title="Example" %}
```
wsl --cd "/"
wsl --cd "~"
wsl --cd "C:\Users\Bob"
```
{% endcode %}

## Finalize all running distros and close WSL

```
wsl --shutdown
```

## Export a WSL distro (backup)

```
wsl --export <distro> <filename>
```

Where `<distro>` is the name of the distribution you want to export, and `<filename>` the address where the `.tar` file will be exported.

{% code title="Example" %}
```
wsl --export Ubuntu-20.04 UbuntuBackup.tar
```
{% endcode %}

{% hint style="success" %}
You can create backups of your distros with this.
{% endhint %}

## Import a WSL distro

```
wsl --import <distro> <install_location> <filename>
```

Where `<distro>` is the name of the distribution (it can be anything), `<install_location>` is the address where the filesystem will be installed, and `<filename>` is the address where the exported `.tar` file is located.

{% code title="Example" %}
```
wsl --import MyUbuntu "C:\WSL\Ubuntu" UbuntuBackup.tar
```
{% endcode %}

## Delete a WSL distro

```
wsl --unregister <distro>
```

{% code title="Example" %}
```
wsl --unregister Ubuntu-20.04
```
{% endcode %}

{% hint style="danger" %}
**THIS WILL REMOVE EVERYTHING INSIDE THAT DISTRO!**

And it's not recoverable. Make sure to backup!
{% endhint %}
