#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value){
	if ((rear + 1) % SIZE == front){
		printf("Queue is full\n");
		return;
	}

	if (front == -1){
		front =0;
	}

	rear = (rear + 1) % SIZE;
	queue[rear = value;

	printf("%d inserted\n",value);




void dequeue(){
	if (front == - ){

