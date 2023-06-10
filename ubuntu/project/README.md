# YouTube Shorts Blocker

A simple browser extension to block YouTube Shorts videos on the YouTube website.

## Installation

1. Download the extension from the  link : https://github.com/Dxuian/crex.git.
2. Open your browser and navigate to the extension settings.
3. Drag and drop the downloaded file into the extension settings page.
4. Click "Add" or "Install" to add the extension to your browser.
5. A video on how to use the extension: https://youtu.be/M5gWiMUNkw0

## Usage

Once installed, the extension will can block YouTube Shorts videos on the YouTube and on other websites. To enable or
disable the extension, click on the extension icon in the top-right corner of your browser. A pop-up page will appear
with a button to enable or disable the blocking of YouTube Shorts videos.
##  Working
The YouTube Shorts Blocker extension uses a combination of different script types to provide its functionality.
Content scripts are used to interact with and manipulate the content of web pages, in this case the YouTube website.
Background scripts handle the extension's overall functionality and can run even when the extension's pop-up window is closed.
The extension also uses the storage API to save the user's preference for blocking YouTube Shorts videos.
The popup script is used to create the extension's pop-up window, which allows the user to enable or disable the blocking of YouTube Shorts videos.
Together, these scripts work in harmony to provide a seamless and efficient way for users to control the content they see on YouTube.

## manifest.json
The manifest.json file is a fundamental part of any browser extension, and the YouTube
Shorts Blocker extension is no exception. It serves as the extension's configuration file
and contains important information such as the extension's name, version, and description.
Additionally, it also defines the extension's permissions, which specify what resources the extension is allowed to access.
For this extension, the necessary permissions include access to the YouTube website, the ability
to run scripts on web pages, and access to the browser's storage API.
These permissions are required for the extension to be able to block YouTube Shorts videos and save the user's preferences.
Without these permissions, the extension would not be able to perform its intended functionality.

## Uninstallation

1. Open your browser and navigate to the extension settings.
2. Locate the YouTube Shorts Blocker extension and click on the trash icon.
3. Confirm the uninstallation by clicking "Remove".

## Support

If you have any issues with the extension, please open an issue on the https://github.com/Dxuian/crex.git.

## Contributing

If you would like to contribute to the development of the YouTube Shorts Blocker extension, please fork the repository and submit a pull request.

