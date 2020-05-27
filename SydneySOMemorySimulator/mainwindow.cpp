#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QDebug>
#include "processtest.h"

//Acadêmico Sydney Matheus de Souza
//
//

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    screenList.append(ui->scn_Running);//adiciona tela a lista de telas
    screenList.append(ui->scn_Start);

    setCurrentScreenTo(ui->scn_Start);//define tela atual
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Algoritimo para definir tela atual que está atida
void MainWindow::setCurrentScreenTo(QWidget* widget)
{
    widget->setVisible(true);
    widget->setEnabled(true);
    for(int i = 0; i < screenList.size(); i++){
        if(screenList.at(i) != widget){
            screenList.at(i)->setVisible(false);
            screenList.at(i)->setEnabled(false);
        }
    }
}

//Ao clicar em ciloc
void MainWindow::on_btnCiclo_clicked()
{
    ram.memCyclesSum();//Adiciona um ciclo na memoria
    qDebug()<<ram.getMemCycles();
    ui->timeCurrent->setText(QString::number(ciclos++));//mostra os ciclos que ja foram passados
    ui->listWMem->clear();//limpa a lista
    for(int i = 0; i<ram.mainMemProc.size();i++)
    {
        ui->listWMem->addItem(ram.RDMem(i).getProcName()+"; "+QString::number(ram.RDMem(i).getProcCycleSinceRun()));//Adiciona itens na lista da memória ram
    }
    if(processList.size()>=1)//se tiver algo na lista de processos
    {
        ram.WRMem(processList[0]);//escreve na memoria o primeiro processo
        if(ram.getMemoryWRsinal()==1)//caso tenha escrito algo na memoria
        {
            processList.removeFirst();//remove o primeiro item da lista de processos
            ui->listProcessW8->takeItem(0);//remove da lista de espera visual o primeiro item
        }
    } else {
        qDebug()<<"ProcessList Vazia";
    }
}

void MainWindow::on_btnIniciar_clicked()
{
    QString memTam = ui->lineMemTam->text();//defini tamanho da memoria

    if(processList.size()>0 && memTam.toUInt() > 0){//se tiver algum processo na lista e o tamanho de memoria definido
        setCurrentScreenTo(ui->scn_Running);        //inica
        ram.setMemSizeByt(memTam.toUInt());//tamanho da memoria;
        ram.setAlgorithmMode(0);//tipo de inserção Apenas o First Fit foi adicionado
        ram.vectorMemStart();//inicializa todas as posições do vetor auxiliar de memorai em 0
        qDebug()<<ram.getMemSizeByt();

        //Adiciona todos os processos definidos a lista de processos
        for(int i = 0; i<processList.size();i++)
        {
            ui->listProcessW8->addItem(processList[i].getProcName()+"; "+QString::number(processList[i].getProcSize())+"; "+QString::number(processList[i].getProcTime()));
        }
    }
}

//Inserir o processo no inicio do programa
void MainWindow::on_btnAddProc_clicked()
{
    QString procName = nullptr,  lSize = nullptr, lTimeProc = nullptr;

    procName = ui->lineNome->text();
    lSize = ui->lineTam->text();
    lTimeProc = ui->lineTime->text();
    if(procName != nullptr && lSize >0 && lTimeProc >0){
        ProcessTest newProcessGenerator = *new ProcessTest(procName,lTimeProc.toUInt(),lSize.toUInt());
        processList.append(newProcessGenerator);
        ui->previewProcList->addItem(procName+"; "+lSize+"; "+lTimeProc);
    }
}
