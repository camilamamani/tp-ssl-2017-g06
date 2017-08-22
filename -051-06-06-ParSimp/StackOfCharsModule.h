 /* STACKOFCHARSMODULE.h
  * Equipo 06
  * 02/07/2017
  */

#ifndef STACKOFCHARSMODULE_H_
#define STACKOFCHARSMODULE_H_

/*
Qué exporta:
▪ StackItem
▪ Push
▪ Pop
▪ IsEmpty
▪ IsFull
*/

typedef char StackItem;

StackItem pop(void);

void push(StackItem);

StackItem* popString(void);

void push(StackItem);


int isEmpty(void);//

int isFull(void);

#endif