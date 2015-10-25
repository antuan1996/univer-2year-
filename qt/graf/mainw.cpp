#include "mainw.h"
#include "ui_mainw.h"
#include "pallete.h"
Mainw::Mainw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainw)
{
    ui->setupUi(this);

    QSettings settings("graf-set.ini",QSettings::IniFormat);

    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();

    settings.beginGroup("Graph");
    ui->widget->isGrid = settings.value("grid", false).toBool();
    ui->widget->fid = settings.value("fid", 0).toInt();

    ui->widget_2->setparams(ui->widget->fid,ui->widget->isGrid);

    ui->widget->sx = settings.value("sx", -5.).toDouble();
    ui->widget->sy = settings.value("sy", -5.).toDouble();

    ui->widget->fx = settings.value("fx", 5.).toDouble();
    ui->widget->fy = settings.value("fy", 5.).toDouble();

    ui->widget_2->line_col = settings.value("line_color", QColor(Qt::black)).value<QColor>();
    ui->widget_2->back_col = settings.value("back_clor", QColor(Qt::white)).value<QColor>();
    settings.endGroup();

    ui->widget->line_color = ui->widget_2->line_col;
    ui->widget->back_color = ui->widget_2->back_col;
    ui->widget->getfuncid(ui->widget->fid);
    update();

    connect(ui->widget_2, SIGNAL(data_changed(QColor,QColor,bool)), ui->widget, SLOT(getSettings(QColor,QColor,bool)));
    connect(ui->widget_2, SIGNAL(sendfid(int)), ui->widget, SLOT(getfuncid(int)));
    connect(ui->widget, SIGNAL(foundedPoint(double, double)), ui->widget_2, SLOT(getPoint(double,double)));
    /*
    dr = new drawArea();
    setting = new setter();
    dr->show();
    setting->show();

    */
}
void Mainw::closeEvent(QCloseEvent *ev)
{

    QSettings settings("graf-set.ini",QSettings::IniFormat);

    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();



    settings.beginGroup("Graph");
    settings.setValue("fid", ui->widget->fid);
    settings.setValue("grid", ui->widget->isGrid);
    settings.setValue("sx", ui->widget->sx);
    settings.setValue("sy", ui->widget->sy);

    settings.setValue("fx", ui->widget->fx);
    settings.setValue("fy", ui->widget->fy);

    settings.setValue("line_color",ui->widget->line_color);
    settings.setValue("back_clor", ui->widget->back_color);
    settings.endGroup();


    ev->accept();
}

Mainw::~Mainw()
{
    delete ui;
}
