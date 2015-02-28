#include <kPlantsDB/DatabaseConnection.h>

#include <QCoreApplication>

int main(int _argc, char** _argv)
{
  QCoreApplication app(_argc, _argv);
  kPlantsDB::DatabaseConnection connection;
  connection.execute(
      "select distinct ?y where {"
      "?x <http://dbpedia.org/property/regnum> \"Plantae\"@en ."
      "?x dbpedia-owl:order ?y"
      "} LIMIT 100");
}
