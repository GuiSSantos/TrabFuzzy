// Project FLIE-Fuzzy Logic Inference Engine - Jo�o Alberto Fabro - out/1996

// File flie.cc

#include <stdlib.h> // Random!
#include <stdio.h> // Random!
#define DOS
#include "rightMotor.h"

/*Deve-se definir um sistema de controle que ir� conter as regras.*/
fuzzy_control fuzzycontrolD;

/*No programa principal � necess�rio instanciar as vari�veis para conter
todos os conjuntos fuzzy e tamb�m defini-los.*/

trapezoid_category cat1[21];



/*Deve-se definir as vari�veis lingu�sticas que ir�o conter os conjuntos fuzzy*/

linguisticvariable sens_front, sens_right, sens_left, lingRightMotor;



/*Deve-se definir as regras de infer�ncia que ir�o reger o comportamento do
sistema de controle.� necess�rio instanci�-los.*/

//TODO
rule infruleD[99];

rightMotor::rightMotor(){
	mainD();
}

rightMotor::~rightMotor(){

}

void rightMotor::mainD()
{
        int i;



/*deve-se definir vari�veis que ir�o conter as entradas e sa�das(defuzificadas)
do sistema submetidas ao controle.*/

float SumError, ControlOutput;


/* Define-se os conjuntos fuzzy para a vari�vel lingu�stica Error*/

	/*
	 MP = Muito Perto
	 P  = Perto
	 M  = M�dio
	 L  = Longe
	 ML = Muito Longe
	 */

	cat1[0].setname("ML");
	cat1[0].setrange(0, 450);
	cat1[0].setval(0, 0, 50, 450);

	cat1[1].setname("L");
	cat1[1].setrange(50, 950);
	cat1[1].setval(50, 450, 550, 950);

	cat1[2].setname("M");
	cat1[2].setrange(550, 1450);
	cat1[2].setval(550, 950, 1050, 1450);

	cat1[3].setname("P");
	cat1[3].setrange(1050, 1950);
	cat1[3].setval(1050, 1450, 1550, 1950);

	cat1[4].setname("MP");
	cat1[4].setrange(1550, 2000);
	cat1[4].setval(1550, 1950, 2000, 2000);


	/*Define-se a Vari�vel lingu�stica Error*/

	sens_right.setname("Sensores da direita");

	sens_right.includecategory(&cat1[0]);

	sens_right.includecategory(&cat1[1]);

	sens_right.includecategory(&cat1[2]);

	sens_right.includecategory(&cat1[3]);

	sens_right.includecategory(&cat1[4]);


	cat1[5].setname("ML");
	cat1[5].setrange(0, 450);
	cat1[5].setval(0, 0, 50, 450);

	cat1[6].setname("L");
	cat1[6].setrange(50, 950);
	cat1[6].setval(50, 450, 550, 950);

	cat1[7].setname("M");
	cat1[7].setrange(550, 1450);
	cat1[7].setval(550, 950, 1050, 1450);

	cat1[8].setname("P");
	cat1[8].setrange(1050, 1950);
	cat1[8].setval(1050, 1450, 1550, 1950);

	cat1[9].setname("MP");
	cat1[9].setrange(1550, 2000);
	cat1[9].setval(1550, 1950, 2000, 2000);


	/*Define-se a Vari�vel lingu�stica Error*/

	sens_left.setname("Sensores da esquerda");

	sens_left.includecategory(&cat1[5]);

	sens_left.includecategory(&cat1[6]);

	sens_left.includecategory(&cat1[7]);

	sens_left.includecategory(&cat1[8]);

	sens_left.includecategory(&cat1[9]);



	/*Define-se os conjuntos fuzzy para a vari�vel lingu�stica Control*/

	cat1[10].setname("ML");
	cat1[10].setrange(0, 450);
	cat1[10].setval(0, 0, 50, 450);

	cat1[11].setname("L");
	cat1[11].setrange(50, 950);
	cat1[11].setval(50, 450, 550, 950);

	cat1[12].setname("M");
	cat1[12].setrange(550, 1450);
	cat1[12].setval(550, 950, 1050, 1450);

	cat1[13].setname("P");
	cat1[13].setrange(1050, 1950);
	cat1[13].setval(1050, 1450, 1550, 1950);

	cat1[14].setname("MP");
	cat1[14].setrange(1550, 2000);
	cat1[14].setval(1550, 1950, 2000, 2000);


	/*Defini-se a Vari�vel lingu�stica Error*/

	sens_front.setname("Sensores da frente");

	sens_front.includecategory(&cat1[10]);

	sens_front.includecategory(&cat1[11]);

	sens_front.includecategory(&cat1[12]);

	sens_front.includecategory(&cat1[13]);

	sens_front.includecategory(&cat1[14]);

	/*
	 RT = Rapido pra Tr�s
	 MT = M�dio pra Tr�s
	 DT = Devagar pra Tr�s
	 DF = Devagar pra Frente
	 MF = M�dio pra Frente
	 RF = R�pido pra Frente
	 */

	/*Define-se os conjuntos fuzzy para a vari�vel lingu�stica Control*/

	cat1[15].setname("RT");
	cat1[15].setrange(-10, -7);
	cat1[15].setval(-10, -10, -8, -7);

	cat1[16].setname("MT");
	cat1[16].setrange(-8,-2);
	cat1[16].setval(-8, -7, -3, -2);

	cat1[17].setname("DT");
	cat1[17].setrange(-3, 1);
	cat1[17].setval(-3, -2, -1, 1);

	cat1[18].setname("DF");
	cat1[18].setrange(-1, 3);
	cat1[18].setval(-1, 1, 2, 3);

	cat1[19].setname("MF");
	cat1[19].setrange(2, 8);
	cat1[19].setval(2, 3, 7, 8);

	cat1[20].setname("RF");
	cat1[20].setrange(7, 10);
	cat1[20].setval(7, 8, 10, 10);


	/*Defini-se a vari�vel lingu�stica Control*/

	lingRightMotor.setname("Controle");

	lingRightMotor.includecategory(&cat1[15]);

	lingRightMotor.includecategory(&cat1[16]);

	lingRightMotor.includecategory(&cat1[17]);

	lingRightMotor.includecategory(&cat1[18]);

	lingRightMotor.includecategory(&cat1[19]);

	lingRightMotor.includecategory(&cat1[20]);

/*Defini-se o m�todo defuzzifica��o*/

fuzzycontrolD.set_defuzz(CENTEROFAREA);


/* Defini-se o fuzzy_control pelas entradas fuzzy( Error, DeltaError)
e sa�das (Control) )*/

fuzzycontrolD.definevars(sens_left, sens_front, sens_right, lingRightMotor);



/*Deve-se incluir cada regra fuzzy no fuzzy_control*/

fuzzycontrolD.insert_rule("ML","ML","ML","RF");
fuzzycontrolD.insert_rule("ML","ML","L","RF");
fuzzycontrolD.insert_rule("ML","ML","M","RF");
fuzzycontrolD.insert_rule("ML","ML","P","MF");
fuzzycontrolD.insert_rule("ML","ML","MP","MF");
fuzzycontrolD.insert_rule("ML","L","ML","RF");
fuzzycontrolD.insert_rule("ML","L","L","RF");
fuzzycontrolD.insert_rule("ML","L","M","RF");
fuzzycontrolD.insert_rule("ML","L","P","MF");
fuzzycontrolD.insert_rule("ML","L","MP","MF");
fuzzycontrolD.insert_rule("ML","M","ML","MF");
fuzzycontrolD.insert_rule("ML","M","L","MF");
fuzzycontrolD.insert_rule("ML","M","M","MF");
fuzzycontrolD.insert_rule("ML","M","P","MF");
fuzzycontrolD.insert_rule("ML","M","MP","MF");
fuzzycontrolD.insert_rule("ML","P","ML","MF");
fuzzycontrolD.insert_rule("ML","P","L","MF");
fuzzycontrolD.insert_rule("ML","P","M","MF");
fuzzycontrolD.insert_rule("ML","P","P","MF");
fuzzycontrolD.insert_rule("ML","P","MP","MF");
fuzzycontrolD.insert_rule("ML","MP","ML","MF");
fuzzycontrolD.insert_rule("ML","MP","L","MF");
fuzzycontrolD.insert_rule("ML","MP","M","MF");
fuzzycontrolD.insert_rule("ML","MP","P","MF");
fuzzycontrolD.insert_rule("ML","MP","MP","MF");
fuzzycontrolD.insert_rule("L","ML","ML","RF");
fuzzycontrolD.insert_rule("L","ML","L","RF");
fuzzycontrolD.insert_rule("L","ML","M","RF");
fuzzycontrolD.insert_rule("L","ML","P","MF");
fuzzycontrolD.insert_rule("L","ML","MP","MF");
fuzzycontrolD.insert_rule("L","L","ML","RF");
fuzzycontrolD.insert_rule("L","L","L","RF");
fuzzycontrolD.insert_rule("L","L","M","RF");
fuzzycontrolD.insert_rule("L","L","P","MF");
fuzzycontrolD.insert_rule("L","L","MP","MF");
fuzzycontrolD.insert_rule("L","M","ML","MF");
fuzzycontrolD.insert_rule("L","M","L","MF");
fuzzycontrolD.insert_rule("L","M","M","MF");
fuzzycontrolD.insert_rule("L","M","P","MF");
fuzzycontrolD.insert_rule("L","M","MP","MF");
fuzzycontrolD.insert_rule("L","P","ML","MF");
fuzzycontrolD.insert_rule("L","P","L","MF");
fuzzycontrolD.insert_rule("L","P","M","MF");
fuzzycontrolD.insert_rule("L","P","P","MF");
fuzzycontrolD.insert_rule("L","P","MP","MF");
fuzzycontrolD.insert_rule("L","MP","ML","MF");
fuzzycontrolD.insert_rule("L","MP","L","MF");
fuzzycontrolD.insert_rule("L","MP","M","MF");
fuzzycontrolD.insert_rule("L","MP","P","MF");
fuzzycontrolD.insert_rule("L","MP","MP","MF");
fuzzycontrolD.insert_rule("M","ML","ML","MF");
fuzzycontrolD.insert_rule("M","ML","L","MF");
fuzzycontrolD.insert_rule("M","ML","M","MF");
fuzzycontrolD.insert_rule("M","ML","P","MF");
fuzzycontrolD.insert_rule("M","ML","MP","MF");
fuzzycontrolD.insert_rule("M","L","ML","MF");
fuzzycontrolD.insert_rule("M","L","L","MF");
fuzzycontrolD.insert_rule("M","L","M","MF");
fuzzycontrolD.insert_rule("M","L","P","MF");
fuzzycontrolD.insert_rule("M","L","MP","MF");
fuzzycontrolD.insert_rule("M","M","ML","DF");
fuzzycontrolD.insert_rule("M","M","L","DF");
fuzzycontrolD.insert_rule("M","M","M","MF");
fuzzycontrolD.insert_rule("M","M","P","RF");
fuzzycontrolD.insert_rule("M","M","MP","RF");
fuzzycontrolD.insert_rule("M","P","ML","DF");
fuzzycontrolD.insert_rule("M","P","L","DF");
fuzzycontrolD.insert_rule("M","P","M","MF");
fuzzycontrolD.insert_rule("M","P","P","MF");
fuzzycontrolD.insert_rule("M","P","MP","MF");
fuzzycontrolD.insert_rule("M","MP","ML","DF");
fuzzycontrolD.insert_rule("M","MP","L","DF");
fuzzycontrolD.insert_rule("M","MP","M","MF");
fuzzycontrolD.insert_rule("M","MP","P","MF");
fuzzycontrolD.insert_rule("M","MP","MP","MF");
fuzzycontrolD.insert_rule("P","ML","ML","DF");
fuzzycontrolD.insert_rule("P","ML","L","DF");
fuzzycontrolD.insert_rule("P","ML","M","DF");
fuzzycontrolD.insert_rule("P","ML","P","MF");
fuzzycontrolD.insert_rule("P","ML","MP","MF");
fuzzycontrolD.insert_rule("P","L","ML","DF");
fuzzycontrolD.insert_rule("P","L","L","DF");
fuzzycontrolD.insert_rule("P","L","M","DF");
fuzzycontrolD.insert_rule("P","L","P","MF");
fuzzycontrolD.insert_rule("P","L","MP","MF");
fuzzycontrolD.insert_rule("P","M","ML","DF");
fuzzycontrolD.insert_rule("P","M","L","DF");
fuzzycontrolD.insert_rule("P","M","M","DF");
fuzzycontrolD.insert_rule("P","M","P","MF");
fuzzycontrolD.insert_rule("P","M","MP","MF");
fuzzycontrolD.insert_rule("P","P","ML","DF");
fuzzycontrolD.insert_rule("P","P","L","DF");
fuzzycontrolD.insert_rule("P","P","M","DF");
fuzzycontrolD.insert_rule("P","P","P","MF");
fuzzycontrolD.insert_rule("P","P","MP","MF");
fuzzycontrolD.insert_rule("P","MP","ML","DF");
fuzzycontrolD.insert_rule("P","MP","L","DF");
fuzzycontrolD.insert_rule("P","MP","M","DF");
fuzzycontrolD.insert_rule("P","MP","P","MF");
fuzzycontrolD.insert_rule("P","MP","MP","MF");
fuzzycontrolD.insert_rule("MP","ML","ML","DF");
fuzzycontrolD.insert_rule("MP","ML","L","DF");
fuzzycontrolD.insert_rule("MP","ML","M","DF");
fuzzycontrolD.insert_rule("MP","ML","P","MF");
fuzzycontrolD.insert_rule("MP","ML","MP","MF");
fuzzycontrolD.insert_rule("MP","L","ML","DF");
fuzzycontrolD.insert_rule("MP","L","L","DF");
fuzzycontrolD.insert_rule("MP","L","M","DF");
fuzzycontrolD.insert_rule("MP","L","P","MF");
fuzzycontrolD.insert_rule("MP","L","MP","MF");
fuzzycontrolD.insert_rule("MP","M","ML","DF");
fuzzycontrolD.insert_rule("MP","M","L","DF");
fuzzycontrolD.insert_rule("MP","M","M","DF");
fuzzycontrolD.insert_rule("MP","M","P","MF");
fuzzycontrolD.insert_rule("MP","M","MP","MF");
fuzzycontrolD.insert_rule("MP","P","ML","DF");
fuzzycontrolD.insert_rule("MP","P","L","DF");
fuzzycontrolD.insert_rule("MP","P","M","DF");
fuzzycontrolD.insert_rule("MP","P","P","MF");
fuzzycontrolD.insert_rule("MP","P","MP","MF");
fuzzycontrolD.insert_rule("MP","MP","ML","DF");
fuzzycontrolD.insert_rule("MP","MP","L","DF");
fuzzycontrolD.insert_rule("MP","MP","M","DT");
fuzzycontrolD.insert_rule("MP","MP","P","MT");
fuzzycontrolD.insert_rule("MP","MP","MP","MT");

// Define-se a leitura dos sensores do seu sistema
float ErrorInput = -100.0;
float DeltaErrorInput = 0.0;

float min;
char fc1filename[20];



fuzzycontrolD.set_defuzz(CENTEROFAREA);

// Teste para os controles

//min =  navio(fc,1);
//  printf("Minimum Error = %f\n", min);
  fuzzycontrolD.save_m("controlebottom", 0);
}

float rightMotor::makeInference(float input1, float input2, float input3){
	return fuzzycontrolD.make_inference(input1, input2, input3);
}
