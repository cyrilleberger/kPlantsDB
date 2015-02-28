#include "Plantae.h"

#include <QString>

#include "Order.h"
#include "QueryResult.h"
#include "DatabaseConnection.h"

using namespace kPlantsDB;

struct Plantae::Private : public QSharedData
{
  DatabaseConnection* connection;
  mutable QList< Order > cached;
};

Plantae::Plantae(DatabaseConnection* _connection) : d(new Private)
{
  d->connection = _connection;
}

Plantae::Plantae(const Plantae& _other) : d(_other.d)
{

}

Plantae Plantae::operator=(const Plantae& _other)
{
  d = _other.d;
  return *this;
}

Plantae::~Plantae()
{

}

QList< Order > Plantae::orders() const
{
  if(d->cached.isEmpty())
  {
    QString q = "select distinct ?y where {"
                "?x <http://dbpedia.org/property/regnum> \"Plantae\"@en ."
                "?x dbpedia-owl:order ?y"
                "} LIMIT 1000 OFFSET %1";
    
    for(int i = 0; ; i+=1000)
    {
      QString aq = q.arg(i);
      QueryResult qr = d->connection->execute(aq);
      for(const QueryResult::Line& l : qr.lines())
      {
        d->cached.append(Order(l["y"].toString()));
      }
      if(qr.lines().size() != 1000)
      {
        break;
      }
    }
  }
  return d->cached;
}
