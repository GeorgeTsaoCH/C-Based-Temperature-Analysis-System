# C-Based Temperature Analysis System

C project focused on temperature reading, analysis, and hardware-driven output control.  
This project uses menu-based program flow, function-based structure, and hardware interaction to read temperature values, calculate analysis results, and display output through LEDs and a seven-segment display.

## Highlights
- Built a **menu-driven C program** with user options for reading temperatures, displaying analysis, and exiting
- Used **functions, loops, and conditional logic** to control program flow
- Calculated **highest, lowest, and average temperature values**
- Integrated hardware-related control logic for **heater, buzzer, LEDs, pushbuttons, and seven-segment display**
- Strengthened understanding of **embedded-style programming** and structured logic flow

## Project Overview
This project allows the user to:
- read temperature input through hardware interaction
- store and analyze temperature readings
- display the hottest, coldest, and average temperature
- control visual and output feedback devices during execution

The program is structured into separate functions for:
- reading temperature input
- analyzing recorded values
- displaying results

## Files
- `project.c` — main program flow and menu handling
- `functiongetTemperature.c` — temperature reading logic
- `displayTemperatureAnalysis.c` — output display and result presentation logic

## Skills Demonstrated
- **C programming**
- **if/else logic**
- **switch-case control flow**
- **loops**
- **function-based program design**
- **basic hardware interaction**
- **temperature data analysis**
- **embedded-style control logic**

## Key Engineering Lessons
1. **Structured logic improves readability**  
   Separating temperature reading and display analysis into functions made the program easier to understand and maintain.

2. **Simple user flow matters**  
   A menu-based design makes the program easier to operate and test.

3. **Analysis and display are both important**  
   The project does not only collect values, but also processes and presents the hottest, coldest, and average results.

## Resume Version
For resume use, this project can be summarized as:

> Developed a C-based temperature analysis program with menu-driven logic, function-based structure, and hardware-interaction concepts. Implemented temperature reading, highest/lowest/average analysis, and result display using conditional logic, loops, and modular program design.
