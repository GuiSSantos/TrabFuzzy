// Project FLIE-Fuzzy Logic Inference Engine - Jo�o Alberto Fabro - out/1996

// File flie.cc

#include <stdlib.h> // Random!
#include <stdio.h> // Random!
//#define DOS
#include "leftMotor.h"

/*Deve-se definir um sistema de controle que ir� conter as regras.*/
fuzzy_control fuzzycontrolE;

/*No programa principal � necess�rio instanciar as vari�veis para conter
todos os conjuntos fuzzy e tamb�m defini-los.*/

trapezoid_category cat2[21];



/*Deve-se definir as vari�veis lingu�sticas que ir�o conter os conjuntos fuzzy*/

linguisticvariable sens_front2, sens_right2, sens_left2, lingLeftMotor;



/*Deve-se definir as regras de infer�ncia que ir�o reger o comportamento do
sistema de controle.� necess�rio instanci�-los.*/

rule infruleE[99];

leftMotor::leftMotor(){
	mainE();
}

leftMotor::~leftMotor(){

}

void leftMotor::mainE()
{
        int i;



/*deve-se definir vari�veis que ir�o conter as entradas e sa�das(defuzificadas)
do sistema submetidas ao controle.*/

float SumError, ControlOutput;


	cat2[0].setname("ML");
	cat2[0].setrange(0, 450);
	cat2[0].setval(0, 0, 50, 450);

	cat2[1].setname("L");
	cat2[1].setrange(50, 950);
	cat2[1].setval(50, 450, 550, 950);

	cat2[2].setname("M");
	cat2[2].setrange(550, 1450);
	cat2[2].setval(550, 950, 1050, 1450);

	cat2[3].setname("P");
	cat2[3].setrange(1050, 1950);
	cat2[3].setval(1050, 1450, 1550, 1950);

	cat2[4].setname("MP");
	cat2[4].setrange(1550, 2000);
	cat2[4].setval(1550, 1950, 2000, 2000);


	/*Define-se a Vari�vel lingu�stica Error*/

	sens_right2.setname("Sensores da direita");

	sens_right2.includecategory(&cat2[0]);

	sens_right2.includecategory(&cat2[1]);

	sens_right2.includecategory(&cat2[2]);

	sens_right2.includecategory(&cat2[3]);

	sens_right2.includecategory(&cat2[4]);


	cat2[5].setname("ML");
	cat2[5].setrange(0, 450);
	cat2[5].setval(0, 0, 50, 450);

	cat2[6].setname("L");
	cat2[6].setrange(50, 950);
	cat2[6].setval(50, 450, 550, 950);

	cat2[7].setname("M");
	cat2[7].setrange(550, 1450);
	cat2[7].setval(550, 950, 1050, 1450);

	cat2[8].setname("P");
	cat2[8].setrange(1050, 1950);
	cat2[8].setval(1050, 1450, 1550, 1950);

	cat2[9].setname("MP");
	cat2[9].setrange(1550, 2000);
	cat2[9].setval(1550, 1950, 2000, 2000);


	/*Define-se a Vari�vel lingu�stica Error*/

	sens_left2.setname("Sensores da esquerda");

	sens_left2.includecategory(&cat2[5]);

	sens_left2.includecategory(&cat2[6]);

	sens_left2.includecategory(&cat2[7]);

	sens_left2.includecategory(&cat2[8]);

	sens_left2.includecategory(&cat2[9]);



	/*Define-se os conjuntos fuzzy para a vari�vel lingu�stica Control*/

	cat2[10].setname("ML");
	cat2[10].setrange(0, 450);
	cat2[10].setval(0, 0, 50, 450);

	cat2[11].setname("L");
	cat2[11].setrange(50, 950);
	cat2[11].setval(50, 450, 550, 950);

	cat2[12].setname("M");
	cat2[12].setrange(550, 1450);
	cat2[12].setval(550, 950, 1050, 1450);

	cat2[13].setname("P");
	cat2[13].setrange(1050, 1950);
	cat2[13].setval(1050, 1450, 1550, 1950);

	cat2[14].setname("MP");
	cat2[14].setrange(1550, 2000);
	cat2[14].setval(1550, 1950, 2000, 2000);


	/*Defini-se a Vari�vel lingu�stica Error*/

	sens_front2.setname("Sensores da frente");

	sens_front2.includecategory(&cat2[10]);

	sens_front2.includecategory(&cat2[11]);

	sens_front2.includecategory(&cat2[12]);

	sens_front2.includecategory(&cat2[13]);

	sens_front2.includecategory(&cat2[14]);

	/*Define-se os conjuntos fuzzy para a vari�vel lingu�stica Control*/

	cat2[15].setname("RT");
	cat2[15].setrange(-10, -7);
	cat2[15].setval(-10, -10, -8, -7);

	cat2[16].setname("MT");
	cat2[16].setrange(-8,-2);
	cat2[16].setval(-8, -7, -3, -2);

	cat2[17].setname("DT");
	cat2[17].setrange(-3, 1);
	cat2[17].setval(-3, -2, -1, 1);

	cat2[18].setname("DF");
	cat2[18].setrange(-1, 3);
	cat2[18].setval(-1, 1, 2, 3);

	cat2[19].setname("MF");
	cat2[19].setrange(2, 8);
	cat2[19].setval(2, 3, 7, 8);

	cat2[20].setname("RF");
	cat2[20].setrange(7, 10);
	cat2[20].setval(7, 8, 10, 10);


	/*Defini-se a vari�vel lingu�stica Control*/

	lingLeftMotor.setname("Controle");

	lingLeftMotor.includecategory(&cat2[15]);

	lingLeftMotor.includecategory(&cat2[16]);

	lingLeftMotor.includecategory(&cat2[17]);

	lingLeftMotor.includecategory(&cat2[18]);

	lingLeftMotor.includecategory(&cat2[19]);

	lingLeftMotor.includecategory(&cat2[20]);

	/*Defini-se o m�todo defuzzifica��o*/

	fuzzycontrolE.set_defuzz(CENTEROFAREA);


	/* Defini-se o fuzzy_control pelas entradas fuzzy( Error, DeltaError)
	 e sa�das (Control) )*/

	fuzzycontrolE.definevars(sens_left2, sens_front2, sens_right2, lingLeftMotor);


fuzzycontrolE.insert_rule("ML","ML","ML","RF");
fuzzycontrolE.insert_rule("ML","ML","L","RF");
fuzzycontrolE.insert_rule("ML","ML","M","MF");
fuzzycontrolE.insert_rule("ML","ML","P","RT");
fuzzycontrolE.insert_rule("ML","ML","MP","RT");
fuzzycontrolE.insert_rule("ML","L","ML","RF");
fuzzycontrolE.insert_rule("ML","L","L","RF");
fuzzycontrolE.insert_rule("ML","L","M","MF");
fuzzycontrolE.insert_rule("ML","L","P","MT");
fuzzycontrolE.insert_rule("ML","L","MP","RT");
fuzzycontrolE.insert_rule("ML","M","ML","MF");
fuzzycontrolE.insert_rule("ML","M","L","MF");
fuzzycontrolE.insert_rule("ML","M","M","DF");
fuzzycontrolE.insert_rule("ML","M","P","MT");
fuzzycontrolE.insert_rule("ML","M","MP","MT");
fuzzycontrolE.insert_rule("ML","P","ML","DF");
fuzzycontrolE.insert_rule("ML","P","L","DF");
fuzzycontrolE.insert_rule("ML","P","M","DF");
fuzzycontrolE.insert_rule("ML","P","P","RT");
fuzzycontrolE.insert_rule("ML","P","MP","MT");
fuzzycontrolE.insert_rule("ML","MP","ML","DF");
fuzzycontrolE.insert_rule("ML","MP","L","DF");
fuzzycontrolE.insert_rule("ML","MP","M","DF");
fuzzycontrolE.insert_rule("ML","MP","P","MT");
fuzzycontrolE.insert_rule("ML","MP","MP","RT");
fuzzycontrolE.insert_rule("L","ML","ML","RF");
fuzzycontrolE.insert_rule("L","ML","L","RF");
fuzzycontrolE.insert_rule("L","ML","M","MF");
fuzzycontrolE.insert_rule("L","ML","P","DT");
fuzzycontrolE.insert_rule("L","ML","MP","DT");
fuzzycontrolE.insert_rule("L","L","ML","RF");
fuzzycontrolE.insert_rule("L","L","L","RF");
fuzzycontrolE.insert_rule("L","L","M","MF");
fuzzycontrolE.insert_rule("L","L","P","MT");
fuzzycontrolE.insert_rule("L","L","MP","MT");
fuzzycontrolE.insert_rule("L","M","ML","MF");
fuzzycontrolE.insert_rule("L","M","L","MF");
fuzzycontrolE.insert_rule("L","M","M","DF");
fuzzycontrolE.insert_rule("L","M","P","DT");
fuzzycontrolE.insert_rule("L","M","MP","DT");
fuzzycontrolE.insert_rule("L","P","ML","DF");
fuzzycontrolE.insert_rule("L","P","L","DF");
fuzzycontrolE.insert_rule("L","P","M","DF");
fuzzycontrolE.insert_rule("L","P","P","DT");
fuzzycontrolE.insert_rule("L","P","MP","MT");
fuzzycontrolE.insert_rule("L","MP","ML","DF");
fuzzycontrolE.insert_rule("L","MP","L","DF");
fuzzycontrolE.insert_rule("L","MP","M","DF");
fuzzycontrolE.insert_rule("L","MP","P","RT");
fuzzycontrolE.insert_rule("L","MP","MP","MF");
fuzzycontrolE.insert_rule("M","ML","ML","RF");
fuzzycontrolE.insert_rule("M","ML","L","RF");
fuzzycontrolE.insert_rule("M","ML","M","MF");
fuzzycontrolE.insert_rule("M","ML","P","DF");
fuzzycontrolE.insert_rule("M","ML","MP","RF");
fuzzycontrolE.insert_rule("M","L","ML","RF");
fuzzycontrolE.insert_rule("M","L","L","RF");
fuzzycontrolE.insert_rule("M","L","M","MF");
fuzzycontrolE.insert_rule("M","L","P","DF");
fuzzycontrolE.insert_rule("M","L","MP","RT");
fuzzycontrolE.insert_rule("M","M","ML","MF");
fuzzycontrolE.insert_rule("M","M","L","MF");
fuzzycontrolE.insert_rule("M","M","M","MT");
fuzzycontrolE.insert_rule("M","M","P","DF");
fuzzycontrolE.insert_rule("M","M","MP","RT");
fuzzycontrolE.insert_rule("M","P","ML","MF");
fuzzycontrolE.insert_rule("M","P","L","MF");
fuzzycontrolE.insert_rule("M","P","M","DF");
fuzzycontrolE.insert_rule("M","P","P","DF");
fuzzycontrolE.insert_rule("M","P","MP","MT");
fuzzycontrolE.insert_rule("M","MP","ML","MF");
fuzzycontrolE.insert_rule("M","MP","L","MF");
fuzzycontrolE.insert_rule("M","MP","M","DF");
fuzzycontrolE.insert_rule("M","MP","P","MT");
fuzzycontrolE.insert_rule("M","MP","MP","RT");
fuzzycontrolE.insert_rule("P","ML","ML","RF");
fuzzycontrolE.insert_rule("P","ML","L","RF");
fuzzycontrolE.insert_rule("P","ML","M","MF");
fuzzycontrolE.insert_rule("P","ML","P","MF");
fuzzycontrolE.insert_rule("P","ML","MP","MF");
fuzzycontrolE.insert_rule("P","L","ML","RF");
fuzzycontrolE.insert_rule("P","L","L","RF");
fuzzycontrolE.insert_rule("P","L","M","MF");
fuzzycontrolE.insert_rule("P","L","P","MF");
fuzzycontrolE.insert_rule("P","L","MP","DT");
fuzzycontrolE.insert_rule("P","M","ML","MF");
fuzzycontrolE.insert_rule("P","M","L","MF");
fuzzycontrolE.insert_rule("P","M","M","MF");
fuzzycontrolE.insert_rule("P","M","P","MF");
fuzzycontrolE.insert_rule("P","M","MP","MF");
fuzzycontrolE.insert_rule("P","P","ML","MF");
fuzzycontrolE.insert_rule("P","P","L","MF");
fuzzycontrolE.insert_rule("P","P","M","MF");
fuzzycontrolE.insert_rule("P","P","P","DT");
fuzzycontrolE.insert_rule("P","P","MP","DF");
fuzzycontrolE.insert_rule("P","MP","ML","MF");
fuzzycontrolE.insert_rule("P","MP","L","MF");
fuzzycontrolE.insert_rule("P","MP","M","MF");
fuzzycontrolE.insert_rule("P","MP","P","DF");
fuzzycontrolE.insert_rule("P","MP","MP","DF");
fuzzycontrolE.insert_rule("MP","ML","ML","RF");
fuzzycontrolE.insert_rule("MP","ML","L","RF");
fuzzycontrolE.insert_rule("MP","ML","M","MF");
fuzzycontrolE.insert_rule("MP","ML","P","MF");
fuzzycontrolE.insert_rule("MP","ML","MP","MF");
fuzzycontrolE.insert_rule("MP","L","ML","RF");
fuzzycontrolE.insert_rule("MP","L","L","RF");
fuzzycontrolE.insert_rule("MP","L","M","MF");
fuzzycontrolE.insert_rule("MP","L","P","MF");
fuzzycontrolE.insert_rule("MP","L","MP","MF");
fuzzycontrolE.insert_rule("MP","M","ML","MF");
fuzzycontrolE.insert_rule("MP","M","L","MF");
fuzzycontrolE.insert_rule("MP","M","M","MF");
fuzzycontrolE.insert_rule("MP","M","P","MF");
fuzzycontrolE.insert_rule("MP","M","MP","MT");
fuzzycontrolE.insert_rule("MP","P","ML","MF");
fuzzycontrolE.insert_rule("MP","P","L","MF");
fuzzycontrolE.insert_rule("MP","P","M","MF");
fuzzycontrolE.insert_rule("MP","P","P","DT");
fuzzycontrolE.insert_rule("MP","P","MP","DT");
fuzzycontrolE.insert_rule("MP","MP","ML","MF");
fuzzycontrolE.insert_rule("MP","MP","L","MF");
fuzzycontrolE.insert_rule("MP","MP","M","MT");
fuzzycontrolE.insert_rule("MP","MP","P","MT");
fuzzycontrolE.insert_rule("MP","MP","MP","RT");


// Defini-se a leitura dos sensores do seu sistema
float ErrorInput = -100.0;
float DeltaErrorInput = 0.0;

float min;
char fcfilename[20];



	fuzzycontrolE.set_defuzz(CENTEROFAREA);

// Teste para os controles

//min =  navio(fc,1);
//  printf("Minimum Error = %f\n", min);
  fuzzycontrolE.save_m("controlebottom", 0);
}

float leftMotor::makeInference(float input1, float input2, float input3){
	return fuzzycontrolE.make_inference(input1, input2, input3);
}
