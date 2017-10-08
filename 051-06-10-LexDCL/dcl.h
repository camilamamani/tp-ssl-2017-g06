 /* dcl.h
  */
#ifndef DCL_H
#define DCL_H
#define MAXTOKEN 100

enum {NAME= 'N', PARENS='P', BRACKETS='B', END='E'};

void dcl();
void dirdcl();


int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int GetToken();

#endif