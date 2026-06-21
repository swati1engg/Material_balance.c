# Material_balance.c
This is a project that integrates the knowledge of basic C program with core chemical concept of material balance (to solve moles and steady mass balance)

# Chemical Process Material Balance Solver

## Project Overview
In industrial chemical manufacturing, verifying the conservation of mass within plant unit operations is mandatory before resizing equipment or piping. 

This program models a continuous dilution tank where an incoming process stream containing a specific solute fraction (\(a_1\)) is diluted using a pure solvent stream (\(a_2\)) to output a continuous product stream (\(a_3\)) at a tightly controlled target concentration( outlet).

##  Chemical Engineering Principles
The mathematics driving this software toolkit are grounded in steady-state conservation equations without chemical reactions (Accumulation = 0).

* **Total Mass Balance Equation:** \(a_1 + a_2 = a_3\)
* **Solute Component Balance Equation:** \(a_1 \cdot x_1 = a_3 \cdot x_3\)

### Dimensional Parameters:
* `a1` = Inlet Process Feed Rate (kg/hr)
* `x1` = Solute Mass Fraction in Feed Stream (%)
* `a2` = Pure Solvent/Water Flow Rate Requirement (kg/hr)
* `a3` = Continuous Total Product Discharge Flow Rate (kg/hr)
* `x3` = Targeted Product Solute Mass Fraction (%)

## Software Architecture & Design
* **Sequential Engineering Layout:** Built entirely inside a clean `main` control block without tracking complex memory stack custom functions.
* **Industrial Constraint Verification:** The program includes rigorous validation structures to capture physically impossible engineering scenarios (e.g., preventing negative flow domains, bounding concentration fractions between 0% and 100%, and rejecting mathematically impossible dilution parameters).
* **Robust Input Parsing:** Implements active stream clearing mechanics to intercept character formatting injection bugs, making sure the application doesn't crash on faulty human input 

```bash
gcc material_balance.c -o material_balance
```

Run the compiled platform executable:
```bash
./material_balance
```

## 📊 Sample Execution Log Output
```text
===================================================
     CHEMICAL PROCESS MATERIAL BALANCE SOLVER
===================================================
  1. Solve Mixing/Dilution Tank Balance
  2. Project Specifications & Engineering Principles
  3. Exit Program
---------------------------------------------------
Enter your choice (1-3): 1

--- Stream 1: Inlet Concentration Stream ---
Enter mass flow rate a1 (kg/hr): 150
Enter feed chemical concentration x1 (%): 60

--- Stream 3: Desired Target Product Stream ---
Enter target concentration x3 (%): 15

================= CORRELATION REPORT =================
 Process Configuration: Dilution of 60.00% stream to 15.00%
------------------------------------------------------
 -> Input Feed Flow (F1)        :     150.00 kg/hr
 -> Required Pure Solvent (F2)  :     450.00 kg/hr
 -> Total Blended Product (F3)  :     600.00 kg/hr
======================================================
```
