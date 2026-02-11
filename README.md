# CAN Bus Analyzer (Qt + C++)

A desktop-based **CAN Bus Analyzer simulation tool** built using **Qt (Widgets) and C++**.  
This project simulates CAN frames, displays them in real time, highlights message status, and logs data to a CSV file - similar to professional CAN analysis tools.

---

## Features

- Start / Stop CAN data simulation
- Pause / Resume CAN frame generation
- Real-time CAN data display using `QTableWidget`
- Random CAN ID and data generation (simulation)
- Time-stamped CAN frames
- Color-coded CAN message status:
  -  Red -> Critical Error
  -  Orange -> Warning
  -  Light Green -> Normal
- Automatic CSV logging (`can_log.csv`)
- Table size limit to keep latest CAN frames visible
- Styled UI buttons and status labels

---

## Technologies Used

-   C++
-   Qt Widgets
- `QTimer` for periodic CAN frame generation
- `QTableWidget` for real-time data display
- `QFile` & `QTextStream` for CSV logging
- `QTime` for timestamps
-   Qt Signal–Slot mechanism

---

## Project Functionality Explained

  CAN Data Simulation:-
- Uses `rand()` to generate:
  - **CAN ID** (11-bit range: 0–2047)
  - **Data byte** (0–255)
- `srand(time(0))` seeds randomness to avoid repeated values.

## Timer-Based Frame Generation
- `QTimer` triggers every **1 second**.
- Each timeout generates a new CAN frame.

## Pause / Resume Logic
- Pause button toggles frame generation without stopping the timer.
- Useful for inspecting data without losing session state.

## CSV Logging
- On Start, a CSV file `can_log.csv` is created.
- Logs:
- Automatically stops logging when the analyzer stops.

---
## Error Highlighting Logic

 CAN ID Range    Status             Color        
  ≥ 1500             Critical Error    Red          
  ≥ 1000             Warning          Orange       
  < 1000             Normal            Light Green  

---

## What This Project Demonstrates

- Qt Widgets UI development
- Signal–Slot communication
- Timer-based real-time data processing
- File handling and CSV logging
- GUI styling using Qt Style Sheets
- Embedded-systems-style CAN monitoring logic

---

## How to Run

1. Open the project in Qt Creator
2. Build the project
3. Run the application
4. Click Start to begin CAN simulation
5. Use Pause / Resume as needed
6. Check `can_log.csv` for logged data

---

## Author

Name:- Pratik Narkhede  
Qt & C++ Developer  
CAN | Embedded Systems | Desktop Applications

---
## Output
<img width="978" height="523" alt="MainWindow 11-02-2026 15_14_25" src="https://github.com/user-attachments/assets/c3a52e8d-280a-4ff0-8ebd-f2577366c3c3" />


<img width="978" height="523" alt="MainWindow 11-02-2026 15_14_49" src="https://github.com/user-attachments/assets/097280f9-9bd3-4aca-8cd2-afcadab007d5" />

## Video Output



https://github.com/user-attachments/assets/9ac01aa1-44e0-43b2-896f-546095073cbb


