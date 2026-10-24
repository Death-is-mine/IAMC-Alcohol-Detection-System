# IAMC Problem Statement 7: Alcohol Detection System

Arduino Uno teaching prototype that samples the MQ-3 analog signal, gives a buzzer/status warning above an adjustable threshold, and drives an isolated relay module output to inhibit starting.

## Wokwi simulation

Open this folder as a Wokwi Arduino project, or import `diagram.json` and `sketch.ino`. The potentiometer is an **input substitute** for the MQ-3 analog output because the simulation uses a controllable analog source. Turning it upward emulates a larger sensor reading. The blue LED emulates the engine-enable output; the simulation does not contain a vehicle or starter. The below- and above-threshold states were observed in a live Wokwi run. The public Wokwi project is linked below and provided separately from the PDF for interactive review of the circuit, code, and outputs. The report has a generated circuit overview on page 4 and actual Wokwi screenshots on pages 7 and 8.

## Pin map

| Arduino Uno | Connection | Purpose |
|---|---|---|
| A0 | MQ-3 AO (simulation: potentiometer SIG) | Sensor analog reading |
| D5 | Green LED through 220 ohm resistor | Below-threshold status |
| D6 | Red LED through 220 ohm resistor | Inhibit/alarm status |
| D8 | Buzzer positive | Audible alarm |
| D9 | Isolated active-low relay module IN | Engine-start permit output |
| 5V / GND | Sensor/module supply and common ground | Use module supply requirements |

## Threshold and operation

`TRIP_THRESHOLD` starts at 500 ADC counts solely as an illustrative value. Calibrate against the selected sensor module, supply, environment, and clean-air baseline; this is not a blood-alcohol measurement. The sketch inhibits the relay during a 20 second warm-up and when the reading is at/above threshold. The MQ-3 and hobby electronics are not safety-certified.

## Bill of materials

- Arduino Uno (or compatible 5 V board)
- MQ-3 alcohol gas sensor/module with analog output
- 5 V active-low relay module with suitable isolation and contact rating (physical build only)
- Active buzzer, two status LEDs, current-limiting resistors, regulated supply, wiring and breadboard
- Enclosure and automotive-rated protected interface only for a professionally reviewed vehicle installation
- Arduino IDE 2.x; Wokwi web simulator for demonstration

## Build and test

1. Open `sketch.ino` in Arduino IDE and select Arduino Uno.
2. Wire the sensor, indicators, buzzer, and relay module as listed. Do not power a relay coil from a GPIO pin.
3. Open the public Wokwi project linked below, allow the warm-up to finish, and use the potentiometer to review readings below and above 500.
4. On hardware, allow sensor warm-up, collect clean-air baseline readings, and tune the threshold experimentally. Test relay polarity without connecting a vehicle starter.

## Deliverables status

The repository includes the eight-page report PDF, Arduino/Wokwi source project, a 55-second screen recording of the live Wokwi simulation, and a passive breakout-board Gerber package. The recording shows the warm-up, below-threshold permit state, and above-threshold inhibit state in the browser simulator; it is not a physical hardware test. The PCB package is not automotive safety hardware and requires electrical/footprint review and CAM inspection before fabrication. The interactive Wokwi review is provided separately through the public project link below.

## Attribution

This repository contains AI-assisted work. Commit history identifies the assistant-authored commits as `Codex (AI-assisted)`; repository ownership remains with `Death-is-mine`.

## Live Wokwi project

[Open the IAMC Alcohol Detection System in Wokwi](https://wokwi.com/projects/478784437484163073). The public simulation includes the sketch and circuit. Let the 20-second warm-up finish, then turn the potentiometer below 500 for permit status or above 500 for the alarm/inhibit state.

