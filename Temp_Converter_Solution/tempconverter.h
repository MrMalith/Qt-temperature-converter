#ifndef TEMPCONVERTER_H
#define TEMPCONVERTER_H

#include <QObject>

class tempconverter : public QObject
{
    Q_OBJECT
    public:
        tempconverter(QObject *parent = nullptr);
        int tempFahrenheit();
    public slots:
        void setTempCelsius(int);
        void setTempFahrenheit(int);
    signals:
        void tempCelsiusChanged(int);
        void tempFahrenheitChanged(int);
    private:
        int m_tempCelsius; //notation: “m_” private member variable
};

#endif // TEMPCONVERTER_H
