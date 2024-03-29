# WSL1 and WSL2

{% hint style="warning" %}
**This topic is: ** <mark style="background-color:red;">**advanced**</mark>&#x20;

If you know how to use Linux and you are comfortable using it, you can do this.
{% endhint %}

{% embed url="https://learn.microsoft.com/en-us/windows/wsl/compare-versions" %}
Microsoft documentation about WSL1 and WSL2
{% endembed %}

When WSL was introduced, the virtualization technology was different.

WSL1 was more "integrated" in Windows, just like running a trimmed version of the Linux kernel alongside Windows. This improves performance but has its limitations regarding Linux kernel usage.

WSL2 is the new version more "virtualized" than WSL1, it means it runs inside a virtual machine. This allowed to run the entire Linux kernel without problems, keeping the integration with Windows.

<figure><img src="../../.gitbook/assets/wsl_comp.png" alt=""><figcaption><p>WSL1 (left) and WSL2 (right) inside Task Manager</p></figcaption></figure>

<figure><img src="../../.gitbook/assets/wsl_chart.png" alt=""><figcaption><p>WSL1 and WSL2 comparation chart from Microsoft documentation</p></figcaption></figure>

TL;DR: the new version of WSL2 replicates the "true Linux" kernel, and with that, many internal things work "as it should be", but at the cost of performance.

## Check version

You can check what version of WSL are you using with your distro.

* To view the WSL version of your distros, run this command in **Powershell**:

```
wsl --list --verbose
```

* To view default distro and WSL version for new distros:

```
wsl --status
```

* Set default WSL version for new distros:

```
wsl --set-default-version {1|2}
```

* Set version 2 for specific distribution:

```
wsl --set-version <distro> {1|2}
```

{% code title="Example" %}
```
wsl --set-version Ubuntu-20.04 2
```
{% endcode %}

{% hint style="info" %}
This guide will continue using **WSL 2**.
{% endhint %}

## Systemd

{% embed url="https://devblogs.microsoft.com/commandline/systemd-support-is-now-available-in-wsl/" %}
Microsoft Developer Blog about Systemd on WSL
{% endembed %}

> Systemd is a suite of basic building blocks for a Linux system. It provides a system and service manager that runs as PID 1 and starts the rest of the system.

WSL2 can run Systemd, this means software that depends on that service will work, and the experience on WSL will be closer to "using a bare metal Linux machine".

To check if you are using Systemd or not, run this command:

```
ps -p 1 -o comm=
```

To enable Systemd on WSL2, you need to edit `/etc/wsl.conf`. I recommend using [micro ](https://micro-editor.github.io/)as text editor (you need 'sudo' for this).

```
sudo micro /etc/wsl.conf
```

In that file, you must put this:

{% code title="File: /etc/wsl.conf" %}
```
[boot]
systemd=true
```
{% endcode %}

Save it and now restart WSL using `wsl --shutdown`. Now your distro will be using Systemd.
