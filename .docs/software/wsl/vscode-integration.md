# VSCode Integration

Visual Studio Code has an extension that enables integration with WSL.

Install the WSL extension for Visual Studio Code:

<figure><img src="../../.gitbook/assets/wsl_vscode.png" alt=""><figcaption><p>WSL extension in Visual Studio Code marketplace</p></figcaption></figure>

{% embed url="https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl" %}
WSL Visual Studio Code extension webpage
{% endembed %}

With this extension, you can open in a "Linux" mode. You can open any folder from Windows and work with it in a Linux environment. And install VSCode extensions in Linux.

It's like VSCode was runing natively on Linux! Everything you do in this mode is inside WSL (open folders, create files, install extensions, modify settings, etc.)

<figure><img src="../../.gitbook/assets/wsl_vscode2.png" alt=""><figcaption><p>Installing extensions in WSL mode in Visual Studio Code</p></figcaption></figure>

Notice the "WSL Ubuntu-20.04 - Installed" and "Local - Installed" groups. The extensions installed on WSL will remain in WSL and not in Windows. Extensions installed on Windows are called "local".

&#x20;<mark style="background-color:green;">**Congratulations!**</mark>**  Now you can use WSL with Visual Studio Code.**
