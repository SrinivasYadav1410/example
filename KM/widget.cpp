#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_qt_clicked()
{

    int ret = prepareDealerReqFile("/mnt/jffs2/CardHolder.xml",2);
    if(ret < 0)
        return;
    system("cat /mnt/jffs2/CardHolder.xml");
    qDebug() << "I have edited the code for my understanding......";
    qDebug() << "---------------..............--------------";


}

int Widget::prepareDealerReqFile(QString fileName,int i)
{
    switch(i){
    case 1:
        qDebug() << "In Dealer Request framing.. " << endl;
        qDebug() << "File " << fileName << endl;
        return requestframing(fileName,1);
        break;
    case 2:
        qDebug() << "In Case 2" << endl;
        qDebug() << "File " << fileName << endl;
        return requestframing(fileName,2);
        break;
    case 3:
        qDebug() << "In case 3" << endl;
        qDebug() << "File " << fileName << endl;
        return requestframing(fileName,3);
        break;
    default:
        break;
    }
}

int Widget::requestframing(QString fileName,int i)
{
    QString dreq =  fileName;
    QString dresp = "/mnt/jffs2/DealerDetails.xml";

    if (QFile::exists(dreq)) {
        if (QFile::remove(dreq)) {
            qDebug() << "\nfiles are removed" << endl;
        } else if(!QFile::exists(dreq)){
            qDebug() << "\nfiles are not present." << endl;
        }
    } else {
        qDebug() << "Files not exist.";
    }

    QFile file(dreq);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to create file. Error:" << file.errorString();
        return -1;
    }


    if (i == 1) {
        qDebug() << "In if loop" << endl;
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << fileName << "File Open Failed...";
            return -1;
        }

        QTextStream out(&file);

        QString machineId = "1906675275";
        QString simSerialNo = "ABC123456";
        QString latitude = "12.9716";
        QString longitude = "77.5946";

        QString xmlContent = QString("<?xml version='1.0' encoding='UTF-8' standalone='no' ?> "
                                     "<SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" "
                                     "xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" "
                                     "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" "
                                     "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
                                     "xmlns:ns1=\"http://service.epos.nfsc.nic.com/\">"
                                     "<SOAP-ENV:Body>"
                                     "<ns1:getFPSDealerDetails>"
                                     "<shopNo>%1</shopNo>"
                                     "<deviceId>%2</deviceId>"
                                     "<simSerialNo>%3</simSerialNo>"
                                     "<eposVersion>%4</eposVersion>"
                                     "<latitude>%5</latitude>"
                                     "<longitude>%6</longitude>"
                                     "<password>%7</password>"
                                     "</ns1:getFPSDealerDetails>"
                                     "</SOAP-ENV:Body>"
                                     "</SOAP-ENV:Envelope>")
                .arg("1633333")
                .arg(machineId)
                .arg(simSerialNo)
                .arg("5.9")
                .arg(latitude)
                .arg(longitude)
                .arg("1159abbb8b6c0b8a8964210af6954b17");

        out << xmlContent;
        file.close();

        return 0;
    }
    else if (i == 2) {
        qDebug() << "In else if loop 2" << endl;
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << fileName << "File Open Failed...";
            return -1;
        }

        QTextStream out(&file);

        QString xmlContent = QString("<?xml version='1.0' encoding='UTF-8' standalone='no' ?> "
                                     "<SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" "
                                     "xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" "
                                     "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" "
                                     "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
                                     "xmlns:ns1=\"http://service.impds.nfsc.nic.com/\">"
                                     "<SOAP-ENV:Body>"
                                     "<ns1:getRationCardDetails>"
                                     "<distCode>%1</distCode>"
                                     "<shopNo>%2</shopNo>"
                                     "<rationCard>%3</rationCard>"
                                     "<currYear>%4</currYear>"
                                     "<currMonth>%5</currMonth>"
                                     "<transactionId>%6</transactionId>"
                                     "<payType>%7</payType>"
                                     "<password>%8</password>"
                                     "<impdsFlag>1</impdsFlag>"
                                     "</ns1:getRationCardDetails>"
                                     "</SOAP-ENV:Body>"
                                     "</SOAP-ENV:Envelope>")
                .arg("536")
                .arg("1633333")
                .arg("123456789")
                .arg("2024")
                .arg("9")
                .arg("123456789")
                .arg("1")
                .arg("234567");

        out << xmlContent;
        file.close();

        return 0;
    }
    else if (i == 3) {
        qDebug() << "In else if loop 3" << endl;
        return -1;
    }
    return -1;
}


void Widget::on_pushButton_clicked()
{
    int ret = prepareDealerReqFile("/mnt/jffs2/Dealer.xml",1);
    if(ret < 0)
        return;
    system("cat /mnt/jffs2/Dealer.xml");

    QString cmdCurl = QString("curl -k --cacert %1 -H 'SOAPACTION: \"http://tempuri.org/getFPSDealerDetails\"' "
                              "-X POST -H 'Content-type: text/xml' -d @%2 %3 > %4 -v -m %5")
            .arg(SECURECERTICATE)
            .arg("/mnt/jffs2/Dealer.xml")
            .arg("https://eposservices.telangana.gov.in/ePoSServices/epos?wsdl")
            .arg("/mnt/jffs2/DealerDetails.xml")
            .arg(120);
    int exitCode = QProcess::execute("bash", QStringList() << "-c" << cmdCurl);

    qDebug() << "the exitCode " << exitCode;
    system("cat /mnt/jffs2/DealerDetails.xml");
}
