# VSCode Integration

Visual Studio Code has an extension that enables integration with WSL.

Install the WSL extension for Visual Studio Code:

<figure><img src="../../.gitbook/assets/wsl_vscode.png" alt=""><figcaption><p>WSL extension in Visual Studio Code marketplace</p></figcaption></figure>

{% embed url="https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl" %}
WSL Visual Studio Code extension webpage
{% endembed %}

With this, you can open VSCode in "Linux" mode. That means you can open any folder from Windows and work with it in a Linux environment.

It's like VSCode was runing natively on Linux! Everything you do in this mode is inside WSL (open folders, create files, install extensions, modify settings, etc.)

<figure><img src="../../.gitbook/assets/wsl_vscode2.png" alt=""><figcaption><p>Installing extensions in WSL mode in Visual Studio Code</p></figcaption></figure>

Notice the _**"WSL Ubuntu-20.04 - Installed"**_ and _**"Local - Installed"**_ groups. The extensions installed on WSL will remain in WSL and not in Windows. Extensions installed on Windows are called "local".

You can open a folder from WSL directly in VSCode using the command:

```
code .
```

{% hint style="info" %}
Don't forget the final dot.
{% endhint %}

<figure><img src="../../.gitbook/assets/wsl_img4.png" alt=""><figcaption><p>Opening a folder from WSL directly into Visual Studio Code</p></figcaption></figure>

&#x20;<mark style="background-color:green;">**👏 Congratulations!**</mark>**  Now you can use Visual Studio Code inside WSL.**

{% hint style="success" %}
You can stop here if you want.
{% endhint %}

{% hint style="warning" %}
Now some advanced topics are coming...
{% endhint %}
