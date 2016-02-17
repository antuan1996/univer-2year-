#include "previewfiledialog.h"

PreviewFileDialog::PreviewFileDialog(
    QWidget* parent,
    const QString & caption,
    const QString & directory,
    const QString & filter
) : QFileDialog(parent, caption, directory, filter)
{
    setObjectName("PreviewFileDialog");
    QVBoxLayout* box = new QVBoxLayout();

    mpPreview = new QLabel("Preview", this);
    //mpPreview->setGeometry(0,0, 200, 200);
    mpPreview->setMinimumWidth( 200 );
    mpPreview->setMinimumHeight( 200 );

    mpPreview->setAlignment(Qt::AlignCenter);
    mpPreview->setObjectName("labelPreview");
    box->addWidget(mpPreview);

    //box->addStretch();

    // add to QFileDialog layout
    {
        QGridLayout *layout = (QGridLayout*)this->layout();
        layout->addLayout(box, 1, 3, 1, 1);
    }
    connect(this, SIGNAL(currentChanged(const QString&)), this, SLOT(OnCurrentChanged(const QString&)));
}

void PreviewFileDialog::OnCurrentChanged(const QString & path)
{
    QPixmap pixmap = QPixmap(path);
    if (pixmap.isNull()) {
        mpPreview->setText("not an image");
    } else {
        mpPreview->setPixmap(pixmap.scaled(mpPreview->width(), mpPreview->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
