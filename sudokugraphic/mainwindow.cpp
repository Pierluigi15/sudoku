#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <array>
#include "grid.h"
#include <iostream>
#include <QLineEdit>
#include "sudoku.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ //méthode qui initialise la fenêtre graphique
    ui->setupUi(this);
    //on initialise l'attribut listcase ici car avant les widgets ne sont pas définis, cette liste nous permet de parcourir tous les QLineEdits qui composent la grille
    this->listcase = {ui->case_1, ui->case_2, ui->case_3, ui->case_4, ui->case_5, ui->case_6, ui->case_7, ui->case_8, ui->case_9, ui->case_10, ui->case_11, ui->case_12, ui->case_13, ui->case_14, ui->case_15, ui->case_16, ui->case_17, ui->case_18, ui->case_19, ui->case_20, ui->case_21, ui->case_22, ui->case_23, ui->case_24, ui->case_25, ui->case_26, ui->case_27, ui->case_28, ui->case_29, ui->case_30, ui->case_31, ui->case_32, ui->case_33, ui->case_34, ui->case_35, ui->case_36, ui->case_37, ui->case_38, ui->case_39, ui->case_40, ui->case_41, ui->case_42, ui->case_43, ui->case_44, ui->case_45, ui->case_46, ui->case_47, ui->case_48, ui->case_49, ui->case_50, ui->case_51, ui->case_52, ui->case_53, ui->case_54, ui->case_55, ui->case_56, ui->case_57, ui->case_58, ui->case_59, ui->case_60, ui->case_61, ui->case_62, ui->case_63, ui->case_64, ui->case_65, ui->case_66, ui->case_67, ui->case_68, ui->case_69, ui->case_70, ui->case_71, ui->case_72, ui->case_73, ui->case_74, ui->case_75, ui->case_76, ui->case_77, ui->case_78, ui->case_79, ui->case_80, ui->case_81};
    this->ColorMainWindow();

    //on connecte tous les boutons à leurs actions, le CheckButton permet de vérifier les chiffres déjà rentrés
    connect(ui->CheckButton,&QPushButton::clicked,this,&MainWindow::checkgrid);
    //on connecte les différents boutons qui permettent d'afficher des sudokus de niveaux variés
    connect(ui->FacileButton,&QPushButton::clicked,[=]() {this->setSudoku(this->sudoku_facile);});
    connect(ui->MoyenButton,&QPushButton::clicked,[=]() {this->setSudoku(this->sudoku_moyen);});
    connect(ui->DifficileButton,&QPushButton::clicked,[=]() {this->setSudoku(this->sudoku_difficile);});

    //on connecte chaque case pour qu'à chaque fois que leur contenu est modifié le worksudoku soit actualisé
    for(int i=0;i<81;i++){
        connect(listcase[i],&QLineEdit::textEdited, [=](const QString& text) {this->worksudoku.updatewg(i, text.toStdString());});
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FillMainWindow(std::array<int,81>a)
{
    //méthode qui permet d'afficher la grille correspondant à un certain array<int,81>, les cases non vides à l'origine sont en mode ReadOnly
    for(int i=0;i<81;i++){
        if(a[i]!=0){
            std::string c = std::to_string(a[i]);
            const char *d = c.c_str();
            //la méthode setText prend des char* en argument donc on doit convertir la string représentant l'entier en char*
            listcase[i]->setText(d);
            listcase[i]->setReadOnly(true);
        }

    };


}

void MainWindow::ColorMainWindow()
{
    //méthode qui permet de colorer le background des cases en 2 couleurs pour faire apparaître les grandes cases et rendre le jeu plus agréable
    const char *gris="QLineEdit { background: rgb(255, 195, 135); }";
    const char *blanc="QLineEdit { background: rgb(255, 255, 255); }";
    std::array<const char*,9> colors ={gris,blanc,gris,blanc,gris,blanc,gris,blanc,gris};
    for(int i=0;i<81;i++){
        int line=i/9;
        int column=i%9;
        int divline = line/3;
        int divcol = column/3;
        int sqr = divline*3+divcol;
        listcase[i]->setStyleSheet(colors[sqr]);
    }

}


void MainWindow::checkgrid()
{
    //méthode qui permet de vérifier les entrées faites par l'utilisateur par comparaison avec la grille solution
    //si une entrée est fausse, le background de la case devient rouge
    this->ColorMainWindow();
    std::array<int,81> checkedarray= worksudoku.check();
    for(int i=0;i<81;i++){
        if(checkedarray[i]==1){
            listcase[i]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
        }
    }

}

void MainWindow::setSudoku(sudoku s)
{
    //cette méthode permet d'associer un certain sudoku à la fenêtre graphique, ce sudoku devient un de ses attributs et est affiché
    this->deleteAll();
    ui->label->clear();
    this->worksudoku=s;
    this->FillMainWindow(s.getwg());
    this->ColorMainWindow();

}

void MainWindow::deleteAll()
{
    //cette méthode efface tout ce qui est écrit dans la grille et réinitialise l'accessibilité des cases
    for(int i=0;i<81;i++){
        listcase[i]->clear();
        listcase[i]->setReadOnly(false);
        listcase[i]->setAlignment(Qt::AlignHCenter);
    }
}
