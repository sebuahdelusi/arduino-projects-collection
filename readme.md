# 7-Segment & RGB LED Logic Controller

This project demonstrates a digital logic controller using an Arduino. It integrates a 7-Segment display with an RGB LED to create a state machine that cycles through 6 distinct phases. The system displays primary colors, secondary colors, and specific digits derived from the user's Student ID (NIM).

## 📋 Features

* **State Machine Logic:** Cycles through 6 states (0-5) using a single push button.
* **RGB Integration:** Displays Primary (Red, Green, Blue) and Secondary (Yellow, Magenta, Cyan) colors.
* **7-Segment Display:** Shows specific NIM digits (2, 3, 0) synchronized with secondary colors.
* **Button Behavior:**
    * **Press & Hold:** Turns OFF all outputs (Reset/Pause).
    * **Release:** Advances to the next state and activates the display.

## ⚙️ State Cycle Details

| State | RGB Color | 7-Segment Output | Decimal Point | Description |
| :---: | :--- | :---: | :---: | :--- |
| **0** | 🔴 Red | OFF | OFF | Primary Color 1 |
| **1** | 🟢 Green | OFF | OFF | Primary Color 2 |
| **2** | 🔵 Blue | OFF | OFF | Primary Color 3 |
| **3** | 🟡 Yellow | **2** | ON | Secondary 1 + NIM Digit 1 |
| **4** | 🟣 Magenta | **3** | ON | Secondary 2 + NIM Digit 2 |
| **5** | ⚪ Cyan | **0** | ON | Secondary 3 + NIM Digit 3 |

## 🔌 Hardware Pin Configuration

Connect the components as defined in the source code:

| Component | Arduino Pin | Notes |
| :--- | :--- | :--- |
| **RGB Red** | D12 | Output |
| **RGB Green** | D10 | Output |
| **RGB Blue** | D11 | Output |
| **Push Button** | D2 | Input Pull-up |
| **Segment A** | D3 | |
| **Segment B** | D4 | |
| **Segment C** | D5 | |
| **Segment D** | D6 | |
| **Segment E** | D7 | |
| **Segment F** | D8 | |
| **Segment G** | D9 | |
| **Segment DP** | D13 | Decimal Point |

*> **Note:** This code assumes a **Common Cathode** 7-Segment display (Active HIGH).*

## 🚀 How to Operate

1.  **Wiring:** Assemble the circuit ensuring current limiting resistors are used for the LEDs and 7-Segment pins.
2.  **Power On:** The system starts in an "Off" state until interaction.
3.  **Click Button:** Press and release the button to step through the color/number sequence.
4.  **Hold Button:** While the button is pressed/held down, the display will turn off momentarily.
