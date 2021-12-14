#include "networkprogressdialog.h"
#include <QDebug>
#include <QtMath>

NetworkProgressDialog::NetworkProgressDialog(const QString &labelText, QWidget *parent)
    : QProgressDialog(labelText,tr("Cancel"),0,100,parent)
{
    /* I'm use Progress dialog to show download/upload progress.
     * So make dialog modal to block user click download during network progress.
     * Also close and destroy after receive network finished() signal */
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::WindowModality::WindowModal);
}

NetworkProgressDialog::~NetworkProgressDialog()
{
}

void NetworkProgressDialog::networkProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << "Prograss: " << bytesReceived << "," << bytesTotal;
    if(bytesReceived>0 && (bytesReceived<bytesTotal)){
//        int prograss = int((double(bytesReceived)/double(bytesTotal))*100);
        setValue(int((double(bytesReceived)/double(bytesTotal))*100));
    }
    else{
        setValue(0);
    }
}

/// when network reply finished, you may want to simply destroy NetworkProgressDialog
/// using QWidget::close will emit QProgressDialog::canceled signal, so we need block
/// all signal here
void NetworkProgressDialog::closeAndBlockSignal()
{
    this->blockSignals(true);
    this->close();
}
