//
//  main.c
//  OperacijskiSistemi
//
//  Created by RokZabukovec on 26/05/2018.
//  Copyright © 2018 Rok Zabukovec. All rights reserved.
//
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
	// Finds the process id
	pid_t getpid(void);
	//Finds the effective user ID (UID) of the calling process.
	uid_t geteuid(void);
	printf("-Zacetek izvajanja programa.-\n PID izvajanjega procesa je %d.\n UID izvajanega procesa je %d\n", (int)getpid(), (int)geteuid());
	// Number of seconds to calculate days and weeks...
	printf("Vnesi stevilo sekund: \n");
	long numOfSeconds;
	int seconds = scanf("%ld", &numOfSeconds);
	
	

	if (seconds == EOF) {
		return 1;
	}
	// User inputs a collection of numbers
	int i=0, j=0;
	// max amount of numbers is declared with 100
	int arr[100];
	char temp;
	int counter = 0;
	printf("Vnesi zbirko stevil: \n");
	do {
		scanf("%d%c", &arr[i], &temp);
		i++;
		counter++;
	} while(temp != '\n');
	
	int additionalNum;
	printf("Vnesi dodatno stevilko za iskanje: \n");
	scanf("%d", &additionalNum);
	printf("Vneseno stevilo sekund je: %ld.\n", numOfSeconds );
	printf("Stevilo elementov polj je: %d.\n", counter );
	printf("Vneseno polje je: ");
	for(j=0; j<i; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
	printf("Vneseno celo število za iskanje je: %d. \n", additionalNum );
	
	// fork() returns twice. For child and parent process.
	int otrok = fork();
	// If the fork() return -1 it means error accured.
	if(otrok < 0){
		printf("ERROR");
	}
	// code in if statment is executed by a child process
	else if(otrok == 0){
		printf("\n---------------CHILD------------------\n");
		// Finds the process id
		pid_t getpid(void);
		pid_t getppid(void);
		//Finds the effective user ID (UID) of the calling process.
		printf("Proces otrok je bil ustvarjen.\nPID procesa otrok je %d.\nPPID starševskega procesa je %d. \n", (int)getpid(), (int)getppid());
		// Calculates a number of days, hours, minutes and remaining seconds from users input of seconds
		long seconds = numOfSeconds;
		long days = seconds / (60 * 60 * 24);
		seconds -= days * (60 * 60 * 24);
		long hours = seconds / (60 * 60);
		seconds -= hours * (60 * 60);
		long min = seconds / 60;
		seconds -= min * 60;
		// Formated output to user of how many days, hours, minutes and seconds is in seconds that the user entered.
		printf("%lds se lahko zapise kot: %lddni %ldh: %ld min: %lds\n",numOfSeconds,days, hours, min, seconds);
	}else{
		// Code in else statment is executed by a parent process.
		printf("--------------PARENT-----------------\n");
		int smallest = arr[0];
		int counter = 0;
		int suma = 0;
		for(int i = 0; i < sizeof(&arr); i++){
	
			if(arr[i] < smallest){
				smallest = arr[i];
			}
			printf("%d ", arr[i]);
			suma = suma + arr[i];
			if(arr[i] == additionalNum){
				counter++;
			}
		}
		if(counter != 0){
			printf("\nDodatna stevilka %d za iskanje se pojavi %d-krat. \n",additionalNum, counter);
		}else{
			printf("\nDodatna stevilka %d za iskanje se ne pojavi v zaporedju! \n", additionalNum);
		}
		printf("Seštevek vseh številk v zbirki je: %d \n", suma);
		printf("Najmanjse stevilo v skupini je: %d\n", smallest);

	}
	FILE *fp;
	fp = fopen("output.txt", "w");
	
	fprintf(fp, "I love cheese.");
	fflush(fp);
	fclose(fp);
	return 0;
}
