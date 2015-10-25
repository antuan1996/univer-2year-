#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    rnum = 5;
    cnum = 5;
    mod = 10;
    data.assign(rnum * cnum, 0);
    ui->setupUi(this);
    update_matrix();

    sub_menu = new QMenu(this);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(show_menu(QPoint)));

    createAct = new QAction(this);
    createAct->setIcon(QIcon::fromTheme("window-new"));
    createAct->setText("Create new matrix...");
    createAct->setStatusTip("CTRL + N");
    createAct->setShortcut(Qt::CTRL + Qt::Key_N);
    connect(createAct, SIGNAL(triggered()),this, SLOT(create_mat()));
    sub_menu->addAction(createAct);
    ui->menuFiles->addAction(createAct);
    ui->mainToolBar->addAction(createAct);


    fillAct = new QAction(this);
    fillAct->setIcon(QIcon::fromTheme("view-refresh"));
    fillAct->setText("Generate matrix values");
    fillAct->setStatusTip("CTRL + G");
    fillAct->setShortcut(Qt::CTRL + Qt::Key_G);
    connect(fillAct, SIGNAL(triggered()),this, SLOT(fill_matrix()));
    sub_menu->addAction(fillAct);
    ui->menuFiles->addAction(fillAct);
    ui->mainToolBar->addAction(fillAct);

    searchAct = new QAction(this);
    searchAct->setIcon(QIcon::fromTheme("system-search"));
    searchAct->setEnabled(0);
    searchAct->setText("Find max");
    searchAct->setStatusTip("CTRL + F");
    searchAct->setShortcut(Qt::CTRL + Qt::Key_F);
    connect(searchAct, SIGNAL(triggered()),this, SLOT(find_max()));
    sub_menu->addAction(searchAct);
    ui->menuFiles->addAction(searchAct);
    ui->mainToolBar->addAction(searchAct);


    deleteAct = new QAction(this);
    deleteAct->setIcon(QIcon::fromTheme("edit-delete"));
    deleteAct->setEnabled(0);
    deleteAct->setText("Delete current row");
    deleteAct->setStatusTip("CTRL + X");
    deleteAct->setShortcut(Qt::CTRL + Qt::Key_X);
    connect(deleteAct, SIGNAL(triggered()),this, SLOT(delete_row()));
    sub_menu->addAction(deleteAct);
    ui->menuFiles->addAction(deleteAct);
    ui->mainToolBar->addAction(deleteAct);


    ui->menuFiles->addSeparator();

    closeAct = new QAction(this);
    closeAct->setIcon(QIcon::fromTheme("window-close"));
    closeAct->setText("Close file");
    closeAct->setStatusTip("CTRL + Q");
    closeAct->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(closeAct, SIGNAL(triggered()),this, SLOT(close()));
    ui->menuFiles->addAction(closeAct);
    ui->mainToolBar->addAction(closeAct);



    //QToolBar* pr_bar = this->addToolBar("Main toolbar");
    //pr_bar->addAction(closeAct);
}
void MainWindow::show_menu(QPoint p){
    QPoint globalPos = ui->tableWidget->mapToGlobal(p);
    sub_menu->popup(globalPos);
}

void MainWindow::fill_matrix(){
    srand( rand() );
    searchAct->setEnabled(1);
    for(int r = 0; r < rnum; ++r)
        for(int c = 0; c < cnum; ++c){
            data[r * cnum + c] = rand() % (mod+1) ;
        }
    update_matrix();
}
void MainWindow::find_max(){
    int frow = 0, fcol = 0;
    int maxx = -1;
    deleteAct->setEnabled(1);
    for(int r = 0; r < rnum; ++r)
        for(int c = 0; c < cnum; ++c){
            int cur_val = data[ r * cnum + c ];
            if(cur_val > maxx){
                maxx = cur_val;
                frow = r;
                fcol = c;
            }
        }
    ui->tableWidget->setCurrentCell(frow, fcol);
}

void MainWindow::update_matrix(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(cnum);
    ui->tableWidget->setRowCount(rnum);
    for(int r = 0; r < rnum; ++r)
        for(int c = 0; c < cnum; ++c){
            int cur_val = data[r * cnum + c];
            QTableWidgetItem* cur_item = new QTableWidgetItem(QString::number(cur_val));
            ui->tableWidget->setItem(r, c, cur_item);
        }
    ui->tableWidget->setCurrentCell(0,0);
}
void MainWindow::delete_row(){
    deleteAct->setEnabled(0);
    if (data.size() <= cnum ) return;
    std::vector< int >::iterator it = data.begin();

    int pos = ( ui->tableWidget->currentRow() ) * cnum;

    data.erase(it + pos, it + pos + cnum);
    //std::cout << data.size() <<std::endl;

    --rnum;
    std::cout << rnum <<" "<<cnum <<std::endl;
    update_matrix();
}
void MainWindow::create_mat(){
    std::cout <<"Im here" << std::endl;
    Dialog* newd = new Dialog(rnum, cnum, this);
    connect(newd, SIGNAL(send_coord(int,int)), this, SLOT(create_new(int,int)));
    newd->exec();

}
void MainWindow::create_new(int h, int w){
    rnum = h;
    cnum = w;
    data.clear();
    data.assign(rnum * cnum, 0);
    std::cout <<"I am here" << std::endl;
    deleteAct->setEnabled(0);
    searchAct->setEnabled(0);
    std::cout << rnum <<" "<<cnum <<std::endl;
    fill_matrix();
    //update_matrix();
}

MainWindow::~MainWindow()
{
    delete ui;
}
