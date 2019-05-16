#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Structure.h"
#define NUM_OF_CHARACTERS 1024
int numSpeciality, numDoctor, numPatient, numDoctorLeave, numConsultation;
Speciality specialityList[MAX_SPECIALITY];
Doctor doctorList[MAX_DOCTOR];
Patient patientList[MAX_PATIENT];
DoctorLeave doctorLeaveList[MAX_DOCTORLEAVE];
Consultation consultationList[MAX_CONSULATION];
void readSpeciality()
{
	char inputArray[NUM_OF_CHARACTERS];
    FILE *fp = fopen("speciality.txt", "r");
 
    int lineCount = 0;
     
    // check if the file loaded successfully 
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
 
    //find out how many lines are in the file.
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL)
    {
        lineCount++;
    }
	
    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    // copy lines from inputArray to individual arrays
    int currentLine = 0;
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL && currentLine < lineCount)
    {
		//printf("%s", inputArray);
		//printf("\n");
        sscanf(inputArray, "%[^|]|%[^|]|%d",
               specialityList[currentLine].specialityName,
               specialityList[currentLine].specialityInformation,
               &specialityList[currentLine].specialityPrice );
 
        //printf("%s\n", specialityList[currentLine].specialityName);
        //printf("%s\n", specialityList[currentLine].specialityInformation);
        //printf("%d\n", specialityList[currentLine].specialityPrice);
        
        currentLine++;
    }
	numSpeciality = currentLine;
    fclose(fp);
}
void readPatient()
{
	char inputArray[NUM_OF_CHARACTERS];
    FILE *fp = fopen("patient.txt", "r");
 
    int lineCount = 0;
     
    // check if the file loaded successfully 
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
 
    //find out how many lines are in the file.
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL)
    {
        lineCount++;
    }
	printf("%d\n", lineCount);
    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    // copy lines from inputArray to individual arrays
    int currentLine = 0;
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL && currentLine < lineCount)
    {
		//printf("%s", inputArray);
		printf("\n");
		//1|David Mathews|12-07-1987|746927462|812641842||576165411|1011 Malesuada Road Moscow Kentucky 77382|83898953456
		/*int patientID;
	char patientName[30];
	Date patientDOB;
	char patientNIF[10];
	char patientnCC[10];
	char patientSNS[10];
	char patientTelephoneNumber[10];
	char patientAddress[100];
		*/
        sscanf(inputArray, "%d|%[^|]|%d-%d-%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
        		&patientList[currentLine].patientID,
               	patientList[currentLine].patientName,
               	&patientList[currentLine].patientDOB.day,
               	&patientList[currentLine].patientDOB.month,
               	&patientList[currentLine].patientDOB.year,
               	patientList[currentLine].patientNIF,
				patientList[currentLine].patientnCC,
               	patientList[currentLine].patientSNS,
               	patientList[currentLine].patientAddress,
               	patientList[currentLine].patientTelephoneNumber
               );
 
        //printf("%s\n", patientList[currentLine].patientName);
       // printf("%s\n", patientList[currentLine].patientAddress);
        //printf("%d\n", patientList[currentLine].patientDOB.year);
        
        currentLine++;
    }
	numPatient = currentLine;
    fclose(fp);
}
void readDoctor()
{
	char inputArray[NUM_OF_CHARACTERS];
    FILE *fp = fopen("doctor.txt", "r");
 
    int lineCount = 0;
     
    // check if the file loaded successfully 
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
 
    //find out how many lines are in the file.
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL)
    {
        lineCount++;
    }
	printf("%d\n", lineCount);
    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    // copy lines from inputArray to individual arrays
    int currentLine = 0;
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL && currentLine < lineCount)
    {
		//printf("%s", inputArray);
		printf("\n");
		//1|Adam Kraner|Neurology|213214234|711-2880 Nulla St.Mankato Mississippi 96522|72934758294|21/12/2018
        sscanf(inputArray, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d",
        		&doctorList[currentLine].doctorOrderNumber,
               	doctorList[currentLine].doctorName,
              	doctorList[currentLine].doctorSpeciality,
               	doctorList[currentLine].doctorNIF,
               	doctorList[currentLine].doctorFullAddress,
               	doctorList[currentLine].doctorTelephoneNumber,
               	&doctorList[currentLine].doctorDateOfAddmission.day,
               	&doctorList[currentLine].doctorDateOfAddmission.month,
               	&doctorList[currentLine].doctorDateOfAddmission.year
                );
 
        //printf("%s\n", doctorList[currentLine].doctorName);
        //printf("%s\n", doctorList[currentLine].doctorNIF);
        //printf("%d\n", doctorList[currentLine].doctorDateOfAddmission.year);
        
        currentLine++;
    }
	numDoctor = currentLine;
    fclose(fp);
}
void readDoctorLeave()
{
	char inputArray[NUM_OF_CHARACTERS];
    FILE *fp = fopen("doctorleave.txt", "r");
 
    int lineCount = 0;
     
    // check if the file loaded successfully 
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
 
    //find out how many lines are in the file.
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL)
    {
        lineCount++;
    }
	
    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    // copy lines from inputArray to individual arrays
    int currentLine = 0;
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL && currentLine < lineCount)
    {
		//printf("%s", inputArray);
		//printf("\n");
        sscanf(inputArray, "%d|%d-%d-%d|%d",
               &doctorLeaveList[currentLine].doctorOrderNumber,
               &doctorLeaveList[currentLine].doctorLeaveStartDate.day,
               &doctorLeaveList[currentLine].doctorLeaveStartDate.month,
               &doctorLeaveList[currentLine].doctorLeaveStartDate.year,
               &doctorLeaveList[currentLine].doctorLeaveDays );
 
        //printf("%d\n", doctorLeaveList[currentLine].doctorOrderNumber);
        //printf("%d\n", doctorLeaveList[currentLine].doctorLeaveStartDate.month);
        //printf("%d\n", doctorLeaveList[currentLine].doctorLeaveDays);
        
        currentLine++;
    }
	numDoctorLeave = currentLine;
    fclose(fp);
}
void readConsultation()
{
	char inputArray[NUM_OF_CHARACTERS];
    FILE *fp = fopen("consultation.txt", "r");
 
    int lineCount = 0;
     
    // check if the file loaded successfully 
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
 
    //find out how many lines are in the file.
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL)
    {
        lineCount++;
    }
	
    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    // copy lines from inputArray to individual arrays
    int currentLine = 0;
    while(fgets(inputArray, sizeof(inputArray), fp) != NULL && currentLine < lineCount)
    {
		//printf("%s", inputArray);
		//printf("\n");
		//1|1|1|22-05-2019|10-00|16-05-2019
        sscanf(inputArray, "%d|%d|%d|%d-%d-%d|%d-%d|%d-%d-%d",
               &consultationList[currentLine].consultationOrderID,
               &consultationList[currentLine].patient,
               &consultationList[currentLine].doctor,
               &consultationList[currentLine].consultationDate.day,
               &consultationList[currentLine].consultationDate.month,
               &consultationList[currentLine].consultationDate.year,
               &consultationList[currentLine].consultationTime.hour,
               &consultationList[currentLine].consultationTime.min,
               &consultationList[currentLine].consultationBookingDate.day,
               &consultationList[currentLine].consultationBookingDate.month,
               &consultationList[currentLine].consultationBookingDate.year);
 
        //printf("%d\n", consultationList[currentLine].patient);
        //printf("%d\n", consultationList[currentLine].consultationDate.day);
        //printf("%d\n", consultationList[currentLine].consultationBookingDate.day);
        
        currentLine++;
    }
	numConsultation = currentLine;
    fclose(fp);
}
//Compares two strings case insensitive
int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}
int isNumeric (const char * s)
{
    if (s == NULL || *s == '\0' || isspace(*s))
      return 0;
    char * p;
    strtod (s, &p);
    return *p == '\0';
}
void addSpeciality()
{
	Speciality newSpeciality;
	char name[30];
	printf("Enter Speciality name: ");
	scanf("%s", newSpeciality.specialityName);
	int flag = -1;
	int index = -1;
	int i;
	for(i = 0; i < numSpeciality; i++)
	{
		if(strcicmp(newSpeciality.specialityName, specialityList[i].specialityName) == 0)
		{
			flag = 1;
			index = i;
			break;
		}
	}
	if(flag == 1)
	{
		printf("Error: Speciality already listed. Details are as follows: \n");
		printf("Speciality Name: %s\n", specialityList[index].specialityName);

		printf("Speciality Information: %s\n", specialityList[index].specialityInformation);

		printf("Speciality Price: $%d per consulation\n", specialityList[index].specialityPrice);
	}
	else
	{
		char temp[10];
		gets(temp);
		printf("Enter speciality information: ");
		gets(newSpeciality.specialityInformation);

		int validInt = 0;
		while(validInt == 0)
		{
			printf("Enter speciality consultation price: ");
			scanf("%d", newSpeciality.specialityPrice);
			if(newSpeciality.specialityPrice> 0)
			{
				validInt = 1;
			}
			else
				printf("Error: Price cant be in negative\n");
		}
		specialityList[numSpeciality] = newSpeciality;
		numSpeciality++;
	}

}
void addDoctor()
{
	Speciality newSpeciality;
	char name[30];
	printf("Enter Speciality name: ");
	scanf("%s", newSpeciality.specialityName);
	int flag = -1;
	int index = -1;
	int i;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	for(i = 0; i < numSpeciality; i++)
	{
		if(strcicmp(newSpeciality.specialityName, specialityList[i].specialityName)== 0)
		{
			flag = 1;
			index = i;
			break;
		}
	}
	if(flag == 1)
	{
		char temp[10];
		printf("Speciality already listed. Details are as follows: \n");
		printf("Speciality Name: %s\n", specialityList[index].specialityName);

		printf("Speciality Information: %s\n", specialityList[index].specialityInformation);

		printf("Speciality Price: $%d per consulation\n", specialityList[index].specialityPrice);
		Doctor newDoctor;
		/*
		&doctorList[currentLine].doctorOrderNumber,
               	doctorList[currentLine].doctorName,
              	doctorList[currentLine].doctorSpeciality,
               	doctorList[currentLine].doctorNIF,
               	doctorList[currentLine].doctorFullAddress,
               	doctorList[currentLine].doctorTelephoneNumber,
               	&doctorList[currentLine].doctorDateOfAddmission.day,
               	&doctorList[currentLine].doctorDateOfAddmission.month,
               	&doctorList[currentLine].doctorDateOfAddmission.year
               	*/
		newDoctor.doctorOrderNumber = numDoctor;
		gets(temp);
		printf("Enter doctor name: ");
		gets(newDoctor.doctorName);

		int validNIF = 0;
		while(validNIF == 0)
		{
			printf("Enter doctor NIF: ");
			scanf("%s", newDoctor.doctorNIF);
			if(isNumeric(newDoctor.doctorNIF) && (unsigned)strlen(newDoctor.doctorNIF) == 9)
			{
				validNIF = 1;
			}
			else
				printf("Error: NIF format error\n");
		}
		gets(temp);
		printf("Enter doctor Address: ");
		gets(newDoctor.doctorFullAddress);

		printf("Enter doctor Telephone number: ");
		gets(newDoctor.doctorTelephoneNumber);
		newDoctor.doctorDateOfAddmission.day = tm.tm_mday;
		newDoctor.doctorDateOfAddmission.month = tm.tm_mon;
		newDoctor.doctorDateOfAddmission.year = tm.tm_year;
		doctorList[numDoctor] = newDoctor;
		numDoctor++;
	}
	else
	{
		printf("Error: Speciality not available at this clinic. Please go to main menu and check specialities available");
	}

}

void addPatient()
{
	char temp[10];
	
	Patient newPatient;
	/*
	int patientID;
	char patientName[30];
	Date patientDOB;
	char patientNIF[10];
	char patientnCC[10];
	char patientSNS[10];
	char patientAddress[100];
	char patientTelephoneNumber[10];
	*/
	newPatient.patientID = numPatient;
	printf("Enter patient name: ");
	gets(newPatient.patientName);

	int validNIF = 0;
	while(validNIF == 0)
	{
		printf("Enter patient NIF(Tax Identification Number Numeric only 9 digits): ");
		scanf("%s", newPatient.patientNIF);
		if(isNumeric(newPatient.patientNIF) && (unsigned)strlen(newPatient.patientNIF) == 9)
		{
			validNIF = 1;
		}
		else
			printf("Error: NIF format error\n");
	}
	int validnCC = 0;
	while(validnCC == 0)
	{
		printf("Enter patient nCC(citizen card number Numeric only): ");
		scanf("%s", newPatient.patientnCC);
		if(isNumeric(newPatient.patientnCC))
		{
			validnCC = 1;
		}
		else
			printf("Error: NCC format error\n");
	}
	int validSNS = 0;
	while(validSNS == 0)
	{
		printf("Enter patient SNS(national health service number Numeric only): ");
		scanf("%s", newPatient.patientSNS);
		if(isNumeric(newPatient.patientSNS))
		{
			validSNS = 1;
		}
		else
			printf("Error: SNS format error\n");
	}
	gets(temp);
	printf("Enter patient Address: ");
	gets(newPatient.patientAddress);

	printf("Enter patient Telephone number: ");
	gets(newPatient.patientTelephoneNumber);
	patientList[numPatient] = newPatient;
	numPatient++;
	printf("Patient successfully added. Please go to main menu to book consultation.");
}
//add leave doctor
//add consultation
void displayAllSpeciality()
{
	int i;
	for(i = 0; i < numSpeciality; i++)
	{
		printf("Speciality Name: %s\nSpeciality Information:  %s\nSpeciality Consultation Price: $%d\n", specialityList[i].specialityName, specialityList[i].specialityInformation, specialityList[i].specialityPrice);

	}

}

void displayAllSpecialityAlphabetical()
{
	Speciality tempList[numSpeciality];
	int i, j;
	for(i = 0; i < numSpeciality; i++)
	{
		tempList[i] = specialityList[i];
	}
	Speciality temp;
	for (i = 1; i < numSpeciality; i++)
  		for (j = 0; j < numSpeciality - i; j++) {
 			if (strcmp(tempList[j].specialityName, tempList[j + 1].specialityName) > 0) {
 				temp = tempList[j];
 				tempList[j] = tempList[j + 1];
 				tempList[j + 1] = temp;
 			}
  		}
  	for(i = 0; i < numSpeciality; i++)
	{
		printf("Speciality Name: %s\nSpeciality Information:  %s\nSpeciality Consultation Price: $%d\n", tempList[i].specialityName, tempList[i].specialityInformation, tempList[i].specialityPrice);

	}
}

void displayAllDoctor()
{
	int i;
	for(i = 0; i < numDoctor; i++)
	{
		printf("Doctor Name: %s\n Doctor order No: %d\n Doctor Speciality: %s\n Doctor NIF: %s\n Doctor Address: %s\n Doctor Telephone Number: %s\n",
				doctorList[i].doctorName, doctorList[i].doctorOrderNumber, doctorList[i].doctorSpeciality, doctorList[i].doctorNIF,	doctorList[i].doctorFullAddress, doctorList[i].doctorTelephoneNumber);	
		
	}

}

void displayAllDoctorAlphabetical()
{
	Doctor tempList[numDoctor];
	int i, j;
	for(i = 0; i < numDoctor; i++)
	{
		tempList[i] = doctorList[i];
	}
	Doctor temp;
	for (i = 1; i < numDoctor; i++)
  		for (j = 0; j < numDoctor - i; j++) {
 			if (strcmp(tempList[j].doctorName, tempList[j + 1].doctorName) > 0) {
 				temp = tempList[j];
 				tempList[j] = tempList[j + 1];
 				tempList[j + 1] = temp;
 			}
  		}
  	for(i = 0; i < numDoctor; i++)
	{
		printf("Doctor Name: %s\n Doctor order No: %d\n Doctor Speciality: %s\n Doctor NIF: %s\n Doctor Address: %s\n Doctor Telephone Number: %s\n",
				tempList[i].doctorName, tempList[i].doctorOrderNumber, tempList[i].doctorSpeciality, tempList[i].doctorNIF,	tempList[i].doctorFullAddress, tempList[i].doctorTelephoneNumber);	
		
	}
}

void displayAllDoctorBySpeciality()
{
	int choice = -1;
	int newPrice;
	int validChoice = 0;
	int i;
	while(validChoice == 0)
	{
		printf("Select the speciality whose list of doctor you want to see.\n");
		for(i = 0; i < numSpeciality; i++)
		{
			printf("[%d]Speciality Name: %s Speciality Consultation Price(current): $%d\n",(i+1), specialityList[i].specialityName, specialityList[i].specialityPrice);
		}
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > numSpeciality)
		{
			validChoice = 0;
			printf("Error: Invalid speciality selected");
		}
		else
		{
			printf("Doctors with mentioned speciality are as follows: \n");
			for(i = 0; i <numDoctor; i++)
			{
				if(strcicmp(doctorList[i].doctorSpeciality, specialityList[choice-1].specialityName) == 0)
				printf("Doctor Name: %s\n Doctor order No: %d\n Doctor Speciality: %s\n Doctor NIF: %s\n Doctor Address: %s\n Doctor Telephone Number: %s\n",
				doctorList[i].doctorName, doctorList[i].doctorOrderNumber, doctorList[i].doctorSpeciality, doctorList[i].doctorNIF,	doctorList[i].doctorFullAddress, doctorList[i].doctorTelephoneNumber);	
			
			}
			validChoice = 1;
		}
	}
}
void changeSpecialityConsultationPrice()
{
	int choice = -1;
	int newPrice;
	int validChoice = 0;
	int i;
	while(validChoice == 0)
	{
		printf("Select the speciality to change consultation price.(Enter number adjacent to speciality)\n");
		for(i = 0; i < numSpeciality; i++)
		{
			printf("[%d]Speciality Name: %s Speciality Consultation Price(current): $%d\n",(i+1), specialityList[i].specialityName, specialityList[i].specialityPrice);
		}
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > numSpeciality)
		{
			validChoice = 0;
			printf("Error: Invalid speciality selected");
		}
		else
		{
			printf("Enter new price for consultation(integer only): ");
			scanf("%d", &specialityList[choice-1].specialityPrice);
			printf("Price of consultation successfully updated.");
		}
	}

}

void changeDoctorDetails()
{
	int choice = -1;
	int choiceTwo = -1;
	int newPrice;
	int validChoice = 0;
	char temp[10];
	int i;
	while(validChoice == 0)
	{
		printf("Select the doctor whose address or phone number field you want to modify\n");
		for(i = 0; i < numDoctor; i++)
		{
			printf("[%d]Doctor Name: %s Doctor NIF: %s\n",(i+1), doctorList[i].doctorName, doctorList[i].doctorNIF);
		}
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > numDoctor)
		{
			validChoice = 0;
			printf("Error: Invalid choice selected");
		}
		else
		{
			int validChoiceTwo = 0;
			while(validChoiceTwo == 0)
			{
				printf("Select field you want to modify: \n");
				printf("[1] Address\n");
				printf("[2] Telephone Number\n");
				printf("Enter choice: ");
				scanf("%d", &choiceTwo);
				if(choiceTwo < 1 || choiceTwo > 2)
				{
					validChoiceTwo = 0;
					printf("Error: Invalid field selected");
				}
				else
				{
					gets(temp);
					validChoice = 1;
					validChoiceTwo = 1;
					if(choiceTwo == 1)
					{
						printf("Enter new address: ");
						gets(doctorList[choice-1].doctorFullAddress);
						printf("Address successfully updated.");
					}
					else
					{
						printf("Enter new telephone number: ");
						gets(doctorList[choice-1].doctorTelephoneNumber);
						printf("Price of consultation successfully updated.");
					}
				}
			}
		}
	}
	/*
	int choice = -1;
	int validChoice = 0;
	while(validChoice == 0)
	{
		printf("Select field you want to modify: \n")
		printf("[1] Address\n");
		printf("[2] Telephone Number\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > 2)
		{
			validChoice = 0;
			printf("Error: Invalid field selected");
		}
		else
		{
			if(choice == 1)
			printf("Enter new address: ");
			scanf("%d", &specialityList[choice-1].specialityPrice);
			printf("Price of consultation successfully updated.");
		}


	}
	*/
}
//add doctor
//add patient guide him to go to main menu to book consultation
//add consulation
//add doctorleave

//view speciality
//change speciality consultation price
//sort and save speciality in another file in alphabetical order

//view all doctors
//view doctor by speciality
//view doctor alphabetical
//view doctor by speciality in alphabetic


//view patient alphabetically
//view patient by nSNS
//view patient by DOB after a certain date
//List patient by doctor consulted

//view consultation by patient

//modify doctor addess or phone number
//modify patient telephone number and address
//Enter missing patient details i.e. NIF, nCC or nSNS

//calculate profit of current day
//calculate profilt of current month and save report to file
//calculate profit of current year and save report to file


int main()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	numSpeciality = 0, numDoctor = 0, numPatient = 0, numDoctorLeave = 0, numConsultation = 0;
	readSpeciality();
	readDoctor();
	readPatient();
	readDoctorLeave();
	readConsultation();
	//addSpeciality();
	//addDoctor();
	//addPatient();
	//displayAllSpeciality();
	//changeSpecialityConsultationPrice();
	//displayAllSpeciality();
	//displayAllSpecialityAlphabetical();
	displayAllDoctor();
	displayAllDoctorBySpeciality();
	//displayAllDoctorAlphabetical();
	//changeDoctorDetails();
	//displayAllDoctor();
	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	
}

