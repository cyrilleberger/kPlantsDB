#include <QCoreApplication>
#include <QDebug>

#include <kPlantsDB/DatabaseConnection.h>
#include <kPlantsDB/QueryResult.h>


int main(int _argc, char** _argv)
{
  QCoreApplication app(_argc, _argv);
  kPlantsDB::DatabaseConnection connection;
  kPlantsDB::QueryResult qr = connection.execute(
      "select distinct ?y where {"
      "?x <http://dbpedia.org/property/regnum> \"Plantae\"@en ."
      "?x dbpedia-owl:order ?y"
      "} LIMIT 100");
  qDebug() << qr;
}
