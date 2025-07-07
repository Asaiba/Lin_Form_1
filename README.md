# Linux Programming Projects

This repository contains implementations for various system-level programming challenges using **C**, **x86 Assembly**, **Python**, and **shared libraries**.

---

## 📁 Table of Contents

- [1. Disassemble ELF Binary](#1-disassemble-elf-binary)
- [2. x86 Assembly ATM Simulation](#2-x86-assembly-atm-simulation)
- [3. C-Python IoT Monitoring System](#3-c-python-iot-monitoring-system)
- [4. Secure Diary with Encryption and Shared Library](#4-secure-diary-with-encryption-and-shared-library)

---

## ✅ 1. Disassemble ELF Binary

**Language:** C  
**Tool Used:** `objdump`

### 📌 Objective:
Disassemble an ELF executable's `.text` section and save the output to a `.txt` file.

### 📂 Files:
- `disassemble.c`

### 🚀 Build & Run:
```bash
gcc disassemble.c -o disassemble
./disassemble <path_to_ELF_file>
```

## ✅ 2. x86 Assembly ATM Simulation

Language: x86 Assembly (NASM)

📌 Objective:
Simulate basic ATM operations (Deposit, Withdraw, Check Balance, Exit) using modular procedures.

📂 Files:
- ` atm.asm `

🚀 Build & Run:
```bash
nasm -f elf atm.asm
ld -m elf_i386 -s -o atm atm.o
./atm
```

## ✅ 3. C-Python IoT Monitoring System

Languages: C + Python
Python Integration: C extension module (sensor.so)
Visualization: matplotlib

📌 Objective:
Simulate sensor readings (Temperature, Humidity, Battery) and visualize them in real-time from a Python script.

📂 Files:
- ` sensor_module.c (C Extension) `
- ` monitor.py (Python Visualization) `
🛠 Build C Extension:
```bash
gcc -fPIC -shared -o sensor.so sensor_module.c $(python3-config --includes --ldflags)
Make sure python3-dev is installed. On Ubuntu/Debian:
```

```bash
sudo apt install python3-dev
```

🚀 Run:
```bash
python3 monitor.py
```

## ✅ 4. Secure Diary with Encryption and Shared Library

Language: C
Concept: Symmetric key encryption using shared library

📌 Objective:
Create a CLI diary that encrypts entries using a shared .so library and decrypts them after password verification.

📂 Files:
- `diarylib.c (Shared Library)`
- `diary.c (Executable using shared lib)`

🛠 Build:
```bash
gcc -fPIC -shared -o libdiary.so diarylib.c
gcc diary.c -L. -ldiary -o diary
export LD_LIBRARY_PATH=.
```
🚀 Run:
```bash
./diary
```

📦 Dependencies Used:
gcc, nasm, ld
Python 3 with:
python3-dev
matplotlib
