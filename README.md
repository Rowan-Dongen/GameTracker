Author: Rowan Dongen
- This is the repository for my embedded project.
  
# Game Tracker
The game tracker allows you to track the score of various games using an arduino and various sensors and actuators/displays.


# Currently supported games
- Darts 🎯
- Boxing bag timer 🥊👊⏲️

# Follow along!
-https://trello.com/b/Ju48PjNp/game-tracker

## :ledger: Index

- [About](#beginner-about)
- [Usage](#zap-usage)
  - [Installation](#electric_plug-installation)
- [Development](#wrench-development)
  - [Pre-Requisites](#notebook-pre-requisites)
  - [Developmen Environment](#nut_and_bolt-development-environment)
  - [File Structure](#file_folder-file-structure)
  - [Build](#hammer-build)  
  - [Deployment](#rocket-deployment)  
- [Gallery](#camera-gallery)
- [Credit/Acknowledgment](#star2-creditacknowledgment)

##  :beginner: About

## :zap: Usage
Write about how to use this project.

###  :electric_plug: Installation


```
$ - Steps on how to install this project, to use it.
$ - Install PlatformIO for VSCode
$ - Clone repository
$ - Open repository directory as PlatformIO project in VSCode
$ - Plug in device
$ - Upload and monitor in PlatformIO
```

##  :wrench: Development
If you want other people to contribute to this project, hmu!

### :notebook: Pre-Requisites (Libraries)
Following libraries installed using platformIO, are swapable, but you figure it out :)
	arduino-libraries/LiquidCrystal@^1.0.7
	Wire
	gmarty2000/Joystick@^1.0.0
	mathertel/OneButton@^2.5.0

###  :nut_and_bolt: Development Environment
This project is built using Visual Studio Code and the PlatformIO extension for VScode.

###  :file_folder: File Structure
Add a file structure here with the basic details about files, below is an example.

```
DART-BOARD-COUNTER
├── .pio
│   └──PIO SETTINGS
├── .vscode
│   └──VSCODE SETTINGS
├── include
│   └──LIB FILES
├── lib
│   └── LIB FILES
└── src
│   ├── css
│   ├──DartboardGame.cpp
│   ├──DartboardGame.h
│   ├──Game.cpp
│   ├──Game.h
│   ├──GamesEnum.h
│   ├──pitches.h
│   ├──main.cpp 
│   └── rate-ui.css
├──.gitignore
├──.platformio.ini
```

| No | File Name | Details 
|----|------------|-------|
| 1  | index | Entry point


 ### :cactus: Branches
1. **`master`** is the development branch.

**Steps to work with feature branch**

1. To start working on a new feature, create a new branch prefixed with `feature/` and followed by feature name. (ie. `feature/FEATURE-NAME`)
2. Once you are done with your changes, you can raise PR.

### :exclamation: Guideline
coding guidelines or other things you want people to follow should follow.

## 🖱️: Hardware
- Arduino Uno
- 16x2 LCD Display
- Clicking Joystick
- Buzzer

##  🔌: Wiring
<insert wiring diagram>

##  :camera: Gallery
<Pics>

## :star2: Credit/Acknowledgment
My momma!

##  :lock: License
Verified cool people license.TM
