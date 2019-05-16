#define MAX_SPECIALITY 10
#define MAX_DOCTOR	45
#define MAX_PATIENT 1000
#define MAX_DOCTORLEAVE 1000
#define MAX_CONSULATION 1000

enum choice {TRUE,FALSE};

typedef struct{
    int day;
    int month;
    int year;
}Date;

typedef struct{
	int hour;
	int min;
}Time;

typedef struct{
	char specialityName[30];
	char specialityInformation[512];
	int specialityPrice;
	
}Speciality;

typedef struct{
	//DoctorOrderNumber(Unique)	DoctorSpeciality	DoctorName	DoctorNIF	DoctorFullAddress	DoctorTelephoneNumber	DoctorDateOfAddmission	
	int doctorOrderNumber;
	char doctorSpeciality[30];
	char doctorName[30];
	char doctorNIF[10];
	char doctorFullAddress[100];
	char doctorTelephoneNumber[10];
	Date doctorDateOfAddmission;
}Doctor;

typedef struct{
	int patientID;
	char patientName[30];
	Date patientDOB;
	char patientNIF[10];
	char patientnCC[10];
	char patientSNS[10];
	char patientAddress[100];
	char patientTelephoneNumber[10];
	
} Patient;

typedef struct{
	int doctorOrderNumber;
	//DoctorOrderNumber	DoctorLeaveStartDate	DoctorLeaveDays
	Date doctorLeaveStartDate;
	int doctorLeaveDays;
}DoctorLeave;

typedef struct{
	//ConsultationOrderID	PatientID	DoctorOrderNumber ConsultationDay	ConsultationHour	
	int consultationOrderID;
	int patient;
	int doctor;
	Date consultationDate;
	Time consultationTime;
	Date consultationBookingDate;
}Consultation;


	