# IAMC Problem Statement 7: Alcohol Detection System

Arduino Uno teaching prototype that samples the MQ-3 analog signal, gives a buzzer/status warning above an adjustable threshold, and drives an isolated relay module output to inhibit starting.

## Wokwi simulation

Open this folder as a Wokwi Arduino project, or import `diagram.json` and `sketch.ino`. The potentiometer is an **input substitute** for the MQ-3 analog output because the simulation uses a controllable analog source. Turning it upward emulates a larger sensor reading. The blue LED emulates the engine-enable output; the simulation does not contain a vehicle or starter. The below- and above-threshold serial states were observed in a live Wokwi run. Genuine Wokwi screenshots (circuit, code, and both output states) still need to be captured and inserted into the report before final academic submission.

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
3. For Wokwi, use the provided potentiometer input to exercise readings below and above 500; capture screenshots of the circuit, sketch, serial output, and both indicator states for submission.
4. On hardware, allow sensor warm-up, collect clean-air baseline readings, and tune the threshold experimentally. Test relay polarity without connecting a vehicle starter.

## Deliverables status

The repository includes the six-page report PDF, Arduino/Wokwi source project, a generated logic-walkthrough demo video, and a generated passive breakout-board Gerber package. The demo video is an animation based on the observed Wokwi output states, not a screen recording or physical hardware demonstration. The PCB package is not automotive safety hardware and requires electrical/footprint review and CAM inspection before fabrication. Genuine Wokwi screenshots and student identification details are still needed to complete the report for submission.
