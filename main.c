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
	int numOfSeconds;
	int seconds = scanf("%d", &numOfSeconds);
	
	if (seconds == EOF) {
		// ERROR
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
	printf("Vneseno stevilo sekund je: %d.\n", numOfSeconds );
	printf("Stevilo elementov polj je: %d. \n ", counter );
	printf("Vneseno polje je:");
	for(j=0; j<i; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
	printf("Vneseno celo stevilo za iskanje je: %d. \n ", additionalNum );
	
	// fork returns twice. For child and parent process
	int otrok = fork();
	if(otrok < 0){
		printf("ERROR");
	}
	// code in if statment is executed by a child process
	else if(otrok == 0){
		// Finds the process id
		pid_t getpid(void);
		pid_t getppid(void);
		//Finds the effective user ID (UID) of the calling process.
		printf("Proces otrok je bil ustvarjen. PID procesa otrok je %d.\n PPID starševskega procesa je %d \n", (int)getpid(), (int)getppid());
		int seconds = numOfSeconds;
		int days = seconds / (60 * 60 * 24);
		seconds -= days * (60 * 60 * 24);
		int hours = seconds / (60 * 60);
		seconds -= hours * (60 * 60);
		int min = seconds / 60;
		seconds -= min * 60;
		
		printf("%ds: %d days %d hours: %d min: %ds \n",numOfSeconds,days, hours, min, seconds);
	}else{
		printf(" PARENT \n");
	}
	
	
	return 0;
}
