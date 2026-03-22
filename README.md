# PIOTest Exmaple

# System Setup

* Update WSL: `wsl --update`
* Install: vscode, podman desktop, usbipd-win

# Create Project

* Create the local directory
* Add Containerfile & devcontainer.json from https://github.com/prenone/platformio-vscode-devcontainer
* Open VS Code
* F1 -> open in devcontainer
* Install platformio extension
* F1 -> platformio terminal -> `pio project init --board featheresp32` assuming you're using https://docs.platformio.org/en/latest/boards/espressif32/featheresp32.html

# Write Code

* Add "monitor_speed = 115200" to platformio.ini
* Create src/main.cpp

# Upload & Monitor

* Run `wsl` -> `sudo dnf install usbutils`
* https://learn.microsoft.com/en-us/windows/wsl/connect-usb
  * `powershell` -> `usbipd list`
  * `powershell` -> `usbipd attach --wsl --busid <BUSID>`
* Run `wsl` -> `sudo chmod 666 /dev/ttyUSB*`
* In PlatformIO in VSCode select "Upload and monitor" and you should see "Hello, World!" in the temrinal
