# Install

Installing WSL is very easy!

* To install WSL, run this command:

```
wsl --install
```

Doing so will install WSL and do every configuration needed. Sit back and relax.

{% hint style="info" %}
This command will install WSL from [**Microsoft Store**](https://apps.microsoft.com/store/detail/windows-subsystem-for-linux/9P9TQF7MRM4R) and the [**latest Ubuntu version**](https://apps.microsoft.com/store/detail/ubuntu/9PDXGNCFSCZV?hl=en-us\&gl=us).
{% endhint %}

## Install WSL with other distribution

If you want to install WSL with other distribution than Ubuntu, you can do that.

* To view a **list of available distros**, run this command:

```
wsl --list --online
```

Look at the "NAME" column, you will need that.

* To install WSL with a **different distribution**, run this command:

```
wsl --install -d <distro>
```

Where `<distro>` is the name of the distribution that appears in the "NAME" column in the list before.

For example, if you want to install Ubuntu 20.04, you will have to run this command:

```
> wsl --list --online

NAME               FRIENDLY NAME
Ubuntu             Ubuntu
Debian             Debian GNU/Linux
kali-linux         Kali Linux Rolling
SLES-12            SUSE Linux Enterprise Server v12
SLES-15            SUSE Linux Enterprise Server v15
Ubuntu-18.04       Ubuntu 18.04 LTS
Ubuntu-20.04       Ubuntu 20.04 LTS
OracleLinux_8_5    Oracle Linux 8.5
OracleLinux_7_9    Oracle Linux 7.9

> wsl --install -d Ubuntu-20.04
```

{% hint style="info" %}
This guide will continue using **Ubuntu 20.04**.
{% endhint %}

&#x20;<mark style="background-color:green;">**Congratulations!**</mark>**  You just installed Ubuntu in WSL.**
