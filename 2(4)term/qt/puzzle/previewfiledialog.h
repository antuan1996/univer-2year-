#ifndef PREVIEWFILEDIALOG_H
#define PREVIEWFILEDIALOG_H

#include <QFileDialog>
#include <QLabel>
#include <QGridLayout>

class PreviewFileDialog : public QFileDialog
{
    Q_OBJECT
public:
    explicit PreviewFileDialog(
        QWidget* parent = 0,
        const QString & caption = QString(),
        const QString & directory = QString(),
        const QString & filter = QString()
    );

protected slots:
    void OnCurrentChanged(const QString & path);

protected:
    QLabel* mpPreview;
};

#endif // PREVIEWFILEDIALOG_H
