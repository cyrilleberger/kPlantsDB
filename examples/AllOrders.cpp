#include <QCoreApplication>
#include <QDebug>

#include <kPlantsDB/DatabaseConnection.h>
#include <kPlantsDB/Order.h>
#include <kPlantsDB/Plantae.h>
#include <kPlantsDB/QueryResult.h>


int main(int _argc, char** _argv)
{
  QCoreApplication app(_argc, _argv);
  kPlantsDB::DatabaseConnection connection;
  kPlantsDB::Plantae plantae(&connection);
  for(const kPlantsDB::Order& order : plantae.orders())
  {
    qDebug() << order.name();
  }
  return 0;
}
