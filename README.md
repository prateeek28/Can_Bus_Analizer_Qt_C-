# CAN Bus Analyzer (Qt + C++)
 
This project simulates CAN frames, displays them in real time, highlights message status, and logs data to a CSV file - similar to professional CAN analysis tools.
## Output
<img width="978" height="523" alt="MainWindow 11-02-2026 15_14_25" src="https://github.com/user-attachments/assets/c3a52e8d-280a-4ff0-8ebd-f2577366c3c3" />

<img width="978" height="523" alt="MainWindow 11-02-2026 15_14_49" src="https://github.com/user-attachments/assets/097280f9-9bd3-4aca-8cd2-afcadab007d5" />

## Video Output

https://github.com/user-attachments/assets/9ac01aa1-44e0-43b2-896f-546095073cbb

---
## Technologies Used

-  C++
-  Qt Widgets
-  QTimer for periodic CAN frame generation
-  QTableWidget for real-time data display
-  QFile & QTextStream for CSV logging
-  QTime for timestamps
-  Qt Signal–Slot mechanism
---

## Error Highlighting Logic

 CAN ID Range        Status             Color        
  ≥ 1500             Critical Error     Red          
  ≥ 1000             Warning            Orange       
  < 1000             Normal             Light Green  
  
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
Name:- Prateek Narkhede  
Qt & C++ Developer 
