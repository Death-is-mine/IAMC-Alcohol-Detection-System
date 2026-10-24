# Alcohol detection system breakout PCB (Gerber)

Passive two-layer through-hole breakout board for the classroom Arduino Uno + MQ-3 sensor prototype. It routes Uno 5V/GND/A0 and D5/D6/D8/D9 to the MQ-3 sensor header and an external load header. The relay module, buzzer driver, and LEDs remain external modules/components.

## Files

- `AlcoholBreakout-F_Cu.gbr`, `AlcoholBreakout-B_Cu.gbr`
- `AlcoholBreakout-F_Mask.gbr`, `AlcoholBreakout-B_Mask.gbr`
- `AlcoholBreakout-F_Silkscreen.gbr`, `AlcoholBreakout-Edge_Cuts.gbr`
- `AlcoholBreakout-PTH.drl`, `AlcoholBreakout-NPTH.drl`

Connector pitch: 5.08 mm; plated holes: 1.0 mm; standard header pads: 1.8 mm. Board outline: 48 x 38 mm. J1 pin order is 5V, GND, A0, D5, D6, D8, D9, spare. J2 is 5V, GND, MQ-3 AO. J3 is 5V, GND, A0 monitor, D5, D6, D8, D9.

This is a passive educational breakout, not an automotive safety controller or vehicle starter interface. Verify pin order, footprint compatibility, clearances, manufacturer rules, and electrical requirements in a PCB/CAM viewer before fabrication. No board was manufactured or electrically validated.
