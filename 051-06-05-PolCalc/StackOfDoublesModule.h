 /* StackOfDoublesModule.h
  * Equipo 06
  * 02/07/2017
  */

#ifndef STACKOFDOUBLESMODULE_H_
#define STACKOFDOUBLESMODULE_H_

/*
Qué exporta:
▪ StackItem
▪ Push
▪ Pop
▪ IsEmpty
▪ IsFull
*/

typedef double StackItem;

StackItem pop(void);

void push(StackItem);

int isEmpty(void);//

int isFull(void);

#endif
