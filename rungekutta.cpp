#include "rungekutta.h"
#include "ui_rungekutta.h"
#include <Qstring>
#include <cmath>
#include <qmath.h>
#include <qmessagebox.h>

RungeKutta::RungeKutta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RungeKutta)
{
    ui->setupUi(this);//connections within the program
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

RungeKutta::~RungeKutta()
{
    delete ui;
}

void RungeKutta::metodo(){

    QString temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18;
    double h=ui->doubleSpinBox_3->value();
    double y=ui->doubleSpinBox_4->value();
    double x=ui->doubleSpinBox_5->value();
    double k1,k2,k21,k22,k31,k32,k3,k4,y1,x1;
    double k10,k20,k210,k220,k310,k320,k30,k40,y2,x2;
    double k15,k25,k215,k225,k315,k325,k35,k45,y3,x3;


    //F(X)=2XY

    if(h==0){
        QMessageBox msgBox;
        msgBox.setText("Usted no ingreso H la cual es fundamental para que el método funcione.");//suggests entering more than 1 value in X0 to start the method
        msgBox.exec();
        }
//FIRST                       //the first iteration of the method is performed to obtain its results
    k1=h*2*(x*y);

    k21=(x+(0.5*h));
    k22=(y+(0.5*k1));

    k2=h*2*(k21*k22);          //K is calculated for the final method gain

    k31=h*2*(x+(0.5*h));
    k32=(y+(0.5*k2));

    k3=k31*k32;

    k4=h*2*(x+h)*(y+k3);

    x1=x+h;//end result
    y1=y+((k1+(2*k2)+(2*k3)+k4)/6);//end result

//SECOND                               //the second iteration of the method is performed to obtain its results
    k10=h*2*(x1*y);

    k210=(x1+(0.5*h));
    k220=(y+(0.5*k10));

    k20=h*2*(k210*k220);    //K is calculated for the final method gain

    k310=h*2*(x1+(0.5*h));
    k320=(y+(0.5*k20));

    k30=k310*k320;

    k40=h*2*(x1+h)*(y+k30);

    x2=x1+h;//end result
    y2=y+((k10+(2*k20)+(2*k30)+k40)/6); //end result

//THIRD                          //the second iteration of the method is performed to obtain its results
    k15=h*2*(x2*y);

    k215=(x2+(0.5*h));
    k225=(y+(0.5*k15));

    k25=h*2*(k215*k225);

    k315=h*2*(x2+(0.5*h));                  //K is calculated for the final method gain
    k325=(y+(0.5*k25));

    k35=k315*k325;

    k45=h*2*(x2+h)*(y+k35);

    x3=x2+h;//end result
    y3=y+((k15+(2*k25)+(2*k35)+k45)/6);//end result


//show the text in the interface
    temp
            .append("PRIMER ITERACIÓN\n\n")
.append("k1=").append(temp1.setNum(k1)).append("\nk2=").append(temp2.setNum(k2)).append("\nk3=").append(temp3.setNum(k3)).append("\nk4=").append(temp4.setNum(k4)).append("\n\nX1=").append(temp5.setNum(x1)).append("\n\nY1=").append(temp6.setNum(y1))
            .append("\n\nSEGUNDA ITERACIÓN\n\n")
.append("k1=").append(temp7.setNum(k10)).append("\nk2=").append(temp8.setNum(k20)).append("\nk3=").append(temp9.setNum(k30)).append("\nk4=").append(temp10.setNum(k40)).append("\n\nX2=").append(temp11.setNum(x2)).append("\n\nY2=").append(temp12.setNum(y2))
            .append("\n\nTERCER ITERACIÓN\n\n")
.append("k1=").append(temp13.setNum(k15)).append("\nk2=").append(temp14.setNum(k25)).append("\nk3=").append(temp15.setNum(k35)).append("\nk4=").append(temp16.setNum(k45)).append("\n\nX3=").append(temp17.setNum(x3)).append("\n\nY3=").append(temp18.setNum(y3));
ui->textEdit->setText(temp);  //The text is presented
}

void RungeKutta::borrar(){//The spinbox is deleted
    ui->doubleSpinBox_3->setValue(0.0);
    ui->doubleSpinBox_4->setValue(0.0);
    ui->doubleSpinBox_5->setValue(0.0);
    ui->textEdit->clear();   //Text is deleted

}


