#include "tempconverter.h"

tempconverter::tempconverter(QObject *parent) : QObject(parent)
{

}

void tempconverter::setTempCelsius(int tempCelsius)
{
    if(m_tempCelsius == tempCelsius) // this is to avoid infinite loop
        return;

    m_tempCelsius = tempCelsius;
    emit tempCelsiusChanged(m_tempCelsius);
    emit tempFahrenheitChanged(tempFahrenheit());
}

void tempconverter::setTempFahrenheit(int tempFahrenheit)
{
    int tempCelsius = (5.0/9.0)*(tempFahrenheit-32);
    setTempCelsius(tempCelsius);
}

int tempconverter::tempFahrenheit()
{
    int tempFahrenheit = m_tempCelsius * (9.0/5.0) + 32;
    return tempFahrenheit;
}
