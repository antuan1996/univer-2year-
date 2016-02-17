#include "control.h"
#include "ui_control.h"
#include "previewfiledialog.h"
Control::Control(int bw, int bh, QWidget *parent) : QDialog(parent),
                                                    border_color( Qt::white ), shadow_deep( 10 ) ,ui(new Ui::Control)
{
    mask_horiz.load( ":/images/cross.png" );
    mask_vert.load(":/images/cross_vert.png");
    board_w = bw;
    board_h = bh;
    n_horiz = 2;
    n_vert  = 2;
    shadow_intensity = 120;
    img_name = "";
    ui->setupUi(this);
    const QStringList colorNames = QColor::colorNames();
    int index = 0;
    int white_ind = 0;
    for(const QString &colorName: colorNames)
    {
        const QColor color(colorName);
        if( color == Qt::white )
            white_ind = index;
        ui->color_box->addItem(colorName, color);
        const QModelIndex idx = ui->color_box->model()->index(index++, 0);
        ui->color_box->model()->setData(idx, color, Qt::BackgroundColorRole);
    }
    ui->color_box->setCurrentIndex( white_ind );
}

Control::~Control()
{
    delete ui;
}


void Control::scale_puzzle()
{

        puzzle_h = data.height();
        puzzle_w = data.width();
        if( puzzle_w >= 3 * board_w / 4)
        {
            double mn = 3.* board_w / ( 4 * puzzle_w) ;
            puzzle_w *= mn;
            puzzle_h *= mn;
        }

        if( puzzle_h >= 3 * board_h / 4 )
        {
            double mn = 3. * board_h / ( 4. * puzzle_h );
            puzzle_w *= mn;
            puzzle_h *= mn;
        }
        int div = n_horiz * 3;
            puzzle_w += div - puzzle_w % div;
        div = n_vert * 3;
            puzzle_h += div - puzzle_h % div;

        picture = data.scaled(puzzle_w, puzzle_h);
        emit data_changed( this );

}
void Control::load_image()
{
    if( data.load( img_name ))
    {
        ui->image_name->setText( img_name );
        ui->imagests_lbl->setText( "Loaded" );
        ui->load_buttn->setEnabled( true );
        ui->tab_2->setEnabled( true );
        ui->tab_3->setEnabled( true );
        ui->tab_4->setEnabled( true );
        ui->finish_buttn->setEnabled( false );
        scale_puzzle();
    }
    else
    {
        ui->imagests_lbl->setText( "Opening Error" );
        ui->load_buttn->setEnabled( false );
        ui->tab_2->setEnabled( false );
        ui->tab_3->setEnabled( false );
        ui->tab_4->setEnabled( false );

    }

}

void Control::on_pushButton_2_clicked()
{
    QFileDialog* dialog = new PreviewFileDialog(this, "Open image", "", tr("Image Files (*.png *.jpg *.bmp *.tif);;"));
    dialog->setAcceptMode(QFileDialog::AcceptOpen);
    connect( dialog, SIGNAL(currentChanged(QString)), this, SLOT(preview_change(QString)) );
    dialog->exec();
    load_image();
}

void Control::on_load_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 1 );
}

void Control::on_lvl_slider_valueChanged(int value)
{
    level = value;
    n_horiz = 2 * level;
    n_vert  = 2 * level;
    scale_puzzle();
}

void Control::on_nextlvl_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 2 );
}

void Control::on_add_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 3 );
}

void Control::on_pushButton_clicked()
{
    ui->finish_buttn->setEnabled( true );
    emit shuffle_puzzle();
}

void Control::on_finish_buttn_clicked()
{
    close();
}

void Control::on_color_box_activated(int index)
{
    const QModelIndex idx = ui->color_box->model()->index( index, 0);
    QVariant data = ui->color_box->model()->data(idx, Qt::UserRole);
    border_color = data.value < QColor >();
    emit view_changed( false, false, true );
}

void Control::on_spinBox_valueChanged(int arg1)
{
    shadow_deep = arg1;
    emit view_changed( false, true, false );
}

void Control::on_horizontalSlider_valueChanged(int value)
{
    shadow_intensity = value;
    emit view_changed( false, true, false );
}
void Control::preview_change(const QString &path)
{
    QPixmap pixmap = QPixmap(path);
    if (pixmap.isNull()) {
        ui->preview_pict->setText("not an image");
    }
    else {
        img_name = path;
        ui->preview_pict->setPixmap(pixmap.scaled(ui->preview_pict->width(), ui->preview_pict->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Control::on_tabWidget_currentChanged(int index)
{
    QSize sz = size();
    if( index == 0 )
        sz.setHeight( 400 );
    else
        sz.setHeight( 220 );
    resize( sz );
}
