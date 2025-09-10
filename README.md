# Small Clinic Management System - Documentation

<p align="center">
  <b>Name:</b> Ngô Quang Trường &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <b>Student's ID:</b> 24110142
</p>

<p align="center">
  <b>Subject:</b> Object - Oriented Programming
</p>


## 1. OOA Analysis

In the analysis phase, the system was divided into key objects:
**Patient, Doctor, Appointment, and Clinic**. Relationships between them
were identified: doctors manage appointments, patients are linked to
appointments, and the clinic manages everything.

## 2. Class Design Explanation

-   **Patient class**: Stores information about ID, name, age, and
    medical history.\
-   **ChronicPatient class**: Inherits from Patient, adds conditionType
    and lastCheckupDate. This shows **inheritance** in OOP.\
-   **Doctor class**: Manages doctors, their specialty, and a list of
    appointments.\
-   **Appointment class**: Connects Doctor and Patient.\
-   **Clinic class**: Manages collections of doctors, patients, and
    appointments.

Inheritance was used for ChronicPatient, so it can reuse Patient
features but extend with chronic-specific details.

## 3. Challenges Encountered

-   Designing classes and methods was difficult at first, since I did
    not know how objects would connect.\
-   Syntax mistakes happened often because I was not yet confident with
    C++.\
-   Implementing full OOP features, especially **polymorphism**, was
    challenging.

## 4. Code Walkthrough

-   **Patient & ChronicPatient**: Patients are created with their info,
    chronic patients extend functionality.\
-   **Doctor**: Stores personal data and list of appointments.\
-   **Appointment**: Holds date, time, and links doctor with patient.\
-   **Clinic**: Central management of all entities, with methods to add
    and show them.

## 5. Test Results

-   Test Case 1: Added doctors and patients successfully.\
-   Test Case 2: Created appointments linking doctors and patients.\
-   Test Case 3: Chronic patient displayed with extended info and
    simulated appointment scheduling.\
-   Test Case 4: Appointment created for chronic patient, correctly
    linked with doctor and shown in clinic data.

Outputs confirmed that data connections and relationships worked as
designed.

## 6. LLM Usage

- I used ChatGPT to get suggestions for class methods and structuring my
documentation.\
- For example, I asked: *"Suggest methods for an Appointment class in a
clinic system."*\
- I then adapted the suggestions to my design, and all the final code was
written by myself.
