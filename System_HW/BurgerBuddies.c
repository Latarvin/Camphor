#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>

sem_t Customers,Cashiers,Burgers,RackSize;
pthread_t CUSTOMER[1000],CASHIER[1000],COOK[1000];
int customerID[1000],cashierID[1000],cookID[1000];
int i,customers_num,cashiers_num,cooks_num,racksize;

int KILL;//wait all customers leave,then kill all of the processes
sem_t KILL_protect;

void *customer_thread(void *num){
	sleep( rand()%3 );
	printf("Customer [%d] come.\n",*(int *)num);
	sem_post(&Customers);
	sem_wait(&Cashiers);
}

void *cashier_thread(void *num){
	int tmp;
	for(;;){
		sem_post(&Cashiers);
		sem_wait(&Customers);
		//try to kill himslef start
		sem_wait(&KILL_protect);
			tmp = KILL;
		sem_post(&KILL_protect);
		if( tmp <= 0 ){
			sem_post(&Cashiers);
			sem_post(&Customers);
			break;
		}
		//try to kill himslef end
		printf("Cashier [%d] accepts an order.\n", *(int *)num);
		sem_wait(&Burgers);
		//try to kill himslef start
		sem_wait(&KILL_protect);
			tmp = KILL;
		sem_post(&KILL_protect);
		if( tmp <= 0 ){
			sem_post(&Cashiers);
			sem_post(&Customers);
			break;
		}
		//try to kill himslef end
		printf("Cashier [%d] take a burger to customer.\n",*(int *)num);
		sem_post(&RackSize);
		//try to kill himslef start && change KILL
		sem_wait(&KILL_protect);
			KILL--;
			tmp = KILL;
		sem_post(&KILL_protect);
		if( tmp <= 0 ){
			sem_post(&Cashiers);
			sem_post(&Customers);
			break;
		}
		//try to kill himslef end
	}
}

void *cook_thread(void *num){
	int tmp;
	for(;;){
		sleep( rand()%1 );
		sem_wait(&RackSize);
		//try to kill himslef start
		sem_wait(&KILL_protect);
			tmp = KILL;
		sem_post(&KILL_protect);
		if( tmp <= 0 ){
			sem_post(&RackSize);
			break;
		}
		//try to kill himslef end
		printf("Cook [%d] make a burger.\n",*(int *)num);
		sem_post(&Burgers);
		//try to kill himslef start
		sem_wait(&KILL_protect);
			tmp = KILL;
		sem_post(&KILL_protect);
		if( tmp <= 0 ){
			sem_post(&RackSize);
			break;
		}
		//try to kill himslef end
	}
}

///////////////////////////////////
int main(int argu,char* argv[]){
	srand( time(NULL) );
	customers_num = atoi(argv[3]);
	cashiers_num = atoi(argv[2]);
	cooks_num = atoi(argv[1]);
	racksize = atoi(argv[4]);
	KILL = customers_num;
	printf("Cooks[%d], Cashiers[%d], Customers[%d].\n", cooks_num, cashiers_num, customers_num);
	printf("Begin run.\n");
	sem_init(&Customers,0,0);
	sem_init(&Cashiers,0,0);
	sem_init(&Burgers,0,0);
	sem_init(&RackSize,0,racksize);
	sem_init(&KILL_protect,0,1);

	for( i=0; i<customers_num; ++i, customerID[i]=i )
		pthread_create( &CUSTOMER[i], NULL, customer_thread, customerID+i+1 );
	for( i=0; i<cashiers_num; ++i, cashierID[i]=i )
		pthread_create( &CASHIER[i], NULL, cashier_thread, cashierID+i+1 );
	for( i=0; i<cooks_num; ++i, cookID[i]=i )
		pthread_create( &COOK[i], NULL, cook_thread, cookID+i+1 );
	for( i=0; i<customers_num; ++i )
		pthread_join( CUSTOMER[i], NULL );
	for( i=0; i<cashiers_num; ++i )
		pthread_join( CASHIER[i], NULL );
	for( i=0; i<cooks_num; ++i )
		pthread_join( COOK[i], NULL );

	return 0;
}
