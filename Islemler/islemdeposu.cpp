#include "islemdeposu.h"
#include <Islemler/VeriGirisi/isletmegirisislemi.h>
#include <Islemler/VeriGirisi/otobusgirisislemi.h>
#include <Islemler/VeriGirisi/sefergirisislemi.h>
#include <Islemler/VeriGirisi/seyehatkurallariislemi.h>
#include <Islemler/VeriGirisi/seyehatgirisislemi.h>
#include <Islemler/VeriGirisi/soforgirisislemi.h>
#include <Islemler/VeriGirisi/yolcugirisislemi.h>

IslemDeposu &IslemDeposu::fb()
{
    static IslemDeposu tempislem;
    return tempislem;
}

QAction *IslemDeposu::getAction(IslemSirasi x)
{
    return _islemler[x]->islem();

}

void IslemDeposu::calistir(IslemSirasi y)
{
    _islemler[y]->main();
}

IslemDeposu::IslemDeposu(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<IsletmeGirisIslemi>());
    _islemler.append(std::make_shared<OtobusGirisIslemi>());
    _islemler.append(std::make_shared<SeferGirisIslemi>());
    _islemler.append(std::make_shared<SeyehatKurallariIslemi>());
    _islemler.append(std::make_shared<SeyehatGirisIslemi>());
    _islemler.append(std::make_shared<SoforGirisIslemi>());
    _islemler.append(std::make_shared<YolcuGirisIslemi>());
}
