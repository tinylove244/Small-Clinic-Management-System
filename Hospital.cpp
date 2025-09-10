#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class Patient
// Attributes: id, name, age, history (vector of strings)
// Methods: constructor, showInfo(), addHistory(string record), getId(), getName(), getAge()
class Patient {
private: // show encapsulation
    int id;
    string name;
    int age;
    vector<string> history;
public:
    // Constructors default
    Patient() {
        id = 0;
        name = "";
        age = 0;
    }
    // Constructor with parameters
    Patient(int id, string& name, int age, string& record) {
        this->id = id;
        this->name = name;
        this->age = age;
        if (!record.empty()) history.push_back(record);
    }
    // Method to display patient information
    void showInfo() {
        cout << "Patient ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "History: ";
        for (int i = 0; i < history.size(); i++) {
            cout << history[i];
            if (i < history.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    // Method to add a record to the patient's history
    void addHistory(string record) {
        history.push_back(record);
    }
    // Getters
    int getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
};

//class ChronicPatient : public Patient (shows inheritance)
// Additional Attributes: conditionType, lastCheckupDate
//methods: constructor, showInfo(), scheduleAppointment()
class ChronicPatient : public Patient {
private:
    string conditionType;
    string lastCheckupDate;
public:
    // Constructors default
    ChronicPatient() : Patient() {
        conditionType = "";
        lastCheckupDate = "";
    }
    // Constructor with parameters
    ChronicPatient(int id, string& name, int age, string& record,
                   string& conditionType, string& lastCheckupDate)
        : Patient(id, name, age, record) {
        this->conditionType = conditionType;
        this->lastCheckupDate = lastCheckupDate;
    }
    // Override showInfo to include chronic patient details
    void showInfo() {
        cout << "--- Chronic Patient Info ---" << endl;
        Patient::showInfo(); // Call base class method: show inherited attributes
        cout << "Condition Type: " << conditionType << endl;
        cout << "Last Checkup Date: " << lastCheckupDate << endl;
    }
    // Method to schedule an appointment
    void scheduleAppointment() {
        cout << "Scheduling appointment for chronic patient: " << getName() << endl;
        cout << "Condition Type: " << conditionType << endl;
        cout << "Last Checkup Date: " << lastCheckupDate << endl;
        cout << "Appointment scheduled successfully!" << endl;
    }
};

class Appointment; // Forward declaration of Appointment class

//class Doctor
// Attributes: id, name, specialty, appointments (vector of Appointment pointers)
// Methods: constructor, showInfo(), getId(), getName(), getSpecialty(), addAppointment(Appointment* appointment)
class Doctor {
private: // show encapsulation
    int id;
    string name;
    string specialty;
    vector<Appointment*> appointments;
public:
    // Constructors default
    Doctor() {
        id = 0;
        name = "";
        specialty = "";
    }
    // Constructor with parameters
    Doctor(int id, string& name, string& specialty) {
        this->id = id;
        this->name = name;
        this->specialty = specialty;
    }
    // Method to display doctor information
    void showInfo() {
        cout << "Doctor ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Appointments: " << appointments.size() << endl;
    }
    // Getters
    int getId() { return id; }
    string getName() { return name; }
    string getSpecialty() { return specialty; }
    // Method to add an appointment to the doctor's list
    void addAppointment(Appointment* appointment) {
        appointments.push_back(appointment);
    }
};

//class Appointment
// Attributes: id, date, time, doctor (Doctor pointer), patient (Patient pointer)
// Methods: constructor, showInfo(), getId()
class Appointment {
private:
    int id;
    string date;
    string time;
    Doctor* doctor;
    Patient* patient;
public:
    // Constructors default
    Appointment() {
        id = 0;
        date = "";
        time = "";
        doctor = NULL;
        patient = NULL;
    }
    
    Appointment(int id, string& date, string& time, Doctor* doctor, Patient* patient) {
        this->id = id;
        this->date = date;
        this->time = time;
        this->doctor = doctor;
        this->patient = patient;
    }
    // Method to display appointment information
    void showInfo() {
        cout << "--- Appointment Info ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        if (doctor != NULL) cout << "Doctor: " << doctor->getName() << endl;
        if (patient != NULL) cout << "Patient: " << patient->getName() << endl;
    }
    // Getter
    int getId() { return id; }
};

// class Clinic

//class Clinic
// Attributes: doctors (vector of Doctor), patients (vector of Patient), appointments (vector of Appointment)
// Methods: addDoctor(Doctor doctor), addPatient(Patient patient), addAppointment(Appointment appointment), showAll()
class Clinic {
private: // show encapsulation
    vector<Doctor> doctors;         // List of doctors in the clinic
    vector<Patient> patients;       // List of patients in the clinic
    vector<Appointment> appointments; // List of appointments in the clinic

public:
    // Method to add a doctor to the clinic
    void addDoctor(Doctor doctor) { 
        doctors.push_back(doctor); 
    }

    // Method to add a patient to the clinic
    void addPatient(Patient patient) { 
        patients.push_back(patient); 
    }

    // Method to add an appointment to the clinic
    void addAppointment(Appointment appointment) { 
        appointments.push_back(appointment);
     }

    // Method to display all clinic data (patients, doctors, appointments)
    void showAll() {
        cout << "===== Clinic Data =====" << endl;

        cout << "\n-- Patients --" << endl;
        for (int i = 0; i < patients.size(); i++) {
            patients[i].showInfo();
        }

        cout << "\n-- Doctors --" << endl;
        for (int i = 0; i < doctors.size(); i++) {
            doctors[i].showInfo();
        }

        cout << "\n-- Appointments --" << endl;
        for (int i = 0; i < appointments.size(); i++) {
            appointments[i].showInfo();
        }
    }
};

void showMenu(Clinic& clinic, vector<Doctor>& doctors, vector<Patient>& patients);

int main() {
    Clinic clinic; // Create a clinic object to manage doctors, patients, and appointments

    // ---------- Test case 1: Add Patients and Doctors ----------
    // Purpose: Kiểm tra khả năng thêm bệnh nhân và bác sĩ vào hệ thống
    string pname1 = "Nguyen Van A", record1 = "Flu";
    string pname2 = "Tran Thi B", record2 = "Headache";
    Patient p1(1, pname1, 30, record1); // Create patient 1
    Patient p2(2, pname2, 25, record2); // Create patient 2

    string dname1 = "Dr. Smith", spec1 = "Cardiology";
    string dname2 = "Dr. Alice", spec2 = "Neurology";
    Doctor d1(1, dname1, spec1); // Create doctor 1
    Doctor d2(2, dname2, spec2); // Create doctor 2

    clinic.addPatient(p1); // Add patient 1 to clinic
    clinic.addPatient(p2); // Add patient 2 to clinic
    clinic.addDoctor(d1);  // Add doctor 1 to clinic
    clinic.addDoctor(d2);  // Add doctor 2 to clinic

    cout << "\n=== Test Case 1: Added Patients and Doctors ===" << endl;
    clinic.showAll(); // Display all clinic data

    // ---------- Test case 2: Create Appointments ----------
    // Purpose: Kiểm tra khả năng tạo lịch hẹn giữa bác sĩ và bệnh nhân
    string date1 = "2025-09-15", time1 = "09:00";
    string date2 = "2025-09-16", time2 = "10:00";
    Appointment a1(1, date1, time1, &d1, &p1); // Appointment for patient 1 with doctor 1
    Appointment a2(2, date2, time2, &d2, &p2); // Appointment for patient 2 with doctor 2

    d1.addAppointment(&a1); // Link appointment to doctor 1
    d2.addAppointment(&a2); // Link appointment to doctor 2

    clinic.addAppointment(a1); // Add appointment 1 to clinic
    clinic.addAppointment(a2); // Add appointment 2 to clinic

    cout << "\n=== Test Case 2: Added Appointments ===" << endl;
    clinic.showAll();

    // ---------- Test case 3: Add Chronic Patient ----------
    // Purpose: Kiểm tra khả năng thêm bệnh nhân mãn tính và đặt lịch tái khám
    string pname3 = "Le Van C", record3 = "Diabetes";
    string cond3 = "Diabetes", lastCheck3 = "2025-01-10";
    ChronicPatient cp1(3, pname3, 50, record3, cond3, lastCheck3); // Create chronic patient

    clinic.addPatient(cp1); // Add chronic patient to clinic

    cout << "\n=== Test Case 3: Chronic Patient ===" << endl;
    cp1.showInfo(); // Show chronic patient details
    cp1.scheduleAppointment(); // Simulate scheduling appointment for chronic patient

    // ---------- Test case 4: Appointment with Chronic Patient ----------
    // Purpose: Kiểm tra khả năng tạo lịch hẹn cho bệnh nhân mãn tính
    string date3 = "2025-09-20", time3 = "11:00";
    Appointment a3(3, date3, time3, &d1, &cp1); // Appointment for chronic patient with doctor 1

    d1.addAppointment(&a3); // Link appointment to doctor 1
    clinic.addAppointment(a3); // Add appointment to clinic

    cout << "\n=== Test Case 4: Appointment with Chronic Patient ===" << endl;
    clinic.showAll();

    vector<Doctor> doctors; // để giữ tham chiếu cho appointment
    vector<Patient> patients;

    showMenu(clinic, doctors, patients);

    return 0;
}

//  Function: Display menu and allow user interaction
void showMenu(Clinic& clinic, vector<Doctor>& doctors, vector<Patient>& patients) {
    while (true) {
        // ---------- Menu header ----------
        cout << "\n===== CLINIC MENU =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Add Appointment" << endl;
        cout << "4. Show All Information" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // avoid getline issue after cin

        if (choice == 0) {
            cout << "Exiting program..." << endl;
            break;
        }

        switch (choice) {
        // ---------- Case 1: Add a new patient ----------
        case 1: {
            int id, age;
            string name, record;
            cout << "Enter Patient ID: "; cin >> id; cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Age: "; cin >> age; cin.ignore();
            cout << "Enter Record: "; getline(cin, record);

            Patient p(id, name, age, record);
            clinic.addPatient(p);
            patients.push_back(p); // store patient for later appointment
            cout << "Patient added successfully!" << endl;
            break;
        }
        // ---------- Case 2: Add a new doctor ----------
        case 2: {
            int id;
            string name, specialty;
            cout << "Enter Doctor ID: "; cin >> id; cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Specialty: "; getline(cin, specialty);

            Doctor d(id, name, specialty);
            clinic.addDoctor(d);
            doctors.push_back(d); // store doctor for later appointment
            cout << "Doctor added successfully!" << endl;
            break;
        }
        // ---------- Case 3: Create a new appointment ----------
        case 3: {
            if (doctors.empty() || patients.empty()) {
                cout << "Need at least one doctor and one patient before making an appointment!" << endl;
                break;
            }

            int id, docId, patId;
            string date, time;
            cout << "Enter Appointment ID: "; cin >> id; cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): "; getline(cin, date);
            cout << "Enter Time (HH:MM): "; getline(cin, time);
            cout << "Enter Doctor ID: "; cin >> docId;
            cout << "Enter Patient ID: "; cin >> patId;
            cin.ignore();

            // Find doctor and patient by ID
            Doctor* docPtr = nullptr;
            Patient* patPtr = nullptr;
            for (int i = 0; i < doctors.size(); i++) {
                if (doctors[i].getId() == docId) { docPtr = &doctors[i]; break; }
            }
            for (int i = 0; i < patients.size(); i++) {
                if (patients[i].getId() == patId) { patPtr = &patients[i]; break; }
            }

            if (docPtr && patPtr) {
                Appointment a(id, date, time, docPtr, patPtr);
                docPtr->addAppointment(&a);
                clinic.addAppointment(a);
                cout << "Appointment added successfully!" << endl;
            } else {
                cout << "Doctor or Patient not found!" << endl;
            }
            break;
        }
        // ---------- Case 4: Show all information ----------
        case 4: {
            clinic.showAll();
            break;
        }
        // ---------- Default: Invalid input ----------
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


